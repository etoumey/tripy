#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void get_input(char *ptr_file_name, float *ptr_lthr, int argc, char **argv)
{
   int r;
   char is_string_buffer[30];
   //
   if(argc == 1)
   {
      printf("\nEnter file name : ");
      fgets(ptr_file_name, 255, stdin);

      printf("\nEnter LTHR [bpm]:");
      scanf("%f", ptr_lthr);
   }

   if(argc == 2)
   {
      
      r = sscanf(argv[1], "%s", is_string_buffer); 
      if(r == 1)
      {
         printf("cmd line arg is string\n");
      }
   }

   printf("argc value in get_input: %d\n",argc);

   if(argc != 2)
   {
      // Echo the instructions for specifying a file from cmd line
      printf("To calculate stress for a file, use: '%s filename'\n", argv[0]);
      printf("For testing purposes, we will load 'TestGPX.gpx' anyway.\n");
      // *** HACK FOR TESTING *** 
      // If you run the program w/o supplying a file name, the following line
      // sets it to the test *.gpx file automatically.
      strcpy(ptr_file_name, "TestGPX.gpx");      
   }
   else
   { 
      FILE *file = fopen( argv[1], "r");
      if(file == 0) 
      {
         // If the file pointer is null, terminate the program
         printf("File not found. Terminating...\n");
        // fclose(file);
         exit(EXIT_SUCCESS);
      }
      else
      {
         strcpy(ptr_file_name,argv[1]);
      }
   } 

   printf("input file name before exiting get_input: %s\n",ptr_file_name);
/*   int input_check = 0;
    
   while (input_check == 0)
   {
      // fix this with input checking
      printf("\nEnter file name: ");
      fgets(ptr_file_name, 255, stdin);
      printf("\nFile name echo: %s", ptr_file_name);
      input_check = 1;
   }
  
   
   //
   input_check = 0;
   while (input_check == 0)
   {  
      printf("\nEnter threshold heart rate in BPM: ");
      if(scanf("%f", ptr_lthr))
      {
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
      else
      {
	printf("enter a number yo");
        input_check = 0;
        *ptr_lthr = 0;
      }
   }
*/
}

