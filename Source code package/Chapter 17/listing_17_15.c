#include <stdio.h>
#include <stdbool.h>

// Declare the variables
FILE *myGPIoUnexportFd;


// Define the target pin number
myGPIOPinNumber = 19;

// Open a messaging channel to the kernel
if((myGPIoUnexportFd = fopen("/sys/class/gpio/unexport", "w")) == NULL)
{
  printf("Error: unable to unexport GPIO pin\n");
  return false;
}

// Tell the kernel which pin to relinquish
fprintf(myGPIoUnexportFd, "%d\n", myGPIOPinNumber);

// Close the kernel messaging channel
fclose(myGPIoUnexportFd);
