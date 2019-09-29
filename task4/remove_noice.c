#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "remove_noice.h"

double remove_noice(double* data, int size)
{
	float sum;

	FILE *input_file;
	float num=0;

	input_file = fopen("remove_noice.dat", "w"); //open remove_noice.dat in write mode

	if(input_file != NULL) //check if file is open
	{
		for(int i=0;i<size-1;i++)
		{
			sum= (data[i]+data[i+1])/2;
			fprintf(input_file, "%f\n",sum);
		}
	}
	fclose(input_file); //close input_file

	
}