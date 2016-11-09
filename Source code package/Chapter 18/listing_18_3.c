#include <stdio.h>

int main( int argc, char *argv[] )
{
  char myResult[6];
  FILE *myFp;

  myFp = fopen("/sys/devices/126c0000.adc/iio:device0/in_voltage1_raw", "r");

  if(fgets(myResult, 6, myFp) == NULL)
  {
    return(2);
  }

  fclose(myFp);

  printf("ADC channel 0 has value: %s\n", myResult);

  return(0);
}
