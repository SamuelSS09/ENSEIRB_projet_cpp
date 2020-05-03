#include "Book.h"
// #include "helper.h"


const string class_index = "0";

Book::Book():Media(){
	this->init(0,0,"","");
}

void Book:: init (int publishingYear, int numberOfPages, string summary,string collection){
	this->set_publishing_year(publishingYear);
	this->set_number_of_pages(numberOfPages);
	this->set_summary(summary);
	this->set_collection(collection);
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

	//replace class index
	int position_at_str = 0;
	int length_of_char = 1;
	s.replace(position_at_str,length_of_char,class_index);

	//continue to build string
	s 	     = s + std::to_string(get_publishing_year()) + "," + std::to_string(get_number_of_pages()) + ",";
	s   	 = s + get_summary() + "," + get_collection();
	return s;
}
