bool invertPWM(int anId, bool anInvertFlag)
{
  FILE *myPWMPolarityFd;
  char myPath[256];
  bool myPWMStatusFlag;

  myPWMStatusFlag = bool isPWMRunning(int anId);

  // Conditionally switch off the PWM channel
  if(myPWMStatusFlag)
  {
    disablePWM(int anId);
  }


  // Manufacture a path to the PWM polarity property
  sprintf(myPath, "/sys/class/pwm/pwmchip0/pwm%d/polarity", anId);


  // Open the PWM polarity property
  if((myPWMPolarityFd = fopen(myPath, "w")) == NULL)
  {
    printf("Error: cannot open PWM polarity for writing\n");
    return false;
  }


  // Set the required PWM invert value
 if(anInvertFlag)
  {
    fprintf(myPWMPolarityFd, "inversed\n");
  }
  else
  {
    fprintf(myPWMPolarityFd, "normal\n");
  }


  // Close the PWM polarity property
  fclose(myPWMPolarityFd);


  // Conditionally turn the PWM back on
  if(myPWMStatusFlag)
  {
    enablePWM(int anId);
  }


  return true;
}
