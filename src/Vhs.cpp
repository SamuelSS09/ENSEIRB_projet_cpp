#include "Vhs.h"

Vhs::Vhs():Media(){
	length = 0;
	producer = "";
}

Vhs::Vhs(unsigned id, string name,string title,string author,int length,string producer)
: Media(id,name,title,author) {
	this->set_length(length);
	this->set_producer(producer);
}

string Vhs::to_string(){
	return "Vhs: je suis une string hehe";
}
