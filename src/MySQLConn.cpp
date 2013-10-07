#include "MySQLConn.h"
#include "ofMain.h"





void MySQLConn::setup(){
	connectDb();
	createUserTable();
	

}

void MySQLConn::createUserTable()
{
	string queryString = "CREATE TABLE IF NOT EXISTS user (";
	queryString +="user_ID INT AUTO_INCREMENT NOT NULL," ;
	queryString +="username varchar(200) NOT NULL,";
	queryString +="password varchar(200) NOT NULL,";
	queryString += "firstname TEXT,";
	queryString += "lastname TEXT,";
	queryString += "type varchar(10),";
	queryString +="boundeduser varchar(200) NOT NULL,";
	queryString += "PRIMARY KEY (user_ID)) ";
	query(queryString);

}

string MySQLConn::getUser(string user)
{

		string queryString = "SELECT username FROM user";
	queryString += " WHERE username = '" +user+ "'";
	query(queryString);
	if (res->next())
		return res->getString ("username");
	else
		return "Username not found";

}

string MySQLConn::getPassword(string user)
{

		string queryString = "SELECT username, password FROM user";
	queryString += " WHERE username = '" +user+ "'";
	query(queryString);
	if (res->next())
		return res->getString ("password");
	else
		return "Password not found";

}

string MySQLConn::getType(string user)
{
	string queryString = "SELECT username, type FROM user";
	queryString += " WHERE username = '" +user+ "'";
	query(queryString);
	if (res->next())
		return res->getString ("type");
	else
		return "Type not found";

}

string MySQLConn::getBoundedUser(string user)
{
	string queryString = "SELECT username, boundeduser FROM user";
	queryString += " WHERE username = '" +user+ "'";
	query(queryString);
	if (res->next())
		return res->getString ("boundeduser");
	else
		return "Bounded User not found";


}

bool MySQLConn::authenticateUser(string user, string pass)
{
	string dbuser;
	string dbpass;
	string queryString = "SELECT username, password FROM user";
	queryString += " WHERE username = '" +user+ "'";
	cout<<queryString;
	query(queryString);
	
//	{

	//while (res->next())
	//{
	if (res->next())
	{
	cout<<res->getString("username")<<endl;
	dbuser = res->getString("username");
	dbpass = res->getString("password");
	
	cout<<res->getString("password");
	}
	if (dbuser ==user && dbpass== pass)
		return true;
	else
		return false;
	//}

//	}
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
		  res = stmt->executeQuery(queryString);
		  delete stmt;

	}	
	catch (sql::SQLException &e) {
		exceptionMsg(e);
	}
}

void MySQLConn::execute(string queryString)
{
	try
	{
		  //stmt = con->createStatement();
		  stmt->execute(queryString);
		  delete stmt;

	}	
	catch (sql::SQLException &e) {
		exceptionMsg(e);
	}
}

void MySQLConn::createUser(string username, string password, string firstname, string lastname, string type, string boundeduser)
{
	string queryString = "INSERT INTO user (username, password, firstname, lastname, type, boundeduser)";
	queryString += " VALUES ('"+username+"','"+password+"','"+firstname+"','"+lastname+"','"+type+"','"+boundeduser+"');";
	query(queryString);
	//execute(queryString);
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

	con->~Connection();
	

	
}