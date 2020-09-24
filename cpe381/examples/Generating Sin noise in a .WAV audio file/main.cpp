/*===================================================================================
Author: Evan Stewart
Class: CPE 381 - Signals and Systems
Assignment: Project Phase 1
Date: 10/5/2018
GitHub: https://github.com/Evan6678
Design Information: All design information prior to writting code 
		will be on my GitHub including flowcharts
Description: This program is to take in a .wav audio file. It will 
				run processing on this file to overlay the original signal with 2 sin waves to
				simulate noise. More information can be found in the design section on my GitHub.
*///=================================================================================

#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <string>
#include <iomanip>
#include <queue>
#include <cstring>

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
void readAndValidateHeader(ifstream &inputData, string filename, ofstream &summaryFile, waveHeader &waveHeaderInfo, bool errorOccurred);
void processFile(ifstream &inputData, ofstream &outputFile, unsigned long sampleRate, queue <short> &leftHistoryBuffer, queue <short> &rightHistoryBuffer);
void addSinWave(ofstream &outputData, short sinAmp, short leftSample, short rightSample, float time);

int main(int argc, char *argv[])
{
	//misc variables
	bool errorOccurred = false;
	short maxAmp = 0;

	//declare history buffers
	queue <short> leftHistoryBuffer;
	queue <short> rightHistoryBuffer;

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

	inputData.open("Stewart_E_orig.wav", ios::binary|ios::in);
	outputData.open("Stewart_E_output.wav", ios::binary|ios::out);
	summaryFile.open("Stewart_E_summary.txt", ios::app);

	//error handling for failed open file
	if (!inputData.is_open())
	{
		cout << "Error - unable to open input file" << endl;
		summaryFile<< "Error - unable to open input file" << endl;

		summaryFile.close();
		outputData.close();

		return 0;
	}

	//start the start time for the process clock
	start = clock();	

	//read the header in and validate 
	readAndValidateHeader(inputData, "Stewart_E_orig.wav", summaryFile, waveHeaderInfo, errorOccurred);

	//error handling for invalid file type
	if (errorOccurred)
	{
		cout << "Error - File is not compatible" << endl;
		summaryFile << "Error - File is not compatible" << endl;
		summaryFile.close();
		outputData.close();
		inputData.close();

		return 0;
	}

	//handle invalid file type
	if (waveHeaderInfo.bitPerSample != 16 && waveHeaderInfo.numChannels != 2)
	{
		cout << "Error - File is not compatible" << endl;
		summaryFile << "Error - File is not compatible" << endl;
		summaryFile.close();
		outputData.close();
		inputData.close();

		return 0;
	}

	//write the header to the new outfile
	outputData.write((char*)&waveHeaderInfo, sizeof(waveHeaderInfo));

	//will modify the data and create a queue of averaged values ready to add sin wave
	processFile(inputData, outputData, waveHeaderInfo.sampleRate, leftHistoryBuffer, rightHistoryBuffer);

	//calculate runtime and close out
	finish = clock();
	processTime = (double)(finish - start) / 1000;
	summaryFile << "Processing time: " << setprecision(.2) << processTime << " s" << endl;
	summaryFile << "===================================================" << endl;

	inputData.close();
	outputData.close();
	summaryFile.close();

	return 0;
}

void readAndValidateHeader(ifstream &inputData, string filename, ofstream &summaryFile, waveHeader &waveHeaderInfo, bool errorOccurred)
{	
	//read in and valudate header
	try
	{
		inputData.read((char*)&waveHeaderInfo, sizeof(waveHeaderInfo));

		if (memcmp(&waveHeaderInfo.RIFF, "RIFF", 4) != 0
			&& memcmp(&waveHeaderInfo.WAVE, "WAVE", 4) != 0
			&& memcmp(&waveHeaderInfo.WAVE, "WAVE", 4) != 0) {
			errorOccurred = true;
		}
	}
	//invalid file types could cause exceptions
	catch (...)
	{
		errorOccurred = true;
		return;
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

	return;
}

void processFile(ifstream &inputData, ofstream &outputFile, unsigned long sampleRate, queue <short> &leftHistoryBuffer, queue <short> &rightHistoryBuffer)
{
	//declare variables for processing
	short sample1_Left;
	short sample1_Right;
	short sample2_Left;
	short sample2_Right;
	short leftResult;
	short rightResult;
	short MaxAmp = 32767;

	//set time and sinAmp
	short sinAmp = MaxAmp / 10;
	float time = 0.0f;

	//handel the first item in the data set
	//where time = 0

	//read in first sample
	inputData.read((char*)&sample1_Left, sizeof(sample1_Left));
	inputData.read((char*)&sample1_Right, sizeof(sample1_Right));

	addSinWave(outputFile, sinAmp, sample1_Left, sample1_Right, time);
	//////////////////////////////////////

	//average all data points then send to addSinWave() to add the wave and output
	while (!inputData.eof())
	{
		//read in next 2 values from file
		inputData.read((char*)&sample2_Left, sizeof(sample2_Left));
		inputData.read((char*)&sample2_Right, sizeof(sample2_Right));

		//average the 2 samples
		leftResult = (sample1_Left>>1) + (sample2_Left>>1);
		rightResult = (sample1_Right>>1) + (sample2_Right>>1);

		//calucluate time of sample
		time = time + (1.0f / sampleRate);

		//call function to add sin wave and output
		addSinWave(outputFile, sinAmp, sample1_Left, sample1_Right, time);

		//store in history buffer
		leftHistoryBuffer.push(sample1_Left);
		rightHistoryBuffer.push(sample1_Right);

		//shift samples over 
		sample1_Left = sample2_Left;
		sample1_Right = sample2_Right;
	}
}

void addSinWave(ofstream &outputData, short sinAmp, short leftSample, short rightSample, float time)
{
	short sinWaveValue = 0;
	short sinWaveValue2 = 0;
	int newLeftValINT = 0;
	int newRightValINT = 0;

	//get values of both sin waves
	sinWaveValue = (short)sinAmp*sin(2.0f*PI*SIN_FREQUENCY_1*time);
	sinWaveValue2 = (short)sinAmp*sin(2.0f*PI*SIN_FREQUENCY_2*time + (PI / 3));

	//get new sample with noise
	newLeftValINT = leftSample + sinWaveValue + sinWaveValue2;
	newRightValINT = rightSample + sinWaveValue + sinWaveValue2;

	//clipping too large values
	if (newLeftValINT > MAX_NUM)
		newLeftValINT = MAX_NUM;
	if (newLeftValINT < MIN_NUM)
		newLeftValINT = MIN_NUM;

	if (newRightValINT > MAX_NUM)
		newRightValINT = MAX_NUM;
	if (newRightValINT < MIN_NUM)
		newRightValINT = MIN_NUM;

	//write out the data
	outputData.write((char*)&newLeftValINT, sizeof(short));
	outputData.write((char*)&newRightValINT, sizeof(short));
}