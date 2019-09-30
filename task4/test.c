#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "curve.h"
#include "random.h"
#include "remove_noice.h"

void main(int argc, char** argv)
{
	float x;
	int count=0, count2=0;
	float amplitude;
	FILE *input_file;

	input_file = fopen(argv[1],"r");

	if(input_file != NULL)
	{
		while(fscanf(input_file,"%f",&x) != EOF)
		{
			count++;
		}
		double data[count];

		rewind(input_file);
		for(int i=0;i<count;i++)
		{
			if(fscanf(input_file,"%lf",&data[i]) == EOF) //EOF is end of the file
			{
				//printf("The number output ended\n");
				break;
			}
		}
		fclose(input_file);
		amplitude = find_amplitude(data,count);
		printf("amplitude = %f\n", amplitude);

		//random(count);

		input_file = fopen("random.dat","r");

		if(input_file != NULL)
		{
			while(fscanf(input_file,"%f",&x) != EOF)
			{
				count2++;
			}
			double data2[count2];

			rewind(input_file);
			for(int i=0;i<count2;i++)
			{
				if(fscanf(input_file,"%lf",&data2[i]) == EOF) //EOF is end of the file
				{
					break;
				}
			}
			fclose(input_file);
			remove_noice(data2, count2, 5);
		}
		

		
	}
	else
	{
		printf("Couldn't open the target file");
		return;
	}

	

}