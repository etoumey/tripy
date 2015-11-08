#include <stdio.h>

void get_input(char *ptr_file_name, int *ptr_lthr);

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
   // echo your input   
   printf("File name   : %c\n",file_name);
   printf("File length : %d\n",sizeof(file_name));   
   printf("your lthr is: %d BPM\n",lthr);
   //
   // DECODE *.FIT FILE: using "fitSDK"
   //
   //decode_fit(&file_name);

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
