/*===================================================================================
Author: Evan Stewart
Class: CPE 381 - Signals and Systems
Assignment: Project Phase 2
Date: 11/18/2018

GitHub: https://github.com/Evan6678

Description: This program takes a .wav file with noise at 1600Hz and 2400Hz and uses
a FIR filter to remove the noise.
*///=================================================================================

#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <iomanip>
#include <string>

#include "filter_44100.h"
#include "filter_11025.h"

using namespace std;

//Useful constants
const unsigned short EIGHT_BITS = 8;
const unsigned short SIN_FREQUENCY_1 = 1600;
const unsigned short SIN_FREQUENCY_2 = 2400;
const float PI = 3.14159f;
const int MAX_NUM = 32767;
const int MIN_NUM = -32768;

//.wav file header structure
struct waveHeader
{
	char RIFF[4];
	unsigned long chunkSize;
	char WAVE[4];
	char fmt[4];
	unsigned long subChunkSize1;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned long sampleRate;
	unsigned long byteRate;
	unsigned short blockAlign;
	unsigned short bitPerSample;
	char subTrunkID[4];
	unsigned long dataSize;
};

//function prototypes
bool readAndValidateHeader(ifstream &inputData, string filename, ofstream &summaryFile, waveHeader &waveHeaderInfo);
bool frequencySelectionSwitcher(ifstream &inputData, ofstream &outputData, waveHeader waveHeaderInfo, string &errorMessage);
bool filter_44100Freq(ifstream &inputData, ofstream &outputData, waveHeader waveHeaderInfo, string &errorMessage);
bool filter_11025Freq(ifstream &inputData, ofstream &outputData, waveHeader waveHeaderInfo, string &errorMessage);

int main(int argc, char *argv[])
{
	//error variables
	bool errorOccurred = false;
	string errorMessage;

	//create instance of struct 
	waveHeader waveHeaderInfo;

	//variables to determine how long proccess time took
	clock_t start;
	clock_t finish;
	double processTime = 0.0;

	//define I/O Files and open
	ifstream inputData;
	ofstream outputData;
	ofstream summaryFile;

	inputData.open("Stewart_E_mod.wav", ios::binary | ios::in);
	outputData.open("Stewart_E_filt.wav", ios::binary | ios::out);
	summaryFile.open("Stewart_E_summary.txt", ios::app);

	//error handling for failed open file
	if (!inputData.is_open())
	{
		cout << "Error - unable to open input file" << endl;
		summaryFile << "Error - unable to open input file" << endl;

		summaryFile.close();
		outputData.close();

		return 0;
	}

	//start the start time for the process clock
	start = clock();

	//read the header in and validate 
	errorOccurred = readAndValidateHeader(inputData, "Stewart_E_mod.wav", summaryFile, waveHeaderInfo);

	//error handling for invalid file type
	if (errorOccurred)
	{
		summaryFile.close();
		outputData.close();
		inputData.close();

		return 0;
	}

	//write the header to the new outfile
	outputData.write((char*)&waveHeaderInfo, sizeof(waveHeaderInfo));

	//call switcher to determine filter function to use (Helps manage larger scalability)
	errorOccurred = frequencySelectionSwitcher(inputData, outputData, waveHeaderInfo, errorMessage);

	//if an error occured during processing this will catch it
	if (errorOccurred)
	{
		summaryFile << endl << errorMessage << endl;

		summaryFile.close();
		outputData.close();
		inputData.close();

		return 0;
	}

	//calculate runtime and close out
	finish = clock();
	processTime = (double)(finish - start) / 1000;
	summaryFile << "Processing time: " << setprecision(.2) << processTime << " s" << endl;
	summaryFile << "===================================================" << endl;

	//close files
	inputData.close();
	outputData.close();
	summaryFile.close();

	return 0;
}

//Read and validate the header then print to the summary file
bool readAndValidateHeader(ifstream &inputData, string filename, ofstream &summaryFile, waveHeader &waveHeaderInfo)
{
	//read in and valudate header
	try
	{
		inputData.read((char*)&waveHeaderInfo, sizeof(waveHeaderInfo));

		if (memcmp(&waveHeaderInfo.RIFF, "RIFF", 4) != 0
			&& memcmp(&waveHeaderInfo.WAVE, "WAVE", 4) != 0
			&& memcmp(&waveHeaderInfo.WAVE, "WAVE", 4) != 0
			&& (waveHeaderInfo.bitPerSample != 16 
			&& waveHeaderInfo.numChannels != 2)) {

			cout << "Error - File is not compatible" << endl;
			summaryFile << "Error - File is not compatible" << endl;

			return true;
		}
	}
	//invalid file types could cause exceptions
	catch (...)
	{
		cout << "Error - Exception in Read File" << endl;
		summaryFile << "Error - Exception in Read File" << endl;
		return true;
	}

	//datasize = samples * channels
	unsigned long samples = (waveHeaderInfo.dataSize / waveHeaderInfo.numChannels) / (waveHeaderInfo.bitPerSample / EIGHT_BITS);
	double playTime = (double)samples / waveHeaderInfo.sampleRate;

	//write to summary file
	summaryFile << endl << endl << "===================================================" << endl;
	summaryFile << "FileName: " << filename << endl;
	summaryFile << "Sampling Frequency: " << waveHeaderInfo.sampleRate << " Hz" << endl;
	summaryFile << "Number of channels: " << waveHeaderInfo.numChannels << " channels" << endl;
	summaryFile << "Number of bits per sample: " << waveHeaderInfo.bitPerSample << " bits" << endl;
	summaryFile << "Recording length: " << setprecision(.2) << playTime << " sec" << endl;

	return false;
}

