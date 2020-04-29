#include "Dvd.h"

Dvd::Dvd():Vhs(){
	tracksNumber = 0;
}

Dvd::Dvd(unsigned id,string title,string author,int length,string producer,int tracksNumber)
: Vhs(id,title,author,length,producer) {
	this->set_tracks_number(tracksNumber);
}

string Dvd::to_string(){
	return "Dvd: je suis une string hehe\n" ;
}
