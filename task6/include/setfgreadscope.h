#ifndef _SETFGREADSCOPE_H
#define _SETFGREADSCOPE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <visa.h>

void setfgreadscope(ViSession funcHandle,ViSession scopeHandle,double* amplitude,double* frequency,int* datacount);

#endif