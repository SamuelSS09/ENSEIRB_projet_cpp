#include "Media.h"
#include <iostream>

const string class_index = "X";

Media::Media(){
	id = 0;
	author = "";
	title = "";
}
void Media::init(unsigned id, string title,string author){
	this->set_id(id);
	this->set_author(author);
	this->set_title(title);
}


Media::Media(unsigned id, string title,string author){
	this->init(id,title,author);
}

Media::Media(vector<string> attributs){
	this->init(stoi(attributs.at(1)),attributs.at(2),attributs.at(3));
}

string Media::to_string(){
	return class_index + "," + std::to_string(get_id()) + "," + get_title() + "," + get_author() + "," ;
} 


// Method 1: 
//Media::Media(vector<string> attributs)
// : Media(stoi(attributs.at(0)), attributs.at(1), attributs.at(2),attributs.at(3)){}



