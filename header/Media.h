#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;


// READ ME -----------------------------------------------------------------
// UNIQUE ID:
// the unique id is implemented using the static variable nextID, which is shared
// accros every instance of the object and its childs.
// If we construct an object, this variable is incremented. In case we conctruct
// it from a file, we make sure that if any of the found IDs are greater than 
// the nextID, we change its value so it can start couting from the greatest id found
// and therefore avoid duplicate IDs. We also make sure to decrement the variable
// when an instance of the class is destroyed.

// This is an ABSTRACT CLASS, and as such cannot be instantiated
// This is seem from the pure virtual function to_string

//

// -------------------------------------------------------------------------


class Media{
protected: // can be accesed by the child classes

private:
	static unsigned nextID;// counter for the unique id
	unsigned id;
	string title;
	string author;

	void set_id(unsigned id){this->id=id;}



public:
	//Constructors
	Media();
	Media(string title,string author);
	Media(vector<string> attributs); //used to construct from file
	
	// Destructors
	// This class is abstract, so we want to call the destructors of its childs.
	// That is why we need a virtual destructor, so it can be overriden by its childs destructors
	// more info :https://stackoverflow.com/questions/1123044/when-should-your-destructor-be-virtual
	
	virtual ~Media();

	//Getters
	unsigned get_id(){return this->id;}
	string get_title(){return this->title;}
	string get_author(){return this->author;}

	//Setters
	void set_author(string author){this->author=author;}
	void set_title(string title){this->title=title;}

	//Other functions
	virtual string to_string() = 0; //pure virtual function => Abstract Class
	void init(unsigned id, string title,string author);

};

#endif
