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

string Interface::get_user_input(){
	cin.clear();
	string option;

	getline(cin,option);
	while (option.length()==0 ){
            getline(cin, option);
    }

    return option;
}


Interface::Interface(){
	this->add_possible_options("BYE,0");
	this->add_possible_options("LIST,0");
	this->add_possible_options("ADD,1");
	this->add_possible_options("LOAD,1");
	this->add_possible_options("RESET,0");
	this->add_possible_options("SEARCH,1");

}

vector<string> Interface::get_user_command(){

	cout << "Bienvenu(e) à l'application de management de la librairie! " << endl;
	cout << "Veuillez utiliser une des options suivants: " << endl;
	cout << "- LOAD filename : charger la médiathèque avec le fichier nomé filename" << endl;
	cout << "- SEARCH chaine : chercher la médiathèque avec la chaine fournue" << endl;
	
	vector<string> optionSplit = helper::split_string(this->get_user_input(),' ');	

	
	while(cin.bad() || !(this->validate_option(optionSplit)) ){

		cout << "Veuillez inserer une option valide " << endl;

		optionSplit = helper::split_string(this->get_user_input(),' ');
		
	}
	cin.clear();
	return optionSplit;

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