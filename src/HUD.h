#pragma once
#include "ofMain.h"
#include "globaldata.h"

class HUD {
public:
	void draw();
	void update();
	void updateScore();
	void drawScore();
	void drawHealth();
	void updateHealth();
	void setup();
	void drawLetters();


	float scoreTime;
	float scoreStartTime;
	float rawScore;
	ofTrueTypeFont pixfont;
	ofImage letters[6];


};