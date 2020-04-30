#include "Review.h"
const string class_index = "1";

Review::Review() : Book() {
	editor = "";
}

void Review::init(string editor, std::vector<string> articles){
	this-> set_editor(editor);
	this-> set_articles(articles);
}

Review::Review(unsigned id, string title,string author, int publishingYear, int numberOfPages, string summary,string collection,string editor, vector<string>articles)
: 	Book(id,title,author,publishingYear,numberOfPages,summary,collection) {
	this->init(editor,articles);
}

Review::Review(vector<string> attributs)
: Book(attributs) {

	// vector to hold the articles
	vector<string> artc(attributs.begin() + 9 , attributs.end());
	
	this->init(attributs.at(8),artc);
}

string Review::to_string(){

	string book = Book::to_string();
	
	int position_at_str = 0;
	int length_of_char = 1;
	book.replace(position_at_str,length_of_char,class_index);

	string s    = book + "," + this->get_editor() + ",";

	for (int i = 0; i< this->articles.size() -1 ;i++){
		s = s + articles.at(i) + ",";
	}

	if(articles.size() > 0){ // avoid "," at the end
		s = s + articles.back();
	}

	return s;
}
