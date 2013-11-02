#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxSpine.h"
#include "Player.h"


// A simple little Data class. This is were
// you can store anything you want.
class DragonData {
public:
	float x;
	float y;
	ofColor color;
	string  name;
	int		id;
};


// A Custom Particle extedning the box2d circle
class DragonProjectile : public ofxBox2dCircle {
	
public:
	
	void setupProjectileData() {
		
		static int colors[] = {0xcae72b, 0xe63b8f, 0x2bb0e7};
		static string abc   = "abcdefghijklmnopqrstuvwxyz";
		
		// we are using a Data pointer because 
		// box2d needs to have a pointer not 
		// a referance
		setData(new DragonData());
		DragonData * theData = (DragonData*)getData();
		
		theData->id = ofRandom(0, 100);
		theData->name += abc[(int)ofRandom(0, abc.size())];
		theData->color.setHex(colors[(int)ofRandom(0, 3)]);
	

		printf("setting the custom data!\n");
		
	}
	
	void draw() {
		DragonData* theData = (DragonData*)getData();
		//theData->skeleton.draw();
		if(theData) {
			
			// Evan though we know the data object lets just 
			// see how we can get the data out from box2d
			// you would use this when using a contact listener
			// or tapping into box2d's solver.
			
			float radius = getRadius();
			ofPushMatrix();
			ofTranslate(getPosition());
			ofRotateZ(getRotation());
			ofSetColor(theData->color);
			
			ofFill();
			ofCircle(0, 0, radius);	
			
			ofSetColor(255);
			ofDrawBitmapString(theData->name, -5, 5);
			ofPopMatrix();
		}
	}

	void update()
	{
		DragonData* theData = (DragonData*)getData();
		//theData->skeleton.setPosition (ofPoint (x,y+55));
		//theData->skeleton.update(1.0f/60);
		
		
	}
		
		
};

// ------------------------------------------------- App
class Dragon {
	
public:
	
	void setup();
	void update();
	void draw();
	void createDragon();
	void createProjectile();
	vector <DragonProjectile>		particles;
	ofxSkeleton dragon;
	ofPoint dragonPos;
	BoneData *dragonHead;
	ofPoint headPos;
	void mousePressed(int x, int y, int button);
	
};
