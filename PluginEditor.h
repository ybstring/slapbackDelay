/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SlapbackDelayAudioProcessorEditor  : public juce::AudioProcessorEditor, 
                                           private juce::Slider::Listener
{
public:
    SlapbackDelayAudioProcessorEditor (SlapbackDelayAudioProcessor&);
    ~SlapbackDelayAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged(juce::Slider* slider) override;
    SlapbackDelayAudioProcessor& audioProcessor;
    juce::Slider delayControl;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlapbackDelayAudioProcessorEditor)
};
