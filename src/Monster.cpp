#include "Monster.h"



ofPoint monsterpos;



void Monster::setup(){
	

	/*worldBounds.set(0, 0 , ofGetWidth(), 650);
	box2dworld.init();
	box2dworld.setFPS(60);
	box2dworld.setGravity(0, 10);
	box2dworld.createBounds(worldBounds);
	box2dworld.registerGrabbing();*/
	skeleton.setup("assets/monster.atlas", "assets/monster.json", 0.4);
	
	monsterpos.x = -250;
	monsterpos.y = 500;
	skeleton.setPosition(monsterpos);

	AnimationState_setAnimationByName(skeleton.getState(), "animation", true);
	createMonster();
	setupState = "setup";
	
	
}


void Monster::createMonster()
{
	float radius = 50.0;
	
		monsterbody.setPhysics(3.0, 0.53, 0.1);
		monsterbody.setup(box2dworld.getWorld(),monsterpos.x, monsterpos.y, radius);
		
	

	

}


float Monster::getX()
{
	return x = skeleton.getPosition().x;
}

float Monster::getY()
{
	return y = skeleton.getPosition().y;
}



void Monster::update()
{
//	_box2dworld.update();
	if (setupState == "setup")
	{
	ofPoint position = monsterbody.getPosition();
	ofPoint drawPos;
	drawPos.y = position.y + 55;
	drawPos.x = position.x;
	skeleton.setPosition(drawPos);
	skeleton.update(1.0f /60);
	b2Vec2 vel = monsterbody.body->GetLinearVelocity();
	vel.x = 5;
	monsterbody.body->SetLinearVelocity(vel);

	if (monsterbody.getPosition().x >= ofGetWidth())
		monsterbody.getWorld()->DestroyBody(monsterbody.body);
	
	
	
	}

	
		
}



void Monster::draw()
{
	

	
	skeleton.draw();
	
	


	
}

void Monster::keyPressed(int key){



}

Monster::~Monster()
{
	//monsterbody.getWorld()->DestroyBody(monsterbody.body);
	//skeleton.~ofxSkeleton();


}