#include "Digital.h"

Digital::Digital():Media(){
	extension = "";
	path = "";
	size = 0;
}

Digital::Digital(unsigned id, string name,string title,string author,string extension,string path,int size)
: Media(id,name,title,author) {
	this->set_extension(extension);
	this->set_path(path);
	this->set_size(size);
}

string Digital::to_string(){
	return "Voila la string";
}
