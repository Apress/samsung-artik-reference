bool destroyPWMChannel(int anId)
{
  FILE *myPWMUnexportFd;

  // Open the PWM unexport property
  if((myPWMUnexportFd = fopen("/sys/class/pwm/pwmchip0/unexport", "w")) == NULL)
  {
    printf("Error: cannot open PWM unexporter for writing\n");
    return false;
  }


  // Deactivate the required PWM channel
  fprintf(myPWMUnexportFd, "%d\n", anId);


  // Close the PWM enexport property
  fclose(myPWMUnexportFd);


  return true;
}
