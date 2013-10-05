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
		void audioReceived 	(float * input, int bufferSize, int nChannels);
		
		ofstream mfile;
		int spacecount;
		MySQLConn mysql;
		string word;
		float time;
		float startTime;
		float wordRecordTime;
		float wordRecordStartTime;
		float wordStopTime;
		float wordStopStartTime;
		float displayTime;
		float displayStartTime;
		bool isWordReady;
		bool isNow;
		vector<string> wordArray;

		int multiplier;
		int wordsCorrect;
		int wordsIncorrect;
		int scoreMultiplier;

		MyThread thread;
		ofImage floorImage;
		ofPoint floorpoint;
		ofRectangle worldBounds;
		ofxBox2d box2dworld;
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
		ofxSkeleton dragon;
		Player player;
		Skulls skull;


		
		
		
		
		
};
