#include "math.h"
#include "acm_dsp.h"

#define SIMULATION 0
#define U3PHRMS 300.0

volatile float32 Tsc = 1.0 / 2700.0;
volatile struct Dsp_Data DspData;
volatile struct Dsp_Param DspParam;
volatile struct Mcu_Data McuData;
volatile struct Mcu_Param McuParam;
TYPE_SOGIOSGMA sogiosg = SOGIOSGMA_DEFAULTS;
TYPE_PI_CONTROLLER PI_F3PhSz = PI_CONTROLLER_DEFAULTS;
TYPE_PI_CONTROLLER PI_U3PhCl = PI_CONTROLLER_DEFAULTS;

void DspInit(void) {
	DspParam.PN_IPhFixMcu_Flt = 4.0; //rad/s
	DspParam.PN_U3PhRms_Flt = 5.0; //5
	DspParam.PN_UDcLk_Flt = 100.0;
	DspParam.PN_URef_Flt = 600.0;
	DspParam.PN_IPhActRct_Flt = 2000;
	DspParam.PN_IPhActRctMcu_Flt = 20;
	DspParam.PN_IPhAbs_Flt = 60;
	DspParam.PN_PQ3PhMcu_Flt = 60;
	DspParam.PN_IPhDQ_Flt = 18;
	DspParam.PN_IPhRms_Flt = 30.0;
	DspParam.PN_URefIPhClTrs_Flt = 20.0;

	DspParam.PU_PhClTrsMax = 75.0; //	75
	DspParam.PI_PhClTrsAbsLim = 600.0; //	600

	DspParam.PD_TrfThetaPr3Ph = PI / 3.0;
	DspParam.PZ_3PhFiNdRe = 0.078; //	0,078 滤波电感电阻
	DspParam.PZ_3PhFiNdIm = 0.207; //	0,207滤波电感电抗
	DspParam.PZ_3PhFiCaIm = -5.47; //	-5,47 滤波电容电抗折算到一次侧
	DspParam.PZ_3PhTfRe = 0.0; //	0
	DspParam.PZ_3PhTfIm = 0.0; //	0
	DspParam.PZ_3PhFiNd = FRAC2CPLX(DspParam.PZ_3PhFiNdRe,
			DspParam.PZ_3PhFiNdIm);
	DspParam.PZ_3PhFiCa = FRAC2CPLX(0.0, DspParam.PZ_3PhFiCaIm);
	DspParam.PZ_3PhTf = FRAC2CPLX(DspParam.PZ_3PhTfRe, DspParam.PZ_3PhTfIm);

	DspParam.L_UDcLkStbEn = TRUE; //	TRUE
	DspParam.PN_UDcLkStbSliSmt = 2200.0; //	2200
	DspParam.PN_UDcLkStbHevSmt = 13.5; //	13,5
	DspParam.PU_DcLkStbMaxMin = 100.0; //	100
	DspParam.PX_KpUDcLkStb = 150.0; //需调试
	DspParam.PX_KpUDcLkVoStbFb = 0.00002;

	DspParam.PX_3PhClRtHgh = 0.94;
	DspParam.PX_3PhClRtLow = 0.06;

	DspParam.PF_IRQBMax = 150000000.0 / 8.0;
	DspParam.PF_3PhSg = 1350.0;

	DspParam.L_EnIPhClRms = FALSE;

	if (SIMULATION) {

	} else {
		Uint16 i;
		for (i = 0; i < sizeof(DspData); i++) {

			*((Uint16*) &DspData + i) = 0;
		}

	}

	DspData.XX_PwmPdVv = floor(1.0 / 1350.0 / 2.0 * DspParam.PF_IRQBMax);
	DspData.XT_Tsc = DspData.XX_PwmPdVv / DspParam.PF_IRQBMax; //开关频率1350Hz，波峰波谷双采样
	DspData.XX_DutyA = 0.5;
	DspData.XX_DutyB = 0.5;
	DspData.XX_DutyC = 0.5;
	DspData.XX_Mode = 0;

	DspData.XU_3PhSqu = 0.0;

	DspData.XI_Ph1Rms = 0.0;
	DspData.XI_Ph2Rms = 0.0;
	DspData.XI_Ph3Rms = 0.0;
	DspData.XI_Ph1Squ = 0.0;
	DspData.XI_Ph2Squ = 0.0;
	DspData.XI_Ph3Squ = 0.0;
	DspData.XX_CntPh1Rms = 0;
	DspData.XX_CntPh2Rms = 0;
	DspData.XX_CntPh3Rms = 0;

	Tsc = 1.0 / 2700.0;
}

