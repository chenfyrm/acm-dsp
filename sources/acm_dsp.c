#include "math.h"
#include "acm_dsp.h"

#define SIMULATION 1
#define U3PHRMS 380.0

volatile struct Dsp_Data DspData;
TYPE_SOGIOSGMA sogiosg = SOGIOSGMA_DEFAULTS;
TYPE_IIRFILTER_2ND U3PhRe,
U3PhIm;
volatile struct Dsp_Param DspParam;

volatile struct Mcu_Data McuData;
TYPE_PI_CONTROLLER PI_F3PhSz = PI_CONTROLLER_DEFAULTS;
TYPE_PI_CONTROLLER PI_U3PhCl = PI_CONTROLLER_DEFAULTS;
volatile struct Mcu_Param McuParam;

/*IRQB 370us*/
void ANIN_B(void);
void CSIV_B(void);
void MEMS_B(void);
void POCP_B(void);
void CALI_B(void);
void SIPR_B(void);
void ACCL_B(void);
void BACC_B(void);
void UFCO_B(void);
void PPG3_B(void);
void LOGB_B(void);

float32 OvMd(float32 M1);
void SVPWM(volatile float32 *DutyA, volatile float32 *DutyB,
		volatile float32 *DutyC, cfloat32 _3PhAB);
void DdCmp(void);

/*IRQC 200us*/
void BCHO_C(void);
void SFPA_C(void);
void DUVP_C(void);
void DOVP_C(void);
void ERFL_C(void);
void OROP_C(void);
void PABO_C(void);
void PROT_C(void);
void SRTO_C(void);
void HWSS_C(void);

/*IRQD 166us 2QC*/

/*T1 500us*/

/*T2 1ms*/
void HSTI_T2(void);
void FPGI_T2(void);
void MEMS_T2(void);
void ACCL_T2(void);
void ACLS_T2(void);
void OVPT_T2(void);
void OROP_T2(void);
void POCP_T2(void);
void AICS_T2(void);
void HWTS_T2(void);
void HWSS_T2(void);
void FPGO_T2(void);
void DIAG_T2(void);
void HSTO_T2(void);

/*T3 100ms*/
void SFSU_T3(void);
void DIAG_T3(void);
void DCUI_T3(void);
void HSTP_T3(void);
void HWSS_T3(void);

/**/
void DspInit(void) {
	DspParam.PN_IPhFixMcu_Flt = 4.0; //rad/s
	DspParam.PN_U3PhRms_Flt = 5.0; //5
	DspParam.PN_UDcLk_Flt = 100.0;
	DspParam.PN_URef_Flt = 600.0;
	DspParam.PN_IPhActRct_Flt = 2000.0;
	DspParam.PN_IPhActRctMcu_Flt = 20.0;
	DspParam.PN_IPhAbs_Flt = 60.0;
	DspParam.PN_PQ3PhMcu_Flt = 60.0;
	DspParam.PN_IPhDQ_Flt = 18.0;
	DspParam.PN_IPhRms_Flt = 30.0;
	DspParam.PN_URefIPhClTrs_Flt = 20.0;

	DspParam.PU_PhClTrsMax = 75.0; //	75
	DspParam.PI_PhClTrsAbsLim = 600.0; //	600

	if (SIMULATION) {
		DspParam.PD_ThetaFiOs = PI / 3.0 - PI / 180.0;

	} else {
		DspParam.PD_ThetaFiOs = PI / 3.0 - 4.5 / 180.0 * PI; //同步相位补偿,1.047 线电压落后相电压60deg,死区时间造成电压相位滞后
	}
	DspParam.PZ_3PhFiNdRe = 0.078; //	0,078 滤波电感电阻
	DspParam.PZ_3PhFiNdIm = 0.207; //	0,207滤波电感电抗
	DspParam.PZ_3PhFiCaIm = -5.47; //	-5,47 滤波电容电抗折算到一次侧
	DspParam.PZ_3PhTfRe = 0.0; //	0
	DspParam.PZ_3PhTfIm = 0.0; //	0

	/*直流振荡抑制*/
	DspParam.L_UDcLkStbEn = TRUE; //	TRUE
	DspParam.PN_UDcLkStbSliSmt = 2200.0; //	2200
	DspParam.PN_UDcLkStbHevSmt = 13.5; //	13,5
	DspParam.PU_DcLkStbMaxMin = 100.0; //	100
	DspParam.PX_KpUDcLkStb = 150.0; //需调试
	DspParam.PX_KpUDcLkVoStbFb = 0.00002;

	/**/
//	data->PARADP_PX_3PhClRtMax = 1 - 0.00000025 * (MWT_REAL) (data->PARTDP_PT_PoaOnMin * data->PARADP_PX_T3PhSmpNvt) ;
//	data->PARADP_PX_3PhClRtHgh = 1 - 0.00000050 * (MWT_REAL) (data->PARTDP_PT_PoaOnMin * data->PARADP_PX_T3PhSmpNvt) ;
//	data->PARADP_PX_3PhClRtLow = 0.00000050 * (MWT_REAL) (data->PARTDP_PT_PoaOnMin * data->PARADP_PX_T3PhSmpNvt) ;
//	data->PARADP_PX_3PhClRtMin = 0.00000025 * (MWT_REAL) (data->PARTDP_PT_PoaOnMin * data->PARADP_PX_T3PhSmpNvt) ;
//	data->PARADP_PT_PoaOfMin = 2 * data->PARTDP_PT_PrDdPoa + data->PARTDP_PT_PoaOnMin ;
	DspParam.PX_3PhClRtHgh = 0.94;
	DspParam.PX_3PhClRtLow = 0.06;

	DspParam.PF_IRQBMax = 150000000.0 / 8.0;
	DspParam.PF_3PhSg = 1350.0;
	DspParam.L_3PhRndEn = FALSE; //TRUE
	DspParam.PX_3PhRndMax = 0.0345; //0.0345

	DspParam.L_EnIPhClRms = FALSE;

	if (SIMULATION) {
	} else {
		Uint16 i;
		for (i = 0; i < sizeof(DspData); i++) {
			*((Uint16*) &DspData + i) = 0;
		}
		for (i = 0; i < sizeof(sogiosg); i++) {
			*((Uint16*) &sogiosg + i) = 0;
		}
		for (i = 0; i < sizeof(U3PhRe); i++) {
			*((Uint16*) &U3PhRe + i) = 0;
		}
		for (i = 0; i < sizeof(U3PhIm); i++) {
			*((Uint16*) &U3PhIm + i) = 0;
		}
	}

	DspData.XX_PwmPdVv = floor(1.0 / 1350.0 / 2.0 * DspParam.PF_IRQBMax);
	DspData.XT_Tsc = DspData.XX_PwmPdVv / DspParam.PF_IRQBMax; //开关频率1350Hz，波峰波谷双采样
	DspData.XX_DutyA = 0.5;
	DspData.XX_DutyB = 0.5;
	DspData.XX_DutyC = 0.5;
	DspData.XX_Mode = 0;

//	DspData.XU_3PhSqu = 0.0;
//
//	DspData.XI_Ph1Rms = 0.0;
//	DspData.XI_Ph2Rms = 0.0;
//	DspData.XI_Ph3Rms = 0.0;
//	DspData.XI_Ph1Squ = 0.0;
//	DspData.XI_Ph2Squ = 0.0;
//	DspData.XI_Ph3Squ = 0.0;
//	DspData.XX_CntPh1Rms = 0;
//	DspData.XX_CntPh2Rms = 0;
//	DspData.XX_CntPh3Rms = 0;
}

