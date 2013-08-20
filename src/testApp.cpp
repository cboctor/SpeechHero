#include "testApp.h"
#include "Interfaces.h"



//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(50,50,50);
	pixfont.loadFont("pix.ttf", 32);

	mainWindow.setup();
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){


	
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if (key == 's')
		rec.start();

	if (key=='d')
		rec.stop();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::audioReceived 	(float * input, int bufferSize, int nChannels){
	
	rec.audioReceived(input,bufferSize,nChannels);
}



void testApp::exit()
{
	mainWindow.exit();
}