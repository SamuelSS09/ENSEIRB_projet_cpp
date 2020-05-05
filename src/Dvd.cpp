#include "Dvd.h"

// const string class_index = "5";

Dvd::Dvd():Vhs(){
	tracksNumber = 0;
	this->class_index=6;
}

Dvd::Dvd(string title,string author,int length,string producer,int tracksNumber)
: Vhs(title,author,length,producer) {
	this->set_tracks_number(tracksNumber);
	this->class_index=6;

}

Dvd::Dvd(std::vector<string> attributs) : Vhs(attributs) {
	this->set_tracks_number(stoi(attributs.at(6)));
	this->class_index=6;

}

string Dvd::to_string(){
	string s = Vhs::to_string();
	return s + "," + std::to_string(this->get_tracks_number());

}

void Dvd::show_info(bool detailed){
	Vhs::show_info(detailed);
	if(detailed){
		cout << "Número des pistes: " << this->get_tracks_number() << endl;
	}
}

void Dvd::set_info(){
	Vhs::set_info();

	cout << "Insérer le número des pistes: ";
	this->set_tracks_number(this->get_int_from_user());
}