//by boen zhang
//csci 487
//assignment 11
//1/25/2017

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double getlum(double r,double g,double b){

  return 0.2126*(r/255.0)+0.7152*(g/255.0)+0.0722*(b/255.0);
}

string getstar(int a){
  int temp;
  string result;
  temp=a/150;

  if(temp>99){
    for(int i=0;i<100;i++){
      result+="*";
    }
    result+="+";
  }


  else{
  for(int i=0;i<temp;i++){
    result+="*";
  }
}//end of else
  return result;
}//end of getstar




bool readtga(string a){
  double r;//data for r
  double g;//data for g
  double b;//data for b
  double temp;
  short height;
  short width;
  int pixel;//data for bits per pixel
  double averageR;
  double averageG;
  double averageB;
  string name=a;//the file name
  int total;//the data height*width
  double min=0.5;//min lum value
  double max=0.5;//max lum value





  int* arr=new int[60];
  unsigned char c;
  ifstream infile("flower.tga",ios :: binary);

  infile.seekg(12);
  infile.read(reinterpret_cast<char *>(&height),sizeof(height));
  //cout<<"the height"<<height<<endl;

  infile.read(reinterpret_cast<char *>(&width),sizeof(width));
  //cout<<"width"<<width<<endl;

  infile.read(reinterpret_cast<char *>(&c),sizeof(c));
  pixel=(int)c;
  //cout<<"pix"<<pixel<<endl;

  total=height*width;



  infile.seekg(18);
  while(!infile.eof()){
    infile.read(reinterpret_cast<char *>(&c),sizeof(c));
    r=(int)c;
    infile.read(reinterpret_cast<char *>(&c),sizeof(c));
    g=(int)c;
    infile.read(reinterpret_cast<char *>(&c),sizeof(c));
    b=(int)c;
    temp=getlum(r,g,b);
    infile.read(reinterpret_cast<char *>(&c),sizeof(c));

    averageR+=r;
    averageG+=g;
    averageB+=b;


    if(temp<min)
    min=temp;
    if(temp>max)
    max=temp;

    for(double i=1.0;i<61.0;i++){
      if(temp>=(i-1.0)/60.0 && temp<i/60.0)
        arr[(int)i-1]++;//push to the right position in the array for histogram
    }//end of for loop
  }//end of read in data while loop
  averageR /=total;
  averageG /=total;
  averageB /=total;

  cout<<"File name: "<<name<<endl;
  cout<<"Image format: Truevision TGA"<<endl;
  cout<<"Image size (width X height): "<<width<<" X "<<height<<endl;
  cout<<"Bits per pixel: "<<pixel<<endl;
  cout<<"Luminace range (min-max): "<<min<<"-"<<max<<endl;
  cout<<"Average pixel value (r,g,b):  ( "<<averageR<<", "<<averageG<<", "<<averageB<<")"<<endl;

  cout<<endl;
  cout<<"Luminance histogram"<<endl;
  cout<<"-----------------------------------------------------------------------------------------"<<endl;



  for(int i=0;i<60;i++){
    cout<<arr[i]<<" | "<<getstar(arr[i])<<endl;
  }



  return true;
}

int main(){
readtga("flower.tga");

}
