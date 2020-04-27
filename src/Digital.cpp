#include "Digital.h"

Digital::Digital(){}

Digital::Digital(string name,string title,string author,string extension,string path,int size) 
: Media(name,title,author) {
	this->set_extension(extension);
	this->set_path(path);
	this->set_size(size);
}

string Digital::to_string(){
	return "Voila la string";
}