#include "Cd.h"

Cd::Cd(){

}

Cd::Cd(string name,string title,string author,int length,string producer,int tracksNumber)
: Vhs(name,title,author,length,producer) {
	this->set_tracks_number(tracksNumber);
}

string Cd::to_string(){
	return "Cd: je suis une string hehe\n" + this->get_name();
}