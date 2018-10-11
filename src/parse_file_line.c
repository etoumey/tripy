#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* remove_leading_spaces_colons(char *input);

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
/*  Subroutines:  remove_leading_spaces_colons                           */
/*                                                                       */
/*************************************************************************/

int parse_file_line(char *ptr_file_name, int *raw_time, int *raw_hr)
{
   FILE *fp;
   char individual_line;
   char buffer[256];
   size_t len;
   char *ptr_b;
   int counter = 1;
   char buffer_nw[256];
   char time_buffer[6];
   char time_buffer_nc[6];
   char hr_buffer[4];  //hope HR is fewer than 3 characters LOL

   // variables for converting string to int
   long hour_ret;
   long minute_ret;
   long second_ret;
   
   char *ptr_conv;

   char hour_char_type[3];
   char minute_char_type[3];
   char second_char_type[3];

   int total_seconds;
   int hr;  // integer HR

   int time_counter;
   int hr_counter = 0;  //counter for how many characters in HR

   int start_time; // used to store start time in seconds
   int timer_reset_value;

   time_counter = 0;
   hr_counter = 0;  //initialize hr_counter

   // Open the *test* input file
//   fp = fopen("./TestGPX.gpx", "r");
   fp = fopen(ptr_file_name,"r");
   printf("Reading file...\n");
//   while(fgets(buffer, 256, fp))
   while(!feof(fp))
   {
      // Read the first string into the buffer, echo result
      fgets(buffer, 256, fp);

      //printf("Line: %d, %s",counter,buffer);

      // Strip leading spaces, echo result
      remove_leading_spaces_colons(buffer);
      //
      // Check if current line is a "<time" tag
      //
      if(strncmp(buffer,"<time",5) == 0)
      {
         strncpy(time_buffer, buffer + 17, 6); //was 17
         //getchar();
         // Now our time_buffer holds a 6-char string with hrs, minutes, seconds
         // let's convert to seconds
         // 
         strncpy(hour_char_type, time_buffer, 2);
         hour_char_type[2] = '\0';
         // printf("%s\n",hour_char_type);
         strncpy(minute_char_type, time_buffer + 2, 2);
         minute_char_type[2] = '\0';
         // printf("%s\n",minute_char_type);
         strncpy(second_char_type, time_buffer + 4, 2);
         second_char_type[2] = '\0';
         // printf("%s\n",second_char_type);

         hour_ret = strtol(hour_char_type, &ptr_conv, 10);
         //printf("%ld\n",hour_ret);

         //      printf("%ld\n",hour_ret);
         minute_ret = strtol(minute_char_type, &ptr_conv, 10);
         //printf("%ld\n",minute_ret);
         second_ret = strtol(second_char_type, &ptr_conv, 10);
         //printf("%ld\n", second_ret);
         // convert all items to seconds
         total_seconds = hour_ret * 3600 + minute_ret * 60 + second_ret;
         //printf("%d\n\n",total_seconds);
       
         // ** ASSUMPTION ABOUT *.GPX FILE ALERT **
         // The first "<time>" tag is by itself at the top of the file and
         // isn't associated with any data. If that is the time tag that 
         // we read, (assuming we will on the first instance of encountering 
         // the "<time>" tag) store this as the "start_time"
         if(time_counter < 1)
         {
            start_time = total_seconds;
         }  

         // After converting the current time string, loop through the following lines
         // until finding the HR tag
         do
         {     
            fgets(buffer,256,fp);
            remove_leading_spaces_colons(buffer);
         }while(strncmp(buffer,"<ns3hr",6));
         //while(strncmp(buffer,"<gpxtpxhr",9)); // Loop until buffer is HR tag

         // Once the line containing HR info is in the buffer, increment the HR counter 
         // until reaching the "<" part of "</gpxtpx:hr>" tag. This way, we know if the HR
         // is 2 or 3 characters
         //printf("%s", buffer);
         hr_counter = 0;
         do
         {
            hr_counter++;
         }while(strncmp(buffer + 6 + hr_counter, "<",1));

         // Copy the HR to a separate HR char array
         strncpy(hr_buffer, buffer + 1,hr_counter);
         printf("%s\n", hr_buffer);

         //hr_buffer[hr_counter+1] = '\0';
         // Normalize times by subtracting the start_time; this way the times in the 
         // array start at 0
         if(total_seconds - start_time < 0)
         {
            timer_reset_value = 86399;
         }
         else
         {
            timer_reset_value = 0;
         }
         raw_time[time_counter] = total_seconds - start_time + timer_reset_value;
         hr = strtol(hr_buffer, &ptr_conv, 10);
         raw_hr[time_counter] = hr;
         printf("%d hr %d time", hr, raw_time[time_counter]);
         //getchar();
         time_counter++;
      }         
      

      // increment line counter
      counter++;
   }
   printf("Total seconds (from parsed file): %d\n",raw_time[time_counter - 1]);
   raw_time[time_counter] = '\0';
   raw_hr[time_counter] = '\0'; //signify end of dataset

   // Close input file stream
   fclose(fp);
   printf("...Done reading file.\n");

   return(0);
}

char* remove_leading_spaces_colons(char *input)
{
   int ii,jj;

   ii = 0;
   jj = 0;

   while(input[ii] != '\0')
   {
      // check if character at current pointer location is not equal to a space and colon
      if(input[ii] != ' ' && input[ii] != ':')
      {
         // if yes, increment the "write" pointer jj and store the current value of the input
         // string to the location of the "write" pointer 
         input[jj++] = input[ii];
      }
      ii++;
   }
   // add NULL end-of-line character
   input[jj] = '\0';
   return(input);
}
