#include <stdio.h>

/*************************************************************************/
/*                                                                       */
/*  File:         parse_file_line.c                                      */
/*                                                                       */
/*  Date:         November 2015                                          */
/*                                                                       */
/*  Description:  Parse the input *.gpx file, looking for HR data after  */
/*                each <time> tag.                                       */
/*                                                                       */
/*  Inputs:       ptr_lthr        memory address of threshold HR         */
/*                                                                       */
/*************************************************************************/

int parse_file_line(char *ptr_file_name)
{
   FILE *fp;
   char individual_line;
   char buffer[100];
   size_t len;

   fp = fopen("./TestGPX.gpx", "r");
   
      
   fgets(buffer, 256, fp);

   printf("%s\n",buffer);

   return(0);
}
