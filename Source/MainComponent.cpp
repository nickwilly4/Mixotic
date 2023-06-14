#include "MainComponent.h"

//==============================================================================

// 'Global' Variables
auto windowWidth = 450;
auto windowHeight = 800;

MainComponent::MainComponent()
{
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
    
    addAndMakeVisible(loopOut);
    loopOut.setClickingTogglesState(true);
    loopOut.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::orange);
    loopOut.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    loopOut.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    loopOut.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(loopRe);
    loopRe.setClickingTogglesState(false);
    loopRe.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    loopRe.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    loopRe.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    loopRe.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(loopHalf);
    loopHalf.setClickingTogglesState(false);
    loopHalf.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    loopHalf.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    loopHalf.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    loopHalf.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    addAndMakeVisible(loopDouble);
    loopDouble.setClickingTogglesState(false);
    loopDouble.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    loopDouble.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    loopDouble.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    loopDouble.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    
    // Channel switch
    addAndMakeVisible(channelSwitch);
    channelSwitch.setClickingTogglesState(true);
    channelSwitch.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::blue);
    channelSwitch.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    channelSwitch.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    channelSwitch.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (48.0f));
    g.setColour (juce::Colours::green);
    g.drawText ("New Graphics!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.\
    
    // Convenient
    auto margin = 10;
    auto space = 10;
    auto biggerSpace = 2*space;
    
    auto buttonWidth = 50;
    auto buttonHeight = 50;
    
    auto smallButtonWidth = 20;
    auto smallButtonHeight = 20;
    
    auto padWidth = 60;
    auto padHeight = 60;
    
    auto padModeWidth = padWidth;
    auto padModeHeight = padHeight/3;
    
    auto loopBigWidth = 40;
    auto loopBigHeight = 40;
    
    auto channelWidth = 80;
    auto channelHeight = channelWidth/2;
    
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
    
    // Loop
    loopIn.setBounds(margin, margin, loopBigWidth, loopBigHeight);
    loopOut.setBounds(margin+loopBigWidth+space, margin, loopBigWidth, loopBigHeight);
    loopRe.setBounds(margin+loopBigWidth+space+loopBigWidth+biggerSpace, margin, smallButtonWidth, smallButtonHeight);
    loopHalf.setBounds(margin+loopBigWidth+space+loopBigWidth+biggerSpace+smallButtonWidth+space, margin, smallButtonWidth, smallButtonHeight);
    loopDouble.setBounds(margin+loopBigWidth+space+loopBigWidth+biggerSpace+2*smallButtonWidth+2*space, margin, smallButtonWidth, smallButtonHeight);
    
    // Channel switch
    channelSwitch.setBounds(windowWidth-margin-channelWidth, margin, channelWidth, channelHeight);
}
