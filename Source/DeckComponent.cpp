/*
  ==============================================================================

    DeckComponent.cpp
    Created: 21 Jun 2023 5:37:24pm
    Author:  Nick Aichholz

  ==============================================================================
*/

#include "DeckComponent.h"

DeckComponent::DeckComponent(const std::string& channelNumber)
: channelNum(channelNumber), currentMode(Mode::Mode1), backgroundColor(juce::Colours::blue)
{
    auto windowWidth = 450;
    auto windowHeight = 700;
    
    // Window
    setSize (windowWidth, windowHeight);
    
    // Play Pause Button
    addAndMakeVisible(playPause);
    playPause.setButtonText("Play");
    playPause.setClickingTogglesState(true);
    playPause.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::lightgoldenrodyellow);
    playPause.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    playPause.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    playPause.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    // Cue Button
    addAndMakeVisible(cue);
    cue.setButtonText("Cue");
    cue.setClickingTogglesState(true);
    cue.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::lightgoldenrodyellow);
    cue.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    cue.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    cue.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    // Pads
    auto padColor = juce::Colours::red;
    auto padToggleState = true;
    addAndMakeVisible(padBottom1);
    padBottom1.setClickingTogglesState(padToggleState);
    padBottom1.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padBottom1.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padBottom1.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padBottom1.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    //padBottom1.onClick = [this] {openButtonClicked(); };
    padBottom1.onClick = [&]() {printf("test");};
    
    addAndMakeVisible(padBottom2);
    padBottom2.setClickingTogglesState(padToggleState);
    padBottom2.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padBottom2.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padBottom2.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padBottom2.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padBottom3);
    padBottom3.setClickingTogglesState(padToggleState);
    padBottom3.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padBottom3.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padBottom3.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padBottom3.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padBottom4);
    padBottom4.setClickingTogglesState(padToggleState);
    padBottom4.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padBottom4.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padBottom4.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padBottom4.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padTop1);
    padTop1.setClickingTogglesState(padToggleState);
    padTop1.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padTop1.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padTop1.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padTop1.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padTop2);
    padTop2.setClickingTogglesState(padToggleState);
    padTop2.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padTop2.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padTop2.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padTop2.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padTop3);
    padTop3.setClickingTogglesState(padToggleState);
    padTop3.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padTop3.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padTop3.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padTop3.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padTop4);
    padTop4.setClickingTogglesState(padToggleState);
    padTop4.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padTop4.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padTop4.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padTop4.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    // Pad Mode buttons
    addAndMakeVisible(padMode1);
    padMode1.setClickingTogglesState(true);
    padMode1.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padMode1.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padMode1.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padMode1.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padMode2);
    padMode2.setClickingTogglesState(true);
    padMode2.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padMode2.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padMode2.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padMode2.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padMode3);
    padMode3.setClickingTogglesState(true);
    padMode3.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padMode3.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padMode3.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padMode3.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(padMode4);
    padMode4.setClickingTogglesState(true);
    padMode4.setColour(juce::TextButton::ColourIds::buttonOnColourId, padColor);
    padMode4.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    padMode4.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    padMode4.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    // Loop Buttons
    addAndMakeVisible(loopIn);
    loopIn.setClickingTogglesState(true);
    loopIn.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::orange);
    loopIn.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    loopIn.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    loopIn.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    addAndMakeVisible(loopInLabel);
    loopInLabel.setText("In", juce::dontSendNotification);
    
    addAndMakeVisible(loopOut);
    loopOut.setClickingTogglesState(true);
    loopOut.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::orange);
    loopOut.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    loopOut.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    loopOut.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    addAndMakeVisible(loopOutLabel);
    loopOutLabel.setText("Out", juce::dontSendNotification);
    
    addAndMakeVisible(loopRe);
    loopRe.setClickingTogglesState(false);
    loopRe.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    loopRe.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    loopRe.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    loopRe.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    addAndMakeVisible(loopReLabel);
    loopReLabel.setText("Re", juce::dontSendNotification);
    
    addAndMakeVisible(loopHalf);
    loopHalf.setClickingTogglesState(false);
    loopHalf.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    loopHalf.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    loopHalf.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    loopHalf.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    addAndMakeVisible(loopHalfLabel);
    loopHalfLabel.setText("1/2", juce::dontSendNotification);
    
    addAndMakeVisible(loopDouble);
    loopDouble.setClickingTogglesState(false);
    loopDouble.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    loopDouble.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    loopDouble.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    loopDouble.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    addAndMakeVisible(loopDoubleLabel);
    loopDoubleLabel.setText("2", juce::dontSendNotification);
    
    // Channel switch
    channelLabel.setText(channelNumber, juce::dontSendNotification);
    addAndMakeVisible(channelLabel);
    
    addAndMakeVisible(channelSlide);
    channelSlide.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    channelSlide.setTextBoxStyle(juce::Slider::NoTextBox, false, 72, 32);
    channelSlide.setRange(0, 1,1);
    channelSlide.addListener(this);
    
    // Volume fader
    addAndMakeVisible(volFader);
    volFader.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    volFader.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 72, 32);
    volFader.setRange(-24, 24,0.1);
    
    // Jog wheel
    addAndMakeVisible(jog);
    jog.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    jog.setTextBoxStyle(juce::Slider::NoTextBox, false, 1, 1);
    jog.setRange(0, 100);
}

