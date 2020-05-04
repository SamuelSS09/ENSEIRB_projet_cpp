#include "Media.h"


const string class_index = "X"; //not supposed to be instantiated
unsigned Media::nextID = 0;

void Media::init(unsigned id, string title, string author){
	this->set_id(id);
	this->set_author(author);
	this->set_title(title);
	this->isSearched = false;
}

Media::~Media(){ 
	//this->nextID = nextID -1;
}

Media::Media(){
	this->init(this->nextID,"", "");
	this->nextID++; // increment the counter of IDs
}

Media::Media(string title,string author){
	this->init(this->nextID,title,author);
	this->nextID++;
}

Media::Media(vector<string> attributs){

	int readID = stoi(attributs.at(1));

	// we check if the id received is greater than the number of classes
	// already existent. In this case, we have to correct the couting of IDs

	if(readID > this->nextID){ 
		this->nextID = readID + 1;
	}

	this->init(readID,attributs.at(2),attributs.at(3));
}

string Media::to_string(){
	return class_index + "," + std::to_string(get_id()) + "," + get_title() + "," + get_author() + "," ;
} 


// Method 1: 
//Media::Media(vector<string> attributs)
// : Media(stoi(attributs.at(0)), attributs.at(1), attributs.at(2),attributs.at(3)){}