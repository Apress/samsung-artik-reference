#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
  FILE *myTempFd;
  char myResult[10];

  // Open the thermometer file
  if((myTempFd = fopen("/sys/devices/virtual/thermal/thermal_zone0/temp", "r")) == NULL)
  {
    printf("Error: cannot open thermometer for reading\n");
    return false;
  }

  // Read the temperature value
  fgets(myResult, 6, myTempFd);

  // Close the thermometer
  fclose(myTempFd);

  // Convert the value to an integer before returning it to your application:
  printf("Temperature is: %2.2f\n", atof(myResult)/1000.0);
}
