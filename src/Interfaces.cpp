#include "Interfaces.h"

vector<string> wordArray;
bool isStarted;
#pragma region settings boolean declaration
bool b_initial;
bool b_medial;
bool b_final;
bool ch_initial;
bool ch_medial;
bool ch_final;
bool d_initial;
bool d_medial;
bool d_final;
bool f_initial;
bool f_medial;
bool f_final;
bool g_initial;
bool g_medial;
bool g_final;
bool h_initial;
bool j_initial;
bool j_medial;
bool j_final;
bool k_initial;
bool k_medial;
bool k_final;
bool l_initial;
bool l_medial;
bool l_final;
bool m_initial;
bool m_medial;
bool m_final;
bool n_initial;
bool n_medial;
bool n_final;
bool ng_initial;
bool p_initial;
bool p_medial;
bool p_final;
bool r_initial;
bool r_medial;
bool r_final;
bool s_initial;
bool s_medial;
bool s_final;
bool sh_initial;
bool sh_medial;
bool sh_final;
bool t_initial;
bool t_medial;
bool t_final;
bool th_initial;
bool th_medial;
bool th_final;
bool v_initial;
bool v_medial;
bool v_final;
bool w_initial;
bool y_initial;
bool z_initial;
bool z_medial;
bool z_final;

#pragma endregion
//--------------------------------------------------------------
void Interfaces::setup(){
	isLoggedIn = false;
	setUIPractice();
	setUILogin();
	setUIRegister();
	setUIGameOver();
	
	uimain = new ofxUICanvas(0.2*ofGetWidth(),0, 0.6*ofGetWidth(), ofGetHeight());
	 uioptionsuser = new ofxUICanvas(0.2*ofGetWidth(),0, 0.6*ofGetWidth(), 100);
	 uioptions = new ofxUIScrollableCanvas(0.2*ofGetWidth(),200, 0.6*ofGetWidth(), ofGetHeight());  
	 uihighscores = new ofxUICanvas(0.2*ofGetWidth(),0, 0.6*ofGetWidth(), ofGetHeight());
	
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
	msgEmpty.addNewMessage("Empty Fields", "Please ensure all fields are complete", OFX_MESSAGEBOX_OK);
	//msgBox.
	
	view="login";
	setView(view);
	
	
}

#pragma region views
string Interfaces::getView()
{
	return view;
	
}

void Interfaces::setView(string _view)
{
	view = _view;
	if (_view == "login")
	{

		uilogin->setVisible(true);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		uioptions ->setVisible(false);
		uioptionsuser->setVisible(false);
		//uisessions->setVisible(false);
		uigameover->setVisible(false);
	}
	else if (_view =="register")
	{
		uilogin->setVisible(true);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(true);
		uioptions ->setVisible(false);
		//uisessions->setVisible(false);
		uigameover->setVisible(false);
	}
	else if (_view == "main")
	{
		uilogin->setVisible(false);
		uimain->setVisible(true);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		uioptions ->setVisible(false);
		uioptionsuser->setVisible(false);
		//uisessions->setVisible(false);
		uigameover->setVisible(false);
		uihighscores->setVisible(false);
	}
	else if (_view =="practice")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(true);
		uiregister->setVisible(false);
		uioptions ->setVisible(false);
		//uisessions->setVisible(false);
		uigameover->setVisible(false);
	}
	else if (_view =="game")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		uioptions ->setVisible(false);
		//uisessions->setVisible(false);
		uigameover->setVisible(false);

	}
	else if (_view =="sessions")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		uisessions->setVisible(true);
		uioptions ->setVisible(false);
		//sessionpanel1->setVisible(true);
		uigameover->setVisible(false);

	}
	else if (_view == "options")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		//uisessions->setVisible(false);
		uioptions ->setVisible(true);
		uioptionsuser->setVisible(true);
		uigameover->setVisible(false);

	}
	else if (_view == "gameover")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		//uisessions->setVisible(false);
		uioptions ->setVisible(false);
		uioptionsuser->setVisible(false);
		uigameover->setVisible(true);

	}

		else if (_view == "highscores")
	{
		uilogin->setVisible(false);
		uimain->setVisible(false);
		uipractice->setVisible(false);
		uiregister->setVisible(false);
		//uisessions->setVisible(false);
		uioptions ->setVisible(false);
		uioptionsuser->setVisible(false);
		uigameover->setVisible(false);
		uihighscores->setVisible(true);

	}
}

