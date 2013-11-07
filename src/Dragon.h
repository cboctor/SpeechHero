#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxSpine.h"
#include "Player.h"
#include "FireballProjectile.h"
#include "globaldata.h"



// ------------------------------------------------- App
class Dragon {
	
public:
	
	void setup();
	void update();
	void draw();
	void createDragon();
	void createProjectile();
	
	ofxSkeleton dragon;
	ofPoint dragonPos;
	BoneData *dragonHead;
	BoneData *head;
	ofPoint headPos;
	float radDiff( float a, float b );
	float time;
	float startTime;
	float projtime;
	float projstartTime;
	float randTime;


};
