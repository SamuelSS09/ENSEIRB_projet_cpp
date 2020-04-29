#include "Dvd.h"

Dvd::Dvd(){}

Dvd::Dvd(string name,string title,string author,int length,string producer,int tracksNumber)
: Vhs(name,title,author,length,producer) {
	this->set_tracks_number(tracksNumber);
}

string Dvd::to_string(){
	return "Dvd: je suis une string hehe\n" + this->get_name();
}
