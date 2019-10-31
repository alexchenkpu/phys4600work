#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include <string.h>
#include "inputdata.h"

void inputdata(int* startfrequceny,int* endfrequency,char* filename)
{
	float inputx;

	printf("Please enter start frequency with integer:\n");
	fflush(stdout); //print out above printf immediately
	int corr = scanf(" %f",&inputx); //scan the input first time
	while(corr != 1) //check input correction
	{
		if(corr != 1)
		{
		printf("Wrong, try again\n");
		fflush(stdin);
		corr = scanf(" %f",&inputx);
		}
	}
	printf("Start frequency is %f\n",inputx);
	*startfrequceny = inputx;

	printf("Please enter end frequency with integer:\n");
	fflush(stdout); //print out above printf immediately
	corr = scanf(" %f",&inputx); //scan the input first time
	while(corr != 1) //check input correction
	{
		if(corr != 1)
		{
		printf("Wrong, try again\n");
		fflush(stdin);
		corr = scanf(" %f",&inputx);
		}
	}
	printf("End frequency is %f\n",inputx);
	*endfrequency = inputx;

	printf("Please enter output file name:\n");
	fflush(stdout); //print out above printf immediately
	corr = scanf(" %c",filename); //scan the input first time
	while(corr != 1) //check input correction
	{
		if(corr != 1)
		{
		printf("Wrong, try again\n");
		fflush(stdin);
		corr = scanf(" %c",filename);
		}
	}
	printf("Output file name will be: ");
	for(int i=0;i<6;i++)
	{
		printf("%c",filename);
	}
}