#include "MainController.h"

MainController::MainController(string filename){
	this->myLibrary.set_db_filename(filename);
}

void MainController::start_program(){

	vector<string> user_input = this->myInterface.get_user_command();
	string command = user_input.at(0);

	if(command == "BYE"){}

	else if (command == "LOAD"){
		this->myLibrary.set_db_filename(user_input.at(1));
		this->myLibrary.load_media();
		// Just for testing
		cout << this->myLibrary.get_medias().at(0)->to_string() << endl;
	}

	else if (command == "LIST"){}

}