#include "Vhs.h"

const string class_index = "3";

Vhs::Vhs():Media(){
	length = 0;
	producer = "";
}

Vhs::Vhs(unsigned id, string title,string author,int length,string producer)
: Media(title,author) {
	this->set_length(length);
	this->set_producer(producer);
}

Vhs::Vhs(vector<string> attributs) : Media(attributs) {
	this->set_length(stoi(attributs.at(4)));
	this->set_producer(attributs.at(5));
}

string Vhs::to_string(){
	string s = Media::to_string();

	//replace class index
	int position_at_str = 0;
	int length_of_char = 1;
	s.replace(position_at_str,length_of_char,class_index);

	return s + "," + std::to_string(get_length()) + "," + get_producer();

}
