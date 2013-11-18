#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "Interfaces.h"
#include "RecordFlac.h"
#include "MyThread.h"

#include "MySQLConn.h"
#include "ofxBox2d.h"
#include "ofxSpine.h"
#include "Player.h"
#include "Skulls.h"
#include "Monster.h"
#include "Dragon.h"
#include "Item.h"
#include "globaldata.h"
#include "HUD.h"


extern vector<string> wordArray;
extern bool isStarted;

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void draw(ofxUIEventArgs &args);
		void exit();
		void loadWords();
		void selectRandomWord();
		void loadHUD();
		void startRecording();
		void stopRecording();
		void copyFile(string status);
		void drawHealth();
		void checkCorrect();
		
		

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		ofTrueTypeFont pixfont;
		ofTrueTypeFont bigPixfont;
		Interfaces mainWindow;
		RecordFlac rec;
		ofxUICanvas *gui;
		void guiEvent(ofxUIEventArgs &e);
		void audioIn 	(float * input, int bufferSize, int nChannels);
		
		ofstream mfile;
		int spacecount;
		MySQLConn mysql;
		string word;
		string resultWord;
		float time;
		float startTime;
		float scoreTime;
		float scoreStartTime;
		float wordRecordTime;
		float wordRecordStartTime;
		float wordStopTime;
		float wordStopStartTime;
		float displayTime;
		float displayStartTime;
		string recordingState;

		float spawnMonsterTime;
		float spawnMonsterStartTime;

		void spawnMonster();

		bool isWordReady;
		bool isNow;
		

		
		vector<string> incorrectwords;
		vector<string> correctwords;
		

		MyThread thread;
		ofImage floorImage;
		ofPoint floorpoint;
		ofRectangle worldBounds;
		//ofxBox2d box2dworld;
		vector <ofxBox2dCircle> circlesA;
		ofImage characterImage;
		ofImage backgroundImage;
		ofPoint circlepos;
		ofxBox2dCircle c;
		float force;
		float desiredVel;
		string keypressed;
		bool isMidAir;

		unsigned long last;
		int counter;
		ofColor col;
		bool isDirectionRight;
		ofxSkeleton skeleton;
		//ofxSkeleton dragon;
		ofxSkeleton backgroundSet;
		Player player;
		Skulls skull;
		Dragon dragon;
		Item item;
		
		//vector<Monster> monsters;
		Monster monster;

		int rawScore;

		HUD hud;

		
	
		




		
		
		
		
		
};