void DspTask_185us(void) {

	/*
	 * clark变换
	 * */
	DspData.XI_PhAB = PH3TOCPLX(DspData.XI_PhA, DspData.XI_PhB, DspData.XI_PhC);
	LowPass(&DspData.XI_PhReFix, DspData.XI_PhAB.re,
			DspData.XT_Tsc * DspParam.PN_IPhFixMcu_Flt / 2.0);
	LowPass(&DspData.XI_PhImFix, DspData.XI_PhAB.im,
			DspData.XT_Tsc * DspParam.PN_IPhFixMcu_Flt / 2.0);

	cfloat32 XS_3Ph;
	XS_3Ph = CPLXSCA(CPLXMULT(DspData.WU_3PhAB, CPLXCONJ(DspData.XI_PhAB)),
			1.5);
	DspData.XP_3Ph = XS_3Ph.re;
	DspData.XQ_3Ph = XS_3Ph.im;

	/*park变换*/
	DspData.XI_PhDQ = CPLXMULT(DspData.XI_PhAB,
			POL2CPLX(1.0, -DspData.WX_Theta));
	/**/
	DspData.XI_PhAct = DspData.XI_PhDQ.re;
	DspData.XI_PhRct = DspData.XI_PhDQ.im;

	/*********************************************
	 *
	 *
	 *******************************************/
	/*IIR Notch Filter*/
	U3PhRe.In = 2.0 * DspData.XU_PhABLk
			* cos(DspData.WX_Theta + DspParam.PD_ThetaFiOs);
	AdaptIIRNotchFilter(&U3PhRe, 2.0 * PI2 * Max(McuData.WF_3PhDsp, 1.0),
			DspData.XT_Tsc);
//		DspData.XU_3PhRe = U3PhRe.Out;

	U3PhIm.In = 2.0 * DspData.XU_PhABLk
			* sin(DspData.WX_Theta + DspParam.PD_ThetaFiOs);
	AdaptIIRNotchFilter(&U3PhIm, 2.0 * PI2 * Max(McuData.WF_3PhDsp, 1.0),
			DspData.XT_Tsc);
//		DspData.XU_3PhIm = U3PhIm.Out;
	/**/
	DspData.XU_3PhAbs_Notch = sqrt(
			U3PhRe.Out * U3PhRe.Out + U3PhIm.Out * U3PhIm.Out);

	/*
	 *
	 * */
	sogiosg.phase = DspData.XU_PhABLk;
	sogiosg.Ts = DspData.XT_Tsc; //
	sogiosg.w0 = 100 * PI;
	sogiosg.K = sqrt(0.1); //sqrt(2)
	sogiosg.Ki = 10000;

	SOGIOSGFLL(&sogiosg);

	DspData.XF_U3Ph = sogiosg.w / 2.0 / PI;

	cfloat32 XU_3PhAB, XU_3PhDQ;
	/**/
	if (SIMULATION) {
		//仿真
		XU_3PhAB = CPLXSCA(
				CPLXMULT(FRAC2CPLX(sogiosg.alpha, sogiosg.beta),
						POL2CPLX(1.0, 0.0)), 1.0);

	} else {
		//调试
		//		XU_3PhAB = CPLXSCA(
		//				CPLXMULT(FRAC2CPLX(sogiosg.alpha, sogiosg.beta),
		//						POL2CPLX(1.0, PI / 2.0)),
		//				1.095 * 100.0 * PI / sqrt(sogiosg.w * sogiosg.w + 1));
		XU_3PhAB = CPLXSCA(
				CPLXMULT(FRAC2CPLX(sogiosg.alpha, sogiosg.beta),
						POL2CPLX(1.0, PI / 2.0)), 1.095);
	}
	XU_3PhDQ = CPLXMULT(XU_3PhAB,
			POL2CPLX(1.0, -(DspData.WX_Theta + DspParam.PD_ThetaFiOs)));

	DspData.XU_3PhRe = XU_3PhDQ.re;
	DspData.XU_3PhIm = XU_3PhDQ.im;
	DspData.XU_3PhAbs = sqrt(
			DspData.XU_3PhRe * DspData.XU_3PhRe
					+ DspData.XU_3PhIm * DspData.XU_3PhIm);

	DspData.WX_Theta += 2.0 * PI * McuData.WF_3PhDsp * DspData.XT_Tsc;
	DspData.WX_Theta = fmod(DspData.WX_Theta, 2 * PI);

	if (McuData.C_AuSz) {
		float32 temp = sqrt(
				DspData.XU_3PhRe * DspData.XU_3PhRe
						+ DspData.XU_3PhIm * DspData.XU_3PhIm);
		PI_F3PhSz.Ref = 0.0;
		PI_F3PhSz.Fbk = -DspData.XU_3PhIm / Max(0.001, temp);

		//		PI_F3PhSz.Kp = McuParam.PX_KpF3PhSzCl;
		//		PI_F3PhSz.Ki = 16.0 / McuParam.PT_F3PhSzCl;
		PI_F3PhSz.Kp = PI2 * 0.5;
		PI_F3PhSz.Ki = DspData.XT_Tsc * PI_F3PhSz.Kp * PI_F3PhSz.Kp / 4.0;
		PI_F3PhSz.Umax = McuParam.PF_UF3PhSzClMaxMin;
		PI_F3PhSz.Umin = -McuParam.PF_UF3PhSzClMaxMin;
		PI_CONTROLLER(&PI_F3PhSz);
		McuData.WF_UF3PhSzErr = Limit(
				atan2(DspData.XU_3PhIm, Max(DspData.XU_3PhRe, 1.0)), -PI / 2.0,
				PI / 2.0);
		McuData.WF_UF3PhSz = PI_F3PhSz.Out;
	} else {
		McuData.WF_UF3PhSz = 0.0;
	}

	if (McuData.C_AuSz) {
		McuData.WU_UF3PhSzErr = DspData.XU_3PhAbs / SQRT3
				* McuParam.PX_TrfRtPr3Ph + McuParam.PU_UF3PhSzClAdd
				- McuData.WU_3PhDsp;

		INTEGR(&McuData.WU_UF3PhSz, McuData.WU_UF3PhSzErr, 16.0 / 200.0, 0.0,
				McuParam.PU_UF3PhSzClMaxMin, -McuParam.PU_UF3PhSzClMaxMin,
				FALSE, FALSE);

	} else {
//		RAMP(&McuData.WU_UF3PhSz,0.0);
		McuData.WU_UF3PhSz = 0.0;
	}
}

void DspTask_C(void) {
	SRTO_C();
}

/*
 *
 * */
void DspTask_B(void) {
	SIPR_B();
	ACCL_B();
	UFCO_B();
	PPG3_B();
}

void DspTask_T2(void) {
	ACCL_T2();
}

void DspTask_T3(void) {

}

void SRTO_C(void) {
	if (McuData.C_CvOpSa) {
		DspData.A_CvOp = TRUE;
	} else {
		DspData.A_CvOp = FALSE;
	}
}

