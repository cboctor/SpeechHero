#include "Player.h"



void Player::setup(){
	keycount = 0;
	isMidAir = false;
	isDirectionRight = true;
	circle.setPhysics(1, 0.1, 1);
	worldBounds.set(0, 0 , ofGetWidth(), 650);
	box2dworld.init();
	box2dworld.setFPS(60);
	box2dworld.setGravity(0, 10);
	box2dworld.createBounds(worldBounds);
	box2dworld.registerGrabbing();
	circle.setup(box2dworld.getWorld(), 500,500, 30);
	keypressed = "nothing";
	player.setup("assets/skeleton.atlas", "assets/skeleton.json", 0.4);
	AnimationState_setAnimationByName(player.getState(), "standing", true);
	player.setPosition(circle.getPosition());
	
	
}

float Player::getX()
{
	return x = player.getPosition().x;
}

float Player::getY()
{
	return y = player.getPosition().y;
}

void setX(){}
void setY(){}

void Player::update()
{
	box2dworld.update();
	b2Vec2 vel = circle.body->GetLinearVelocity();
	
	player.update(1.0f /60);
	player.setPosition(circle.getPosition());
	
	if (keypressed == "key-left" && !isMidAir)
		{
			if (keycount ==1)
				AnimationState_setAnimationByName(player.getState(), "walk", true);
			vel.x = -10;
			keycount ++;
		}

	else if (keypressed == "key-right" && !isMidAir)
	{
		if (keycount ==1)
			AnimationState_setAnimationByName(player.getState(), "walk", true);
		keycount ++;
		vel.x = 10;
	}
	else if (keypressed == "key-up" && !isMidAir)
		vel.y = 100;
	else if (keypressed == "key-up" && isMidAir)
	{
				if (keycount >=1)
					AnimationState_setAnimationByName(player.getState(), "jump", false);
				keycount ++;
			
	}
	else if (keypressed =="released" && !isMidAir)
	{
		vel.x= 0;
		AnimationState_setAnimationByName(player.getState(), "standing", true);
	}
	else if (keypressed == "released" && isMidAir)
		{vel.x *=0.99;
	AnimationState_setAnimationByName(player.getState(), "jump", false);}
	else if (keypressed == "key-down")
	{
		if (keycount ==1)
		AnimationState_setAnimationByName(player.getState(), "duck", false);
		keycount ++;

	}

	circle.body->SetLinearVelocity(vel);

	
		if ( circle.body->GetLinearVelocity().y != 0 ) {
			 isMidAir = true;			 
			} else { 
			  isMidAir = false;
		}

		if (isMidAir)
		{
	
		}
}


void Player::keyPressed(int key){

	if (key == OF_KEY_UP)
	{
		keypressed = "key-up";
	}

	if (key == OF_KEY_DOWN)
	{
		keypressed = "key-down";
	}

	if (key == OF_KEY_RIGHT)
	{
		keypressed = "key-right";
		if (!isDirectionRight)
		{
			isDirectionRight = true;
			player.getSkeleton()->flipX = false;
		}
	}

	if (key == OF_KEY_LEFT)
	{
		keypressed = "key-left";
		if (isDirectionRight)
		{
			isDirectionRight = false;
			player.getSkeleton()->flipX = true;
		}
	}
}

void Player::keyReleased(int key){
	keypressed = "released";
	keycount = 0;
	AnimationState_setAnimationByName(player.getState(), "standing", true);
}


void Player::draw()
{
	player.draw();
	circle.draw();
}

void Player::exit()
{
	player.~ofxSkeleton();
}