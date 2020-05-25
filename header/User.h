#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class User {

protected:
  static unsigned user_nextID;// counter for the unique id
  unsigned id;

  string login;
  string password;
  bool admin;


public:
  //Constructors
  User();
  User(string login, string password,bool admin);
  User(vector<string> attributs); // used to construct from file or from interface.


  //Destructors
  ~User(){};

  //getters
  unsigned get_id(){return this->id;}
  string get_login(){return this->login;}
  string get_password(){return this->password;}
  bool get_admin(){return this->admin;}

  //Setters
  //set id
  void set_id(unsigned id){this->id=id;}
  void set_login(string login){this->login=login;}
  void set_password(string password){this->password=password;}
  void set_admin(bool admin){this->admin=admin;}


    //Initialisation of attributs
    void init(unsigned id, string login,string password,bool admin);


  //Violation of the MVC, only here for the sake of simplicity.
	string get_string_from_user(); // function to obtain a single line inserted
								   // by the user in string format

  //other FUNCTIONS
  string to_string();
  void show_info();
	void set_info();
};

#endif
