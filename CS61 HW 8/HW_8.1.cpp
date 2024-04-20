#include <iostream>
#include <cstdlib>
#include "table2.h"
using namespace std;
using namespace main_savitch_12B;

struct record{
  int data;
  int key;
};

int main(){
  table<record> t1;
  cout<<"Creating new empty Table t1"<<endl;
  record r1{1,1};
  cout<<"creating new record r1 with value 1 & key 1"<<endl;
  cout<<"Does table t1 contain r1.key: ";
  if(t1.is_present(r1.key)){
    cout<<"Yes"<<endl;
  } else {
    cout<<"No"<<endl;
  }
  t1.insert(r1);
  cout<<"Inserting r1"<<endl;
  cout<<"Does table t1 contain r1.key: ";
  if(t1.is_present(r1.key)){
    cout<<"Yes"<<endl;
  } else {
    cout<<"No"<<endl;
  }
  table<record> t2;
  cout<<"Creating new Table t2"<<endl;
  cout<<"Does table t2 contain r1.key: ";
  if(t2.is_present(r1.key)){
    cout<<"Yes"<<endl;
  } else {
    cout<<"No"<<endl;
  }
  cout<<"Setting Table t2 equal to t1"<<endl;
  t2 = t1;
  cout<<"Does table t2 contain r1.key: ";
  if(t2.is_present(r1.key)){
    cout<<"Yes"<<endl;
  } else {
    cout<<"No"<<endl;
  }
  cout<<"Removing r1.key from Table t2"<<endl;
  t2.remove(r1.key);
  cout<<"Does table t2 contain r1.key: ";
  if(t2.is_present(r1.key)){
    cout<<"Yes"<<endl;
  } else {
    cout<<"No"<<endl;
  }
  record r2{81,1};
  cout<<"creating new record r1 with value 81 & key 1"<<endl;
  t1.insert(r2);
  cout<<"Inserting r2 into t1"<<endl;
  bool present;
  record temp;
  t1.find(r2.key, present, temp);
  cout<<"Value of record with key 1 is: "<<temp.data<<endl;
  record r3{81,2};
  cout<<"creating new record r3 with value 81 & key 2"<<endl;
  t1.insert(r3);
  cout<<"Inserting r3 into t1"<<endl;
  record r4{79,3};
  cout<<"creating new record r4 with value 79 & key 3"<<endl;
  t1.insert(r4);
  cout<<"Inserting r4 into t1"<<endl;
  cout<<"Size of table t1: "<<t1.size()<<endl;

  return 0;
}
