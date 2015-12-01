#include <stdio.h>

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

void classify_heartrate(int raw_time[], int raw_hr[])
{
   int ii;
   int t_1, t_p1;


   // replace 200 with a computed string length
   for(ii = 0; ii < 200; ii++)
   { 
      //
      t_1 = raw_time[ii];
      t_p1 = raw_time[ii + 1];
//      printf("%d\n",raw_hr[ii]);
      printf("%d :: %d\n",t_1,t_p1);
   }

}
