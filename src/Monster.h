#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxSpine.h"
#include "Player.h"
#include "MonsterBody.h"
#include "globaldata.h"




// ------------------------------------------------- App
class Monster {
	
public:
	
	void setup();
	void update();
	void draw();
	void createMonster();
	void keyPressed  (int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	float spawnMonsterTime;
		float spawnMonsterStartTime;
	
	
};
