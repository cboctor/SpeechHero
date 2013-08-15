#pragma once

#include "ofMain.h"
#include "ofxUI.h"

class Interfaces {
	public:
		void setup();
		void update();
		void draw();
		void exit();
		
		

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
		ofxUICanvas *uilogin;
		ofxUICanvas *uiregister;
		ofxUICanvas *uimain;
		
		void guiEvent(ofxUIEventArgs &e);
};
