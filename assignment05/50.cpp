//by boen zhang as5  1/13/2017
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;
using std::string;

//problem 6.50
int tripleByValue(int a){
  return a*3;
}

int tripleByreference(int a){
  return tripleByValue(a);
}

//problem 6.51: recursive function onece it start, you can not control every indiviude elements
// also if you forget to setup the base case or the base case was not right the program will never end.

//problem 6.52
double sum(double a,double b ){
  return a+b;
}

//problem 6.61
void game(){
  int choose=0;//the users choose number
  int type;//the game type ex:1 or 2 .
  int x=0;
  int y=0;
  int input=1;
  int result=0;
  int highsort=0;
  int lowsort=0;
  cout<<"please choose the game type: 1.add 2.sub 3.mult 4.div 5.random mode. when you want to stop, type 0"<<endl;
  cin>>choose;
  while(input!=0){//input 0 to stop
    type=choose;
    if(choose<1||choose>4){
    type=rand()%4+1;
  }

  x=rand()%101;
  y=rand()%101;
    switch(type){
      case 1:
      cout<< x<<" + "<<y<<" = "<<endl;
      cin>>input;
      result=x+y;
      break;

      case 2:
      cout<< x<<" - "<<y<<" = "<<endl;
      cin>>input;
      result=x-y;
      break;

      case 3:
      cout<< x<<" * "<<y<<" = "<<endl;
      cin>>input;
      result=x*y;
      break;

      case 4:
      cout<< x<<" / "<<y<<" = "<<endl;
      cin>>input;
      result=x/y;
      break;
    }
    if(input!=result){
      cout<<"wrong result"<<endl;
    }
    else{
      cout<<"right result"<<endl;
    }
  }//end of while
}//end of game

//Exercise 4
void printArray(int** a){
  for(int y=0;y<10;y++){
    for(int x=0;x<8;x++){
      cout<<a[y][x]<<" ";

    }
    cout<<endl;
  }//end of outside for loop
}//end of method

void findSmallest(int** a){
  int result=a[0][0];
  for(int y=0;y<10;y++){
    for(int x=0;x<8;x++){
      if(a[y][x]<result){
        result=a[y][x];
      }

    }}
  cout<<"the smallest number is: "<<result<<endl;
}

void findAverage(int** a){
  int sum=0;
  int result=0;
  for(int y=0;y<10;y++){
    for(int x=0;x<8;x++){

        sum=sum+a[y][x];

    }}//end of for loop
    result=sum/80;
    cout<<"the average is: "<< result<<endl;
}
void removeEven(int** a){
  int check=0;
  for(int y=0;y<10;y++){
    for(int x=0;x<8;x++){
      check=a[y][x]%2;
      if(check==0){
        a[y][x]=11;
      }
    }}//end of for loop
}

void identity(int** a){
  for(int y=0;y<10;y++){
    for(int x=0;x<8;x++){
      if(x==y){
        a[y][x]=1;
      }
      else{
        a[y][x]=0;
      }
    }}//end of for loop
}

void findMode(int** a){
  int* temp=new int[100];
  int check=0;//go though the thrid for loop to check
  int result=0;
  for(int y=0;y<10;y++){
    for(int x=0;x<8;x++){
      temp[a[y][x]]++;
    }}//end of for loop
    for(int i=0;i<100;i++){
      if(temp[i]>check){
        result=i;
        check=temp[i];
      }
    }//end of for loop
    cout<<"the mode is: "<<result<<endl;

}


//Exercise 4
void leftSum(int** a){
  int sum=0;
  for(int y=0;y<4;y++){
    for(int x=0;x<4;x++){
      if(y>x){
        sum=sum+a[y][x];
      }
    }}
  cout<<"the left sum is: "<< sum<<endl;
}

void rightSum(int** a){
  int sum=0;
  for(int y=0;y<4;y++){
    for(int x=0;x<4;x++){
      if(y<x){
        sum=sum+a[y][x];
      }
    }}
  cout<<"the right sum is: "<< sum<<endl;
}

void printLow(int** a){
  for(int y=0;y<4;y++){
    for(int x=0;x<4;x++){
      if(y>x){
        cout<< a[y][x]<<" ";
      }
    }}

}

void printUp(int** a){
  for(int y=0;y<4;y++){
    for(int x=0;x<4;x++){
      if(y<x){
        cout<< a[y][x]<<" ";
      }
    }}

}

//problem 7.35
void polling(){
  int** a = new int*[5];
  for(int i = 0; i < 5; ++i){a[i] = new int[10];}
  string str[5];
  int choose=1;
  int vote=0;
  int* sum=new int[5];
  int highsort=0;
  int lowsort=0;

  str[1]="topic1";
  str[2]="topic2";
  str[3]="topic3";
  str[4]="topic4";
  str[5]="topic5";

  cout<<"please enter how many time you want to do the polling?"<<endl;
  cin>>choose;

  for(int i=0;i<choose;i++){

    for(int i=0;i<5;i++){
      cout<<"what do you think about(from 1-10(most important)): "<<str[i]<<endl;
      cin>>vote;
      if(vote<1||vote>10)
      vote=0;

      a[i][vote]=a[i][vote]+vote;//store the vote point
    }

    for(int y=0;y<5;y++){
      for(int x=0;x<10;x++){
        sum[y]=sum[y]+a[y][x];//get sum from each element

      }
    }





  }//end of for loop biggest


  for(int i=0;i<5;i++){
    cout<<str[i]<<"point is:  "<<sum[i]<<endl;
  }

  for(int i=0;i<5;i++){
    cout<<str[i]<<"average point is:  "<<sum[i]/choose<<endl;
  }


  int high=sum[0];
  int low=sum[0];

  for(int i=0;i<5;i++){
    if(sum[i]>high){
      high=sum[i];
      highsort=i;
    }
    if(sum[i]<low){
      low=sum[i];
      lowsort=i;
    }
  }//end of for loop

  cout<<"the highest point issus is: "<<str[highsort]<<" point is: "<<high<<endl;
  cout<<"the lowest point issus is: "<<str[lowsort]<< " Point is: "<<low<<endl;






}






int main(){
  float s(5e-2);
  float b(6e-2);
  //game();
  int** a = new int*[10];
  for(int i = 0; i < 10; ++i){a[i] = new int[8];}

  int** m = new int*[4];
  for(int c = 0; c < 4; ++c){m[c] = new int[4];}

  for(int y=0;y<10;y++){
    for(int x=0;x<8;x++){
      a[y][x]=rand()%50+50;
    }
  }//end of outside for loop
  printArray(a);
  findSmallest(a);
  findAverage(a);
  findMode(a);
  removeEven(a);
  printArray(a);
  identity(a);

  for(int q=0;q<4;q++){
    for(int w=0;w<4;w++){
      m[q][w]=rand()%2;
    }
  }//for matrix

  polling();








}
