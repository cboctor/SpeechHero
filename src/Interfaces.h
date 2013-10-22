#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "RecordFlac.h"
#include "MySQLConn.h"
#include "ofxMessageBox.h"
#include "ofxGui.h"

class Interfaces {
	public:
		void setup();
		void update();
		void draw();
		void exit();
		bool authenticateUser();
		
		

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void setUILogin();
		void setUIRegister();
		void setUIMain();
		void setUIPractice();
		void setUISession();
		void setUISessions();
		void setUIOptions();
		void setUISessionPanelUser();
		//void setUISessionPanelChild();
		//void setUISessionPanel2();
		ofxUICanvas *uilogin;
		ofxUICanvas *uiregister;
		ofxUICanvas *uimain;
		ofxUICanvas *uipractice;
		ofxUICanvas *uisessions;
		ofxUICanvas *sessionpanel1;
		ofxUICanvas *sessionpanel2;
		ofxUICanvas *uioptionsuser;
		ofxUIScrollableCanvas *uioptions; 
		string getRecordingState();
		string getView();
		string recState;
		void visible(ofxUICanvas *uiInt, bool intVisible);
		void setView(string view);
		string view;
		ofxUIButton *practice;
		ofxUIButton *back;
		ofxUIButton *createButton;
		ofxUIButton *playButton;
		ofxUITextInput *txtusername;
		ofxUITextInput *txtpassword;
		ofxUITextInput *txtparentusername;
		ofxUITextInput *txtparentpassword;
		ofxUITextInput *txtchildusername;
		ofxUITextInput *txtchildpassword;
		ofxUITextInput *txtchildfirstname;
		ofxUITextInput *txtchildlastname;
		ofxUITextInput *txtparentfirstname;
		ofxUITextInput *txtparentlastname;
		MySQLConn mysql;
		//ofTrueTypeFont pfont;
		EaseRectBox rr;
		ofxMessageBox msgBox;
		
		string getUser();
		void guiEvent(ofxUIEventArgs &e);
		void guiEventPractice(ofxUIEventArgs &e);
		void guiEventMain(ofxUIEventArgs &e);
		void guiEventSessions(ofxUIEventArgs &e);
		void createUser();
		bool isLoggedIn;

		string getSessionID();
		void setSessionID();
		int hours;
		int minutes;
		int day;
		int month;
		int year;

		string selectedUser;
		vector<string> sessions;
		vector<string> words;
		void getSessions(string user);
		void getWords(string user, string session, string status);
		ofxUIDropDownList *sessionsddl;

		ofxUIToggle *wordToggles [50];
		vector<ofxUIToggle*> sessionToggles;

		ofxUIRadio *sessionButtons;
		ofxUIRadio *userButtons;
		string boundeduser;
		string getBoundedUser();
		void setUserInfo();
		void setBoundedUser(string _user);

		string getType();
		void setType(string _user);
		string type;

		string userlist;
		string sessionlist;
		string wordlist;

		int currentuser;
		int currentsession;
		int currentword;

		string selectionstate;
		string currentSelectedUser;
		string currentSelectedSession;
		string currentSelectedWord;

			string pathInfoUser;
	string pathInfoChild;
	string pathInfoSessions;
	string pathInfoCorrect;
	string pathInfoIncorrect;

	ofDirectory dirSession;
	ofDirectory dirCorrect;
	ofDirectory dirIncorrect;

	ofxPanel sessiongui;
	ofxButton sessionbuttons1[100];
	ofxUIButton * optionsButton;

	

		
};
