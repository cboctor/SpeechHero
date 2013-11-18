#include "MySQLConn.h"
#include "ofMain.h"





void MySQLConn::setup(){
	connectDb();
	createUserTable();
	createWordTable();
	createHighScoresTable();
	

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

void MySQLConn::createHighScoresTable()
{
	string queryString = "CREATE TABLE IF NOT EXISTS highscores (";
	queryString +="username varchar(200) NOT NULL,";
	queryString +="score int,";
	queryString += "correct int,";
	queryString += "incorrect int,";
	queryString += "multiplier int)";
	query(queryString);

}

void MySQLConn::createWordTable()
{
		string queryString = "CREATE TABLE IF NOT EXISTS words (";
	queryString +="username varchar(200) NOT NULL,";
	queryString += "b_initial varchar(10) DEFAULT false,";
	queryString += "b_medial varchar(10) DEFAULT false,";
	queryString += "b_final varchar(10) DEFAULT false,";
	queryString += "ch_initial varchar(10) DEFAULT false,";
	queryString += "ch_medial varchar(10) DEFAULT false,";
	queryString += "ch_final varchar(10) DEFAULT false,";
	queryString += "d_initial varchar(10) DEFAULT false,";
	queryString += "d_medial varchar(10) DEFAULT false,";
	queryString += "d_final varchar(10) DEFAULT false,";
	queryString += "f_initial varchar(10) DEFAULT false,";
	queryString += "f_medial varchar(10) DEFAULT false,";
	queryString += "f_final varchar(10) DEFAULT false,";
	queryString += "g_initial varchar(10) DEFAULT false,";
	queryString += "g_medial varchar(10) DEFAULT false,";
	queryString += "g_final varchar(10) DEFAULT false,";
	queryString += "h_initial varchar(10) DEFAULT false,";
	queryString += "j_initial varchar(10) DEFAULT false,";
	queryString += "j_medial varchar(10) DEFAULT false,";
	queryString += "j_final varchar(10) DEFAULT false,";
	queryString += "k_initial varchar(10) DEFAULT false,";
	queryString += "k_medial varchar(10) DEFAULT false,";
	queryString += "k_final varchar(10) DEFAULT false,";
	queryString += "l_initial varchar(10) DEFAULT false,";
	queryString += "l_medial varchar(10) DEFAULT false,";
	queryString += "l_final varchar(10) DEFAULT false,";
	queryString += "m_initial varchar(10) DEFAULT false,";
	queryString += "m_medial varchar(10) DEFAULT false,";
	queryString += "m_final varchar(10) DEFAULT false,";
	queryString += "n_initial varchar(10) DEFAULT false,";
	queryString += "n_medial varchar(10) DEFAULT false,";
	queryString += "n_final varchar(10) DEFAULT false,";
	queryString += "ng_initial varchar(10) DEFAULT false,";
	queryString += "p_initial varchar(10) DEFAULT false,";
	queryString += "p_medial varchar(10) DEFAULT false,";
	queryString += "p_final varchar(10) DEFAULT false,";
	queryString += "r_initial varchar(10) DEFAULT false,";
	queryString += "r_medial varchar(10) DEFAULT false,";
	queryString += "r_final varchar(10) DEFAULT false,";
	queryString += "s_initial varchar(10) DEFAULT false,";
	queryString += "s_medial varchar(10) DEFAULT false,";
	queryString += "s_final varchar(10) DEFAULT false,";
	queryString += "sh_initial varchar(10) DEFAULT false,";
	queryString += "sh_medial varchar(10) DEFAULT false,";
	queryString += "sh_final varchar(10) DEFAULT false,";
	queryString += "t_initial varchar(10) DEFAULT false,";
	queryString += "t_medial varchar(10) DEFAULT false,";
	queryString += "t_final varchar(10) DEFAULT false,";
	queryString += "th_initial varchar(10) DEFAULT false,";
	queryString += "th_medial varchar(10) DEFAULT false,";
	queryString += "th_final varchar(10) DEFAULT false,";
	queryString += "v_initial varchar(10) DEFAULT false,";
	queryString += "v_medial varchar(10) DEFAULT false,";
	queryString += "v_final varchar(10) DEFAULT false,";
	queryString += "w_initial varchar(10) DEFAULT false,";
	queryString += "y_initial varchar(10) DEFAULT false,";
	queryString += "z_initial varchar(10) DEFAULT false,";
	queryString += "z_medial varchar(10) DEFAULT false,";
	queryString += "z_final varchar(10) DEFAULT false,";
	queryString += "PRIMARY KEY (username)) ";
	

	try
	{
		  stmt = con->createStatement();
		  res = stmt->executeQuery(queryString);
		  delete stmt;

	}	
	catch (sql::SQLException &e) {
		exceptionMsg(e);
		cout<<" failed";
	}

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

void MySQLConn::setSettings(string user)
{
	string queryString = "SELECT";
	queryString += " b_initial," ;
queryString += " b_medial," ;
queryString += " b_final," ;
queryString += " ch_initial," ;
queryString += " ch_medial," ;
queryString += " ch_final," ;
queryString += " d_initial," ;
queryString += " d_medial," ;
queryString += " d_final," ;
queryString += " f_initial," ;
queryString += " f_medial," ;
queryString += " f_final," ;
queryString += " g_initial," ;
queryString += " g_medial," ;
queryString += " g_final," ;
queryString += " h_initial," ;
queryString += " j_initial," ;
queryString += " j_medial," ;
queryString += " j_final," ;
queryString += " k_initial," ;
queryString += " k_medial," ;
queryString += " k_final," ;
queryString += " l_initial," ;
queryString += " l_medial," ;
queryString += " l_final," ;
queryString += " m_initial," ;
queryString += " m_medial," ;
queryString += " m_final," ;
queryString += " n_initial," ;
queryString += " n_medial," ;
queryString += " n_final," ;
queryString += " ng_initial," ;
queryString += " p_initial," ;
queryString += " p_medial," ;
queryString += " p_final," ;
queryString += " r_initial," ;
queryString += " r_medial," ;
queryString += " r_final," ;
queryString += " s_initial," ;
queryString += " s_medial," ;
queryString += " s_final," ;
queryString += " sh_initial," ;
queryString += " sh_medial," ;
queryString += " sh_final," ;
queryString += " t_initial," ;
queryString += " t_medial," ;
queryString += " t_final," ;
queryString += " th_initial," ;
queryString += " th_medial," ;
queryString += " th_final," ;
queryString += " v_initial," ;
queryString += " v_medial," ;
queryString += " v_final," ;
queryString += " w_initial," ;
queryString += " y_initial," ;
queryString += " z_initial," ;
queryString += " z_medial," ;
queryString += " z_final " ;
queryString += "FROM words";
queryString += " WHERE username = '" +user+ "'";
	query(queryString);

		if (res->next())
	{
		 b_initial = res->getBoolean("b_initial");
		 b_medial = res->getBoolean("b_medial");
		 b_final = res->getBoolean("b_final");
		 ch_initial = res->getBoolean("ch_initial");
		 ch_medial = res->getBoolean("ch_medial");
		 ch_final = res->getBoolean("ch_final");
		 d_initial = res->getBoolean("d_initial");
		 d_medial = res->getBoolean("d_medial");
		 d_final = res->getBoolean("d_final");
		 f_initial = res->getBoolean("f_initial");
		 f_medial = res->getBoolean("f_medial");
		 f_final = res->getBoolean("f_final");
		 g_initial = res->getBoolean("g_initial");
		 g_medial = res->getBoolean("g_medial");
		 g_final = res->getBoolean("g_final");
		 h_initial = res->getBoolean("h_initial");
		 j_initial = res->getBoolean("j_initial");
		 j_medial = res->getBoolean("j_medial");
		 j_final = res->getBoolean("j_final");
		 k_initial = res->getBoolean("k_initial");
		 k_medial = res->getBoolean("k_medial");
		 k_final = res->getBoolean("k_final");
		 l_initial = res->getBoolean("l_initial");
		 l_medial = res->getBoolean("l_medial");
		 l_final = res->getBoolean("l_final");
		 m_initial = res->getBoolean("m_initial");
		 m_medial = res->getBoolean("m_medial");
		 m_final = res->getBoolean("m_final");
		 n_initial = res->getBoolean("n_initial");
		 n_medial = res->getBoolean("n_medial");
		 n_final = res->getBoolean("n_final");
		 ng_initial = res->getBoolean("ng_initial");
		 p_initial = res->getBoolean("p_initial");
		 p_medial = res->getBoolean("p_medial");
		 p_final = res->getBoolean("p_final");
		 r_initial = res->getBoolean("r_initial");
		 r_medial = res->getBoolean("r_medial");
		 r_final = res->getBoolean("r_final");
		 s_initial = res->getBoolean("s_initial");
		 s_medial = res->getBoolean("s_medial");
		 s_final = res->getBoolean("s_final");
		 sh_initial = res->getBoolean("sh_initial");
		 sh_medial = res->getBoolean("sh_medial");
		 sh_final = res->getBoolean("sh_final");
		 t_initial = res->getBoolean("t_initial");
		 t_medial = res->getBoolean("t_medial");
		 t_final = res->getBoolean("t_final");
		 th_initial = res->getBoolean("th_initial");
		 th_medial = res->getBoolean("th_medial");
		 th_final = res->getBoolean("th_final");
		 v_initial = res->getBoolean("v_initial");
		 v_medial = res->getBoolean("v_medial");
		 v_final = res->getBoolean("v_final");
		 w_initial = res->getBoolean("w_initial");
		 y_initial = res->getBoolean("y_initial");
		 z_initial = res->getBoolean("z_initial");
		 z_medial = res->getBoolean("z_medial");
		 z_final = res->getBoolean("z_final");
	
	
	}
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

void MySQLConn::addScore(string username, int score, int correct, int incorrect, int multiplier)
{
	string queryString = "INSERT INTO highscores (username, score, correct, incorrect, multiplier)";
	queryString += " VALUES ('"+username+ "','" + ofToString(score,1)+"','"+ ofToString(correct,1)+"','"+ofToString(incorrect,1)+"','"+ ofToString(multiplier,1)+"');";
	query(queryString);
}

string MySQLConn::getHighScores()
{
	string queryString = "SELECT * FROM highscores ORDER BY score DESC";
	//queryString += " WHERE username = '" +user+ "'";
	query(queryString);
	string highscores;
	highscores = " USERNAME  \t  SCORE  \t  CORRECT  \t  INCORRECT  \t MULTIPLIER  \n";
	string usernames = "USERNAME \n";
	string score = "SCORE \n";
	string correct = "CORRECT \n";
	string incorrect = "INCORRECT \n";
	string multiplier = "MULTIPLIER \n";

	for (int i =0 ; i<10; i++)
	{
		if (res->next())
		{
			usernames += res->getString("username")+"\n";
			score += res->getString("score") + "\n";
			correct += res->getString("correct") + "\n";
			incorrect += res->getString("incorrect") + "\n";
			multiplier += res->getString("multiplier") + "\n";
		}
	}

	GlobalData::highscoresTable = highscores;
	GlobalData::hscorrect = correct;
	GlobalData::hsmultiplier = multiplier;
	GlobalData::hsscore = score;
	GlobalData::hsincorrect = incorrect;
	GlobalData::hsmultiplier = multiplier;
	GlobalData::hsusername = usernames;
	return highscores;
	//highscoresTable = highscores;
	//if (res->next())
		//return res->getString ("type");
	//else
		//return "Type not found";

}


void MySQLConn::setupSettings(string username)
{
	string queryString = "INSERT INTO words (username)";
	queryString += " VALUES ('"+username+"');";
	query(queryString);

}

void MySQLConn::updateSettings(string username, string _queryString)
{
	string queryString = "UPDATE words ";
	queryString += "SET " + _queryString;
	queryString += "WHERE username = '" + username + "';";
	query(queryString);
	cout<<queryString;
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