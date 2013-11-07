#include "Skulls.h"

ofxBox2dCircle circles [10];
ofxSkeleton skulls [10];
ofPoint bigskullpos;
bool isNoAmmo;
//ofxBox2d GlobalData::box2dworld;

void Skulls::setup(){
	
	isNoAmmo = false;
	/*worldBounds.set(0, 0 , ofGetWidth(), 650);
	GlobalData::box2dworld.init();
	GlobalData::box2dworld.setFPS(60);
	GlobalData::box2dworld.setGravity(0, 10);
	GlobalData::box2dworld.createBounds(worldBounds);
	GlobalData::box2dworld.registerGrabbing();*/
	skeleton.setup("assets/skull.atlas", "assets/skull.json", 0.6);
	
	bigskullpos.x = -250;
	bigskullpos.y = ofGetHeight()/2;
	skeleton.setPosition(bigskullpos);

	AnimationState_setAnimationByName(skeleton.getState(), "bigskull", true);
	createSkulls();
	
	
}

void Skulls::createSkulls()
{
	float radius = 30.0;
		for (int i=0; i<10; i++){
		circles[i].setPhysics(3.0, 0.53, 0.1);
		circles[i].setup(GlobalData::box2dworld.getWorld(),ofGetWidth()/2, ofGetHeight()/2, radius);
		skulls[i].setup("assets/skull.atlas", "assets/skull.json", 1.0);
		AnimationState_setAnimationByName(skulls[i].getState(), "littleskull", false);
	}

	

}

void Skulls::updateSmallSkulls()
{

	for (int i=0; i<10; i++){
		ofPoint position = circles[i].getPosition();
		float rotation = circles[i].getRotation();
		skulls[i].setPosition(position);
		skulls[i].setRotation(rotation);
		skulls[i].update(1.0f/60);
	}
}

void Skulls::updateBigSkull()
{
	if (bigskullpos.x < ofGetWidth()/2)
		bigskullpos.x +=1;
	skeleton.setPosition(bigskullpos);
	

}

float Skulls::getX()
{
	return x = skeleton.getPosition().x;
}

float Skulls::getY()
{
	return y = skeleton.getPosition().y;
}



void Skulls::update()
{
//	_GlobalData::box2dworld.update();
	
	skeleton.update(1.0f /60);
	
	updateSmallSkulls();
	updateBigSkull();
	//skeleton.setPosition(circle.getPosition());
	

	
		
}



void Skulls::draw()
{
	/*skeleton.draw();
	circle.draw();
	smallskull.draw();

*/
	skeleton.draw();
	circle.draw();
	for (int i =0; i<10; i++){
		//circles[i].draw();
		skulls[i].draw();
	}
	//smallskull.draw();

	
}

void Skulls::keyPressed(int key){



}

void Skulls::exit()
{
	for (int i=0; i <10; i++)
	{
		skulls[i].~ofxSkeleton();
	}
	skeleton.~ofxSkeleton();


}