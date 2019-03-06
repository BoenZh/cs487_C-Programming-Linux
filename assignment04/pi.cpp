#include <iostream>
using namespace std;

double pi(int i){
	double x=rand() %1001;
	x =x/1000;
	double y=rand() %1001;
	y=y/1000;

	int check=0;
	for(int a=0;a<i;a++){
		if(sqrt((x*x)+(y*y)) <1.0)
			check++;

		x=rand() % 1001;
		x=x/1000;
		y=rand() %1001;
		y=y/1000;
	}
	return (4.0 * check)/(double)i;
}
