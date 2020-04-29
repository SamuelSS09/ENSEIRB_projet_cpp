#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include "Media.h"
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
	MediaController(){}
	MediaController(string filename);

	//Destructors:
	~MediaController();

	//getters
	vector<Media*> get_medias(){return this->medias;}

	//setters
	void set_db_filename(string filename){this->db.set_filename(filename);}
	void set_medias(vector<Media*> medias){this->medias = medias;}

	//other functions
	void load_media();
	void write_media();
	void delete_by_id();
	void search_by_id();
	void search_by_char(); // searches by a string
};

#endif