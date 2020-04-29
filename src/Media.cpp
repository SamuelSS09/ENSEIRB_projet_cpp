#include "Media.h"
#include <iostream>

Media::Media(){
	id = 0;
	name = "";
	author = "";
	title = "";
}

Media::Media(unsigned id, string name,string title,string author){
	this->set_id(id);
	this->set_name(name);
	this->set_author(author);
	this->set_title(title);
}


// string Media::to_string(){
// 	return "should have a string";
// }
