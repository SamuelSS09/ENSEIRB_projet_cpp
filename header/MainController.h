#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "Interface.h"
#include "Library.h"

using namespace std;

class MainController {
private:
	Interface myInterface;
	Library myLibrary;

	//helper functions
	void load_filename();
	void load_my_database(string filename);
public:
	//Constructor
	MainController();
	MainController(string filename);
	//other functions
	void start_program();

};
#endif