#include <stdio.h>
#define SIZE 20000
void get_input(char *ptr_file_name, float *ptr_lthr);
void calc_hr_zones(float *ptr_lthr, float *zone_array);
void file_process(float *raw_data, char *ptr_file_name);
char parse_file_file(char *ptr_file_name, int *raw_time, int *raw_hr);
void classify_heartrate(int *raw_time, int *raw_hr, float *zone_array);
void calc_stress(int *zone_bin);

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
   char file_name [30] = { '\0' };
   float lthr;
   float zone_array [6];
   int raw_time [SIZE] = {0};
   int raw_hr [SIZE] = {0};
   int x,y;
   //
   // GET INPUT: LTHR, desired *.fit file name
   //
//   get_input(&file_name[30], &lthr);
   // echo your input   
//   printf("\nFile name   : %s", &file_name);
//   printf("\nFile length : %zu",sizeof(file_name));   
//   printf("\nYour lthr is: %f BPM",lthr);

   //
   // CALCULATE HR ZONES: hr zones from Joe Friel
   // 
   lthr = 145.0; // [bpm], hard-coded for testing 
   calc_hr_zones(&lthr, zone_array);
/*   for (ii = 0;ii < 6;ii++)
   {
      printf("\n%f\n",zone_array[ii]);
   }*/
   //
   // DECODE *.FIT FILE: using "fitSDK"
   //
   //decode_fit(&file_name);

   //
   // PARSE XML FILE: look at the HRs in the 'decoded' *.fit file
   //
//   file_process(&raw_data[1000][2], &file_name[30]);

   parse_file_line(&file_name[30], &raw_time, &raw_hr);
   //for(x=0; x<10; x++)
   //{
   //   printf("raw_data[%i]: %i %i\n", x, raw_time[x], raw_hr[x]);
      
   //}


   //
   // SORT HR: figure out time spent in each zone
   //
   classify_heartrate(raw_time, raw_hr, zone_array);
   //
   // CALCULATE STRESS: using formula from excel sheet
   //
   calc_stress(zone_bin);
   //
   // WRITE RESULTS: to screen, or file 
   //
  
  printf("\n");  //clean up the end of prog

   return 0;
}
