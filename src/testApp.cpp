#include "testApp.h"
#define PI 3.14159265

ofPoint p1;
ofPoint charpos;
int keycount;
ofxBox2d box2dworld;



//--------------------------------------------------------------

void testApp::setup(){
	//ofBackground(0,0,0);
	ofSetWindowPosition((ofGetScreenWidth() - ofGetWindowWidth())/2, (ofGetScreenHeight() - ofGetWindowHeight())/2);
	pixfont.loadFont("pix.ttf", 32);
	bigPixfont.loadFont("pix.ttf", 55);
	spacecount=0;
	mainWindow.setup();
	word="";
	
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
	worldBounds.set(-500, 0 , ofGetWidth()+1000, floorpoint.y);
	box2dworld.init();
	box2dworld.setFPS(60);
	box2dworld.setGravity(0, 10);
	box2dworld.createBounds(worldBounds);
	box2dworld.registerGrabbing();
	isStarted = false;

	ofSetFrameRate(60);
	characterImage.loadImage("assets/char.png");
	backgroundImage.loadImage("assets/trees.png");
	
	monsterCount = 0;
	 c.setPhysics(1, 0.1, 1);
     c.setup(box2dworld.getWorld(), 500, 500, 30);
	 circlepos = c.getPosition();
	 keypressed = "nothing";
	desiredVel =0 ;
	isMidAir = false;
	col.r = 0;
	col.g = 0;
	col.b = 128;
	counter = 0;
	
	dragon.setup("assets/dragon.atlas", "assets/dragon.json", 0.3);
	player.setup();
	//skull.setup();
	//monster.setup();

	
	p1.x = -50;
	p1.y = 250;
	dragon.setPosition(p1);
	//AnimationStateData_setMixByName(skeleton.getStateData(), "walk", "jump", 0.2f);
	//AnimationStateData_setMixByName(skeleton.getStateData(), "jump", "walk", 0.4f);

	AnimationState_setAnimationByName(dragon.getState(), "fly", true);


	


}




//--------------------------------------------------------------
void testApp::update(){
	ofBackground(col);
	mainWindow.update();
	player.update();
	//skull.update();
	
	for (int i=0; i < monsterCount; i++)
		monsters[i].update();
	dragon.update(1.0f/60);
	charpos.x = circlepos.x -30;
	charpos.y = circlepos.y+28;
	p1.x+=5;
	 if (p1.x >= ofGetWidth() + 200)
		 p1.x = -150;
	dragon.setPosition(p1);

//	if (ofGetElapsedTimeMillis()-last > 2000)
//	{
//		double bluechange =  abs(128* sin(counter * PI /180));
//		double brightness = 100 * abs (sin (counter * PI/180));
//		double saturation = 100/ brightness;

//		col.setBrightness(brightness);
//		counter++;

//	}
	box2dworld.update();

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
		if (isStarted)
		{
			startTime=ofGetElapsedTimeMillis();
			wordRecordStartTime = ofGetElapsedTimeMillis();
			wordStopStartTime = ofGetElapsedTimeMillis();
			displayStartTime = ofGetElapsedTimeMillis();
			spawnMonsterStartTime = ofGetElapsedTimeMillis();
			isStarted =false;
		}
		backgroundImage.draw(0, floorpoint.y - backgroundImage.getHeight()+10);
		floorImage.draw(floorpoint.x,floorpoint.y);
		dragon.draw();
		player.draw();
		//skull.draw();
		spawnMonster();
		for (int i=0; i < monsterCount; i++)
			monsters[i].draw();

		box2dworld.getWorld()->DrawDebugData();
		loadHUD();


	}

	mainWindow.draw();

	//if (mainWindow.getView() == "sessions")
	//	mainWindow.setUISession();

}


void testApp::spawnMonster()
{
	spawnMonsterTime = ofGetElapsedTimeMillis() - spawnMonsterStartTime;
	if (spawnMonsterTime >=3000)
	{

		monsters[monsterCount].setup();
		monsterCount ++;
		cout << endl<< "Monsters: " + monsterCount << endl;
		if (monsterCount >=50)
			monsterCount = 0;
		spawnMonsterStartTime = ofGetElapsedTimeMillis();
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
			{
				wordsCorrect ++;
				copyFile("correct");
				correctwords.push_back(word);
			}
		else
			{
				wordsIncorrect++;
				copyFile("incorrect");
				incorrectwords.push_back(word);
			}

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
	player.keyPressed(key);
	skull.keyPressed(key);

	if (key == 's')
	{


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
	player.keyReleased(key);

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
	//mkdir ("data/
	
	

}
//--------------------------------------------------------------


void testApp::copyFile(string status)
{
	
	string srcdest = "data/audio.flac";
	string dst = "user/" + mainWindow.getUser() + "/" + mainWindow.getSessionID() + "/"+ status+ "/" + status + ".df";
	string dstpath = "data/user/" + mainWindow.getUser() + "/" + mainWindow.getSessionID() + "/"+ status+ "/" + word+ ".flac";
	ofFile newFile(ofToDataPath(dst), ofFile::WriteOnly);
	newFile.create();
	CopyFileA(srcdest.c_str(), dstpath.c_str(), false);
	
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
	player.getSkeleton().~ofxSkeleton();
	dragon.~ofxSkeleton();
	skull.exit();
	mainWindow.exit();
}