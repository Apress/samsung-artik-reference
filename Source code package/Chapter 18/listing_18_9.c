#include <stdio.h>

int analogRawRead(int aPinNumber)
{
  FILE *fd;
  char fName[64];
  char val[8];

  // open value file
  sprintf(fName,
          "/sys/bus/iio/devices/iio:device0/in_voltage%d_raw",
          aPinNumber);

  if((fd = fopen(fName, "r")) == NULL)
  {
    printf("Error: cannot open analog voltage value\n");
    return 0;
  }

  fgets(val, 8, fd);
  fclose(fd);

  return atoi(val);
}
