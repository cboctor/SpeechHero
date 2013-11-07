#pragma once

#include "ofMain.h"
#include "ofxSpine.h"
#include "ofxBox2d.h"
#include "globaldata.h"
#include "ContactListener.h"


//extern ofxBox2d box2dworld;
//extern b2Body* dynamicBody;
//vector <CustomItem>	items;

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
		void obstacles();
		void box2dplayerBody();
		
		b2Vec2 vel ;
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
		ofRectangle worldBounds;


		

	
		
};



