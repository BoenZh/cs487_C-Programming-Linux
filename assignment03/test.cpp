//by boen zhang
//assignment 4
//1/11/2017

#include <iostream>
#include "Vec.h"
using namespace std;

int main(){
	Vec a();
	Vec b(1.5);
	Vec c(1.0,1.2,3.1);

	cout << b.length()<<endl;
	cout << b.dot(c)<<endl;
	cout << b.angle(a);

	return 0;
}
