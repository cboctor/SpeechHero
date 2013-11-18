#include "HUD.h"


void HUD::setup()
{
	scoreStartTime = ofGetElapsedTimeMillis();
	pixfont.loadFont("pix.ttf", 32);
	rawScore = 0;
	GlobalData::healthPercent = 1.0;
	GlobalData::scoreMultiplier =1 ;
	GlobalData::wordsCorrect = 0;
	GlobalData::wordsIncorrect = 0;
	GlobalData::score = 0;
	letters[0].loadImage("assets/S.png");
	letters[1].loadImage("assets/P.png");
	letters[2].loadImage("assets/E.png");
	letters[3].loadImage("assets/E.png");
	letters[4].loadImage("assets/C.png");
	letters[5].loadImage("assets/H.png");
}

void HUD::draw()
{
	drawHealth();
	drawScore();
	drawLetters();

}

void HUD::drawHealth()
{
	string s = "Health :";
	float barPosX = ofGetWidth() -300;
	float barPosY = ofGetHeight() -100;
	pixfont.drawString(s , barPosX - 100, barPosY+50);
	ofSetColor(250,250,250);
	ofRect(barPosX,barPosY+30,0, 200, 30);
	ofSetColor(250,0,0);
	ofRect(barPosX,barPosY+30,0, GlobalData::healthPercent*200, 30);
	ofSetColor(250,250,250);
	
	
}

void HUD::drawScore()
{
	string scoreLabel;
	scoreLabel = "Score: " + ofToString(GlobalData::score,1 );
	pixfont.drawString(scoreLabel, 50 , 50);
}



void HUD::update()
{
	updateScore();
	updateHealth();
}

void HUD::updateHealth()
{
	const int HEALTH_MAX = 1.0;
	const int HEALTH_MIN = 0;
	if (GlobalData::healthPercent > HEALTH_MAX)
		GlobalData::healthPercent =HEALTH_MAX;
	else if (GlobalData::healthPercent <=HEALTH_MIN)
		GlobalData::healthPercent = HEALTH_MIN;
	
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


void HUD::drawLetters()
{
	if (GlobalData::itemIndex <=6)
	{
		for (int i=0; i <GlobalData::itemIndex; i++)
		letters[i].draw(ofGetWidth()/2-80 + i*50, ofGetHeight()-80, 0, 48,48);
	}

}