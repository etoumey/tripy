#include <stdio.h>


int convert_fit_file(char *ptr_file_name)
{

   FILE *ptr_myfile;
   // hard code for now
   ptr_myfile = fopen("jan11-trainer.fit","rb");
   if (!ptr_myfile)
   {
      printf("*** Cannot open file. *** \n");
   }
    
   fread(


   return(0);
} 
