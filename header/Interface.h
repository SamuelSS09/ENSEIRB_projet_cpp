#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <vector>
#include <helper.h>

using namespace std;
// using std::cout;
// using std::cin;
// using std::vector;
// using std::string;

// READ ME -----------------------------------------------------------------
// -------------------------------------------------------------------------

class Interface {

private:
	vector<string> possible_options; // possible user choices. Each option in 
								     // this vector has the format
									 // (OPTION,N), where n is the number of arguments
									 // it requires


	//helper functions
	bool validate_option(vector<string> optionSplit);
	string get_user_input();

public:
	//Constructor
	Interface();

	//other functions
	vector<string> get_user_command();


	//Destructor

	//getters

	//setters
	void add_possible_options(string option);

};

#endif