#include <stdlib.h>
#include <stdio.h>

int main()
{
	float inputx;

	printf("Please enter a number\n");
	fflush(stdout); //print out above printf immediately

	int corr = scanf(" %f",&inputx); //scan the input first time

	/*do
	{
		fflush(stdin);
		corr = scanf(" %f",&inputx);
		
		//printf("corr = %d\n",corr);
	}
	while(corr != 1);*/

	while(corr != 1) //check input correction
	{
		if(corr != 1)
		{
		printf("Wrong, try again\n");
		fflush(stdin);
		corr = scanf(" %f",&inputx);
		}
	}
	
	printf("The input was %0.3f\n",inputx);
	


}