#include "MySQLConn.h"
#include "ofMain.h"





void MySQLConn::setup(){
	

}

void MySQLConn::exceptionMsg(sql::SQLException &e)
{
	cout << "# ERR: SQLException in " << __FILE__;
	cout << "(" << __FUNCTION__ << ") on line  » "    << __LINE__ << endl;
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

void MySQLConn::connectDb()
{
	try
	{
	 /* Create a connection */
	 driver = get_driver_instance();
	 con = driver->connect("tcp://sql2.freesqldatabase.com:3306", "sql217337", "hQ6%cW5*");
	 /* Connect to the MySQL test database */
	con->setSchema("sql217337");

	}
	catch (sql::SQLException &e) {
	exceptionMsg(e);
	}
}

void MySQLConn::query(string queryString)
{
	try
	{
		  stmt = con->createStatement();
		  stmt->executeQuery(queryString);

	}	
	catch (sql::SQLException &e) {
		exceptionMsg(e);
	}
}


//--------------------------------------------------------------
void MySQLConn::update(){

}



//--------------------------------------------------------------

void MySQLConn::draw(){


	
}



//--------------------------------------------------------------
void MySQLConn::keyPressed(int key){

}

//--------------------------------------------------------------
void MySQLConn::keyReleased(int key){

}

//--------------------------------------------------------------
void MySQLConn::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void MySQLConn::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void MySQLConn::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void MySQLConn::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void MySQLConn::windowResized(int w, int h){

}

//--------------------------------------------------------------
void MySQLConn::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void MySQLConn::dragEvent(ofDragInfo dragInfo){ 

}

void MySQLConn::exit()
{
	
}