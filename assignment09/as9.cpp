//by boen zhang
//assignment 9
//1/20/2017
#include <iostream>
#include <vector>
using namespace std;

class Term{
  long x;
  long y;
  Term(){
    x=0;
    y=0;
  }
  Term(int a,int b){
    x=a;
    y=b;
  }
};

class polynomial{

public:
  vector<int> a;

  polynomial(){
    a=vector<int>(5,0);
   }

   polynomial(const int i){
     a=vector<int>(i,0);
   }

  polynomial(const vector<int> &s){
    a=s;
  }

  int size(){
    return a.size();
  }

  vector<int> getTerms(){
    return a;
  }

  polynomial operator+(const polynomial &s){
    int size=0;
    if(s.a.size()>=a.size())
    size=s.a.size();
    else
    size=a.size();

    polynomial result(size);
    for(int i=0;i<size;i++){
      result.a[i]=s.a[i]+a[i];
    }

    return result;
  }

  polynomial operator-(const polynomial &s){
    int size=0;
    if(s.a.size()>=a.size())
    size=s.a.size();
    else
    size=a.size();

    polynomial result(size);
    for(int i=0;i<size;i++){
      result.a[i]=s.a[i]-a[i];
    }

    return result;
  }

  polynomial operator=(const polynomial &s){
    return s;
  }

  void operator+=(const polynomial &s ){
    int size=0;
    if(s.a.size()>=a.size())
      size=s.a.size();
      else
      size=a.size();

      for(int i=0;i<size;i++){
        a[i]=a[i]+s.a[i];
      }
    }

  void operator-=(const polynomial &s ){
        int size=0;
        if(s.a.size()>=a.size())
          size=s.a.size();
          else
          size=a.size();

          for(int i=0;i<size;i++){
            a[i]=a[i]-s.a[i];
          }

  }

  void operator*=(const polynomial &s ){
    a.resize(a.size()+s.a.size()-1,0);
    int size=a.size();

    for(int i=0;i<size;i++){
      for(int j=0;j<s.a.size();j++){
        a[i+j]=a[i+j]+a[i]*s.a[j];
      }

    }


      }
};

int main(){
  return 0;
}
