#include "Cd.h"

const string class_index = "4";

Cd::Cd():Vhs(){
	tracksNumber = 0;
}

Cd::Cd(string title,string author,int length,string producer,int tracksNumber)
: Vhs(title,author,length,producer) {
	this->set_tracks_number(tracksNumber);
}

Cd::Cd(std::vector<string> attributs) : Vhs(attributs) {
	this->set_tracks_number(stoi(attributs.at(6)));
}

string Cd::to_string(){
	string s = Vhs::to_string();
    
    //replace class index
	int position_at_str = 0;
	int length_of_char = 1;
	s.replace(position_at_str,length_of_char,class_index);

	return s + "," + std::to_string(this->get_tracks_number());

}
