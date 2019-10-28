#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void outputdata(double* amplitude, double* frequency, int datacount)
{
	FILE *input_file;

	input_file = fopen("data.dat", "w"); //open data.dat in write mode

	if(input_file != NULL) //check if file is open
	{
		for(int i=0;i<datacount;i++)
		{
			fprintf(input_file, "%lf %lf\n",frequency[i],amplitude[i]);
		}
	}
	fclose(input_file); //close input_file
	
}