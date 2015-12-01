#include <stdio.h>

void sort_zone(int interval_time, int raw_hr, float *zone_array);
/*************************************************************************/
/*                                                                       */
/*  File:         classify_heartrate.c                                   */
/*                                                                       */
/*  Date:         November 2015                                          */
/*                                                                       */
/*  Description:  Determine the time spent in each heart rate zone and   */
/*                populate the corresponding HR zone bin.                */
/*                                                                       */
/*  Inputs:       raw_time        memory address of array containing     */
/*                                time values                            */
/*                raw_hr          memory address of array containing the */
/*                                corresponding HR values                */
/*                                                                       */
/*************************************************************************/

void classify_heartrate(int raw_time[], int raw_hr[], float zone_array[])
{
   int ii, jj;
   int t_1, t_p1;
   int interval_time;
   int zone_bin[7] = {0};
   
   // Loop throught the time array. At each execution, store the current time and the next time 
   // to 2 variables and compute the difference. This is the time spent in the zone.
   // replace 200 with a computed string length
   for(ii = 0; ii < 200 - 1; ii++)
   { 
      // Save the current and plus 1 times
      t_1 = raw_time[ii];
      t_p1 = raw_time[ii + 1];

      interval_time = t_p1 - t_1;
      
      // Sort the HR at the current time -- add the elapsed time (between data recording points)
      // to the appropriate bin. Eventually functionalize with:
      // 
      //  sort_zone(interval_time, raw_hr[ii], zone_array);
      for(jj = 0; jj < 7; jj++)
      {
         if(raw_hr[ii] < zone_array[jj])
         {
            zone_bin[1] = zone_bin[1] + interval_time;
            printf("%d\n",zone_bin[1]);
         }
         else if(raw_hr[ii] < zone_array[jj])
         {
            zone_bin[2] = zone_bin[2] + interval_time;
         }
         else if(raw_hr[ii] < zone_array[jj])
         {
            zone_bin[3] = zone_bin[3] + interval_time;
         }
         else if(raw_hr[ii] < zone_array[jj])
         {
            zone_bin[3] = zone_bin[3] + interval_time;
         }
         else if(raw_hr[ii] < zone_array[jj])
         {
            zone_bin[4] = zone_bin[4] + interval_time;
         }
         else if(raw_hr[ii] < zone_array[jj])
         {
            zone_bin[5] = zone_bin[5] + interval_time;
         }
         else if(raw_hr[ii] < zone_array[jj])
         {
            zone_bin[6] = zone_bin[6] + interval_time;
         }
         else if(raw_hr[ii] < zone_array[jj])
         {
            zone_bin[7] = zone_bin[7] + interval_time;
         }
      }
      interval_time = 0; // reset 
   }
   // ** test print ** 
   for(ii = 0; ii < 7;ii++)
   {
      printf("%d\n",zone_bin[ii]);
   }

}

/*
void sort_zone(int interval_time, int raw_hr, float *zone_array[])
{
   int ii;

   for(ii = 0; ii < 6; ii++)
   {
      if(raw_hr < zone_
   }
}
*/
