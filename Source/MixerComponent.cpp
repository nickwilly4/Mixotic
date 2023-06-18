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
    
    // ========Channel 1========
    // ========Load 1========
    addAndMakeVisible(load_chn1);
    load_chn1.setButtonText("Load 1");
    load_chn1.onClick = [&]() {printf("test");};
    // ========Dials 1========
    addAndMakeVisible(trim_chn1);
    trim_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    trim_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    trim_chn1.setRange(-24, 24);
    //
    addAndMakeVisible(hi_chn1);
    hi_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    hi_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    hi_chn1.setRange(-24, 24);
    //
    addAndMakeVisible(med_chn1);
    med_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    med_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    med_chn1.setRange(-24, 24);
    //
    addAndMakeVisible(lo_chn1);
    lo_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    lo_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    lo_chn1.setRange(-24, 24);
    //
    addAndMakeVisible(clr_chn1);
    clr_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    clr_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    clr_chn1.setRange(-24, 24);
    //
    addAndMakeVisible(fx_chn1);
    fx_chn1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    fx_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    fx_chn1.setRange(-24, 24);
    // ========Toggle Buttons 1========
    addAndMakeVisible(fxtoggle_chn1);
    fxtoggle_chn1.setClickingTogglesState(true);
    fxtoggle_chn1.setButtonText("FX 1");
    fxtoggle_chn1.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    fxtoggle_chn1.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    fxtoggle_chn1.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    fxtoggle_chn1.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    //
    addAndMakeVisible(cuetoggle_chn1);
    cuetoggle_chn1.setButtonText("CUE 1");
    cuetoggle_chn1.setClickingTogglesState(true);
    cuetoggle_chn1.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    cuetoggle_chn1.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    cuetoggle_chn1.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    cuetoggle_chn1.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    // ========Volume Fader 1========
    addAndMakeVisible(volFader_chn1);
    volFader_chn1.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    //volFader.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 72, 32);
    volFader_chn1.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    volFader_chn1.setRange(-24, 24,0.1);
    // ========End Channel 1========
    
    // ========Channel 2========
    // ========Load 2========
    addAndMakeVisible(load_chn2);
    load_chn2.setButtonText("Load 2");
    load_chn2.onClick = [&]() {printf("test");};
    // ========Dials 2========
    addAndMakeVisible(trim_chn2);
    trim_chn2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    trim_chn2.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    trim_chn2.setRange(-24, 24);
    //
    addAndMakeVisible(hi_chn2);
    hi_chn2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    hi_chn2.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    hi_chn2.setRange(-24, 24);
    //
    addAndMakeVisible(med_chn2);
    med_chn2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    med_chn2.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    med_chn2.setRange(-24, 24);
    //
    addAndMakeVisible(lo_chn2);
    lo_chn2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    lo_chn2.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    lo_chn2.setRange(-24, 24);
    //
    addAndMakeVisible(clr_chn2);
    clr_chn2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    clr_chn2.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    clr_chn2.setRange(-24, 24);
    //
    addAndMakeVisible(fx_chn2);
    fx_chn2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    fx_chn2.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    fx_chn2.setRange(-24, 24);
    // ========Toggle Buttons 2========
    addAndMakeVisible(fxtoggle_chn2);
    fxtoggle_chn2.setClickingTogglesState(true);
    fxtoggle_chn2.setButtonText("FX 2");
    fxtoggle_chn2.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    fxtoggle_chn2.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    fxtoggle_chn2.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    fxtoggle_chn2.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    //
    addAndMakeVisible(cuetoggle_chn2);
    cuetoggle_chn2.setButtonText("CUE 2");
    cuetoggle_chn2.setClickingTogglesState(true);
    cuetoggle_chn2.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    cuetoggle_chn2.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    cuetoggle_chn2.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    cuetoggle_chn2.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    // ========Volume Fader 2========
    addAndMakeVisible(volFader_chn2);
    volFader_chn2.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    //volFader.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 72, 32);
    volFader_chn2.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    volFader_chn2.setRange(-24, 24,0.1);
    // ========End Channel 2========
    
    // ========Channel 3========
    // ========Load 3========
    addAndMakeVisible(load_chn3);
    load_chn3.setButtonText("Load 3");
    load_chn3.onClick = [&]() {printf("test");};
    // ========Dials 3========
    addAndMakeVisible(trim_chn3);
    trim_chn3.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    trim_chn3.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    trim_chn3.setRange(-24, 24);
    //
    addAndMakeVisible(hi_chn3);
    hi_chn3.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    hi_chn3.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    hi_chn3.setRange(-24, 24);
    //
    addAndMakeVisible(med_chn3);
    med_chn3.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    med_chn3.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    med_chn3.setRange(-24, 24);
    //
    addAndMakeVisible(lo_chn3);
    lo_chn3.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    lo_chn3.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    lo_chn3.setRange(-24, 24);
    //
    addAndMakeVisible(clr_chn3);
    clr_chn3.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    clr_chn3.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    clr_chn3.setRange(-24, 24);
    //
    addAndMakeVisible(fx_chn3);
    fx_chn3.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    fx_chn3.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    fx_chn3.setRange(-24, 24);
    // ========Toggle Buttons 3========
    addAndMakeVisible(fxtoggle_chn3);
    fxtoggle_chn3.setButtonText("FX 3");
    fxtoggle_chn3.setClickingTogglesState(true);
    fxtoggle_chn3.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    fxtoggle_chn3.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    fxtoggle_chn3.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    fxtoggle_chn3.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    //
    addAndMakeVisible(cuetoggle_chn3);
    cuetoggle_chn3.setButtonText("CUE 3");
    cuetoggle_chn3.setClickingTogglesState(true);
    cuetoggle_chn3.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    cuetoggle_chn3.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    cuetoggle_chn3.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    cuetoggle_chn3.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    // ========Volume Fader 3========
    addAndMakeVisible(volFader_chn3);
    volFader_chn3.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    //volFader.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 73, 33);
    volFader_chn3.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    volFader_chn3.setRange(-24, 24,0.1);
    // ========End Channel 3========
    
    // ========Channel 4========
    // ========Load 4========
    addAndMakeVisible(load_chn4);
    load_chn4.setButtonText("Load 4");
    load_chn4.onClick = [&]() {printf("test");};
    // ========Dials 4========
    addAndMakeVisible(trim_chn4);
    trim_chn4.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    trim_chn4.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    trim_chn4.setRange(-24, 24);
    //
    addAndMakeVisible(hi_chn4);
    hi_chn4.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    hi_chn4.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    hi_chn4.setRange(-24, 24);
    //
    addAndMakeVisible(med_chn4);
    med_chn4.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    med_chn4.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    med_chn4.setRange(-24, 24);
    //
    addAndMakeVisible(lo_chn4);
    lo_chn4.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    lo_chn4.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    lo_chn4.setRange(-24, 24);
    //
    addAndMakeVisible(clr_chn4);
    clr_chn4.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    clr_chn4.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    clr_chn4.setRange(-24, 24);
    //
    addAndMakeVisible(fx_chn4);
    fx_chn4.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    fx_chn4.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    fx_chn4.setRange(-24, 24);
    // ========Toggle Buttons 4========
    addAndMakeVisible(fxtoggle_chn4);
    fxtoggle_chn4.setButtonText("FX 4");
    fxtoggle_chn4.setClickingTogglesState(true);
    fxtoggle_chn4.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    fxtoggle_chn4.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    fxtoggle_chn4.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    fxtoggle_chn4.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    //
    addAndMakeVisible(cuetoggle_chn4);
    cuetoggle_chn4.setButtonText("CUE 4");
    cuetoggle_chn4.setClickingTogglesState(true);
    cuetoggle_chn4.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    cuetoggle_chn4.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    cuetoggle_chn4.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    cuetoggle_chn4.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    // ========Volume Fader 4========
    addAndMakeVisible(volFader_chn4);
    volFader_chn4.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    //volFader.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 74, 44);
    volFader_chn4.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    volFader_chn4.setRange(-24, 24,0.1);
    // ========End Channel 4========
    
    
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
    
    //auto labelHeight = 10;
    //auto labelSpace = 10;
    
    // Button
    auto buttonWidth = 60;
    auto buttonHeight = buttonWidth/3;
    
    // Volume fader
    auto faderWidth = 50;
    auto faderHeight = 150;
    
    // Dial
    auto dialDim = 60;
    
    // ========Channel 1========
    auto chn1_x = margin+1*(dialDim+space); // Order of the channels margin
    // ========Load 1========
    load_chn1.setBounds(chn1_x, margin, buttonWidth, buttonHeight);
    // ========Dials 1========
    trim_chn1.setBounds(chn1_x, load_chn1.getY()+buttonHeight+space, dialDim, dialDim);
    trim_chn1.setDoubleClickReturnValue(true, 0);
    //
    hi_chn1.setBounds(chn1_x, trim_chn1.getY()+dialDim+space, dialDim, dialDim);
    hi_chn1.setDoubleClickReturnValue(true, 0);
    //
    med_chn1.setBounds(chn1_x, hi_chn1.getY()+dialDim+space, dialDim, dialDim);
    med_chn1.setDoubleClickReturnValue(true, 0);
    //
    lo_chn1.setBounds(chn1_x, med_chn1.getY()+dialDim+space, dialDim, dialDim);
    lo_chn1.setDoubleClickReturnValue(true, 0);
    //
    clr_chn1.setBounds(chn1_x, lo_chn1.getY()+dialDim+space, dialDim, dialDim);
    clr_chn1.setDoubleClickReturnValue(true, 0);
    //
    fx_chn1.setBounds(chn1_x, clr_chn1.getY()+dialDim+space, dialDim, dialDim);
    fx_chn1.setDoubleClickReturnValue(true, 0);
    // ========Toggle Buttons 1========
    fxtoggle_chn1.setBounds(chn1_x, fx_chn1.getY()+dialDim+space, buttonWidth, buttonHeight);
    cuetoggle_chn1.setBounds(chn1_x, fxtoggle_chn1.getY()+buttonHeight+biggerSpace, buttonWidth, buttonHeight);
    // ========Volume Fader 1========
    volFader_chn1.setBounds(chn1_x, windowHeight-margin-faderHeight, faderWidth, faderHeight);
    // ========End Channel 1========
    
    // ========Channel 2========
    auto chn2_x = windowWidth-margin-space-2*dialDim; // Order of the channels margin+1*(dialDim+space)
    // ========Load 2========
    load_chn2.setBounds(chn2_x, margin, buttonWidth, buttonHeight);
    // ========Dials 2========
    trim_chn2.setBounds(chn2_x, load_chn2.getY()+buttonHeight+space, dialDim, dialDim);
    trim_chn2.setDoubleClickReturnValue(true, 0);
    //
    hi_chn2.setBounds(chn2_x, trim_chn2.getY()+dialDim+space, dialDim, dialDim);
    hi_chn2.setDoubleClickReturnValue(true, 0);
    //
    med_chn2.setBounds(chn2_x, hi_chn2.getY()+dialDim+space, dialDim, dialDim);
    med_chn2.setDoubleClickReturnValue(true, 0);
    //
    lo_chn2.setBounds(chn2_x, med_chn2.getY()+dialDim+space, dialDim, dialDim);
    lo_chn2.setDoubleClickReturnValue(true, 0);
    //
    clr_chn2.setBounds(chn2_x, lo_chn2.getY()+dialDim+space, dialDim, dialDim);
    clr_chn2.setDoubleClickReturnValue(true, 0);
    //
    fx_chn2.setBounds(chn2_x, clr_chn2.getY()+dialDim+space, dialDim, dialDim);
    fx_chn2.setDoubleClickReturnValue(true, 0);
    // ========Toggle Buttons 2========
    fxtoggle_chn2.setBounds(chn2_x, fx_chn2.getY()+dialDim+space, buttonWidth, buttonHeight);
    cuetoggle_chn2.setBounds(chn2_x, fxtoggle_chn2.getY()+buttonHeight+biggerSpace, buttonWidth, buttonHeight);
    // ========Volume Fader 2========
    volFader_chn2.setBounds(chn2_x, windowHeight-margin-faderHeight, faderWidth, faderHeight);
    // ========End Channel 2========
    
    // ========Channel 3========
    auto chn3_x = margin; // Order of the channels windowWidth-margin-space-2*dialDim
    // ========Load 3========
    load_chn3.setBounds(chn3_x, margin, buttonWidth, buttonHeight);
    // ========Dials 3========
    trim_chn3.setBounds(chn3_x, load_chn3.getY()+buttonHeight+space, dialDim, dialDim);
    trim_chn3.setDoubleClickReturnValue(true, 0);
    //
    hi_chn3.setBounds(chn3_x, trim_chn3.getY()+dialDim+space, dialDim, dialDim);
    hi_chn3.setDoubleClickReturnValue(true, 0);
    //
    med_chn3.setBounds(chn3_x, hi_chn3.getY()+dialDim+space, dialDim, dialDim);
    med_chn3.setDoubleClickReturnValue(true, 0);
    //
    lo_chn3.setBounds(chn3_x, med_chn3.getY()+dialDim+space, dialDim, dialDim);
    lo_chn3.setDoubleClickReturnValue(true, 0);
    //
    clr_chn3.setBounds(chn3_x, lo_chn3.getY()+dialDim+space, dialDim, dialDim);
    clr_chn3.setDoubleClickReturnValue(true, 0);
    //
    fx_chn3.setBounds(chn3_x, clr_chn3.getY()+dialDim+space, dialDim, dialDim);
    fx_chn3.setDoubleClickReturnValue(true, 0);
    // ========Toggle Buttons 3========
    fxtoggle_chn3.setBounds(chn3_x, fx_chn3.getY()+dialDim+space, buttonWidth, buttonHeight);
    cuetoggle_chn3.setBounds(chn3_x, fxtoggle_chn3.getY()+buttonHeight+biggerSpace, buttonWidth, buttonHeight);
    // ========Volume Fader 3========
    volFader_chn3.setBounds(chn3_x, windowHeight-margin-faderHeight, faderWidth, faderHeight);
    // ========End Channel 3========
    
    // ========Channel 4========
    auto chn4_x = windowWidth-margin-dialDim; // Order of the channels windowWidth-margin-dialDim
    // ========Load 4========
    load_chn4.setBounds(chn4_x, margin, buttonWidth, buttonHeight);
    // ========Dials 4========
    trim_chn4.setBounds(chn4_x, load_chn4.getY()+buttonHeight+space, dialDim, dialDim);
    trim_chn4.setDoubleClickReturnValue(true, 0);
    //
    hi_chn4.setBounds(chn4_x, trim_chn4.getY()+dialDim+space, dialDim, dialDim);
    hi_chn4.setDoubleClickReturnValue(true, 0);
    //
    med_chn4.setBounds(chn4_x, hi_chn4.getY()+dialDim+space, dialDim, dialDim);
    med_chn4.setDoubleClickReturnValue(true, 0);
    //
    lo_chn4.setBounds(chn4_x, med_chn4.getY()+dialDim+space, dialDim, dialDim);
    lo_chn4.setDoubleClickReturnValue(true, 0);
    //
    clr_chn4.setBounds(chn4_x, lo_chn4.getY()+dialDim+space, dialDim, dialDim);
    clr_chn4.setDoubleClickReturnValue(true, 0);
    //
    fx_chn4.setBounds(chn4_x, clr_chn4.getY()+dialDim+space, dialDim, dialDim);
    fx_chn4.setDoubleClickReturnValue(true, 0);
    // ========Toggle Buttons 4========
    fxtoggle_chn4.setBounds(chn4_x, fx_chn4.getY()+dialDim+space, buttonWidth, buttonHeight);
    cuetoggle_chn4.setBounds(chn4_x, fxtoggle_chn4.getY()+buttonHeight+biggerSpace, buttonWidth, buttonHeight);
    // ========Volume Fader 4========
    volFader_chn4.setBounds(chn4_x, windowHeight-margin-faderHeight, faderWidth, faderHeight);
    // ========End Channel 4========
}
