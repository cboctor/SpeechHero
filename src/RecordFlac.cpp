#include "RecordFlac.h"
#include "ofMain.h"


void RecordFlac::setup(){
	

}


//--------------------------------------------------------------
void RecordFlac::update(){

}


//--------------------------------------------------------------

void RecordFlac::start(){

	
	left = new float[256];
	right = new float[256];


	bufferCounter = 0;
	drawCounter = 0;


    sampleRate = 16000;
	ofSoundStreamSetup(0,2, sampleRate, 256, 4);

    info.format=SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    info.frames = sampleRate*60;
    info.samplerate = sampleRate;
    info.channels = 2;
    outfile = sf_open ("data/mysounddata.wav", SFM_WRITE, &info) ;

    if (!outfile)
        {
            cerr<<"Error opening ["<<outfilename<<"] : "<<sf_strerror (outfile)<<endl;
        }


}

void RecordFlac::audioReceived 	(float * input, int bufferSize, int nChannels){
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];
		right[i] = input[i*2+1];
	}
	bufferCounter++;

	sf_write_float(outfile, input, bufferSize*2);

}


//--------------------------------------------------------------
void RecordFlac::stop(){
	sf_close(outfile);
}

//--------------------------------------------------------------

void RecordFlac::draw(){


	
}



//--------------------------------------------------------------
void RecordFlac::keyPressed(int key){

}

//--------------------------------------------------------------
void RecordFlac::keyReleased(int key){

}

//--------------------------------------------------------------
void RecordFlac::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void RecordFlac::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void RecordFlac::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void RecordFlac::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void RecordFlac::windowResized(int w, int h){

}

//--------------------------------------------------------------
void RecordFlac::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void RecordFlac::dragEvent(ofDragInfo dragInfo){ 

}

void RecordFlac::exit()
{
	
}