#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "curve.h"


double find_amplitude(double* data, int size)
{
	float max=0, min=0, amplitude;

	for(int i=0;i<size;i++)
	{
		if(data[i]>max)
		{
			max=data[i];
		}
	}
	
	for(int i=0;i<size;i++)
	{
		if(data[i]<min)
		{
			min=data[i];
		}
	}

	amplitude = (max-min)/2;

	return (amplitude);
}