void SIPR_B(void) {

//	DspData.WX_Theta += 2.0 * PI * McuData.WF_3PhDsp * DspData.XT_Tsc;
//	DspData.WX_Theta = fmod(DspData.WX_Theta, 2 * PI);

	/**/
//	DspData.XF_U3Ph = sogiosg.w / 2.0 / PI;
	/*IIR Notch Filter*/
//	U3PhRe.In = DspData.XU_PhABLk
//			* cos(DspData.WX_Theta + DspParam.PD_ThetaFiOs);
//	AdaptIIRNotchFilter(&U3PhRe, 2.0 * PI2 * Max(McuData.WF_3PhDsp, 1.0),
//			DspData.XT_Tsc);
//	DspData.XU_3PhRe = U3PhRe.Out;
//
//	U3PhIm.In = DspData.XU_PhABLk
//			* sin(DspData.WX_Theta + DspParam.PD_ThetaFiOs);
//	AdaptIIRNotchFilter(&U3PhIm, 2.0 * PI2 * Max(McuData.WF_3PhDsp, 1.0),
//			DspData.XT_Tsc);
//	DspData.XU_3PhIm = U3PhIm.Out;
	/**/
//	DspData.XU_3PhAbs = sqrt(
//			DspData.XU_3PhRe * DspData.XU_3PhRe
//					+ DspData.XU_3PhIm * DspData.XU_3PhIm);
//	LowPass(&DspData.XU_3PhSqu, DspData.XU_PhABLk * DspData.XU_PhABLk,
//			DspData.XT_Tsc * DspParam.PN_U3PhRms_Flt);
//	DspData.XU_3PhRms = sqrt(DspData.XU_3PhSqu);
	DspData.XU_3PhRms = DspData.XU_3PhAbs / SQRT2;

	/**/
	LowPass(&DspData.XU_DcLkFlt, DspData.XU_DcLk,
			DspData.XT_Tsc * DspParam.PN_UDcLk_Flt);
	LowPass(&DspData.WU_3PhAbs_Flt, DspData.WU_3PhAbs,
			DspData.XT_Tsc * DspParam.PN_URef_Flt);
	LowPass(&DspData.XI_PhAct_Flt, DspData.XI_PhAct,
			DspData.XT_Tsc * DspParam.PN_IPhActRct_Flt);
	LowPass(&DspData.XI_PhRct_Flt, DspData.XI_PhRct,
			DspData.XT_Tsc * DspParam.PN_IPhActRct_Flt);
	LowPass(&DspData.XI_PhAct_Flt2, DspData.XI_PhAct,
			DspData.XT_Tsc * DspParam.PN_IPhActRctMcu_Flt);
	LowPass(&DspData.XI_PhRct_Flt2, DspData.XI_PhRct,
			DspData.XT_Tsc * DspParam.PN_IPhActRctMcu_Flt);
	LowPass(&DspData.XI_PhAbs_Flt, DspData.XI_PhAbs,
			DspData.XT_Tsc * DspParam.PN_IPhAbs_Flt);
	LowPass(&DspData.XP_3Ph_Flt, DspData.XP_3Ph,
			DspData.XT_Tsc * DspParam.PN_PQ3PhMcu_Flt);
	LowPass(&DspData.XQ_3Ph_Flt, DspData.XQ_3Ph,
			DspData.XT_Tsc * DspParam.PN_PQ3PhMcu_Flt);
	CplxLowPass(&DspData.XI_PhDQ_Flt, DspData.XI_PhDQ,
			DspData.XT_Tsc * DspParam.PN_IPhDQ_Flt);
}

void ACCL_B(void) {

	float32 a, b, c;

	a = Min(DspParam.PI_PhClTrsAbsLim - DspData.XI_PhAbs, 0.0)
			* McuData.XX_IPhClTrsKpAbsDsp;
	b = Min(McuData.WI_PhActDsp - DspData.XI_PhAct_Flt, 0.0)
			* McuData.XX_IPhClTrsKpActDsp;
	c = Min(McuData.WI_PhRctDsp - DspData.XI_PhRct_Flt, 0.0)
			* McuData.XX_IPhClTrsKpRctDsp;

	DspData.WU_IPhClTrs = Max(-DspParam.PU_PhClTrsMax, a + b + c);
	if (DspData.WU_IPhClTrs < 0) {
		DspData.S_IPhClTrsAv = 1;
	} else {
		DspData.S_IPhClTrsAv = 0;
	}

	LowPass(&DspData.WU_IPhClTrs_Flt, DspData.WU_IPhClTrs,
			DspData.XT_Tsc * DspParam.PN_URefIPhClTrs_Flt);
}

void UFCO_B(void) {

	DspData.WU_3PhSec = POL2CPLX(McuData.WU_3PhDsp, 0.0); //静止坐标系按1次侧，同步频率按WF_3PhDsp  DQ

	DspParam.PZ_3PhFiNd = FRAC2CPLX(DspParam.PZ_3PhFiNdRe,
			DspParam.PZ_3PhFiNdIm / 50.0 * McuData.WF_3PhDsp);
	DspParam.PZ_3PhFiCa = FRAC2CPLX(0.0,
			DspParam.PZ_3PhFiCaIm / 50.0 * McuData.WF_3PhDsp);
	DspParam.PZ_3PhTf = FRAC2CPLX(DspParam.PZ_3PhTfRe,
			DspParam.PZ_3PhTfIm / 50.0 * McuData.WF_3PhDsp);

	cfloat32 Z1, Z2;
	Z1 = CPLXDIV(DspParam.PZ_3PhFiCa,
			CPLXADD(DspParam.PZ_3PhFiCa, DspParam.PZ_3PhTf));
	Z2 = CPLXADD(DspParam.PZ_3PhFiNd, CPLXMULT(DspParam.PZ_3PhTf, Z1));

	/**/
	DspData.WU_3PhPm = CPLXADD(CPLXMULT(DspData.WU_3PhSec, Z1),
			CPLXMULT(DspData.XI_PhDQ_Flt, Z2));
	//B_EnBuiTs
//		DspData.WU_3PhPm = DspData.WU_3PhSec;	//DQ
	/*
	 * ipark变换
	 * */
	DspData.WU_3PhPmAB = CPLXMULT(DspData.WU_3PhPm,
			POL2CPLX(1.0, DspData.WX_Theta)); //ipark
	/*
	 * 电流直流分量控制
	 * WU_IPhDcClRe WU_IPhDcClIm
	 * */

	/**/

	CPLX2POL(&DspData.WU_Ref_Abs, &DspData.WX_ThetaCv, DspData.WU_3PhPmAB);

	/******************************************************************
	 * 直流母线电压振荡抑制
	 *
	 *
	 *
	 *
	 *****************************************************************/
	LowPass(&DspData.XU_DcLkStbFltSli, DspData.XU_DcLk,
			DspData.XT_Tsc * DspParam.PN_UDcLkStbSliSmt);
	LowPass(&DspData.XU_DcLkStbFltHev, DspData.XU_DcLk,
			DspData.XT_Tsc * DspParam.PN_UDcLkStbHevSmt);
	DspData.WU_DcLkStb = Limit(
			DspParam.PX_KpUDcLkStb
					* (pow(DspData.XU_DcLkStbFltSli / DspData.XU_DcLkStbFltHev,
							2.0) - 1.0), -DspParam.PU_DcLkStbMaxMin,
			DspParam.PU_DcLkStbMaxMin);

	/**/
	DspData.WU_Ref_Abs = DspData.WU_Ref_Abs + DspData.WU_IPhClTrs
			+ DspData.WU_DcLkStb;
	DspData.WU_Ref_Abs = Max(0.0, DspData.WU_Ref_Abs);

	DspData.XX_MRef = DspData.WU_Ref_Abs / DspData.XU_DcLk;
	if (DspData.A_CvOp && (DspData.XX_MRef > ONEbySQRT3)) {
		DspData.S_3PhOvMd = 1;
	} else {
		DspData.S_3PhOvMd = 0;
	}

	DspData.WU_OvMd = DspData.XU_DcLk * Min(0.6057 - DspData.XX_MRef, 0); //<0
	DspData.WU_3PhAbsOvMd = DspData.XU_DcLk * OvMd(DspData.XX_MRef);
	if (DspData.B_LimAct) {
		DspData.WU_IPhClRmsRed = DspData.WU_IPhClRms - DspData.WU_3PhAbsOvMd;
	} else {
		DspData.WU_IPhClRmsRed = 0;
	}
	DspData.WU_3PhAbs = DspData.WU_3PhAbsOvMd + DspData.WU_IPhClRmsRed;
	DspData.WU_3PhAB = POL2CPLX(DspData.WU_3PhAbs, DspData.WX_ThetaCv);

	SVPWM(&DspData.XX_CrU, &DspData.XX_CrV, &DspData.XX_CrW,
			CPLXSCA(DspData.WU_3PhAB, 1.0 / DspData.XU_DcLk));

	DspData.XX_Mode = !DspData.XX_Mode;
//	DdCmp();

}

void PPG3_B(void) {

	/***************/
	if (Max(DspData.XX_CrU, Max(DspData.XX_CrV, DspData.XX_CrW))
			> DspParam.PX_3PhClRtHgh) {
		DspData.S_UDcLkLow = 1;
	} else {
		DspData.S_UDcLkLow = 0;
	}

	/*
	 * 随机开关频率降噪
	 * */
	if (!DspParam.L_3PhRndEn) {
		DspData.XT_Tsc = 0.5 / DspParam.PF_3PhSg; //开关频率1350Hz，波峰波谷双采样
	} else {

	}
	/**/
	DspData.XX_PwmPdVv = DspData.XT_Tsc * DspParam.PF_IRQBMax + 0.5;

	/*
	 * 最小脉宽限制
	 * */
	DspData.XX_DutyA = Limit(DspData.XX_CrU, DspParam.PX_3PhClRtLow,
			DspParam.PX_3PhClRtHgh);
	DspData.XX_DutyB = Limit(DspData.XX_CrV, DspParam.PX_3PhClRtLow,
			DspParam.PX_3PhClRtHgh);
	DspData.XX_DutyC = Limit(DspData.XX_CrW, DspParam.PX_3PhClRtLow,
			DspParam.PX_3PhClRtHgh);
}

