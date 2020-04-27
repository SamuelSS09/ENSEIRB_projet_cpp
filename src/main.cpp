#include <iostream>

#include "Database.h"
#include "Review.h"

using namespace std;

int main(){

//Check if pointers as return from func
	Database d = Database();
	vector<Media*> m = d.read_database();

	cout << m.at(0)->to_string() << endl;
	cout << m.at(1)->to_string() << endl;
	return 0;

	// Database d("database/media_datdabase.txt");
	// cout << d.check_file() << endl;
	// return 0;


 //Check polymorphism and abstract class
	// Media *m;
	// m = new static Review();
	// cout << m->to_string() << endl;
	// delete m;
	// return 0;
}