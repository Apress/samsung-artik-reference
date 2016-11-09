#include <stdio.h>
#include <stdbool.h>

// Declare variables
FILE *myGPIOPinModeFd;


// Manufacture a path
myGPIOPinNumber = 19;
sprintf(myGPIOPinModePath, "/sys/class/gpio/gpio%d/direction", myGPIOPinNumber);


// Select one of these values to choose a mode
// Uncomment the one you want to use
myGPIOPinMode = "out";
//myGPIOPinMode = "in";
//myGPIOPinMode = "high";
//myGPIOPinMode = "low";


// Open the direction configuration for the GPIO node
if((myGPIOPinModeFd = fopen(myGPIOPinModePath, "w")) == NULL)
{
  printf("Error: cannot open pin direction\n");
  return false;
}


// Set the pin mode with the passed in direction
fprintf(myGPIOPinModeFd, "%s\n", myGPIOPinMode);


// Close the direction configurator
fclose(myGPIOPinModeFd);
