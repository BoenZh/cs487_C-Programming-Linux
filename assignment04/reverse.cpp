#include <iostream>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
using namespace std;

void reverse(int a[]){
	int size;
	size=(sizeof(a)/sizeof(*a));
	int temp[size];
	cout<<size<<endl;
	
	for(int i=0;i<size;i++){
		temp[size-1-i]=a[i];
	}
	for(int i=0;i<size;i++){
		a[i]=temp[i];
	}

}


int main(){
	int a[]={1,2,3,4,5,6,7,8,9,10};
	reverse(a);
	cout<<a[7];

	return 0;
}
