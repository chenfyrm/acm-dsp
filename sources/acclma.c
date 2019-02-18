/*
 * acclma.c
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */
#include <math.h>
#include "acclma.h"

void ACCLMA(TYPE_ACCLMA_IF *data)
{
	data->XX_CmpA = data->XX_M*sin(data->XX_Theta);
	data->XX_CmpB = data->XX_M*sin(data->XX_Theta-2/3*3.1415926);
	data->XX_CmpC = data->XX_M*sin(data->XX_Theta-4/3*3.1415926);

	data->XX_Theta += 100*3.1415926*data->XX_Ts;
	if (data->XX_Theta>=2*3.1415926)
		data->XX_Theta -= 2*3.1415926;
	if(data->XX_Theta<0)
		data->XX_Theta += 2*3.1415926;

//	data->XX_CmpA = 0.2;
//	data->XX_CmpB = 0.3;
//	data->XX_CmpC = 0.4;
}
