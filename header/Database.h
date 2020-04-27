#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>

//should include all classes from the root of the inheritance tree
#include "Review.h"
#include "Cd.h"
#include "Dvd.h"

// READ ME -----------------------------------------------------------------
	// This class has been conceived to read a database in which each file 
	// contains a table of a type of media.
// -------------------------------------------------------------------------

class Database {

private: 
	string filename;
	// fstream fileManager;

public: 
	//Constructors
	Database(){};
	Database(string filename){this->set_filename(filename);}

	//getters
	string get_filename(){return this->filename;}

	//setters
	void set_filename(string filename){this->filename=filename;}

	//other functions
	vector<Media*> read_media_database();

	void write_database();

	bool check_file(); // TRUE if file is open successfully. FALSE otherwise

};

#endif