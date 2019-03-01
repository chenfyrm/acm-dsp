/*
 * acclma.c
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#include <math.h>
#include "acclma.h"

#define KP 0.5
#define KI 100

void ACCLMA(TYPE_ACCLMA_IF *data)
{
//--------------------------------------
	data->XF_3Ph += 0.1;
	if(data->XF_3Ph>50.0)
		data->XF_3Ph = 50.0;
	data->XU_3PhPek = 380.0/1.732*1.414/50.0*data->XF_3Ph;

	if(data->XU_3PhPek>380.0/1.732*1.414)
		data->XU_3PhPek = 380.0/1.732*1.414;

	data->XX_M = data->XU_3PhPek/(data->XU_DcLk/sqrt(3));

	if(data->XX_M>0.6)
		data->XX_M = 0.6;

//------------------------------------------------------
//	data->XF_3Ph = 50;

//----------------------------------------
	data->clarke.As = data->XI_PhA;
	data->clarke.Bs = data->XI_PhB;
	data->clarke.Cs = data->XI_PhC;
	CLARKE_MACRO(data->clarke);

//--------------------------------------------------
	data->park.Alpha = data->clarke.Alpha;
	data->park.Beta = data->clarke.Beta;
	data->park.Sine = sin(data->XX_Theta);
	data->park.Cosine = cos(data->XX_Theta);
	PARK_MACRO(data->park);

//--------------------------------------------------------
	data->acrd.Ref = 20;
	data->acrd.Fbk = data->park.Ds;
	data->acrd.Kp = KP;
	data->acrd.Ki = KI*data->XX_Ts;
	data->acrd.Umax = 600;
	data->acrd.Umin = -600;
	PI_MACRO(data->acrd);

//--------------------------------------------------------
	data->acrq.Ref = 0;
	data->acrq.Fbk = data->park.Qs;
	data->acrq.Kp = KP;
	data->acrq.Ki = KI*data->XX_Ts;
	data->acrq.Umax = 600;
	data->acrq.Umin = -600;
	PI_MACRO(data->acrq);

//----------------------------------------------------------
	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->park.Qs;
	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->park.Ds;
	data->ipark.Sine = sin(data->XX_Theta + data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + data->XF_3Ph*data->XX_Ts);
	IPARK_MACRO(data->ipark);

//-------------------------------------------------------------
//	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/1.732);
//	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/1.732);
	data->svgen.Ualpha = data->XX_M*cos(data->XX_Theta);
	data->svgen.Ubeta = data->XX_M*sin(data->XX_Theta);
//	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
	if(data->XX_M>1.0)
	{
		data->svgen.Ualpha /= data->XX_M;
		data->svgen.Ubeta /= data->XX_M;
	}
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
//	data->XX_Theta = 0;

}


