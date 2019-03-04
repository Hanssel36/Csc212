#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <cstring>   // Provides memcpy
#include "sequence2.h"
// Provides the sequence class with double items.
using namespace std;
using namespace main_savitch_4;

void show_sequence(sequence display)
// Library facilities used: iostream
{
    for (display.start( ); display.is_item( ); display.advance( ))
        cout << display.current( ) << endl;
}

int main(){
  sequence T, S, U;

  T.attach(5);
  T.attach(6);
  T.attach(7);
  S.attach(13);
  S.attach(16);
  cout << T[1] << endl;
  //show_sequence(T);
  }