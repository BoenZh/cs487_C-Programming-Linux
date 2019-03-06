#include <iostream>
using namespace std;
int sum(int a,int b){
	return a+b;
}
int sum(int a,int b,int c){
	return a+b+c;
}
int sum(int a, int b,int c,int d){
	return a+b+c+d;
}

int sum(int a[]){
	int size=0;
	int sum=0;
	size=(sizeof(a)/sizeof(*a);
	for(int i=0;i<size;i++){
	sum=sum+a[i];
	}
}













int main() {
	int num =0;
	
	num=sum(1,2);
	
	
	cout << num<<endl;

	return 0;
}
