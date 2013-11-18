#include "testApp.h"



ofPoint p1;
ofPoint charpos;
int keycount;


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
	GlobalData::wordsCorrect = 0;
	GlobalData::wordsIncorrect = 0;
	GlobalData::scoreMultiplier = 0;
	floorImage.loadImage("assets/ground.png");
	floorpoint.x = 0;
	floorpoint.y = ofGetHeight() - floorImage.getHeight();
	worldBounds.set(-100, 0 , ofGetWidth()+500, floorpoint.y);
	
	GlobalData::box2dworld.init();
	GlobalData::box2dworld.setFPS(60);
	GlobalData::box2dworld.setGravity(0, 10);
	//GlobalData::box2dworld.createGround(-200, floorpoint.y, ofGetWidth() + 200,floorpoint.y);
	GlobalData::box2dworld.createBounds(worldBounds);
	GlobalData::box2dworld.registerGrabbing();
	isStarted = false;

	ofSetFrameRate(60);
	characterImage.loadImage("assets/char.png");
	backgroundImage.loadImage("assets/trees.png");
	
	
	 c.setPhysics(1, 0.1, 1);
     c.setup(GlobalData::box2dworld.getWorld(), 500, 500, 30);
	 circlepos = c.getPosition();
	 keypressed = "nothing";
	desiredVel =0 ;
	isMidAir = false;
	col.r = 0;
	col.g = 0;
	col.b = 128;
	counter = 0;
	backgroundSet.setup("assets/background.atlas", "assets/background.json", 1.0);
	//dragon.setup("assets/dragon.atlas", "assets/dragon.json", 0.3);
	dragon.createDragon();
	player.setup();
	skull.createSkulls();
	//monster.setup();

	
	p1.x = -50;
	p1.y = 250;
	//dragon.setPosition(p1);
	backgroundSet.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
	//AnimationStateData_setMixByName(skeleton.getStateData(), "walk", "jump", 0.2f);
	//AnimationStateData_setMixByName(skeleton.getStateData(), "jump", "walk", 0.4f);

	/*AnimationState_setAnimationByName(dragon.getState(), "fly", true);*/
	AnimationState_setAnimationByName(backgroundSet.getState(), "animation", true);



	GlobalData::healthPercent = 1.0;
	GlobalData::itemIndex = 0;
	GlobalData::score = 0;
	GlobalData::scoreMultiplier = 1;
	rawScore = 0;
	hud.setup();
	GlobalData::isRecording = false;


}



//--------------------------------------------------------------
void testApp::update(){
	ofBackground(col);
	mainWindow.update();

	if (mainWindow.getView() == "game")
	{
	player.update();
	skull.update();
	item.update();
	monster.update();
	dragon.update();
	GlobalData::box2dworld.update();
	hud.update();

	if (GlobalData::healthPercent <=0)
	{
		mainWindow.setUIGameOver();
		mainWindow.setView("gameover");
		
	}
	}
	backgroundSet.update(0.01f/60);

}


//--------------------------------------------------------------
void testApp::draw(){
		backgroundSet.draw();

		if (mainWindow.getView() != "game")
		{
			ofSetColor(0,0,0,80);  
			ofRect(0,0,0,ofGetWidth(),ofGetHeight());
		}

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

	if(mainWindow.getView() == "highscores")
	{
		ofSetColor(255,255,255);
		ofTrueTypeFont font;
		font.loadFont("GUI/font.ttf", 14);
		font.drawString(GlobalData::hsusername, 270, 45);
		font.drawString(GlobalData::hsscore, 420, 45);
		font.drawString(GlobalData::hscorrect, 570, 45);
		font.drawString(GlobalData::hsincorrect, 720, 45);
		font.drawString(GlobalData::hsmultiplier, 870, 45);

	}

	if (mainWindow.getView() == "game")
	{
		if (isStarted)
		{
			startTime=ofGetElapsedTimeMillis();
			//scoreStartTime = ofGetElapsedTimeMillis();
			hud.setup();
			
			dragon.createDragon();
			skull.createSkulls();
			wordRecordStartTime = ofGetElapsedTimeMillis();
			wordStopStartTime = ofGetElapsedTimeMillis();
			displayStartTime = ofGetElapsedTimeMillis();
			spawnMonsterStartTime = ofGetElapsedTimeMillis();
			isStarted =false;
		}
	
		backgroundImage.draw(0, floorpoint.y - backgroundImage.getHeight()+10);
		floorImage.draw(floorpoint.x,floorpoint.y);
		
		dragon.draw();
		
		skull.draw();
		spawnMonster();

		player.draw();
		//for (int i=0; i < monsters.size(); i++)
		//	monsters[i].draw();
		monster.draw();
		item.draw();
		//GlobalData::box2dworld.getWorld()->DrawDebugData();
		loadHUD();
		hud.draw();


	}

	mainWindow.draw();

	//if (mainWindow.getView() == "sessions")
	//	mainWindow.setUISession();

}



