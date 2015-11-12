#include<stdio.h>
#include<math.h>

/*************************************************************************/
/*                                                                       */
/*  File:         file_process.c                                         */
/*                                                                       */
/*  Date:         November 2015                                          */
/*                                                                       */
/*  Description:  open file, parse HR and duration data                  */
/*                                                                       */ 
/*  Inputs:     raw_data       memory address of array for HR & duration */
/*              ptr_file_name  memory address of input file name         */
/*                                                                       */
/*************************************************************************/

void file_process(float *raw_data, char *ptr_file_name)
{
  //Declarations
  FILE *fp;
  char c;
  int r = 0;  //current row counter
  int inputCheck;
  char *line[300]; 
  char *currentTime[10];  
//Statements
  fp = fopen("/home/etoumey/Documents/tss_estimator/src/TestGPX.gpx", "r");
  
  //ensure file exists and opened
  if(fp ==  NULL)
  {
    printf("file did not open");
  }
  else  //good to go, calculation time
  {
    c = fgetc(fp);  //initial read
    do
    {
      if(c == 't')
      {
        c = fgetc(fp);
        if(c == 'i')
        {
          c = fgetc(fp);
          if(c == 'm')
          {
            c = fgetc(fp);
            if(c == 'e')
            {
              printf("time tag found\n");
            }
          }
        }
      }
      else        
      {
        c = fgetc(fp);
      }      
    }while(!feof(fp));
    fclose(fp);
  }  
}
