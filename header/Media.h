#ifndef MEDIA_H
#define MEDIA_H

#include <string>
using namespace std;

// Read me of the class
// Explain its role

class Media{
private:

	string name;
	string title;
	string author;

public:
	//Constructors
	Media();
	Media(string name,string title,string author);

	// Destructors
	// Class does not have pointers, so no memory leak
	// is likely. Therefore, no need to change the default
	// destructor.

	//Getters
	string get_name(){return this->name;}
	string get_title(){return this->title;}
	string get_author(){return this->author;}

	//Setters
	void set_author(string author){this->author=author;}
	void set_title(string title){this->title=title;}
	void set_name(string name){this->name=name;}

	//Other functions
	virtual string to_string();
};

#endif