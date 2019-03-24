/*
 * acclma.c
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#include <math.h>
#include "ufctrl.h"

#define KP 0.6767
#define KI 232.0

//static float32 XF_3PhRef = 50.0;
//static float32 XU_3PhPeakRef = 50.0;

void UFCTRLOpenLoop(TYPE_UFCTRL_IF *data)
{
	/*command*/
	data->WF_3PhDsp = 50.0;
	data->WU_3PhDsp = 50.0/1.732*1.64;

	/*for simulink*/
	data->XX_UPeakCom = 1.0;
	data->XX_AngleCom = 0.0;

//	data->XX_UPeakCom = 0.97;
//	data->XX_AngleCom = -0.7;
//--------------------------------------
	if(data->XF_3Ph<data->WF_3PhDsp)
	{
		data->XF_3Ph += 0.1;
		if(data->XF_3Ph>data->WF_3PhDsp)
			data->XF_3Ph = data->WF_3PhDsp;
	}
	if(data->XF_3Ph>data->WF_3PhDsp)
	{
		data->XF_3Ph -= 0.1;
		if(data->XF_3Ph<0.0)
			data->XF_3Ph = 0.0;
	}

//--------------------------------------
	if(data->XU_3PhPek<data->WU_3PhDsp*data->XX_UPeakCom)
	{
		data->XU_3PhPek += 0.1;
		if(data->XU_3PhPek>data->WU_3PhDsp*data->XX_UPeakCom)
			data->XU_3PhPek = data->WU_3PhDsp*data->XX_UPeakCom;
	}
	if(data->XU_3PhPek>data->WU_3PhDsp*data->XX_UPeakCom)
	{
		data->XU_3PhPek -= 0.1;
		if(data->XU_3PhPek<0.0)
			data->XU_3PhPek = 0.0;
	}

	/**/
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

		//---------------------------------------
		data->XI_Act3Ph = data->park.Ds;
		data->LpFilterId.XX_In = data->park.Ds;
		LPFILTER(&data->LpFilterId);
		data->XI_Act3PhFlt = data->LpFilterId.XX_Out;
		data->XI_Rct3Ph = data->park.Qs;
		data->LpFilterIq.XX_In = data->park.Qs;
		LPFILTER(&data->LpFilterIq);
		data->XI_Rct3PhFlt = data->LpFilterIq.XX_Out;

//----------------------------------------------------------
	data->ipark.Ds = data->XU_3PhPek;
	data->ipark.Qs = 0.0;
	data->ipark.Sine = sin(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
	IPARK_MACRO(data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/1.732);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/1.732);
	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
	/*插入死区时间和最小脉宽限制减小线性调制区
	 * 死区5微妙，最小脉宽10微妙，调制周期1/2900=345微秒
	 * 线性调制比区[0.1,0.9]
	 * */
	if(data->XX_M>0.9)
	{
		data->svgen.Ualpha /= data->XX_M*0.9;
		data->svgen.Ubeta /= data->XX_M*0.9;
		data->XX_M = 0.9;
	}
	SVGENDQ_MACRO(data->svgen);//[-1,1]

//---------------------------------------------------------
	data->XX_DutyA = data->svgen.Ta/2.0+0.5;
	data->XX_DutyB = data->svgen.Tb/2.0+0.5;
	data->XX_DutyC = data->svgen.Tc/2.0+0.5;


/*Update*/
	data->XX_Theta += 2.0*3.1415926*data->XF_3Ph*data->XX_Ts;
	if (data->XX_Theta>=2.0*3.1415926)
		data->XX_Theta -= 2.0*3.1415926;
	if(data->XX_Theta<0.0)
		data->XX_Theta += 2.0*3.1415926;


}

