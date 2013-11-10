#pragma once
#include "ofMain.h"
#include "globaldata.h"

class HUD {
public:
	void draw();
	void update();
	void updateScore();
	void drawHealth();
	void setup();


	float scoreTime;
	float scoreStartTime;
	float rawScore;
	ofTrueTypeFont pixfont;


};