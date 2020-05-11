#include "Database.h"


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
	 return strings;
}

void Database::write_database(vector<string> lines) throw (std::exception) {

	//ofstream ofs(this->filename,std::ios::out);
	ofstream ofs(this->filename, std::ios_base::app | std::ios_base::out);//avoid overwritting file
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
