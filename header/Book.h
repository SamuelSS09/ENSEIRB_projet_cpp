#ifndef BOOK_H
#define BOOK_H

#include "Media.h"

using namespace std;

// READ ME -----------------------------------------------------------------

// -------------------------------------------------------------------------

class Book: public Media {
private:
	int publishingYear;
	int numberOfPages;
	string summary;
	string collection;
public:
	//Constructors
	Book();
	Book(string title,string author, int publishingYear, int numberOfPages, string summary,string collection);
	Book(vector<string> attributs);
	// Destructors
	// Class does not have pointers, so no memory leak
	// is likely. Therefore, no need to change the default
	// destructor.

	// LINE WAS USED FOR DEBUG: ~Book(){cout << "destruit" << endl;}

	//Getters
	string get_summary(){return this->summary;}
	int get_publishing_year(){return this->publishingYear;}
	string get_collection(){return this->collection;}
	int get_number_of_pages(){return this->numberOfPages;}


	//Setters
	void set_summary(string summary){this->summary=summary;}
	void set_publishing_year(int publishingYear){this->publishingYear=publishingYear;}
	void set_number_of_pages(int numberOfPages){this->numberOfPages=numberOfPages;}
	void set_collection(string collection){this->collection=collection;}
	void init (int publishingYear, int numberOfPages, string summary,string collection);

	//Other functions
	virtual string to_string();
	virtual void show_info(bool detailed);
	virtual void set_info();
};
#endif
