/*
 * acclma.c
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#include <math.h>
#include "ufctrl.h"

//#define KP 0.6767
//#define KI 232.0

#define TSC  		(1.0/1450.0/2.0)
#define DEADTIME	(0.0*0.000001)
#define	MINPW		(5.0*0.000001)

#define KP 0.15
#define KI 40.0

//static float32 XF_3PhRef = 50.0;
//static float32 XU_3PhPeakRef = 50.0;

void UFCTRLOpenLoop(TYPE_UFCTRL_IF *data)
{

	/*for simulink*/
//	data->XX_UPeakCom = 1.0;
//	data->XX_AngleCom = 0.0;

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
		if(data->XF_3Ph<data->WF_3PhDsp)
			data->XF_3Ph = data->WF_3PhDsp;
	}

	data->XF_3Ph = data->WF_3PhDsp;

//--------------------------------------
	if(data->XU_3PhPek<data->WU_3PhDsp)
	{
		data->XU_3PhPek += 0.1;
		if(data->XU_3PhPek>data->WU_3PhDsp)
			data->XU_3PhPek = data->WU_3PhDsp;
	}
	if(data->XU_3PhPek>data->WU_3PhDsp)
	{
		data->XU_3PhPek -= 0.1;
		if(data->XU_3PhPek<data->WU_3PhDsp)
			data->XU_3PhPek = data->WU_3PhDsp;
	}

	/**/
//	//----------------------------------------
//		data->clarke.As = data->XI_PhA;
//		data->clarke.Bs = data->XI_PhB;
//		data->clarke.Cs = data->XI_PhC;
//		CLARKE(&data->clarke);
//
//	//--------------------------------------------------
//		data->park.Alpha = data->clarke.Alpha;
//		data->park.Beta = data->clarke.Beta;
//		data->park.Sine = sin(data->XX_Theta);
//		data->park.Cosine = cos(data->XX_Theta);
//		PARK(&data->park);
//
//		//---------------------------------------
//		data->XI_Act3Ph = data->park.Ds;
//		data->LpFilterId.XX_In = data->park.Ds;
//		data->LpFilterId.XX_T = 1.0/2900.0;
//		LPFILTER(&data->LpFilterId);
//		data->XI_Act3PhFlt = data->LpFilterId.XX_Out;
//		data->XI_Rct3Ph = data->park.Qs;
//		data->LpFilterIq.XX_In = data->park.Qs;
//		data->LpFilterIq.XX_T = 1.0/2900.0;
//		LPFILTER(&data->LpFilterIq);
//		data->XI_Rct3PhFlt = data->LpFilterIq.XX_Out;
//
//		//--------------------------------------------------
//			data->park.Alpha = data->XU_PhAl/1.732;
//			data->park.Beta = data->XU_PhBe/1.732;
//			data->park.Sine = sin(data->XX_Theta-3.1415926/6.0);
//			data->park.Cosine = cos(data->XX_Theta-3.1415926/6.0);
//			PARK(&data->park);
//
//		//---------------------------------------
//			data->XU_Act3Ph = data->park.Ds;
//			data->LpFilterUd.XX_In = data->park.Ds;
//			data->LpFilterUd.XX_T = 1.0/300.0;
//			LPFILTER(&data->LpFilterUd);
//			data->XU_Act3PhFlt = data->LpFilterUd.XX_Out;
//			data->XU_Rct3Ph = data->park.Qs;
//			data->LpFilterUq.XX_In = data->park.Qs;
//			data->LpFilterUq.XX_T = 1.0/300.0;
//			LPFILTER(&data->LpFilterUq);
//			data->XU_Rct3PhFlt = data->LpFilterUq.XX_Out;

//----------------------------------------------------------
	data->ipark.Ds = data->XU_3PhPek;
	data->ipark.Qs = 0.0;
	data->ipark.Sine = sin(data->XX_Theta );
	data->ipark.Cosine = cos(data->XX_Theta );
//	data->ipark.Sine = sin(data->XX_Theta + 2.0*PI*data->XF_3Ph*data->XX_Ts);
//	data->ipark.Cosine = cos(data->XX_Theta + 2.0*PI*data->XF_3Ph*data->XX_Ts);
	IPARK(&data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/SQRT3);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/SQRT3);
