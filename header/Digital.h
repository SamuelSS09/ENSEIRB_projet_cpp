#ifndef DIGITAL_H
#define DIGITAL_H

#include "Media.h"
using namespace std;

// READ ME -----------------------------------------------------------------
// -------------------------------------------------------------------------

class Digital : public Media {
private:
	string extension; // the extentions are many and
					 // can change overtime, so we set it as a string

	int size;		// in kB

	string path;	// usually a url

public:
	//Constructors
	Digital();
	Digital(string title,string author,int size, string extension,string path);	
	Digital(std::vector<string> attributs); 
	// Destructors
	// Class does not have pointers, so no memory leak
	// is likely. Therefore, no need to change the default
	// destructor.

	//Getters
	string get_extension(){return this->extension;}
	int get_size(){return this->size;}
	string get_path(){return this->path;}

	//Setters
	void set_extension(string extension){this->extension=extension;}
	void set_size(int size){this->size=size;}
	void set_path(string path){this->path=path;}
	void init(int size,string extension,string path);
	//Other functions
	virtual string to_string();
	virtual void show_info(bool detailed);
	virtual void set_info();
};

#endif
