#include "testApp.h"
#include "Interfaces.h"





//--------------------------------------------------------------

void testApp::setup(){
	ofBackground(0,76,153);
	ofSetWindowPosition((ofGetScreenWidth() - ofGetWindowWidth())/2, (ofGetScreenHeight() - ofGetWindowHeight())/2);
	pixfont.loadFont("pix.ttf", 32);
	bigPixfont.loadFont("pix.ttf", 55);
	spacecount=0;
	mainWindow.setup();
	word="";
	startTime=ofGetElapsedTimeMillis();
	wordStartTime = ofGetElapsedTimeMillis();
	isWordReady = false;
	loadWords();
	selectRandomWord();
	wordsCorrect = 0;
	wordsIncorrect = 0;
	scoreMultiplier = 0;
	
	

	
	
}


//--------------------------------------------------------------
void testApp::update(){
	
}


//--------------------------------------------------------------
void testApp::draw(){
	


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
		loadHUD();


	}
	 

	
}

void testApp::loadHUD()
{
	pixfont.drawString(word, 50 , 50);
		time = (ofGetElapsedTimeMillis() - startTime) / 1000;
		wordTime = (ofGetElapsedTimeMillis() - wordStartTime) / 1000;

		

		if (wordTime > 10 && wordTime < 15)
			isWordReady = true;
		else
			isWordReady = false;
		

		 if (wordTime >= 15)
			{
			wordStartTime = ofGetElapsedTimeMillis();
			selectRandomWord();
		}
		
		string s = "Multiplier: x" + ofToString(scoreMultiplier,1) + "    ";
		s+= "Correct: " + ofToString(wordsCorrect,1) + "    ";
		s+="Incorrect: " + ofToString(wordsIncorrect,1) + "    ";
		string s1 ="Time: " + ofToString(time,1);
		

		string nextword;
		const double NEXTWORD_TIME = 15;
		double nextwordTime = NEXTWORD_TIME - wordTime;
		nextword = "Next Word: " + word;
		nextword += " in " + ofToString(nextwordTime,1);

		pixfont.drawString(s1 ,ofGetWidth() - 150, 50);
		pixfont.drawString(s ,50, ofGetHeight() -50);
		pixfont.drawString(nextword, (ofGetWidth() - 200) /2, 50);

		if (isWordReady == true)
		{
			
		 ofEnableAlphaBlending();    // turn on alpha blending
		 ofSetColor(0,0,0,50);  
		ofRect( 0, 0.4 * ofGetHeight(), 0 ,ofGetWidth() , 0.2* ofGetHeight());
		
		ofSetColor(255,255,255);
		bigPixfont.drawString(word, (ofGetWidth() - 30) /2, ofGetHeight()/2);

		}
}

void testApp::loadWords()
{
	ifstream myfile ("data/words/b/b-initial.word");
	
		copy(istream_iterator<string>(myfile),
         istream_iterator<string>(),
         back_inserter(wordArray));
		
}

void testApp::selectRandomWord()
{
	int randnum = std::rand() % wordArray.size();

		 word = wordArray[randnum];
		 cout << wordArray.size();
		 cout<<word;
		  
}




//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if (key == 's')
	{
		

	}
	

	if (key==358)
	{
		selectRandomWord();
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