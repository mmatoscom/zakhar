/*
 * rotsensors.h
 *
 *  Created on: Jun 30, 2019
 *      Author: dongr
 */

#ifndef ROTSENSORS_H_
#define ROTSENSORS_H_

#include <Arduino.h>
#include <stdint.h>

#ifndef ROTSENS_L_INT
#	warning "ROTSENS_L_INT is not defined, will be set to 0"
#	define ROTSENS_L_INT 0
#endif

#ifndef ROTSENS_R_INT
#	warning "ROTSENS_R_INT is not defined, will be set to 1"
#	define ROTSENS_R_INT 1
#endif

class rot_sensors {
public:
	rot_sensors();
	bool init();
	void send();
	virtual ~rot_sensors();
private:
	uint8_t l_int;
	uint8_t r_int;
	uint32_t l_count;
	uint32_t r_count;
	void l_count_incr();
	void r_count_incr();
	void send_left(int gaps);
	void send_right(int gaps);
};

#endif /* ROTSENSORS_H_ */
