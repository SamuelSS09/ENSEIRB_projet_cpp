#include "Review.h"

Review::Review(){}

Review::Review(string name,string title,string author, int publishingYear, int numberOfPages, string summary,string collection,string editor, vector<string>articles)
: 	Book(name,title,author,publishingYear,numberOfPages,summary,collection) {
	this-> set_editor(editor);
	this-> set_articles(articles);
}

string Review::to_string(){
	return "Review: voilà";
}