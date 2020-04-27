#include <iostream>
using namespace std;
#include "Review.h"

int main(){

	Media *m;
	m = new Review();
	cout << m->to_string() << endl;
	delete m;
	return 0;
}