#include "testApp.h"
#include "Interfaces.h"



static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
//--------------------------------------------------------------

void testApp::postFLAC()
{
  CURL *curl;
  CURLcode res;
  
//  mfile.open ("data/myjson.json");
  curl = curl_easy_init();
  if(curl) {
	           curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
 
         // Headers
         // Disable "Expect: 100-continue"
       //  headers = curl_slist_append(headers, "Expect:");
		 struct curl_slist *headers=NULL;  headers = curl_slist_append(headers, "Content-Type: audio/x-flac; rate=16000");
         curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
 
         // POST
         curl_easy_setopt(curl, CURLOPT_HTTPPOST, 1);
 
         curl_httppost* post_start = 0;
         curl_httppost* post_end = 0;
 
         // Upload File
         curl_formadd(&post_start, &post_end,
             CURLFORM_COPYNAME, "fileupload",
             CURLFORM_FILE, "data/audio.flac",
             CURLFORM_END);
 
         
 
         curl_easy_setopt(curl, CURLOPT_HTTPPOST, post_start);
    curl_easy_setopt(curl, CURLOPT_URL,
             "http://www.google.com/speech-api/v1/recognize?xjerr=1&client=chromium&lang=en-AU");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
        // Cleanup
         curl_easy_cleanup(curl);
         curl_formfree(post_start);
         curl_slist_free_all(headers);

  //  std::cout << readBuffer << std::endl;
  }
  curl_global_cleanup();
 // cout<< "this is" + readBuffer + "readBuffer";
 // mfile <<readBuffer;
 // mfile.close();
  
}

void testApp::jSONSetup(){
//	  std::string file = "myjson.json";
	
	// Now parse the JSON
	//bool parsingSuccessful = result.open(file);
	bool parsingSuccessful = result.parse(readBuffer);
	
    if (parsingSuccessful) {
		cout << result.getRawString() << endl;
        
        // now write pretty print
        if(!result.save("example_output_pretty.json",true)) {
            cout << "example_output_pretty.json written unsuccessfully." << endl;
        } else {
            cout << "example_output_pretty.json written successfully." << endl;
        }
        
        // now write without pretty print
        if(!result.save("example_output_fast.json",false)) {
            cout << "example_output_pretty.json written unsuccessfully." << endl;
        } else {
            cout << "example_output_pretty.json written successfully." << endl;
        }
		
	} else {
		cout  << "Failed to parse JSON" << endl;
	}
}
//--------------------------------------------------------------

void testApp::setup(){
	ofBackground(50,50,50);
	pixfont.loadFont("pix.ttf", 32);
	spacecount=0;
	mainWindow.setup();
}


//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){

	//jSONSetup();
//pixfont.drawString(readBuffer, 100,100);
	if (mainWindow.getState()=="practice")
	{
std::stringstream ss;
    
    ss << "confidence   = " << result["hypotheses"][0]["confidence"].asDouble() << endl;
    ss << "utterance = " << result["hypotheses"][0]["utterance"].asString() << endl;
	

    ofDrawBitmapString(ss.str(), 200, 200);
}
	 
	/*if (mainWindow.getRecordingState()=="start")
	{
		rec.start();
		mainWindow.setRecordingState("recording");
	}
	if (mainWindow.getRecordingState()=="stop")
	{
		rec.stop();
		mainWindow.setRecordingState("stopped");
	}*/

	
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if (key == 's')
	{
		

	}
	

	if (key=='d')
	{
		
	}

	if (key ==32) //Spacebar pressed
	{
		if (mainWindow.getView()=="practice")
		{
			spacecount++;
			if (!(spacecount%2==0))
			{
				readBuffer.clear();
				mfile.clear();
				rec.start();
			}
			else
			{
				rec.stop();
				postFLAC();
				jSONSetup();
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