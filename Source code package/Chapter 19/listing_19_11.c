bool setPWMDutyCycle(int anId, long int aDutyCycle)
{
  FILE *myPWMDutyCycleFd;
  char myPath[256];


  // Manufacture a path to the PWM duty cycle property
  sprintf(myPath, "/sys/class/pwm/pwmchip0/pwm%d/duty_cycle", anId);


  // Open the PWM duty cycle property
  if((myPWMDutyCycleFd = fopen(myPath, "w")) == NULL)
  {
    printf("Error: cannot open PWM duty cycle for writing\n");
    return false;
  }


  // Activate the required PWM channel
  fprintf(myPWMDutyCycleFd, "%d\n", aDutyCycle);


  // Close the PWM duty cycle property
  fclose(myPWMDutyCycleFd);


  return true;
}
