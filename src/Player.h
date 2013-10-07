#pragma once

#include "ofMain.h"
#include "ofxSpine.h"
#include "ofxBox2d.h"



class Player
{
public:
		
		void setup();
		void update();
		float getX();
		float getY();
		void setX();
		void setY();
		void keyPressed(int key);
		void keyReleased(int key);
		void draw();
		void exit();


		ofxSkeleton player;

		ofxSkeleton getSkeleton(){
        return player;
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

