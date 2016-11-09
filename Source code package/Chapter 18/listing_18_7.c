float analogRead(int aPinNumber)
{
  int myRawVoltage;

  myRawVoltage = analogRawRead(int aPinNumber);

  return (myRawVoltage * 2 * 0.439453125);
}
