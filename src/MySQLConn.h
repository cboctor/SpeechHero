#pragma once

#include "ofMain.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


extern bool b_initial;
extern bool b_medial;
extern bool b_final;
extern bool ch_initial;
extern bool ch_medial;
extern bool ch_final;
extern bool d_initial;
extern bool d_medial;
extern bool d_final;
extern bool f_initial;
extern bool f_medial;
extern bool f_final;
extern bool g_initial;
extern bool g_medial;
extern bool g_final;
extern bool h_initial;
extern bool j_initial;
extern bool j_medial;
extern bool j_final;
extern bool k_initial;
extern bool k_medial;
extern bool k_final;
extern bool l_initial;
extern bool l_medial;
extern bool l_final;
extern bool m_initial;
extern bool m_medial;
extern bool m_final;
extern bool n_initial;
extern bool n_medial;
extern bool n_final;
extern bool ng_initial;
extern bool p_initial;
extern bool p_medial;
extern bool p_final;
extern bool r_initial;
extern bool r_medial;
extern bool r_final;
extern bool s_initial;
extern bool s_medial;
extern bool s_final;
extern bool sh_initial;
extern bool sh_medial;
extern bool sh_final;
extern bool t_initial;
extern bool t_medial;
extern bool t_final;
extern bool th_initial;
extern bool th_medial;
extern bool th_final;
extern bool v_initial;
extern bool v_medial;
extern bool v_final;
extern bool w_initial;
extern bool y_initial;
extern bool z_initial;
extern bool z_medial;
extern bool z_final;

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
		void setupSettings(string username);
		void createUserTable();
		void createWordTable();
		bool authenticateUser(string user, string password);
		string getUser(string user);
		string getPassword(string user);
		string getType(string user);
		string getBoundedUser(string user);

		void setSettings(string user);
		void updateSettings(string user, string _queryString);
		
		

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

