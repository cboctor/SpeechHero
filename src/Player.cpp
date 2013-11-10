#include "Player.h"



 MyContactListener myContactListenerInstance;
 //int GlobalData::numFootContacts;
 int setJump;



void Player::setup(){
	keycount = 0;
	isMidAir = false;
	isDirectionRight = true;
	worldBounds.set(0, 0 , ofGetWidth(), 650);
	keypressed = "nothing";
	player.setup("assets/MainChar2.atlas", "assets/MainChar2.json", 0.7);
	AnimationState_setAnimationByName(player.getState(), "standing", true);
	GlobalData::numFootContacts = 0;	
	GlobalData::box2dworld.getWorld()->SetContactListener(&myContactListenerInstance);
	setJump = 0;
	box2dplayerBody();
}

void Player::box2dplayerBody()
	{
      //body definition
		
      b2BodyDef myBodyDef;
      myBodyDef.type = b2_dynamicBody;
      myBodyDef.fixedRotation = true;
  
      //shape definition for main fixture
      b2PolygonShape polygonShape;
      polygonShape.SetAsBox(1, 2.5); //a 2x4 rectangle
  
      //fixture definition
      b2FixtureDef myFixtureDef;
      myFixtureDef.shape = &polygonShape;
      myFixtureDef.density = 0.1;
  
      //create dynamic body
      myBodyDef.position.Set(500/OFX_BOX2D_SCALE, 500/OFX_BOX2D_SCALE); //middle
      GlobalData::playerBody = GlobalData::box2dworld.getWorld()->CreateBody(&myBodyDef);
  
      //add main fixture
      GlobalData::playerBody->CreateFixture(&myFixtureDef);
	  
      //add foot sensor fixture
      polygonShape.SetAsBox(0.3, 0.3, b2Vec2(0,2.5), 0);
      myFixtureDef.isSensor = true;
      b2Fixture* footSensorFixture = GlobalData::playerBody->CreateFixture(&myFixtureDef);
      footSensorFixture->SetUserData( (void*)3 );
  }

void Player::obstacles()
	{
      //body definition
      b2BodyDef myBodyDef;
      myBodyDef.position.Set(-5/OFX_BOX2D_SCALE,5/OFX_BOX2D_SCALE);
      myBodyDef.type = b2_dynamicBody;
  
      //shape definition
      b2PolygonShape polygonShape;
      polygonShape.SetAsBox(1, 1); //a 2x2 rectangle
  
      //fixture definition
      b2FixtureDef myFixtureDef;
      myFixtureDef.shape = &polygonShape;
      myFixtureDef.density = 1;
  
      for (int i = 0; i < 5; i++)
      {
          b2Fixture* fixture = GlobalData::box2dworld.getWorld()->CreateBody(&myBodyDef)->CreateFixture(&myFixtureDef);
          fixture->SetUserData( (void*)1 );//tag square boxes as 1
      }
  
      //change size
      polygonShape.SetAsBox(0.5, 1); //a 1x2 rectangle
      
      for (int i = 0; i < 5; i++)
      {
          b2Fixture* fixture = GlobalData::box2dworld.getWorld()->CreateBody(&myBodyDef)->CreateFixture(&myFixtureDef);
          fixture->SetUserData( (void*)2 );//tag smaller rectangular boxes as 2
      }
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

	GlobalData::box2dworld.update();
	limitToWindow();
	
	b2Vec2 vel = GlobalData::playerBody->GetLinearVelocity();
	b2Vec2 posVec;
	ofPoint posPoint;
	posVec = GlobalData::playerBody->GetPosition();
	posPoint.x = posVec.x * OFX_BOX2D_SCALE;
	posPoint.y = posVec.y * OFX_BOX2D_SCALE + 85;
	player.update(1.0f /60);
	player.setPosition(posPoint);
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
	else if (keypressed == "key-up")
	{
		if (GlobalData::numFootContacts >= 1 && !isMidAir) //Check if Player is standing before being allowed to jump
		{
		 float force = GlobalData::playerBody->GetMass() * 250 ;
		  GlobalData::playerBody->ApplyForce( b2Vec2(0,-force), GlobalData::playerBody->GetWorldCenter() );
		}
	}
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
	AnimationState_setAnimationByName(player.getState(), "jump", false);
	}
	else if (keypressed == "key-down" && !isMidAir)
	{
		if (keycount ==1)
		AnimationState_setAnimationByName(player.getState(), "duck", false);
		keycount ++;

	}

	
		if ( GlobalData::numFootContacts <1 ) {
			 isMidAir = true;			 
			} else { 
			  isMidAir = false;
		}

		if (isMidAir)
		{
			cout <<isMidAir;
		}
		GlobalData::playerBody->SetLinearVelocity(vel);



		
}

void Player::limitToWindow()
{
	float x = GlobalData::playerBody->GetPosition().x * OFX_BOX2D_SCALE;
	float y = GlobalData::playerBody->GetPosition().y * OFX_BOX2D_SCALE;

	if (x<=0)
	{
	GlobalData::playerBody->SetTransform(b2Vec2(b2dNum(1), b2dNum(y)), 0);
	//body->SetLinearVelocity(b2Vec2(0, 0)); // maybe bring this back...
	GlobalData::playerBody->SetAwake(true); // this sounds backwards but that is what the doc says todo...
	}

	if (x>ofGetWidth())
	{
		GlobalData::playerBody->SetTransform(b2Vec2(b2dNum(ofGetWidth()-1), b2dNum(y)), 0);
	//body->SetLinearVelocity(b2Vec2(0, 0)); // maybe bring this back...
		GlobalData::playerBody->SetAwake(true); // this sounds backwards but that is what the doc says todo...
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
	//GlobalData::box2dworld.getWorld()->DrawDebugData();
}

void Player::exit()
{
	player.~ofxSkeleton();
}