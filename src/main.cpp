#include <iostream>
using namespace std;
#include "Media.h"

int main(){

	Media *m = new Media();
	cout << m->to_string() << endl;
	return 0;
}