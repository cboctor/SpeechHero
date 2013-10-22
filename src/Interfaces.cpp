#include "Interfaces.h"

//--------------------------------------------------------------
void Interfaces::setup(){
	
	
	
	//pfont->loadFont("password.ttf", OFX_UI_FONT_MEDIUM);
	//pfont->loadFont("password.ttf", );
	//txtparentpassword->setFont(pfont);
	isLoggedIn = false;
	setUIPractice();
	setUILogin();
	setUIRegister();
	
	uimain = new ofxUICanvas(0.2*ofGetWidth(),0, 0.6*ofGetWidth(), ofGetHeight());
	 uioptionsuser = new ofxUICanvas(0.2*ofGetWidth(),0, 0.6*ofGetWidth(), 100);
	 uioptions = new ofxUIScrollableCanvas(0.2*ofGetWidth(),200, 0.6*ofGetWidth(), ofGetHeight());  
	
	// uioptions->drawFill();
	
	
	//setUIMain();
	
	userlist = " ";
	sessionlist = " ";
	wordlist= " ";
	currentuser = 0;
	currentsession = 0;
	currentword = 0;
	selectionstate = "user";

	mysql.setup();
	
	msgBox.addNewMessage("Incorrect Login", "Please enter correct login", OFX_MESSAGEBOX_OK);
	//msgBox.
	
	view="login";
	setView(view);
	
	
}

#pragma region views
string Interfaces::getView()
{
	return view;
	
}

void Interfaces::setView(string view)
{
	if (view == "login")
	{
		uilogin->setVisible(true);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		uioptions ->setVisible(false);
		uioptionsuser->setVisible(false);
		//uisessions->setVisible(false);
	}
	else if (view =="register")
	{
		uilogin->setVisible(true);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(true);
		uioptions ->setVisible(false);
		//uisessions->setVisible(false);
	}
	else if (view == "main")
	{
		uilogin->setVisible(false);
		uimain->setVisible(true);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		uioptions ->setVisible(false);
		//uisessions->setVisible(false);
	}
	else if (view =="practice")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(true);
		uiregister->setVisible(false);
		uioptions ->setVisible(false);
		//uisessions->setVisible(false);
	}
	else if ( view =="game")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		uioptions ->setVisible(false);
		//uisessions->setVisible(false);

	}
	else if ( view =="sessions")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		uisessions->setVisible(true);
		uioptions ->setVisible(false);
		//sessionpanel1->setVisible(true);

	}
	else if ( view == "options")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		//uisessions->setVisible(false);
		uioptions ->setVisible(true);
		uioptionsuser->setVisible(true);

	}
}

#pragma endregion 


#pragma region setUI

