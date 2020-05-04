#include "Library.h"
#include "helper.h"
#include <iostream>

char char_delimiter = ',';

Library::Library(string filename){
	this->db.set_filename(filename);
}

Library::~Library(){

	// try to write media vector to a file
	vector<string> medias_string;

	for (int i=0;i<this->medias.size();i++){

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
	for(int i=0 ; i < this->medias.size() ; i++){
		delete this->medias.at(i);
	}

	this->medias.clear();

	this->search_indexes.clear();

}

vector<Media*> Library::get_medias(){ //
	//this->myMediaInterface.show_header();
	if(this->search_indexes.empty()){ // if there was no previous search
		return this->medias;
	}

	else{ // if there was a previous search
		vector<Media*> medias_filtered;
		for(int i : this->search_indexes){
			medias_filtered.push_back(this->medias.at(i));
		}
		return medias_filtered;
	}
}

void Library::load_media(){
   vector<string> media_string = this->db.read_database();
   for(int i = 0; i < media_string.size(); i++){
   	//OBS1: should not create duplicated Media.
      this->medias.push_back(this->media_from_string(media_string.at(i)));
   }

}
void Library::write_media(){
	std::vector<string> lines;
	for(int i = 0; i < this->medias.size() ; i++){

		lines.push_back(medias.at(i)->to_string());
	}
	this->db.write_database(lines);
}
void Library::delete_by_id(int media_id){
	for(int i=0; i < this->medias.size(); i++){
		if (medias.at(i)->get_id() == media_id){
			//delete this->medias.at(i);
			this->medias.erase(medias.begin()+i);
		}
		this->search_indexes.clear();
	}
}
void Library::search_by_id(){

}
bool Library::search_by_string(string character_sequence){


	bool isFound = false; // check if the search was sucessfull;

	//this function has a different behavioral in case the vector
	//of searched indexes is not empty

	if(this->search_indexes.empty()){ //CASE OF NO PREVIOUS SEARCH
		for(int i = 0; i < this->medias.size(); i++){ // iterate through the media vector

			string mediaString = medias.at(i)->to_string();

			if(character_sequence.size() < mediaString.size() ){ //char_seq must be smaller than mediaString

	    		if(mediaString.find(character_sequence) != std::string::npos){ // check if we have a substring
	    			isFound = true; // the search found a match
	    			this->search_indexes.push_back(i);

	    		}
			}
		}

		//makes sure the vector of indexes is ordered.
		std::sort(this->search_indexes.begin(),this->search_indexes.end());
		return isFound;
	}

	else{ // CASE THERE WAS A PREVIOUS A SEARCH

		vector<int> new_search_indexes; // temporary array to hold the results of the new search

		for(int i = 0; i < this->search_indexes.size(); i++){ // iterate through indexes vector

			string mediaString = medias.at(search_indexes.at(i))->to_string();

			if(character_sequence.size() < mediaString.size() ){ //char_seq must be smaller than mediaString

	    		if(mediaString.find(character_sequence) != std::string::npos){ // check if we have a substring
	    			isFound = true; // the search found a match
	    			new_search_indexes.push_back(i); // add to the temporary vector of indexes

	    		}
			}
		}

		//makes sure the vector of indexes is ordered.
		std::sort(new_search_indexes.begin(),new_search_indexes.end());
		this->search_indexes = new_search_indexes; // update the original search_indexes
		return isFound;
	}

}

void Library::clear_search(){
	this->search_indexes.clear();
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

		case 0 :	media = new Book(attributs);
					break;

		case 1 :	media = new Review(attributs);
					break;

		case 2 : 	media = new Digital(attributs);
		 			break;

		case 3 : 	media = new Vhs(attributs);
		 			break;

		case 4 : 	media = new Cd(attributs);
		 			break;

		case 5 : 	media = new Dvd(attributs);
		 			break;

		default: 	media = NULL; // pas de media a construire
				    break;
	}

 	return media;
}
