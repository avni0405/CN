
/**************************************************

file: demo_tx.c
purpose: simple demo that transmits characters to
the serial port and print them on the screen,
exit the program by pressing Ctrl-C

compile with the command: gcc demo_tx.c rs232.c -Wall -Wextra -o2 -o test_tx

**************************************************/

#include <stdlib.h>
#include <stdio.h>

//#ifdef _WIN32
//#include <Windows.h>
//#else
#include <unistd.h>
//#endif

#include "rs232.h"



int main()
{
  int 
      cport_nr=0,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=9600;       /* 9600 baud */

  char mode[]={'8','N','1',0};
       char str='A';




  //strcpy(str[1], "Happy serial programming!\n");


  if(RS232_OpenComport(cport_nr, bdrate, mode))
  {
    printf("Can not open comport\n");

    return(0);
  }

  while(1)
  {
     RS232_SendByte(cport_nr,str);
    printf("sent: %c\n", str);

//#ifdef _WIN32
  //  Sleep(1000);
//#else
    usleep(1000000);  /* sleep for 1 Second */
//#endif

    //i++;

    //i %= 2;
  }

  return(0);
}

