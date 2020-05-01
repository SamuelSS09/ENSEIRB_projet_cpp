#include "MainController.h"

MainController::MainController(string filename){
	//setlocale(LC_ALL, "french");
	this->load_my_database(filename);
   
}

void MainController::load_my_database(string filename){
	 this->myLibrary.set_db_filename(filename);

	try{
		this->myLibrary.load_media();
		//AFICHER UNE MESSAGE
	}catch(exception e){
		// this line must be a method of the interface class.
		cerr << "Le fichier n'a pas pu être ouverte" << endl;
	}
}

void MainController::start_program(){

	vector<string> user_input = this->myInterface.get_user_command();
	string command = user_input.at(0);

	if(command == "BYE"){
		//this->myInterface.show_goodbye();
	}

	else if (command == "LOAD"){

		//string original_filename = this->myLibrary.get_filename();

		this->myLibrary.set_db_filename(user_input.at(1));
		try{
			this->myLibrary.load_media();
			//AFICHER UNE MESSAGE
			this->start_program();
		}catch(exception e){
			// this line must be a method of the interface class.
			cerr << "Le fichier n'a pas pu être ouverte" << endl;
			//this->load_my_database(original_filename);
			this->start_program();

		}
	}

	else if (command == "SEARCH"){
		if(this->myLibrary.search_by_string(user_input.at(1))){
			//should list all the found media?
		}

		else{

		}
	}

}

