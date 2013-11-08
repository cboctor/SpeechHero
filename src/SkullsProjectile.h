#pragma once

#include "ofxSpine.h"
#include "ofxBox2d.h"



// A simple little Data class. This is were
// you can store anything you want.
class SkullData {
public:
	float x;
	float y;
	ofColor color;
	string  name;
	int		id;
	ofxSkeleton skeleton;
};


// A Custom Particle extedning the box2d circle
class SkullsProjectile : public ofxBox2dCircle {
	
public:
	
	void setupProjectileData() {
		
		static int colors[] = {0xcae72b, 0xe63b8f, 0x2bb0e7};
		static string abc   = "abcdefghijklmnopqrstuvwxyz";
		
		// we are using a Data pointer because 
		// box2d needs to have a pointer not 
		// a referance
		setData(new SkullData());
		SkullData * theData = (SkullData*)getData();
		bHit = false;
		onScreen = true;
		theData->id = ofRandom(0, 100);
		theData->name += abc[(int)ofRandom(0, abc.size())];
		theData->color.setHex(colors[(int)ofRandom(0, 3)]);
		theData->skeleton.setup("assets/skull.atlas", "assets/skull.json", 1.0);
		AnimationState_setAnimationByName(theData->skeleton.getState(), "littleskull", false);

		printf("setting the custom data!\n");
		
	}
	
	void draw() {
		SkullData* theData = (SkullData*)getData();
		theData->skeleton.draw();
		if(theData) {
			
			// Evan though we know the data object lets just 
			// see how we can get the data out from box2d
			// you would use this when using a contact listener
			// or tapping into box2d's solver.
			
			/*float radius = getRadius();
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
			ofPopMatrix();*/
		}
	}

	void update()
	{
		SkullData* theData = (SkullData*)getData();
		//theData->skeleton.setPosition (ofPoint (x,y+55));
		//theData->skeleton.update(1.0f/60);
		float x = getPosition().x;
		float y = getPosition().y;
		float rotation = getRotation();
		
		theData->skeleton.setPosition (ofPoint (x,y));
		theData->skeleton.setRotation(rotation);
		theData->skeleton.update(1.0f/60);


		
		
	}

	bool bHit;
	bool onScreen;
		
		
};
