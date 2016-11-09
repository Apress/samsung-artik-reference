#include <stdio.h>

// Declare and initialisevariables
int inputPin = 1;
int currentRun = 0;
const int MAX_RUNS = 10;

int main(void)
{

  while(currentRun < MAX_RUNS){

    int sensorVal = analogRead(inputPin);

    printf("current sensor is %f\n", sensorVal);

    /* Convert sensor data to temperature */

    currentRun++;

    sleep(1);

  }
}
