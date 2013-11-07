#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxSpine.h"
#include "Player.h"
#include "CustomItem.h"
#include "globaldata.h"







// ------------------------------------------------- App
class Item{
	
public:
	
	void setup();
	void update();
	void draw();
	void createItem();
	void keyPressed  (int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	float spawnMonsterTime;
	float spawnMonsterStartTime;
	//ofxBox2d box2d;
	
	void contactStart(ofxBox2dContactArgs &e);
	void contactEnd(ofxBox2dContactArgs &e);
	
};

