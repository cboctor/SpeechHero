#include "Dragon.h"
//
//



void Dragon::update()
{
	time = ofGetElapsedTimeMillis() - startTime;
	projtime = ofGetElapsedTimeMillis() - projstartTime;
	
	dragon.update(1.0f/60);
	createProjectile();
	//dragon.
	dragonPos.x +=2;
	dragonHead = SkeletonData_findBone (dragon.getSkeletonData(), "head");
	headPos.x = dragonHead->x + dragonPos.x;
	headPos.y = dragonPos.y;// dragonHead->y + dragonPos.y;
	
	//headPos.y = dragonHead->y;
	dragon.setPosition(dragonPos);
	if (dragonPos.x >= ofGetWidth()+1000)
		dragonPos.x =-1000;
	

	for(int i=0; i<GlobalData::fb_projectiles.size(); i++) {
		
		float x = GlobalData::fb_projectiles[i].getPosition().x;
		b2Vec2 Velocity = GlobalData::fb_projectiles[i].body->GetLinearVelocity();
		

		if (x >0 && x <ofGetWidth() && !GlobalData::fb_projectiles[i].bHit)
			GlobalData::fb_projectiles[i].update();
		else
		{
				GlobalData::fb_projectiles[i].body->GetWorld()->DestroyBody(GlobalData::fb_projectiles[i].body);
				GlobalData::fb_projectiles.erase(GlobalData::fb_projectiles.begin()+i );
		}

			/*if (x < 0 || x > ofGetWidth() )
			{
				GlobalData::fb_projectiles[i].body->GetWorld()->DestroyBody(GlobalData::fb_projectiles[i].body);
				GlobalData::fb_projectiles.erase(GlobalData::fb_projectiles.begin()+i );
			}*/

		/*	if (GlobalData::fb_projectiles[i].bHit)
			{
				GlobalData::fb_projectiles[i].body->GetWorld()->DestroyBody(GlobalData::fb_projectiles[i].body);
				GlobalData::fb_projectiles.erase(GlobalData::fb_projectiles.begin()+i );
			}*/

		
			
			
			
			
		

		
	}


}
//
void Dragon::createProjectile()
{
	
	if (time >= randTime)
	{
		FireballProjectile p;
		p.setPhysics(1.0, 0.5, 0.3);
		p.setup(GlobalData::box2dworld.getWorld(), headPos.x, headPos.y, ofRandom(20, 60));
		p.setupProjectileData() ;
		GlobalData::fb_projectiles.push_back(p);
		startTime = ofGetElapsedTimeMillis();
		projstartTime = ofGetElapsedTimeMillis();
		randTime = ofRandom(1,5) * 1000;
		head = SkeletonData_findBone (dragon.getSkeletonData(), "bone3");
		float rotation = head->rotation;
		float magnitude = GlobalData::fb_projectiles.back().body->GetMass()*10;
		b2Vec2 force = b2Vec2(cos(rotation) * magnitude , sin(rotation) * magnitude);
		GlobalData::fb_projectiles.back().body->ApplyLinearImpulse(force, GlobalData::fb_projectiles.back().body->GetPosition());
	}
}

float Dragon::radDiff( float a, float b )
   {
      return atan2( sin(a-b), cos(a-b) );
   }
//
void Dragon::createDragon()
{
	dragon.setup("assets/dragon.atlas", "assets/dragon.json", 0.3);
	AnimationState_setAnimationByName(dragon.getState(), "fly", true);
	dragonPos.x = -50;
	dragonPos.y = 250;
	dragon.setPosition(dragonPos);
	startTime = ofGetElapsedTimeMillis();
	projstartTime = ofGetElapsedTimeMillis();
	randTime = 2000;

}


void Dragon::draw()
{
	
	
	for(int i=0; i<GlobalData::fb_projectiles.size(); i++) {
		GlobalData::fb_projectiles[i].draw();
	}
	dragon.draw();
	
}
