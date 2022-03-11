/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SlapbackDelayAudioProcessorEditor::SlapbackDelayAudioProcessorEditor (SlapbackDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    float pluginWidth = 712;
    float pluginHeight = 400;
    setSize(pluginWidth, pluginHeight);

    delayControl.setSliderStyle(juce::Slider::LinearBar);
    delayControl.setRange(0.0, 250.0, 0.1);
    delayControl.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    delayControl.setPopupDisplayEnabled(true, true, this);
    delayControl.setTextValueSuffix(" ms");
    delayControl.setValue(1.0);

    addAndMakeVisible(&delayControl);

    delayControl.addListener(this);
}

SlapbackDelayAudioProcessorEditor::~SlapbackDelayAudioProcessorEditor()
{
}

void SlapbackDelayAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) 
{
    audioProcessor.currentDelay1 = delayControl.getValue();
}

//==============================================================================
void SlapbackDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::turquoise);

    g.setColour (juce::Colours::white);
    g.setFont (50.0f);
    g.drawFittedText ("Slapback Delay", 0, 50, getWidth(), 30, juce::Justification::centred, 1);
    g.setFont(25.0f);
    g.drawFittedText("Delay Time (ms)", 0, 250, getWidth(), 30, juce::Justification::centred, 1);
}

void SlapbackDelayAudioProcessorEditor::resized()
{
    delayControl.setBounds(89, 150, 534, 100);
}
