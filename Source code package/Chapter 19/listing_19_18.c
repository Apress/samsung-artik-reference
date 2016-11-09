bool setPWMFrequency(int anId, int aHzValue, int aPercentage)
{
  long int myDuration;


  // Convert the frequency into a duration
  myDuration = 1000000000/aHzValue;


  // Call the property setting function to set things up
  setCoherentTimingProperties(anId, myDuration, aPercentage);

}
