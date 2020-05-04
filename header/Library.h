#ifndef LIBRARY_H
#define LIBRARY_H

#include "Review.h"
#include "Digital.h"
#include "Dvd.h"
#include "Cd.h"
#include "Database.h"
#include <algorithm>

#include "helper.h"
using namespace std;

// READ ME -----------------------------------------------------------------
// Library v1.0 - MODEL CLASS
// This class is responsible for handling operations in media. It is a MODEL
// class, and as such it implements logic and deals with media objects.

// NOT YET DONE:
// 1- what should we do in the CATCH condition of the destructor, i.e, when it
// does not succed to write media to a file.
// -------------------------------------------------------------------------

class Library {
private:
	vector<Media*> medias;		// holds the media

	bool previousSearch;		// holds if there was a previous search
	// vector<int> search_indexes; // in case of a SEARCH, this vector contains
	// 							// which are the indexes of the elements in the
	// 							// first vector that satisfies the criteria of the
	// 							// search

	Database db;
public:
	// Constructors
	Library(){};			 	// default constructor. SHOULD NOT BE USED BY ITSELF
	Library(string filename);

	//Destructors:

	~Library(); // we must write all the media into the file before closing the
				// application. Its is done in this destructor.
				// As we deal with a vector of pointers, it is necessary to delete
				// its elements to avoid memory leak. This is also done in this destructor.

	//getters
	vector<Media*> get_medias();
	string get_db_filename(){return this->db.get_filename();}


	//setters
	// not all attributs of this class should have a setter
	void set_db_filename(string filename){this->db.set_filename(filename);}



	// other functions
	void clear_medias(); // we must always clear the search vector
											  // when setting a new media vector;


	void clear_search(); // this functions clears the vector search_indexes
	void load_media();  // loads media from the file using the Database db
	void write_media(); // writes media to file using Database db
	void add_media(Media* media); // adds a media;
	void delete_by_id(int media_id); // delete a Media* from medias by its id
	void search_by_id(); // searches a Media* by its id
	bool search_by_string(string character_sequence); // searches by generic string

	Media* media_from_string(string media_string); // constructs a Media pointer from a formated string
												   // this function is used when reading file.
};

#endif
