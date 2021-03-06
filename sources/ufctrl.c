/*
 * acclma.c
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#include <math.h>
#include "ufctrl.h"

//#define KP 0.3
//#define KI 40

#define TSC  		(1.0/1450.0/2.0)
#define DEADTIME	(0.0*0.000001)
#define	MINPW		(10.0*0.000001)

//#define KP 2.167
//#define KI 243

#define KP 0.6767
#define KI 232

#define KP_U 0.09
#define KI_U 58

//static float32 XF_3PhRef = 50.0;
//static float32 XU_3PhPeakRef = 50.0;

void UFCTRLINIT(TYPE_UFCTRL_IF *data)
{

}

void UFCTRLOpenLoop(TYPE_UFCTRL_IF *data)
{

	/*for simulink*/
//	data->XX_UPeakCom = 1.0;
//	data->XX_AngleCom = 0.0;

//	data->XX_UPeakCom = 0.97;
//	data->XX_AngleCom = -0.7;

//--------------------------------------
//	if(data->XF_3Ph<data->WF_3PhDsp)
//	{
//		data->XF_3Ph += 0.5;
//		if(data->XF_3Ph>data->WF_3PhDsp)
//			data->XF_3Ph = data->WF_3PhDsp;
//	}
//	if(data->XF_3Ph>data->WF_3PhDsp)
//	{
//		data->XF_3Ph -= 0.5;
//		if(data->XF_3Ph<data->WF_3PhDsp)
//			data->XF_3Ph = data->WF_3PhDsp;
//	}

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

		data->XI_Act3Ph = data->park.Ds;
		data->XI_Rct3Ph = data->park.Qs;

		//---------------------------------------
		data->LpFilterId.XX_In = data->park.Ds;
		data->LpFilterId.XX_T = 1.0/30.0;
		LPFILTER(&data->LpFilterId);
		data->XI_Act3PhFlt = data->LpFilterId.XX_Out;
		//--------------------------------------------
		data->LpFilterIq.XX_In = data->park.Qs;
		data->LpFilterIq.XX_T = 1.0/30.0;
		LPFILTER(&data->LpFilterIq);
		data->XI_Rct3PhFlt = data->LpFilterIq.XX_Out;

		//--------------------------------------------------
			data->park.Alpha = data->XU_PhAl/1.732;
			data->park.Beta = data->XU_PhBe/1.732;
//			data->park.Sine = sin(data->XX_Theta-PI/6.0);
//			data->park.Cosine = cos(data->XX_Theta-PI/6.0);
			data->park.Sine = sin(data->XX_Theta);
			data->park.Cosine = cos(data->XX_Theta);
			PARK(&data->park);

			data->XU_Act3Ph = data->park.Ds;
			data->XU_Rct3Ph = data->park.Qs;

		//---------------------------------------
			data->LpFilterUd.XX_In = data->park.Ds;
			data->LpFilterUd.XX_T = 1.0/30.0;
			LPFILTER(&data->LpFilterUd);
			data->XU_Act3PhFlt = data->LpFilterUd.XX_Out;
			//------------------------------------
			data->LpFilterUq.XX_In = data->park.Qs;
			data->LpFilterUq.XX_T = 1.0/30.0;
			LPFILTER(&data->LpFilterUq);
			data->XU_Rct3PhFlt = data->LpFilterUq.XX_Out;

//----------------------------------------------------------
	data->ipark.Ds = data->XU_3PhPek;
	data->ipark.Qs = 0.0;
//	data->ipark.Sine = sin(data->XX_Theta );
//	data->ipark.Cosine = cos(data->XX_Theta );
	data->ipark.Sine = sin(data->XX_Theta + 2.0*PI*data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + 2.0*PI*data->XF_3Ph*data->XX_Ts);
	IPARK(&data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/SQRT3);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/SQRT3);
	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
//	/*插入死区时间和最小脉宽限制减小线性调制区
//	 * 死区5微妙，最小脉宽10微妙，调制周期1/2900=345微秒
//	 * 线性调制比区[0.1,0.9]
//	 * */
//	if(data->XX_M>0.85)
//	{
//		data->svgen.Ualpha /= data->XX_M*0.85;
//		data->svgen.Ubeta /= data->XX_M*0.85;
//		data->XX_M = 0.85;
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


//
//			data->svgen.Ta = data->XU_3PhPek/55.0*sin(data->XX_Theta+PI/2)*0.5+0.5;
//			data->svgen.Tb = data->XU_3PhPek/55.0*sin(data->XX_Theta+PI/2-PI/3.0*2.0)*0.5+0.5;
//			data->svgen.Tb = data->XU_3PhPek/55.0*sin(data->XX_Theta+PI/2-PI/3.0*4.0)*0.5+0.5;


