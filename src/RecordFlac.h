#pragma once

#include "ofMain.h"
#include <sndfile.h>



class RecordFlac
{
public:
		void setup();
		void update();
		void draw();
		void exit();
		void start();
		void stop();
		
		

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void audioReceived(float * input, int bufferSize, int nChannels);

		float * left;
		float * right;
		int 	bufferCounter;
		int 	drawCounter;


        int      format;
        int      channels;
        int      sampleRate;
        int      sndBuffSize;
        int      sndBuffPos;
        char   * outfilename;
        SNDFILE * outfile;
        SF_INFO    info;

	
		
};

