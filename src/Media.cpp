#include "Media.h"

Media::Media(){
//empty constructor of the class
}

Media::Media(string name,string title,string author){
	this->set_name(name);
	this->set_author(author);
	this->set_title(author);
}


