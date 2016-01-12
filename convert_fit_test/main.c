#include <stdio.h>
#include <string.h>


// Function declaration
int convert_fit_file(char *ptr_file_name); 


// main driver
int main()
{
   char file_name[30] = { '\0' };
   strcpy(file_name,"jan11-trainer.fit");
   
   convert_fit_file(file_name);

   return(0);
}
