#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "sequence3.h"  // With value_type defined as double
using namespace std;
using namespace main_savitch_5;

void show_sequence(sequence display)
// Library facilities used: iostream
{
    for (display.start( ); display.is_item( ); display.advance( ))
        cout << display.current( ) << endl;
}


int main(){

  sequence T,y;

  T.attach(5);
  T.attach(4);
  T.attach(3);
  T.attach(2);
  show_sequence(T);

  }