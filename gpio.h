/*
 * gpio.h
 *
 *  Created on: 02/06/2015
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int open_gpio(int,int,int);
/* <PINO>, <IN ou OUT>, <Low ou High> */

int close_gpio(int,int);

#endif /* GPIO_H_ */
