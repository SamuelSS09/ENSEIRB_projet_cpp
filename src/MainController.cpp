#include "MainController.h"

MainController::MainController(string data_filename, string uc_filename){
	setlocale(LC_ALL, "french");
	this->load_my_database(data_filename,uc_filename);
	this->myInterface.hello();
	// this->myInterface.login();
}

void MainController::load_my_database(string filename, string uc_filename){

	this->myLibrary.set_db_filename(filename);
	this->myUc.set_db_filename(uc_filename);
	try{
		this->myLibrary.load_media();
		this->myUc.read_users();
		//AFICHER UNE MESSAGE
	}catch(exception e){
		this->myInterface.print_error_db();
	}
}

User MainController::login(){
	string command = "";
	User u;

	 do{
		vector<string> user_input = this->myInterface.get_user_login();
		command = user_input.at(0);
		// bool isAdmin = false;

		if(command == "LOGIN"){
			this->myInterface.print("Entrez le nom de l'utilisateur: ");
			u.set_login(this->myInterface.get_string_from_user());
			this->myInterface.print("Entrez le mot de passe: ");
			u.set_password(this->myInterface.get_string_from_user());
			if (this->myUc.validate_login(u)){
				this->myInterface.print("Identification réussie!");
				// validate if user is admin to manage the multiple commands
				if(this->myUc.validate_admin(u)){
					u.set_admin("true");
				}
			}
			else{
				this->myInterface.error("Vos coordonnées sont incorrects!");
				u.init(0,"","",false);
			}
		}

		else if(command == "SIGN-UP"){
			u.set_info();
			this->myInterface.print("Voulez-vous vous enregistrer comme admin?(Oui/Non)");
			if (this->myInterface.get_string_from_user()=="Oui"){
				this->myInterface.print("Vous êtes bien inscrit. Vous pouvez utiliser l'application comme administrateur!");
				u.set_admin(true);
				this->myUc.add_user(u);
				// isAdmin = true;
			}
			else if (this->myInterface.get_string_from_user()=="Non"){
				this->myInterface.print("Vous êtes bien inscrit. Vous pouvez utiliser l'application comme client!");
			}
			else{
				this->myInterface.error("Veuillez entrer une option valide!");
				u.init(0,"","",false);
			}
		}
		// else if(command == "CLIENT"){
		// 	this->myInterface.print("Vous pouvez utiliser l'application comme un client.");
		// }
	}while(u.get_login()=="");
	return u;
	this->myInterface.goodbye();
}

void MainController::start_program(){
	string command = "";
	bool isAdmin = this->login().get_admin();
	cout << "le login est: " << this->login().get_login() << endl;

	do{
		vector<string> user_input = this->myInterface.get_user_command(isAdmin);
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
			string original_user_filename = this->myUc.get_db_filename();
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
					this->myInterface.print("Le média a été effacé.");
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
		else if(command == "DELETE-ACCOUNT"){
			this->myUc.delete_user(this->login());
		}

		else if((command == "DELETE-USER") && (isAdmin)){

			int id = 0;
			try{
				id = stoi(user_input.at(1));
				if(this->myUc.delete_user_by_id(id)){
					this->myInterface.print("L'utilisateur a été effacé.");
				}
				else{
					this->myInterface.print("Aucun utilisateur trouvé avec l'id fourni.");
				}
			}catch(...){
				this->myInterface.error("L'identifiant fourni n'est pas valable!");
			}
		}

		else if(command == "LIST-USERS"){
			this->myUc.list_users();
		}

		else if((command == "ADMIN") && (isAdmin)){
			string user_name = user_input.at(1);
			if (this->myUc.set_user_as_admin(user_name)){
				this->myInterface.print("Opération réussie.");
			}
			else{
				this->myInterface.print("Opération a échouché.");
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

		// check for updates in the database
		if( this->myLibrary.update_mydb() || this->myUc.update_mydb() ){
			this->myInterface.print("La base des données a été mise à jour.");
		}
	}while(command != "BYE");

	this->myInterface.goodbye();
	//NT: when the program is closed, the destructor of myLibrary will be called.
	//It will try to write all media into a file
}
