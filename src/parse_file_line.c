#include <stdio.h>
#include <string.h>

char* strip_leading_spaces(char *input);

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
   char time_buffer[8];
   char time_buffer_nc[6];
   int i,j;

   // variables for converting string to int
   long hour_ret;
   long minute_ret;
   long second_ret;
   
   char *ptr_conv;

   char hour_char_type[3];
   char minute_char_type[3];
   char second_char_type[3];
   //

   i = 0;
   j = 0;

   // Open the *test* input file
   fp = fopen("./TestGPX.gpx", "r");
   
   printf("Reading file...\n");
//   while(fgets(buffer, 256, fp))
   while(counter < 200)
   {
      // Read the first string into the buffer, echo result
      fgets(buffer, 256, fp);
      printf("Line: %d, %s",counter,buffer);

      // Strip leading spaces, echo result
      strip_leading_spaces(buffer);
      if(strncmp(buffer,"<time",5) == 0)
      {
         printf("Line: %d, %s\n",counter,buffer);
      }

      if(strncmp(buffer,"<time",5) == 0)
      {
         printf(":)\n");
         strncpy(time_buffer, buffer + 17, 6);
         printf("%s\n",time_buffer);
      }
      // Now our time_buffer holds a 6-char string with hrs, minutes, seconds
      // let's convert to seconds
      // 
      strncpy(hour_char_type, time_buffer, 2);
      hour_char_type[2] = '\0';
      printf("%s\n",hour_char_type);
      strncpy(minute_char_type, time_buffer + 2, 2);
      minute_char_type[2] = '\0';
      printf("%s\n",minute_char_type);
      strncpy(second_char_type, time_buffer + 4, 2);
      second_char_type[2] = '\0';
      printf("%s\n",second_char_type);
//      hour_ret = strtol(time_buffer, &ptr_conv, 10);
  //    printf("%ld\n",hour_ret);

      counter++;
   }


   // Close input file stream
   fclose(fp);

   return(0);
}

char* strip_leading_spaces(char *input)
{
   int i,j;

   i = 0;
   j = 0;

   while(input[i] != '\0')
   {
      // check if current pointer location is not equal to a space and colon
      if(input[i] != ' ' && input[i] != ':')
      {
         input[j++] = input[i];
      }
      i++;
   }
   input[j] = '\0';
   return(input);
}
