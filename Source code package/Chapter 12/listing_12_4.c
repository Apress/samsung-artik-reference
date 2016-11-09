#include <string.h>
#include <unistd.h>

int main()
{
  char myHostname[] = "MY-ARTIK";

  sethostname(myHostname, strlen(myHostname));

  return 0;
}
