/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#define M_PI

//==============================================================================
/**
*/
class SlapbackDelayAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    SlapbackDelayAudioProcessor();
    ~SlapbackDelayAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //==============================================================================
    void fillDelayBuffer(int channel, const int bufferLength, const int delayBufferLength,
                         const float* bufferData, const float* delayBufferData);
    void SlapbackDelayAudioProcessor::getFromDelayBuffer(juce::AudioBuffer<float>& buffer,
                                                         int channel, const int bufferLength,
                                                         const int delayBufferLength, const float* bufferData,
                                                         const float* delayBufferData); 

    float currentDelay1 = 0;

private:
    //==============================================================================
    juce::AudioBuffer<float> mDelayBuffer;
    int mWritePosition = 0;
    int mSampleRate = 44100;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlapbackDelayAudioProcessor)
};
