/*
 * adc.h
 *
 *  Created on: 02/06/2015
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int read_adc(int);
/* Return value 0-4095 */

#endif /* ADC_H_ */