void DspStep(void) {
	SIPR_B();
	ACCL_B();
	ACCL_T2();
	UFCO_B();
	PPG3_B();
}

void SIPR_B(void) {
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

	/**/
	DspData.XI_PhDQ = CPLXMULT(DspData.XI_PhAB,
			POL2CPLX(1.0, -DspData.WX_Theta));
	/**/
	DspData.XI_PhAct = DspData.XI_PhDQ.re;
	DspData.XI_PhRct = DspData.XI_PhDQ.im;

	DspData.WX_Theta += 2.0 * PI * McuData.WF_3PhDsp * DspData.XT_Tsc;
	DspData.WX_Theta = fmod(DspData.WX_Theta, 2 * PI);

	/**/
	sogiosg.phase = DspData.XU_PhABLk;
	sogiosg.Ts = DspData.XT_Tsc;
	sogiosg.w0 = 100 * 3.1415926;
	sogiosg.K = sqrt(0.1); //sqrt(2)
	sogiosg.Ki = 10000;

	SOGIOSGFLL(&sogiosg);

	DspData.XT_U3Ph = 2.0 * PI / sogiosg.w;

	cfloat32 XU_3PhAB;
	/**/
	if (SIMULATION) {
		//仿真
		XU_3PhAB = CPLXSCA(
				CPLXMULT(FRAC2CPLX(sogiosg.alpha, sogiosg.beta),
						POL2CPLX(1.0, 0.0)), 1.0);

	} else {
		//调试
		XU_3PhAB = CPLXSCA(
				CPLXMULT(FRAC2CPLX(sogiosg.alpha, sogiosg.beta),
						POL2CPLX(1.0, PI / 2.0)), 1.1);
	}

	/**/
	DspData.XU_3PhRe = XU_3PhAB.re;
	DspData.XU_3PhIm = XU_3PhAB.im;
	DspData.XU_3PhAbs = sqrt(CPLXNORM(XU_3PhAB));

	LowPass(&DspData.XU_3PhSqu, DspData.XU_PhABLk * DspData.XU_PhABLk,
			DspData.XT_Tsc * DspParam.PN_U3PhRms_Flt);
	DspData.XU_3PhRms = sqrt(DspData.XU_3PhSqu);
//	DspData.XU_3PhRms = DspData.XU_3PhAbs / SQRT2;

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

void ACCL_T2(void) {
	RmsClc(&DspData.XI_Ph1Rms, DspData.XI_PhA, 50, &DspData.XI_Ph1Squ,
			&DspData.XX_CntPh1Rms);
	RmsClc(&DspData.XI_Ph2Rms, DspData.XI_PhB, 50, &DspData.XI_Ph2Squ,
			&DspData.XX_CntPh2Rms);
	RmsClc(&DspData.XI_Ph3Rms, DspData.XI_PhC, 50, &DspData.XI_Ph3Squ,
			&DspData.XX_CntPh3Rms);

	LowPass(&DspData.XI_Ph1Rms_Flt, DspData.XI_Ph1Rms,
			Cycle() * DspParam.PN_IPhRms_Flt);
	LowPass(&DspData.XI_Ph2Rms_Flt, DspData.XI_Ph2Rms,
			Cycle() * DspParam.PN_IPhRms_Flt);
	LowPass(&DspData.XI_Ph3Rms_Flt, DspData.XI_Ph3Rms,
			Cycle() * DspParam.PN_IPhRms_Flt);

	DspData.WU_IPhClRms = 0.0;
	DspData.B_LimAct = 0;

	if (DspParam.L_EnIPhClRms) //功能未开启
	{

	}
}

void UFCO_B(void) {

	DspData.WU_3PhSec = POL2CPLX(McuData.WU_3PhDsp, 0.0); //静止坐标系按1次侧，同步频率按WF_3PhDsp  DQ

	cfloat32 Z1, Z2;
	Z1 = CPLXDIV(DspParam.PZ_3PhFiCa,
			CPLXADD(DspParam.PZ_3PhFiCa, DspParam.PZ_3PhTf));
	Z2 = CPLXADD(DspParam.PZ_3PhFiNd, CPLXMULT(DspParam.PZ_3PhTf, Z1));

	/**/
	DspData.WU_3PhPm = CPLXADD(CPLXMULT(DspData.WU_3PhSec, Z1),
			CPLXMULT(DspData.XI_PhDQ_Flt, Z2));
	//B_EnBuiTs
//	DspData.WU_3PhPm = DspData.WU_3PhSec;	//DQ
	/**/
	DspData.WU_3PhPmAB = CPLXMULT(DspData.WU_3PhPm,
			POL2CPLX(1.0, DspData.WX_Theta)); //ipark
	CPLX2POL(&DspData.WU_Ref_Abs, &DspData.WX_ThetaCv, DspData.WU_3PhPmAB);

	/*
	 * 直流母线电压振荡抑制
	 *
	 *
	 *
	 *
	 * */
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

	DspData.XX_MRef = DspData.WU_Ref_Abs / DspData.XU_DcLk;
	if (DspData.C_CvOp && (DspData.XX_MRef > ONEbySQRT3)) {
		DspData.S_3PhOvMd = 1;
	} else {
		DspData.S_3PhOvMd = 0;
	}

	DspData.WU_OvMd = DspData.XU_DcLk * Min(0.6057 - DspData.XX_MRef, 0); //<0
	DspData.WU_3PhAbsOvMd = DspData.XU_DcLk * OvMd(DspData.XX_MRef);

	DspData.WU_IPhClRmsRed = 0.0;
	DspData.WU_3PhAbs = DspData.WU_3PhAbsOvMd + DspData.WU_IPhClRmsRed;
	DspData.WU_3PhAB = POL2CPLX(DspData.WU_3PhAbs, DspData.WX_ThetaCv);

	SVPWM(&DspData.XX_CrU, &DspData.XX_CrV, &DspData.XX_CrW,
			CPLXSCA(DspData.WU_3PhAB, 1.0 / DspData.XU_DcLk));

	if (Max(DspData.XX_CrU, Max(DspData.XX_CrV, DspData.XX_CrW))
			> DspParam.PX_3PhClRtHgh) {
		DspData.S_UDcLkLow = 1;
	} else {
		DspData.S_UDcLkLow = 0;
	}

}

void PPG3_B(void) {
	DspData.XX_PwmPdVv = floor(0.5 * DspParam.PF_IRQBMax / DspParam.PF_3PhSg);
	DspData.XT_Tsc = DspData.XX_PwmPdVv / DspParam.PF_IRQBMax; //开关频率1350Hz，波峰波谷双采样
	DspData.XX_DutyA = Limit(DspData.XX_CrU, DspParam.PX_3PhClRtLow,
			DspParam.PX_3PhClRtHgh);
	DspData.XX_DutyB = Limit(DspData.XX_CrV, DspParam.PX_3PhClRtLow,
			DspParam.PX_3PhClRtHgh);
	DspData.XX_DutyC = Limit(DspData.XX_CrW, DspParam.PX_3PhClRtLow,
			DspParam.PX_3PhClRtHgh);
	DspData.XX_Mode = !DspData.XX_Mode;
}

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

/**/
void McuInit(void) {

	if (SIMULATION) {

	} else {
		Uint16 i;
		for (i = 0; i < sizeof(McuData); i++) {

			*((Uint16*) &McuData + i) = 0;
		}
	}

	McuData.WF_3PhRmp = 0.0;
	McuData.WF_3PhDsp = 0.0;
	McuData.WU_3PhRmp = 0.0;
	McuData.WU_3PhDsp = 0.0;

	/*TFrefRmp*/
	McuData.PX_FRefRmpUp = 25.0;
	McuData.PX_FRefRmpUpSlaveAcm = 100.0;
	McuData.PX_FRefRmpDo1 = 40.0;
	McuData.PX_FRefRmpDo2 = 40.0;
	McuData.PX_FRefRmpDo3 = 40.0;
	McuData.PF_FRefRmpDo12 = 4.0;
	McuData.PF_FRefRmpDo23 = 30.0;

	/*FrefRmp*/
	McuData.PF_3PhNom = 50.0;
	McuData.PF_3PhMin = 3.0;

	/*UF3PhCmp 4ms*/
	McuData.L_EnUF3PhCmp = FALSE;	//TRUE
	McuData.PI_UF3PhCmpActHiLo = 4000.0;
	McuData.PF_UF3PhCmpActHiLo = -10.0;
	McuData.PI_UF3PhCmpRctHiLo = 4000.0;
	McuData.PU_UF3PhCmpRctHiLo = -100.0;

	/*F3PhSz 16ms*/
	McuData.C_AuSz = FALSE;	//
	McuData.PX_KpF3PhSzCl = 0.5;
	McuData.PT_F3PhSzCl = 800.0; //ms
	McuData.PF_UF3PhSzClMaxMin = 50.0;
	McuData.PF_UF3PhSzRdy = 0.3;
	McuData.PT_UF3PhSzRmp = 1000.0; //ms

	/*U3PhSz 16ms*/
	McuData.PU_UF3PhSzClAdd = 0.0;
	McuData.PU_UF3PhSzClMaxMin = 100.0;
	McuData.PU_UF3PhSzRdy = 20.0;

	McuData.PU_3PhBusAct = 370.0;
	McuData.PU_3PhBusIdle = 50.0;

	/*U3PhRef*/
	McuData.PF_U3PhRef2 = 6.0;
	McuData.PF_U3PhRef3 = 50.0;
	McuData.PU_U3PhRef1 = 0.0; //0Hz
	McuData.PU_U3PhRef2 = 0.0;  //6Hz
	McuData.PU_U3PhRef3 = U3PHRMS;  //50Hz
	McuData.PU_U3PhRef4 = U3PHRMS; //100Hz
	McuData.L_ExtU3PhRef = FALSE;
	McuData.PX_ExtU3PhRefRmp = 200.0;
	McuData.L_EnRmpU3PhRef = FALSE;
	McuData.PX_U3PhRefRmp1 = 200.0;
	McuData.PX_U3PhRefRmp2 = 50.0;
	McuData.PX_U3PhRefRmpSel = 0.9;

	/*U3PhCl 4ms*/
	McuData.B_EnU3PhCl = FALSE; //
	McuData.L_En3PhCl = TRUE; //TRUE
	McuData.L_EnU3PhOpLoCl = FALSE;
	McuData.PX_KpU3PhCl = 0.8;
	McuData.PT_U3PhCl = 50.0; //ms
	McuData.PU_3PhClMax = 75.0;
	McuData.PU_3PhClMin = -50.0;
	McuData.PU_3PhClRefMax = 395.0;
	McuData.PU_3PhClRefMin = 0.0;
	McuData.PX_TrfRtPr3Ph = 1.684;

	McuParam.PX_IPhClTrsKpAct = 0.005;
	McuParam.PX_IPhClTrsKpRct = 0.03;
	McuParam.PX_IPhClTrsKpAbs = 0.0;

	PI_U3PhCl.i1 = 0.0;
	PI_U3PhCl.ui = 0.0;
	PI_U3PhCl.Out = 0.0;
}

void McuStep(void) {
	/**/
	TFrefRmp();
	FrefUDcLk();
	FrefRmp();
	UF3PhCmp();
	F3PhSz();
	U3PhSz();
	IPhClGenOvLd();
	IPhClPsTrs();
	F3PhRef();
	U3PhRef();
	U3PhCl();
}

/**/
void TFrefRmp(void) {
	McuData.XX_FRefRmpUp = 25.0;
	McuData.XX_FRefRmpDo = 25.0;
}

void FrefUDcLk(void) {
	McuData.WF_3PhUDcLk = McuData.PF_3PhNom;
}

void FrefRmp(void) {
	if (DspData.C_CvOp) {
		if (McuData.WF_3PhRmp <= McuData.PF_3PhNom) {
			McuData.WF_3PhRmp += McuData.XX_FRefRmpUp * Cycle();
			if (McuData.WF_3PhRmp > McuData.PF_3PhNom)
				McuData.WF_3PhRmp = McuData.PF_3PhNom;
		} else {
			McuData.WF_3PhRmp -= McuData.XX_FRefRmpDo * Cycle();
			if (McuData.WF_3PhRmp < McuData.PF_3PhNom)
				McuData.WF_3PhRmp = McuData.PF_3PhNom;
		}
		if (McuData.WF_3PhRmp == McuData.PF_3PhNom)
			McuData.A_FRmp = TRUE;
		else
			McuData.A_FRmp = FALSE;
	} else {
		if (McuData.WF_3PhRmp <= McuData.PF_3PhMin) {
			McuData.WF_3PhRmp += McuData.XX_FRefRmpUp * Cycle();
			if (McuData.WF_3PhRmp > McuData.PF_3PhMin)
				McuData.WF_3PhRmp = McuData.PF_3PhMin;
		} else {
			McuData.WF_3PhRmp -= McuData.XX_FRefRmpDo * Cycle();
			if (McuData.WF_3PhRmp < McuData.PF_3PhMin)
				McuData.WF_3PhRmp = McuData.PF_3PhMin;
		}
		if (McuData.WF_3PhRmp == McuData.PF_3PhMin)
			McuData.A_FRmp = TRUE;
		else
			McuData.A_FRmp = FALSE;
	}

	McuData.WF_3PhRmp = Min(McuData.WF_3PhRmp, McuData.WF_3PhUDcLk);
}

void UF3PhCmp(void) {
	if (DspData.C_CvOp && McuData.L_EnUF3PhCmp) {
		McuData.WF_WF3PhCmp = McuData.PF_UF3PhCmpActHiLo
				/ McuData.PI_UF3PhCmpActHiLo * DspData.XI_PhAct;
		McuData.WU_UF3PhCmp = McuData.PU_UF3PhCmpRctHiLo
				/ McuData.PI_UF3PhCmpRctHiLo * DspData.XI_PhRct;
	} else {
		McuData.WF_WF3PhCmp = 0.0;
		McuData.WU_UF3PhCmp = 0.0;
	}
}

void F3PhSz(void) {
	if (McuData.C_AuSz) {
		float32 temp = sqrt(
				DspData.XU_3PhRe * DspData.XU_3PhRe
						+ DspData.XU_3PhIm * DspData.XU_3PhIm);
		PI_F3PhSz.Ref = 0.0;
		if (temp < 0.001) {
			PI_F3PhSz.Fbk = -DspData.XU_3PhIm / 0.001;
		} else {
			PI_F3PhSz.Fbk = -DspData.XU_3PhIm / temp;
		}
		PI_F3PhSz.Kp = McuData.PX_KpF3PhSzCl;
		PI_F3PhSz.Ki = 1000.0 * Cycle() / McuData.PT_F3PhSzCl;
		PI_F3PhSz.Umax = McuData.PF_UF3PhSzClMaxMin;
		PI_F3PhSz.Umin = -McuData.PF_UF3PhSzClMaxMin;
		PI_CONTROLLER(&PI_F3PhSz);
		McuData.WF_UF3PhSz = PI_F3PhSz.Out;
	} else {
		McuData.WF_UF3PhSz = 0.0;
	}
}

void U3PhSz(void) {
	if (McuData.C_AuSz) {
		float32 temp = DspData.XU_3PhAbs / SQRT3 * McuData.PX_TrfRtPr3Ph
				- McuData.WU_3PhDsp;

		if (McuData.WU_UF3PhSz < temp) {
			McuData.WU_UF3PhSz += 1.0;
			if (McuData.WU_UF3PhSz > temp)
				McuData.WU_UF3PhSz = temp;
		}
		if (McuData.WU_UF3PhSz > temp) {
			McuData.WU_UF3PhSz -= 1.0;
			if (McuData.WU_UF3PhSz < temp)
				McuData.WU_UF3PhSz = temp;
		}
		McuData.WU_UF3PhSz += McuData.PU_UF3PhSzClAdd;
		McuData.WU_UF3PhSzErr = -temp;
	} else {
		McuData.WU_UF3PhSz = 0.0;
	}
}

void IPhClGenOvLd(void) {
	McuData.WF_IPhCl = 0.0;
}

void IPhClPsTrs(void) {
	McuData.WI_PhActDsp = 450;
	McuData.WI_PhRctDsp = 300;
}

void F3PhRef(void) {

	McuData.WF_3PhU3PhRef = McuData.WF_3PhRmp + McuData.WF_IPhCl
			+ McuData.WF_UF3PhSz;
	McuData.WF_3PhDsp = McuData.WF_3PhU3PhRef + McuData.WF_WF3PhCmp;

}

void U3PhRef(void) {
	if (!McuData.L_ExtU3PhRef) {
		if (McuData.WF_3PhU3PhRef <= 0.0)
			McuData.WU_3PhU3PhRef = McuData.PU_U3PhRef1;
		else if (McuData.WF_3PhU3PhRef <= McuData.PF_U3PhRef2)
			McuData.WU_3PhU3PhRef = McuData.PU_U3PhRef1
					+ (McuData.WF_3PhU3PhRef - 0.0)
							/ (McuData.PF_U3PhRef2 - 0.0)
							* (McuData.PU_U3PhRef2 - McuData.PU_U3PhRef1);
		else if (McuData.WF_3PhU3PhRef <= McuData.PF_U3PhRef3)
			McuData.WU_3PhU3PhRef = McuData.PU_U3PhRef2
					+ (McuData.WF_3PhU3PhRef - McuData.PF_U3PhRef2)
							/ (McuData.PF_U3PhRef3 - McuData.PF_U3PhRef2)
							* (McuData.PU_U3PhRef3 - McuData.PU_U3PhRef2);
		else if (McuData.WF_3PhU3PhRef <= 100.0)
			McuData.WU_3PhU3PhRef = McuData.PU_U3PhRef3
					+ (McuData.WF_3PhU3PhRef - McuData.PF_U3PhRef3)
							/ (100.0 - McuData.PF_U3PhRef3)
							* (McuData.PU_U3PhRef4 - McuData.PU_U3PhRef3);
		else
			McuData.WU_3PhU3PhRef = McuData.PU_U3PhRef4;
	}

	RAMP2(&McuData.WU_3PhRmp, McuData.WU_3PhU3PhRef, McuData.PX_U3PhRefRmp1,
			-McuData.PX_U3PhRefRmp1, 0.0, FALSE, FALSE);

	McuData.WU_3PhRmp = McuData.WU_3PhRmp;

	if (!McuData.L_EnRmpU3PhRef) {

	} else {

	}
}

void U3PhCl(void) {
	McuData.WU_3PhClIn = McuData.WU_3PhRmp * SQRT2 / SQRT3 + McuData.WU_UF3PhCmp
			+ McuData.WU_UF3PhSz;
	McuData.WU_3PhClIn = Limit(McuData.WU_3PhClIn, McuData.PU_3PhClRefMin,
			McuData.PU_3PhClRefMax);

	PI_U3PhCl.Ref = McuData.WU_3PhClIn
			+ (DspData.WU_IPhClTrs_Flt + DspData.WU_OvMd
					+ DspData.WU_IPhClRmsRed) / McuData.PX_TrfRtPr3Ph;
	PI_U3PhCl.Fbk = DspData.XU_3PhAbs / SQRT3;

	if (McuData.B_EnU3PhCl) {
		PI_U3PhCl.Kp = McuData.PX_KpU3PhCl;
//		PI_U3PhCl.Ki = 1000.0 * Cycle() / McuData.PT_U3PhCl;
		//	YI := YI + ((KP * ERROR) / LIMIT(1.0,TN_TZ,3.4E+38)) ;
		PI_U3PhCl.Ki = PI_U3PhCl.Kp / (McuData.PT_U3PhCl * 0.001 / Cycle()); //TN_TZ 控制周期的倍率，推荐大于10  PI_U3PhCl.Kp *Cycle()*1000/ McuData.PT_U3PhCl;
		PI_U3PhCl.Umax = McuData.PU_3PhClMax;
		PI_U3PhCl.Umin = McuData.PU_3PhClMin;
		PI_CONTROLLER(&PI_U3PhCl);
	} else {
		PI_U3PhCl.i1 = 0.0;
		PI_U3PhCl.v1 = 0.0;
		PI_U3PhCl.Out = 0.0;
	}

	McuData.WU_U3PhClOut = PI_U3PhCl.Out;
	McuData.WU_3PhDsp = McuData.WU_3PhClIn * McuData.PX_TrfRtPr3Ph
			+ McuData.WU_U3PhClOut;
}

/**/
void Delay(volatile float32 *Dy, float32 Src) {

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

void RAMP2(volatile float32 *Y, float32 X, float32 Dr, float32 Df, float32 Init,
		Uint16 Set, Uint16 Hold) {
	float32 Yinc, Ydec;
	if (!Hold) {
		if (Set) {
			*Y = Init;
		} else {
			Yinc = *Y + fabs(Dr) * Cycle();
			Ydec = *Y - fabs(Df) * Cycle();

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

void INTEGR(volatile float32 *Y, float32 X, float32 T, float32 Init,
		float32 Max, float32 Min, Uint16 Set, Uint16 Hold) {
	if (!Hold) {
		if (Set) {
			*Y = Init;
		} else {
			*Y = *Y + X * Cycle() / T;
			*Y = Limit(*Y, Min, Max);
		}
	}
}

float32 Cycle(void) {
	return Tsc;
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