//

//			data->XX_M = data->XU_3PhPek/(data->XU_DcLk/2.0);
//			data->svgen.Ta = data->XX_M*sin(data->XX_Theta)*0.5+0.5;
//			data->svgen.Tb = data->XX_M*sin(data->XX_Theta-PI/3.0*2.0)*0.5+0.5;
//			data->svgen.Tc = data->XX_M*sin(data->XX_Theta-PI/3.0*4.0)*0.5+0.5;

//------------------------
			data->BpFilterIa.phase = data->XI_PhA;
			data->BpFilterIa.w = 2.0*PI*data->XF_3Ph;
			BPFILTER(&data->BpFilterIa);

			data->BpFilterIb.phase = data->XI_PhB;
			data->BpFilterIb.w = 2.0*PI*data->XF_3Ph;
			BPFILTER(&data->BpFilterIb);

			data->BpFilterIc.phase = data->XI_PhC;
			data->BpFilterIc.w = 2.0*PI*data->XF_3Ph;
			BPFILTER(&data->BpFilterIc);


				//-----------
				data->dtCom.Ia = data->BpFilterIa.alpha;
				data->dtCom.Ib = data->BpFilterIa.alpha;
				data->dtCom.Ic = data->BpFilterIa.alpha;
				data->dtCom.mode = data->XX_Mode;
				data->dtCom.dt = DEADTIME/TSC; //10us
				DEADTIMECOM(&data->dtCom);
//				DEADTIMECOM_1(&data->dtCom);

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

//				data->XX_DutyA = data->svgen.Ta;
//				data->XX_DutyB = data->svgen.Tb;
//				data->XX_DutyC = data->svgen.Tc;



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
//--------------------------------------
//	if(data->XF_3Ph<data->WF_3PhDsp)
//	{
//		data->XF_3Ph += 0.1;
//		if(data->XF_3Ph>data->WF_3PhDsp)
//			data->XF_3Ph = data->WF_3PhDsp;
//	}
//	if(data->XF_3Ph>data->WF_3PhDsp)
//	{
//		data->XF_3Ph -= 0.1;
//		if(data->XF_3Ph<0.0)
//			data->XF_3Ph = 0.0;
//	}
	data->XF_3Ph = data->WF_3PhDsp;

	//------------------------------------------------
	/**/
//		data->rampId.XX_In = data->RefId;
//		data->rampId.XX_Step = 0.01;
//		RAMP(&data->rampId);

	/**/
//	data->rampIq.XX_In = data->RefIq;
//	data->rampIq.XX_Step = 0.01;
//	RAMP(&data->rampIq);



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
	data->LpFilterId.XX_T = 1.0/30.0;
	LPFILTER(&data->LpFilterId);
	data->XI_Act3PhFlt = data->LpFilterId.XX_Out;
	//---------------------------------------------
	data->XI_Rct3Ph = data->park.Qs;
	data->LpFilterIq.XX_In = data->park.Qs;
	data->LpFilterIq.XX_T = 1.0/30.0;
	LPFILTER(&data->LpFilterIq);
	data->XI_Rct3PhFlt = data->LpFilterIq.XX_Out;

////---------------------------------------------
//	data->dosgpll.phase = data->XU_PhAB;
//	data->dosgpll.w0 = 2*PI*data->XF_3Ph;
//	DOSGPLL(&data->dosgpll);
//
////------------------------------------------
//	data->XU_PhAl = data->dosgpll.alpha;
//	data->XU_PhBe = data->dosgpll.beta;

	//--------------------------------------------------
		data->park.Alpha = data->XU_PhAl/SQRT3;
		data->park.Beta = data->XU_PhBe/SQRT3;
//		data->park.Sine = sin(data->XX_Theta-PI/6.0);
//		data->park.Cosine = cos(data->XX_Theta-PI/6.0);
		data->park.Sine = sin(data->XX_Theta);
		data->park.Cosine = cos(data->XX_Theta);
		PARK(&data->park);

	//---------------------------------------
		data->XU_Act3Ph = data->park.Ds;
		data->LpFilterUd.XX_In = data->park.Ds;
		data->LpFilterUd.XX_T = 1.0/30.0;
		LPFILTER(&data->LpFilterUd);
		data->XU_Act3PhFlt = data->LpFilterUd.XX_Out;
		//------------------------------------------
		data->XU_Rct3Ph = data->park.Qs;
		data->LpFilterUq.XX_In = data->park.Qs;
		data->LpFilterUq.XX_T = 1.0/30.0;
		LPFILTER(&data->LpFilterUq);
		data->XU_Rct3PhFlt = data->LpFilterUq.XX_Out;

