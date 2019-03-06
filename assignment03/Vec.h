//by boen zhang, assignment 3
#include <string>
using namespace std;
class Vec{
	public:
		double x;
		double y;
		double z;
		Vec();
		Vec(double);
		Vec(double,double,double);
		double length();
		void normalize();
		double dot(Vec);
		double angle(Vec);
};

