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

bool UserController::validate_password(string user_string, string password_string){
  bool validPassword = false;
  for (long unsigned int i=0; i<this->users.size(); i++){
    if ((users.at(i).get_password()==password_string) && (users.at(i).get_login()==user_string)){
      validPassword = true;
    }
  }
  return validPassword;
}

  bool UserController::validate_admin(string user_string, string password_string){
    for (long unsigned int i=0; i<this->users.size(); i++){
      if ((users.at(i).get_password()==password_string) && (users.at(i).get_login()==user_string)){
        return this->users.at(i).get_admin();
      }
    }
  }

  void UserController::set_user_as_admin(){

  }

  bool UserController::delete_user(int user_id){
    bool isFound = false;
  	for(long unsigned int i=0; i < this->users.size(); i++){
  		if (users.at(i).get_id() == user_id){
  			this->users.erase(users.begin()+i);
  			isFound=true;
  		}
  	}
  	return isFound;
  }

  void UserController::list_users(){
    for (long unsigned int i=0; i<this->users.size(); i++){
      this->users.at(i).show_info();
    }
  }

bool UserController::update_mydb(){
  if( !(this->db.is_updated()) ){
    this->db.read_database();
    return true;
  }
  return false;
}