void UFCTRLSingleLoop(TYPE_UFCTRL_IF *data)
{
	data->WF_3PhDsp = 50.0;
//--------------------------------------
	if(data->XF_3Ph<data->WF_3PhDsp)
	{
		data->XF_3Ph += 0.1;
		if(data->XF_3Ph>data->WF_3PhDsp)
			data->XF_3Ph = data->WF_3PhDsp;
	}
	if(data->XF_3Ph>data->WF_3PhDsp)
	{
		data->XF_3Ph -= 0.1;
		if(data->XF_3Ph<0.0)
			data->XF_3Ph = 0.0;
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

//---------------------------------------
	data->XI_Act3Ph = data->park.Ds;
	data->LpFilterId.XX_In = data->park.Ds;
	LPFILTER(&data->LpFilterId);
	data->XI_Act3PhFlt = data->LpFilterId.XX_Out;
	data->XI_Rct3Ph = data->park.Qs;
	data->LpFilterIq.XX_In = data->park.Qs;
	LPFILTER(&data->LpFilterIq);
	data->XI_Rct3PhFlt = data->LpFilterIq.XX_Out;

	//--------------------------------------------------
		data->park.Alpha = data->XU_PhAl/1.732;
		data->park.Beta = data->XU_PhBe/1.732;
		data->park.Sine = sin(data->XX_Theta-3.1415926/6.0);
		data->park.Cosine = cos(data->XX_Theta-3.1415926/6.0);
		PARK_MACRO(data->park);

	//---------------------------------------
		data->XU_Act3Ph = data->park.Ds;
		data->LpFilterUd.XX_In = data->park.Ds;
		data->LpFilterUd.XX_T = 1/300;
		LPFILTER(&data->LpFilterUd);
		data->XU_Act3PhFlt = data->LpFilterUd.XX_Out;
		data->XU_Rct3Ph = data->park.Qs;
		data->LpFilterUq.XX_In = data->park.Qs;
		data->LpFilterUq.XX_T = 1/300;
		LPFILTER(&data->LpFilterUq);
		data->XU_Rct3PhFlt = data->LpFilterUq.XX_Out;

//--------------------------------------------------------
//	data->acrd.Ref = 5;
	data->acrd.Fbk = data->XI_Act3Ph;
//	data->acrd.Fbk = data->XI_Act3PhFlt;
	data->acrd.Kp = KP;
	data->acrd.Ki = KI*data->XX_Ts;
	data->acrd.Umax = 50;
	data->acrd.Umin = -50;
	PI_MACRO(data->acrd);

//--------------------------------------------------------
//	data->acrq.Ref = 3;
	data->acrq.Fbk = data->XI_Rct3Ph;
//	data->acrq.Fbk = data->XI_Rct3PhFlt;
	data->acrq.Kp = KP;
	data->acrq.Ki = KI*data->XX_Ts;
	data->acrq.Umax = 50;
	data->acrq.Umin = -50;
	PI_MACRO(data->acrq);

//----------------------------------------------------------
//	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->park.Qs + data->XU_Act3PhFlt;
//	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->park.Ds + data->XU_Rct3PhFlt;
	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->park.Qs;
	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->park.Ds;
	data->ipark.Sine = sin(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
	IPARK_MACRO(data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/1.732);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/1.732);
	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
	/*插入死区时间和最小脉宽限制减小线性调制区
	 * 死区5微妙，最小脉宽10微妙，调制周期1/2900=345微秒
	 * 线性调制比区[0.1,0.9]
	 * */
	if(data->XX_M>0.9)
	{
		data->svgen.Ualpha /= data->XX_M*0.9;
		data->svgen.Ubeta /= data->XX_M*0.9;
		data->XX_M = 0.9;
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
}

void UFCTRLDoubleLoop(TYPE_UFCTRL_IF *data)
{
//--------------------------------------
	data->XF_3Ph += 0.1;
	if(data->XF_3Ph>data->WF_3PhDsp)
		data->XF_3Ph = data->WF_3PhDsp;

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
	data->ipark.Sine = sin(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
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

void LPFILTER(TYPE_LPFILTER *data)
{
/**/
	data->XX_Out = (data->XX_Out + data->XX_Ts/data->XX_T*data->XX_In)/(1.0 + data->XX_Ts/data->XX_T);
}


