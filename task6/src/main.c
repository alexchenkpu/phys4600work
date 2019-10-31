#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include "setfgreadscope.h"
#include "openscope.h"
#include "openfuncg.h"
#include "outputdata.h"

void main(int argc, char** argv)
{
	ViStatus status = VI_SUCCESS;
	ViSession defaultRM, scopeHandle, funcHandle;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[2500];
	unsigned char resultBuffer[256], filename[30];
	double amplitude[2500], frequency[2500];
	int datacount;

	status = viOpenDefaultRM(&defaultRM); //start the VISA interface
	if(status == VI_SUCCESS)
	{
		openscope(defaultRM, &scopeHandle);

		openfuncg(defaultRM, &funcHandle);

		setfgreadscope(funcHandle,scopeHandle,amplitude,frequency,&datacount,filename);

		outputdata(amplitude, frequency, datacount);
	}
	else {printf("Failed to open defaultRM\n"); exit(EXIT_FAILURE);}
}