/*
 * 过调制
 * */
float32 OvMd(float32 M1) {
	//[0 1/sqrt(3) 0.579 0.6038 0.6057]
	//[0 1/sqrt(3) 0.58  0.6389 0.6667]

	float32 M;

	if (M1 < 0)
		M = 0;
	else if (M1 < 1.0 / sqrt(3))
		M = M1;
	else if (M1 < 0.579)
		M = 1.0 / sqrt(3)
				+ (0.58 - 1.0 / sqrt(3)) / (0.579 - 1.0 / sqrt(3))
						* (M1 - 1.0 / sqrt(3));
	else if (M1 < 0.6038)
		M = 0.58 + (0.6389 - 0.58) / (0.6038 - 0.579) * (M1 - 0.579);
	else if (M1 < 0.6057)
		M = 0.6389 + (0.6667 - 0.6389) / (0.6057 - 0.6038) * (M1 - 0.6038);
	else
		M = 0.6667;

	return M;
}

/*
 * 空间电压矢量调节
 * */
void SVPWM(volatile float32 *DutyA, volatile float32 *DutyB,
		volatile float32 *DutyC, cfloat32 _3PhAB) {
	float32 a, b, c, min, max, NrmFa, Cml;

	CPLXTO3PH(&a, &b, &c, _3PhAB);

	min = Min(a, Min(b, c));
	max = Max(a, Max(b, c));

	NrmFa = Max(1.0, max - min);
	Cml = (max + min) * (-0.5);

	*DutyA = (a + Cml) / NrmFa + 0.5;
	*DutyB = (b + Cml) / NrmFa + 0.5;
	*DutyC = (c + Cml) / NrmFa + 0.5;
}

/*
 * 死区补偿
 * */
void DdCmp(void) {
	/*
	 * 电流小于零时从上管续流，下管为可控管，电压增加
	 * 电流大于零时从下管续流，上管为可控管，电压减小
	 * ***************/
	if (DspData.XX_Mode) {
		float32 coff;
		if (DspData.XI_PhA <= 0) {

			if (fabs(DspData.XI_PhA) < 10.0)
				coff = 0.0;
			else if (fabs(DspData.XI_PhA) < 50.0)
				coff = (fabs(DspData.XI_PhA) - 10.0) / 40.0;
			else
				coff = 1.0;

			DspData.XX_CrU -= 0.00001 / DspData.XT_Tsc * coff;
		}
		if (DspData.XI_PhB <= 0) {

			if (fabs(DspData.XI_PhB) < 10.0)
				coff = 0.0;
			else if (fabs(DspData.XI_PhB) < 50.0)
				coff = (fabs(DspData.XI_PhB) - 10.0) / 40.0;
			else
				coff = 1.0;

			DspData.XX_CrV -= 0.00001 / DspData.XT_Tsc * coff;
		}
		if (DspData.XI_PhC <= 0) {

			if (fabs(DspData.XI_PhC) < 10.0)
				coff = 0.0;
			else if (fabs(DspData.XI_PhC) < 50.0)
				coff = (fabs(DspData.XI_PhC) - 10.0) / 40.0;
			else
				coff = 1.0;

			DspData.XX_CrW -= 0.00001 / DspData.XT_Tsc * coff;
		}

	} else {
		float32 coff;
		if (DspData.XI_PhA >= 0) {

			if (fabs(DspData.XI_PhA) < 10.0)
				coff = 0.0;
			else if (fabs(DspData.XI_PhA) < 50.0)
				coff = (fabs(DspData.XI_PhA) - 10.0) / 40.0;
			else
				coff = 1.0;

			DspData.XX_CrU += 0.00001 / DspData.XT_Tsc * coff;
		}
		if (DspData.XI_PhB >= 0) {

			if (fabs(DspData.XI_PhB) < 10.0)
				coff = 0.0;
			else if (fabs(DspData.XI_PhB) < 50.0)
				coff = (fabs(DspData.XI_PhB) - 10.0) / 40.0;
			else
				coff = 1.0;

			DspData.XX_CrV += 0.00001 / DspData.XT_Tsc * coff;
		}
		if (DspData.XI_PhC >= 0) {

			if (fabs(DspData.XI_PhC) < 10.0)
				coff = 0.0;
			else if (fabs(DspData.XI_PhC) < 50.0)
				coff = (fabs(DspData.XI_PhC) - 10.0) / 40.0;
			else
				coff = 1.0;

			DspData.XX_CrW += 0.00001 / DspData.XT_Tsc * coff;
		}
	}

}

/*
 * DSP中1ms任务
 * */
void ACCL_T2(void) {
	RmsClc(&DspData.XI_Ph1Rms, DspData.XI_PhA, 50, &DspData.XI_Ph1Squ,
			&DspData.XX_CntPh1Rms);
	RmsClc(&DspData.XI_Ph2Rms, DspData.XI_PhB, 50, &DspData.XI_Ph2Squ,
			&DspData.XX_CntPh2Rms);
	RmsClc(&DspData.XI_Ph3Rms, DspData.XI_PhC, 50, &DspData.XI_Ph3Squ,
			&DspData.XX_CntPh3Rms);

	LowPass(&DspData.XI_Ph1Rms_Flt, DspData.XI_Ph1Rms,
			0.001 * DspParam.PN_IPhRms_Flt);
	LowPass(&DspData.XI_Ph2Rms_Flt, DspData.XI_Ph2Rms,
			0.001 * DspParam.PN_IPhRms_Flt);
	LowPass(&DspData.XI_Ph3Rms_Flt, DspData.XI_Ph3Rms,
			0.001 * DspParam.PN_IPhRms_Flt);

	DspData.WU_IPhClRms = 0.0;
	DspData.B_LimAct = 0;

	if (DspParam.L_EnIPhClRms) //功能未开启
	{

	}
}

/****************************************************
 *
 *
 *****************************************************/
void CvOpSaSq(void);
void CvOpSoSq(void);
void UF3PhCmp(void);
void IPhClGenOvLd(void);
void IPhClPsTrs(void);
void F3PhRef(void);
void U3PhRef(void);
void U3PhCl(void);

void TFrefRmp(void);
void FrefUDcLk(void);
void FrefRmp(void);
void F3PhSz(void);
void U3PhSz(void);
void UF3PhSz(void);

