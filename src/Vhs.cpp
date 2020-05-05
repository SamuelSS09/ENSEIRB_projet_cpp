#include "Vhs.h"

// const string class_index = "3";

Vhs::Vhs():Media(){
	length = 0;
	producer = "";
	this->class_index = 4;
}

Vhs::Vhs(string title,string author,int length,string producer)
: Media(title,author) {
	this->set_length(length);
	this->set_producer(producer);
	this->class_index = 4;
}

Vhs::Vhs(vector<string> attributs) : Media(attributs) {
	this->set_length(stoi(attributs.at(4)));
	this->set_producer(attributs.at(5));
	this->class_index = 4;
}

string Vhs::to_string(){
	string s = Media::to_string();
	return s + "," + std::to_string(get_length()) + "," + this->get_producer();

}

void Vhs::show_info(bool detailed){
	Media::show_info(detailed);
	if(detailed){
		cout << "Duration: " << this->get_length() << " minutes" << "\t";
		cout <<  "Producteur: " << this->get_producer() << "\t";
	}
}

void Vhs::set_info(){
	Media::set_info();

	cout << "Insérer la longuer en minutes: ";
	this->set_length(this->get_int_from_user());

	cout << "Insérer le producteur: ";
	this->set_producer(this->get_string_from_user());
}