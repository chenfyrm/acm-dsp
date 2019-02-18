/*
 * acclma.c
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */
#include <math.h>
#include "acclma.h"


float32 Theta = 0.0;
static float32 Ts = 1/1450/2;
float32 M = 0.9;

void ACCLMA(TYPE_ACCLMA_IF *data)
{
	Theta += 100*3.1415926*Ts;
	if (Theta>=2*3.1415926)
	{Theta -= 2*3.1415926;}
	else
	{
		if(Theta<0)
		{Theta += 2*3.1415926;}
		else
		{}
	}

	data->XX_CmpA = M*sin(Theta);
	data->XX_CmpB = M*sin(Theta-2/3*3.1415926);
	data->XX_CmpC = M*sin(Theta-4/3*3.1415926);

//	data->XX_CmpA = 0.2;
//	data->XX_CmpB = 0.3;
//	data->XX_CmpC = 0.4;
}
