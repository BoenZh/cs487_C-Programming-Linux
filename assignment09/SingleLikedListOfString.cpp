//by boen zhang
//assignment 9
//1/20/2017

#include "SingleLinkedListOfString.h"
using namespace std;

#include <stdexcept>
using std::out_of_range;

SingleLinkedListOfString::SingleLinkedListOfString() : head(NULL) { }

SingleLinkedListOfString::SingleLinkedListOfString(const std::string a[], int size) :
    head(NULL)
{
  for( int i = size - 1; i >= 0; i-- )
    addFirst(a[i]);
}

SingleLinkedListOfString::~SingleLinkedListOfString()
{
  if( empty() ) return;
  Node * n = head;
  while( n != NULL ) {
    Node * toDelete = n;
    n = n->next;

    delete toDelete;
  }
}

int SingleLinkedListOfString::size() const
{
  Node * n = head;
  int count = 0;
  while( n != NULL ) {
    count++;
    n = n->next;
  }
  return count;
}

bool SingleLinkedListOfString::empty() const {
    return head == NULL;
}

void SingleLinkedListOfString::addFirst( const std::string & str)
{
  Node * n = new Node(str);
  n->next = head;
  head = n;
}

void SingleLinkedListOfString::addLast( const std::string & str ) {

  if( empty() ) addFirst(str);
  else {
    Node * newNode = new Node(str);

    Node * n = head;  // Shouldn't be null
    while( n->next != NULL ) {
      n = n->next;
    }

    n->next = newNode;
  }
}

void SingleLinkedListOfString::add( int idx, const std::string & str) {
  int sz = size();
  if( idx >= 0 && idx <= sz ) {
    if( idx == 0 ) addFirst(str);
    else {
      Node * newNode = new Node(str);
      Node * n = head;
      for( int i = 0; i < idx - 1; i++ ) n = n->next;
      newNode->next = n->next;
      n->next = newNode;
    }
  }
  else
    throw out_of_range("Index out of range");
}

std::string SingleLinkedListOfString::getFirst() const
{
  if( empty() )
    throw out_of_range("No such element");
  else {
    return head->s;
  }
}

std::string SingleLinkedListOfString::getLast() const
{
  if( empty() )
    throw out_of_range("No such element");
  else {
    Node * n = head;
    while( n->next != NULL ) n = n->next;
    return n->s;
  }
}

std::string SingleLinkedListOfString::get(int idx) const {
  int sz = size();
  if( idx < 0 || idx >= sz )
    throw out_of_range("Index out of range");
  else
  {
    Node * n = head;
    for( int i = 0; i < idx ; i++ ) n = n->next;
    return n->s;
  }
}

int SingleLinkedListOfString::find( const std::string & str ) const {
  Node * n = head;
  int idx = 0;
  while( n != NULL )
  {
    if( n->s == str ) return idx;
    n = n->next;
    idx++;
  }
  return -1;
}

bool SingleLinkedListOfString::remove( const std::string & str)
{
  if( empty() ) return false;

  // If it's the first item, use removeFirst
  if( head->s == str ) {
    removeFirst();
    return true;
  }

  // It's not the first and the list has at least 1 element
  Node * n = head;
  while( n->next != NULL ) {

    if( n->next->s == str ) {
      Node * toDelete = n->next;
      n->next = n->next->next;
      delete toDelete;
      return true;
    }

    n = n->next;
  }
  return false;
}

void SingleLinkedListOfString::removeFirst() {
  if( empty() ) return;

  Node * toDelete = head;
  head = head->next;
  delete toDelete;
}
void SingleLinkedListOfString::removeLast() {
  if( empty() ) return;
  if( head->next == NULL ) removeFirst();
  else {
    // At least 2 items in list
    Node * n = head;
    while( n->next->next != NULL ) n = n->next;

    Node * toDelete = n->next;
    n->next = NULL;
    delete toDelete;
  }
}

std::string SingleLinkedListOfString::toString() const
{
  std::string str = "[ ";

  Node * n = head;

  while( n != NULL ) {
    str += n->s;
    if( n->next != NULL ) str += ", ";
    n = n->next;
  }
  str += " ]";
  return str;
}

SingleLinkedListOfString::SingleLinkedListOfString(const SingleLinkedListOfString &tar){
  if(tar.getFirst()!=NULL){
    Node *temp=tar.getFirst();
  }
    string s[tar.size()];
    for(int i=0;i<tar.size();i++){
      temp=temp->next;
      s[i]=temp.s;
    }

    return SingleLinkedListOfString(temp,tar.size());
  }

  SingleLinkedListOfString SingleLinkedListOfString::operator=(const SingleLinkedListOfString &tar){
SingleLinkedListOfString a1;

for(int i=0;i<tar.size();i++)
    a1.add(tar.get(i));
  }

  return a1;


}
