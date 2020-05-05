#include "Digital.h"

// const string class_index = "2";

void Digital::init(int size, string extension,string path){
	this->set_extension(extension);
	this->set_path(path);
	this->set_size(size);
	this->class_index = 3;
}


Digital::Digital():Media(){
	this->init(0, "", "");
}

Digital::Digital(string title,string author,int size, string extension,string path)
: Media(title,author) {
	this->init(size,extension,path);
}

Digital::Digital(std::vector<string> attributs)
: 	Media(attributs){
	this->init(stoi(attributs.at(4)),attributs.at(5),attributs.at(6));
} 

string Digital::to_string(){
	string s = Media::to_string();
	return s + "," + std::to_string(this->get_size()) + "," + get_extension() + "," + get_path();
}

void Digital::show_info(bool detailed){
	Media::show_info(detailed);
	if(detailed){
		cout << "Taille du fichier: " << this->get_size() << " kBs" << "\t";
		cout << "Type du fichier: " << this->get_extension() << endl;
		cout << "Chemin du fichier: " << this->get_path() << endl;
	}
}

void Digital::set_info(){
	Media::set_info();

	cout << "Insérer la taille du fichier en kBs: ";
	this->set_size(this->get_int_from_user());
	
	cout << "Insérer le type du fichier: ";
	this->set_extension(this->get_string_from_user());

	cout << "Insérer le chemin du fichier: ";
	this->set_path(this->get_string_from_user());
}