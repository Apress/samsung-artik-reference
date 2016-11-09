#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[] )
{

  FILE *fp;
  char myResult[1035];
  char myCommand[64];

  // Manufacture a command line from the first argument
  sprintf(myCommand, "ls /sys/devices | grep %s$ | cut -d'.' -f1", argv[1]);


  // Open the command for reading
  fp = popen(myCommand, "r");

  if (fp == NULL)
  {
    printf("Failed to run command\n" );
    exit(1);
  }


  // Read and output the result
  while (fgets(myResult, sizeof(myResult)-1, fp) != NULL)
  {
    printf("%s", myResult);
  }


  // Close and quit
  pclose(fp);

  return 0;
}
