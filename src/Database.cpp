#include "Database.h"

bool Database::check_file(){
	this->fileManager.open(filename);
	return fileManager.good();
}

vector<string> Database::read_database(){

//OBS1: should not create duplicated Media.
//steps 1: make sure the file exists
//step N: close file

	vector<string> strings;
	string line;   					// represents each line of the file
	if(this->check_file()){ 		// check if file is correctly oppened
		while(!fileManager.eof()){ 	// until the end of the file
			getline(fileManager,line);
			strings.push_back(line);
		}
	}

	fileManager.close();

	return strings;
}

void Database::write_database(vector<string> lines){


}