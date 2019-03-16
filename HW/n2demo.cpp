#include "point.h"
#include <iostream>
#include "node2.h"
#include <string>
using namespace std;
using namespace main_savitch_6B;
using namespace main_savitch_2A;

int main(){

  node<int>* ages = NULL;
  list_head_insert(ages,21);
  node <string> name;
  name.set_data("Hans");
  node <point> *seat;
  seat = new node <point>;
  (*seat).set_data(point(2,4));

  cout << name.data() << endl;
  cout << ages->data() << endl;
  cout << seat->data().get_x() << ",";
  cout << seat->data().get_y() << endl;



  }