/*
 * gpio.c
 *
 *  Created on: 02/06/2015
 */

#include "gpio.h"

int open_gpio(int gpio, int direction, int gpio_value) { /* <PINO>, <IN/OUT>, <Low/High> */
    char buffer[100];
    int file_handle;
    int file_mode;

    // Export GPIO
    file_handle = open("/sys/class/gpio/export", O_WRONLY); // Acesso somente escrita (write-only)
    if(file_handle == -1) {
        puts("Error: Unable to opening /sys/class/gpio/export");
        return -1;
    }
    sprintf(buffer,"%d",gpio);
    write(file_handle, buffer, strlen(buffer));
    close(file_handle);

    // Direction
    sprintf(buffer, "/sys/class/gpio/gpio%d/direction", gpio);
    file_handle = open(buffer, O_WRONLY); // Acesso somente escrita (write-only)
    if(file_handle == -1) {
        printf("Unable to open file: %s\n",buffer);
        return -1;
    }

    if (direction == 0) {
        write(file_handle, "out", 3);
        file_mode = O_WRONLY; // Acesso somente escrita (write-only)
    }
    else {
        write(file_handle, "in", 2);
        file_mode = O_RDONLY; // Acesso somente leitura (read-only).
    }
    close(file_handle);

    // Value
    sprintf(buffer, "/sys/class/gpio/gpio%d/value", gpio);
    file_handle = open(buffer, file_mode);
    if(file_handle == -1) {
        printf("Unable to open file:%s\n",buffer);
        return -1;
    }
    if(gpio_value == 0) // Set GPIO low status
        write(file_handle, "0", 1);
    else // Set GPIO high status
        write(file_handle, "1", 1);

    return file_handle;
}

int close_gpio(int gpio, int file_handle) {
    char buffer[256];
    close(file_handle);
    file_handle = open("/sys/class/gpio/unexport", O_WRONLY);
    if(file_handle == -1) {
        printf("Unable to open file:%s\n",buffer);
        return -1;
    }
    sprintf(buffer, "%d", gpio);
    write(file_handle, buffer, strlen(buffer));
    close(file_handle);

    return 0;
}