#pragma endregion 


void Interfaces::loadWords(string _letter, string _placement)
{
	ifstream myfile ("data/words/" + _letter +"/" + _letter +"-" + _placement + ".word");
	
	copy(istream_iterator<string>(myfile),
		istream_iterator<string>(),
		back_inserter(wordArray));

}

void Interfaces::setWords()
{
	if(b_initial) 
	 loadWords("b", "initial");
	if(b_medial) 
	 loadWords("b", "medial");
	if(b_final) 
	 loadWords("b", "final");
	if(ch_initial) 
	 loadWords("ch", "initial");
	if(ch_medial) 
	 loadWords("ch", "medial");
	if(ch_final) 
	 loadWords("ch", "final");
	if(d_initial) 
	 loadWords("d", "initial");
	if(d_medial) 
	 loadWords("d", "medial");
	if(d_final) 
	 loadWords("d", "final");
	if(f_initial) 
	 loadWords("f", "initial");
	if(f_medial) 
	 loadWords("f", "medial");
	if(f_final) 
	 loadWords("f", "final");
	if(g_initial) 
	 loadWords("g", "initial");
	if(g_medial) 
	 loadWords("g", "medial");
	if(g_final) 
	 loadWords("g", "final");
	if(h_initial) 
	 loadWords("h", "initial");
	if(j_initial) 
	 loadWords("j", "initial");
	if(j_medial) 
	 loadWords("j", "medial");
	if(j_final) 
	 loadWords("j", "final");
	if(k_initial) 
	 loadWords("k", "initial");
	if(k_medial) 
	 loadWords("k", "medial");
	if(k_final) 
	 loadWords("k", "final");
	if(l_initial) 
	 loadWords("l", "initial");
	if(l_medial) 
	 loadWords("l", "medial");
	if(l_final) 
	 loadWords("l", "final");
	if(m_initial) 
	 loadWords("m", "initial");
	if(m_medial) 
	 loadWords("m", "medial");
	if(m_final) 
	 loadWords("m", "final");
	if(n_initial) 
	 loadWords("n", "initial");
	if(n_medial) 
	 loadWords("n", "medial");
	if(n_final) 
	 loadWords("n", "final");
	if(ng_initial) 
	 loadWords("ng", "initial");
	if(p_initial) 
	 loadWords("p", "initial");
	if(p_medial) 
	 loadWords("p", "medial");
	if(p_final) 
	 loadWords("p", "final");
	if(r_initial) 
	 loadWords("r", "initial");
	if(r_medial) 
	 loadWords("r", "medial");
	if(r_final) 
	 loadWords("r", "final");
	if(s_initial) 
	 loadWords("s", "initial");
	if(s_medial) 
	 loadWords("s", "medial");
	if(s_final) 
	 loadWords("s", "final");
	if(sh_initial) 
	 loadWords("sh", "initial");
	if(sh_medial) 
	 loadWords("sh", "medial");
	if(sh_final) 
	 loadWords("sh", "final");
	if(t_initial) 
	 loadWords("t", "initial");
	if(t_medial) 
	 loadWords("t", "medial");
	if(t_final) 
	 loadWords("t", "final");
	if(th_initial) 
	 loadWords("th", "initial");
	if(th_medial) 
	 loadWords("th", "medial");
	if(th_final) 
	 loadWords("th", "final");
	if(v_initial) 
	 loadWords("v", "initial");
	if(v_medial) 
	 loadWords("v", "medial");
	if(v_final) 
	 loadWords("v", "final");
	if(w_initial) 
	 loadWords("w", "initial");
	if(y_initial) 
	 loadWords("y", "initial");
	if(z_initial) 
	 loadWords("z", "initial");
	if(z_medial) 
	 loadWords("z", "medial");
	if(z_final) 
	 loadWords("z", "final");

}


