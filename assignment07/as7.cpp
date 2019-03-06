//by boen zhang
//Assignmeny 7
//1/18/2017

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Node{
public:
string s;
Node *next;

Node(const string & str){
  s=str;
  next=NULL;

}

};//end of Node class

class SLLofString{
private:
  Node* head;
public:
  SLLofString(){
    head=NULL;
  }
  SLLofString(const string a[],int size){
    Node *cur=new Node(a[0]);
    head=cur;
    for(int i=1;i<size;i++){
      cur->next=new Node(a[i]);
      cur=cur->next;
    }//end of for loop

  }

  ~SLLofString(){
    Node* cur=head;
    while(cur!=NULL){
      head=head->next;
      delete cur;
      cur=head;
    }//end of while loop
  }//end of ~SLLofString

  int size(){
    int result=0;
    Node* temp=head;
    while(temp!=NULL){
      temp=temp->next;
      result++;
    }//end of while loop
    return result;
  }//end of size

  bool empty(){
    bool result=false;
    if(head=NULL)
    result=true;
    else
    result=false;

    return result;

  }

  void addFirst(const string & s){
    Node* temp=new Node(s);
    if(head==NULL){
      head=temp;
    }
    else{
      temp->next=head;
      head=temp;
    }
  }//end of add first

  void addLast(const string & s){
    Node* temp=new Node(s);
    Node* cur=head;
    while(cur!=NULL){
      cur=cur->next;
    }
    cur->next=temp;
  }//end of addLast

  void add(int idx,const string & s){
    if(size()<idx){
      throw out_of_range("out of range");
    }
    Node* temp=head->next;
    Node* cur=head;

    for(int i=0;i<idx-1;i++){
      cur=cur->next;
      temp=temp->next;
    }

    cur->next=new Node(s);
    cur->next->next=temp;
  }//end of add

  string getFirst(){

    return head->s;
  }

  string getLast(){
    Node* temp=head;
    while(temp!=NULL){
      temp=temp->next;
    }
    return temp->s;
  }

  string get(int idx){
    Node* temp=head;
    for(int i=0;i<idx;i++){
      temp=temp->next;
    }
    return temp->s;
  }

  int find(const string & str){
    int result=-1;
    int count=0;
    Node* temp=head;

    while(result==-1){
      if(str==temp->s){
        result=count;
      }
      temp=temp->next;
      count++;

    }//end of while loop
    return result;

  }//end of find

  bool remove(const string &str){

    //int check=0;
    Node* temp=head->next;//use for delete the node
    Node* cur=head;
    //if(temp->s==str){
      //check=1;
      //head=head->next;
      //delete cur;
      //return true;
    //}

    while(cur->next !=NULL){
      if(cur->s==str){
        temp->next=cur->next;
        delete cur;
        return true;
      }
      temp=temp->next;
      cur=cur->next;

    }
    return false;

  }//end of remove

  void removeFirst(){
    if(head==NULL){
      cout<<"does nothing";
    }
    else{
      Node* temp=head;
      head=temp->next;
      delete head;

    }

  }//end of removeFirst

  void removeLast(){
    if(head==NULL){
      cout<<"does nothing";
    }
    else{
      Node* temp=head;
      while(temp!=NULL){
        temp=temp->next;
      }
      delete temp;
    }

  }//end of removeLast

  string toString(){
    Node* temp=head;
    int count=0;
    string a="\"[";

    while(temp!=NULL){
      if(temp->next !=NULL){
        a=a+" "+temp->s+",";
      }
      else{
        a=a+" "+temp->s+" ]\"";
      }
      temp=temp->next;

    }
    return a;
  }//end of toString



};//end of SLLofString class


int main()
{
  string a[]={"aa","bb","2323"};
  SLLofString test=SLLofString(a,3);
  cout<<test.toString()<<endl;
  cout<<test.get(0)<<endl;
  cout<<test.find("bb")<<endl;

  test.add(1,"gogo");
  cout<<test.toString()<<endl;
  test.addFirst("iiiiii");
  cout<<test.toString()<<endl;

  cout<<test.get(0)<<endl;
  cout<<test.empty()<<endl;
  test.remove("aa");
  cout<<test.toString()<<endl;







  return 0;
}
