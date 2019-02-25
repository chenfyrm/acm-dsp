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
//--------------------------------------------------
	data->park.Alpha = data->XI_PhAlpha;
	data->park.Beta = data->XI_PhBeta;
	data->park.Sine = sin(data->XX_Theta);
	data->park.Cosine = cos(data->XX_Theta);
	PARK_MACRO(data->park);

//--------------------------------------------------------
	data->acrd.Ref = 10;
	data->acrd.Fbk = data->park.Ds;
	data->acrd.Kp = 0.6767;
	data->acrd.Ki = 232.0;
	data->acrd.Umax = 600;
	data->acrd.Umax = -600;
	PI_MACRO(data->acrd);

//--------------------------------------------------------
	data->acrq.Ref = 0;
	data->acrq.Fbk = data->park.Qs;
	data->acrq.Kp = 0.6767;
	data->acrq.Ki = 232.0;
	data->acrq.Umax = 600;
	data->acrq.Umax = -600;
	PI_MACRO(data->acrq);

//----------------------------------------------------------
	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->park.Qs;
	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->park.Ds;
	data->ipark.Sine = sin(data->XX_Theta);
	data->ipark.Cosine = cos(data->XX_Theta);
	IPARK_MACRO(data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha;
	data->svgen.Ubeta = data->ipark.Beta;
	SVGENDQ_MACRO(data->svgen);//[-1,1]
//---------------------------------------------------------
	data->XX_DutyA = data->svgen.Ta/2.0+0.5;
	data->XX_DutyB = data->svgen.Tb/2.0+0.5;
	data->XX_DutyC = data->svgen.Tc/2.0+0.5;
//-------------------------------------------------------------
	data->XX_Theta += 2*3.1415926*data->XF_3Ph*data->XX_Ts;
	if (data->XX_Theta>=2*3.1415926)
		data->XX_Theta -= 2*3.1415926;
	if(data->XX_Theta<0)
		data->XX_Theta += 2*3.1415926;
}


