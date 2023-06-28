/*
  ==============================================================================

    EQControlColumn.cpp
    Created: 21 Jun 2023 11:47:30am
    Author:  Nick Aichholz

  ==============================================================================
*/

#include "EQControlColumn.h"
#include "MainComponent.h"

// 'Global' Variables
auto EQwindowWidth = 80; // 2*margin+Width
auto EQwindowHeight = 700;

EQControlColumn::EQControlColumn(const std::string& columnNumber, MainComponent& mainComponentRef)
    : columnNum(columnNumber), mainComponent(mainComponentRef) // Initialize mainComponent here
{
    // Window
    setSize (EQwindowWidth, EQwindowHeight);
    
    // ========Load ========
    addAndMakeVisible(load_chn);
    load_chn.setButtonText("Load " +columnNumber);
    load_chn.onClick = [columnNumber, &mainComponentRef]() {
        mainComponentRef.onEQControlColumnLoadClicked(columnNumber);
    };
    // ========Dials ========
    addAndMakeVisible(trim_chn);
    trim_chn.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    trim_chn.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    trim_chn.setRange(-24, 24);
    //
    addAndMakeVisible(hi_chn);
    hi_chn.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    hi_chn.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    hi_chn.setRange(-24, 24);
    //
    addAndMakeVisible(med_chn);
    med_chn.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    med_chn.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    med_chn.setRange(-24, 24);
    //
    addAndMakeVisible(lo_chn);
    lo_chn.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    lo_chn.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    lo_chn.setRange(-24, 24);
    //
    addAndMakeVisible(clr_chn);
    clr_chn.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    clr_chn.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    clr_chn.setRange(-24, 24);
    //
    addAndMakeVisible(fx_chn);
    fx_chn.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    fx_chn.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    fx_chn.setRange(-24, 24);
    // ========Toggle Buttons ========
    addAndMakeVisible(fxtoggle_chn);
    fxtoggle_chn.setClickingTogglesState(true);
    fxtoggle_chn.setButtonText("FX "+columnNumber);
    fxtoggle_chn.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    fxtoggle_chn.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    fxtoggle_chn.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    fxtoggle_chn.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    //
    addAndMakeVisible(cuetoggle_chn);
    cuetoggle_chn.setButtonText("CUE "+columnNumber);
    cuetoggle_chn.setClickingTogglesState(true);
    cuetoggle_chn.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::red);
    cuetoggle_chn.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    cuetoggle_chn.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    cuetoggle_chn.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    // ========Volume Fader ========
    addAndMakeVisible(volFader_chn);
    volFader_chn.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    //volFader.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 72, 32);
    volFader_chn.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    volFader_chn.setRange(-24, 24,0.1);
    
    
}

EQControlColumn::~EQControlColumn()
{
}

//==============================================================================
void EQControlColumn::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void EQControlColumn::resized()
{
    // Convenient
    auto margin = 10;
    auto space = 10;
    auto biggerSpace = 2*space;
    
    //auto labelHeight = 10;
    //auto labelSpace = 10;
    auto Width = 60;
    // Button
    auto buttonWidth = Width;
    auto buttonHeight = buttonWidth/3;
    
    // Volume fader
    auto faderWidth = Width;
    auto faderHeight = 150;
    
    // Dial
    auto dialDim = Width;
    
    auto chn_x = margin; // Order of the channels margin
    // ========Load ========
    load_chn.setBounds(chn_x, margin, buttonWidth, buttonHeight);
    // ========Dials ========
    trim_chn.setBounds(chn_x, load_chn.getY()+buttonHeight+space, dialDim, dialDim);
    trim_chn.setDoubleClickReturnValue(true, 0);
    //
    hi_chn.setBounds(chn_x, trim_chn.getY()+dialDim+space, dialDim, dialDim);
    hi_chn.setDoubleClickReturnValue(true, 0);
    //
    med_chn.setBounds(chn_x, hi_chn.getY()+dialDim+space, dialDim, dialDim);
    med_chn.setDoubleClickReturnValue(true, 0);
    //
    lo_chn.setBounds(chn_x, med_chn.getY()+dialDim+space, dialDim, dialDim);
    lo_chn.setDoubleClickReturnValue(true, 0);
    //
    clr_chn.setBounds(chn_x, lo_chn.getY()+dialDim+space, dialDim, dialDim);
    clr_chn.setDoubleClickReturnValue(true, 0);
    //
    fx_chn.setBounds(chn_x, clr_chn.getY()+dialDim+space, dialDim, dialDim);
    fx_chn.setDoubleClickReturnValue(true, 0);
    // ========Toggle Buttons ========
    fxtoggle_chn.setBounds(chn_x, fx_chn.getY()+dialDim+space, buttonWidth, buttonHeight);
    cuetoggle_chn.setBounds(chn_x, fxtoggle_chn.getY()+buttonHeight+biggerSpace, buttonWidth, buttonHeight);
    // ========Volume Fader ========
    volFader_chn.setBounds(chn_x, EQwindowHeight-margin-faderHeight, faderWidth, faderHeight);
    
}
