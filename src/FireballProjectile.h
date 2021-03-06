#pragma once

#include "ofxSpine.h"
#include "ofxBox2d.h"



// A simple little Data class. This is were
// you can store anything you want.
class FireballData {
public:
	float x;
	float y;
	ofColor color;
	string  name;
	int		id;
};


// A Custom Particle extedning the box2d circle
class FireballProjectile : public ofxBox2dCircle {
	
public:
	
	void setupProjectileData() {
		
		static int colors[] = {0xcae72b, 0xe63b8f, 0x2bb0e7};
		static string abc   = "abcdefghijklmnopqrstuvwxyz";
		
		// we are using a Data pointer because 
		// box2d needs to have a pointer not 
		// a referance
		setData(new FireballData());
		FireballData * theData = (FireballData*)getData();
		bHit = false;
		onScreen = true;
		theData->id = ofRandom(0, 100);
		theData->name += abc[(int)ofRandom(0, abc.size())];
		theData->color.setHex(colors[(int)ofRandom(0, 3)]);
	

		printf("setting the custom data!\n");
		
	}
	
	void draw() {
		FireballData* theData = (FireballData*)getData();
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
			ofSetColor(255,165,0);
			ofFill();
			ofCircle(0, 0, radius);	
			radius = 0.8 * radius;
			ofSetColor(255,69,0);
			ofFill();
			ofCircle(0, 0, radius);	
			radius = 0.7 * radius;
			ofSetColor(255,0,0);
			ofFill();
			ofCircle(0, 0, radius);	

			
			ofSetColor(255);
			ofDrawBitmapString(theData->name, -5, 5);
			ofPopMatrix();
		}
	}

	void update()
	{
		FireballData* theData = (FireballData*)getData();
		//theData->skeleton.setPosition (ofPoint (x,y+55));
		//theData->skeleton.update(1.0f/60);
		if (body->GetPosition().x > ofGetWidth())
			onScreen = false;
		if (body->GetPosition().x < 0)
			onScreen = false;


		
		
	}

	bool bHit;
	bool onScreen;
		
		
};
