#include <stdio.h>

/*************************************************************************/
/*                                                                       */
/*  File:         get_input.c                                            */
/*                                                                       */
/*  Date:         November 2015                                          */
/*                                                                       */
/*  Description:  Read in user inputs                                    */
/*                                                                       */
/*************************************************************************/

void get_input(char *a, int *b)
{
   //
   int input_check = 0;
   
   // 
   printf("Enter file name: \n");
   scanf("%c",a);
   //
   while (input_check != 1)
   {  
      printf("Enter threshold heart rate in BPM: \n");
      scanf("%d",b);
      //
      if (*b < 50 || *b > 215)
      {
         printf("!!! Please enter a reasonable LTHR !!!\n");
         input_check = 0;
      }
      else 
      {
         input_check = 1;
      }
   }
}
