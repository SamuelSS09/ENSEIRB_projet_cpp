#include "MediaController.h"

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

}
void MediaController::write_media(){

}
void MediaController::delete_by_id(){

}
void MediaController::search_by_id(){

}
void MediaController::search_by_char(){

}
