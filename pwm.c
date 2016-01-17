/*
 * pwm.c
 *
 *  Created on: 02/06/2015
 */

#include "pwm.h"

int pwm_init(int port) {
	char buffer[55];
	int file_handle;
	int file_mode;

	file_handle = open("/sys/class/pwm/pwmchip0/export", O_WRONLY);
	if(file_handle == -1) {
		puts("Error: Unable to opening /sys/class/gpio/export");
		return -1;
	}
    sprintf(buffer, "%d", port);
    write(file_handle, buffer, strlen(buffer));
    close(file_handle);
    sleep(1);

    return 0;
}

int pwm_enable(int enable, int port) {
	char buffer[55];
	int file_handle;

	// Enable PWM
	sprintf(buffer, "/sys/class/pwm/pwmchip0/pwm%d/enable", port);
	file_handle = open(buffer, O_WRONLY);
	if(file_handle == -1) {
		puts("Error: Unable to open file "); puts(buffer);
		return -1;
	}
	sprintf(buffer, "%d", enable);
	write(file_handle, buffer, strlen(buffer)); // Definindo o Enable

	return 0;
}


int pwm_period(int period, int port) {
	char buffer[55];
	int file_handle;

	// Period PWM
	sprintf(buffer, "/sys/class/pwm/pwmchip0/pwm%d/period", port);
	file_handle = open(buffer, O_WRONLY);
	if(file_handle == -1) {
		puts("Error: Unable to open file "); puts(buffer);
		return -1;
	}
	sprintf(buffer, "%d", period);
	write(file_handle, buffer, strlen(buffer)); // Definindo Periodo

	return 0;
}

int pwm_duty_cycle(int duty_cycle, int port) {
	char buffer[55];
	int file;

	// Period PWM
	sprintf(buffer, "/sys/class/pwm/pwmchip0/pwm5/duty_cycle");
	file = open(buffer, O_WRONLY);
	if(file == -1) {
		puts("Error: Unable to open file "); puts(buffer);
		return -1;
	}
	sprintf(buffer, "%d", duty_cycle);
	write(file, buffer, strlen(buffer)); // Definindo Duty Cycle

	return 0;
}
