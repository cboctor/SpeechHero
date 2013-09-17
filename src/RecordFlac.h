#pragma once

#include "ofMain.h"
#include <sndfile.h>
#include <curl/curl.h>
#include "ofxJSONElement.h"
#include "MyThread.h"



class RecordFlac
{
public:
		
		void start();
		void stop();
		void postFLAC();
		void jSONSetup();
		void clearBuffer();
		
		void audioReceived(float * input, int bufferSize, int nChannels);

		float * left;
		float * right;
		int 	bufferCounter;
		int 	drawCounter;
		string recState;
		void setState(string state);
		string getState();
		string getResult();

        int      format;
        int      channels;
        int      sampleRate;
        int      sndBuffSize;
        int      sndBuffPos;
        char   * outfilename;
        SNDFILE * outfile;
        SF_INFO    info;

		string readBuffer;
		ofxJSONElement result;

		MyThread thread1;

	
		
};

