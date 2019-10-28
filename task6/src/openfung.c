#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>

void openfuncg(ViSession defaultRM,ViSession* funcHandle)
{
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViChar description[VI_FIND_BUFLEN];
	ViUInt32 resultCount;

	unsigned char resultBuffer[256];

	status = viFindRsrc(defaultRM,"USB[0-9]::0x1AB1?*INSTR", &resourceList,&num_inst,description); //find instrument that has 0x1AB1(rigol)
	if(status == VI_SUCCESS)
	{
		status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,funcHandle); //open function generator

		if(status == VI_SUCCESS)
		{
			printf("\nOpened %s\n",description);

			viWrite(*funcHandle,"*IDN?\n",6,&resultCount);
			viRead(*funcHandle,resultBuffer,256,&resultCount);

			printf("\nFunctionGen = %s\n",resultBuffer );
		}
		else printf("Couldn't open function generator\n");
	}
	else {printf("Couldn't find function generator\n"); exit(EXIT_FAILURE);}
}