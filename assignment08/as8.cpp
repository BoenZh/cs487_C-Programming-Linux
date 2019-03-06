#include <iostream>
#include <vector>
using namespace std;


int main(){
  vector<bool> v(10001,true);

  for(int i=0;i<10001;i++){
    if(i==1||i==2||i==3||i==5||i==7)
      NULL;
      else if(i%2==0||i%3==0||i%4==0||i%5==0||i%6==0||i%7==0||i%8==0||i%9==0){
        v[i]=false;
      }//end of else
  }//end of for loop

    for(int i=2;i<=10000;i++){
      if(v[i]==true){
        cout<<i<<" is a prime"<<endl;
      }
    }

return 0;

}
