#include "MediaController.h"

char char_delimiter = ',';


std::vector<std::string> split_string(const std::string& s, char delimiter){
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

MediaController::MediaController(string filename){
	this->db.set_filename(filename);
}

MediaController::~MediaController(){

	for (int i=0;i<this->medias.size();i++){
 		delete this->medias.at(i);
 	} 
	this->medias.clear();
}

void MediaController::load_media(){
	//OBS1: should not create duplicated Media.
   vector<string> media_string = this->db.read_database();
   for(int i = 0; i < media_string.size(); i++){
      this->medias.push_back(this->media_from_string(media_string.at(i)));
   }

}
void MediaController::write_media(){

}
void MediaController::delete_by_id(){

}
void MediaController::search_by_id(){

}
void MediaController::search_by_char(){

}

Media* MediaController::media_from_string(string media_string){

	Media *media;
	vector<string> attributs = split_string(media_string,char_delimiter);
	// CATCH EXCEPTION //////
	int media_index = stoi(attributs.at(0));
	// CATCH EXCEPTION

	//0:Book
	//1:Review
	//2 Digital
	//3:VHS
	//4:Cd
	//5:Dvd

	// class_id
	//id
   //title
	//author
	

   //publishing_year
   //number_of_pages
	//summary
	//collection
	


	switch(media_index){
		case 0 : media = new Book(attributs);
				   break;


		default: media = new Book();
				   break; 
	}

 	return media;
}

