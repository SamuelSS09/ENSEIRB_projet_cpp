#include "UserController.h"

char c_delimiter = ',';

UserController::UserController(string users_database){
  this->db.set_filename(users_database);
}

UserController::~UserController(){
  vector<string> lines;
  for (long unsigned int i=0; i<this->users.size(); i++){
    lines.push_back(users.at(i)->to_string());
    delete this->users.at(i);//allocation of memory by pointer needs to be destroyed
  }
  this->users.clear();//it is used to remove/clear all elements of the vector,

  /*                    //it makes the 0 sized vector after removing all elements.
  try{
		this->db.write_database(lines);
		// cout << "Library: j'appelle mon destructeur, tout va bien!" << endl;
	}catch(...){
		//
	}*/
}
/*
void UserController::read_users(){
  vector<string> user_string = this->db.read_database();
  for (long unsigned int i=0; i<user_string.size(); i++){
    vector<string> attributs = helper::split_string(user_string.at(i),c_delimiter);
    for (long unsigned int j=0; j<this->users.size(); j++){
      if((attributs.at(1)!=users.at(j)->get_login()) && (attributs.at(2)!=users.at(j)->get_password())){
        User* u = new User();
        u->set_id(stoi(attributs.at(0)));
        u->set_login(attributs.at(1));
        u->set_password(attributs.at(2));
        this->add_user(u);
      }
    }
  }
}*/

void UserController::write_users(){
  vector<string> lines;
  for(long unsigned int i=0; i < this->users.size(); i++){
    lines.push_back(users.at(i)->to_string());
  }
  this->db.write_database(lines);
}

void UserController::add_user(User* user){
  if (user) {
    this->users.push_back(user);
  }
}

bool UserController::validate_login(string user_string){
  bool validLogin = false;
  for (long unsigned int i=0; i<this->users.size(); i++){
    if (users.at(i)->get_login()==user_string){
      validLogin = true;
    }
  }
  return validLogin;
}

bool UserController::validate_password(string user_string){
  bool validPassword = false;
  for (long unsigned int i=0; i<this->users.size(); i++){
    if (users.at(i)->get_password()==user_string){
      validPassword = true;
    }
  }
  return validPassword;
}
