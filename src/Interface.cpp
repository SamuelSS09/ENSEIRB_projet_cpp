#include "Interface.h"


Interface::Interface(){
	this->possible_options.push_back("BYE,0");
	this->possible_options.push_back("CLEAR,0");
	this->possible_options.push_back("LIST,0");
	this->possible_options.push_back("ADD,1");
	this->possible_options.push_back("LOAD,1");
	this->possible_options.push_back("RESET,0");
	this->possible_options.push_back("SEARCH,1");
	this->possible_options.push_back("DELETE,1");
	this->possible_options.push_back("SHOW,1");
	this->possible_options.push_back("UTILISATEUR,0");
	this->possible_options.push_back("ADMIN,0");
	this->possible_options.push_back("CLIENT,0");
}

string Interface::get_string_from_user(){
	cin.clear();
	string option;
	cout << endl <<  ">> ";
	getline(cin,option);
	while (option.length()==0 ){
            getline(cin, option);
    }

    return option;
}

int Interface::get_int_from_user(){

    int user_int = 0;
   	cout << endl << ">> ";
    try{
    	user_int = stoi(this->get_string_from_user());
    }catch(...){
    	cout << "Veuillez inserer une nombre valide" << endl;
    	this->get_int_from_user(); // try again
    }

    return user_int;
}

vector<string> Interface::get_user_login(){
	cout << endl;
	cout << "Veuillez choisir entre l'une des options d'utilisations suivantes: " << endl;
	cout << "UTILISATEUR : connectez-vous à votre compte." << endl;
	cout << "ADMIN : s'enregister autant qu'aministrateur." << endl;
	cout << "CLIENT : utiliser l'application comme client." << endl;

	vector<string> optionSplit = helper::split_string(this->get_string_from_user(),' ');


	while(cin.bad() || !(this->validate_option(optionSplit)) ){

		cout << "Veuillez inserer une option valide " << endl;

		optionSplit = helper::split_string(this->get_string_from_user(),' ');

	}
	cin.clear();
	return optionSplit;

}

vector<string> Interface::get_user_command(){
	cout << endl;
	cout << "Veuillez utiliser une des options suivantes: " << endl;
	cout << "- LOAD filename : charger la médiathèque avec le fichier nommé filename." << endl;
	cout << "- SEARCH chaine : chercher la médiathèque avec la chaine fournie." << endl;
	cout << "- LIST          : afficher la médiathèque. Garde les résultats d'une recherche précedente." << endl;
	cout << "- CLEAR         : jetter les résultats des recherches accumulées." << endl;
	cout << "- RESET         : vider la base de données de la médiathèque." << endl;
	cout << "- ADD type      : ajouter un média du type fourni." << endl;
	cout << "- SHOW id       : afficher la médiathèque de l'identifiant fourni" << endl;
	cout << "- DELETE id     : supprimer la médiathèque de l'identifiant fourni." << endl;
	cout << "- BYE           : sortir du logiciel." << endl;

	vector<string> optionSplit = helper::split_string(this->get_string_from_user(),' ');


	while(cin.bad() || !(this->validate_option(optionSplit)) ){

		cout << "Veuillez inserer une option valide " << endl;

		optionSplit = helper::split_string(this->get_string_from_user(),' ');

	}
	cin.clear();
	return optionSplit;

}

void Interface::hello(){
	cout << endl << "Bienvenu(e) à l'application de management de la librairie! " << endl;

}

void Interface::login(){
	cout << endl << "Veuillez vous connecter!" << endl;
}

void Interface::print_error_db(){

	cerr << endl << "Le fichier n'a pas pu être ouverte." << endl;
	cout << "Veuillez vérifier si le fichier de données existe."<< endl;

}

void Interface::goodbye(){
	cout << endl  << "Au revoir!" << endl;
}

void Interface::print_reset(){
	cout << endl << "La base des données a été efacée." << endl;
}

bool Interface::validate_option(vector<string> optionSplit){//validate every possible option
	// 1 - Nothing was inserted:
	if(optionSplit.size() == 0){return false;}

	else{

		string userOption = optionSplit.at(0);

		for (long unsigned int i = 0; i < this->possible_options.size() ; i++){

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

void Interface::print(string txt){ cout << endl << txt << endl;}
void Interface::error(string error){cerr << endl << error << endl;}


// void Interface::list_media(std::vector<Media*> medias){
// 	cout << "ID              " << "TITRE            " <<"AUTEUR            " << endl;
// 	for(int i = 0; i < medias.size() ; i++){
// 		cout << medias.at(i)->get_id() << "            ";
// 		cout << medias.at(i)->get_title() << "            ";
// 		cout << medias.at(i)->get_author() << "            ";
// 		cout << endl;
// 	}

// }
