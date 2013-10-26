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
		void guiEventOptions(ofxUIEventArgs &e);
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

	void loadWords(string _letter, string _placement);
	void setWords();
		void updateSettings();
		void setLetterInDb(string queryString);

	
	ofxUIDropDownList *optionsDDLUser;
	string optionsSelectedUser;

#pragma region declare toggles
	 ofxUIToggle *toggle_b_initial;
 ofxUIToggle *toggle_b_medial;
 ofxUIToggle *toggle_b_final;
 ofxUIToggle *toggle_ch_initial;
 ofxUIToggle *toggle_ch_medial;
 ofxUIToggle *toggle_ch_final;
 ofxUIToggle *toggle_d_initial;
 ofxUIToggle *toggle_d_medial;
 ofxUIToggle *toggle_d_final;
 ofxUIToggle *toggle_f_initial;
 ofxUIToggle *toggle_f_medial;
 ofxUIToggle *toggle_f_final;
 ofxUIToggle *toggle_g_initial;
 ofxUIToggle *toggle_g_medial;
 ofxUIToggle *toggle_g_final;
 ofxUIToggle *toggle_h_initial;
 ofxUIToggle *toggle_j_initial;
 ofxUIToggle *toggle_j_medial;
 ofxUIToggle *toggle_j_final;
 ofxUIToggle *toggle_k_initial;
 ofxUIToggle *toggle_k_medial;
 ofxUIToggle *toggle_k_final;
 ofxUIToggle *toggle_l_initial;
 ofxUIToggle *toggle_l_medial;
 ofxUIToggle *toggle_l_final;
 ofxUIToggle *toggle_m_initial;
 ofxUIToggle *toggle_m_medial;
 ofxUIToggle *toggle_m_final;
 ofxUIToggle *toggle_n_initial;
 ofxUIToggle *toggle_n_medial;
 ofxUIToggle *toggle_n_final;
 ofxUIToggle *toggle_ng_initial;
 ofxUIToggle *toggle_p_initial;
 ofxUIToggle *toggle_p_medial;
 ofxUIToggle *toggle_p_final;
 ofxUIToggle *toggle_r_initial;
 ofxUIToggle *toggle_r_medial;
 ofxUIToggle *toggle_r_final;
 ofxUIToggle *toggle_s_initial;
 ofxUIToggle *toggle_s_medial;
 ofxUIToggle *toggle_s_final;
 ofxUIToggle *toggle_sh_initial;
 ofxUIToggle *toggle_sh_medial;
 ofxUIToggle *toggle_sh_final;
 ofxUIToggle *toggle_t_initial;
 ofxUIToggle *toggle_t_medial;
 ofxUIToggle *toggle_t_final;
 ofxUIToggle *toggle_th_initial;
 ofxUIToggle *toggle_th_medial;
 ofxUIToggle *toggle_th_final;
 ofxUIToggle *toggle_v_initial;
 ofxUIToggle *toggle_v_medial;
 ofxUIToggle *toggle_v_final;
 ofxUIToggle *toggle_w_initial;
 ofxUIToggle *toggle_y_initial;
 ofxUIToggle *toggle_z_initial;
 ofxUIToggle *toggle_z_medial;
 ofxUIToggle *toggle_z_final;

#pragma endregion
	

		
};
