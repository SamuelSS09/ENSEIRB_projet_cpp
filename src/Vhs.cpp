#include "Vhs.h"

Vhs::Vhs(){}

Vhs::Vhs(string name,string title,string author,int length,string producer)
: Media(name,title,author) {
	this->set_length(length);
	this->set_producer(producer);
}

string Vhs::to_string(){
	return "Vhs: je suis une string hehe";
}