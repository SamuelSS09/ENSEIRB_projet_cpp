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

	vector<string> user_input = this->myInterface.get_user_login();
	command = user_input.at(0);
	bool isAdmin = false;
	if(command == "M'IDENTIFIER"){
		this->myInterface.print("Entrez le nom d'utilisateur: ");
		if (this->Users.validate_username(this->myInterface.get_string_from_user())){
			this->myInterface.print("Entrez le mot de passe: ");
			if (this->Users.validate_password(this->myInterface.get_string_from_user())){
				this->myInterface.print("Identification réussie!");
				isAdmin = true;
			}
		}
		else{
			this->myInterface.error("Votre identification a échouché. Vous pouvez utiliser l'application comme client!");
		}
	}
	else if(command == "M'INSCRIRE"){
		User u;
		u.set_info();
		this->Users.add_user(u);
		u.set_admin(true);
		if (u.get_admin()){
			this->myInterface.print("Vous êtes bien inscrit. Vous pouvez utiliser l'application comme administrateur!");
			isAdmin = true;
		}
		else{
			this->myInterface.error("Votre inscription a échouchée. Utilisez l'application comme client!");
		}
	}
	else if(command == "CLIENT"){
		this->myInterface.print("Vous pouvez utiliser l'application comme un client.");
	}

	do{

		user_input = this->myInterface.get_user_command(isAdmin);
		command = user_input.at(0);
		if(command == "CLEAR"){
			this->myLibrary.clear_search();
			this->myInterface.print("L'historique de recherche a été effacé.");
		}

		else if(command == "LIST"){
			// this->myInterface.list_media(this->myLibrary.get_medias());
			this->myLibrary.list_media();
		}

		else if((command == "RESET") && (isAdmin)){
			this->myLibrary.clear_medias();
			this->myInterface.print_reset();
		}



		else if((command == "ADD") && (isAdmin)){

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

		else if((command == "SAVE") && (isAdmin)){

			this->myLibrary.set_db_filename(user_input.at(1));
			try{
				this->myLibrary.write_media();
			}catch(...){
				this->myInterface.error("Le fichier n'a pas pu été crée.");
			}

		}

		else if((command == "LOAD") && (isAdmin)){

			//before loading a new dabatase, we should save changes to the
			// curent one.
			this->myLibrary.write_media();
			this->myInterface.print("La base de données a été sauvegardée.");


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

		else if((command == "DELETE") && (isAdmin)){

			int id = 0;
			try{
				id = stoi(user_input.at(1));
				if(this->myLibrary.delete_by_id(id)){
					this->myInterface.print("Le média a été éfacé.");
				}
				else{
					this->myInterface.print("Aucun média trouvé avec l'id fourni.");
				}
			}catch(...){
				this->myInterface.error("L'identifiant fourni n'est pas valable!");
			}
		}

		else if(command == "SHOW"){

			int id = 0;
			try{
				id = stoi(user_input.at(1));
				if(!this->myLibrary.show_media_by_id(id)){
					this->myInterface.print("Aucun média trouvé avec l'id fourni.");
				}
			}catch(...){
				this->myInterface.error("L'identifiant fourni n'est pas valable!");
			}
		}

		else if (command == "SEARCH"){
			if(this->myLibrary.search_by_string(user_input.at(1))){
				this->myLibrary.list_media();
			}
			else{
				this->myInterface.print("Aucun média a été trouvé. Les filtres de recherche ont été effacés.");
			}
		}
	}while(command != "BYE");

	this->myInterface.goodbye();
	//NT: when the program is closed, the destructor of myLibrary will be called.
	//It will try to write all media into a file
}
