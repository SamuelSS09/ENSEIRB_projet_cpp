#include "Database.h"

bool Database::check_file(){
	this->fileManager.open(filename);
	return fileManager.good();
}

vector<Books*> Database::read_media_database(){
//steps 1: make sure the file exists
//step N: close file

	vector<Medias*> medias;
	string line; // represents each line of the file
	int inter = 0; // we need the first iteration
	if(this->check_file()){ // check if file is correctly oppened
		while(!fileManager.eof){ //until the end of the file
			getline(fileManager,line);
		}
	}
	
	return medias;
}

void Database::write_database(){


}