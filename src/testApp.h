#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "Interfaces.h"
#include "RecordFlac.h"
#include "MyThread.h"

#include "MySQLConn.h"



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
		float wordTime;
		float wordStartTime;
		bool isWordReady;
		bool isNow;
		vector<string> wordArray;

		int multiplier;
		int wordsCorrect;
		int wordsIncorrect;
		int scoreMultiplier;

		MyThread thread;
		
		
		
		
		
};
