// Based on an example found at http://elinux.org/

// Define access to the operating system library functions
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>


// Define some manifest constants to describe the memory layout
#define PAGE_SIZE (4*1024)
#define BLOCK_SIZE (4*1024)


// Define the base address for the GPIO registers in virtual memory
#define GPIO_BASE 0x11400000


// Define the global variables
int  mem_fd;
char *gpio_mem
unsigned char *gpio_map;
volatile unsigned *gpio;


// Main application body
int main(int argc, char* argv[])
{


  // Open the kernel provided memory image
  if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0)
  {
    printf("cannot open /dev/mem \n");
    exit (-1);
  }


  // Allocate some space to map the memory into
  if ((gpio_mem = malloc(BLOCK_SIZE + (PAGE_SIZE-1))) == NULL)
  {
    printf("allocation error \n");
    exit (-1);
  }


  // Adjust the pointer to locate it on a 4K boundary
  if ((unsigned long)gpio_mem % PAGE_SIZE)
  {
   gpio_mem += PAGE_SIZE - ((unsigned long)gpio_mem % PAGE_SIZE);
  }



  // Map the kernel memory image into application memory space
  gpio_map = (unsigned char *)mmap((caddr_t)gpio_mem,
                                   BLOCK_SIZE,
                                   PROT_READ|PROT_WRITE,
                                   MAP_SHARED|MAP_FIXED,
                                   mem_fd,
                                   GPIO_BASE);


  // Now check that the mapping worked
  if ((long)gpio_map < 0)
  {
    printf("mmap error %d\n", (int)gpio_map);
    exit (-1);
  }


  // Preserve the mapped GPIO pointer
  gpio = (volatile unsigned *)gpio_map;


  // Dump out the contents of the mapped GPIO memory
  int i;
  printf("Memory dump\n");
  for(i=0; i<10;i++)
  {
    printf("GPIO memory address=0x%08x: 0x%08x\n",
                               (unsigned int)gpio+i,
                               *(gpio+i));
  }



// Return a result code
return 0;
}