/**/
void McuInit(void) {

	/*CvOpSaSq 4ms*/
	McuParam.PU_3PhIdlCmp = 10.0;
	McuParam.PU_3PhActCmp = 30.0;

	/*CvOpSoSq 4ms*/

	/*UF3PhCmp 4ms*/
	McuParam.L_EnUF3PhCmp = FALSE;	//TRUE
	McuParam.PI_UF3PhCmpActHiLo = 4000.0;
	McuParam.PF_UF3PhCmpActHiLo = -10.0;
	McuParam.PI_UF3PhCmpRctHiLo = 4000.0;
	McuParam.PU_UF3PhCmpRctHiLo = -100.0;

	/*IPhClGenOvLd 4ms*/

	/*IPhClPsTrs 4ms*/
	McuParam.PX_IPhClTrsKpAct = 0.005;
	McuParam.PX_IPhClTrsKpRct = 0.03;
	McuParam.PX_IPhClTrsKpAbs = 0.0;

	/*F3PhRef 4ms*/

	/*U3PhRef*/
	McuParam.PF_U3PhRef2 = 6.0;
	McuParam.PF_U3PhRef3 = 50.0;
	McuParam.PU_U3PhRef1 = 0.0; //0Hz
	McuParam.PU_U3PhRef2 = 0.0;  //6Hz
	McuParam.PU_U3PhRef3 = U3PHRMS * SQRT2bySQRT3;  //50Hz
	McuParam.PU_U3PhRef4 = U3PHRMS * SQRT2bySQRT3; //100Hz
	McuParam.L_ExtU3PhRef = FALSE;
	McuParam.PX_ExtU3PhRefRmp = 200.0;
	McuParam.L_EnRmpU3PhRef = FALSE;
	McuParam.PX_U3PhRefRmp1 = 200.0;
	McuParam.PX_U3PhRefRmp2 = 50.0;
	McuParam.PX_U3PhRefRmpSel = 0.9;

	/*U3PhCl 4ms*/
	McuParam.L_En3PhCl = TRUE; //TRUE
	McuParam.L_EnU3PhOpLoCl = FALSE;
	McuParam.PX_KpU3PhCl = 0.8;
	McuParam.PT_U3PhCl = 50.0; //ms
	McuParam.PU_3PhClMax = 75.0;
	McuParam.PU_3PhClMin = -50.0;
	McuParam.PU_3PhClRefMax = 395.0 * SQRT2bySQRT3;
	McuParam.PU_3PhClRefMin = 0.0;
	McuParam.PX_TrfRtPr3Ph = 1.684;

	/*TFrefRmp 16ms*/
	McuParam.PX_FRefRmpUp = 40.0;
	McuParam.PX_FRefRmpUpSlaveAcm = 100.0;
	McuParam.PX_FRefRmpDo1 = 40.0;
	McuParam.PX_FRefRmpDo2 = 40.0;
	McuParam.PX_FRefRmpDo3 = 40.0;
	McuParam.PF_FRefRmpDo12 = 4.0;
	McuParam.PF_FRefRmpDo23 = 30.0;

	/*FrefUDcLk 16ms*/
	McuParam.PF_UDcLkMin = 50.0;	//	50
	McuParam.PU_DcLkFRefMin = 1000.0;	//	1000
	McuParam.PU_DcLkFRefLow = 1000.;	//	1000
	McuParam.PX_FRefRmpUDcLkUp = 1000.0;	//	40
	McuParam.PX_FRefRmpUDcLkDo = 1000.0;	//	40
	McuParam.PT_FRefUDcLk = 100;	//100ms

	/*FrefRmp 16ms*/
	McuParam.PF_3PhNom = 50.0;
	McuParam.PF_3PhMin = 3.0;

	/*F3PhSz 16ms*/
	McuParam.PX_KpF3PhSzCl = 0.5;	//0.5
	McuParam.PT_F3PhSzCl = 160.0; //800ms
	McuParam.PF_UF3PhSzClMaxMin = 50.0;
	McuParam.PT_UF3PhSzRmp = 1000.0; //ms

	/*U3PhSz 16ms*/
	McuParam.PU_UF3PhSzClAdd = 0.0; //同步幅值补偿
	McuParam.PU_UF3PhSzClMaxMin = 100.0;

	/*UF3PhSz 16ms*/
	McuParam.PF_UF3PhSzRdy = 0.3;
	McuParam.PU_UF3PhSzRdy = 20.0 * SQRT2bySQRT3;
	if (SIMULATION) {
		McuParam.PT_UF3PhSzRdy = 250.0; //250ms

	} else {
		McuParam.PT_UF3PhSzRdy = 10000.0; //250ms

	}

	McuParam.PT_UF3PhSzFl = 5000.0; //5000ms

	/**/
	if (SIMULATION) {
	} else {
		Uint16 i;
		for (i = 0; i < sizeof(McuData); i++) {
			*((Uint16*) &McuData + i) = 0;
		}
		for (i = 0; i < sizeof(PI_F3PhSz); i++) {
			*((Uint16*) &PI_F3PhSz + i) = 0;
		}
		for (i = 0; i < sizeof(PI_U3PhCl); i++) {
			*((Uint16*) &PI_U3PhCl + i) = 0;
		}
	}
}

void McuTask_4ms(void) {
	/**/
	CvOpSaSq();
	CvOpSoSq();
	UF3PhCmp();
	IPhClGenOvLd();
	IPhClPsTrs();
	F3PhRef();
	U3PhRef();
	U3PhCl();
}

void McuTask_16ms(void) {
	TFrefRmp();
	FrefUDcLk();
	FrefRmp();
//	F3PhSz();
//	U3PhSz();
	UF3PhSz();
}

/*
 * 4ms
 * */
void CvOpSaSq(void) {
	if (McuData.NX_SqStCvOpSa == 0) {
		if (McuData.C_CvOpSa_MnSq) {
			if (DspData.XU_3PhRms < McuParam.PU_3PhIdlCmp) {
				McuData.NX_SqStCvOpSa = 1;
			} else if (DspData.XU_3PhRms > McuParam.PU_3PhActCmp) {
				McuData.NX_SqStCvOpSa = 2;
			}
		}
	} else if (McuData.NX_SqStCvOpSa == 1) {
		McuData.C_CdAuLdCt = TRUE;
		if (McuData.A_CdAuLdCt) {
			McuData.NX_SqStCvOpSa = 2;
		}
	} else if (McuData.NX_SqStCvOpSa == 2) {
		McuData.C_Ck3PhGduFb = TRUE;
		McuData.NX_SqStCvOpSa = 3;
	} else if (McuData.NX_SqStCvOpSa == 3) {
		McuData.C_CvOpSa = TRUE;
		if (DspData.A_CvOp) {
			McuData.NX_SqStCvOpSa = 4;
		}
	} else if (McuData.NX_SqStCvOpSa == 4) {
		McuData.C_FRmp = TRUE;
		if (McuData.A_FNom)
			McuData.NX_SqStCvOpSa = 5;
	} else if (McuData.NX_SqStCvOpSa == 5) {
		if (McuData.A_CdAuLdCt) {
			McuData.NX_SqStCvOpSa = 8;
		} else {
			McuData.NX_SqStCvOpSa = 6;
		}
	} else if (McuData.NX_SqStCvOpSa == 6) {
		McuData.C_AuSz = TRUE;
		if (McuData.A_AuSz) {
			McuData.NX_SqStCvOpSa = 7;
		}
	} else if (McuData.NX_SqStCvOpSa == 7) {
		McuData.C_CdAuLdCt = TRUE;
		if (McuData.A_CdAuLdCt) {
			McuData.NX_SqStCvOpSa = 8;
		}
	} else if (McuData.NX_SqStCvOpSa == 8) {
		McuData.A_CvOpSa = TRUE;
//		McuData.B_EnU3PhCl = TRUE;//微网
		McuData.C_AuSz = TRUE; //强网
	}
}

/*
 *
 * */
void CvOpSoSq(void) {
	if (McuData.NX_SqStCvOpSo == 0) {
		if (McuData.C_CvOpSo_MnSq)
			McuData.NX_SqStCvOpSo = 1;
	} else if (McuData.NX_SqStCvOpSo == 1) {
		McuData.C_CvOpSa = FALSE;
		if (!DspData.A_CvOp) {
			McuData.NX_SqStCvOpSo = 2;
		}
	} else if (McuData.NX_SqStCvOpSo == 2) {
		McuData.C_CkSrCtI = TRUE;
		if (McuData.A_SrCtIOk)
			McuData.NX_SqStCvOpSo = 2;
	} else if (McuData.NX_SqStCvOpSo == 3) {
		McuData.C_OpAuLdCt = TRUE;
		McuData.C_OpSrCt = TRUE;
		McuData.C_OpChCt = TRUE;
		if ((!McuData.A_CdAuLdCt) && (!McuData.A_CdSrCt) && (!McuData.A_CdChCt))
			McuData.NX_SqStCvOpSo = 5;
	} else if (McuData.NX_SqStCvOpSo == 4) {
		McuData.C_OpAuLdCt = TRUE;
		if (!McuData.A_CdAuLdCt)
			McuData.NX_SqStCvOpSo = 5;
	} else if (McuData.NX_SqStCvOpSo == 5) {
		McuData.A_CvOpSo = TRUE;
	}
}

/*
 * 4ms
 * */
