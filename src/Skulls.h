#pragma once

#include "ofMain.h"
#include "ofxSpine.h"
#include "ofxBox2d.h"



class Skulls
{
public:
		
		void setup();
		void update();
		float getX();
		float getY();
		void createSkulls();
		void updateSmallSkulls();
		void updateBigSkull();
		void keyPressed(int key);
		void exit();
		
		void draw();


		ofxSkeleton skeleton;

		ofxSkeleton getSkeleton(){
        return skeleton;
		}


protected:
		float x;
		float y;
		string keypressed;
		int keycount;
		bool isMidAir;
		bool isDirectionRight;
		ofxBox2dCircle circle;
		ofxBox2d box2dworld;
		ofRectangle worldBounds;

		

	
		
};

