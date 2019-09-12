#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program a physicist would write! remember to use the -lm option with your compiler when including this file */ 

float meanf(float* inp,int len)
{
	float sum=0;
	float mean;

	for(int i=0;i<len;i++) //sum of data
	{
		sum = sum + inp[i];
	}

	//printf("\nSum= %f",sum);

	mean = sum/len;	

	return mean;
}


float std_devf(float* data,float mean, int len)
{
	float sum1=0; //sum for calculate squared difference
	float std_dev;
	
	for(int i=0;i<len;i++) //sum of squared differences
	{
		sum1 += pow((data[i]-mean),2);
	}
	
	std_dev= sqrt(sum1/(len-1));

	return std_dev;
}

float mean_std_dev(float* data, float* std_dev, int len)
{
	float sum=0;
	float mean;
	float sum1=0; //sum for calculate squared difference

	for(int i=0;i<len;i++) //sum of data
	{
		sum += data[i];
	}
	//printf("\nSum= %f",sum);

	mean = sum/len;

	for(int i=0;i<len;i++) //sum of squared differences
	{
		sum1 += pow((data[i]-mean),2);
	}
	
	*std_dev= sqrt(sum1/(len-1));

	return mean;
}

int main()
{
	float data [] ={0.068038, 0.173967, 0.439303, 0.615258, 0.789436, 0.770980, 0.890924, 1.034431, 0.955555, 0.991579, 0.919359, 0.857244, 0.680064, 0.558250, 0.473129, 0.278329, 0.027142, -0.151631, -0.454363, -0.534177, -0.803847, -0.882892, -0.996433, -0.919950, -1.068664, -1.000596, -0.997921, -0.909708, -0.607322, -0.611919, -0.380097, -0.127268};
	//float sum=0; //sum for calculate mean
	float mean;
	float std_dev;

	/*	Here you can put the code to find the standard deviation of the data array	*/


	/*  ==== START OF YOUR CODE ==== */
	//part1
	mean = meanf(data,32); //call the function calculate mean
	std_dev = std_devf(data,mean,32); //calculate standard deviation

	//part2
	//mean = mean_std_dev(data,&std_dev,32);	

	/*  ==== END OF YOUR CODE ==== */


	/* These lines will output the results to console */

	printf("\nMean = %f", mean);
	printf("\nStandard deviation = %f", std_dev);
	//printf("\nStandard deviation = %f", std_dev); //std_dev for combined function

	
	return 0;  // Functions which return a value MUST contain at least one return statement
}