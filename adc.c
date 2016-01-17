/*
 * adc.c
 *
 *  Created on: 02/06/2015
 */

#include "adc.h"

int read_adc(int port) {
	usleep(2);

	int value;
	char buffer[60];
	FILE *file;

	if(port == 37)
		port = 0;
	else if(port == 36)
		port = 1;
	else if(port == 23)
		port = 2;

	sprintf(buffer, "/sys/bus/iio/devices/iio\:device0/in_voltage%d_raw", port);

	file = fopen(buffer, "r");

	if(file == NULL){
		printf("Arquivo do AD não pode ser aberto: %s\n", buffer);
		return -1;
	}

	fscanf(file, "%d", &value); // Realiza a leitura do arquivo
	fclose(file);

	usleep(2);

	return value;
}
