#include "Skulls.h"
//
//



void Skulls::update()
{
	time = ofGetElapsedTimeMillis() - startTime;
	spawntime = ofGetElapsedTimeMillis() - spawnstartTime;
	skull.update(1.0f/60);
	setEyePosition();
	skullBehaviour();
	removeProjectiles();
	

	
}

void Skulls::removeProjectiles()
{
	for(int i=0; i<GlobalData::skulls_projectiles.size(); i++) {
		float x = GlobalData::skulls_projectiles[i].getPosition().x;
		if (x >0 && x <ofGetWidth() && !GlobalData::skulls_projectiles[i].bHit)
			GlobalData::skulls_projectiles[i].update();
		else
		{
				GlobalData::skulls_projectiles[i].body->GetWorld()->DestroyBody(GlobalData::skulls_projectiles[i].body);
				GlobalData::skulls_projectiles.erase(GlobalData::skulls_projectiles.begin()+i );
		}
	}

}

void Skulls::setEyePosition()
{
	leftEye = SkeletonData_findBone (skull.getSkeletonData(), "left_eye");
	rightEye = SkeletonData_findBone (skull.getSkeletonData(), "right_eye");
	head = SkeletonData_findBone (skull.getSkeletonData(), "head");
	leftEyePos.x = leftEye->x + skullPos.x;
	leftEyePos.y = leftEye->y +skullPos.y - head->y;
	rightEyePos.x = rightEye->x + skullPos.x;
	rightEyePos.y = rightEye->y +skullPos.y - head->y;
}


void Skulls::skullBehaviour()
{
	if (spawntime > 120000)
	{
		GlobalData::enemyType = "skull";
		if (skullPos.x < ofGetWidth()/2 || skullPos.x > ofGetWidth()/2)
			skullPos.x +=1;
		else
		{
			createProjectile();
			if (spawntime >= 155000)
				skullPos.x +=1;
		}

		skull.setPosition(skullPos);
		if (skullPos.x >= ofGetWidth()+500)
			{
				spawnstartTime = ofGetElapsedTimeMillis();
				skullPos.x =-500;
				GlobalData::enemyType = "dragon";
			}
	}
}


void Skulls::createProjectile()
{
	if (time >= randTime)
	{
		ofPoint eyePosition;
		int rndNum = ofRandom(0,2);
		if (rndNum ==1)
		{
			eyePosition.x = leftEyePos.x;
			eyePosition.y = leftEyePos.y;
		}
		else
		{
			eyePosition.x = rightEyePos.x;
			eyePosition.y = rightEyePos.y;
		}

		SkullsProjectile p;
		p.setPhysics(1.0, 0.5, 0.3);
		p.setup(GlobalData::box2dworld.getWorld(), eyePosition.x, eyePosition.y, 30);
		p.setupProjectileData() ;
		GlobalData::skulls_projectiles.push_back(p);
		startTime = ofGetElapsedTimeMillis();
		randTime = ofRandom(1,5) * 1000;
		ofPoint p1;
		p1 =GlobalData::skulls_projectiles.back().getPosition();
		ofPoint p2;
		p2.x = GlobalData::playerBody->GetPosition().x *OFX_BOX2D_SCALE;
		p2.y = GlobalData::playerBody->GetPosition().y *OFX_BOX2D_SCALE;
		float angle = atan2(p2.y - p1.y, p2.x - p1.x);
		float magnitude = GlobalData::skulls_projectiles.back().body->GetMass()*10;
		b2Vec2 force = b2Vec2(cos(angle) * magnitude , sin(angle) * magnitude);
		GlobalData::skulls_projectiles.back().body->ApplyLinearImpulse(force, GlobalData::skulls_projectiles.back().body->GetPosition());
	}
}

void Skulls::createSkulls()
{
	skull.setup("assets/skull.atlas", "assets/skull.json", 0.7);
	AnimationState_setAnimationByName(skull.getState(), "bigskull", true);
	skullPos.x = -300;
	skullPos.y = ofGetHeight()/2;
	skull.setPosition(skullPos);
	startTime = ofGetElapsedTimeMillis();
	spawnstartTime = ofGetElapsedTimeMillis();
	randTime = 1000;

}


void Skulls::draw()
{
	
		skull.draw();
	for(int i=0; i<GlobalData::skulls_projectiles.size(); i++) {
		GlobalData::skulls_projectiles[i].draw();
	}

	
}

void Skulls::keyPressed(int key){
	SkullsProjectile p;
		p.setPhysics(1.0, 0.5, 0.3);
		p.setup(GlobalData::box2dworld.getWorld(), leftEyePos.x, leftEyePos.y, 30);
		p.setupProjectileData() ;
		GlobalData::skulls_projectiles.push_back(p);
}