//will determin what filter function to use and will return the status in a bool along with any error messages if failed
bool frequencySelectionSwitcher(ifstream &inputData, ofstream &outputData, waveHeader waveHeaderInfo, string &errorMessage)
{
	bool errorOccured = false;
	switch (waveHeaderInfo.sampleRate)
	{
	case 44100:
		return filter_44100Freq(inputData, outputData, waveHeaderInfo, errorMessage);
		break;

	case 11025:
		return filter_11025Freq(inputData, outputData, waveHeaderInfo, errorMessage);
		break;

	default:
		errorMessage = "Error: Invalid sample frequency";
		return true;
		break;
	}
}

bool filter_44100Freq(ifstream &inputData, ofstream &outputData, waveHeader waveHeaderInfo, string &errorMessage)
{
	//set array to all 0
	short inputArrayLeft[filtLen_44100];
	short inputArrayRight[filtLen_44100];
	memset(inputArrayLeft, 0, filtLen_44100 * 2);
	memset(inputArrayRight, 0, filtLen_44100 * 2);

	//vars for holding and calculating
	short leftInput;
	short rightInput;
	double resultLeft = 0;
	double resultRight = 0;

	short shortResultLeft;
	short shortResultRight;

	try 
	{
		//while not end of file keep looping
		while (!(inputData.eof()))
		{
			//re-init var
			resultLeft = 0;
			resultRight = 0;

			//read in left and right values
			inputData.read((char*)&leftInput, sizeof(short));
			inputData.read((char*)&rightInput, sizeof(short));

			//shift input arrays
			for (int i = filtLen_44100 - 1; i > 0; i--)
			{
				inputArrayLeft[i] = inputArrayLeft[i - 1];
				inputArrayRight[i] = inputArrayRight[i - 1];
			}

			//load the new value into buff
			inputArrayLeft[0] = leftInput;
			inputArrayRight[0] = rightInput;

			//get convolution values
			for (int i = 0; i < filtLen_44100; i++)
			{
				resultLeft += inputArrayLeft[i] * filt_44100[i];
				resultRight += inputArrayRight[i] * filt_44100[i];
			}

			//convert to short
			shortResultLeft = (short)resultLeft;
			shortResultRight = (short)resultRight;

			//output to wav file
			outputData.write((char*)&shortResultLeft, sizeof(short));
			outputData.write((char*)&shortResultRight, sizeof(short));
		}
	}
	catch (...)
	{
		errorMessage = "Failure during processing filt_44100";
		return true;
	}

	return false;
	
}

bool filter_11025Freq(ifstream &inputData, ofstream &outputData, waveHeader waveHeaderInfo, string &errorMessage)
{
	//set array to all 0
	short inputArrayLeft[filtLen_11025];
	short inputArrayRight[filtLen_11025];
	memset(inputArrayLeft, 0, filtLen_11025 * 2);
	memset(inputArrayRight, 0, filtLen_11025 * 2);

	//vars for holding and calculating
	short leftInput;
	short rightInput;
	double resultLeft = 0;
	double resultRight = 0;

	short shortResultLeft;
	short shortResultRight;

	try
	{
		//while not end of file keep looping
		while (!(inputData.eof()))
		{
			//re-init var
			resultLeft = 0;
			resultRight = 0;

			//read in left and right values
			inputData.read((char*)&leftInput, sizeof(short));
			inputData.read((char*)&rightInput, sizeof(short));

			//shift input arrays
			for (int i = filtLen_11025 - 1; i > 0; i--)
			{
				inputArrayLeft[i] = inputArrayLeft[i - 1];
				inputArrayRight[i] = inputArrayRight[i - 1];
			}

			//load the new value into buff
			inputArrayLeft[0] = leftInput;
			inputArrayRight[0] = rightInput;

			//get convolution values
			for (int i = 0; i < filtLen_11025; i++)
			{
				resultLeft += inputArrayLeft[i] * filt_11025[i];
				resultRight += inputArrayRight[i] * filt_11025[i];
			}

			//convert to short
			shortResultLeft = (short)resultLeft;
			shortResultRight = (short)resultRight;

			//output to wav file
			outputData.write((char*)&shortResultLeft, sizeof(short));
			outputData.write((char*)&shortResultRight, sizeof(short));
		}
	}
	catch (...)
	{
		errorMessage = "Failure during processing filt_11025";
		return true;
	}

	return false;
}
