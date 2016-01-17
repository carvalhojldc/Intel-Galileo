/*
 * pwm.h
 *
 *  Created on: 02/06/2015
 */

#ifndef PWM_H_
#define PWM_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int pwm_init(int);
int pwm_enable(int,int);
int pwm_period(int, int);
int pwm_duty_cycle(int,int);

#endif /* PWM_H_ */
