#include "Book.h"

Book::Book():Media(){
	summary = "";
	publishingYear = 0;
	numberOfPages = 0;
	collection ="";
}

Book::Book(unsigned id, string name,string title,string author, int publishingYear, int numberOfPages, string summary,string collection)
: Media(id,name,title,author) {
	this->set_summary(summary);
	this->set_publishing_year(publishingYear);
	this->set_number_of_pages(numberOfPages);
	this->set_collection(collection);
}

string Book::to_string(){
	return "Book: je suis une string quoi!";
}
