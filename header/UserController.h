#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "User.h"
#include "Database.h"
#include "helper.h"

using namespace std;

class UserController {
private:
  vector<User> users;
  Database db;

public:
  //Contsructors
  UserController(){};
  UserController(string users_database);

  //Destructors
  ~UserController();

  //Setters
  void set_db_filename(string filename){this->db.set_filename(filename);}

  //getters
  string get_db_filename(){return this->db.get_filename();}

  //Other functions
  void read_users();
  void write_users();
  void add_user(User user);
  // bool validate_username(string user_string);
  // bool validate_password(string user_string, string password_string);
  User login(User u);


  bool set_user_as_admin(string user_login);
  bool delete_user_by_id(int user_id);
  void list_users();
  bool update_mydb();
};

#endif