#pragma region setUI

void Interfaces::setUILogin(){
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
	float length = 255-xInit;
	uilogin = new ofxUICanvas(0,0, length+xInit, ofGetHeight());
	uilogin->addWidgetDown(new ofxUILabel("SPEECH HERO", OFX_UI_FONT_LARGE));
	uilogin->addWidgetDown(new ofxUILabel("Username:", OFX_UI_FONT_MEDIUM));
	txtusername= uilogin->addTextInput("Username", "", length-xInit);
	uilogin->addWidgetDown(new ofxUILabel("Password:", OFX_UI_FONT_MEDIUM));
	//uilogin->updateFont(OFX_UI_FONT_MEDIUM,"GUI/password.ttf", 16);
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


void Interfaces::setUIGameOver()
{

	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
	float length = 255-xInit;
	uigameover = new ofxUICanvas(0.3*ofGetWidth(), 0.3*ofGetHeight(), 0.4*ofGetWidth(), 0.4*ofGetHeight());
	uigameover->addWidgetDown(new ofxUILabel("Game Over", OFX_UI_FONT_LARGE));
	 lbl =uigameover->addLabel("Score", "Score: " + ofToString(GlobalData::score), 1);
	uigameover->addLabel ("Correct", "Words Correct: " + ofToString(GlobalData::wordsCorrect,1));
	uigameover->addLabel ("Incorrect", "Words Incorrect: " + ofToString(GlobalData::wordsIncorrect,1));
	uigameover->addLabel ("Multiplier", "Multiplier : x" + ofToString(GlobalData::scoreMultiplier,1));
	uigameover->addLabel ("Collected", "Letters Collected : "+ ofToString(GlobalData::itemIndex,1));
	uigameover->addLabelButton("SUBMIT",false, length-xInit);
	ofAddListener(uigameover->newGUIEvent,this,&Interfaces::guiEventOptions);
	
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
	highscoreButton = uimain->addLabelButton("Highscores", false, butSize);
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
	optionsDDLUser = uioptionsuser ->addDropDownList("Users", users);
	optionsDDLUser->setShowCurrentSelected(true);
	uioptions->addSpacer(ofGetWidth(), 100);
	uioptions->setPosition(0.2*ofGetWidth(), 250);
	
	uioptions ->addLabel ("B");
	toggle_b_initial =uioptions ->addToggle("b-initial", false);
	toggle_b_medial =uioptions ->addToggle ("b-medial", false);
	toggle_b_final =uioptions ->addToggle ("b-final", false);
	uioptions ->addLabel ("CH");
	toggle_ch_initial =uioptions ->addToggle("ch-initial", false);
	toggle_ch_medial =uioptions ->addToggle ("ch-medial", false);
	toggle_ch_final=uioptions ->addToggle ("ch-final", false);
	uioptions ->addLabel ("D");
	toggle_d_initial =uioptions ->addToggle("d-initial", false);
	toggle_d_medial=uioptions ->addToggle ("d-medial", false);
	toggle_d_final=uioptions ->addToggle ("d-final", false);
	uioptions ->addLabel ("F");
	toggle_f_initial =uioptions ->addToggle("f-initial", false);
	toggle_f_medial =uioptions ->addToggle ("f-medial", false);
	toggle_f_final =uioptions ->addToggle ("f-final", false);
	uioptions ->addLabel ("G");
	toggle_g_initial =uioptions ->addToggle("g-initial", false);
	toggle_g_medial =uioptions ->addToggle ("g-medial", false);
	toggle_g_final =uioptions ->addToggle ("g-final", false);
	uioptions ->addLabel ("H");
	toggle_h_initial =uioptions ->addToggle("h-initial", false);
	uioptions ->addLabel ("J");
	toggle_j_initial =uioptions ->addToggle("j-initial", false);
	toggle_j_medial =uioptions ->addToggle ("j-medial", false);
	toggle_j_final =uioptions ->addToggle ("j-final", false);
	uioptions ->addLabel ("K");
	toggle_k_initial =uioptions ->addToggle("k-initial", false);
	toggle_k_medial =uioptions ->addToggle ("k-medial", false);
	toggle_k_final =uioptions ->addToggle ("k-final", false);
	uioptions ->addLabel ("L");
	toggle_l_initial =uioptions ->addToggle("l-initial", false);
	toggle_l_medial =uioptions ->addToggle ("l-medial", false);
	toggle_l_final =uioptions ->addToggle ("l-final", false);
	uioptions ->addLabel ("M");
	toggle_m_initial =uioptions ->addToggle("m-initial", false);
	toggle_m_medial =uioptions ->addToggle ("m-medial", false);
	toggle_m_final =uioptions ->addToggle ("m-final", false);
	uioptions ->addLabel ("N");
	toggle_n_initial =uioptions ->addToggle("n-initial", false);
	toggle_n_medial =uioptions ->addToggle ("n-medial", false);
	toggle_n_final =uioptions ->addToggle ("n-final", false);
	uioptions ->addLabel ("NG");
	toggle_ng_initial =uioptions ->addToggle("ng-initial", false);
	uioptions ->addLabel ("P");
	toggle_p_initial=uioptions ->addToggle("p-initial", false);
	toggle_p_medial =uioptions ->addToggle ("p-medial", false);
	toggle_p_final =uioptions ->addToggle ("p-final", false);
	uioptions ->addLabel ("R");
	toggle_r_initial =uioptions ->addToggle("r-initial", false);
	toggle_r_medial =uioptions ->addToggle ("r-medial", false);
	toggle_r_final =uioptions ->addToggle ("r-final", false);
	uioptions ->addLabel ("S");
	toggle_s_initial=uioptions ->addToggle("s-initial", false);
	toggle_s_medial =uioptions ->addToggle ("s-medial", false);
	toggle_s_final =uioptions ->addToggle ("s-final", false);
	uioptions ->addLabel ("SH");
	toggle_sh_initial =uioptions ->addToggle("sh-initial", false);
	toggle_sh_medial =uioptions ->addToggle ("sh-medial", false);
	toggle_sh_final =uioptions ->addToggle ("sh-final", false);
	uioptions ->addLabel ("T");
	toggle_t_initial =uioptions ->addToggle("t-initial", false);
	toggle_t_medial =uioptions ->addToggle ("t-medial", false);
	toggle_t_final =uioptions ->addToggle ("t-final", false);
		uioptions ->addLabel ("TH");
	toggle_th_initial =uioptions ->addToggle("th-initial", false);
	toggle_th_medial =uioptions ->addToggle ("th-medial", false);
	toggle_th_final =uioptions ->addToggle ("th-final", false);
		uioptions ->addLabel ("V");
	toggle_v_initial =uioptions ->addToggle("v-initial", false);
	toggle_v_medial =uioptions ->addToggle ("v-medial", false);
	toggle_v_final =uioptions ->addToggle ("v-final", false);
		uioptions ->addLabel ("W");
	toggle_w_initial =uioptions ->addToggle("w-initial", false);
			uioptions ->addLabel ("Y");
	toggle_y_initial =uioptions ->addToggle("y-initial", false);
		uioptions ->addLabel ("Z");
	toggle_z_initial =uioptions ->addToggle("z-initial", false);
	toggle_z_medial =uioptions ->addToggle ("z-medial", false);
	toggle_z_final =uioptions ->addToggle ("z-final", false);

	uioptions->addLabelButton("SAVE", false, butSize);
	  uioptions->setScrollAreaToScreen();
    uioptions->setScrollableDirections(false, true);
	uioptions->autoSizeToFitWidgets();
    uioptions->getRect()->setWidth(ofGetWidth());
	uioptionsuser ->addLabelButton("SAVE", false, butSize);
	uioptionsuser ->addLabelButton("BACK", false, butSize);

	


	ofAddListener(uioptions->newGUIEvent,this,&Interfaces::guiEventOptions);
	ofAddListener(uioptionsuser->newGUIEvent,this,&Interfaces::guiEventOptions);
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

void Interfaces::setUIHighscores()
{
	float butSize = 0.59*ofGetWidth();
		string highscore = mysql.getHighScores();
		uihighscores->addWidgetDown(new ofxUILabel("Highscores", OFX_UI_FONT_LARGE));
		uihighscores->addSpacer(0, 650);
		hsMainButton =uihighscores->addLabelButton("MAIN", false, butSize);
	    ofAddListener(uihighscores->newGUIEvent, this, &Interfaces::guiEventPractice);

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

	if (view =="highscores"){
		if (name == "MAIN")
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
		isStarted = true;
		GlobalData::healthPercent = 1.0;
		GlobalData::itemIndex =0;
		
	}
	else if (name == "Highscores" && highscoreButton->getValue() ==1)
	{
		view = "highscores";
		setUIHighscores();
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
			setWords();
			
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
		{
			if (txtparentusername->getTextString().empty())
				msgEmpty.viewMessage(0);
			else if (txtparentpassword->getTextString().empty())
				msgEmpty.viewMessage(0);
			else if (txtchildusername->getTextString().empty())
				msgEmpty.viewMessage(0);
			else if (txtchildpassword->getTextString().empty())
				msgEmpty.viewMessage(0);
			else
			createUser();
	}
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

void Interfaces::guiEventOptions(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	if (name =="SAVE")
	{
		updateSettings();
		wordArray.clear();
		setWords();

	}
	if (name == "BACK")
	{
		view = "main";
		setView(view);
	}

	if(name == "Users")
    {
        ofxUIDropDownList *ddlist = (ofxUIDropDownList *) e.widget;
        vector<ofxUIWidget *> &selected = ddlist->getSelected(); 
        for(int i = 0; i < selected.size(); i++)
        {
            optionsSelectedUser = selected[i]->getName();
			cout <<optionsSelectedUser;
        }
    }

	if (name == "SUBMIT")
	{
		mysql.addScore(getUser(), GlobalData::score, GlobalData::wordsCorrect, GlobalData::wordsIncorrect, GlobalData::scoreMultiplier);
		view = "main";
		setView(view);
	}

	

	
}
#pragma endregion


void Interfaces::updateSettings()
{
	string queryString = " ";
	if(toggle_b_initial->getValue()==true) 
queryString +=" b_initial = true, ";
 else 
queryString +=" b_initial = false, ";
if(toggle_b_medial->getValue()==true) 
queryString +=" b_medial= true, ";
 else 
 queryString +=" b_medial= false, ";
if(toggle_b_final->getValue()==true) 
queryString +=" b_final= true, ";
 else 
queryString +=" b_final= false, ";
if(toggle_ch_initial->getValue()==true) 
queryString +=" ch_initial = true, ";
 else 
queryString +="ch_initial = false, ";
if(toggle_ch_medial->getValue()==true) 
queryString +=" ch_medial= true, ";
 else 
 queryString +=" ch_medial= false, ";
if(toggle_ch_final->getValue()==true) 
queryString +=" ch_final= true, ";
 else 
queryString +=" ch_final= false, ";
if(toggle_d_initial->getValue()==true) 
queryString +=" d_initial = true, ";
 else 
queryString +=" d_initial = false, ";
if(toggle_d_medial->getValue()==true) 
queryString +=" d_medial= true, ";
 else 
 queryString +=" d_medial= false, ";
if(toggle_d_final->getValue()==true) 
queryString +=" d_final= true, ";
 else 
queryString +=" d_final= false, ";
if(toggle_f_initial->getValue()==true) 
queryString +=" f_initial = true, ";
 else 
queryString +=" f_initial = false, ";
if(toggle_f_medial->getValue()==true) 
queryString +=" f_medial= true, ";
 else 
 queryString +=" f_medial= false, ";
if(toggle_f_final->getValue()==true) 
queryString +=" f_final= true, ";
 else 
queryString +=" f_final= false, ";
if(toggle_g_initial->getValue()==true) 
queryString +=" g_initial = true, ";
 else 
queryString +=" g_initial = false, ";
if(toggle_g_medial->getValue()==true) 
queryString +=" g_medial= true, ";
 else 
 queryString +=" g_medial= false, ";
if(toggle_g_final->getValue()==true) 
queryString +=" g_final= true, ";
 else 
queryString +=" g_final= false, ";
if(toggle_h_initial->getValue()==true) 
queryString +=" h_initial = true, ";
 else 
queryString +=" h_initial = false, ";
if(toggle_j_initial->getValue()==true) 
queryString +=" j_initial = true, ";
 else 
queryString +=" j_initial = false, ";
if(toggle_j_medial->getValue()==true) 
queryString +=" j_medial= true, ";
 else 
 queryString +=" j_medial= false, ";
if(toggle_j_final->getValue()==true) 
queryString +=" j_final= true, ";
 else 
queryString +=" j_final= false, ";
if(toggle_k_initial->getValue()==true) 
queryString +=" k_initial = true, ";
 else 
queryString +=" k_initial = false, ";
if(toggle_k_medial->getValue()==true) 
queryString +=" k_medial= true, ";
 else 
 queryString +=" k_medial= false, ";
if(toggle_k_final->getValue()==true) 
queryString +=" k_final= true, ";
 else 
queryString +=" k_final= false, ";
if(toggle_l_initial->getValue()==true) 
queryString +=" l_initial = true, ";
 else 
queryString +=" l_initial = false, ";
if(toggle_l_medial->getValue()==true) 
queryString +=" l_medial= true, ";
 else 
 queryString +=" l_medial= false, ";
if(toggle_l_final->getValue()==true) 
queryString +=" l_final= true, ";
 else 
queryString +=" l_final= false, ";
if(toggle_m_initial->getValue()==true) 
queryString +=" m_initial = true, ";
 else 
queryString +=" m_initial = false, ";
if(toggle_m_medial->getValue()==true) 
queryString +=" m_medial= true, ";
 else 
 queryString +=" m_medial= false, ";
if(toggle_m_final->getValue()==true) 
queryString +=" m_final= true, ";
 else 
queryString +=" m_final= false, ";
if(toggle_n_initial->getValue()==true) 
queryString +=" n_initial = true, ";
 else 
queryString +=" n_initial = false, ";
if(toggle_n_medial->getValue()==true) 
queryString +=" n_medial= true, ";
 else 
 queryString +=" n_medial= false, ";
if(toggle_n_final->getValue()==true) 
queryString +=" n_final= true, ";
 else 
queryString +=" n_final= false, ";
if(toggle_ng_initial->getValue()==true) 
queryString +=" ng_initial = true, ";
 else 
queryString +=" ng_initial = false, ";
if(toggle_p_initial->getValue()==true) 
queryString +=" ng_initial = true, ";
 else 
queryString +=" ng_initial = false, ";
if(toggle_p_medial->getValue()==true) 
queryString +=" p_medial= true, ";
 else 
 queryString +=" p_medial= false, ";
if(toggle_p_final->getValue()==true) 
queryString +=" p_final= true, ";
 else 
queryString +=" p_final= false, ";
if(toggle_r_initial->getValue()==true) 
queryString +=" r_initial = true, ";
 else 
queryString +=" r_initial = false, ";
if(toggle_r_medial->getValue()==true) 
queryString +=" r_medial= true, ";
 else 
 queryString +=" r_medial= false, ";
if(toggle_r_final->getValue()==true) 
queryString +=" r_final= true, ";
 else 
queryString +=" r_final= false, ";
if(toggle_s_initial->getValue()==true) 
queryString +=" s_initial = true, ";
 else 
queryString +=" s_initial = false, ";
if(toggle_s_medial->getValue()==true) 
queryString +=" s_medial= true, ";
 else 
 queryString +=" s_medial= false, ";
if(toggle_s_final->getValue()==true) 
queryString +=" s_final= true, ";
 else 
queryString +=" s_final= false, ";
if(toggle_sh_initial->getValue()==true) 
queryString +=" sh_initial = true, ";
 else 
queryString +=" sh_initial = false, ";
if(toggle_sh_medial->getValue()==true) 
queryString +=" sh_medial= true, ";
 else 
 queryString +=" sh_medial= false, ";
if(toggle_sh_final->getValue()==true) 
queryString +=" sh_final= true, ";
 else 
queryString +=" sh_final= false, ";
if(toggle_t_initial->getValue()==true) 
queryString +=" t_initial = true, ";
 else 
queryString +=" t_initial = false, ";
if(toggle_t_medial->getValue()==true) 
queryString +=" t_medial= true, ";
 else 
 queryString +=" t_medial= false, ";
if(toggle_t_final->getValue()==true) 
queryString +=" t_final= true, ";
 else 
queryString +=" t_final= false, ";
if(toggle_th_initial->getValue()==true) 
queryString +=" th_initial = true, ";
 else 
queryString +=" th_initial = false, ";
if(toggle_th_medial->getValue()==true) 
queryString +=" th_medial= true, ";
 else 
 queryString +=" th_medial= false, ";
if(toggle_th_final->getValue()==true) 
queryString +=" th_final= true, ";
 else 
queryString +=" th_final= false, ";
if(toggle_v_initial->getValue()==true) 
queryString +=" v_initial = true, ";
 else 
queryString +=" v_initial = false, ";
if(toggle_v_medial->getValue()==true) 
queryString +=" v_medial= true, ";
 else 
 queryString +=" v_medial= false, ";
if(toggle_v_final->getValue()==true) 
queryString +=" v_final= true, ";
 else 
queryString +=" v_final= false, ";
if(toggle_w_initial->getValue()==true) 
queryString +=" w_initial = true, ";
 else 
queryString +=" w_initial = false, ";
if(toggle_y_initial->getValue()==true) 
queryString +=" y_initial = true, ";
 else 
queryString +=" y_initial = false, ";
if(toggle_z_initial->getValue()==true) 
queryString +=" z_initial = true, ";
 else 
queryString +=" z_initial = false, ";
if(toggle_z_medial->getValue()==true) 
queryString +=" z_medial= true, ";
 else 
 queryString +=" z_medial= false, ";
if(toggle_z_final->getValue()==true) 
queryString +=" z_final= true ";
 else 
queryString +=" z_final= false ";


setLetterInDb(queryString);
}

void Interfaces::setLetterInDb(string queryString)
{
	if (!optionsSelectedUser.empty())
	{

		mysql.updateSettings(optionsSelectedUser, queryString);
		cout<<"updating...";
		//cout<<queryString;
	//	cout<< optionsSelectedUser <<endl << letter << endl << placement << endl <<value << endl;
	}
}

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
	uilogin->update();
	uigameover->update();
	lbl->update();
	
	
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