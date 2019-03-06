#include <iostream>
using namespace std;
 
 void printArray(int a[]){
 int size;
 size=(sizeof(a)/sizeof(*a));
 cout<<size;
 for(int i=0;i<size-1;i++){
 cout<<a[i]<<",";
 }
 cout<<a[size-1];
 
 
 }
 
 int main(){
 int a[5]={1,2,3,4,5};

 int size=0;
 
 printArray(a);
 
 return 0;
 
 }
