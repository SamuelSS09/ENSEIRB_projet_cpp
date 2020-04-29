#ifndef VHS_H
#define VHS_H

#include "Media.h"
using namespace std;

// READ ME -----------------------------------------------------------------
// -------------------------------------------------------------------------


class Vhs : public Media{
private:
	int length; //in minutes
	string producer;

public:
	//Constructors
	Vhs();
	Vhs(unsigned id,string title,string author,int length,string producer);

	// Destructors
	// Class does not have pointers, so no memory leak
	// is likely. Therefore, no need to change the default
	// destructor.

	//Getters
	int get_length(){return this->length;}
	string get_producer(){return this->producer;}

	//Setters
	void set_length(int length){this->length=length;}
	void set_producer(string producer){this->producer=producer;}

	//Other functions
	string to_string();
};

#endif
