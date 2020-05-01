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
	vector<Media*> get_medias();
	string get_db_filename(){return this->db.get_filename();}


	//setters
	void set_db_filename(string filename){this->db.set_filename(filename);}
	void set_medias(vector<Media*> medias){this->medias = medias;}
	Media* media_from_string(string media_string);

	// other functions
	void clear_search(); // this functions clears the vector search_indexes
	void load_media(); // loads media from the file using the Database db
	void write_media(); // writes media to file using Database db
	void add_media(Media* media); // adds a media;
	void delete_by_id(); // delete a Media* from medias by its id 
	void search_by_id(); // searches a Media* by its id
	bool search_by_string(string character_sequence); // searches by generic string
};

#endif