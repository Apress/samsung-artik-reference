// Open a PID file for writing
FILE *myPidFd;

if((myPidFd = fopen("/run/my_application.pid", "w")) == NULL)
{
  printf("Error: unable to write PID file\n");
  return false;
}


// Store the PID value
fprintf(myPidFd, "%d\n", getpid());


// Close the pid file
fclose(myPidFd);
