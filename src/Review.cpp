#include "Review.h"

Review::Review():Book(){
	editor = "";
	articles = {};
}

Review::Review(unsigned id, string name,string title,string author, int publishingYear, int numberOfPages, string summary,string collection,string editor, vector<string>articles)
: 	Book(id,name,title,author,publishingYear,numberOfPages,summary,collection) {
	this-> set_editor(editor);
	this-> set_articles(articles);
}

string Review::to_string(){
	return "Review: voilà";
}
