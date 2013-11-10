#include "Dragon.h"
//
//



void Dragon::update()
{
	time = ofGetElapsedTimeMillis() - startTime;
	spawnTime = ofGetElapsedTimeMillis() - spawnstartTime;
	
	dragon.update(1.0f/60);
	updateHeadPosition();
	createProjectile();
	dragonBehaviour();
	removeProjectiles();
	

	
}

void Dragon::updateHeadPosition()
{
	dragonHead = SkeletonData_findBone (dragon.getSkeletonData(), "head");
	headPos.x = dragonHead->x + dragonPos.x;
	headPos.y = dragonPos.y;// dragonHead->y + dragonPos.y;
}

void Dragon::dragonBehaviour()
{
	if (spawnTime >=25000 && GlobalData::enemyType =="dragon")
	{
		dragonPos.x +=2;
	}
	else if (dragonPos.x + 300 > 0 && dragonPos.x-1000 < ofGetWidth())
		dragonPos.x +=2;

		dragon.setPosition(dragonPos);
		if (dragonPos.x >= ofGetWidth()+1000)
		{
			spawnstartTime = ofGetElapsedTimeMillis();
			dragonPos.x =-1000;
		}
		
	
	
}

void Dragon::removeProjectiles()
{
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
		randTime = ofRandom(1,5) * 1000;
		head = SkeletonData_findBone (dragon.getSkeletonData(), "bone3");
		float rotation = head->rotation;
		float magnitude = GlobalData::fb_projectiles.back().body->GetMass()*10;
		b2Vec2 force = b2Vec2(cos(rotation) * magnitude , sin(rotation) * magnitude);
		GlobalData::fb_projectiles.back().body->ApplyLinearImpulse(force, GlobalData::fb_projectiles.back().body->GetPosition());
	}
}

void Dragon::createDragon()
{
	dragon.setup("assets/dragon.atlas", "assets/dragon.json", 0.3);
	AnimationState_setAnimationByName(dragon.getState(), "fly", true);
	dragonPos.x = -500;
	dragonPos.y = 250;
	dragon.setPosition(dragonPos);
	startTime = ofGetElapsedTimeMillis();
	spawnstartTime = ofGetElapsedTimeMillis();
	randTime = 2000;
	GlobalData::enemyType = "dragon";

}


void Dragon::draw()
{
	
	
	for(int i=0; i<GlobalData::fb_projectiles.size(); i++) {
		GlobalData::fb_projectiles[i].draw();
	}
	dragon.draw();
	
}
 Dragon::~Dragon()
{
	dragon.~ofxSkeleton();
}