//--------------------------------------------------------
//	data->acrd.Ref = data->rampId.XX_Out;
	data->acrd.Ref = data->RefId;
	data->acrd.Fbk = data->XI_Act3Ph;
//	data->acrd.Fbk = data->XI_Act3PhFlt;
	data->acrd.Kp = KP;
	data->acrd.Ki = KI*data->XX_Ts;
	data->acrd.Umax = 550;
	data->acrd.Umin = -550;
	PI_CONTROLLER(&data->acrd);


//--------------------------------------------------------
//	data->acrq.Ref = data->rampIq.XX_Out;
	data->acrq.Ref = data->RefIq;
	data->acrq.Fbk = data->XI_Rct3Ph;
//	data->acrq.Fbk = data->XI_Rct3PhFlt;
	data->acrq.Kp = KP;
	data->acrq.Ki = KI*data->XX_Ts;
	data->acrq.Umax = 550;
	data->acrq.Umin = -550;
	PI_CONTROLLER(&data->acrq);

//----------------------------------------------------------
//	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Rct3PhFlt + data->XU_Act3PhFlt;
//	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Act3PhFlt + data->XU_Rct3PhFlt;
//	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Rct3Ph + data->XU_Act3PhFlt;
//	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Act3Ph + data->XU_Rct3PhFlt;
//	data->ipark.Ds = data->acrd.Out - 2.0*PI*data->XF_3Ph*0.0007*data->XI_Rct3PhFlt;
//	data->ipark.Qs = data->acrq.Out + 2.0*PI*data->XF_3Ph*0.0007*data->XI_Act3PhFlt;
//	data->ipark.Ds = data->acrd.Out + data->XU_Act3PhFlt;
//	data->ipark.Qs = data->acrq.Out + data->XU_Rct3PhFlt;
//	data->ipark.Ds = data->acrd.Out ;
//	data->ipark.Qs = data->acrq.Out ;
	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Rct3Ph ;
	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Act3Ph ;
//	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Rct3Ph + 2*3.1415926*data->XF_3Ph*0.00055*3*1.64*1.64*data->acrq.Ref;
//	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Act3Ph - 2*3.1415926*data->XF_3Ph*0.00055*3*1.64*1.64*data->acrd.Ref;
//	data->ipark.Ds = data->acrd.Out + data->XU_Act3Ph;
//	data->ipark.Qs = data->acrq.Out + data->XU_Rct3Ph;
//	data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Rct3Ph + data->XU_Act3Ph;
//	data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Act3Ph + data->XU_Rct3Ph;
	data->ipark.Sine = sin(data->XX_Theta + 2.0*PI*data->XF_3Ph*data->XX_Ts);
	data->ipark.Cosine = cos(data->XX_Theta + 2.0*PI*data->XF_3Ph*data->XX_Ts);
//	data->ipark.Sine = sin(data->XX_Theta );
//	data->ipark.Cosine = cos(data->XX_Theta );
	IPARK(&data->ipark);

//-------------------------------------------------------------
	data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/SQRT3);
	data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/SQRT3);
	data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
	/*插入死区时间和最小脉宽限制减小线性调制区
	 * 死区10微妙，最小脉宽10微妙，调制周期1/2900=345微秒
	 * 线性调制比区[0,0.85]
	 * */
//	if(data->XX_M>0.85)
//	{
//		data->svgen.Ualpha /= data->XX_M*0.85;
//		data->svgen.Ubeta /= data->XX_M*0.85;
//		data->XX_M = 0.85;
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

	//------------------------
				data->BpFilterIa.phase = data->XI_PhA;
				data->BpFilterIa.w = 2.0*PI*data->XF_3Ph;
				BPFILTER(&data->BpFilterIa);

				data->BpFilterIb.phase = data->XI_PhB;
				data->BpFilterIb.w = 2.0*PI*data->XF_3Ph;
				BPFILTER(&data->BpFilterIb);

				data->BpFilterIc.phase = data->XI_PhC;
				data->BpFilterIc.w = 2.0*PI*data->XF_3Ph;
				BPFILTER(&data->BpFilterIc);

				//-------------------------------------------



					//-----------
					data->dtCom.Ia = data->BpFilterIa.alpha;
					data->dtCom.Ib = data->BpFilterIa.alpha;
					data->dtCom.Ic = data->BpFilterIa.alpha;
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

//-------------------------------------------------------------
	data->XX_Theta += 2*PI*data->XF_3Ph*data->XX_Ts;
	if (data->XX_Theta>=2*PI)
		data->XX_Theta -= 2*PI;
	if(data->XX_Theta<0)
		data->XX_Theta += 2*PI;
}

