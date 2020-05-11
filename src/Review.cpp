#include "Review.h"
// const string class_index = "1";

Review::Review() : Book() {
	class_index = 2;
}

void Review::init(string editor, std::vector<string> articles){
	this-> set_editor(editor);
	this-> set_articles(articles);
	this-> class_index = 2;
}

Review::Review(string title,string author, int publishingYear, int numberOfPages, string summary,string collection,string editor, vector<string>articles)
: 	Book(title,author,publishingYear,numberOfPages,summary,collection) {
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

	string s   = book + "," + this->get_editor();

	for (long unsigned int i = 0; i < this->articles.size();i++){
		s = s + "," + articles.at(i);
	}

	return s;
}

void Review::show_info(bool detailed){
	Book::show_info(detailed);
	if(detailed){
		cout << "Editeur: " << this->get_editor() << endl;
		for(long unsigned int i = 0 ; i < this->articles.size() ; i++){
			cout << "Article " << i + 1 << ": " << articles.at(i) << endl;
		}
	}
}

void Review::set_info(){
	Book::set_info();
	cout << "Insérer le nom de l'editeur: ";
	this->set_editor(this->get_string_from_user());

	vector<string> tempArticles;
	string article;

	while(true){
		cout << "Insérer une article, ou insérer <<quitter>> pour finir: ";
		article = this->get_string_from_user();

		if(article != "quitter"){
			tempArticles.push_back(article);
		}

		else{
			break;
		}
	}

	this->set_articles(tempArticles);

}
