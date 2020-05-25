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
  this->users.clear();

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

 
User UserController::login(User u){

  for( int i = 0; i< this->users.size() ; i++ ){

    if (( users.at(i).get_password()==u.get_password() ) && ( users.at(i).get_login()==u.get_login() )){

      return this->users.at(i);

    } 

  }

  return User();

}


bool UserController::set_user_as_admin(string user_login){

    for (long unsigned int i=0; i<this->users.size(); i++){
      if (users.at(i).get_login()==user_login){
        this->users.at(i).set_admin(true);
        return true;
      }
    }

    return false;
}


bool UserController::delete_user_by_id(int user_id){
  for(long unsigned int i=0; i < this->users.size(); i++){
    if (users.at(i).get_id() == user_id){
      this->users.erase(users.begin()+i);
      return true;
    }
  }
  return false;
}

  void UserController::list_users(){
    for (long unsigned int i=0; i<this->users.size(); i++){
      this->users.at(i).show_info();
    }
  }

bool UserController::update_mydb(){
  if( !(this->db.is_updated()) ){
    this->read_users();
    return true;
  }
  return false;
}
