#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "remove_noice.h"

double remove_noice(double* data, int size, int smooth)
{
	
	FILE *input_file;
	float aver;
	float sum;
	int round=0, i=0;

	if(smooth>size) return 0; //check if the num of average is greater than data size

	input_file = fopen("remove_noice.dat", "w"); //open remove_noice.dat in write mode

	if(input_file != NULL) //check if file is open
	{
		for(int i=0; i<(size-smooth); i++)
		{	
			sum=0;

			for(int j=0; j<smooth; j++)
			{
				sum+= data[i+j];
			}
			aver = sum/smooth;
			fprintf(input_file, "%f\n", aver);
			
		}

	}
		
	
	fclose(input_file); //close input_file

	
}