void UF3PhCmp(void) {
	if (McuParam.L_EnUF3PhCmp) {
		if (DspData.XI_PhAct_Flt2 < -McuParam.PI_UF3PhCmpActHiLo)
			McuData.WF_UF3PhCmp = -McuParam.PF_UF3PhCmpActHiLo;
		else if (DspData.XI_PhAct_Flt2 < McuParam.PI_UF3PhCmpActHiLo)
			McuData.WF_UF3PhCmp = McuParam.PF_UF3PhCmpActHiLo
					/ McuParam.PI_UF3PhCmpActHiLo * DspData.XI_PhAct_Flt2;
		else
			McuData.WF_UF3PhCmp = McuParam.PF_UF3PhCmpActHiLo;

		if (DspData.XI_PhRct_Flt2 < -McuParam.PI_UF3PhCmpRctHiLo)
			McuData.WU_UF3PhCmp = -McuParam.PU_UF3PhCmpRctHiLo;
		else if (DspData.XI_PhRct_Flt2 < McuParam.PI_UF3PhCmpRctHiLo)
			McuData.WU_UF3PhCmp = McuParam.PU_UF3PhCmpRctHiLo
					/ McuParam.PI_UF3PhCmpRctHiLo * DspData.XI_PhRct_Flt2;
		else
			McuData.WU_UF3PhCmp = McuParam.PU_UF3PhCmpRctHiLo;
	} else {
		McuData.WF_UF3PhCmp = 0.0;
		McuData.WU_UF3PhCmp = 0.0;
	}
}

/*4ms*/
void IPhClGenOvLd(void) {
	McuData.WF_IPhCl = 0.0;
}

/*4ms*/
void IPhClPsTrs(void) {
	McuData.WI_PhActDsp = 450;
	McuData.WI_PhRctDsp = 300;
}

/*4ms*/
void F3PhRef(void) {
	McuData.WF_3PhU3PhRef = McuData.WF_3PhRmp + McuData.WF_IPhCl
			+ McuData.WF_UF3PhSz;
	McuData.WF_3PhDsp = McuData.WF_3PhU3PhRef + McuData.WF_UF3PhCmp;
}

/*4ms*/
void U3PhRef(void) {
	if (!McuParam.L_ExtU3PhRef) {
		if (McuData.WF_3PhU3PhRef <= 0.0)
			McuData.WU_3PhU3PhRef = McuParam.PU_U3PhRef1;
		else if (McuData.WF_3PhU3PhRef <= McuParam.PF_U3PhRef2)
			McuData.WU_3PhU3PhRef = McuParam.PU_U3PhRef1
					+ (McuData.WF_3PhU3PhRef - 0.0)
							/ (McuParam.PF_U3PhRef2 - 0.0)
							* (McuParam.PU_U3PhRef2 - McuParam.PU_U3PhRef1);
		else if (McuData.WF_3PhU3PhRef <= McuParam.PF_U3PhRef3)
			McuData.WU_3PhU3PhRef = McuParam.PU_U3PhRef2
					+ (McuData.WF_3PhU3PhRef - McuParam.PF_U3PhRef2)
							/ (McuParam.PF_U3PhRef3 - McuParam.PF_U3PhRef2)
							* (McuParam.PU_U3PhRef3 - McuParam.PU_U3PhRef2);
		else if (McuData.WF_3PhU3PhRef <= 100.0)
			McuData.WU_3PhU3PhRef = McuParam.PU_U3PhRef3
					+ (McuData.WF_3PhU3PhRef - McuParam.PF_U3PhRef3)
							/ (100.0 - McuParam.PF_U3PhRef3)
							* (McuParam.PU_U3PhRef4 - McuParam.PU_U3PhRef3);
		else
			McuData.WU_3PhU3PhRef = McuParam.PU_U3PhRef4;
	}

	RAMP2(&McuData.WU_3PhRmp, McuData.WU_3PhU3PhRef, McuParam.PX_U3PhRefRmp1,
			-McuParam.PX_U3PhRefRmp1, 0.0, FALSE, FALSE);

	if (!McuParam.L_EnRmpU3PhRef) {

	} else {

	}
	McuData.WU_3PhClIn = McuData.WU_3PhRmp + McuData.WU_UF3PhCmp
			+ McuData.WU_UF3PhSz;
//	McuData.WU_3PhDsp = McuData.WU_3PhClIn * McuParam.PX_TrfRtPr3Ph;
}

/*4ms*/
void U3PhCl(void) {
	McuData.WU_3PhClIn = McuData.WU_3PhRmp + McuData.WU_UF3PhCmp
			+ McuData.WU_UF3PhSz;
	McuData.WU_3PhClIn = Limit(McuData.WU_3PhClIn, McuParam.PU_3PhClRefMin,
			McuParam.PU_3PhClRefMax);

	PI_U3PhCl.Ref = McuData.WU_3PhClIn
			+ (DspData.WU_IPhClTrs_Flt + DspData.WU_OvMd
					+ DspData.WU_IPhClRmsRed) / McuParam.PX_TrfRtPr3Ph;
	PI_U3PhCl.Fbk = DspData.XU_3PhAbs / SQRT3;

	if (McuData.B_EnU3PhCl) {
		PI_U3PhCl.Kp = McuParam.PX_KpU3PhCl;
		//		PI_U3PhCl.Ki = 1000.0 * Ts / McuData.PT_U3PhCl;
		//	YI := YI + ((KP * ERROR) / LIMIT(1.0,TN_TZ,3.4E+38)) ;
		PI_U3PhCl.Ki = PI_U3PhCl.Kp * 4.0 / McuParam.PT_U3PhCl; //TN_TZ 控制周期的倍率，推荐大于10  PI_U3PhCl.Kp *Ts*1000/ McuData.PT_U3PhCl; 4ms/50ms
		PI_U3PhCl.Umax = McuParam.PU_3PhClMax;
		PI_U3PhCl.Umin = McuParam.PU_3PhClMin;
		PI_CONTROLLER(&PI_U3PhCl);
	} else {
		PI_U3PhCl.i1 = 0.0;
		PI_U3PhCl.v1 = 0.0;
		PI_U3PhCl.Out = 0.0;
	}

	McuData.WU_U3PhClOut = PI_U3PhCl.Out;
	McuData.WU_3PhDsp = McuData.WU_3PhClIn * McuParam.PX_TrfRtPr3Ph
			+ McuData.WU_U3PhClOut;
}

/*16ms*/
void TFrefRmp(void) {
	if (McuData.WF_3PhDsp < McuParam.PF_3PhMin)
		McuData.XX_FRefRmpUp = 1000.0;
	else
		McuData.XX_FRefRmpUp = McuParam.PX_FRefRmpUp;
	/**/
	if (McuData.WF_3PhDsp < McuParam.PF_FRefRmpDo12)
		McuData.XX_FRefRmpDo = McuParam.PX_FRefRmpDo1;
	else if (McuData.WF_3PhDsp < McuParam.PF_FRefRmpDo23)
		McuData.XX_FRefRmpDo = McuParam.PX_FRefRmpDo2;
	else
		McuData.XX_FRefRmpDo = McuParam.PX_FRefRmpDo3;
}

/*16ms*/
void FrefUDcLk(void) {
	LowPass(&McuData.XU_DcLkFlt2, DspData.XU_DcLkFlt,
			16.0 / McuParam.PT_FRefUDcLk);
	float32 v01;
	v01 = FKG4(McuData.XU_DcLkFlt2, 0.0, McuParam.PF_3PhMin,
			McuParam.PU_DcLkFRefMin, McuParam.PF_3PhMin,
			McuParam.PU_DcLkFRefLow, McuParam.PF_3PhNom, 10000.0,
			McuParam.PF_3PhNom);
	RAMP2(&McuData.WF_3PhUDcLk, v01, McuParam.PX_FRefRmpUDcLkUp * 0.016,
			McuParam.PX_FRefRmpUDcLkDo * 0.016, 0.0, FALSE, FALSE);
}

/*
 * MCU中16ms任务
 * */
