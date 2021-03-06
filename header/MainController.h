#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "Interface.h"
#include "Library.h"
#include "UserController.h"

using namespace std;

class MainController {
private:
	Interface myInterface;
	Library myLibrary;
	UserController myUc;
	User activeUser;

	//helper functions
	void load_filename();
	void load_my_database(string filename, string uc_filename);
public:
	//Constructor
	//MainController();
	MainController(string data_filename, string uc_filename);

	//other functions
	User login();
	void start_login();
	void start_program();

};
#endif
