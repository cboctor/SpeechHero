#pragma once

#include "ofMain.h"
#include "ofxSpine.h"
#include "ofxBox2d.h"


extern  int numFootContacts;

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
		
		ofxBox2d box2dworld;
		ofRectangle worldBounds;


		

	
		
};


class MyContactListener : public b2ContactListener
  {
      void BeginContact(b2Contact* contact) {
          //check if fixture A was the foot sensor
          void* fixtureUserData = contact->GetFixtureA()->GetUserData();
          if ( (int)fixtureUserData == 3 )
              numFootContacts++;
          //check if fixture B was the foot sensor
          fixtureUserData = contact->GetFixtureB()->GetUserData();
          if ( (int)fixtureUserData == 3 )
              numFootContacts++;
      }
  
      void EndContact(b2Contact* contact) {
          //check if fixture A was the foot sensor
          void* fixtureUserData = contact->GetFixtureA()->GetUserData();
          if ( (int)fixtureUserData == 3 )
              numFootContacts--;
          //check if fixture B was the foot sensor
          fixtureUserData = contact->GetFixtureB()->GetUserData();
          if ( (int)fixtureUserData == 3 )
              numFootContacts--;
      }
  };

