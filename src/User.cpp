#include "User.h"
#include <typeinfo>

unsigned User::user_nextID = 0;

User::User(){
  this->init(this->user_nextID,"", "",false);
	this->user_nextID++; // increment the counter of IDs
}

User::User(string login, string password,bool admin){
  this->init(this->user_nextID,login,password,admin);
  this->user_nextID++;
}

User::User(vector<string> attributs){
	int readID = stoi(attributs.at(0));
  bool readAdmin = false;
	// we check if the id received is greater or equal  than the number of instances
	// already existent. In this case, we have to correct the couting of IDs
	if(readID >= this->user_nextID){
		this->user_nextID = readID + 1;
	}

  if(attributs.at(3) == "1"){
    readAdmin = true;
  }
  else{
    readAdmin =  false;
  }

	this->init(readID,attributs.at(1),attributs.at(2),readAdmin);
}

void User::init(unsigned id, string login,string password,bool admin){
    this->set_id(id);
    this->set_login(login);
    this->set_password(password);
    this->admin = admin;
  }

string User::get_string_from_user(){
	cin.clear();
	string option;

	getline(cin,option);
	while (option.length()==0 ){
            getline(cin, option);
    }

    return option;
}

string User::to_string(){
  string is_admin;

  if(this->admin){is_admin="1";} else{is_admin="0";}

  return std::to_string(get_id()) + "," + get_login() + "," + get_password()+ "," + is_admin;

}
void User::show_info(){
  cout << "ID: " << this->get_id() << "\t" << "Login: " << this->get_login() << endl;
  // cout << "Password: " << this->get_password() << endl;
}

void User::set_info(){
  cout << "Choisissez un pseudo: ";
  this->set_login(this->get_string_from_user());

  cout << "Entrez le mot de passe: ";
  this->set_password(this->get_string_from_user());
}
