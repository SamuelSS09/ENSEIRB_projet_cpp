#include "Media.h"
#include <iostream>

Media::Media(){
//empty constructor of the class
}

Media::Media(string name,string title,string author){
	this->set_name(name);
	this->set_author(author);
	this->set_title(title);
}


string Media::to_string(){
	return "should have a string";
}