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
	data->XF_3Ph += 0.001;
	if(data->XF_3Ph>50.0)
		data->XF_3Ph = 50.0;
	data->XU_3PhPek = 380.0/1.732*1.414/50.0*data->XF_3Ph;

	if(data->XU_3PhPek>380.0/1.732*1.414)
		data->XU_3PhPek = 380.0/1.732*1.414;

	data->XX_M = data->XU_3PhPek/(data->XU_DcLk/sqrt(3));

	if(data->XX_M>0.8)
		data->XX_M = 0.8;
//	if(data->XX_M< 0.1)
//		data->XX_M = 0.1;

//-------------------------------------------------------------
	data->XX_Theta += 2*3.1415926*data->XF_3Ph*data->XX_Ts;
	if (data->XX_Theta>=2*3.1415926)
		data->XX_Theta -= 2*3.1415926;
	if(data->XX_Theta<0)
		data->XX_Theta += 2*3.1415926;
//-------------------------------------------------------------
	data->svgen.Ualpha = data->XX_M*cos(data->XX_Theta);
	data->svgen.Ubeta = data->XX_M*sin(data->XX_Theta);
	SVGENDQ_MACRO(data->svgen);//[-1,1]
//---------------------------------------------------------
	data->XX_DutyA = data->svgen.Ta/2.0+0.5;
	data->XX_DutyB = data->svgen.Tb/2.0+0.5;
	data->XX_DutyC = data->svgen.Tc/2.0+0.5;
}


