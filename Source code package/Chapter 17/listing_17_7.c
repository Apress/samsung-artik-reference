#include <stdio.h>
#include <stdbool.h>

// Declare the variables
FILE *myGPIoExportFd;


// Define the target pin number
myGPIOPinNumber = 19;


// Open a messaging channel to the kernel
if((myGPIoExportFd = fopen("/sys/class/gpio/export", "w")) == NULL)
{
  printf("Error: unable to export GPIO pin\n");
  return false;
}


// Tell the kernel which pin to use
fprintf(myGPIoExportFd, "%d\n", myGPIOPinNumber);


// Close the kernel messaging channel
fclose(myGPIoExportFd);
