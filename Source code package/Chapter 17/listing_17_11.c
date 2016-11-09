#include <stdio.h>
#include <stdbool.h>

// Declare the variables
FILE *myGPIOPinValueFd;
char myResult[6];


// Manufacture a path to the pin value
sprintf(myGPIOPinValuePath, "/sys/class/gpio/gpio%d/value", myGPIOPinNumber);


// Open the value configuration for the GPIO node
if((myGPIOPinValueFd = fopen(myGPIOPinValuePath, "r")) == NULL)
{
  printf("Error: cannot open pin value for reading\n");
  return false;
}


// Read the pin value
fgets(myResult, 2, myGPIOPinValueFd);


// Close the value configurator
fclose(myGPIOPinValueFd);


// Convert the value to an integer before returning it to your application:
myIntegerResult = atoi(myResult);