void FrefRmp(void) {
	static float32 temp = 0.0;
	if (McuData.C_FRmp) {
		RAMP2(&temp, McuParam.PF_3PhNom, McuData.XX_FRefRmpUp * 0.016,
				-McuData.XX_FRefRmpDo * 0.016, 0.0, FALSE, FALSE);
		if (temp == McuParam.PF_3PhNom)
			McuData.A_FNom = TRUE;
		else
			McuData.A_FNom = FALSE;
	} else {
		RAMP2(&temp, McuParam.PF_3PhMin, McuData.XX_FRefRmpUp * 0.016,
				-McuData.XX_FRefRmpDo * 0.016, 0.0, FALSE, FALSE);
		if (temp == McuParam.PF_3PhMin)
			McuData.A_FMin = TRUE;
		else
			McuData.A_FMin = FALSE;
	}

//	McuData.WF_3PhRmp = Min(temp, McuData.WF_3PhUDcLk);
	McuData.WF_3PhRmp = temp;
}

/*
 * 16ms
 * */
void F3PhSz(void) {
	if (McuData.C_AuSz) {
		PI_F3PhSz.Ref = 0.0;

//		float32 temp = sqrt(
//				DspData.XU_3PhRe * DspData.XU_3PhRe
//						+ DspData.XU_3PhIm * DspData.XU_3PhIm);
//		if (temp < 0.001) {
//			PI_F3PhSz.Fbk = -DspData.XU_3PhIm / 0.001;
//		} else {
//			PI_F3PhSz.Fbk = -DspData.XU_3PhIm / temp;
//		}
		float32 temp;
		temp = atan2(DspData.XU_3PhIm, Max(DspData.XU_3PhRe, 1.0));
		PI_F3PhSz.Fbk = Limit(temp, -PI / 2.0, PI / 2.0);
		PI_F3PhSz.Kp = McuParam.PX_KpF3PhSzCl;
		PI_F3PhSz.Ki = 16.0 / McuParam.PT_F3PhSzCl;
//		PI_F3PhSz.Kp = PI2 * 1.0;
//		PI_F3PhSz.Ki = 0.016 * PI_F3PhSz.Kp * PI_F3PhSz.Kp / 4.0;
		PI_F3PhSz.Umax = McuParam.PF_UF3PhSzClMaxMin;
		PI_F3PhSz.Umin = -McuParam.PF_UF3PhSzClMaxMin;
		PI_CONTROLLER(&PI_F3PhSz);
		McuData.WF_UF3PhSzErr = PI_F3PhSz.Fbk;
		McuData.WF_UF3PhSz = PI_F3PhSz.Out;
	} else {
		McuData.WF_UF3PhSz = 0.0;
	}
}

/*
 * 16ms
 * */
void U3PhSz(void) {
	if (McuData.C_AuSz) {
		McuData.WU_UF3PhSzErr = DspData.XU_3PhAbs / SQRT3
				* McuParam.PX_TrfRtPr3Ph + McuParam.PU_UF3PhSzClAdd
				- McuData.WU_3PhDsp;

		INTEGR(&McuData.WU_UF3PhSz, McuData.WU_UF3PhSzErr, 16.0 / 200.0, 0.0,
				McuParam.PU_UF3PhSzClMaxMin, -McuParam.PU_UF3PhSzClMaxMin,
				FALSE, FALSE);

	} else {
//		RAMP(&McuData.WU_UF3PhSz,0.0);
		McuData.WU_UF3PhSz = 0.0;
	}
}

/*
 * 16ms
 * */
void UF3PhSz(void) {

	static float32 WndTime1, WndTime2;

	if (McuData.C_AuSz) {
		if ((fabs(McuData.WF_UF3PhSzErr) <= McuParam.PF_UF3PhSzRdy)
				&& (fabs(McuData.WU_UF3PhSzErr) <= McuParam.PU_UF3PhSzRdy))
			WndTime1 += 16.0;
		else
			WndTime1 = 0.0;

		if (WndTime1 > McuParam.PT_UF3PhSzRdy)
			McuData.A_AuSz = TRUE;
	} else {

	}
}

/**/
void LowPass(volatile float32 *Flt, float32 Src, float32 TsPerT1) {
	*Flt = (*Flt + Src * TsPerT1) / (1.0 + TsPerT1);
}

void CplxLowPass(volatile cfloat32 *Flt, cfloat32 Src, float32 TsPerT1) {
	Flt->re = (Flt->re + Src.re * TsPerT1) / (1.0 + TsPerT1);
	Flt->im = (Flt->im + Src.im * TsPerT1) / (1.0 + TsPerT1);
}

void RmsClc(volatile float32 *rms, float32 Src, Uint16 N,
		volatile float32 *Square, volatile Uint16 *cnt) {
	*Square += Src * Src / N;
	*cnt += 1;
	if (*cnt >= N) {
		*rms = sqrt(*Square);
		*Square = 0;
		*cnt = 0;
	}
}

float32 FKG4(float32 X, float32 X1, float32 Y1, float32 X2, float32 Y2,
		float32 X3, float32 Y3, float32 X4, float32 Y4) {
	float32 Y;
	if (X < X1)
		Y = Y1;
	else if (X < X2)
		Y = Y1 + (Y2 - Y1) * (X - X1) / Max((X2 - X1), 0.00001);
	else if (X < X3)
		Y = Y2 + (Y3 - Y2) * (X - X2) / Max((X3 - X2), 0.00001);
	else if (X < X4)
		Y = Y3 + (Y4 - Y3) * (X - X3) / Max((X4 - X3), 0.00001);
	else
		Y = Y4;

	return Y;
}

void RAMP2(volatile float32 *Y, float32 X, float32 Dr, float32 Df, float32 Init,
		Uint16 Set, Uint16 Hold) {
	float32 Yinc, Ydec;
	if (!Hold) {
		if (Set) {
			*Y = Init;
		} else {
			Yinc = *Y + fabs(Dr);
			Ydec = *Y - fabs(Df);

			if (X > Yinc) {
				*Y = Yinc;
			} else if (X < Ydec) {
				*Y = Ydec;
			} else {
				*Y = X;
			}
		}
	}
}

void RAMP(volatile float32 *Y, float32 X, float32 TsPerTr, float32 TsPerTf,
		float32 Init, Uint16 Set, Uint16 Hold, float32 Max) {
	float32 Yinc, Ydec;
	if (!Hold) {
		if (Set) {
			*Y = Init;
		} else {
			Yinc = *Y + fabs(Max) * Min(TsPerTr, 1.0);
			Ydec = *Y - fabs(Max) * Min(TsPerTr, 1.0);

			if (X > Yinc) {
				*Y = Yinc;
			} else if (X < Ydec) {
				*Y = Ydec;
			} else {
				*Y = X;
			}
		}
	}

}

void INTEGR(volatile float32 *Y, float32 X, float32 TsPerT1, float32 Init,
		float32 Max, float32 Min, Uint16 Set, Uint16 Hold) {
	if (!Hold) {
		if (Set) {
			*Y = Init;
		} else {
			*Y = *Y + X * TsPerT1;
			*Y = Limit(*Y, Min, Max);
		}
	}
}

/*
 * SR Flip Flop with reset dominant
 * */
Uint16 SR1(volatile Uint16* Q, Uint16 Set, Uint16 Reset) {
	if (Reset) {
		*Q = FALSE;
	} else {
		if (Set)
			*Q = TRUE;
	}
}

/*
 * SR Flip Flop with set dominant
 * */
Uint16 SR2(volatile Uint16* Q, Uint16 Set, Uint16 Reset) {
	if (Set) {
		*Q = TRUE;
	} else {
		if (Reset)
			*Q = FALSE;
	}
}

/*
 * IF ( ACTNB AND FB ) THEN
 IF TON_PREV_IN THEN
 TON_ET := TON_ET + CT ;
 END_IF ;
 TON_ET := MIN( TON_ET, TONTimer ) ;
 TON_Q := TON_ET = TONTimer ;
 ELSE
 TON_ET := TIME#0s ;
 TON_Q := FALSE ;
 END_IF ;
 TON_PREV_IN := ACTNB AND FB ;
 * */
