#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>

void openscope(ViSession defaultRM,ViSession* scopeHandle)
{
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViChar description[VI_FIND_BUFLEN];
	ViUInt32 resultCount;

	unsigned char resultBuffer[256];

	status = viFindRsrc(defaultRM,"USB[0-9]::0x0699?*INSTR", &resourceList,&num_inst,description); //find instrument that has 0x0699(tektronix)
		
	if(status == VI_SUCCESS)
	{
		status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,scopeHandle); //open oscilloscope

		if(status == VI_SUCCESS)
		{
			printf("\nOpened %s\n",description);

			viWrite(*scopeHandle,"*IDN?\n",6,&resultCount);
			viRead(*scopeHandle,resultBuffer,256,&resultCount);

			printf("\nOscilloscope = %s\n",resultBuffer );
		}
		else printf("Couldn't open oscilloscope\n");
	}
	else {printf("Couldn't fnd oscilloscope\n"); exit(EXIT_FAILURE);}
}