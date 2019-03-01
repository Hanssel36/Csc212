#include <iostream>
using namespace std;




int main(){
int* a;
    int b = 34;
  a = &b;

  *a = 23;

  cout << *a << endl;

}