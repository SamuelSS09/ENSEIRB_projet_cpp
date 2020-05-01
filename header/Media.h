#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;


// READ ME -----------------------------------------------------------------

// This is an ABSTRACT CLASS, and as such cannot be instantiated
// This is seem from the pure virtual function to_string
// -------------------------------------------------------------------------


class Media{
protected: // can be accesed by the child classes
	static unsigned nextID;// counter for the unique id

private:

	unsigned id;
	string title;
	string author;

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
	void set_id(unsigned id){this->id=id;}
	void set_author(string author){this->author=author;}
	void set_title(string title){this->title=title;}

	//Other functions
	virtual string to_string() = 0; //pure virtual function => Abstract Class
	void init(unsigned id, string title,string author);

};

#endif
