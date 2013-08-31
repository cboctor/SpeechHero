#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "Interfaces.h"
#include "RecordFlac.h"
#include <curl/curl.h>
#include "ofxJSONElement.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void draw(ofxUIEventArgs &args);
		void exit();
		void postFLAC();
		void jSONSetup();

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
		Interfaces mainWindow;
		RecordFlac rec;
		ofxUICanvas *gui;
		void guiEvent(ofxUIEventArgs &e);
		void audioReceived 	(float * input, int bufferSize, int nChannels);
		string readBuffer;
		ofxJSONElement result;
		ofstream mfile;
		int spacecount;
		
		
		
};
