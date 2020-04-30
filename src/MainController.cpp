#include "MainController.h"

MainController::MainController(string filename){
	this->myLibrary.set_db_filename(filename);
}

void MainController::start_program(){

	vector<string> user_input = this->myInterface.get_user_command();
	string command = user_input.at(0);

	if(command == "BYE"){
		//this->myInterface.show_goodbye();
	}

	else if (command == "LOAD"){
		this->myLibrary.set_db_filename(user_input.at(1));
		try{
			this->myLibrary.load_media();
		}catch(exception e){

			// this line must be a method of the interface class.
			cerr << "Le fichier n'a pas pu être ouverte" << endl;
			
			this->start_program();
		}
		// Just for testing
		//cout << this->myLibrary.get_medias().at(0)->to_string() << endl;
	}

	else if (command == "LIST"){
		
	}

}