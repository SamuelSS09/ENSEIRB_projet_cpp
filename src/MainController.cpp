#include "MainController.h"

MainController::MainController(string data_filename, string users_filename){
	setlocale(LC_ALL, "french");
	this->load_my_database(data_filename,users_filename);
	this->myInterface.hello();
	// this->myInterface.login();
}

void MainController::load_my_database(string filename, string users_filename){

	this->myLibrary.set_db_filename(filename);
	this->Users.set_db_filename(users_filename);
	try{
		this->myLibrary.load_media();
		this->Users.read_users();
		//AFICHER UNE MESSAGE
	}catch(exception e){
		this->myInterface.print_error_db();
	}
}

void MainController::start_program(){

	string command = "";

	do{
		
		// vector<string> user_input = this->myInterface.get_user_login();
		// command = user_input.at(0);
		// this->Users.write_users();
		// if(command == "UTILISATEUR"){
		// 	this->myInterface.print("Entrer le nom d'utilisateur: ");
		// 	if (this->Users.validate_login(this->myInterface.get_string_from_user())){
		// 		this->myInterface.print("Entrer le mot de passe: ");
		// 		if (this->Users.validate_password(this->myInterface.get_string_from_user())){
		// 			this->myInterface.print("Vous êtes un administrateur!");
		// 		}
		// 		else{
		// 			this->myInterface.error("Vous n'êtes pas administrateur. Veuillez utiliser l'application comme client!");
		// 		}
		// 	}
		// }
		// else if(command == "ADMIN"){
		// 	User u;
		// 	u.set_info();
		// 	this->Users.add_user(u);
		// }
		// else if(command == "CLIENT"){
		// 	this->myInterface.print("Vous pouvez utiliser l'application comme un client.");
		// }

		vector<string> user_input = this->myInterface.get_user_command();
		command = user_input.at(0);
		if(command == "CLEAR"){
			this->myLibrary.clear_search();
		}

		else if(command == "LIST"){
			// this->myInterface.list_media(this->myLibrary.get_medias());
			this->myLibrary.list_media();
		}

		else if(command == "RESET"){
			this->myLibrary.clear_medias();
			this->myInterface.print_reset();
		}



		else if(command == "ADD"){

			string media_type = user_input.at(1);
			Media* m;

			if(media_type == "Book"){
				m = new Book();
				m->set_info();
				this->myLibrary.add_media(m);
			}

			else if(media_type == "Review"){
				m = new Review();
				m->set_info();
				this->myLibrary.add_media(m);
			}

			else if(media_type == "Digital"){
				m = new Digital();
				m->set_info();
				this->myLibrary.add_media(m);
			}

			else if(media_type == "Vhs"){
				m = new Vhs();
				m->set_info();
				this->myLibrary.add_media(m);
			}

			else if(media_type == "Cd"){
				m = new Cd();
				m->set_info();
				this->myLibrary.add_media(m);
			}

			else if(media_type == "Dvd"){
				m = new Dvd();
				m->set_info();
				this->myLibrary.add_media(m);
			}

			// delete m;
		}

		else if(command == "SAVE"){
			
			this->myLibrary.set_db_filename(user_input.at(1));
			try{
				this->myLibrary.write_media();
			}catch(...){
				this->myInterface.error("Le fichier n'a pas pu été cré.");
			}
			
		}

		else if(command == "LOAD"){

			//before loading a new dabatase, we should save changes to the
			// curent one.
			this->myLibrary.write_media();
			this->myInterface.print("La base des donnés a été sauvegardée.");


			string original_filename = this->myLibrary.get_db_filename();
			string original_user_filename = this->Users.get_db_filename();
			this->myLibrary.set_db_filename(user_input.at(1));

			try{
				 this->myLibrary.load_media();
				 this->myInterface.print("Le fichier a été chargé.");

			}catch(exception e){
				this->load_my_database(original_filename,original_user_filename);
			}
		}

		else if(command == "DELETE"){

			int id = 0;
			try{
				id = stoi(user_input.at(1));
				if(this->myLibrary.delete_by_id(id)){
					this->myInterface.print("Le média a été éfacé.");
				}
				else{
					this->myInterface.print("Aucune média trovué avec l'id fourni.");
				}
			}catch(...){
				this->myInterface.error("L'identifiant fourni n'est pas valable");
			}
		}

		else if(command == "SHOW"){

			int id = 0;
			try{
				id = stoi(user_input.at(1));
				if(!this->myLibrary.show_media_by_id(id)){
					this->myInterface.print("Aucune média trovué avec l'id fourni.");
				}
			}catch(...){
				this->myInterface.error("L'identifiant fourni n'est pas valable");
			}
		}

		else if (command == "SEARCH"){
			if(this->myLibrary.search_by_string(user_input.at(1))){
			}
			else{
				this->myInterface.print("Aucune média a été trouvé. Les filtres des recherche on été éfacées.");
			}
		}
	}while(command != "BYE");

	this->myInterface.goodbye();
	//NT: when the program is closed, the destructor of myLibrary will be called.
	//It will try to write all media into a file
}
