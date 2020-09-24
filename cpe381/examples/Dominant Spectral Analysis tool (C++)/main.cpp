#include <iostream>
#include <fstream>
#include <complex>
#include <iomanip>
#include <valarray>
#include <ctime>
#include <string.h>

using namespace std;

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

//Useful constants
const unsigned short EIGHT_BITS = 8;
const unsigned short SIN_FREQUENCY_1 = 1600;
const unsigned short SIN_FREQUENCY_2 = 2400;
const double PI = 3.141592653589793238460;
const int MAX_NUM = 32767;
const int MIN_NUM = -32768;

//typeDef
typedef complex<double> Complex;
typedef valarray<Complex> CArray;

bool readAndValidateHeader(ifstream &inputData, string filename, ofstream &summaryFile, waveHeader &waveHeaderInfo);
void fft(CArray& x);

int main()
{
	//variables
	bool errorOccurred = false;

	//variables to determine how long proccess time took
	clock_t start;
	clock_t finish;
	double processTime = 0.0;

	//create instance of struct 
	waveHeader waveHeaderInfo;

	//declare input and output files
	ofstream summaryFile;
	ifstream inputData;

	inputData.open("Stewart_E_mod.wav", ios::binary | ios::in);
	summaryFile.open("Stewart_E_bonus_summary.txt", ios::app);

	//error handling for failed open file
	if (!inputData.is_open())
	{
		cout << "Error - unable to open input file" << endl;
		summaryFile << "Error - unable to open input file" << endl;

		summaryFile.close();

		exit(0);
	}

	//start the start time for the process clock
	start = clock();

	//read the header in and validate 
	errorOccurred = readAndValidateHeader(inputData, "Stewart_E_mod.wav", summaryFile, waveHeaderInfo);

	//error handling for invalid file type
	if (errorOccurred)
	{
		cout << "Error - File is not compatible" << endl;
		summaryFile << "Error - File is not compatible" << endl;
		summaryFile.close();
		inputData.close();

		exit(0);
	}

	//declare the complex vector to store the values
	CArray fftBuff(waveHeaderInfo.dataSize/4);

	//holds values while reading in
	short sample1_Left;
	short sample1_Right;
	unsigned int fftBuffLen = 0;

	//reads in the entire file
	while (!inputData.eof())
	{
		//read in both channels but we only want the left channel so ignore right
		inputData.read((char*)&sample1_Left, sizeof(sample1_Left));
		inputData.read((char*)&sample1_Right, sizeof(sample1_Right));

		//push into vector and increment
		fftBuff[fftBuffLen] = sample1_Left;
		fftBuffLen++;
	}

	//perform fourier on the buffer
	fft(fftBuff);

	//create values for processing
	double maxSpec = (fftBuff[0].real()) * (fftBuff[0].real()) + (fftBuff[0].imag()) * (fftBuff[0].imag());
	double temp = 0;
	int maxIndex = 0;

	//for each values in buffer check its Spectrum and see if it is the new max
	for (int i = 0; i < fftBuffLen; i++)
	{
		temp = (fftBuff[i].real()) * (fftBuff[i].real()) + (fftBuff[i].imag()) * (fftBuff[i].imag());

		if (temp > maxSpec)
		{
			maxSpec = temp;
			maxIndex = i;
		}
	}

	//calculate for the hertz 
	double maxInHz = maxIndex * waveHeaderInfo.sampleRate / fftBuffLen;

	//calculate runtime and close out
	finish = clock();
	processTime = (double)(finish - start) / 1000;

	summaryFile << "Processing time: " << setprecision(.2) << processTime << " s" << endl;
	summaryFile << "Dominant spectral component: " << setprecision(.2) << maxInHz << "Hz" << endl;
	summaryFile << "===================================================" << endl;

	inputData.close();
	summaryFile.close();

	exit(0);
	return 0;
}

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
	summaryFile << "Dominant spectrum analysis using C++" << endl;
	summaryFile << "FileName: " << filename << endl;
	summaryFile << "Sampling Frequency: " << waveHeaderInfo.sampleRate << " Hz" << endl;
	summaryFile << "Recording length: " << setprecision(.2) << playTime << " sec" << endl;

	return false;
}

//fft function. Credit to: https://rosettacode.org/wiki/Fast_Fourier_transform#C.2B.2B
void fft(CArray& x)
{
	const size_t N = x.size();
	if (N <= 1) return;

	// divide
	CArray even = x[slice(0, N / 2, 2)];
	CArray  odd = x[slice(1, N / 2, 2)];

	// conquer
	fft(even);
	fft(odd);

	// combine
	for (size_t k = 0; k < N / 2; ++k)
	{
		Complex t = polar(1.0, -2 * PI * k / N) * odd[k];
		x[k] = even[k] + t;
		x[k + N / 2] = even[k] - t;
	}
}