bool setPWMDuration(int anId, long int aDuration)
{
  FILE *myPWMDurationFd;
  char myPath[256];


  // Manufacture a path to the PWM period property
  sprintf(myPath, "/sys/class/pwm/pwmchip0/pwm%d/period", anId);


  // Open the PWM period property
  if((myPWMDurationFd = fopen(myPath, "w")) == NULL)
  {
    printf("Error: cannot open PWM period duration for writing\n");
    return false;
  }


  // Activate the required PWM channel
  fprintf(myPWMDurationFd, "%d\n", aDuration);


  // Close the PWM period property
  fclose(myPWMDurationFd);


  return true;
}
