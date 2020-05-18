#include "Date.h"
#include "helper.h"
// #include <iostream>

const char delimiter = ',';
const short mydate_size = 6;

Date::Date(){
	
}

void Date::update(){
	// get current date

	time_t now = time(0);

   tm *ltm = localtime(&now);

   this->myDate.at(0) = 1900 + ltm->tm_year;
   
   this->myDate.at(1) = 1+ ltm->tm_mon;

   this->myDate.at(2) = ltm->tm_mday;

   this->myDate.at(3) = ltm->tm_hour;

   this->myDate.at(4) = ltm->tm_min	;

   this->myDate.at(5) = 1+ ltm->tm_sec;


}


void Date::from_string(string myDate){
	vector<string> myInfo = helper::split_string(myDate,delimiter);
	for(short i = 0; i < mydate_size ; i++){
		try{
			this->myDate.at(i) = stoi(myInfo.at(i));
		}catch(...){

		}
	}
}




string Date::to_string(){
	string dateString;
	for(short i = 0; i < mydate_size - 1 ; i++){
		dateString = dateString + std::to_string(this->myDate.at(i)) + ",";
	}

	dateString = dateString + std::to_string(this->myDate.back());

	return dateString;
}

bool Date::later(Date d){

	std::vector<unsigned> otherDate = d.get_date();

	for(short i = 0; i < mydate_size ; i++){
		if(this->myDate.at(i) > otherDate.at(i)){
			return true;
		}
	}
	return false;

}