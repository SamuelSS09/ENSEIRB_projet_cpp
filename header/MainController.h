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
	UserController Users;

	//helper functions
	void load_filename();
	void load_my_database(string filename, string users_filename);
public:
	//Constructor
	//MainController();
	MainController(string data_filename, string users_filename);

	//other functions
	void start_program();

};
#endif
