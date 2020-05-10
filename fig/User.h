#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

class User {

private:
	string login;
	string password;
	bool admin;

public:
	User();
	User(string login, string password, bool admin);
	User(vector<string> attributs);

	//getters
	bool is_admin(){return this->admin;}
	string get_password(return this->password;)
	string get_login(return this->login;)

	//setters
	void set_admin(bool admin){this->admin=admin;}
	void set_login(string login){this->login=login;}
	void set_password(string password){this->password=password;}

	//other functions
	
	//VIOLATION OF THE MVC. 

	void set_info(); //get information from the user to construct
	void get_info(); 
};

#endif