// #include <iostream>

// #include "Database.h"
// #include "Review.h"
// #include <iostream>
// #include <sstream>      // std::istringstream


// using namespace std;

// std::vector<std::string> split_string(const std::string& s, char delimiter)
// {
//    std::vector<std::string> tokens;
//    std::string token;
//    std::istringstream tokenStream(s);
//    while (std::getline(tokenStream, token, delimiter))
//    {
//       tokens.push_back(token);
//    }
//    return tokens;
// }

// int test(){
// // Construct an Media object from file test
// 	string s = "to,no,quarto,po";
// 	vector<string> ss = split_string(s,',');
// 	for(string t: ss){
// 	cout<<t<<endl;
// }

// 	return 0;
// //Test if media *ges destroied
// 	// vector<Book*> b;
// 	// b.push_back(new Book());

// 	// delete b.at(0);
// 	// b.clear();
// 	// return 0;

// //Check if pointers as return from func
// 	// Database d = Database();
// 	// vector<Media*> m = d.read_database();

// 	// cout << m.at(0)->to_string() << endl;
// 	// cout << m.at(1)->to_string() << endl;
// 	// return 0;

// 	// Database d("database/media_datdabase.txt");
// 	// cout << d.check_file() << endl;
// 	// return 0;


//  //Check polymorphism and abstract class
// 	// Media *m;
// 	// m = new static Review();
// 	// cout << m->to_string() << endl;
// 	// delete m;
// 	// return 0;
// }

