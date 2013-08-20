#include "Interfaces.h"

//--------------------------------------------------------------
void Interfaces::setup(){
	draw();
	cout<<"its working";
	ofSetColor(255,255,255);
	ofRect(100,100,1000,1000);
	
	setUILogin();
	setUIRegister();
	setUIMain();
	setUIPractice();
	uimain->setVisible(false);
	uiregister->setVisible(false);
	uipractice->setVisible(false);
	
}

void Interfaces::setUILogin(){
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
	float length = 255-xInit;
	
	uilogin = new ofxUICanvas(0,0, length+xInit, ofGetHeight());
	uilogin->addWidgetDown(new ofxUILabel("SPEECH HERO", OFX_UI_FONT_LARGE));
	uilogin->addWidgetDown(new ofxUILabel("Username:", OFX_UI_FONT_MEDIUM));
	uilogin->addTextInput("TEXT INPUT", "InputText", length-xInit);
	uilogin->addWidgetDown(new ofxUILabel("Password:", OFX_UI_FONT_MEDIUM));
	uilogin->addTextInput("TEXT INPUT", "InputText", length-xInit)->setAutoClear(false);
	uilogin->addSpacer(length-xInit, 2);
	uilogin->addSpacer(length-xInit, 30);
	uilogin->addLabelButton("LOGIN", false, length-xInit);
	uilogin->addLabelButton("REGISTER", false, length-xInit);
    uilogin->addLabelButton("QUIT", false, length-xInit);
	
	ofAddListener(uilogin->newGUIEvent,this,&Interfaces::guiEvent);
}

void Interfaces::setUIRegister(){
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
	float length = 255-xInit;
	uiregister = new ofxUICanvas(length+xInit+15,0, ofGetWidth() - length-xInit-15, ofGetHeight());
	uiregister->addWidgetDown(new ofxUILabel("REGISTER", OFX_UI_FONT_LARGE));
	uiregister->addWidgetDown(new ofxUILabel("Parent:", OFX_UI_FONT_MEDIUM));
	uiregister->addWidgetDown(new ofxUILabel("Username:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit);
	uiregister->addWidgetDown(new ofxUILabel("Password:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit)->setAutoClear(false);
	uiregister->addWidgetDown(new ofxUILabel("Confirm Password:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit)->setAutoClear(false);
	uiregister->addSpacer(length-xInit, 2);
	uiregister->addWidgetDown(new ofxUILabel("Name:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit);
	uiregister->addWidgetDown(new ofxUILabel("Family Name:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit);
	uiregister->addSpacer(length-xInit, 2);
	uiregister->addWidgetDown(new ofxUILabel("Child:", OFX_UI_FONT_MEDIUM));
	uiregister->addWidgetDown(new ofxUILabel("Username:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit);
	uiregister->addWidgetDown(new ofxUILabel("Password:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit)->setAutoClear(false);
	uiregister->addWidgetDown(new ofxUILabel("Confirm Password:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit)->setAutoClear(false);
	uiregister->addSpacer(length-xInit, 2);
	uiregister->addWidgetDown(new ofxUILabel("Name:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit);
	uiregister->addWidgetDown(new ofxUILabel("Family Name:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "InputText", length-xInit);
	uiregister->addSpacer(length-xInit, 2);
	uiregister->addSpacer(length-xInit, 30);
	uiregister->addLabelButton("CREATE", false, length-xInit);
	uiregister->addLabelButton("CANCEL", false, length-xInit);
	
	ofAddListener(uiregister->newGUIEvent,this,&Interfaces::guiEvent);
}

void Interfaces::setUIMain(){
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
	float length = 255-xInit;
	float butSize = 0.59*ofGetWidth();
	uimain = new ofxUICanvas(0.2*ofGetWidth(),0, 0.6*ofGetWidth(), ofGetHeight());
	uimain->addWidgetDown(new ofxUILabel("SPEECH HERO", OFX_UI_FONT_LARGE));
	uimain->addSpacer(butSize, 2);
	
	uimain->addSpacer(butSize, 2);
	uimain->addSpacer(butSize, 30);
	uimain->addLabelButton("Play", false,butSize);
	uimain->addSpacer(0,15);
	uimain->addLabelButton("Highscores", false, butSize);
	uimain->addSpacer(0,15);
    uimain->addLabelButton("Sessions", false, butSize);
	uimain->addSpacer(0,15);
	uimain->addLabelButton("Options", false, butSize);
	uimain->addSpacer(0,15);
	uimain->addLabelButton("Practice", false, butSize);
	uimain->addSpacer(0,15);
	uimain->addLabelButton("Quit", false, butSize);
	
	ofAddListener(uimain->newGUIEvent,this,&Interfaces::guiEvent);
}

void Interfaces::setUIPractice(){
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
	float length = 255-xInit;
	float butSize = 0.59*ofGetWidth();
	uipractice = new ofxUICanvas(0.2*ofGetWidth(),0, 0.6*ofGetWidth(), ofGetHeight());
	uipractice->addWidgetDown(new ofxUILabel("Practice", OFX_UI_FONT_LARGE));
	uipractice->addSpacer(butSize, 2);
	
	uipractice->addSpacer(butSize, 2);
	uipractice->addSpacer(butSize, 30);
	uipractice->addLabelButton("Record", false,butSize);
	uipractice->addSpacer(0,15);
	uipractice->addLabelButton("Stop", false, butSize);
	uipractice->addSpacer(0,15);
	uipractice->addLabelButton("Back", false, butSize);
	uipractice->addSpacer(0,15);
	ofAddListener(uipractice->newGUIEvent,this,&Interfaces::guiEvent);
}



void Interfaces::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	if (name=="LOGIN")
	{
		uimain->setVisible(true);
		uilogin->setVisible(false);
		uiregister->setVisible(false);
		
	}


	else if (name =="Practice")
	{
		uimain->setVisible(false);
		uipractice->setVisible(true);
	}

	else if (name == "CANCEL")
	{
	 uiregister ->setVisible(false);
	}

	else if (name == "Play")
	{

	}
	else if (name == "Highscores")
	{

	}
	else if (name == "Sessions")
	{

	}
	else if (name == "Options")
	{

	}
	else if (name == "REGISTER")
	{
		uiregister->setVisible(true);

	}
	else if (name == "QUIT")
	{
	 ofExit();
	}
	else if (name == "Quit")
	{
		ofExit();
	}
	
	
	
	else if (name == "Record")
	{
		
		
	}
	else if (name == "Stop")
	{
		recordFlac.stop();
		
	}
	else if (name == "Back")
	{
		//recordFlac.stop();
		uipractice->setVisible(false);
		uimain->setVisible(true);
	}
}
	
	
	


//--------------------------------------------------------------
void Interfaces::update(){

}

//--------------------------------------------------------------
void Interfaces::draw(){
	
	ofSetColor(255,255,255);
	ofRect(100,100,100,100);


}

//--------------------------------------------------------------
void Interfaces::keyPressed(int key){

}

//--------------------------------------------------------------
void Interfaces::keyReleased(int key){

}

//--------------------------------------------------------------
void Interfaces::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void Interfaces::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Interfaces::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Interfaces::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Interfaces::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Interfaces::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Interfaces::dragEvent(ofDragInfo dragInfo){ 

}

void Interfaces::exit()
{
	delete uilogin;
	delete uiregister;
	delete uipractice;
	delete uimain;
}