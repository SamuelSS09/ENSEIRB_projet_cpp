#include "UserController.h"

char c_delimiter = ',';

UserController::UserController(string users_database){
  this->db.set_filename(users_database);
}

UserController::~UserController(){

  vector<string> lines;
  for (long unsigned int i=0; i<this->users.size(); i++){
    lines.push_back(users.at(i).to_string());
  }

  try{
		this->db.write_database(lines);
	}catch(...){

	}
}

void UserController::read_users(){
  vector<string> user_string = this->db.read_database();
  for (long unsigned int i=0; i<user_string.size(); i++){
    vector<string> attributs = helper::split_string(user_string.at(i),c_delimiter);
    User u(attributs);
    this->add_user(u);
  }
}


void UserController::write_users(){
  vector<string> lines;
  for(long unsigned int i=0; i < this->users.size(); i++){
    lines.push_back(users.at(i).to_string());
  }
  this->db.write_database(lines);
}

void UserController::add_user(User user){
    this->users.push_back(user);
}

bool UserController::validate_username(string user_string){
  bool validLogin = false;
  for (long unsigned int i=0; i<this->users.size(); i++){
    if (users.at(i).get_login()==user_string){
        validLogin = true;
    }
  }
  return validLogin;
}

bool UserController::validate_password(string user_string){
  bool validPassword = false;
  for (long unsigned int i=0; i<this->users.size(); i++){
    if (users.at(i).get_password()==user_string){
      this->users.at(i).set_admin(true);
      validPassword = true;
    }
  }
  return validPassword;
}
