#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include "ofxBox2d.h" // Definition of Object might be here
#include "CustomItem.h"
#include "MonsterBody.h"
#include "FireballProjectile.h"
#include "SkullsProjectile.h"

namespace GlobalData
{
   extern ofxBox2d box2dworld;
   extern int numFootContacts;
   extern vector <CustomItem>	items;
   extern vector <MonsterBody> m_bodies;
   extern vector <FireballProjectile>	fb_projectiles;
   extern vector <SkullsProjectile> skulls_projectiles;
   extern b2Body* playerBody;
   extern float healthPercent;
   extern int itemIndex;
   extern string itemType;
   extern int scoreMultiplier;
   extern int score;
   
   
}

#endif GLOBALDATA_H