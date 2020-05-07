#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <vector>
#include <string>
#include <exception>

using namespace std;
//should include all classes from the root of the inheritance tree

// READ ME -----------------------------------------------------------------
// This class has been conceived to read a database in which each file 
// contains a table of a type of media.
	
// BRAINSTORM
// we have many different types of objects to construct: Users, Media, and in Media
// we we have Books, DVDs, etc.
// 
// useful to append vectors to vectors: https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector
// 
// Problem 1: A: single file vs B: multi file for media
// A: easier to implement, return all the objects at once. 
// B: makes more sense, because the data beeing read is different. Problem for the writing part.
// CHOICE: A
//
// Problem 2: A: read the file and construct objects VS B: return a vector of strings and later construc obj
// A: less loops in the code, since we need only one to read and create the objects. 
// But code becomes more procedural and less modulariazed, therefore changes are harder
// B: more loops than before. Code is less reutilizable.
// CHOICE : B

// -------------------------------------------------------------------------

class Database {

private: 
	string filename;

public: 
	//Constructors
	Database(){};
	Database(string filename){this->set_filename(filename);}

	//getters
	string get_filename(){return this->filename;}

	//setters
	void set_filename(string filename){this->filename=filename;}

	//other functions
	vector<string> read_database() throw (std::exception);

	void write_database(vector<string> lines) throw (std::exception);


};

#endif