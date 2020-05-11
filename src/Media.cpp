#include "Media.h"
#include <typeinfo>       // operator typeid

unsigned Media::nextID = 0;
// constant short class_index = 0;
//PRIVATE FUNCTIONS

void Media::init(unsigned id, string title, string author){
	this->set_id(id);
	this->set_author(author);
	this->set_title(title);
	this->isSearched = false;
	this->class_index = 0;
}

string Media::get_string_from_user(){
	cin.clear();
	string option;

	getline(cin,option);
	while (option.length()==0 ){
            getline(cin, option);
    }

    return option;
}

int Media::get_int_from_user(){

    int user_int = 0;

    try{
    	user_int = stoi(this->get_string_from_user());
    }catch(...){
    	cout << "Veuillez inserer une nombre valide" << endl;
    	this->get_int_from_user(); // try again
    }

    return user_int;
}

//CONSTRUCTORS AND DESTRUCTOR

Media::~Media(){}

Media::Media(){
	this->init(this->nextID,"", "");
	this->nextID++; // increment the counter of IDs
}

Media::Media(string title,string author){
	this->init(this->nextID,title,author);
	this->nextID++;
}

Media::Media(vector<string> attributs){
	int readID = stoi(attributs.at(1));

	// we check if the id received is greater or equal  than the number of instances
	// already existent. In this case, we have to correct the couting of IDs
	if(readID >= this->nextID){
		this->nextID = readID + 1;
	}
	this->init(readID,attributs.at(2),attributs.at(3));
}

//OTHER FUNCTIONS

string Media::to_string(){ // formating to write on file.
	return std::to_string(class_index) + "," + std::to_string(this->id) + ","  + get_title() + "," + get_author();
}

void Media::show_info(bool detailed){ // NOT MVC

	string s;

	switch(this->class_index){
		case 0: s = "Media";
				break;
		case 1: s = "Livre";
				break;
		case 2: s = "Article";
				break;
		case 3: s = "Numérique";
				break;
		case 4: s = "VHS";
				break;
		case 5: s = "CD";
				break;
		case 6: s = "DVD";
				break;
	}

	string space_char;

	if(detailed){space_char = "\n";} else{space_char = "\t";}

	cout << "ID: " << this->get_id() << space_char;
	cout << "Type: " << s << space_char;
	cout << "Titre: " << this->get_title() << space_char;
	cout << "Auteur: " << this->get_author() << endl;
	
 }


void Media::set_info(){ // NOT MVC
	cout << "Inserer le titre: ";
	this->set_title(this->get_string_from_user());

	cout << "Inserer l'auteur: ";
	this->set_author(this->get_string_from_user());
}
