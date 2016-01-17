/*
 * core.h
 *
 *  Created on: 10/06/2015
 */

#ifndef CORE_H_
#define CORE_H_

typedef enum { false, true } bool;

#define DIRA 31 // IO2_MUX -> Direção A da Ponte H
#define	DIRB 30 // IO3_MUX -> Direção B da Ponte H

#define GPIO_OUT 0 // In
#define GPIO_IN	 1 // Out

#define PWM					5  // Canal 5 para PWM
#define SENSOR_POSICAO		37 // A0_MUX
#define SENSOR_VELOCIDADE	36 // A1_MUX
#define POT					23 // A2_MUX

#endif /* CORE_H_ */
