#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program a physicist would write! remember to use the -lm option with your compiler when including this file */ 


void main(int argc, char** argv)
{
	int data_count=0;
	float x,y;
	float sum=0; //sum for calculate mean
	float sum1=0; //sum for calculate squared difference
	float mean;
	float std_dev;

	FILE *input_file;

	input_file = fopen(argv[1],"r"); //open the name that type after command gcc

	//input_file = fopen("data.dat","r"); //open data.dat for read

	if(input_file != NULL) //check if the file is open
	{	
		while(fscanf(input_file,"%f %f",&x,&y) != EOF)
		{
			data_count ++;
		}
	}
	else
	{
		printf("Couldn't open the entered file");
		return;
	}

	/*  ==== START OF YOUR CODE ==== */

	float x_axis[data_count];
	float data[data_count];
	
	/* JAMES: Probably don't need to check this again here - if it had been NULL we would
	have already exited at the last check. However it would be a good idea to check if 
	data_count > 0 */

	if(input_file != NULL) //check if the file is open
	{	
		rewind(input_file);

		for(int i=0;i<data_count;i++)
		{
			if(fscanf(input_file,"%f %f",&x_axis[i],&data[i]) == EOF) //EOF is end of the file
			{
				printf("The number output ended\n");
				break;
			}
		}
		printf("data count = %d\n",data_count);
		fclose(input_file);

		/*for(int i=0;i<data_count;i++)
		{
			printf("%f\n",data[i]);
		}*/

		for(int i=0;i<data_count;i++)
		{
			sum += data[i];
		}
		mean = sum/data_count;

		//calculate standard deviation
		for(int i=0;i<data_count;i++) //sum of squared differences
		{
			sum1 += pow((data[i]-mean),2);
		}
	
		std_dev= sqrt(sum1/(data_count-1));

		/* JAMES: You run through your data twice here, 
		this is a bit inefficient - maybe a more efficient method? */

		printf("\nMean = %f", mean);
		printf("\nStandard deviation = %f", std_dev);
	}
	else
	{
		printf("Couldn't open the input_file");
	}

	

	/*  ==== END OF YOUR CODE ==== */
	return;  // Functions which return a value MUST contain at least one return statement
}