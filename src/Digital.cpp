#include "Digital.h"

const string class_index = "2";

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
	string s = Media::to_string();

	//replace class index
	int position_at_str = 0;
	int length_of_char = 1;
	s.replace(position_at_str,length_of_char,class_index);

	return s + "," + std::to_string(this->get_size()) + "," + get_extension() + "," + get_path();
}

