#include "Library.h"
#include "helper.h"
#include <iostream>

char char_delimiter = ',';

Library::Library(string filename){
	this->db.set_filename(filename);
}

Library::~Library(){

	for (int i=0;i<this->medias.size();i++){
 		delete this->medias.at(i);
 	} 
	this->medias.clear();
}

vector<Media*> Library::get_medias(){ // 
	//this->myMediaInterface.show_header();
	if(this->search_indexes.size() == 0){ // if there was no previous search
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
void Library::delete_by_id(){

}
void Library::search_by_id(){

}
bool Library::search_by_string(string character_sequence){

	bool isFound = false; // check if the search was sucessfull;
	for(int i = 0; i < this->medias.size(); i++){ // iterate the media vector
	
		string mediaString = medias.at(i)->to_string();

		if(character_sequence.size() < mediaString.size() ){ //char_seq must be smaller than mediaString
    		
    		if(mediaString.find(character_sequence) != std::string::npos){
    			this->search_indexes.push_back(i);
    			isFound = true; // the search found a match
    		}
		}
	}
	return isFound;
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