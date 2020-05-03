#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <vector>
#include <helper.h>
#include "Library.h"

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
	string get_string_from_user(); // function to obtain a single line inserted
								  // by the user in string format

	int get_int_from_user();	 // used to obtain a single line insertd by the user
								 // in integer format.

public:
	//Constructor
	Interface();

	//other functions
	vector<string> get_user_command();
	void list_media(std::vector<Media*> medias);
	Media* media_from_input(string media_type); // launches option to add info about 
										  // new media to be added


	void goodbye();// prints goodbye message
	void hello(); // prints hello message;
	void print_error_db(); // prints error message while opening db
	void print_reset(); // prints message after RESET is called

	//Destructor

	//getters

	//setters

	void add_possible_options(string option);

};

#endif