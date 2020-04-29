#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include "Review.h"
#include "Digital.h"
#include "Dvd.h"
#include "Cd.h"
#include "Database.h"

using namespace std;

// READ ME -----------------------------------------------------------------
// The idea of this class is to avoid the previous super class LIBRARY. It is 
// focused on the opearations over Media objects.
// TEST IF AN 
// -------------------------------------------------------------------------

class MediaController {
private:
	vector<Media*> medias;
	Database db;
public: 
	// Constructors
	MediaController();
	MediaController(string filename);

	//Destructors:
	~MediaController();

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
	void search_by_string(); // searches by a string
};

#endif