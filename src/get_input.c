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
   int lthr_flag;
   char is_string_buffer[30];
   char *ptr_conv;
   char file_name_buffer[30];
   //
   // The user specified no cmd line arguments. Query for both
   //
   if(argc == 1)
   {
      printf("\nEnter file name : ");
      fgets(file_name_buffer, 255, stdin);
      strcpy(ptr_file_name,file_name_buffer);

      printf("\nEnter LTHR [bpm]:");
      scanf("%f", ptr_lthr);
   }
   //
   // The user specified one argument. Find out if it is only digits (=> LTHR)
   //
   else if(argc == 2)
   {
      if(strspn(argv[1], "0123456789.") == strlen(argv[1]))
      {
         printf("string only numbers\n");
         lthr_flag = 1;
      }      
      else
      {
         printf("string has characters that are not numbers\n ");
         lthr_flag = 0;
      }
      if(lthr_flag == 0)
      {
         printf("\nEnter LTHR [bpm]:");
         scanf("%f", ptr_lthr);
         //
         strcpy(ptr_file_name, argv[1]);
      }
      else
      {
         printf("\nEnter file name : ");
         fgets(ptr_file_name, 255, stdin);
         //
         *ptr_lthr = strtol(argv[1], &ptr_conv, 10);
      }
   }
   //
   // The user specified both arguments. Find out which is which
   //
   else if(argc == 3)
   {
      lthr_flag = 0;
      if(strspn(argv[1], "0123456789.") == strlen(argv[1]))
      {
         printf("string only numbers\n");
         lthr_flag = 1;
      }      
      if(lthr_flag == 0)
      {
         strcpy(ptr_file_name, argv[1]);
         *ptr_lthr = strtol(argv[2], &ptr_conv, 10);
      }
      if(lthr_flag == 1)
      {
         *ptr_lthr = strtol(argv[1], &ptr_conv, 10);
         strcpy(ptr_file_name, argv[2]);
      }
   } 

   printf("File name: %s\n", ptr_file_name);
   printf("LTHR     : %f\n", *ptr_lthr);
/*
   //
   // Validate the input 
   //
   FILE *file = fopen(ptr_file_name, "r");
   if(file == 0) 
   {
      // If the file pointer is null, terminate the program
      printf("File not found. Terminating...\n");
     // fclose(file);
      exit(EXIT_SUCCESS);
   }
*/
}