void Interfaces::setUILogin(){
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
	float length = 255-xInit;
	
	uilogin = new ofxUICanvas(0,0, length+xInit, ofGetHeight());
	uilogin->addWidgetDown(new ofxUILabel("SPEECH HERO", OFX_UI_FONT_LARGE));
	uilogin->addWidgetDown(new ofxUILabel("Username:", OFX_UI_FONT_MEDIUM));
	txtusername= uilogin->addTextInput("Username", "", length-xInit);
	uilogin->addWidgetDown(new ofxUILabel("Password:", OFX_UI_FONT_MEDIUM));
	txtpassword = uilogin->addTextInput("Password", "", length-xInit);
	txtpassword->setAutoClear(false);
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
	
	txtparentusername = uiregister->addTextInput("Parent Username", "", length-xInit);
	uiregister->addWidgetDown(new ofxUILabel("Password:", OFX_UI_FONT_MEDIUM));
	txtparentpassword = uiregister->addTextInput("TEXT INPUT", "", length-xInit);
	txtparentpassword->setAutoClear(false);
	//txtparentpassword->setFont(pfont);
	uiregister->addWidgetDown(new ofxUILabel("Confirm Password:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "", length-xInit)->setAutoClear(false);
	uiregister->addSpacer(length-xInit, 2);
	uiregister->addWidgetDown(new ofxUILabel("Name:", OFX_UI_FONT_MEDIUM));
	txtparentfirstname = uiregister->addTextInput("TEXT INPUT", "", length-xInit);
	uiregister->addWidgetDown(new ofxUILabel("Family Name:", OFX_UI_FONT_MEDIUM));
	txtparentlastname = uiregister->addTextInput("TEXT INPUT", "", length-xInit);
	uiregister->addSpacer(length-xInit, 2);
	uiregister->addWidgetDown(new ofxUILabel("Child:", OFX_UI_FONT_MEDIUM));
	uiregister->addWidgetDown(new ofxUILabel("Username:", OFX_UI_FONT_MEDIUM));
	txtchildusername = uiregister->addTextInput("TEXT INPUT", "", length-xInit);
	uiregister->addWidgetDown(new ofxUILabel("Password:", OFX_UI_FONT_MEDIUM));
	txtchildpassword =uiregister->addTextInput("TEXT INPUT", "", length-xInit);
	txtchildpassword->setAutoClear(false);
	uiregister->addWidgetDown(new ofxUILabel("Confirm Password:", OFX_UI_FONT_MEDIUM));
	uiregister->addTextInput("TEXT INPUT", "", length-xInit)->setAutoClear(false);
	uiregister->addSpacer(length-xInit, 2);
	uiregister->addWidgetDown(new ofxUILabel("Name:", OFX_UI_FONT_MEDIUM));
	txtchildfirstname = uiregister->addTextInput("TEXT INPUT", "", length-xInit);
	uiregister->addWidgetDown(new ofxUILabel("Family Name:", OFX_UI_FONT_MEDIUM));
	txtchildlastname=uiregister->addTextInput("TEXT INPUT", "", length-xInit);
	uiregister->addSpacer(length-xInit, 2);
	uiregister->addSpacer(length-xInit, 30);
	createButton = uiregister->addLabelButton("CREATE", false, length-xInit);
	uiregister->addLabelButton("CANCEL", false, length-xInit);
	
	ofAddListener(uiregister->newGUIEvent,this,&Interfaces::guiEvent);
}

void Interfaces::setUIMain(){
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
	float length = 255-xInit;
	float butSize = 0.59*ofGetWidth();
	
	uimain->addWidgetDown(new ofxUILabel("SPEECH HERO", OFX_UI_FONT_LARGE));
	uimain->addSpacer(butSize, 2);
	
	uimain->addSpacer(butSize, 2);
	uimain->addSpacer(butSize, 30);
	playButton = uimain->addLabelButton("Play", false,butSize);
	uimain->addSpacer(0,15);
	uimain->addLabelButton("Highscores", false, butSize);
	uimain->addSpacer(0,15);
    uimain->addLabelButton("Sessions", false, butSize);
	uimain->addSpacer(0,15);

	if (getType() == "parent")
	{
	optionsButton = uimain->addLabelButton("Options", false, butSize);
	uimain->addSpacer(0,15);
	}
	
	practice = uimain->addLabelButton("Practice", false, butSize);
	uimain->addSpacer(0,15);
	uimain->addLabelButton("Quit", false, butSize);
	
	ofAddListener(uimain->newGUIEvent,this,&Interfaces::guiEventMain);
}

void Interfaces::setUIOptions(){
	float butSize = 200.0;
		setBoundedUser(getUser());
	vector<string> users;
	users.push_back(getUser());
	users.push_back(getBoundedUser());
	uioptionsuser ->addLabel("Select letters you wish to be tested");
	uioptionsuser ->addDropDownList("Users", users);
	uioptions->addSpacer(ofGetWidth(), 100);
	uioptions->setPosition(0.2*ofGetWidth(), 250);
	
	uioptions ->addLabel ("B");
	uioptions ->addToggle("b-initial", false);
	uioptions ->addToggle ("b-medial", false);
	uioptions ->addToggle ("b-final", false);
	uioptions ->addLabel ("CH");
	uioptions ->addToggle("ch-initial", false);
	uioptions ->addToggle ("ch-medial", false);
	uioptions ->addToggle ("ch-final", false);
	uioptions ->addLabel ("D");
	uioptions ->addToggle("d-initial", false);
	uioptions ->addToggle ("d-medial", false);
	uioptions ->addToggle ("d-final", false);
	uioptions ->addLabel ("F");
	uioptions ->addToggle("f-initial", false);
	uioptions ->addToggle ("f-medial", false);
	uioptions ->addToggle ("f-final", false);
	uioptions ->addLabel ("G");
	uioptions ->addToggle("g-initial", false);
	uioptions ->addToggle ("g-medial", false);
	uioptions ->addToggle ("g-final", false);
	uioptions ->addLabel ("H");
	uioptions ->addToggle("h-initial", false);
	uioptions ->addLabel ("J");
	uioptions ->addToggle("j-initial", false);
	uioptions ->addToggle ("j-medial", false);
	uioptions ->addToggle ("j-final", false);
	uioptions ->addLabel ("K");
	uioptions ->addToggle("k-initial", false);
	uioptions ->addToggle ("k-medial", false);
	uioptions ->addToggle ("k-final", false);
	uioptions ->addLabel ("L");
	uioptions ->addToggle("l-initial", false);
	uioptions ->addToggle ("l-medial", false);
	uioptions ->addToggle ("l-final", false);
	uioptions ->addLabel ("M");
	uioptions ->addToggle("m-initial", false);
	uioptions ->addToggle ("m-medial", false);
	uioptions ->addToggle ("m-final", false);
	uioptions ->addLabel ("N");
	uioptions ->addToggle("n-initial", false);
	uioptions ->addToggle ("n-medial", false);
	uioptions ->addToggle ("n-final", false);
	uioptions ->addLabel ("NG");
	uioptions ->addToggle("ng-initial", false);
	uioptions ->addLabel ("P");
	uioptions ->addToggle("p-initial", false);
	uioptions ->addToggle ("p-medial", false);
	uioptions ->addToggle ("p-final", false);
	uioptions ->addLabel ("R");
	uioptions ->addToggle("r-initial", false);
	uioptions ->addToggle ("r-medial", false);
	uioptions ->addToggle ("r-final", false);
	uioptions ->addLabel ("S");
	uioptions ->addToggle("s-initial", false);
	uioptions ->addToggle ("s-medial", false);
	uioptions ->addToggle ("s-final", false);
	uioptions ->addLabel ("SH");
	uioptions ->addToggle("sh-initial", false);
	uioptions ->addToggle ("sh-medial", false);
	uioptions ->addToggle ("sh-final", false);
	uioptions ->addLabel ("T");
	uioptions ->addToggle("t-initial", false);
	uioptions ->addToggle ("t-medial", false);
	uioptions ->addToggle ("t-final", false);
		uioptions ->addLabel ("TH");
	uioptions ->addToggle("th-initial", false);
	uioptions ->addToggle ("th-medial", false);
	uioptions ->addToggle ("th-final", false);
		uioptions ->addLabel ("V");
	uioptions ->addToggle("v-initial", false);
	uioptions ->addToggle ("v-medial", false);
	uioptions ->addToggle ("v-final", false);
		uioptions ->addLabel ("W");
	uioptions ->addToggle("w-initial", false);
			uioptions ->addLabel ("Y");
	uioptions ->addToggle("y-initial", false);
		uioptions ->addLabel ("Z");
	uioptions ->addToggle("z-initial", false);
	uioptions ->addToggle ("z-medial", false);
	uioptions ->addToggle ("z-final", false);

	uioptions->addLabelButton("SAVE", false, butSize);
	  uioptions->setScrollAreaToScreen();
    uioptions->setScrollableDirections(false, true);
	uioptions->autoSizeToFitWidgets();
    uioptions->getRect()->setWidth(ofGetWidth());
	uioptionsuser ->addLabelButton("SAVE", false, butSize);
	uioptionsuser ->addLabelButton("BACK", false, butSize);

	


	//ofAddListener(uioptions->newGUIEvent,this,&Interfaces::guiEventMain);
}

void Interfaces::setUISession()
{
	
	vector<string> users;
	string user = getUser();
	string boundeduser = getBoundedUser();
	string type = getType();

	
	userlist.append(users[currentuser]);
	if (isLoggedIn)
	{
		users.clear();

		if(type == "parent")
		{
			pathInfoUser = "user/" + user;
			pathInfoChild = "user/" + boundeduser;
			pathInfoSessions = "user/" +currentSelectedUser + "/";
			pathInfoCorrect = "user/" + currentSelectedUser + "/correct/" + currentSelectedWord;
			pathInfoIncorrect = "user/" + currentSelectedUser + "/correct/" + currentSelectedWord;

			users.push_back(user);
			users.push_back(boundeduser);
		}
		else
		{
			pathInfoUser = "user/" + user;
			users.push_back(user);
		}

	}
	
	//dir.listDir("user/" + getUser()
}



void Interfaces::setUISessions(){
	float x,y,w,h;
	x = 0;
	y = 50;
	h = ofGetHeight() -y;
	w = 200 ;
	uisessions = new ofxUICanvas(x,y,w,h);
	uisessions->addWidgetDown(new ofxUILabel ("Past Sessions", OFX_UI_FONT_LARGE));
	uisessions->addSpacer(ofGetWidth(), 2);
	 vector<string> users;
	 string user = getUser();
	 if(isLoggedIn)
	 {
		  if (mysql.getType(user) == "parent"){
			string boundeduser = mysql.getBoundedUser(user);
			  users.push_back(user);
			 users.push_back(boundeduser);
			// uisessions->addToggle(user, false);
			// uisessions->addToggle(boundeduser, false);
		 }
		  else
		  {
			  users.push_back(user);
			 // uisessions->addToggle(user, false);
		  }

		  userButtons = uisessions->addRadio("vr", users, OFX_UI_ORIENTATION_VERTICAL);


	 }
	setUISessionPanelUser();
	//setUISessionPanelChild();

	 ofAddListener(uisessions->newGUIEvent, this, &Interfaces::guiEventSessions);
	
} 


void Interfaces::setUISessionPanelUser(){
	float x,y,w,h;
	x = 205;
	y = 50;
	h = ofGetHeight() -y;
	w = 250;
	sessionpanel1 = new ofxUICanvas(x,y,w,h);
	sessionpanel1->addWidgetDown(new ofxUILabel("Sessions", OFX_UI_FONT_LARGE));
	getSessions(getUser());
	//sessionpanel1->addRadio("vr", sessions, OFX_UI_ORIENTATION_VERTICAL);
	for (int i = 0 ; i< sessions.size(); i++)
		sessionpanel1->addButton(sessions[i], false);

	sessionpanel2 = new ofxUICanvas(x+ w,y,w,h);
}


void Interfaces::getSessions(string user)
{
			ofDirectory dir;
			string dirString;
			
			sessionpanel1->addSpacer(2, 2);
			dirString = "user/" + user+ "/";
			dir.listDir(dirString);	
			for (int i=0; i < (int)dir.size(); i++)
			{cout<< dir.getName(i);
			string session = dir.getName(i);
			sessions.push_back(session);			
			}
			




	
	
}

void Interfaces::getWords(string user,string session, string status)
{
	ofDirectory dir;
			string dirString;
			sessionpanel2->addWidgetDown(new ofxUILabel(status, OFX_UI_FONT_LARGE));
			sessionpanel2->addSpacer(2, 2);
			dirString = "user/" + user+ "/"+ session+ "/" + status; //+ getUser();
			dir.listDir(dirString);	
			for (int i=0; i < (int)dir.size(); i++)
			{
				
				cout<< dir.getName(i);
			string word = dir.getName(i);
			wordToggles[i] = sessionpanel2->addToggle(word,false);
			words.push_back(word);			
			}
			
	
	
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
	uipractice->addWidgetDown(new ofxUILabel("Press Space to start Recording", OFX_UI_FONT_MEDIUM));
	uipractice->addSpacer(butSize, 2);
	uipractice->addSpacer(0,350);
back=	uipractice->addLabelButton("Back", false, butSize);
	uipractice->addSpacer(0,15);
	
	ofAddListener(uipractice->newGUIEvent,this,&Interfaces::guiEventPractice);
}


#pragma endregion

# pragma region GUI Events

void Interfaces::guiEventPractice(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	
	if (view =="practice"){
	if (name =="Back" &&back->getValue()==1)
		view = "main";
	setView(view);
}


}

void Interfaces::guiEventMain(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	if (view =="main")
	{
	if (name == "Play" && playButton->getValue() == 1)
	{ 
	    setSessionID();
		view = "game";
		
	}
	else if (name == "Highscores")
	{
	}
	else if (name == "Sessions")
	{setUISessions();
	view = "sessions";}
	else if (name == "Options")
	{
		view = "options";
		setUIOptions();
	}
	else if (name =="Practice" && practice->getValue() == 1)
		{setSessionID();
			view = "practice";
	uipractice->disable();}
	else if (name == "Quit")
		ofExit();
	
	setView(view);
	}


}

void Interfaces::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	if (name=="LOGIN")
	{
		//authenticateUser();
		if (authenticateUser())
		{
			
			view = "main";
			isLoggedIn=true;
			setUserInfo();
			setUIMain();
			
		}
		else
			msgBox.viewMessage(0);
	}
	else if (name == "CANCEL")
		view = "login";
	else if (name == "REGISTER")
		view="register";
	else if (name == "QUIT")
		 ofExit();
	else if (name == "CREATE" & createButton->getValue()==1)
		createUser();
	setView(view);
}



void Interfaces::guiEventSessions(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
		if (name == "SELECT USERS")
		{
			ofxUIDropDownList *ddlist = (ofxUIDropDownList *) e.widget;
			vector<ofxUIWidget *> &selected = ddlist->getSelected(); 
			for(int i = 0; i < selected.size(); i++)
			{
				selectedUser = selected[i]->getName();
				cout << "SELECTED: " << selected[i]->getName() << endl; 
			}
		}

		if (name == getUser())
		{
			ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
			if (toggle->getValue() == 0)
			{sessionpanel1->setVisible(false);
			}
			else if (toggle->getValue() ==1)
			{
				sessionpanel1->setVisible(true);
			}
			
		
		}

		for (int i =0; i<sessions.size(); i++)
		{
			if (name ==sessions[i])
			{
				getWords(getUser(), sessions[i], "correct");
				getWords(getUser(), sessions[i], "incorrect");
				//sessionpanel1->addButton(
			}

		}

		

	//	if (name ==
			

}
#pragma endregion


#pragma region sessionID
string Interfaces::getSessionID()
{
	return "Session" + ofToString(day) +"." + ofToString(month) +"."+ ofToString(year) +"-"  + ofToString(hours)+"."+ ofToString(minutes);
}

void Interfaces::setSessionID()
{
	hours = ofGetHours();
	minutes = ofGetMinutes();
	day = ofGetDay();
	month = ofGetMonth();
	year = ofGetYear();

}

#pragma endregion





void Interfaces::createUser()
{
	string parentUser = txtparentusername->getTextString();
	string parentPass = txtparentpassword ->getTextString();
	string parentfirstname = txtparentfirstname ->getTextString();
	string parentlastname = txtparentlastname ->getTextString();
	string childUser = txtchildusername ->getTextString();
	string childpass = txtchildpassword ->getTextString();
	string childfirstname = txtchildfirstname->getTextString();
	string childlastname = txtchildlastname->getTextString();
	mysql.createUser(parentUser,parentPass,parentfirstname,parentlastname, "parent", childUser);
	mysql.createUser(childUser, childpass, childfirstname, childlastname, "child", parentUser);
	mysql.setupSettings(parentUser);
	mysql.setupSettings(childUser);

}

bool Interfaces::authenticateUser()
{
	string user =txtusername->getTextString();
	string pass = txtpassword->getTextString();
	mysql.setSettings(user);
	if (mysql.authenticateUser(user,pass))
		return true;
	else return false;
	return true;

}
	
#pragma region Get Info from MySQL
	string Interfaces::getUser()
	{
		return txtusername->getTextString();
	}

	string Interfaces::getBoundedUser()
	{
		return boundeduser;
	}

	void Interfaces::setBoundedUser(string _user)
	{	boundeduser = mysql.getBoundedUser(_user);
	}

	void Interfaces::setUserInfo()
	{
		setBoundedUser(getUser());
		setType(getUser());

	}

	string Interfaces::getType()
	{
		return type;

	}

	void Interfaces::setType(string _user)
	{
		type = mysql.getType(_user);
	}

#pragma endregion


//--------------------------------------------------------------
void Interfaces::update(){
	uimain->update();
	
}

//--------------------------------------------------------------
void Interfaces::draw(){
	
	//ofSetColor(255,255,255);
	//ofRect(100,100,100,100);
	 uioptionsuser->drawFill();


}

//--------------------------------------------------------------
void Interfaces::keyPressed(int key){
	
	if (view == "sessions")
	{
			if (key == OF_KEY_UP)
			{
				if (selectionstate == "user")
					currentuser --;

			}

			if (key == OF_KEY_DOWN)
			{
				if (selectionstate =="user")
					currentuser ++;

			}

			if (key == OF_KEY_RETURN)
			{
		
				if (selectionstate == "user")
				selectionstate = "session";
				else if (selectionstate == "session")
					selectionstate =="word";
				}

	}

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
	mysql.exit();
	delete uilogin;
	delete uiregister;
	delete uimain;
	delete uipractice;
	
}