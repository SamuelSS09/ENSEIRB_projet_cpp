#ifndef CD_H
#define CD_H

#include "Vhs.h"

using namespace std;

// READ ME -----------------------------------------------------------------
// -------------------------------------------------------------------------


class Cd : public Vhs{
private:
	int tracksNumber;

public:
	//Constructors
	Cd();
	Cd(string title,string author,int length,string producer,int tracksNumber);
	Cd(std::vector<string> attributs);
	// Destructors
	// Class does not have pointers, so no memory leak
	// is likely. Therefore, no need to change the default
	// destructor.

	//Getters
	int get_tracks_number(){return this->tracksNumber;}
	//Setters
	void set_tracks_number(int tracksNumber){this->tracksNumber=tracksNumber;}
	//Other functions
	virtual string to_string();
	virtual void show_info(bool detailed);
	virtual void set_info();
};

#endif
