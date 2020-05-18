#include "Library.h"
#include "helper.h"
#include <iostream>

char char_delimiter = ',';

Library::Library(string filename){
	this->db.set_filename(filename);
	this->previousSearch=false;
}


Library::Library(){
	this->previousSearch=false;
}

Library::~Library(){

	// try to write media vector to a file
	vector<string> medias_string;

	for (long unsigned int i=0;i<this->medias.size();i++){

		//populate a vector of strings, each entry with a media in
		// in string format
		medias_string.push_back(this->medias.at(i)->to_string());

		//free memory
 		delete this->medias.at(i);
 	}
	this->medias.clear();


	//try to write the media vector to a file

	try{
		this->db.write_database(medias_string);
		// cout << "Library: j'appelle mon destructeur, tout va bien!" << endl;
	}catch(...){
		//
	}

}

void Library::clear_medias(){

	// clear memory allocation
	for(long unsigned int i=0 ; i < this->medias.size() ; i++){
		delete this->medias.at(i);
	}

	this->medias.clear();

}


vector<Media*> Library::get_medias(){ //
	//this->myMediaInterface.show_header();

	if(!previousSearch){ // if there was no previous search
		return this->medias;
	}

	else{ // if there was a previous search
		vector<Media*> medias_filtered;
		for(long unsigned int i = 0; i < medias.size() ; i++){
			if(this->medias.at(i)->is_searched()){
				//add only medias whose isSearch attribut is true
				medias_filtered.push_back(this->medias.at(i));

			}
		}
		return medias_filtered;
	}
}

void Library::load_media(){
   vector<string> media_string = this->db.read_database();
   for(long unsigned int i = 0; i < media_string.size(); i++){
   	//OBS1: should not create duplicated Media.
      this->medias.push_back(this->media_from_string(media_string.at(i)));
   }

}

void Library::write_media(){
	std::vector<string> lines;
	for(long unsigned int i = 0; i < this->medias.size() ; i++){

		lines.push_back(medias.at(i)->to_string());
	}
	this->db.write_database(lines);
}

bool Library::delete_by_id(int media_id){
	bool isFound = false;
	for(long unsigned int i=0; i < this->medias.size(); i++){
		if (medias.at(i)->get_id() == media_id){
			this->medias.erase(medias.begin()+i);
			isFound=true;
		}
	}
	return isFound;
}

bool Library::show_media_by_id(int media_id){

	bool isFound = false;

	for(long unsigned int i=0; i < this->medias.size(); i++){
		if (medias.at(i)->get_id() == media_id){
			// this->medias.at(i)->set_searched(true);
			isFound = true;
			this->medias.at(i)->show_info(true); // show detailed info
		}
	}
	return isFound;
}

bool Library::search_by_string(string character_sequence){


	bool isFound = false; // check if the search was sucessfull;

	//this function has a different behavioral for each state of this->previosSearch

	if(!this->previousSearch){ //CASE OF NO PREVIOUS SEARCH
		for(long unsigned int i = 0; i < this->medias.size(); i++){ // iterate through the media vector

			string mediaString = medias.at(i)->get_search_string();

			if(character_sequence.size() < mediaString.size() ){ //char_seq must be smaller than mediaString

	    		if(mediaString.find(character_sequence) != std::string::npos){ // check if we have a substring
	    			this->medias.at(i)->set_searched(true);
	    			isFound = true; // the search found a matchr
	    			this->previousSearch=true; // we now have made a search
	    		}
			}
		}
	}

	else{ // CASE THERE WAS A PREVIOUS A SEARCH

		for(long unsigned int i = 0; i < this->medias.size(); i++){ // iterate through indexes vector

			if(this->medias.at(i)->is_searched()){// we should only check the medias which have already been searched

				string mediaString = medias.at(i)->get_search_string();

				if(character_sequence.size() < mediaString.size() ){ //char_seq must be smaller than mediaString

		    		if(mediaString.find(character_sequence) != std::string::npos){ // check if we have a substring
		    			this->medias.at(i)->set_searched(true);
		    			isFound = true; // the search found a match
					}

					else{ //make the search even more selective
						this->medias.at(i)->set_searched(false);
					}
	    		}
			}
		}

		// in case no media was found in a sucessive search, we reset the search parameters
		if(!isFound){this->clear_search();}
	}

	return isFound;

}

void Library::list_media(){
	if(previousSearch){ // show only media which was prevoisly searched
		for(vector<Media*>::iterator it = medias.begin(); it != medias.end(); ++it){
			if((*it)->is_searched()){
				(*it)->show_info(false); //not detailed information
			}
		}
	}
	else{
		for(vector<Media*>::iterator it = medias.begin(); it != medias.end(); ++it){
			(*it)->show_info(false); //not detailed information
		}
	}

}

void Library::clear_search(){
	for(vector<Media*>::iterator it = medias.begin(); it != medias.end(); ++it){
		(*it)->set_searched(false);
	}
	this->previousSearch = false;
}

void Library::add_media(Media* media){
	// we could check for duplicates
	if (media) { //check if media is not a NULL pointer
		this->medias.push_back(media);
	}
}


Media* Library::media_from_string(string media_string){

	Media *media;
	vector<string> attributs = helper::split_string(media_string,char_delimiter);

	// CATCH EXCEPTION //////
	int media_index = stoi(attributs.at(0));
	// CATCH EXCEPTION


	switch(media_index){

		case 1 :	media = new Book(attributs);
					break;

		case 2 :	media = new Review(attributs);
					break;

		case 3 : 	media = new Digital(attributs);
		 			break;

		case 4 : 	media = new Vhs(attributs);
		 			break;

		case 5 : 	media = new Cd(attributs);
		 			break;

		case 6 : 	media = new Dvd(attributs);
		 			break;

		default: 	media = NULL; // pas de media a construire
				    break;
	}

 	return media;
}

bool Library::update_mydb(){
  if( !(this->db.is_updated()) ){
    this->load_media();
    return true;
  }
  return false;
}