//	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
//	/*插入死区时间和最小脉宽限制减小线性调制区
//	 * 死区5微妙，最小脉宽10微妙，调制周期1/2900=345微秒
//	 * 线性调制比区[0.1,0.9]
//	 * */
//	if(data->XX_M>0.9)
//	{
//		data->svgen.Ualpha /= data->XX_M*0.9;
//		data->svgen.Ubeta /= data->XX_M*0.9;
//		data->XX_M = 0.9;
//	}
	SVGEN(&data->svgen);

	//-----------------------------------
	if(data->XX_Mode == 0)
	{
		data->XX_Mode = 21;
	}
	else
	{
		data->XX_Mode = 0;
	}

//---------------------------------------------------------

		data->XX_DutyA = data->svgen.Ta;
		data->XX_DutyB = data->svgen.Tb;
		data->XX_DutyC = data->svgen.Tc;
//
			data->XX_DutyA = data->XU_3PhPek/55.0*sin(data->XX_Theta+PI/2)*0.5+0.5;
			data->XX_DutyB = data->XU_3PhPek/55.0*sin(data->XX_Theta+PI/2-PI/3.0*2.0)*0.5+0.5;
			data->XX_DutyC = data->XU_3PhPek/55.0*sin(data->XX_Theta+PI/2-PI/3.0*4.0)*0.5+0.5;

			data->svgen.Ta = data->XU_3PhPek/55.0*sin(data->XX_Theta)*0.5+0.5;
			data->svgen.Tb = data->XU_3PhPek/55.0*sin(data->XX_Theta-PI/3.0*2.0)*0.5+0.5;
			data->svgen.Tc = data->XU_3PhPek/55.0*sin(data->XX_Theta-PI/3.0*4.0)*0.5+0.5;


				//-----------
				data->dtCom.Ia = data->XI_PhA;
				data->dtCom.Ib = data->XI_PhB;
				data->dtCom.Ic = data->XI_PhC;
				data->dtCom.mode = data->XX_Mode;
				data->dtCom.dt = DEADTIME/TSC; //10us
				DEADTIMECOM(&data->dtCom);

				//---------------------
				data->minPwLim.Ta_in = data->svgen.Ta + data->dtCom.TaCom;
				data->minPwLim.Tb_in = data->svgen.Tb + data->dtCom.TbCom;
				data->minPwLim.Tc_in = data->svgen.Tc + data->dtCom.TcCom;
				data->minPwLim.Tmin = MINPW/TSC; //5us
				MINPWLIM(&data->minPwLim);

				//-------------------------
				data->XX_DutyA = data->minPwLim.Ta_out;
				data->XX_DutyB = data->minPwLim.Tb_out;
				data->XX_DutyC = data->minPwLim.Tc_out;

//	//-----------
//	data->dtCom.Ia = data->XI_PhA;
//	data->dtCom.Ib = data->XI_PhB;
//	data->dtCom.Ic = data->XI_PhC;
//	data->dtCom.mode = data->XX_Mode;
//	data->dtCom.dt = DEADTIME/TSC; //10us
//	DEADTIMECOM(&data->dtCom);
//
//	//---------------------
//	data->minPwLim.Ta_in = data->svgen.Ta + data->dtCom.TaCom;
//	data->minPwLim.Tb_in = data->svgen.Tb + data->dtCom.TbCom;
//	data->minPwLim.Tc_in = data->svgen.Tc + data->dtCom.TcCom;
//	data->minPwLim.Tmin = MINPW/TSC; //5us
//	MINPWLIM(&data->minPwLim);
//
//	//-------------------------
//	data->XX_DutyA = data->minPwLim.Ta_out;
//	data->XX_DutyB = data->minPwLim.Tb_out;
//	data->XX_DutyC = data->minPwLim.Tc_out;

/*Update*/
	data->XX_Theta += 2.0*PI*data->XF_3Ph*data->XX_Ts;
	if (data->XX_Theta>=2.0*PI)
		data->XX_Theta -= 2.0*PI;
	if(data->XX_Theta<0.0)
		data->XX_Theta += 2.0*PI;
}