Uint16 DLYON(Uint16 In, Uint16 N, volatile Uint16 *Cnt,
		volatile Uint16 *Prev_In) {
	if (In) {
		if (*Prev_In) {
			*Cnt++;
		}
		*Cnt = Min(*Cnt, N);
		return (*Cnt == N);
	} else {
		*Cnt = 0;
		return FALSE;
	}
	*Prev_In = In;
}

Uint16 MONO(Uint16 In, Uint16 N, TYPE_LOGICAL* data) {
	data->PreLogic = data->Logic;
	data->Logic = In;
	if (data->PreLogic ^ data->Logic) {
		if (data->Logic)
			data->RTrig = TRUE;
		else
			data->FTrig = TRUE;
	} else {
		data->RTrig = FALSE;
		data->FTrig = FALSE;
	}

}

float32 Min(float32 a, float32 b) {
	if (a <= b)
		return a;
	else
		return b;
}

float32 Max(float32 a, float32 b) {
	if (a <= b)
		return b;
	else
		return a;
}

float32 Limit(float32 x, float32 low, float32 up) {
	return Max(low, Min(x, up));
}

void CPLX2FRAC(volatile float32 *Re, volatile float32 *Im, cfloat32 Z) {
	*Re = Z.re;
	*Im = Z.im;
}

cfloat32 FRAC2CPLX(float32 Re, float32 Im) {
	cfloat32 Z;
	Z.re = Re;
	Z.im = Im;
	return Z;
}

cfloat32 CPLXCONJ(cfloat32 Z) {
	cfloat32 Z_conj;
	Z_conj.re = Z.re;
	Z_conj.im = -Z.im;
	return Z_conj;
}

cfloat32 CPLXMULT(cfloat32 Z1, cfloat32 Z2) {
	cfloat32 Z;
	Z.re = Z1.re * Z2.re - Z1.im * Z2.im;
	Z.im = Z1.re * Z2.im + Z1.im * Z2.re;
	return Z;
}

cfloat32 CPLXMULT_SHFT(cfloat32 Z1, cfloat32 Z2, int32 m) {
	cfloat32 Z = { 0, 0 };
	return Z;
}

float32 CPLXNORM(cfloat32 Z) {
	return Z.re * Z.re + Z.im * Z.im;
}

cfloat32 CPLXSCA(cfloat32 Z1, float32 a) {
	cfloat32 Z;
	Z.re = Z1.re * a;
	Z.im = Z1.im * a;
	return Z;
}

cfloat32 CPLXSCA_SHFT(cfloat32 Z1, float32 a, int32 m) {
	cfloat32 Z = { 0, 0 };
	return Z;
}

cfloat32 CPLXSHFT(cfloat32 Z1, int32 m) {
	cfloat32 Z = { 0, 0 };
	return Z;
}

cfloat32 CPLXSUB(cfloat32 Z1, cfloat32 Z2) {
	cfloat32 Z;
	Z.re = Z1.re - Z2.re;
	Z.im = Z1.im - Z2.im;
	return Z;
}

cfloat32 CPLXADD(cfloat32 Z1, cfloat32 Z2) {
	cfloat32 Z;
	Z.re = Z1.re + Z2.re;
	Z.im = Z1.im + Z2.im;
	return Z;
}

cfloat32 _PREVCPLX(cfloat32 Z) {

	return Z;
}

cfloat32 CPLXDIVSCA(cfloat32 Z1, float32 F, int32 m) {
	cfloat32 Z = { 0, 0 };
	return Z;
}

cfloat32 CPLXDIV(cfloat32 Z1, cfloat32 Z2) {
	cfloat32 Z;
	Z.re = (Z1.re * Z2.re + Z1.im * Z2.im) / (Z2.re * Z2.re + Z2.im * Z2.im);
	Z.im = (-Z1.re * Z2.im + Z1.im * Z2.re) / (Z2.re * Z2.re + Z2.im * Z2.im);
	return Z;
}

void CPLX2POL(volatile float32 *r, volatile float32 *fi, cfloat32 Z) {
	*r = sqrt(Z.re * Z.re + Z.im * Z.im);
	*fi = fmod(atan2(Z.im, Z.re), PI2);
}

cfloat32 PH3TOCPLX(float32 a, float32 b, float32 c) {
	cfloat32 Z;
	Z.re = (a - 0.5 * (b + c)) * 2.0 / 3.0;
	Z.im = (b - c) * ONEbySQRT3;
	return Z;
}

void CPLXTO3PH(volatile float32 *a, volatile float32 *b, volatile float32 *c,
		cfloat32 Z) {
	*a = Z.re;
	*b = -Z.re * 0.5 + Z.im * SQRT3byTWO;
	*c = -Z.re * 0.5 - Z.im * SQRT3byTWO;
}

cfloat32 POL2CPLX(float32 r, float32 fi) {
	cfloat32 Z;
	Z.re = r * cos(fi);
	Z.im = r * sin(fi);
	return Z;
}

/**/
void SOGIOSGFLL(TYPE_SOGIOSGMA *data) {

//	data->Ts = 1.0/2700.0;
//	data->w0 = 100*3.1415926;
//	data->K = sqrt(2);
//	data->Ki = 10000;

	/**/
	data->a = data->Ts * data->w / 2.0 + 2.0 / data->Ts / data->w;
	data->b = data->Ts * data->w / 2.0 - 2.0 / data->Ts / data->w;

	data->alpha = data->K / (data->a + data->K)\

			* (data->phase - data->oldPhase2)\

			- 2.0 * data->b / (data->a + data->K) * data->oldAlpha1\

			- (data->a - data->K) / (data->a + data->K) * data->oldAlpha2;
	data->beta = data->K / (data->a + data->K) * (data->a + data->b) / 2.0\

			* (data->phase + 2.0 * data->oldPhase1 + data->oldPhase2)\

			- 2.0 * data->b / (data->a + data->K) * data->oldBeta1\

			- (data->a - data->K) / (data->a + data->K) * data->oldBeta2;

	data->peak = sqrt(data->alpha * data->alpha + data->beta * data->beta);
	if (data->peak <= 0.001)
		data->peak = 0.001;
	/**/
	data->ErrF = (data->phase - data->alpha) * data->beta
			/ (data->peak * data->peak);
	data->ComW += data->ErrF * (-1.0) * data->Ki * data->Ts;
	if (data->ComW > 30.0)
		data->ComW = 30.0;
	if (data->ComW < -30.0)
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

/**/
void PI_CONTROLLER(TYPE_PI_CONTROLLER *data) {
	/* proportional term */
	data->up = data->Kp * (data->Ref - data->Fbk);

	/* integral term */
	data->ui =
			(data->Out == data->v1) ?
					(data->Ki * (data->Ref - data->Fbk) + data->i1) : data->i1;
	data->i1 = data->ui;

	/* control output */
	data->v1 = data->up + data->ui;
	data->Out = (data->v1 > data->Umax) ? data->Umax : data->v1;
	data->Out = (data->Out < data->Umin) ? data->Umin : data->Out;
}

/**/
void IIRFilter_2nd(TYPE_IIRFILTER_2ND *data) {
	data->Out = data->b0 * data->In + data->b1 * data->oldIn1
			+ data->b2 * data->oldIn2 - data->a1 * data->oldOut1
			- data->a2 * data->oldOut2;
	/***********************************/
	data->oldIn2 = data->oldIn1;
	data->oldIn1 = data->In;
	data->oldOut2 = data->oldOut1;
	data->oldOut1 = data->Out;
}

/***************************
 *
 *
 *
 *
 ****************************/
void AdaptIIRNotchFilter(TYPE_IIRFILTER_2ND *data, float32 W0, float32 Ts) {
	data->b0 = 1.0;
	data->b1 = -2.0 * cos(W0 * Ts);
	data->b2 = 1.0;
	data->a1 = (1 - W0 * Ts / 4) * data->b1;
	data->a2 = pow((1 - W0 * Ts / 4), 2.0);
	if (data->b1 == -2.0) {
		data->In *= 1.0;
	} else {
		data->In *= (1.0 + data->a1 + data->a2) / (2.0 + data->b1);
	}
	IIRFilter_2nd(data);
}

