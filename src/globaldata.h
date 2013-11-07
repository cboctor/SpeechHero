#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include "ofxBox2d.h" // Definition of Object might be here
#include "CustomItem.h"
#include "MonsterBody.h"
#include "FireballProjectile.h"

namespace GlobalData
{
   extern ofxBox2d box2dworld;
   extern int numFootContacts;
   extern vector <CustomItem>	items;
   extern vector <MonsterBody> m_bodies;
   extern vector <FireballProjectile>	fb_projectiles;
   extern b2Body* playerBody;
   extern float healthPercent;
}

#endif GLOBALDATA_H