/*
 * acclma.c
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#include <math.h>
#include "ufctrl.h"

#define KP 1.0
#define KI 100

static float32 XF_3PhRef = 50.0;
float32 XU_3PhPeakRef = 674.0/380.0*20.0*1.414;

void UFCTRLOpenLoop(TYPE_UFCTRL_IF *data)
{
//--------------------------------------
	if(data->XF_3Ph<XF_3PhRef)
	{
		data->XF_3Ph += 0.1;
		if(data->XF_3Ph>XF_3PhRef)
			data->XF_3Ph = XF_3PhRef;
	}
	if(data->XF_3Ph>XF_3PhRef)
	{
		data->XF_3Ph -= 0.1;
		if(data->XF_3Ph<0.0)
			data->XF_3Ph = 0.0;
	}

//--------------------------------------
	if(data->XU_3PhPek<XU_3PhPeakRef)
	{
		data->XU_3PhPek += 1.0;
		if(data->XU_3PhPek>XU_3PhPeakRef)
			data->XU_3PhPek = XU_3PhPeakRef;
	}
	if(data->XU_3PhPek>XU_3PhPeakRef)
	{
		data->XU_3PhPek -= 1.0;
		if(data->XU_3PhPek<0.0)
			data->XU_3PhPek = 0.0;
	}

//	/*U/f ratio*/
//	data->XU_3PhPek = 380.0/1.732*1.414/50.0*data->XF_3Ph;
//	if(data->XU_3PhPek>380.0/1.732*1.414)
//		data->XU_3PhPek = 380.0/1.732*1.414;
//	/*M*/
//	data->XX_M = data->XU_3PhPek/(data->XU_DcLk/sqrt(3));
//	if(data->XX_M>0.6)
//		data->XX_M = 0.6;
//	/**/
//	data->svgen.Ualpha = data->XX_M*cos(data->XX_Theta);
//	data->svgen.Ubeta = data->XX_M*sin(data->XX_Theta);
//	SVGENDQ_MACRO(data->svgen);//[-1,1]

//----------------------------------------------------------
	data->ipark.Ds = data->XU_3PhPek;
	data->ipark.Qs = 0.0;
	data->ipark.Sine = sin(data->XX_Theta + data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + data->XF_3Ph*data->XX_Ts);
	IPARK_MACRO(data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/1.732);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/1.732);
	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
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

//	if(data->XX_DutyA<0.05)
//		data->XX_DutyA = 0.0;
//	if(data->XX_DutyA>0.95)
//			data->XX_DutyA = 1.0;
//	if(data->XX_DutyB<0.05)
//		data->XX_DutyB = 0.0;
//	if(data->XX_DutyB>0.95)
//			data->XX_DutyB = 1.0;
//	if(data->XX_DutyC<0.05)
//		data->XX_DutyC = 0.0;
//	if(data->XX_DutyC>0.95)
//			data->XX_DutyC = 1.0;


/*Update*/
	data->XX_Theta += 2.0*3.1415926*data->XF_3Ph*data->XX_Ts;
	if (data->XX_Theta>=2.0*3.1415926)
		data->XX_Theta -= 2.0*3.1415926;
	if(data->XX_Theta<0.0)
		data->XX_Theta += 2.0*3.1415926;
}

void UFCTRLSingleLoop(TYPE_UFCTRL_IF *data)
{
//--------------------------------------
	data->XF_3Ph += 0.1;
	if(data->XF_3Ph>XF_3PhRef)
		data->XF_3Ph = XF_3PhRef;

//--------------------------------------
	if(data->XU_3PhPek<XU_3PhPeakRef)
	{
		data->XU_3PhPek += 1.0;
		if(data->XU_3PhPek>XU_3PhPeakRef)
			data->XU_3PhPek = XU_3PhPeakRef;
	}
	if(data->XU_3PhPek>XU_3PhPeakRef)
	{
		data->XU_3PhPek -= 1.0;
		if(data->XU_3PhPek<0.0)
			data->XU_3PhPek = 0.0;
	}

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
//	data->acrd.Ref = 10;
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
	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->park.Qs+data->XU_3PhPek;
	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->park.Ds;
	data->ipark.Sine = sin(data->XX_Theta + data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + data->XF_3Ph*data->XX_Ts);
	IPARK_MACRO(data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/1.732);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/1.732);
	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
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
//	data->XX_Theta = 0.0;
}

void UFCTRLDoubleLoop(TYPE_UFCTRL_IF *data)
{
//--------------------------------------
	data->XF_3Ph += 0.1;
	if(data->XF_3Ph>XF_3PhRef)
		data->XF_3Ph = XF_3PhRef;

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
	data->acrd.Ref = 10;
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
	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->park.Qs+50;
	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->park.Ds;
	data->ipark.Sine = sin(data->XX_Theta + data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + data->XF_3Ph*data->XX_Ts);
	IPARK_MACRO(data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/1.732);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/1.732);
	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
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
//	data->XX_Theta = 0.0;

}


