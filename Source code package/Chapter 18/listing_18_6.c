#include <stdio.h>

int analogRawRead(int aPinNumber)
{
  FILE *fd;
  char fName[64];
  char val[8];
  int myResult;
  char myBaseAddress[BUFFER_LENGTH];

  myResult = getBaseAddress("adc", myBaseAddress);

  // open value file
  sprintf(fName,
          "/sys/devices/%s.adc/iio:device0/in_voltage%d_raw",
          myBaseAddress,
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
