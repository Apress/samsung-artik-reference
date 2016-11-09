bool setCoherentTimingProperties(int anId, long int aDuration, int aPercentage)
{
  long int myDutyCycle;

  if(!setPWMDuration(anId, aDuration))
  {
    printf("Duration setting failed");
    return false;
  }


  // Calculate the duty cycle as a proportion of the duration period
  myDutyCycle = (aDuration * aPercentage)/100;


  if(setPWMDutyCycle(anId, myDutyCycle))
  {
    printf("Duty cycle setting failed");
    return false;
  }

  return true;
}