void testApp::spawnMonster()
{

	
	spawnMonsterTime = ofGetElapsedTimeMillis() - spawnMonsterStartTime;
	if (spawnMonsterTime >=5500)
	{
		//monsters.clear();
		spawnMonsterStartTime = ofGetElapsedTimeMillis();
		monster.createMonster();
		
		
		
	}



}


void testApp::loadHUD()
{
	resultWord = thread.getResult();
	pixfont.drawString(resultWord, 50, 100);
	time = (ofGetElapsedTimeMillis() - startTime) / 1000;
	wordRecordTime = (ofGetElapsedTimeMillis() - wordRecordStartTime) / 1000;
	wordStopTime = (ofGetElapsedTimeMillis() - wordStopStartTime) /1000;
	displayTime = (ofGetElapsedTimeMillis() - displayStartTime) /1000;
	

	const double NEXTWORD_TIME = 25;

	if (displayTime >= NEXTWORD_TIME)
	{
		 
		
		checkCorrect();
		displayStartTime = ofGetElapsedTimeMillis();
		wordRecordStartTime = ofGetElapsedTimeMillis();
		wordStopStartTime = ofGetElapsedTimeMillis();
	
		selectRandomWord();
		thread.clearResult();
		recordingState.clear();
	}

	if (displayTime >=15 && displayTime <=NEXTWORD_TIME)
		isWordReady = true;
	else
		isWordReady = false;

	if (wordRecordTime >=15)
	{
		recordingState = "Recording";
		cout<<"recording started";
		startRecording();
		wordRecordStartTime = ofGetElapsedTimeMillis();
	}

	if (wordStopTime >=18)
	{
		recordingState = "Checking word matches..";
		stopRecording(); 
		cout<<"recording stopped";
		wordStopStartTime = ofGetElapsedTimeMillis();
	}

	string s = "Multiplier: x" + ofToString(GlobalData::scoreMultiplier,1) + "    ";
	s+= "Correct: " + ofToString(GlobalData::wordsCorrect,1) + "    ";
	s+="Incorrect: " + ofToString(GlobalData::wordsIncorrect,1) + "    ";
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
			recordingState = "Correct";
			ofEnableAlphaBlending();    // turn on alpha blending
			ofSetColor(0,255,0,50);  
			ofRect( 0, 0.4 * ofGetHeight(), 0 ,ofGetWidth() , 0.2* ofGetHeight());
			
		}
		else if (!resultWord.empty())
		{
			recordingState = "Incorrect";
			ofEnableAlphaBlending();    // turn on alpha blending
			ofSetColor(255,0,0,50);  
			ofRect( 0, 0.4 * ofGetHeight(), 0 ,ofGetWidth() , 0.2* ofGetHeight());

		}
		ofEnableAlphaBlending();    // turn on alpha blending
		ofSetColor(0,0,0,50);  
		ofRect( 0, 0.4 * ofGetHeight(), 0 ,ofGetWidth() , 0.2* ofGetHeight());

		ofSetColor(255,255,255);
		bigPixfont.drawString(word, (ofGetWidth() - 30) /2, ofGetHeight()/2);
		pixfont.drawString(recordingState, 15, ofGetHeight() * 0.4 + 50);
		wordRecordStartTime = ofGetElapsedTimeMillis();
	}
	//else
	//	thread.clearResult();
}

void testApp::checkCorrect()
{
	if (resultWord == word)
			{
				GlobalData::wordsCorrect ++;
				copyFile("correct");
				correctwords.push_back(word);
				item.createItem();
				rawScore += 1000;
			}
		else
			{
				GlobalData::wordsIncorrect++;
				copyFile("incorrect");
				incorrectwords.push_back(word);
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

	if (key == 's')
	{
		skull.keyPressed(key);

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

void testApp::audioIn 	(float * input, int bufferSize, int nChannels){

	rec.audioReceived(input,bufferSize,nChannels);
}


void testApp::exit()
{
	player.getSkeleton().~ofxSkeleton();
	//dragon.~ofxSkeleton();
	//skull.exit();
	mainWindow.exit();
}