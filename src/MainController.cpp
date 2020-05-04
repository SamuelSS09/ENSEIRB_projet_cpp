#include "MainController.h"

MainController::MainController(string filename){
	setlocale(LC_ALL, "french");
	this->load_my_database(filename);
	this->myInterface.hello();

}

void MainController::load_my_database(string filename){

	this->myLibrary.set_db_filename(filename);

	try{
		this->myLibrary.load_media();
		//AFICHER UNE MESSAGE
	}catch(exception e){
		this->myInterface.print_error_db();
	}
}

void MainController::start_program(){

	string command = "";
	do{
		vector<string> user_input = this->myInterface.get_user_command();
		command = user_input.at(0);
		if(command == "CLEAR"){
			this->myLibrary.clear_search();
		}

		else if(command == "LIST"){
			this->myInterface.list_media(this->myLibrary.get_medias());
		}

		else if(command == "RESET"){
			this->myLibrary.clear_medias();
			this->myInterface.print_reset();
		}

		else if(command == "ADD"){
			//this solutions is weird, because we feed a input that the interface got
			// back to herself
			this->myLibrary.add_media(this->myInterface.media_from_input(user_input.at(1)));
		}

		else if(command == "LOAD"){

			string original_filename = this->myLibrary.get_db_filename();
			this->myLibrary.set_db_filename(user_input.at(1));

			try{
				 this->myLibrary.load_media();
				//AFICHER UNE MESSAGE

			}catch(exception e){

				this->myLibrary.set_db_filename(original_filename);
				this->myLibrary.load_media();
				this->myInterface.print_error_db();

			}
		}

		else if(command == "DELETE"){
			this->myLibrary.delete_by_id(stoi(user_input.at(1)));
		}

		else if(command == "SHOW"){
			if(this->myLibrary.search_by_id(stoi(user_input.at(1)))){
				this->myInterface.list_media(this->myLibrary.get_medias());
			}
		}

		else if (command == "SEARCH"){
			if(this->myLibrary.search_by_string(user_input.at(1))){
				this->myInterface.list_media(this->myLibrary.get_medias());
			}
			else{

			}
		}
	}while(command != "BYE");

	this->myInterface.goodbye();
	//NT: when the program is closed, the destructor of myLibrary will be called.
	//It will try to write all media into a file
}
