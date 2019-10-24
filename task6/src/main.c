#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include "setfgreadscope.h"

void main(int argc, char** argv)
{
	ViStatus status = VI_SUCCESS;
	ViSession defaultRM, scopeHandle, funcHandle;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[2500];
	unsigned char resultBuffer[256];

	status = viOpenDefaultRM(&defaultRM);
	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::0x0699?*INSTR",	&resourceList,&num_inst,description); //find instrument that has 0x0699(tektronix)
		
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&scopeHandle); //open oscilloscope

			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);

				viWrite(scopeHandle,"*IDN?\n",6,&resultCount);
				viRead(scopeHandle,resultBuffer,256,&resultCount);

				printf("\nOscilloscope = %s\n",resultBuffer );
			}
			else printf("Couldn't open oscilloscope\n");
		}
		else {printf("Couldn't fnd oscilloscope\n"); exit(EXIT_FAILURE);}

		status = viFindRsrc(defaultRM,"USB[0-9]::0x1AB1?*INSTR", &resourceList,&num_inst,description); //find instrument that has 0x1AB1(rigol)
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&funcHandle); //open function generator

			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);

				viWrite(funcHandle,"*IDN?\n",6,&resultCount);
				viRead(funcHandle,resultBuffer,256,&resultCount);

				printf("\nFunctionGen = %s\n",resultBuffer );
			}
			else printf("Couldn't open function generator\n");
		}
		else {printf("Couldn't find function generator\n"); exit(EXIT_FAILURE);}

		setfgreadscope(funcHandle,scopeHandle);

	}
	else {printf("Failed to open defaultRM\n"); exit(EXIT_FAILURE);}
}