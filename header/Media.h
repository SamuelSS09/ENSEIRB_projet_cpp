#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>
#include <sstream>

#include <iostream> // violation of the MVC, only here for the sake of simplicity.

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

// -------------------------------------------------------------------------


class Media{

protected: // can be accesed by the child classes
	static unsigned nextID;// counter for the unique id
	short class_index;     // unique id for the class type.



	unsigned id;
	string title;
	string author;

	bool isSearched; //this bollean tells if this media belongs to the current
					 // list of searched elements


	void set_id(unsigned id){this->id=id;}
	void init(unsigned id, string title,string author);

	//Violation of the MVC, only here for the sake of simplicity.
	string get_string_from_user(); // function to obtain a single line inserted
								   // by the user in string format

	int get_int_from_user();	   // used to obtain a single line insertd by the user
								   // in integer format.


public:
	//Constructors
	Media();
	Media(string title,string author);
	Media(vector<string> attributs); // used to construct from file or from interface.
	
	// Destructors
	// This class is abstract, so we want to call the destructors of its childs.
	// That is why we need a virtual destructor, so it can be overriden by its childs destructors
	// more info :https://stackoverflow.com/questions/1123044/when-should-your-destructor-be-virtual
	
	virtual ~Media();

	//Getters
	unsigned get_id(){return this->id;}
	string get_title(){return this->title;}
	string get_author(){return this->author;}
	bool is_searched(){return this->isSearched;}

	//Setters
	void set_author(string author){this->author=author;}
	void set_title(string title){this->title=title;}
	void set_searched(bool isSearched){this->isSearched=isSearched;}

	virtual void show_basic_info(){}

	//Other functions
	virtual string to_string() = 0; //pure virtual function => Abstract Class

	virtual string get_search_string();

	//NT: showing and constructing functions. Idally this should be in a interface,
	//but the code is simple enough to allow us to do it here

	virtual void show_info(bool detailed); // shows info. if detailed=true, shows
										   // all the info of the class

	virtual void set_info();				// allows class to gather information
											// from the user to construct itself.
														
	//NT2: A MVC solution: make a class Info which holds a map. This class would then update
	// the map with the info it need to gather or show. The interface would then read this map
	// and translate ir to the user. This would more flexible for changes in the interface.
};

#endif
