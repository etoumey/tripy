#include <stdio.h>

/*************************************************************************/
/*                                                                       */
/*  File:         get_input.c                                            */
/*                                                                       */
/*  Date:         November 2015                                          */
/*                                                                       */
/*  Description:  Read in user inputs                                    */
/*                                                                       */
/*  Inputs:       ptr_file_name  memory address of input file name       */
/*                ptr_lthr       memory address of threshold HR          */
/*                                                                       */
/*************************************************************************/

void get_input(char *ptr_file_name, int *ptr_lthr)
{
   //
   int input_check = 0;
   
   // 
   while (input_check != 1)
   {
      printf("Enter file name: \n");
      scanf("%c",ptr_file_name);
      // fix this with input checking
      // verify if no *.tcx extension, read correct file
//      if (*ptr_file_name )
      input_check = 1;
   }  


   //
   input_check = 0;
   while (input_check != 1)
   {  
      printf("Enter threshold heart rate in BPM: \n");
      scanf("%d",ptr_lthr);
      //
      if (*ptr_lthr < 50 || *ptr_lthr > 215)
      {
         printf("\n!!! Please enter a reasonable LTHR !!!\n\n");
         input_check = 0;
      }
      else 
      {
         input_check = 1;
      }
   }
}
