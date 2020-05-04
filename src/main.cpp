#include <iostream>

#include "MainController.h"

using namespace std;


void test_multi_id(){


	Media* a = new Book();
	Media* b = new Review();
	Media* c = new Digital();

	cout << "id" << a->get_id() << endl;
	cout << "id" << b->get_id() << endl;
	cout << "id" << c->get_id() << endl;
	delete c;

	Media* d = new Digital();
	cout << "id" << d->get_id() << endl;

	Library l("database/media_database.txt");
	try{
		l.load_media();
	}catch(...){

	}
	Media *f = new Book("", "",0,0, "","");

	cout << "id: " << f->get_id() << endl;

}

void test_search_by_string(){
	Library l("database/media_database.txt");
	l.load_media();
}

void test_exception(){

	try{
		Database d("je_existe_pas.txt");
		vector<string> s = d.read_database();

	}catch(...){
		// cerr << s.size() << endl;
	}
	
}

void test_main_controller(){
	// test with: LOAD database/media_database.txt
	MainController m("database/media_database.txt");
	m.start_program();
}

void test_interface(){
	Interface i;
	std::vector<string> v = i.get_user_command();
}

void test_book_from_file(){
	Library m("database/media_database.txt");
	m.load_media();
	m.write_media();
	cout << m.get_medias().at(0)->to_string() << endl;
}

void test_vector_string_constructor(){
	vector<string> s;
	s.push_back("0");
	s.push_back("10");
	s.push_back("Sertão");
	s.push_back("Amado");

	s.push_back("44444");
	s.push_back("500");
	s.push_back("Bresil");
	s.push_back("Bresil ancienne");
	s.push_back("Editeur abs");
	s.push_back("article 1");
	s.push_back("article 2");

	Review b(s);
	cout << b.to_string() << endl;
	// cout << b.get_articles().size() << endl;
}

int main(){
	//test_multi_id();
	//test_exception();
	test_main_controller();
	//test_interface();
	//test_search_by_string();
		

	return 0;
//Test if media *ges destroied
	// vector<Book*> b;
	// b.push_back(new Book());

	// delete b.at(0);
	// b.clear();
	// return 0;

//Check if pointers as return from func
	// Database d = Database();
	// vector<Media*> m = d.read_database();

	// cout << m.at(0)->to_string() << endl;
	// cout << m.at(1)->to_string() << endl;
	// return 0;

	// Database d("database/media_datdabase.txt");
	// cout << d.check_file() << endl;
	// return 0;


 //Check polymorphism and abstract class
	// Media *m;
	// m = new static Review();
	// cout << m->to_string() << endl;
	// delete m;
	// return 0;
}