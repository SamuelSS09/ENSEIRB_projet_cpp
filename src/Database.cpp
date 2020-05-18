#include "Database.h"
#include <iostream>

bool Database::is_updated() throw (std::exception) {


	ifstream ifs(this->filename,std::ios::in);
	Date readDate;
	string line;   					// represents each line of the file
	if(ifs.is_open()){ 		       // check if file is correctly openned
		getline(ifs,line);
		readDate.from_string(line); //construct the date
		ifs.close();
	}
	else{
		throw std::exception();
	}

	return this->date.later(readDate);
}

vector<string> Database::read_database() throw (std::exception) {

	ifstream ifs(this->filename,std::ios::in);

	vector<string> strings;
	string line;   					// represents each line of the file
	if(ifs.is_open()){ 		// check if file is correctly oppened
		while(getline(ifs,line)){ // until the end of the file
			strings.push_back(line);
		}
		ifs.close();

	}

	else{
		// fileManager.close();
		throw std::exception();
	}

	if(strings.size() > 0){
		this->date.from_string(strings.at(0)); //construct the date
		strings.erase(strings.begin());          //erase the date line
	}

	 return strings;
}

void Database::write_database(vector<string> lines) throw (std::exception) {

	this->date.update(); // writes the database using the current date.

	lines.insert(lines.begin(), this->date.to_string()); // write the date at first element

	ofstream ofs(this->filename,std::ios::out);
	if(ofs.is_open()){

		for(long unsigned int i = 0; i < lines.size() - 1; i++){
			ofs << lines.at(i) << endl;
		}
		if(lines.size() > 0 ){ // to avoid  a blank line at end of file
			ofs << lines.back() << "\n";
		}

		ofs.close();
	}

	else{
		throw std::exception();
	}

}
