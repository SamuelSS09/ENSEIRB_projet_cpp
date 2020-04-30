#ifndef DVD_H
#define DVD_H

#include "Vhs.h"

// READ ME -----------------------------------------------------------------
// -------------------------------------------------------------------------

using namespace std;

class Dvd : public Vhs{
private:
	int tracksNumber;

public:
	//Constructors
	Dvd();
	Dvd(unsigned id,string title,string author,int length,string producer,int tracksNumber);
	Dvd(std::vector<string> attributs);
	// Destructors
	// Class does not have pointers, so no memory leak
	// is likely. Therefore, no need to change the default
	// destructor.

	//Getters
	int get_tracks_number(){return this->tracksNumber;}
	//Setters
	void set_tracks_number(int tracksNumber){this->tracksNumber=tracksNumber;}
	//Other functions
	string to_string();
};

#endif
