#include <stdio.h>
#include <string.h>

#define SEC_PER_HOUR 3600.

/*************************************************************************/
/*                                                                       */
/*  File:         calc_stress.c                                          */
/*                                                                       */
/*  Date:         December 2015                                          */
/*                                                                       */
/*  Description:  Use the time (in seconds) spent in each heart rate     */
/*                to approximate the physiological stress                */
/*                each <time> tag.                                       */
/*                                                                       */
/*  Inputs:                                                              */
/*                                                                       */
/*************************************************************************/

void calc_stress(int *zone_bin, float *total_stress)
{
   // I adapted the following stress correlation from djconnel.blogspot.com
   // Units are in [1/hr]

   float stress_correlation[7] = {12., 24., 45., 100., 120., 160., 220.};
   float zone_bin_hour[7] = {0};
 
   int ii = 0;


   // Convert the time in each zone (passed in with units [seconds]) to [hours]
   // calculate stress for each zone and sum

   for(ii = 0;ii < 6;ii++)
   {
      zone_bin_hour[ii] = zone_bin[ii] / SEC_PER_HOUR;
      *total_stress = *total_stress + zone_bin_hour[ii] * stress_correlation[ii];
   }
}
