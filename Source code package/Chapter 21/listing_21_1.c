int SpiWriteAndRead (unsigned char *data, int length)
{
  struct spi_ioc_transfer spi[length];
  int i;
  int retVal;

  //one spi transfer for each byte
  for (i = 0 ; i < length ; i++)
  {
    memset(&spi[i], 0, sizeof (spi[i]));
    spi[i].tx_buf        = (unsigned long)(data + i); // transmit from "data"
    spi[i].rx_buf        = (unsigned long)(data + i) ; // receive into "data"
    spi[i].len           = sizeof(*(data + i)) ;
    spi[i].delay_usecs   = 0 ;
    spi[i].speed_hz      = spi_speed ;
    spi[i].bits_per_word = spi_bitsPerWord ;
    spi[i].cs_change = 0;
  }

  retVal = -1;
  retVal = ioctl(*spi_cs_fd, SPI_IOC_MESSAGE(length), &spi) ;

  if(retVal < 0)
  {
    perror("Error - Problem transmitting spi data..ioctl");
    exit(1);
  }

  return retVal;
}
