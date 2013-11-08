#include "Skulls.h"
//
//



void Skulls::update()
{
	time = ofGetElapsedTimeMillis() - startTime;
	projtime = ofGetElapsedTimeMillis() - projstartTime;
	
	skull.update(1.0f/60);
	createProjectile();
	//Skulls.
	
	leftEye = SkeletonData_findBone (skull.getSkeletonData(), "left_eye");
	rightEye = SkeletonData_findBone (skull.getSkeletonData(), "right_eye");
	head = SkeletonData_findBone (skull.getSkeletonData(), "head");
	leftEyePos.x = leftEye->x + skullPos.x;
	leftEyePos.y = leftEye->y +skullPos.y - head->y;
	rightEyePos.x = rightEye->x + skullPos.x;
	rightEyePos.y = rightEye->y +skullPos.y;
	
	
	if (skullPos.x < ofGetWidth()/2)
		skullPos.x +=1;

	skull.setPosition(skullPos);
	if (skullPos.x >= ofGetWidth()+1000)
		skullPos.x =-1000;
	

	for(int i=0; i<GlobalData::skulls_projectiles.size(); i++) {
		
		float x = GlobalData::skulls_projectiles[i].getPosition().x;
		b2Vec2 Velocity = GlobalData::skulls_projectiles[i].body->GetLinearVelocity();
		

		if (x >0 && x <ofGetWidth() && !GlobalData::skulls_projectiles[i].bHit)
			GlobalData::skulls_projectiles[i].update();
		else
		{
				GlobalData::skulls_projectiles[i].body->GetWorld()->DestroyBody(GlobalData::skulls_projectiles[i].body);
				GlobalData::skulls_projectiles.erase(GlobalData::skulls_projectiles.begin()+i );
		}
	}
}
//
void Skulls::createProjectile()
{
	
	if (time >= randTime)
	{
		SkullsProjectile p;
		p.setPhysics(1.0, 0.5, 0.3);
		p.setup(GlobalData::box2dworld.getWorld(), leftEyePos.x, leftEyePos.y, 30);
		p.setupProjectileData() ;
		GlobalData::skulls_projectiles.push_back(p);
		startTime = ofGetElapsedTimeMillis();
		projstartTime = ofGetElapsedTimeMillis();
		randTime = ofRandom(1,5) * 1000;
		//head = SkeletonData_findBone (Skulls.getSkeletonData(), "bone3");
		//float rotation = head->rotation;
		//float magnitude = GlobalData::skulls_projectiles.back().body->GetMass()*10;
		//b2Vec2 force = b2Vec2(cos(rotation) * magnitude , sin(rotation) * magnitude);
		//GlobalData::skulls_projectiles.back().body->ApplyLinearImpulse(force, GlobalData::skulls_projectiles.back().body->GetPosition());
	}
}

void Skulls::createSkulls()
{
	skull.setup("assets/skull.atlas", "assets/skull.json", 0.7);
	AnimationState_setAnimationByName(skull.getState(), "bigskull", true);
	skullPos.x = -250;
	skullPos.y = ofGetHeight()/2;
	skull.setPosition(skullPos);
	startTime = ofGetElapsedTimeMillis();
	projstartTime = ofGetElapsedTimeMillis();
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
