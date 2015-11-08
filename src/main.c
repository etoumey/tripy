#include <stdio.h>

void get_input(char *a, int *b);

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
   char file_name;
   int lthr;
   //
   // GET INPUT: LTHR, desired *.fit file name
   //
   get_input(&file_name, &lthr);
   
   printf("File name   : %c\n",file_name);   
   printf("your lthr is: %d BPM\n",lthr);
   //
   // DECODE *.FIT FILE: using "fitSDK"
   //


   //
   // PARSE XML FILE: look at the HRs in the 'decoded' *.fit file
   //

   //
   // SORT HR: figure out time spent in each zone
   //

   //
   // CALCULATE TSS: using formula from excel sheet
   //

   //
   // WRITE RESULTS: to screen, or file 
   //
  
   return 0;
}
