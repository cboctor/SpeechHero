#include "globaldata.h"

namespace GlobalData
{
	  ofxBox2d box2dworld;
	  int numFootContacts;
	  vector <CustomItem>	items;
	  vector <MonsterBody> m_bodies;
	  vector <FireballProjectile>	fb_projectiles;
	  vector <SkullsProjectile> skulls_projectiles;
	  b2Body* playerBody;
	  float healthPercent;
	  int itemIndex;
	  string itemType;
	  int scoreMultiplier;
	  int score;
	  string enemyType;
	  bool isRecording;
	  int wordsIncorrect;
	  int wordsCorrect;
	  string highscoresTable;
	  string hsusername;
	  string hsscore;
	  string hsmultiplier;
	  string hscorrect;
	  string hsincorrect;
	  

 
}