void UFCTRLSingleLoop(TYPE_UFCTRL_IF *data)
{
	data->WF_3PhDsp = 50.0;
//	data->WF_3PhDsp = 0.0;
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
	CLARKE(&data->clarke);

//--------------------------------------------------
	data->park.Alpha = data->clarke.Alpha;
	data->park.Beta = data->clarke.Beta;
	data->park.Sine = sin(data->XX_Theta);
	data->park.Cosine = cos(data->XX_Theta);
	PARK(&data->park);

//---------------------------------------
	data->XI_Act3Ph = data->park.Ds;
	data->LpFilterId.XX_In = data->park.Ds;
	data->LpFilterId.XX_T = 1.0/2900.0;
	LPFILTER(&data->LpFilterId);
	data->XI_Act3PhFlt = data->LpFilterId.XX_Out;
	data->XI_Rct3Ph = data->park.Qs;
	data->LpFilterIq.XX_In = data->park.Qs;
	data->LpFilterIq.XX_T = 1.0/2900.0;
	LPFILTER(&data->LpFilterIq);
	data->XI_Rct3PhFlt = data->LpFilterIq.XX_Out;

	//--------------------------------------------------
		data->park.Alpha = data->XU_PhAl/1.732;
		data->park.Beta = data->XU_PhBe/1.732;
		data->park.Sine = sin(data->XX_Theta-3.1415926/6.0);
		data->park.Cosine = cos(data->XX_Theta-3.1415926/6.0);
		PARK(&data->park);

	//---------------------------------------
		data->XU_Act3Ph = data->park.Ds;
		data->LpFilterUd.XX_In = data->park.Ds;
		data->LpFilterUd.XX_T = 1.0/300.0;
		LPFILTER(&data->LpFilterUd);
		data->XU_Act3PhFlt = data->LpFilterUd.XX_Out;
		data->XU_Rct3Ph = data->park.Qs;
		data->LpFilterUq.XX_In = data->park.Qs;
		data->LpFilterUq.XX_T = 1.0/300.0;
		LPFILTER(&data->LpFilterUq);
		data->XU_Rct3PhFlt = data->LpFilterUq.XX_Out;

		/**/
		data->rampId.XX_In = 3.0;
		data->rampId.XX_Step = 0.01;
		RAMP(&data->rampId);

//--------------------------------------------------------
	data->acrd.Ref = data->rampId.XX_Out;
	data->acrd.Fbk = data->XI_Act3Ph;
//	data->acrd.Fbk = data->XI_Act3PhFlt;
	data->acrd.Kp = KP;
	data->acrd.Ki = KI*data->XX_Ts;
	data->acrd.Umax = 550;
	data->acrd.Umin = -550;
	PI_CONTROLLER(&data->acrd);

	/**/
	data->rampIq.XX_In = 10.0;
	data->rampIq.XX_Step = 0.01;
	RAMP(&data->rampIq);

//--------------------------------------------------------
	data->acrq.Ref = data->rampIq.XX_Out;
	data->acrq.Fbk = data->XI_Rct3Ph;
//	data->acrq.Fbk = data->XI_Rct3PhFlt;
	data->acrq.Kp = KP;
	data->acrq.Ki = KI*data->XX_Ts;
	data->acrq.Umax = 550;
	data->acrq.Umin = -550;
	PI_CONTROLLER(&data->acrq);

//----------------------------------------------------------
//	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->park.Qs + data->XU_Act3PhFlt;
//	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->park.Ds + data->XU_Rct3PhFlt;
	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->park.Qs;
	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->park.Ds;
//	data->ipark.Ds = data->acrd.Out;
//	data->ipark.Qs = data->acrq.Out;
	data->ipark.Sine = sin(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
	IPARK(&data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/1.732);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/1.732);
	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
	/*插入死区时间和最小脉宽限制减小线性调制区
	 * 死区10微妙，最小脉宽10微妙，调制周期1/2900=345微秒
	 * 线性调制比区[0,0.85]
	 * */
	if(data->XX_M>0.85)
	{
		data->svgen.Ualpha /= data->XX_M*0.85;
		data->svgen.Ubeta /= data->XX_M*0.85;
		data->XX_M = 0.85;
	}
	SVGEN(&data->svgen);

//---------------------------------------------------------
	data->XX_DutyA = data->svgen.Ta;
	data->XX_DutyB = data->svgen.Tb;
	data->XX_DutyC = data->svgen.Tc;

	//-----------------------------------
	if(data->XX_Mode == 0)
	{
		data->XX_Mode = 21;
	}
	else
	{
		data->XX_Mode = 0;
	}

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
	CLARKE(&data->clarke);

//--------------------------------------------------
	data->park.Alpha = data->clarke.Alpha;
	data->park.Beta = data->clarke.Beta;
	data->park.Sine = sin(data->XX_Theta);
	data->park.Cosine = cos(data->XX_Theta);
	PARK(&data->park);

//--------------------------------------------------------
	data->acrd.Ref = 10;
	data->acrd.Fbk = data->park.Ds;
	data->acrd.Kp = KP;
	data->acrd.Ki = KI*data->XX_Ts;
	data->acrd.Umax = 600;
	data->acrd.Umin = -600;
	PI_CONTROLLER(&data->acrd);

//--------------------------------------------------------
	data->acrq.Ref = 0;
	data->acrq.Fbk = data->park.Qs;
	data->acrq.Kp = KP;
	data->acrq.Ki = KI*data->XX_Ts;
	data->acrq.Umax = 600;
	data->acrq.Umin = -600;
	PI_CONTROLLER(&data->acrq);

//----------------------------------------------------------
	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->park.Qs+50;
	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->park.Ds;
	data->ipark.Sine = sin(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + 2.0*3.1415926*data->XF_3Ph*data->XX_Ts);
	IPARK(&data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/1.732);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/1.732);
	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
	if(data->XX_M>1.0)
	{
		data->svgen.Ualpha /= data->XX_M;
		data->svgen.Ubeta /= data->XX_M;
	}
	SVGEN(&data->svgen);

