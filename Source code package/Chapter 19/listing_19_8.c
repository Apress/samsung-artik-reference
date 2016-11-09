bool initialisePWMChannel(int anId)
{
  FILE *myPWMExportFd;

  // Open the PWM export property
  if((myPWMExportFd = fopen("/sys/class/pwm/pwmchip0/export", "w")) == NULL)
  {
    printf("Error: cannot open PWM exporter for writing\n");
    return false;
  }


  // Activate the required PWM channel
  fprintf(myPWMExportFd, "%d\n", anId);


  // Close the PWM export property
  fclose(myPWMExportFd);


  return true;
}
