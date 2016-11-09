#include <stdio.h>

int main()
{
  FILE *fp;
  char str[60];

  /* open a file for reading */
  fp = fopen("/etc/fedora-release" , "r");

  if(fp == NULL)
  {
    perror("Error opening file");
    return(-1);
  }
  if( fgets (str, 60, fp)!= NULL )
  {
    /* write the file content to stdout */
    puts(str);
  }
  fclose(fp);

  return(0);
}