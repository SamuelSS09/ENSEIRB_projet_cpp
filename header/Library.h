#ifndef LIBRARY_H
#define LIBRARY_H

#include "Review.h"
#include "Digital.h"
#include "Dvd.h"
#include "Cd.h"
#include "Database.h"


#include "helper.h"
using namespace std;

// READ ME -----------------------------------------------------------------
// The idea of this class is to avoid the previous super class LIBRARY. It is 
// focused on the opearations over Media objects.
// TEST IF AN 
// -------------------------------------------------------------------------

class Library {
private:
	vector<Media*> medias;
	vector<int> search_indexes; // in case of a SEARCH, this vector contains 
								// which are the indexes of the elements in the 
								// first vector that satisfies the criteria of the
								// search  
	Database db;
public: 
	// Constructors
	Library(){};
	Library(string filename);

	//Destructors:
	~Library();

	//getters
	vector<Media*> get_medias(){return this->medias;}

	//setters
	void set_db_filename(string filename){this->db.set_filename(filename);}
	void set_medias(vector<Media*> medias){this->medias = medias;}
	Media* media_from_string(string media_string);


	//other functions
	void load_media();
	void write_media();
	void delete_by_id();
	void search_by_id();
	bool search_by_string(string character_sequence); // searches by a string
};

#endif