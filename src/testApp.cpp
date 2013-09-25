#include "testApp.h"
#include "Interfaces.h"


//--------------------------------------------------------------

void testApp::setup(){
	ofBackground(0,0,0);
	ofSetWindowPosition((ofGetScreenWidth() - ofGetWindowWidth())/2, (ofGetScreenHeight() - ofGetWindowHeight())/2);
	pixfont.loadFont("pix.ttf", 32);
	bigPixfont.loadFont("pix.ttf", 55);
	spacecount=0;
	mainWindow.setup();
	word="";
	startTime=ofGetElapsedTimeMillis();
	wordRecordStartTime = ofGetElapsedTimeMillis();
	wordStopStartTime = ofGetElapsedTimeMillis();
	displayStartTime = ofGetElapsedTimeMillis();
	isWordReady = false;
	isNow = false;
	loadWords();
	selectRandomWord();
	wordsCorrect = 0;
	wordsIncorrect = 0;
	scoreMultiplier = 0;
	floorImage.loadImage("assets/ground.png");
	floorpoint.x = 0;
	floorpoint.y = ofGetHeight() - floorImage.getHeight();
	worldBounds.set(0, 0 , ofGetWidth(), floorpoint.y);
	box2dworld.init();
	box2dworld.setFPS(60);
	box2dworld.setGravity(0, 10);
	box2dworld.createBounds(worldBounds);
	box2dworld.registerGrabbing();
	ofSetFrameRate(60);
	characterImage.loadImage("assets/char.png");
	backgroundImage.loadImage("assets/trees.png");
	
	
	 c.setPhysics(1, 0.1, 1);
     c.setup(box2dworld.getWorld(), 500, 500, 30);
	 circlepos = c.getPosition();
	 keypressed = "nothing";
	desiredVel =0 ;
	isMidAir = false;
	last = ofGetElapsedTimeMillis();
	col.setHsb(0,255,255);
	counter = 0;


}


//--------------------------------------------------------------
void testApp::update(){
	ofBackground(col);
	if (ofGetElapsedTimeMillis()-last > 2000)
	{
		col.setHue(counter%256);
		counter++;
	}
	box2dworld.update();
	circlepos = c.getPosition();
	b2Vec2 vel = c.body->GetLinearVelocity();

	if (keypressed == "key-left" && !isMidAir)
		vel.x = -10;
	else if (keypressed == "key-right" && !isMidAir)
		vel.x = 10;
	else if (keypressed == "key-up" && !isMidAir)
		vel.y = 100;
	else if (keypressed =="released")
		vel.x*= 0.98;


	c.body->SetLinearVelocity(vel);

	if ( c.body->GetLinearVelocity().y != 0 ) {
    isMidAir = true;
	} else { 
    isMidAir = false;
	}
}


//--------------------------------------------------------------
void testApp::draw(){


	if (mainWindow.getView()=="practice")
	{

		string resultWord = thread.getResult();
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
		
		backgroundImage.draw(0, floorpoint.y - backgroundImage.getHeight()+10);
		floorImage.draw(floorpoint.x,floorpoint.y);
		characterImage.draw(circlepos.x-30,circlepos.y-84);

		loadHUD();


	}



}

void testApp::loadHUD()
{
	string resultWord = thread.getResult();
	pixfont.drawString(word, 50 , 50);
	pixfont.drawString(resultWord, 50, 100);
	time = (ofGetElapsedTimeMillis() - startTime) / 1000;
	wordRecordTime = (ofGetElapsedTimeMillis() - wordRecordStartTime) / 1000;
	wordStopTime = (ofGetElapsedTimeMillis() - wordStopStartTime) /1000;
	displayTime = (ofGetElapsedTimeMillis() - displayStartTime) /1000;

	const double NEXTWORD_TIME = 25;

	if (displayTime >= NEXTWORD_TIME)
	{
		if (resultWord == word)
			wordsCorrect ++;
		else
			wordsIncorrect++;

		displayStartTime = ofGetElapsedTimeMillis();
		wordRecordStartTime = ofGetElapsedTimeMillis();
		wordStopStartTime = ofGetElapsedTimeMillis();
		word = " ";
		resultWord = " ";
		selectRandomWord();
	}

	if (displayTime >=15 && displayTime <=NEXTWORD_TIME)
		isWordReady = true;
	else
		isWordReady = false;

	if (wordRecordTime >=15)
	{
		cout<<"recording started";
		startRecording();
		wordRecordStartTime = ofGetElapsedTimeMillis();
	}

	if (wordStopTime >=18)
	{
		stopRecording(); 
		cout<<"recording stopped";
		wordStopStartTime = ofGetElapsedTimeMillis();
	}

	string s = "Multiplier: x" + ofToString(scoreMultiplier,1) + "    ";
	s+= "Correct: " + ofToString(wordsCorrect,1) + "    ";
	s+="Incorrect: " + ofToString(wordsIncorrect,1) + "    ";
	string s1 ="Time: " + ofToString(time,1);


	string nextword;

	double nextwordRecordTime = NEXTWORD_TIME - displayTime;
	nextword = "Next Word: " + word;
	nextword += " in " + ofToString(nextwordRecordTime,1);

	pixfont.drawString(s1 ,ofGetWidth() - 150, 50);
	pixfont.drawString(s ,50, ofGetHeight() -50);
	pixfont.drawString(nextword, (ofGetWidth() - 200) /2, 50);

	if (isWordReady == true)
	{

		if (resultWord == word)
		{

			ofEnableAlphaBlending();    // turn on alpha blending
			ofSetColor(0,255,0,50);  
			ofRect( 0, 0.4 * ofGetHeight(), 0 ,ofGetWidth() , 0.2* ofGetHeight());
			
		}
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

	if (key == OF_KEY_UP)
	{
		keypressed = "key-up";
	}

	if (key == OF_KEY_RIGHT)
	{
		keypressed = "key-right";
	//	b2Vec2 vel = c.body->GetLinearVelocity();
	//	vel.x = b2Min(vel.x + 1.0f, 10.0f);
	//	c.body->SetLinearVelocity(vel);
	}

	if (key == OF_KEY_LEFT)
	{
		keypressed = "key-left";
	//	b2Vec2 vel = c.body->GetLinearVelocity();
	//	vel.x= b2Max( vel.x - 0.5f, -10.0f );
	//	c.body->SetLinearVelocity(vel);
	}


	if (key=='n')
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
				startRecording();
			}
			else
			{
				stopRecording();
			}
		}
	}

	cout<<key;
}



void testApp::keyReleased(int key){
	keypressed = "released";

}

void testApp::startRecording()
{
	thread.clearBuffer();
	thread.stop();
	rec.start();

}

void testApp::stopRecording()
{
	rec.stop();
	thread.start();
	
	//rec.postFLAC();
	//rec.jSONSetup();

}
//--------------------------------------------------------------


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