#include <stdio.h>
#include <c6x.h> // Include the TMS320C6416 DSK-specific header file
#include <csl_gpio.h> // Include the GPIO driver header file

// Define GPIO pin number for motor control
#define MOTOR_PIN  0 // Assume GPIO pin 0 is connected to the motor

// Function to set the GPIO pin direction and value
void set_gpio_pin(int pin_number, int direction, int value) {
    CSL_GPIO_Handle hGpio;
    CSL_GPIO_BitConfig bitCfg;
  
    hGpio = CSL_GPIO_open(pin_number);
    bitCfg.dir = direction; // 0 for input, 1 for output
    bitCfg.outData = value; // 0 for low, 1 for high
    CSL_GPIO_configBit(hGpio, &bitCfg);
    CSL_GPIO_close(hGpio);
}

int main() {
    // Initialize the GPIO pin for motor control as an output
    set_gpio_pin(MOTOR_PIN, GPIO_OUTPUT, 0); // Set the GPIO pin low initially

    while (1) {
        // Turn ON the motor for 2 seconds
        set_gpio_pin(MOTOR_PIN, GPIO_OUTPUT, 1); // Set the GPIO pin high to activate the motor

        printf("Motor is ON\n");
        _delayms(2000); // Use the _delayms() function provided by the DSK to create a 2-second delay

        // Turn OFF the motor for 2 seconds
        set_gpio_pin(MOTOR_PIN, GPIO_OUTPUT, 0); // Set the GPIO pin low to deactivate the motor

        printf("Motor is OFF\n");
        _delayms(2000); // Use the _delayms() function provided by the DSK to create a 2-second delay
    }

    return 0;
}
