#include "testApp.h"
#include "Interfaces.h"



//--------------------------------------------------------------

void testApp::setup(){
	ofBackground(0,76,153);
	ofSetWindowPosition((ofGetScreenWidth() - ofGetWindowWidth())/2, (ofGetScreenHeight() - ofGetWindowHeight())/2);
	pixfont.loadFont("pix.ttf", 32);
	spacecount=0;
	mainWindow.setup();
	word="";
	startTime=ofGetElapsedTimeMillis();
	wordStartTime = ofGetElapsedTimeMillis();
	currentWordStart =ofGetElapsedTimeMillis();
	isReady = false;
	

	
	
}


//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//jSONSetup();
//pixfont.drawString(readBuffer, 100,100);
	if (mainWindow.getView()=="practice")
	{
	
	string resultWord = rec.getResult();
	pixfont.drawString(resultWord, ((ofGetWindowWidth() - resultWord.size()) / 2), ofGetWindowHeight()/2);
    ofDrawBitmapString(resultWord, 200, 200);
	ofDrawBitmapString(word, 200, 500);
	if (resultWord == word)
		ofDrawBitmapString("Correct", 200, 550);
	else
		ofDrawBitmapString("Incorrect", 200,550);

	}

	if (mainWindow.getView() == "game")
	{
		pixfont.drawString(word, 50 , 50);
		time = (ofGetElapsedTimeMillis() - startTime) / 1000;
		wordTime = (ofGetElapsedTimeMillis() - wordStartTime) / 1000;
		currentWordTime = (ofGetElapsedTimeMillis() - currentWordStart) /1000;

		if (wordTime >= 10)
		{

			loadWords();

			wordStartTime = ofGetElapsedTimeMillis();
			currentWordStart = ofGetElapsedTimeMillis();
			
			
		}
		
		string s = "Time: " + ofToString(time,1) + "\n";
		s+= "Word Time: "+ ofToString(wordTime,1) + "\n";
		s+= "CTime: " + ofToString(currentWordTime,1);
		pixfont.drawString(s ,ofGetWidth() - 200, 50);
		if (currentWordTime >=5)
		{
			//currentWordStart = ofGetElapsedTimeMillis();
			isReady = true;
		}
		else
			isReady = false;

		if (isReady == true)
		{
			
		 ofEnableAlphaBlending();    // turn on alpha blending
		 ofSetColor(0,0,0,50);  
		ofRect( 0, 0.4 * ofGetHeight(), 0 ,ofGetWidth() , 0.2* ofGetHeight());
		}


	}
	 

	
}

void testApp::loadWords()
{
	ifstream myfile ("data/words/b/b-initial.word");
	
		copy(istream_iterator<string>(myfile),
         istream_iterator<string>(),
         back_inserter(wordArray));
		int randnum = std::rand() % wordArray.size();

		 word = wordArray[randnum];
		 cout<<word;
}




//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if (key == 's')
	{
		

	}
	

	if (key==358)
	{
		loadWords();
	}

	if (key ==32) //Spacebar pressed
	{
		if (mainWindow.getView()=="practice")
		{
			spacecount++;
			if (!(spacecount%2==0))
			{
				rec.clearBuffer();
				mfile.clear();
				rec.start();
			}
			else
			{
				rec.stop();
				rec.postFLAC();
				rec.jSONSetup();
			}
	}
	}

	cout<<key;
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