char myPath[256];
int myChannel;

myChannel = 0;

sprintf(myPath, "/sys/class/pwm/pwmchip0/pwm%d/", myChannel);
