#include "Player.h"



void Player::setup(){
	keycount = 0;
	isMidAir = false;
	isDirectionRight = false;
	circle.setPhysics(1, 0.1, 1);
    circle.setup(box2dworld.getWorld(), 500, 500, 30);
	keypressed = "nothing";
}

float Player::getX()
{
	return x;
}

float Player::getY()
{
	return y;
}

void setX(){}
void setY(){}

void Player::update()
{
	b2Vec2 vel = circle.body->GetLinearVelocity();

	if (keypressed == "key-left" && !isMidAir)
		{
			if (keycount ==1)
				AnimationState_setAnimationByName(player ->getState(), "walk", true);
			vel.x = -10;
			keycount ++;
		}

	else if (keypressed == "key-right" && !isMidAir)
	{
		if (keycount ==1)
			AnimationState_setAnimationByName(player->getState(), "walk", true);
		keycount ++;
		vel.x = 10;
	}
	else if (keypressed == "key-up" && !isMidAir)
		vel.y = 100;
	else if (keypressed =="released" && !isMidAir)
	{
		vel.x= 0;
	}
	else if (keypressed == "released" && isMidAir)
		vel.x *=0.99;
	else if (keypressed == "key-down")
	{
		if (keycount ==1)
		AnimationState_setAnimationByName(player->getState(), "duck", false);
		keycount ++;

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
			player->getSkeleton()->flipX = false;
		}
	}

	if (key == OF_KEY_LEFT)
	{
		keypressed = "key-left";
		if (isDirectionRight)
		{
			isDirectionRight = false;
			player->getSkeleton()->flipX = true;
		}
	}
}

