#ifndef _THREADED_OBJECT
#define _THREADED_OBJECT

#include "ofMain.h"
//#include "RecordFlac.h"
#include "ofxJSONElement.h"

// this is not a very exciting example yet
// but ofThread provides the basis for ofNetwork and other
// operations that require threading.
//
// please be careful - threading problems are notoriously hard
// to debug and working with threads can be quite difficult


class MyThread : public ofThread{

	public:


	    int count;  // threaded fucntions that share data need to use lock (mutex)
	                // and unlock in order to write to that data
	                // otherwise it's possible to get crashes.
	                //
	                // also no opengl specific stuff will work in a thread...
	                // threads can't create textures, or draw stuff on the screen
	                // since opengl is single thread safe

		string readBuffer;
		ofxJSONElement result;

	   

		//--------------------------
		MyThread(){
			count = 0;
		}

		void start(){
            startThread(true, false);   // blocking, verbose
        }

        void stop(){
            stopThread();
        }

		//--------------------------
		 void threadedFunction() {
 
        // start
 
        while(isThreadRunning()) {
 
           
           
 
                // lock access to the resource
                lock();
 
                // load the image
				postFLAC();
				jSONSetup();
                
                // done with the resource
                unlock();
				stop();
              
        }
 
        // done
    }
 
 


		//--------------------------
		void draw(){

			string str = "I am a slowly increasing thread. \nmy current count is: ";

			if( lock() ){
				str += ofToString(count);
				unlock();
			}else{
				str = "can't lock!\neither an error\nor the thread has stopped";
			}
			ofDrawBitmapString(str, 50, 56);
		}

		static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
//--------------------------------------------------------------

void postFLAC()
{

  CURL *curl;
  CURLcode res;
  
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

  
}

void jSONSetup(){
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


string getResult()
{
	return result["hypotheses"][0]["utterance"].asString();
}

void clearBuffer()
{
	readBuffer.clear();
}

		



};

#endif
