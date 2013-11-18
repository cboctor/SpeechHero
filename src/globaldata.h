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
   extern string enemyType;
   extern bool isRecording;
   extern int wordsIncorrect;
   extern int wordsCorrect;
   extern string highscoresTable;
   extern string hsusername;
   extern string hsscore;
   extern string hsmultiplier;
   extern string hscorrect;
   extern string hsincorrect;
   
   
}

#endif GLOBALDATA_H