#pragma once

#include "ofMain.h"
#include "ofxSpine.h"
#include "ofxBox2d.h"
#include "Player.h"



class Monster
{
public:
		
		void setup();
		void update();
		float getX();
		float getY();
		void updateBigSkull();
		void keyPressed(int key);
		//void exit();
		void createMonster();
		void draw();
		int drawCount;
		~Monster();

		string setupState;

		ofxSkeleton skeleton;
		ofxBox2dCircle monsterbody;

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
	

		

	
		
};