//---------------------------------------------------------
	data->XX_DutyA = data->svgen.Ta;
	data->XX_DutyB = data->svgen.Tb;
	data->XX_DutyC = data->svgen.Tc;

	//-----------------------------------
	if(data->XX_Mode == 0)
	{
		data->XX_Mode = 21;
	}
	else
	{
		data->XX_Mode = 0;
	}

//-------------------------------------------------------------
	data->XX_Theta += 2*3.1415926*data->XF_3Ph*data->XX_Ts;
	if (data->XX_Theta>=2*3.1415926)
		data->XX_Theta -= 2*3.1415926;
	if(data->XX_Theta<0)
		data->XX_Theta += 2*3.1415926;
//	data->XX_Theta = 0.0;

}

/**/
void CLARKE(TYPE_CLARKE *data)
{
	data->Alpha = (data->As - 0.5*(data->Bs + data->Cs))*2.0/3.0;
	data->Beta  = (data->Bs - data->Cs)*ONEbySQRT3;
}

/**/
void PARK(TYPE_PARK *data)
{
	data->Ds = data->Alpha*data->Cosine + data->Beta*data->Sine;
	data->Qs = data->Beta*data->Cosine - data->Alpha*data->Sine;
}
/**/
void IPARK(TYPE_IPARK *data)
{
	data->Alpha = data->Ds*data->Cosine - data->Qs*data->Sine;
	data->Beta  = data->Qs*data->Cosine + data->Ds*data->Sine;
}
/**/
void PI_CONTROLLER(TYPE_PI_CONTROLLER *data)
{
	/* proportional term */
	data->up = data->Kp*(data->Ref - data->Fbk);

	/* integral term */
	data->ui = (data->Out == data->v1)?(data->Ki*(data->Ref - data->Fbk) + data->i1) : data->i1;
	data->i1 = data->ui;

	/* control output */
	data->v1 = data->up + data->ui;
	data->Out= (data->v1> data->Umax)?data->Umax:data->v1;
	data->Out= (data->Out< data->Umin)?data->Umin:data->Out;
}
/**/
void SVGEN(TYPE_SVGEN *data)
{
	data->tmp1= data->Ubeta;
	data->tmp2= data->Ubeta*0.5 + data->Ualpha*SQRT3byTWO;
	data->tmp3= data->tmp2 - data->tmp1;

	data->VecSector=3;
	data->VecSector=(data->tmp2> 0)?( data->VecSector-1):data->VecSector;
	data->VecSector=(data->tmp3> 0)?( data->VecSector-1):data->VecSector;
	data->VecSector=(data->tmp1< 0)?(7-data->VecSector) :data->VecSector;

	if     (data->VecSector==1 || data->VecSector==4)
	{
		data->Ta= data->tmp2;
		data->Tb= data->tmp1-data->tmp3;
		data->Tc=-data->tmp2;
	}
	else if(data->VecSector==2 || data->VecSector==5)
	{
		data->Ta= data->tmp3+data->tmp2;
		data->Tb= data->tmp1;
		data->Tc=-data->tmp1;
	}
	else
	{
		data->Ta= data->tmp3;
		data->Tb=-data->tmp3;
		data->Tc=-(data->tmp1+data->tmp2);
	}

	/*从[-1 1]变换[0 1]*/
	data->Ta = data->Ta*0.5 + 0.5;
	data->Tb = data->Tb*0.5 + 0.5;
	data->Tc = data->Tc*0.5 + 0.5;

}

