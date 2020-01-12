/*
 * rotsensors.cpp
 *
 *  Created on: Jun 30, 2019
 *      Author: dongr
 */

#include "rotsensors.h"

rot_sensors::rot_sensors() :
		l_int(ROTSENS_L_INT), r_int(ROTSENS_R_INT), l_count(0), r_count(0) {

}



void rot_sensors::send()
{
//	String msg = "rotsensor_L%i_R%i\n", l_count, r_count;
//	Serial.print(msg);
	l_count = 0;
	r_count = 0;
}



rot_sensors::~rot_sensors() {
	// TODO Auto-generated destructor stub
}

//bool rot_sensors::init() {
//	attachInterrupt(digitalPinToInterrupt(l_int), l_count_incr, RISING);
//	attachInterrupt(digitalPinToInterrupt(r_int), r_count_incr, RISING);
//}


void rot_sensors::l_count_incr() {
	l_count++;
}

void rot_sensors::r_count_incr() {
	r_count++;
}
