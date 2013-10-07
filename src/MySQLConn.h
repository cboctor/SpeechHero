#pragma once

#include "ofMain.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>



class MySQLConn
{
public:
		void setup();
		void update();
		void draw();
		void exit();
		void start();
		void stop();
		void createUser(string username, string password, string firstname, string lastname, string type, string boundeduser);
		void createUserTable();
		bool authenticateUser(string user, string password);
		string getUser(string user);
		string getPassword(string user);
		string getType(string user);
		string getBoundedUser(string user);
		
		

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		
		void exceptionMsg(sql::SQLException &e);
		void connectDb();
		void query(string queryString);
		void execute(string queryString);

	

	
		
};

