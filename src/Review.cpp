#include "Review.h"

Review::Review(){
	editor = "";
}

Review::Review(unsigned id, string title,string author, int publishingYear, int numberOfPages, string summary,string collection,string editor, vector<string>articles)
: 	Book(id,title,author,publishingYear,numberOfPages,summary,collection) {
	this-> set_editor(editor);
	this-> set_articles(articles);
}

string Review::to_string(){
	return "Review: voilà";
}
