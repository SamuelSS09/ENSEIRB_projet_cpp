#ifndef REVIEW_H
#define REVIEW_H

#include "Book.h"
#include <vector>

// READ ME -----------------------------------------------------------------

// -------------------------------------------------------------------------

class Review: public Book {
private:
	string editor;
	vector<string> articles;
public:
	//Constructors
	Review();
	Review(unsigned id, string title,string author, int publishingYear, int numberOfPages, string summary,string collection,string editor, vector<string>articles);

	// Destructors
	// Class does not have pointers, so no memory leak
	// is likely. Therefore, no need to change the default
	// destructor.

	//Getters
	string get_editor(){return this->editor;}
	vector<string> get_articles(){return this->articles;}
	int get_number_of_articles(){return this->articles.size();}

	//Setters
	void set_editor(string editor){this->editor=editor;}
	void set_articles(vector<string> articles){this->articles=articles;}

	//Other functions
	string to_string();

};
#endif
