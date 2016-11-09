bool disablePWM(int anId)
{
  FILE *myPWMControlFd;
  char myPath[256];


  // Manufacture a path to the PWM enable property
  sprintf(myPath, "/sys/class/pwm/pwmchip0/pwm%d/enable", anId);


  // Open the PWM enble property
  if((myPWMControlFd = fopen(myPath, "w")) == NULL)
  {
    printf("Error: cannot open PWM enable for writing\n");
    return false;
  }


  // Disable the required PWM channel
  fprintf(myPWMControlFd, "0\n");


  // Close the PWM enable property
  fclose(myPWMControlFd);


  return true;
}
