#include "globaldata.h"

namespace GlobalData
{
	  ofxBox2d box2dworld;
	  int numFootContacts;
	  vector <CustomItem>	items;
	  vector <MonsterBody> m_bodies;
	  vector <FireballProjectile>	fb_projectiles;
	  b2Body* playerBody;
	  float healthPercent;

 
}