#pragma once
#include "Player.h"
#include "Item.h"
#include "ofxBox2d.h"
#include "globaldata.h"
//#include "Player.h"



//vector<CustomItem> items;
class MyContactListener : public b2ContactListener
  {
      

  public:
	  void BeginContact(b2Contact* contact);
	  void EndContact(b2Contact* contact);
	  void beginContactFoot(b2Contact* contact);
	  void endContactFoot(b2Contact* contact);
	  void beginItemContact(b2Contact* contact);
	  void endItemContact(b2Contact* contact);
	  void beginMonsterContact(b2Contact* contact);
	  void beginFireballContact(b2Contact* contact);
  };