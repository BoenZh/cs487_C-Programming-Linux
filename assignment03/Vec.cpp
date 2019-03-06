//by boen zhang, Assignment3

#include <iostream>
using namespace std;
#include "Vec.h"
#include <math.h>

double x;
double y;
double z;



Vec::Vec(){
	x=0;
	y=0;
	z=0;
}
Vec::Vec(double a){
	x=a;
	y=a;
	z=a;
}
Vec::Vec(double a,double b,double c){
	x=a;
	y=b;
	z=c;
}

double Vec::length(){
	return sqrt(x*x+y*y+z*z);
}//return the length of vec


void Vec::normalize(){
	if(x!=0)
		x=x/x;
	if(y!=0)
		y=y/y;
	if(z!=0)
		z=z/z;
}//set all value to 1, if its 0 do nothing

double Vec::dot(Vec b){
	return (x*b.x+y*b.y+z*b.z);
}

double Vec::angle(Vec b){
	return (acos(dot(b))/(length()*b.length()));
}//return the angle between to vec






