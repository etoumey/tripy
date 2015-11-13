#include <stdio.h>

char *strip_spaces(char *str);

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
   char buffer[256];
   size_t len;
   char *ptr_b;
   int counter = 1;
   char buffer_nw[256];

   fp = fopen("./TestGPX.gpx", "r");
   
   printf("Reading file...\n");
//   while(fgets(buffer, 256, fp))
   while(counter < 10)
   {
      fgets(buffer, 256, fp);
      printf("Line: %d, %s\n",counter,buffer);

      sscanf(buffer,"%s",buffer_nw);

      printf("%s\n",buffer_nw);

//      ptr_b = strip_spaces(&buffer[256]);      
      //printf("%s\n",&ptr_b);
      counter++;
   }
   fclose(fp);

   return(0);
}

char *strip_spaces(char *str)
{
   char *end;

   while(isspace(str[256]))
   {
       str++;
   }

   return(str);
}