void UFCTRLDoubleLoop(TYPE_UFCTRL_IF *data)
{

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
	//---------------------------------------
		data->XI_Act3Ph = data->park.Ds;
		data->LpFilterId.XX_In = data->park.Ds;
		data->LpFilterId.XX_T = 1.0/30.0;
		LPFILTER(&data->LpFilterId);
		data->XI_Act3PhFlt = data->LpFilterId.XX_Out;
		//---------------------------------------------
		data->XI_Rct3Ph = data->park.Qs;
		data->LpFilterIq.XX_In = data->park.Qs;
		data->LpFilterIq.XX_T = 1.0/30.0;
		LPFILTER(&data->LpFilterIq);
		data->XI_Rct3PhFlt = data->LpFilterIq.XX_Out;
		//--------------------------------------------------
			data->park.Alpha = data->XU_PhAl/SQRT3;
			data->park.Beta = data->XU_PhBe/SQRT3;
			data->park.Sine = sin(data->XX_Theta);
			data->park.Cosine = cos(data->XX_Theta);
			PARK(&data->park);
		//---------------------------------------
			data->XU_Act3Ph = data->park.Ds;
			data->LpFilterUd.XX_In = data->park.Ds;
			data->LpFilterUd.XX_T = 1.0/30.0;
			LPFILTER(&data->LpFilterUd);
			data->XU_Act3PhFlt = data->LpFilterUd.XX_Out;
			//------------------------------------------
			data->XU_Rct3Ph = data->park.Qs;
			data->LpFilterUq.XX_In = data->park.Qs;
			data->LpFilterUq.XX_T = 1.0/30.0;
			LPFILTER(&data->LpFilterUq);
			data->XU_Rct3PhFlt = data->LpFilterUq.XX_Out;
			//----------------------------------------------
				if(data->aurd.Ref<33.0)
				{
					data->aurd.Ref += 0.1;
					if(data->aurd.Ref>33.0)
						data->aurd.Ref = 33.0;
				}
				if(data->aurd.Ref>33.0)
				{
					data->aurd.Ref -= 0.1;
					if(data->aurd.Ref<33.0)
						data->aurd.Ref = 33.0;
				}
			//--------------------------------------
//			data->aurd.Ref = 33.0;
			data->aurd.Fbk = data->XU_Act3Ph;
			data->aurd.Kp = KP_U;
			data->aurd.Ki = KI_U*data->XX_Ts;
			data->aurd.Umax = 200;
			data->aurd.Umin = -200;
			PI_CONTROLLER(&data->aurd);
			//--------------------------------------------------
			data->aurq.Ref = 0.0;
			data->aurq.Fbk = data->XU_Rct3Ph;
			data->aurq.Kp = KP_U;
			data->aurq.Ki = KI_U*data->XX_Ts;
			data->aurq.Umax = 200;
			data->aurq.Umin = -200;
			PI_CONTROLLER(&data->aurq);
	//--------------------------------------------------------
		data->acrd.Ref = data->aurd.Out;
		data->acrd.Fbk = data->XI_Act3Ph;
		data->acrd.Kp = KP;
		data->acrd.Ki = KI*data->XX_Ts;
		data->acrd.Umax = 550;
		data->acrd.Umin = -550;
		PI_CONTROLLER(&data->acrd);
	//--------------------------------------------------------
		data->acrq.Ref = data->aurq.Out;
		data->acrq.Fbk = data->XI_Rct3Ph;
		data->acrq.Kp = KP;
		data->acrq.Ki = KI*data->XX_Ts;
		data->acrq.Umax = 550;
		data->acrq.Umin = -550;
		PI_CONTROLLER(&data->acrq);
	//----------------------------------------------------------
		data->ipark.Ds = data->acrd.Out - 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Rct3Ph + data->aurd.Ref;
		data->ipark.Qs = data->acrq.Out + 2*3.1415926*data->XF_3Ph*0.0007*data->XI_Act3Ph + data->aurq.Ref;
		data->ipark.Sine = sin(data->XX_Theta + 2.0*PI*data->XF_3Ph*data->XX_Ts);
		data->ipark.Cosine = cos(data->XX_Theta + 2.0*PI*data->XF_3Ph*data->XX_Ts);
		IPARK(&data->ipark);
	//-------------------------------------------------------------
		data->svgen.Ualpha = data->ipark.Alpha/(data->XU_DcLk/SQRT3);
		data->svgen.Ubeta = data->ipark.Beta/(data->XU_DcLk/SQRT3);
		data->XX_M = sqrt(data->svgen.Ualpha*data->svgen.Ualpha+data->svgen.Ubeta*data->svgen.Ubeta);
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
		//------------------------
					data->BpFilterIa.phase = data->XI_PhA;
					data->BpFilterIa.w = 2.0*PI*data->XF_3Ph;
					BPFILTER(&data->BpFilterIa);

					data->BpFilterIb.phase = data->XI_PhB;
					data->BpFilterIb.w = 2.0*PI*data->XF_3Ph;
					BPFILTER(&data->BpFilterIb);

					data->BpFilterIc.phase = data->XI_PhC;
					data->BpFilterIc.w = 2.0*PI*data->XF_3Ph;
					BPFILTER(&data->BpFilterIc);
						//-----------
						data->dtCom.Ia = data->BpFilterIa.alpha;
						data->dtCom.Ib = data->BpFilterIa.alpha;
						data->dtCom.Ic = data->BpFilterIa.alpha;
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
	//-------------------------------------------------------------
		data->XX_Theta += 2*PI*data->XF_3Ph*data->XX_Ts;
		if (data->XX_Theta>=2*PI)
			data->XX_Theta -= 2*PI;
		if(data->XX_Theta<0)
			data->XX_Theta += 2*PI;
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
			if(data->Ia>=1.0)
			{
				data->TaCom = data->dt;
			}
			else
			{
				data->TaCom = data->dt/1.0*data->Ia;
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
			if(data->Ib>=1.0)
			{
				data->TbCom = data->dt;
			}
			else
			{
				data->TbCom = data->dt/1.0*data->Ib;
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
			if(data->Ic>=1.0)
			{
				data->TcCom = data->dt;
			}
			else
			{
				data->TcCom = data->dt/1.0*data->Ic;
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
			if(data->Ia<=-1.0)
			{
				data->TaCom = -data->dt;
			}
			else
			{
				data->TaCom = data->dt/1.0*data->Ia;
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
			if(data->Ib<=-1.0)
			{
				data->TbCom = -data->dt;
			}
			else
			{
				data->TbCom = data->dt/1.0*data->Ib;
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
			if(data->Ic<=-1.0)
			{
				data->TcCom = -data->dt;
			}
			else
			{
				data->TcCom = data->dt/1.0*data->Ic;
			}
		}
		else
		{
			data->TcCom = 0.0;
		}
	}

}

void DEADTIMECOM_1(TYPE_DEADTIMECOM *data)
{

	if(data->Ia >= 0.0)
	{
		if(data->mode == 0)
		{
			if(data->Ia>=1.0)
			{
				data->TaCom = data->dt;
			}
			else
			{
				data->TaCom = data->dt/1.0*data->Ia;
			}
		}
		else
		{
			data->TaCom = 0.0;
		}
	}
	if(data->Ib >= 0.0)
	{
		if(data->mode == 0)
		{
			if(data->Ib>=1.0)
			{
				data->TbCom = data->dt;
			}
			else
			{
				data->TbCom = data->dt/1.0*data->Ib;
			}

		}
		else
		{
			data->TbCom = 0.0;
		}
	}
	if(data->Ic >= 0.0)
	{
		if(data->mode == 0)
		{
			if(data->Ic>=1.0)
			{
				data->TcCom = data->dt;
			}
			else
			{
				data->TcCom = data->dt/1.0*data->Ic;
			}
		}
		else
		{
			data->TcCom = 0.0;
		}
	}

	if(data->Ia < 0.0)
	{
		if(data->mode == 21)
		{
			if(data->Ia<=-1.0)
			{
				data->TaCom = -data->dt;
			}
			else
			{
				data->TaCom = data->dt/1.0*data->Ia;
			}
		}
		else
		{
			data->TaCom = 0.0;
		}
	}
	if(data->Ib < 0.0)
	{
		if(data->mode == 21)
		{
			if(data->Ib<=-1.0)
			{
				data->TbCom = -data->dt;
			}
			else
			{
				data->TbCom = data->dt/1.0*data->Ib;
			}
		}
		else
		{
			data->TbCom = 0.0;
		}
	}
	if(data->Ic < 0.0)
	{
		if(data->mode == 21)
		{
			if(data->Ic<=-1.0)
			{
				data->TcCom = -data->dt;
			}
			else
			{
				data->TcCom = data->dt/1.0*data->Ic;
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

void DOSGPLL(TYPE_DOSGPLL *data)
{
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

void DOSGPLL_1(TYPE_DOSGPLL *data)
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

void BPFILTER(TYPE_BPFILTER *data)
{
	/**/
	data->k = 0.05;
	data->Tsc = 1.0/2900.0;
	/**/
	data->a = data->Tsc*data->w/2.0 + 2.0/data->Tsc/data->w;
	data->b = data->Tsc*data->w/2.0 - 2.0/data->Tsc/data->w;

	/**/
	data->alpha = data->k/(data->a+data->k)							\
			*(data->phase-data->oldPhase2)							\
			-2.0*data->b/(data->a+data->k)*data->oldAlpha1			\
			-(data->a-data->k)/(data->a+data->k)*data->oldAlpha2;

	/*update*/
	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;

}

void SOGIOSGMA(TYPE_SOGIOSGMA_IF *data)
{
	data->Ts = 1.0/2900.0;
	data->w = 100*3.1415926;
	data->K = sqrt(2);

	/**/
	data->a = data->Ts*data->w/2.0 + 2.0/data->Ts/data->w;
	data->b = data->Ts*data->w/2.0 - 2.0/data->Ts/data->w;

	data->alpha = data->K/(data->a+data->K)\
			*(data->phase-data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
			-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
	data->beta = data->K/(data->a+data->K)*(data->a+data->b)/2.0\
			*(data->phase+2.0*data->oldPhase1+data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldBeta1\
			-(data->a-data->K)/(data->a+data->K)*data->oldBeta2;

	/*update*/
	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;
	data->oldBeta2 = data->oldBeta1;
	data->oldBeta1 = data->beta;

}

void SOGIOSGFLL(TYPE_SOGIOSGMA_IF *data)
{
	data->Ts = 1.0/2900.0;
	data->w0 = 100*3.1415926;
	data->K = sqrt(2);
	data->Ki = 10000;

	/**/
	data->a = data->Ts*data->w/2.0 + 2.0/data->Ts/data->w;
	data->b = data->Ts*data->w/2.0 - 2.0/data->Ts/data->w;

	data->alpha = data->K/(data->a+data->K)\
			*(data->phase-data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
			-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
	data->beta = data->K/(data->a+data->K)*(data->a+data->b)/2.0\
			*(data->phase+2.0*data->oldPhase1+data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldBeta1\
			-(data->a-data->K)/(data->a+data->K)*data->oldBeta2;

	data->peak = sqrt(data->alpha*data->alpha + data->beta*data->beta);
	if(data->peak <= 0.001)
		data->peak = 0.001;
/**/
	data->ErrF = (data->phase-data->alpha)*data->beta/(data->peak*data->peak);
	data->ComW +=data->ErrF*(-1.0)*data->Ki*data->Ts;
	if (data->ComW > 30.0)
		data->ComW = 30.0;
	if (data->ComW <-30.0)
		data->ComW = -30.0;


	/*update*/
	data->w = data->w0 + data->ComW;

	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;
	data->oldBeta2 = data->oldBeta1;
	data->oldBeta1 = data->beta;

}


void UFCOMAInit(TYPE_UFCOMA *data)
{
	data->Tsc = TSC;

	/*U3PhRef*/
	data->PF_U3PhRef2 = 6.0;
	data->PF_U3PhRef3 = 50.0;
	data->PU_U3PhRef1 = 0.0; //0Hz
	data->PU_U3PhRef2 = 0.0;
	data->PU_U3PhRef3 = 30.0;
	data->PU_U3PhRef4 = 30.0;//100Hz
	data->L_ExtU3PhRef = FALSE;
	data->PX_ExtU3PhRefRmp = 200.0;
	data->L_EnRmpU3PhRef = FALSE;
	data->PX_U3PhRefRmp1 = 200.0;
	data->PX_U3PhRefRmp2 = 50.0;
	data->PX_U3PhRefRmpSel = 0.9;

	/*U3PhCl*/
	data->L_En3PhCl = TRUE;
	data->L_EnU3PhOpLoCl = FALSE;
	data->PX_KpU3PhCl = 0.8;
	data->PT_U3PhCl = 50.0;//ms
	data->PU_3PhClMax = 75.0;
	data->PU_3PhClMin = -50.0;
	data->PU_3PhClRefMax = 395.0;
	data->PU_3PhClRefMin = 0.0;
	data->U3PhCl.Kp = data->PX_KpU3PhCl;
	data->U3PhCl.Ki = 1000.0/data->PT_U3PhCl*TSC;
	data->U3PhCl.Umax = data->PU_3PhClMax;
	data->U3PhCl.Umin = data->PU_3PhClMin;

	/*TFrefRmp*/
	data->PX_FRefRmpUp = 40.0;
	data->PX_FRefRmpUpSlaveAcm = 100.0;
	data->PX_FRefRmpDo1 = 40.0;
	data->PX_FRefRmpDo2 = 40.0;
	data->PX_FRefRmpDo3 = 40.0;
	data->PF_FRefRmpDo12 = 4.0;
	data->PF_FRefRmpDo23 = 30.0;

	/*FrefRmp*/
	data->PF_3PhNom = 50.3;
	data->PF_3PhMin = 3.0;

	/*COMPMA*/
	data->L_EnUF3PhCmp = FALSE;
	data->PI_UF3PhCmpActHiLo = 4000.0;
	data->PF_UF3PhCmpActHiLo = -10.0;
	data->PI_UF3PhCmpRctHiLo = 4000.0;
	data->PU_UF3PhCmpRctHiLo = -100.0;

}

void UFCOMAStep(TYPE_UFCOMA *data)
{
//	/**/
//	TFrefRmp(data);
//	/**/
//	FrefUDcLk(data);
//	/**/
//	FrefRmp(data);
//	/**/
//	UF3PhCmp(data);
//	/**/
//	F3PhSz(data);
//	/**/
//	IPhClGenOvLd(data);
//	/**/
//	F3PhRef(data);
//	/**/
//	U3PhRef(data);
//	U3PhCl(data);
//
//	if(data->L_En3PhCl)
//	{
//		data->WU_3PhDsp = data->WU_3PhCl;
//	}

	data->WF_3PhDsp = 50.0;
	if(data->WU_3PhDsp<50.0)
	{
		data->WU_3PhDsp += 0.1;
		if(data->WU_3PhDsp>50.0)
			data->WU_3PhDsp = 50.0;
	}
	if(data->WU_3PhDsp>50.0)
	{
		data->WU_3PhDsp -= 0.1;
		if(data->WU_3PhDsp<50.0)
			data->WU_3PhDsp = 50.0;
	}
}

void UFCOMATerm(TYPE_UFCOMA *data)
{

}

void DspStep(TYPE_UFCOMA *data)
{
	/**/
	data->M = data->WU_3PhDsp/data->XU_DcLk*SQRT3;

	data->svgen.Ualpha = data->M*cos(data->Theta);
	data->svgen.Ubeta = data->M*sin(data->Theta);
	SVGEN(&data->svgen);

//	data->XX_DutyA = data->svgen.Ta;
//	data->XX_DutyB = data->svgen.Tb;
//	data->XX_DutyC = data->svgen.Tc;

	//---------------------
	data->minPwLim.Ta_in = data->svgen.Ta ;
	data->minPwLim.Tb_in = data->svgen.Tb ;
	data->minPwLim.Tc_in = data->svgen.Tc ;
	data->minPwLim.Tmin = MINPW/TSC; //5us
	MINPWLIM(&data->minPwLim);

	//-------------------------
	data->XX_DutyA = data->minPwLim.Ta_out;
	data->XX_DutyB = data->minPwLim.Tb_out;
	data->XX_DutyC = data->minPwLim.Tc_out;

	/**/
	data->XU_3PhPek = sqrt(data->XU_3PhAl*data->XU_3PhAl + data->XU_3PhBe*data->XU_3PhBe);
	data->LpFilterU3PhPek.XX_In = data->XU_3PhPek;
	data->LpFilterU3PhPek.XX_T = 1.0/10.0;
	data->LpFilterU3PhPek.XX_Ts = 1.0/2900.0;
	LPFILTER(&data->LpFilterU3PhPek);
	data->XU_3PhPek = data->LpFilterU3PhPek.XX_Out;

	data->park.Alpha = data->XU_3PhAl;
	data->park.Beta = data->XU_3PhBe;
	data->park.Sine = sin(data->Theta);
	data->park.Cosine = cos(data->Theta);
	PARK(&data->park);
	data->XU_3PhRe = data->park.Ds;
	data->XU_3PhIm = data->park.Qs;

	data->clarke.As = data->XI_PhA;
	data->clarke.Bs = data->XI_PhB;
	data->clarke.Cs = data->XI_PhC;
	CLARKE(&data->clarke);

	data->park.Alpha = data->clarke.Alpha;
	data->park.Beta = data->clarke.Beta;
	data->park.Sine = sin(data->Theta);
	data->park.Cosine = cos(data->Theta);
	PARK(&data->park);
	data->XI_PhAct = data->park.Ds;
	data->XI_PhRct = data->park.Qs;

	//update
	data->Theta += PI2*data->WF_3PhDsp*data->Tsc;
	if(data->Theta >= PI2)
		data->Theta -= PI2;
	if(data->Theta < 0)
		data->Theta += PI2;

	if(!data->XX_Mode)
	{
		data->XX_Mode = 1;
	}
	else
	{
		data->XX_Mode = 0;
	}
}

void F3PhRef(TYPE_UFCOMA *data)
{
	data->WF_3PhDsp = data->WF_3PhRmp + data->WF_WF3PhCmp + data->WF_UF3PhSz + data->WF_IPhCl;
	data->WF_3PhU3PhRef = data->WF_3PhDsp;
}

void U3PhRef(TYPE_UFCOMA *data)
{
	float32	temp;
	if(!data->L_ExtU3PhRef)
	{
		if(data->WF_3PhU3PhRef < 0.0)
			temp = data->PU_U3PhRef1;
		if(data->WF_3PhU3PhRef >= 0.0 && data->WF_3PhU3PhRef < data->PF_U3PhRef2)
			temp = data->PU_U3PhRef1 + (data->WF_3PhU3PhRef - 0.0)/(data->PF_U3PhRef2 - 0.0)*(data->PU_U3PhRef2 - data->PU_U3PhRef1);
		if(data->WF_3PhU3PhRef >= data->PF_U3PhRef2 && data->WF_3PhU3PhRef < data->PF_U3PhRef3)
			temp = data->PU_U3PhRef2 + (data->WF_3PhU3PhRef - data->PF_U3PhRef2)/(data->PF_U3PhRef3 - data->PF_U3PhRef2)*(data->PU_U3PhRef3 - data->PU_U3PhRef2);
		if(data->WF_3PhU3PhRef >= data->PF_U3PhRef3 && data->WF_3PhU3PhRef < 100.0)
			temp = data->PU_U3PhRef3 + (data->WF_3PhU3PhRef - data->PF_U3PhRef3)/(100.0 - data->PF_U3PhRef3)*(data->PU_U3PhRef4 - data->PU_U3PhRef3);
		if(data->WF_3PhU3PhRef >= 100.0)
			temp = data->PU_U3PhRef4;
	}

	if(!data->L_EnRmpU3PhRef)
	{
		data->WU_3PhUFRt = temp*SQRT2;
	}
}

void U3PhCl(TYPE_UFCOMA *data)
{
	data->WU_3PhClIn = data->WU_3PhUFRt;

	data->U3PhCl.Ref = data->WU_3PhClIn + data->WU_UF3PhCmp + data->WU_UF3PhSz;

	if(data->U3PhCl.Ref < data->PU_3PhClRefMin)
		data->U3PhCl.Ref = data->PU_3PhClRefMin;
	if(data->U3PhCl.Ref > data->PU_3PhClRefMax)
		data->U3PhCl.Ref = data->PU_3PhClRefMax;

	data->U3PhCl.Fbk = data->XU_3PhPek;
	PI_CONTROLLER(&data->U3PhCl);
	if(data->B_EnU3PhCl)
	{
		data->WU_3PhCl = data->U3PhCl.Ref + data->U3PhCl.Out;
	}
	else
	{
		data->WU_3PhCl = data->U3PhCl.Ref;
	}
}

void TFrefRmp(TYPE_UFCOMA *data)
{
	data->XX_FRefRmpUp = 40.0;
	data->XX_FRefRmpDo = 40.0;
}

void FrefUDcLk(TYPE_UFCOMA *data)
{

}

void FrefRmp(TYPE_UFCOMA *data)
{
	if(data->WF_3PhRmp < data->PF_3PhMin)
		data->WF_3PhRmp = data->PF_3PhMin;
	if(data->WF_3PhRmp < data->PF_3PhNom)
	{
		data->WF_3PhRmp += data->XX_FRefRmpUp*data->Tsc;
		if(data->WF_3PhRmp > data->PF_3PhNom)
			data->WF_3PhRmp = data->PF_3PhNom;
	}
	if(data->WF_3PhRmp > data->PF_3PhNom)
	{
		data->WF_3PhRmp -= data->XX_FRefRmpDo*data->Tsc;
		if(data->WF_3PhRmp < data->PF_3PhNom)
			data->WF_3PhRmp = data->PF_3PhNom;
	}
}

void UF3PhCmp(TYPE_UFCOMA *data)
{
	if(data->A_CvOp && data->L_EnUF3PhCmp)
	{
		data->WF_WF3PhCmp = data->PF_UF3PhCmpActHiLo/data->PI_UF3PhCmpActHiLo*data->XI_PhAct;
		data->WU_UF3PhCmp = data->PU_UF3PhCmpRctHiLo/data->PI_UF3PhCmpRctHiLo*data->XI_PhRct;
	}
	else
	{
		data->WF_WF3PhCmp = 0.0;
		data->WU_UF3PhCmp = 0.0;
	}
}

void F3PhSz(TYPE_UFCOMA *data)
{
	data->WF_UF3PhSz = 0.0;
}

void U3PhSz(TYPE_UFCOMA *data)
{
	data->WU_UF3PhSz = 0.0;
}

void IPhClGenOvLd(TYPE_UFCOMA *data)
{
	data->WF_IPhCl = 0.0;
}

void IPhClPsTrs(TYPE_UFCOMA *data)
{

}

