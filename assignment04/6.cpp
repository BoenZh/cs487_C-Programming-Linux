#include <iostream>
using namespace std;

int recursionSum(int a[]){
int size;
size=(sizeof(a[])/sizeof(*a[]))-1;
return recursionSum(int a[],size);
}

int recursionSum(int a[],int size){
if(size<0)
return 0;
else{
return (recursionSum(a[],size-1)+a[size]);

}
}

int main() {
	int num =0;
	
	num=sum(1,2);
	int a[5]={1,2,3,4,5};
	num=recursionSum(a); 
	cout << a<<endl;

	return 0;
}