void DEADTIMECOM(TYPE_DEADTIMECOM *data)
{

	if(data->Ia >= 0.0)
	{
		if(data->mode == 21)
		{
			if(data->Ia>=5.0)
			{
				data->TaCom = data->dt;
			}
			else
			{
				data->TaCom = data->dt/5.0*data->Ia;
			}
		}
		else
		{
			data->TaCom = 0.0;
		}
	}
	if(data->Ib >= 0.0)
	{
		if(data->mode == 21)
		{
			if(data->Ib>=5.0)
			{
				data->TbCom = data->dt;
			}
			else
			{
				data->TbCom = data->dt/5.0*data->Ib;
			}

		}
		else
		{
			data->TbCom = 0.0;
		}
	}
	if(data->Ic >= 0.0)
	{
		if(data->mode == 21)
		{
			if(data->Ic>=5.0)
			{
				data->TcCom = data->dt;
			}
			else
			{
				data->TcCom = data->dt/5.0*data->Ic;
			}
		}
		else
		{
			data->TcCom = 0.0;
		}
	}

	if(data->Ia < 0.0)
	{
		if(data->mode == 0)
		{
			if(data->Ia<=-5.0)
			{
				data->TaCom = -data->dt;
			}
			else
			{
				data->TaCom = data->dt/5.0*data->Ia;
			}
		}
		else
		{
			data->TaCom = 0.0;
		}
	}
	if(data->Ib < 0.0)
	{
		if(data->mode == 0)
		{
			if(data->Ib<=-5.0)
			{
				data->TbCom = -data->dt;
			}
			else
			{
				data->TbCom = data->dt/5.0*data->Ib;
			}
		}
		else
		{
			data->TbCom = 0.0;
		}
	}
	if(data->Ic < 0.0)
	{
		if(data->mode == 0)
		{
			if(data->Ic<=-5.0)
			{
				data->TcCom = -data->dt;
			}
			else
			{
				data->TcCom = data->dt/5.0*data->Ic;
			}
		}
		else
		{
			data->TcCom = 0.0;
		}
	}

}

/**/
void MINPWLIM(TYPE_MINPWLIM *data)
{
	data->Ta_out = data->Ta_in;
	data->Tb_out = data->Tb_in;
	data->Tc_out = data->Tc_in;

	if(data->Ta_in <= data->Tmin)
		data->Ta_out = 0.0;
	if(data->Ta_in >= (1.0-data->Tmin))
		data->Ta_out = 1.0;

	if(data->Tb_in <= data->Tmin)
		data->Tb_out = 0.0;
	if(data->Tb_in >= (1.0-data->Tmin))
		data->Tb_out = 1.0;

	if(data->Tc_in <= data->Tmin)
		data->Tc_out = 0.0;
	if(data->Tc_in >= (1.0-data->Tmin))
		data->Tc_out = 1.0;

}

/**/
void LPFILTER(TYPE_LPFILTER *data)
{
/**/
	data->XX_Out = (data->XX_Out + data->XX_Ts/data->XX_T*data->XX_In)/(1.0 + data->XX_Ts/data->XX_T);
}

