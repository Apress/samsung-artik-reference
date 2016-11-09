#include <stdio.h>
#include <stdbool.h>

// Declare variables
FILE *myGPIOPinValueFd;


// Manufacture a path to the pin value
sprintf(myGPIOPinValuePath, "/sys/class/gpio/gpio%d/value", myGPIOPinNumber);


// Select one of these values to set on the pin
// Uncomment the one you want to use
myNewGPIOPinValue = 1;  // Represents HIGH
//myNewGPIOPinValue = 0; // Represents LOW

// Open the value configuration for the GPIO node
if((myGPIOPinValueFd = fopen(myGPIOPinValuePath, "w")) == NULL)
{
  printf("Error: cannot open pin value for writing\n");
  return false;
}

// Set the pin value with the passed in setting
fprintf(myGPIOPinValueFd, "%d\n", myNewGPIOPinValue);

// Close the value configurator
fclose(myGPIOPinValueFd);
