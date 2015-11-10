#include <stdio.h>
#include <math.h>

/*************************************************************************/
/*                                                                       */
/*  File:         calc_hr_zones.c                                        */
/*                                                                       */
/*  Date:         November 2015                                          */
/*                                                                       */
/*  Description:  Calculate HR zones based on user's LTHR input          */
/*                                                                       */
/*  Inputs:       ptr_lthr        memory address of threshold HR         */
/*                ptr_zone_array  memory address of array with HR zone   */
/*                                maximums                               */
/*                                                                       */
/*************************************************************************/

void calc_hr_zones(float *ptr_lthr, float *ptr_zone_array)
{
   // variable declarations
   
   // used only in this function
   int ii;
   float zone_percent[6] = {0.81, 0.89, 0.93, 0.99, 1.02, 1.06};

   // zone_mode = 1 is for BIKE zones, hard-coded for now
   // use structs to switch between bike/run arrays

   // each entry in zone_array represents the maximum HR for that zone

   for (ii = 0;ii < 6;ii++)
   {
      // possible ceiling function
      ptr_zone_array[ii] = ceil(zone_percent[ii] * *ptr_lthr);
      printf("\n%f\n",ptr_zone_array[ii]);
   }
}
