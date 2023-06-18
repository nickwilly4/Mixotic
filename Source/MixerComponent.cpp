/*
  ==============================================================================

    MixerComponent.cpp
    Created: 16 Jun 2023 8:16:01pm
    Author:  Nick Aichholz

  ==============================================================================
*/

#include "MixerComponent.h"

//==============================================================================
//std::unique_ptr<juce::FileChooser> chooser;
//juce::AudioFormatManager formatManager;

// 'Global' Variables
auto windowWidth = 450;
auto windowHeight = 700;

MixerComponent::MixerComponent()
{
    // Window
    setSize (windowWidth, windowHeight);
    
    // Load
    addAndMakeVisible(load_chn1);
    load_chn1.onClick = [&]() {printf("test");};
    
    // Channel Trim
    addAndMakeVisible(trim_chn1);
    trim_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    trim_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    trim_chn1.setRange(-24, 24);
    
    addAndMakeVisible(hi_chn1);
    hi_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    hi_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    hi_chn1.setRange(-24, 24);
    
    addAndMakeVisible(med_chn1);
    med_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    med_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    med_chn1.setRange(-24, 24);
    
    addAndMakeVisible(lo_chn1);
    lo_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    lo_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    lo_chn1.setRange(-24, 24);
    
    addAndMakeVisible(clr_chn1);
    clr_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    clr_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    clr_chn1.setRange(-24, 24);
    
    addAndMakeVisible(fx_chn1);
    fx_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    fx_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    fx_chn1.setRange(-24, 24);
    
    // FX Toggle
    addAndMakeVisible(fxtoggle_chn1);
    fxtoggle_chn1.setClickingTogglesState(true);
    fxtoggle_chn1.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    fxtoggle_chn1.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    fxtoggle_chn1.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    fxtoggle_chn1.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    // Cue Toggle
    addAndMakeVisible(cuetoggle_chn1);
    cuetoggle_chn1.setClickingTogglesState(true);
    cuetoggle_chn1.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    cuetoggle_chn1.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    cuetoggle_chn1.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    cuetoggle_chn1.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    // Volume fader
    addAndMakeVisible(volFader);
    volFader.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    //volFader.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 72, 32);
    volFader.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    volFader.setRange(-24, 24,0.1);
    
    
}

MixerComponent::~MixerComponent()
{
}

//==============================================================================
void MixerComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setFont (juce::Font (48.0f));
    //g.setColour (juce::Colours::green);
    //g.drawText ("New Graphics!", getLocalBounds(), juce::Justification::centred, true);
}

void MixerComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.\
    
    // Convenient
    auto margin = 10;
    auto space = 10;
    auto biggerSpace = 2*space;
    
    auto labelHeight = 10;
    auto labelSpace = 10;
    
    // Button
    auto buttonWidth = 60;
    auto buttonHeight = buttonWidth/3;
    
    // Volume fader
    auto faderWidth = 50;
    auto faderHeight = 150;
    
    load_chn1.setBounds(margin, margin, buttonWidth, buttonHeight);
    
    // Dial
    auto dialDim = 60;
    auto chn1_x = margin;
    
    trim_chn1.setBounds(chn1_x, load_chn1.getY()+buttonHeight+space, dialDim, dialDim);
    trim_chn1.setDoubleClickReturnValue(true, 0);
    
    hi_chn1.setBounds(chn1_x, trim_chn1.getY()+dialDim+space, dialDim, dialDim);
    hi_chn1.setDoubleClickReturnValue(true, 0);
    
    med_chn1.setBounds(chn1_x, hi_chn1.getY()+dialDim+space, dialDim, dialDim);
    med_chn1.setDoubleClickReturnValue(true, 0);
    
    lo_chn1.setBounds(chn1_x, med_chn1.getY()+dialDim+space, dialDim, dialDim);
    lo_chn1.setDoubleClickReturnValue(true, 0);
    
    clr_chn1.setBounds(chn1_x, lo_chn1.getY()+dialDim+space, dialDim, dialDim);
    clr_chn1.setDoubleClickReturnValue(true, 0);
    
    fx_chn1.setBounds(chn1_x, clr_chn1.getY()+dialDim+space, dialDim, dialDim);
    fx_chn1.setDoubleClickReturnValue(true, 0);
    
    // Toggle Buttons
    fxtoggle_chn1.setBounds(chn1_x, fx_chn1.getY()+dialDim+space, buttonWidth, buttonHeight);
    cuetoggle_chn1.setBounds(chn1_x, fxtoggle_chn1.getY()+buttonHeight+biggerSpace, buttonWidth, buttonHeight);
    
    // Volume fader
    volFader.setBounds(chn1_x, windowHeight-margin-faderHeight, faderWidth, faderHeight);
}
