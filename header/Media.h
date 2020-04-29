#ifndef MEDIA_H
#define MEDIA_H

#include <string>
using namespace std;

// READ ME -----------------------------------------------------------------

// This is an ABSTRACT CLASS, and as such cannot be instantiated
// This is seem from the pure virtual function to_string
// -------------------------------------------------------------------------

class Media{
private:

	string name;
	string title;
	string author;
	string id;

public:
	//Constructors
	Media();
	Media(string name,string title,string author);


	// Destructors
	// This class is abstract, so we want to call the destructors of its childs.
	// That is why we need a virtual destructor, so it can be overriden by its childs destructors
	// more info :https://stackoverflow.com/questions/1123044/when-should-your-destructor-be-virtual
	virtual ~Media(){}

	//Getters
	string get_name(){return this->name;}
	string get_title(){return this->title;}
	string get_author(){return this->author;}

	//Setters
	void set_author(string author){this->author=author;}
	void set_title(string title){this->title=title;}
	void set_name(string name){this->name=name;}

	//Other functions
	virtual string to_string() = 0; // Pure virtual function
};

#endif