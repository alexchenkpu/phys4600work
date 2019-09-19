#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	FILE *input_file;
	float num=0;

	input_file = fopen("data.dat", "w"); //open data.dat in write mode

	if(input_file != NULL) //check if file is open
	{
		for(float i=num;i<=(2*M_PI);i+=(M_PI/10))
		{
			num = sin(i);
			fprintf(input_file, "%f %f\n",i,num);
		}
	}
	fclose(input_file); //close input_file
	
}