void RAMP(TYPE_RAMP *data)
{
	/**/
	if(data->XX_Out<data->XX_In)
		{
			data->XX_Out += data->XX_Step;
			if(data->XX_Out>data->XX_In)
				data->XX_Out = data->XX_In;
		}
		if(data->XX_Out>data->XX_In)
		{
			data->XX_Out -= data->XX_Step;
			if(data->XX_Out<data->XX_In)
				data->XX_Out = data->XX_In;
		}

}

void DOSGPLL(TYPE_DOSGPLL_IF *data)
{
	data->Ts = 1.0/2900.0;
	data->w0 = 100*3.1415926;
	data->K = sqrt(2);
	/**/
	data->aqr.Kp = 2*100*3.1415926;
	data->aqr.Ki = 100*3.1415926*100*3.1415926*data->Ts;
	data->aqr.Umax = 100;
	data->aqr.Umin = -100;
	/**/
	data->a = data->Ts*data->w/2.0 + 2.0/data->Ts/data->w;
	data->b = data->Ts*data->w/2.0 - 2.0/data->Ts/data->w;
	/**/
	data->alpha = data->K/(data->a+data->K)\
			*(data->phase-data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
			-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
/**/
	data->park.Alpha = data->alpha;
	data->park.Beta = data->beta;
	data->park.Sine = sin(data->theta);
	data->park.Cosine = cos(data->theta);
	PARK(&data->park);
	/**/
	data->Upeak = fabs(data->park.Ds);
	if(data->Upeak < 0.001)
	data->Upeak = 0.001;
/**/
	data->aqr.Ref = data->park.Qs/data->Upeak;
	data->aqr.Fbk = 0;
	PI_CONTROLLER(&data->aqr);

	/*update*/
	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;
	/**/
	data->w = data->w0 + data->aqr.Out;
/**/
	data->theta += data->w*data->Ts;
	if(data->theta >= 2*3.1415926)
		data->theta -= 2*3.1415926;
	if(data->theta < 0)
		data->theta += 2*3.1415926;
	/**/
	data->dFlt = (1.0-data->Ts/data->T_dFlt)*data->dFlt + data->Ts/data->T_dFlt*data->park.Ds;
	data->beta = data->dFlt*sin(data->theta);
}

void DOSGPLL_1(TYPE_DOSGPLL_IF *data)
{
	data->Ts = 1.0/2900.0;
	data->w0 = 100*3.1415926;
	data->K = sqrt(2);
	/**/
	data->aqr.Kp = 2*100*3.1415926;
	data->aqr.Ki = 100*3.1415926*100*3.1415926*data->Ts;
	data->aqr.Umax = 100;
	data->aqr.Umin = -100;
	/**/
	data->a = data->Ts*data->w/2.0 + 2.0/data->Ts/data->w;
	data->b = data->Ts*data->w/2.0 - 2.0/data->Ts/data->w;
	/**/
//	data->alpha = data->K/(data->a+data->K)\
//			*(data->phase-data->oldPhase2)\
//			-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
//			-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
	data->alpha = -data->K/(data->a+data->K)*(data->a+data->b)/2.0\
				*(data->phase+2.0*data->oldPhase1+data->oldPhase2)\
				-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
				-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
/**/
	data->park.Alpha = data->alpha;
	data->park.Beta = data->beta;
	data->park.Sine = sin(data->theta);
	data->park.Cosine = cos(data->theta);
	PARK(&data->park);
	/**/
	data->Upeak = fabs(data->park.Ds);
	if(data->Upeak < 0.001)
	data->Upeak = 0.001;
/**/
	data->aqr.Ref = data->park.Qs/data->Upeak;
	data->aqr.Fbk = 0;
	PI_CONTROLLER(&data->aqr);

	/*update*/
	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;
	/**/
	data->w = data->w0 + data->aqr.Out;
/**/
	data->theta += data->w*data->Ts;
	if(data->theta >= 2*3.1415926)
		data->theta -= 2*3.1415926;
	if(data->theta < 0)
		data->theta += 2*3.1415926;
	/**/
	data->dFlt = (1.0-data->Ts/data->T_dFlt)*data->dFlt + data->Ts/data->T_dFlt*data->park.Ds;
	data->beta = data->dFlt*sin(data->theta);
}

