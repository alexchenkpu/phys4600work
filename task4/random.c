#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "random.h"

double random(int size)
{
	FILE *input_file;
	input_file = fopen("random.dat","w");
	srand(time(NULL));
	float ran;
	float num;

	if(input_file != NULL) //check if file is open
	{
		for(float i=num;i<=(2*M_PI);i+=(M_PI/10))
		{
			num = sin(i);
			ran = (float)rand()/(float)RAND_MAX;
			num += (ran/5);
			fprintf(input_file, "%f\n",num);
		}
	}
	fclose(input_file); //close input_file

}