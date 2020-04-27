#include <iostream>
using namespace std;
#include "Cd.h"

int main(){

	Cd d = Cd("hoje","eu","vou",0,"na",17);
	cout << d.to_string() << endl;
	return 0;
}