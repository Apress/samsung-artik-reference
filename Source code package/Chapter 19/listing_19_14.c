bool isPWMRunning(int anId)
{
  char myResult[6];
  int myIntegerResult;
  FILE *myPWMStatusFd;
  char myPath[256];


  // Manufacture a path to the property
  sprintf(myPath, "/sys/class/pwm/pwmchip0/pwm%d/enable", anId);


  // Open the PWM enable property
  if((myPWMStatusFd = fopen(myPath, "r")) == NULL)
  {
    printf("Error: cannot open PWM enable for reading\n");
    return false;
  }


  // Read the pin value
  fgets(myResult, 2, myPWMStatusFd);


  // Close the property file
  fclose(myPWMStatusFd);


  // Convert the value to an integer before returning it to your application:
  myIntegerResult = atoi(myResult);


  return myIntegerResult;
}
