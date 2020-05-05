#include "Book.h"
// #include "helper.h"



Book::Book():Media(){
	this->init(0,0,"","");
}

void Book:: init (int publishingYear, int numberOfPages, string summary,string collection){
	this->set_publishing_year(publishingYear);
	this->set_number_of_pages(numberOfPages);
	this->set_summary(summary);
	this->set_collection(collection);
	this->class_index = 1;
}

Book::Book(string title,string author, int publishingYear, int numberOfPages, string summary,string collection)
: Media(title,author) {
	this->init(publishingYear, numberOfPages , summary , collection);
}

Book::Book(vector<string> attributs) 
: Media(attributs) {
	this->init(stoi(attributs.at(4)),stoi(attributs.at(5)),attributs.at(6),attributs.at(7));
}

// Methode 1: weird
// Book::Book(vector<string> attributs)
// : Book(stoi(attributs.at(0)),attributs.at(1),attributs.at(2),attributs.at(3),stoi(attributs.at(4)),stoi(attributs.at(5),attributs.at(6),attributs.at(7))



string Book::to_string(){
	string s = Media::to_string();

	s 	     = s + "," + std::to_string(get_publishing_year()) + "," + std::to_string(get_number_of_pages()) + ",";
	s   	 = s + "," + get_summary() + "," + get_collection();
	return s;
}

void Book::show_info(bool detailed){
	Media::show_info(detailed);
	if(detailed){
		cout << "Année de publication: " << this->get_publishing_year() << endl;
		cout << "Nombre de pages : " << this->get_number_of_pages() << endl;
		cout << "Résumé: " << this->get_summary() << endl;
		cout << "Collection: " << this->get_collection() << endl;
	}	
}

void Book::set_info(){	

	Media::set_info();

	cout << "Inserer l'année de publication: ";
	this->set_publishing_year(this->get_int_from_user());

	cout << "Inserer le nombre de pages: ";
	this->set_number_of_pages(this->get_int_from_user());

	cout << "Inserer le résumé du livre: ";
	this->set_summary(this->get_string_from_user());

	cout << "Inserer la collection dont le livre appartient: ";
	this->set_collection(this->get_string_from_user());

}