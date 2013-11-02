//#pragma once
//#include "ofMain.h"
//#include "ofxBox2d.h"
//#include "ofxSpine.h"
//#include "Player.h"
//
//
//// A simple little Data class. This is were
//// you can store anything you want.
//class Data {
//public:
//	float x;
//	float y;
//	//ofxSkeleton skeleton;
//	ofColor color;
//	string  name;
//	int		id;
//};
//
//
//// A Custom Particle extedning the box2d circle
//class CustomParticle : public ofxBox2dCircle {
//	
//public:
//	
//	void setupTheCustomData() {
//		
//		static int colors[] = {0xcae72b, 0xe63b8f, 0x2bb0e7};
//		static string abc   = "abcdefghijklmnopqrstuvwxyz";
//		
//		// we are using a Data pointer because 
//		// box2d needs to have a pointer not 
//		// a referance
//		setData(new Data());
//		Data * theData = (Data*)getData();
//		
//		theData->id = ofRandom(0, 100);
//		theData->name += abc[(int)ofRandom(0, abc.size())];
//		theData->color.setHex(colors[(int)ofRandom(0, 3)]);
//	
//
//		printf("setting the custom data!\n");
//		
//	}
//	
//	void draw() {
//		Data* theData = (Data*)getData();
//		//theData->skeleton.draw();
//		if(theData) {
//			
//			// Evan though we know the data object lets just 
//			// see how we can get the data out from box2d
//			// you would use this when using a contact listener
//			// or tapping into box2d's solver.
//			
//			float radius = getRadius();
//			ofPushMatrix();
//			ofTranslate(getPosition());
//			ofRotateZ(getRotation());
//			ofSetColor(theData->color);
//			
//			ofFill();
//			ofCircle(0, 0, radius);	
//			
//			ofSetColor(255);
//			ofDrawBitmapString(theData->name, -5, 5);
//			ofPopMatrix();
//		}
//	}
//
//	void update()
//	{
//		Data* theData = (Data*)getData();
//		//theData->skeleton.setPosition (ofPoint (x,y+55));
//		//theData->skeleton.update(1.0f/60);
//		
//		
//	}
//		
//		
//};
//
//// ------------------------------------------------- App
//class Dragon {
//	
//public:
//	
//	void setup();
//	void update();
//	void draw();
//	void createDragon();
//	void createProjectile();
//	vector <CustomParticle>		particles;
//	ofxSkeleton dragon;
//	ofPoint dragonPos;
//	BoneData *dragonHead;
//	ofPoint headPos;
//	
//};
