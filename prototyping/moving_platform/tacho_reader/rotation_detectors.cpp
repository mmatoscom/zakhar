/*
 *
 * @breaf 
 * 
 * @author Andrei Gramakov
 */

#include "rotation_detectors.h"

int l_counter;
int r_counter;

using namespace std;

void send_left(int gaps)
    string msg;
    msg = "l" + to_string(gaps);
}

void send_right(int gaps)
{
    string msg;
    msg = "r" + to_string(gaps);
}

 void inc_left()
 {
   ++l_counter;
 }

  void inc_right()
 {
   ++r_counter;
 }