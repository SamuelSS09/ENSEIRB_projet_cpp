#include "Interface.h"


void Interface::add_possible_options(string option){
	this->possible_options.push_back(option);
}

void Interface::list_media(std::vector<Media*> medias){
	cout << "ID              " << "TITRE            " <<"AUTEUR            " << endl;
	for(int i = 0; i < medias.size() ; i++){
		cout << medias.at(i)->get_id() << "            ";
		cout << medias.at(i)->get_title() << "            ";
		cout << medias.at(i)->get_author() << "            ";
		cout << endl;
	}

}

string Interface::get_string_from_user(){
	cin.clear();
	string option;

	getline(cin,option);
	while (option.length()==0 ){
            getline(cin, option);
    }

    return option;
}

int Interface::get_int_from_user(){

    int user_int = 0;

    try{
    	user_int = stoi(this->get_string_from_user());
    }catch(...){
    	cout << "Veuillez inserer une nombre valide" << endl;
    	this->get_int_from_user(); // try again
    }

    return user_int;
}


Interface::Interface(){
	this->add_possible_options("BYE,0");
	this->add_possible_options("CLEAR,0");
	this->add_possible_options("LIST,0");
	this->add_possible_options("ADD,1");
	this->add_possible_options("LOAD,1");
	this->add_possible_options("RESET,0");
	this->add_possible_options("SEARCH,1");
	this->add_possible_options("DELETE,1");
	this->add_possible_options("SHOW,1");
}

vector<string> Interface::get_user_command(){

	cout << "Veuillez utiliser une des options suivants: " << endl;
	cout << "- LOAD filename : charger la médiathèque avec le fichier nomé filename" << endl;
	cout << "- SEARCH chaine : chercher la médiathèque avec la chaine fournie" << endl;
	cout << "- LIST          : afficher des la médiathèque. Garde les résultats d'une recherche précedente" << endl;
	cout << "- BYE           : sors du programme" << endl;
	cout << "- CLEAR         : jetter les résultats des recherches accumulées" << endl;
	cout << "- RESET         : vider la base médiathèque" << endl;
	cout << "- ADD type      : ajouter une média du type fourni." << endl;
	cout << "- SHOW id     : afficher la médiathèque de l'identifiant fourni" << endl;
	cout << "- DELETE id     : supprimer la médiathèque de l'identifiant fourni." << endl;


	vector<string> optionSplit = helper::split_string(this->get_string_from_user(),' ');


	while(cin.bad() || !(this->validate_option(optionSplit)) ){

		cout << "Veuillez inserer une option valide " << endl;

		optionSplit = helper::split_string(this->get_string_from_user(),' ');

	}
	cin.clear();
	return optionSplit;

}

void Interface::hello(){
	cout << "Bienvenu(e) à l'application de management de la librairie! " << endl;

}

void Interface::print_error_db(){

	cerr << "Le fichier n'a pas pu être ouverte." << endl;
	cout << "Veuillez vérifier si le fichier de données existe."<< endl;

}

void Interface::goodbye(){
	cout << "Au revoir!" << endl;
}

void Interface::print_reset(){
	cout << "La base des données a été vidée." << endl;
}

Media* Interface::media_from_input(string media_type){

	if(media_type == "Book"){

		cout << "Inserer le titre: ";
		string title = this->get_string_from_user();

		cout << "Inserer l'auteur: ";
		string author = this->get_string_from_user();

		cout << "Inserer l'année de publication: ";
		int publishingYear = this->get_int_from_user();

		cout << "Inserer le nombre de pages: ";
		int numberOfPages = this->get_int_from_user();

		cout << "Inserer le résumé du livre: ";
		string summary = this->get_string_from_user();

		cout << "Inserer la collection dont le livre appartient: ";
		string collection = this->get_string_from_user();

		// it is already created with a single unique id. logic explained in the
		// READ_ME of Media.h
		Media * m = new Book(title, author, publishingYear, numberOfPages, summary,collection);
		return m;
	}

	else{
		cout << "Veuillez inserer un type valable de media" << endl;
		cout << "Ces sont: Book, Cd, Dvd, Digital, Review et Vhs" << endl;

		return NULL;
	}
}


bool Interface::validate_option(vector<string> optionSplit){//validate every possible option
	// 1 - Nothing was inserted:
	if(optionSplit.size() == 0){return false;}

	else{

		string userOption = optionSplit.at(0);

		for (int i = 0; i < this->possible_options.size() ; i++){

			// the following vector has OPTION at first position (at 0)
			// and NUMBER OF NECESSARY ARGUMENTS at second position (at 1)
			vector<string> current_option = helper::split_string(this->possible_options.at(i),',');

			// 2 - test if text matches any avaliable option
			if(userOption == current_option.at(0)){

				// test if correct number of arguments was provided
				if(optionSplit.size() == stoi(current_option.at(1)) + 1){
					// cout << "DEU BOM" << endl;
					return true;
				}

				else{
					cout << "Veuillez inserer le bon nombre d'arguments" << endl;
					return false;
				}
			}

		}

		return false; // means we have not found a match in the FOR loop

	}

}
