#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxSpine.h"
#include "Player.h"
#include "SkullsProjectile.h"
#include "globaldata.h"



// ------------------------------------------------- App
class Skulls {
	
public:
	
	void setup();
	void update();
	void draw();
	void createSkulls();
	void createProjectile();
	void keyPressed(int key);
	void setEyePosition();
	void skullBehaviour();
	void removeProjectiles();
	
	ofxSkeleton skull;
	ofPoint skullPos;
	BoneData *leftEye;
	BoneData *rightEye;
	BoneData *head;
	ofPoint headPos;
	ofPoint leftEyePos;
	ofPoint rightEyePos;
	float radDiff( float a, float b );
	float time;
	float startTime;
	float spawntime;
	float spawnstartTime;
	float randTime;


};
