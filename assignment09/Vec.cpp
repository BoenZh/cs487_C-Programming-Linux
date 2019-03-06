//by boen zhang
//assignment 9
//1/20/2017
#include "Vec.h"
using namespace std;

#include <cmath>

Vec::Vec() : x(0.0), y(0.0), z(0.0) {}

Vec::Vec(double a) : x(a), y(a), z(a) {}

Vec::Vec(double a, double b, double c) : x(a), y(b), z(c) {}

double Vec::length() const
{
  return sqrt( x*x + y*y + z*z );
}

void Vec::normalize()
{
  double len = length();
  if( len == 0.0 ) return;
  double scale = 1.0 / len;
  x *= scale;
  y *= scale;
  z *= scale;
}

double Vec::dot( Vec other ) const
{
  return (x * other.x + y * other.y + z * other.z);
}

double Vec::angle( Vec other ) const
{
  double thisLen = length();
  double otherLen = other.length();

  return acos( dot(other) / (thisLen * otherLen) );
}

Vec operator+(const Vec& b){

  Vec a(this->x+b.x,this->y+b.y,this->z+b.z);

return a;

}

Vec operator+=(const Vec& b){

  Vec a(this->x+b.x,this->y+b.y,this->z+b.z);

return a;
}

Vec operator-=(const Vec& b){

  Vec a(this->x+b.x,this->y+b.y,this->z+b.z);

return a;

}

Vec operator-(const Vec& b){

  Vec a(this->x+b.x,this->y+b.y,this->z+b.z);

return a;
}

Vec operator*(const Vec& b){

  Vec a(this->x*b.x,this->y*b.y,this->z*b.z);

return a;
}

Vec operator*=(const Vec& b){

  Vec a(this->x*b.x,this->y*b.y,this->z*b.z);

return a;
}

Vec operator*(double x){

  Vec a(this->x*x,this->y*x.y,this->z*x);

return a;
}

Vec operator*=(double x){

  Vec a(this->x*x.x,this->y*x.y,this->z*x);

return a;
}

bool operator==(const Vec& b){
  if(this->x==b.x&&this->y==b.y&&this->z==b.z)
  return true;
  else
  return false;
}

operator<<(){
  cout<<"this vector: "<<this->x<<" "<<this->y<<" "<<this->z<<endl;
}

int[] operator [](){
  int* a=new int[3];
  a[0]=this->x;
  a[1]=this->y;
  a[2]=this->z;

  return a;


}








int main(){

  return 0;
}
