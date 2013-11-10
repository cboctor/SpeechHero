#include "HUD.h"


void HUD::setup()
{
	scoreStartTime = ofGetElapsedTimeMillis();
	pixfont.loadFont("pix.ttf", 32);
}

void HUD::draw()
{

}


void HUD::update()
{
	updateScore();
}

void HUD::updateScore()
{
	scoreTime = ofGetElapsedTimeMillis() - scoreStartTime;
	GlobalData::score = GlobalData::scoreMultiplier * rawScore;
	if (scoreTime >= 500)
	{
		scoreStartTime = ofGetElapsedTimeMillis();
		rawScore += 15;
	}
	
}