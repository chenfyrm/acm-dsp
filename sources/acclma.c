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
	data->XX_DutyA = data->XX_M*sin(data->XX_Theta)/2.0+0.5;
	data->XX_DutyB = data->XX_M*sin(data->XX_Theta-2.0/3.0*3.1415926)/2.0+0.5;
	data->XX_DutyC = data->XX_M*sin(data->XX_Theta-4.0/3.0*3.1415926)/2.0+0.5;

	data->XF_3Ph += 0.001;
	if(data->XF_3Ph>50.0)
		data->XF_3Ph = 50.0;
	data->XU_3PhPek = 380.0/1.732*1.414/50.0*data->XF_3Ph;

	if(data->XU_3PhPek>380.0/1.732*1.414)
		data->XU_3PhPek = 380.0/1.732*1.414;

	data->XX_M = data->XU_3PhPek/(data->XU_DcLk/2.0);

	if(data->XX_M>0.9)
		data->XX_M = 0.9;
	if(data->XX_M< 0.1)
		data->XX_M = 0.1;

	data->XX_Theta += 2*3.1415926*data->XF_3Ph*data->XX_Ts;
	if (data->XX_Theta>=2*3.1415926)
		data->XX_Theta -= 2*3.1415926;
	if(data->XX_Theta<0)
		data->XX_Theta += 2*3.1415926;
}


