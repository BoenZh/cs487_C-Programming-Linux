#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

class info{
public:
  double x;
  double y;
  double z;
  double HDnum;
  double mag;
  double id;
  info(){
    x=0;
    y=0;
    z=0;
    HDnum=0;
    mag=0;
    id=0;
  }

  info(double x1,double y1,double z1,double Hdnum1,double mag1,double id1){
    x=x1;
    y=y1;
    z=z1;
    HDnum=Hdnum1;
    mag=mag1;
    id=id1;
  }

  void toString(){
    cout<<"x= "<<x<<" y= "<<y<<" z= "<<z<<" HD number= "<<HDnum<<" magnitude= "<<mag<<" identifier= "<<id<<endl;
  }


};


bool readtxt(string a){
  string name;
  string star="";
  star =a;
  double data[5];
  double x;
  double y;
  double z;
  double HDnum;
  double mag;
  double id;
  info temp;
  string want;
  double number=144;


  list<double> val;

  string line="";
  ifstream infile("stars.txt");

  map<double,info> mymap;
  multimap<string,info> mymap2;



  while(getline(infile,line)){

    stringstream ss(line);

    ss>>data[0]>>data[1]>>data[2]>>data[3]>>data[4]>>data[5];
    temp=info(data[0],data[1],data[2],data[3],data[4],data[5]);
    //temp.toString();
    mymap[data[3]]=temp;

    if(ss.peek() !=-1){
      ss>>name;
      mymap2.insert(make_pair(name,temp));
    }

    //cout<<temp.x<<" "<<temp.y<<" "<<temp.z<<" "<<temp.HDnum<<" "<<temp.mag<<" "<<temp.id<<endl;

  }

  cout<<"you want to search by name or id number(if search by name press 0, else press 1):"<<endl;
  cin>>want;
  if(want=="0"){
    cout<<"please enter the star name: "<<endl;
      cin>>want;

      mymap[number].tostring();




  }
  else{
    cout<<"please enter the star's id number: "<<endl;
    cin>>number;
    mymap[number].toString();

  }








  return true;
}




int main(){
readtxt("aaa");


  return 0;
}
