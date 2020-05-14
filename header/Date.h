#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>
#include <vector>


using namespace std;

class Date{

private:
	// unsigned year;
	// unsigned month;
	// unsigned day;
	// unsigned hour;
	// unsigned minutes;
	// unsigned seconds;

	vector<unsigned> myDate{0,0,0,0,0,0};

public:
	Date();


	//setters

	void set_date(vector<unsigned> myDate){this->myDate=myDate;}
	// void set_year(unsigned year){this->year=year;}
	// void set_month(unsigned month){this->month=month;}
	// void set_day(unsigned day){this->day=day;}
	// void set_hour(unsigned hour){this->hour=hour;}
	// void set_minutes(unsigned minutes){this->minutes=minutes;}
	// void set_seconds(unsigned seconds){this->seconds=seconds;}

	//getters
	vector<unsigned> get_date(){return this->myDate;} 
	// unsigned get_year(){return this->year;}
	// unsigned get_month(){return this->month;}
	// unsigned get_day(){return this->day;}
	// unsigned get_hour(){return this->hour;}
	// unsigned get_minutes(){return this->minutes;}
	// unsigned get_seconds(){return this->seconds;}


	//other functions
	void update();
	bool later(Date d);
	void from_string(string myDate);
	string to_string();
};

#endif