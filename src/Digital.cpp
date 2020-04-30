#include "Digital.h"

void Digital::init(int size, string extension,string path){
	this->set_extension(extension);
	this->set_path(path);
	this->set_size(size);
}


Digital::Digital():Media(){
	extension = "";
	path = "";
	size = 0;
}

Digital::Digital(unsigned id,string title,string author,int size, string extension,string path)
: Media(id,title,author) {
	this->init(size,extension,path);
}

Digital::Digital(std::vector<string> attributs)
: 	Media(attributs){
	this->init(stoi(attributs.at(4)),attributs.at(5),attributs.at(6));
} 

string Digital::to_string(){
	return "Voila la string";
}

