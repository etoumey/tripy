#include <stdio.h>

void get_input(int *a);

/*************************************************************************/
/*                                                                       */
/*  File:         main.c                                                 */
/*                                                                       */
/*  Date:         November 2015                                          */
/*                                                                       */
/*  Description:  Main driver file                                       */
/*                                                                       */
/*************************************************************************/

int main(void)
{
   // Variable declaration
   int lthr;
   
   get_input(&lthr);
   
   printf("your lthr is: %d BPM\n",lthr);
     
   return 0;
}
