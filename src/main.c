#include <stdio.h>

void get_input(char *ptr_file_name, float *ptr_lthr);
void calc_hr_zones(float *ptr_lthr, float *zone_array);
void file_process(float *raw_data, char *ptr_file_name);
char parse_file_file(char *ptr_file_name, int *raw_time, int *raw_hr);

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
   int ii;
   char file_name[30] = { '\0' };
   float lthr;
   float zone_array[6];
   int raw_time[20] = {0};
   int raw_hr[20] = {0};
   int x,y;
   //
   // GET INPUT: LTHR, desired *.fit file name
   //
   get_input(&file_name[30], &lthr);
   // echo your input   
//   printf("\nFile name   : %s", &file_name);
//   printf("\nFile length : %zu",sizeof(file_name));   
   printf("\nYour lthr is: %f BPM",lthr);

   //
   // CALCULATE HR ZONES: hr zones from Joe Friel
   // 
   calc_hr_zones(&lthr, zone_array);
   
   //
   // DECODE *.FIT FILE: using "fitSDK"
   //
   //decode_fit(&file_name);

   //
   // PARSE XML FILE: look at the HRs in the 'decoded' *.fit file
   //
//   file_process(&raw_data[1000][2], &file_name[30]);

   parse_file_line(&file_name[30], &raw_time, &raw_hr);
   for(x=0; x<10; x++)
   {
      printf("raw_data[%i]: %i %i\n", x, raw_time[x], raw_hr[x]);
      
   }


   //
   // SORT HR: figure out time spent in each zone
   //

   //
   // CALCULATE TSS: using formula from excel sheet
   //

   //
   // WRITE RESULTS: to screen, or file 
   //
  
  printf("\n");  //clean up the end of prog

   return 0;
}
