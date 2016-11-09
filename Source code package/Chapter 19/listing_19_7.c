int pwmChannelCount()
{
  char myResult[6];
  int myIntegerResult;
  FILE *myPWMCountFd;

  // Open the PWM channel count property
  if((myPWMCountFd = fopen("/sys/class/pwm/pwmchip0/npwm", "r")) == NULL)
  {
    printf("Error: cannot open PWM channel count (npwm) for reading\n");
    return false;
  }


  // Read the pin value
  fgets(myResult, 2, myPWMCountFd);


  // Close the PWM channel count property
  fclose(myPWMCountFd);


  // Convert the value to an integer before returning it to your application:
  myIntegerResult = atoi(myResult);


  return myIntegerResult;
}
