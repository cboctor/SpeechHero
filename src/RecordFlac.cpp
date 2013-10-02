#include "RecordFlac.h"
#include "ofMain.h"
#include <thread>





//--------------------------------------------------------------

void RecordFlac::start(){

	try{
		left = new float[256];
		right = new float[256];

		bufferCounter = 0;
		drawCounter = 0;

		sampleRate = 16000;
		ofSoundStreamSetup(0,2, sampleRate, 256, 4);


		info.format=SF_FORMAT_FLAC | SF_FORMAT_PCM_16;
		info.frames = sampleRate*60;
		info.samplerate = sampleRate;
		info.channels = 2;

		outfile = sf_open ("data/audio.flac", SFM_WRITE, &info) ;

		if (!outfile)
		{
			cerr<<"Error opening ["<<outfilename<<"] : "<<sf_strerror (outfile)<<endl;
		}
	} catch(...)
	{cout<<"could not output";}
}



void RecordFlac::audioReceived 	(float * input, int bufferSize, int nChannels){
	// samples are "interleaved"
	try{
		for (int i = 0; i < bufferSize; i++){
			left[i] = input[i*2];
			right[i] = input[i*2+1];
		}
		bufferCounter++;

		sf_write_float(outfile, input, bufferSize*2);}
	catch(...)
	{cout<<"could not output";}

}


//--------------------------------------------------------------
void RecordFlac::stop(){
	try{
	if (!outfile)
	{
		cerr<<"Error opening ["<<outfilename<<"] : "<<sf_strerror (outfile)<<endl;
	}
	else {

		
		ofSoundStreamClose();
		sf_close(outfile);
	}
	}catch(...)
	{cout<<"could not output";}


}



static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
//--------------------------------------------------------------

void RecordFlac::postFLAC()
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

void RecordFlac::jSONSetup(){
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


string RecordFlac::getResult()
{
	return result["hypotheses"][0]["utterance"].asString();
}

void RecordFlac::clearBuffer()
{
	readBuffer.clear();
}