#include "Cd.h"

// const short class_index = 5;

Cd::Cd():Vhs(){
	tracksNumber = 0;
	this->class_index = 5;
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
	return s + "," + std::to_string(this->get_tracks_number());

}

void Cd::show_info(bool detailed){
	Vhs::show_info(detailed);
	if(detailed){
		cout << "Número des pistes: " << this->get_tracks_number() << endl;
	}
}

void Cd::set_info(){
	Vhs::set_info();

	cout << "Insérer le número des pistes: ";
	this->set_tracks_number(this->get_int_from_user());
}