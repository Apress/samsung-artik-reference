#include <stdio.h>
#include <stdlib.h>


int main()
{
  printf("Reading environment variables\n");
  const char* myEnvVar = getenv("VARIABLE");
  printf("VARIABLE :%s\n", myEnvVar);
  printf("end test\n");
}
