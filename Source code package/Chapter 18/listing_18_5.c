// Include standard library header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Declare the function prototype
int getBaseAddress(char* aSymbolicName, char *aResultString );


// Declare the manifest constants
#define BUFFER_LENGTH 16


// Main body of the test application that calls the helper function
int main( int argc, char *argv[] )
{

  char myBaseAddress[BUFFER_LENGTH];
  int myResult;
  int ii;

  myResult = getBaseAddress("adc", myBaseAddress);

  printf("Base address for ADC is: %s with result %d:\n\n",
         myBaseAddress,
         myResult);


  // Display a character by character dump of the result
  printf("------\n");
  for(ii=0; ii<strlen(myBaseAddress); ii++)
  {
    printf("%d - %d\n", ii, myBaseAddress[ii]);
  }
  printf("------\n");


  return 0;
}


// Helper function to get a base address
int getBaseAddress(char* aSymbolicName, char *aResultString )
{

  FILE *fp;
  char myCommand[64];

  // Manufacture a command line from the first argument
  sprintf(myCommand,
          "ls /sys/devices | grep %s$ | cut -d'.' -f1",
          aSymbolicName);


  // Open the command for reading
  fp = popen(myCommand, "r");

  if (fp == NULL)
  {
    return(1);
  }


  // Read and output the result
  if(fgets(aResultString, BUFFER_LENGTH, fp) == NULL)
  {
    return(2);
  }

  // Close and quit
  pclose(fp);


  // Clean off the trailing line feed character
  // by shortening the string by one character
  aResultString[strlen(aResultString)-1] = 0;


  return(0);
}
