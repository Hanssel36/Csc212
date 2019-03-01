#include <iostream>
using namespace std;


int main(){
  int d = 42;
  int u = 20;
  int *p1, *p2;
  p1 = &d;
  p2 = &u;
  *p1 = *p2;
  cout << *p1 << endl;
  cout << *p2 << endl;

  }