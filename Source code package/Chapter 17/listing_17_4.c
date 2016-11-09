#include <stdio.h>
#include <stdlib.h>
#include <string>


int main( int argc, char *argv[] )
{

  FILE *fp;
  char myResult[16];
  char myFormat[96];
  char myCommand[96];


// Build the format string
// You can do this with a single literal but this method
// avoids confusing line wraps in the book listing
strcpy(myFormat, "ls -la /sys/class/gpio");
strcat(myFormat, " | grep %s");
strcat(myFormat, " | sed 's/..pinctrl.*$//'");
strcat(myFormat, " | sed 's/^.*devices.//'");


  // Manufacture a command line from the first argument
  sprintf(myCommand, myFormat, argv[1]);


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