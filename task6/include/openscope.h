#ifndef _OPENSCOPE_H
#define _OPENSCOPE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <visa.h>

void openscope(ViSession defaultRM,ViSession* scopeHandle);

#endif