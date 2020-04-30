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
public:
	//Constructor
	MainController();
	MainController(string filename);
	//other functions
	void start_program();

};
#endif