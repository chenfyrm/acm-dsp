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
//	data->XX_DutyA = data->XX_M*sin(data->XX_Theta)/2.0+0.5;
//	data->XX_DutyB = data->XX_M*sin(data->XX_Theta-2.0/3.0*3.1415926)/2.0+0.5;
//	data->XX_DutyC = data->XX_M*sin(data->XX_Theta-4.0/3.0*3.1415926)/2.0+0.5;
//
//	if(data->XX_M < 0.9)
//		data->XX_M += 0.001;
//	if(data->XX_M >0.9)
//		data->XX_M = 0.9;
//
//	data->XX_Theta += 100*3.1415926*data->XX_Ts;
//	if (data->XX_Theta>=2*3.1415926)
//		data->XX_Theta -= 2*3.1415926;
//	if(data->XX_Theta<0)
//		data->XX_Theta += 2*3.1415926;

	data->svgen.Ualpha = 0.8;
	data->svgen.Ubeta = 0;
	SVGENDQ_MACRO(data->svgen);

	data->XX_DutyA = data->svgen.Ta;
	data->XX_DutyB = data->svgen.Tb;
	data->XX_DutyC = data->svgen.Tc;

}