DeckComponent::~DeckComponent()
{
    channelSlide.removeListener(this);
}

void DeckComponent::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &channelSlide)
    {
        // Check the value of the channelSlide slider and switch modes accordingly
        if (channelSlide.getValue() == 0)
        {
            currentMode = Mode::Mode1;
            backgroundColor = juce::Colours::blue;
            std::cout << "Deck " << channelNum << " is in " << currentMode << " mode!" << std::endl;
        }
        else
        {
            currentMode = Mode::Mode2;
            backgroundColor = juce::Colours::red;
            std::cout << "Deck " << channelNum << " is in " << currentMode << " mode!" << std::endl;
        }

        // Repaint the component to reflect the new background color
        repaint();
    }
}

/*void DeckComponent::setMode(Mode newMode) {
    currentMode = newMode;
    switch(currentMode) {
        case Mode1:
            backgroundColor = juce::Colours::red;
            std::cout << "Deck " << channelNum << " is in " << currentMode << " mode!" << std::endl;
            // Code to set up Mode 1
            break;
        case Mode2:
            backgroundColor = juce::Colours::blue;
            std::cout << "Deck " << channelNum << " is in " << currentMode << " mode!" << std::endl;
            // Code to set up Mode 2
            break;
    }
    repaint(); // Request a repaint since the background color has changed
}*/

//==============================================================================
void DeckComponent::paint (juce::Graphics& g)
{
    // Fill the background with the current background color
    g.fillAll(backgroundColor);

    // Rest of your painting code
    // ...
}

void DeckComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.\
    
    auto windowWidth = 450;
    auto windowHeight = 700;
    
    // Convenient
    auto margin = 10;
    auto space = 10;
    auto biggerSpace = 2*space;
    
    auto labelHeight = 10;
    auto labelSpace = 10;
    
    // Play pause button
    auto buttonWidth = 75; // needs to be 1.25 * padWidth
    auto buttonHeight = buttonWidth;
    
    // Reloop, 1/2, 2 buttons
    auto smallButtonWidth = 30;
    auto smallButtonHeight = smallButtonWidth;
    
    // In and Out loop buttons
    auto loopBigWidth = 50;
    auto loopBigHeight = loopBigWidth;
    
    // Pads
    auto padWidth = 60;
    auto padHeight = padWidth;
    
    // Pad mode buttons
    auto padModeWidth = padWidth;
    auto padModeHeight = padHeight/3;
    
    // Channel toggle 'switch' button
    auto channelWidth = 40;
    auto channelHeight = channelWidth/2;
    
    // Volume fader
    auto faderWidth = 50;
    auto faderHeight = 200;
    
    // Play Pause Button
    playPause.setBounds(margin, windowHeight-margin-buttonHeight, buttonWidth, buttonHeight);
    
    // Cue Button
    cue.setBounds(margin, windowHeight-playPause.getHeight()-margin-space-buttonHeight, buttonWidth, buttonHeight);
    
    // Pads
    padBottom1.setBounds(margin+buttonWidth+biggerSpace, windowHeight-margin-padHeight, padWidth, padHeight);
    padBottom2.setBounds(margin+buttonWidth+biggerSpace+padWidth+space, windowHeight-margin-padHeight, padWidth, padHeight);
    padBottom3.setBounds(margin+buttonWidth+biggerSpace+2*(padWidth+space), windowHeight-margin-padHeight, padWidth, padHeight);
    padBottom4.setBounds(margin+buttonWidth+biggerSpace+3*(padWidth+space), windowHeight-margin-padHeight, padWidth, padHeight);
    
    padTop1.setBounds(margin+buttonWidth+biggerSpace, windowHeight-margin-space-padHeight-padHeight, padWidth, padHeight);
    padTop2.setBounds(margin+buttonWidth+biggerSpace+padWidth+space, windowHeight-margin-space-padHeight-padHeight, padWidth, padHeight);
    padTop3.setBounds(margin+buttonWidth+biggerSpace+2*(padWidth+space), windowHeight-margin-space-padHeight-padHeight, padWidth, padHeight);
    padTop4.setBounds(margin+buttonWidth+biggerSpace+3*(padWidth+space), windowHeight-margin-space-padHeight-padHeight, padWidth, padHeight);
    
    // Pad Modes
    padMode1.setBounds(margin+buttonWidth+biggerSpace, windowHeight-margin-2*(space+padHeight)-padModeHeight, padModeWidth, padModeHeight);
    padMode2.setBounds(margin+buttonWidth+biggerSpace+padWidth+space, windowHeight-margin-2*(space+padHeight)-padModeHeight, padModeWidth, padModeHeight);
    padMode3.setBounds(margin+buttonWidth+biggerSpace+2*(padWidth+space), windowHeight-margin-2*(space+padHeight)-padModeHeight, padModeWidth, padModeHeight);
    padMode4.setBounds(margin+buttonWidth+biggerSpace+3*(padWidth+space), windowHeight-margin-2*(space+padHeight)-padModeHeight, padModeWidth, padModeHeight);
    
    // Big Loop buttons
    loopIn.setBounds(margin, margin, loopBigWidth, loopBigHeight);
    loopInLabel.setBounds(loopIn.getX(), loopIn.getY()+loopIn.getHeight()+labelSpace, loopBigWidth,labelHeight);
    
    loopOut.setBounds(loopIn.getX()+loopIn.getWidth()+space, margin, loopBigWidth, loopBigHeight);
    loopOutLabel.setBounds(loopOut.getX(), loopOut.getY()+loopOut.getHeight()+labelSpace, loopBigWidth,labelHeight);
    
    // Small Loop Buttons
    loopRe.setBounds(loopOut.getX()+loopOut.getWidth()+biggerSpace, margin, smallButtonWidth, smallButtonHeight);
    loopReLabel.setBounds(loopRe.getX(), loopRe.getY()+loopRe.getHeight()+labelSpace, loopBigWidth,labelHeight);
    
    loopHalf.setBounds(loopRe.getX()+loopRe.getWidth()+space, margin, smallButtonWidth, smallButtonHeight);
    loopHalfLabel.setBounds(loopHalf.getX(), loopHalf.getY()+loopHalf.getHeight()+labelSpace, loopBigWidth,labelHeight);
    
    loopDouble.setBounds(loopHalf.getX()+loopHalf.getWidth()+space, margin, smallButtonWidth, smallButtonHeight);
    loopDoubleLabel.setBounds(loopDouble.getX(), loopDouble.getY()+loopDouble.getHeight()+labelSpace, loopBigWidth,labelHeight);
    
    // Channel switch
    channelSlide.setBounds(windowWidth-margin-channelWidth, margin, channelWidth, channelHeight);
    channelLabel.setBounds(channelSlide.getX()+0*channelWidth, channelSlide.getY()+channelSlide.getHeight()+labelSpace, channelWidth,labelHeight);
    channelSlide.setRange(0, 1); // Assuming two modes: 0 for Mode1, 1 for Mode2
    channelSlide.setValue(0);    // Set the initial value to Mode1
    
    // Volume fader
    volFader.setBounds(windowWidth-margin-faderWidth, windowHeight-margin-faderHeight, faderWidth, faderHeight);
    
    // Jog wheel
    auto jogDim = (windowWidth-margin*2);
    jog.setBounds(margin, (windowHeight-jogDim)/2-50, jogDim, jogDim);
    //jog.setDoubleClickReturnValue(true, 0);
    
}

