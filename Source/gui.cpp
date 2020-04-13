/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "gui.h"
#include "Aleatorio.h"
#include <windows.h>


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

//==============================================================================


gui::gui ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]
    

    jogar.reset (new TextButton ("jogar"));
    addAndMakeVisible (jogar.get());
    jogar->setButtonText (TRANS("Jogar"));
    jogar->addListener (this);
    jogar->setColour (TextButton::buttonColourId, Colour (0xff325dff));

    jogar->setBounds (300, 400, 150, 50);

    addAndMakeVisible(title);
    title.setColour(Label::backgroundColourId, Colours::transparentBlack);
    title.setColour(Label::textColourId, Colours::gold);
    title.setFont(Font(40.0f, Font::bold));
    title.setText("Game of Ur", dontSendNotification);

    title.setJustificationType(Justification::centred);
    title.setBounds(230, 10, 300, 100);

    addAndMakeVisible(subtitle);
    subtitle.setColour(Label::backgroundColourId, Colours::transparentBlack);
    subtitle.setColour(Label::textColourId, Colours::gold);
    subtitle.setFont(Font(20.0f, Font::plain));
    subtitle.setText("4 tetrahedron dice", dontSendNotification);

    subtitle.setJustificationType(Justification::centred);
    subtitle.setBounds(230, 40, 300, 100);

    addAndMakeVisible(resultSum);
    resultSum.setColour(Label::backgroundColourId, Colours::transparentBlack);
    resultSum.setColour(Label::textColourId, Colours::white);
    resultSum.setFont(Font(80.0f, Font::plain));
    
    
    resultSum.setJustificationType(Justification::centred);
    resultSum.setBounds (230, 140, 300, 200);

    addAndMakeVisible(resulArray);
    resulArray.setColour(Label::backgroundColourId, Colours::transparentBlack);
    resulArray.setColour(Label::textColourId, Colours::white);
    resulArray.setFont(Font(50.0f, Font::plain));

    resulArray.setJustificationType(Justification::centred);
    resulArray.setBounds(230, 60, 300, 200);

    internalPath1.startNewSubPath (static_cast<float> (-268), 612.0f);
    internalPath1.lineTo (static_cast<float> (-268), static_cast<float> (-116));
    internalPath1.lineTo (868.0f, static_cast<float> (-116));
    internalPath1.lineTo (868.0f, 612.0f);
    internalPath1.closeSubPath();


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

gui::~gui()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    jogar = nullptr;
    //resultLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void gui::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    {
        float x = 0, y = 0;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath1, AffineTransform::translation(x, y));
        //g.drawText(lancarDado(), getLocalBounds(), Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void gui::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void gui::sumDelay(Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == jogar.get())
    {
        int sum[5];
        int* Dado = lancarDado(sum);

        gui::soma = std::to_string(Dado[4]);
        Sleep(1000);
        resultSum.setText(gui::soma, dontSendNotification);
    }
}

void gui::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]
    if (buttonThatWasClicked == jogar.get())
    {
        int sum[5];
        int* Dado = lancarDado(sum);
        
        gui::arrayResultados = std::to_string(Dado[0]) + " " + std::to_string(Dado[1]) + " " + std::to_string(Dado[2]) + " " + std::to_string(Dado[3]);
        
        resulArray.setText(gui::arrayResultados, sendNotification);
        //resultSum.setText("", dontSendNotification);
        
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]



//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="gui" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="800"
                 initialHeight="600">
  <BACKGROUND backgroundColour="ff323b44">
    <PATH pos="0 0 100 100" fill="solid: ff323042" hasStroke="0" nonZeroWinding="1">s -268 612 l -268 -116 l 868 -116 l 868 612 x</PATH>
  </BACKGROUND>
  <TEXTBUTTON name="jogar" id="230178aa389d650b" memberName="jogar" virtualName=""
              explicitFocusOrder="0" pos="300 300 150 50" bgColOff="ff325dff"
              buttonText="Jogar?" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <JUCERCOMP name="resultDisplay" id="892249214ee34d53" memberName="resultDisplay"
             virtualName="" explicitFocusOrder="0" pos="224 72 300 200" sourceFile=""
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

