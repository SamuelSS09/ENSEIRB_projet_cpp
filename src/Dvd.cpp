#include "Dvd.h"

const string class_index = "5";

Dvd::Dvd():Vhs(){
	tracksNumber = 0;
}

Dvd::Dvd(unsigned id,string title,string author,int length,string producer,int tracksNumber)
: Vhs(id,title,author,length,producer) {
	this->set_tracks_number(tracksNumber);
}

Dvd::Dvd(std::vector<string> attributs) : Vhs(attributs) {
	this->set_tracks_number(stoi(attributs.at(6)));
}

string Dvd::to_string(){
	string s = Vhs::to_string();
    
    //replace class index
	int position_at_str = 0;
	int length_of_char = 1;
	s.replace(position_at_str,length_of_char,class_index);

	return s + "," + std::to_string(this->get_tracks_number());

}
