/*
 *
 * @breaf 
 * 
 * @author Andrei Gramakov
 */

#ifndef ROTATION_DETECTORS_H_
#define ROTATION_DETECTORS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <Arduino.h>
#include <string.h>

using namespace std;

// code here
void send(string msg);
void send_left(int gaps);
void send_right(int gaps);



#ifdef __cplusplus
}
#endif

#endif /* ROTATION_DETECTORS_H_ */
