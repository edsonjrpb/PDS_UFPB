#define  _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <AudioFile.h>
#include <vector>



int main(void)
{
	/*Variables declaration*/
	AudioFile<double> audioFile;
	unsigned int sampleRate{ 0 };
	unsigned int bitDepth{ 0 };
	unsigned int numSamples{ 0 };
	unsigned int numChannels{ 0 };
	bool isMono{ NULL };
	bool isStereo{ NULL };
	double lengthInSeconds{ 0.0 }; 

	/*Open .WAV File*/
	audioFile.load("F:/Mestrado/PDS/Audacity_Teste/WAV Samples/Alesis-S4-Plus-Night-Vox-C3.wav");
		
	/*.WAV File Characteristics*/
	sampleRate = audioFile.getSampleRate();
	bitDepth = audioFile.getBitDepth();
	numSamples = audioFile.getNumSamplesPerChannel();
	lengthInSeconds = audioFile.getLengthInSeconds();
	numChannels = audioFile.getNumChannels();
	isMono = audioFile.isMono();
	isStereo = audioFile.isStereo();
	
	/*Show .WAV File Summary*/
	audioFile.printSummary();
	std::vector<std::vector<double>> VetorAudio = audioFile.samples;

	
	/*************************************************************************************/
	/************************************ AUDIO BUFFER ***********************************/
	/*************************************************************************************/
	
	///*AudioBuffer*/
	AudioFile<double>::AudioBuffer audioBuffer;
	///*Set Number of Channels*/
	audioBuffer.resize(2);

	///*Set number of samples per channel*/ 
	audioBuffer[0].resize(100000);
	audioBuffer[1].resize(100000);

	unsigned int numChannels_02{ 2 };
	unsigned int numSamplesPerChannel_02{ 100000 };
	float sampleRate_02{ 44100.f };
	float frequency{ 440.f };
	

	for (int i = 0; i < numSamplesPerChannel_02; ++i)
	{
		for (int channel = 0; channel < numChannels_02; ++channel)	
			audioBuffer[channel][i] = sinf(2. * M_PI * ((float)i / sampleRate_02) * frequency) * 0.5;
	}
	
	AudioFile<double> createdAudioFile;
	createdAudioFile.setAudioBufferSize(numChannels_02, numSamplesPerChannel_02);
	createdAudioFile.setBitDepth(24);
	createdAudioFile.setSampleRate(sampleRate_02);
	createdAudioFile.printSummary();
	
	// 5. Put into the CreatedAudioFile object
	bool ok = createdAudioFile.setAudioBuffer(audioBuffer);

	createdAudioFile.save("F:/Mestrado/PDS/sample_test.wav", AudioFileFormat::Wave);
	
	

	system("PAUSE");
	return EXIT_SUCCESS;
}