#include "math.h"
#include "acm_dsp.h"

volatile struct Dsp_Data DspData;
volatile struct Dsp_Param DspParam;
volatile struct Mcu_Data McuData;
//volatile struct Mcu_Param McuParam;
TYPE_SOGIOSGMA sogiosg = SOGIOSGMA_DEFAULTS;
TYPE_PI_CONTROLLER PI_F3PhSz = PI_CONTROLLER_DEFAULTS;
TYPE_PI_CONTROLLER PI_U3PhCl = PI_CONTROLLER_DEFAULTS;

void DspInit(void) {

	DspData.XT_Tsc = 1.0 / 1350.0 / 2.0;
	DspParam.PN_IPhFixMcu_Flt = 4.0; //rad/s
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
			DspData.XT_Tsc / 2.0 / DspParam.PN_IPhFixMcu_Flt);
	LowPass(&DspData.XI_PhImFix, DspData.XI_PhAB.im,
			DspData.XT_Tsc / 2.0 / DspParam.PN_IPhFixMcu_Flt);

	cfloat32 XS_3Ph;
	XS_3Ph = CPLXSCA(CPLXMULT(DspData.WU_3PhAB, CPLXCONJ(DspData.XI_PhAB)),
			1.5);
	DspData.XP_3Ph = XS_3Ph.re;
	DspData.XQ_3Ph = XS_3Ph.im;

	DspData.XI_PhDQ = CPLXMULT(DspData.WU_3PhAB,
			POL2CPLX(1.0, -DspData.WX_Theta));
	DspData.XI_PhAct = DspData.XI_PhDQ.re;
	DspData.XI_PhRct = -DspData.XI_PhDQ.im;

	DspData.WX_Theta += 2.0 * PI * DspData.WF_3Ph * DspData.XT_Tsc;
	DspData.WX_Theta = fmod(DspData.WX_Theta, 2 * PI);

	sogiosg.phase = DspData.XU_PhABLk;
	sogiosg.Ts = DspData.XT_Tsc;
	sogiosg.w0 = 100 * 3.1415926;
	sogiosg.K = sqrt(2);
	sogiosg.Ki = 10000;

	SOGIOSGFLL(&sogiosg);

	DspData.XT_U3Ph = 2.0 * PI / sogiosg.w;

	cfloat32 XU_3PhAB;
	XU_3PhAB = CPLXSCA(
			CPLXMULT(FRAC2CPLX(sogiosg.alpha, sogiosg.beta),
					POL2CPLX(1.0, PI / 2.0)), 1.04);
	DspData.XU_3PhRe = XU_3PhAB.re;
	DspData.XU_3PhIm = XU_3PhAB.im;
	DspData.XU_3PhAbs = sqrt(CPLXNORM(XU_3PhAB));
	DspData.XU_3PhRms = DspData.XU_3PhAbs / SQRT2;

}

void ACCL_B(void) {

}

void ACCL_T2(void) {

}

void UFCO_B(void) {
//	DspData.

//	SVPWM(&DspData.XX_CrU,&DspData.XX_CrV,&DspData.XX_CrW,);

}

void PPG3_B(void) {
	DspData.XX_DutyA = Limit(DspData.XX_CrU, 0.1, 0.9);
	DspData.XX_DutyB = Limit(DspData.XX_CrV, 0.1, 0.9);
	DspData.XX_DutyC = Limit(DspData.XX_CrW, 0.1, 0.9);
	DspData.XX_Mode = fabs(1 - DspData.XX_Mode);
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

void SVPWM(float32 *DutyA, float32 *DutyB, float32 *DutyC, cfloat32 _3PhAB) {
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
	McuData.WF_3PhRmp = 0.0;
	McuData.WF_3PhDsp = 0.0;
	McuData.WU_3PhUFRt = 0.0;
	McuData.WU_3PhDsp = 0.0;

	/*TFrefRmp*/
	McuData.PX_FRefRmpUp = 40.0;
	McuData.PX_FRefRmpUpSlaveAcm = 100.0;
	McuData.PX_FRefRmpDo1 = 40.0;
	McuData.PX_FRefRmpDo2 = 40.0;
	McuData.PX_FRefRmpDo3 = 40.0;
	McuData.PF_FRefRmpDo12 = 4.0;
	McuData.PF_FRefRmpDo23 = 30.0;

	/*FrefRmp*/
	McuData.PF_3PhNom = 50.3;
	McuData.PF_3PhMin = 3.0;

	/*UF3PhCmp 4ms*/
	McuData.L_EnUF3PhCmp = TRUE;
	McuData.PI_UF3PhCmpActHiLo = 4000.0;
	McuData.PF_UF3PhCmpActHiLo = -10.0;
	McuData.PI_UF3PhCmpRctHiLo = 4000.0;
	McuData.PU_UF3PhCmpRctHiLo = -100.0;

	/*F3PhSz 16ms*/
	McuData.PX_KpF3PhSzCl = 0.5;
	McuData.PT_F3PhSzCl = 800.0; //ms
	//	McuData.PX_KpF3PhSzCl = 2.0;
	//	McuData.PT_F3PhSzCl = 50.0;
	//	McuData.PX_KpF3PhSzCl = 2.0*100.0*3.1415926;
	//	McuData.PT_F3PhSzCl = 1000.0/(100.0*3.1415926*100.0*3.1415926);
	McuData.PF_UF3PhSzClMaxMin = 50.0;
	McuData.PF_UF3PhSzRdy = 0.3;
	McuData.PT_UF3PhSzRmp = 1000.0; //ms
	PI_F3PhSz.Kp = McuData.PX_KpF3PhSzCl;
	PI_F3PhSz.Ki = 1000.0 / McuData.PT_F3PhSzCl * McuData.PT_Tsc;
	PI_F3PhSz.Umax = McuData.PF_UF3PhSzClMaxMin / (16.0 * 2.9);
	PI_F3PhSz.Umin = -McuData.PF_UF3PhSzClMaxMin / (16.0 * 2.9);
	McuData.PD_TrfSfPr3Ph = PI / 3.0 - PI / 27.0;
	//	McuData.PD_TrfSfPr3Ph = 0.0;

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
	McuData.PU_U3PhRef3 = 100.0;  //50Hz
	McuData.PU_U3PhRef4 = 100.0; //100Hz
	McuData.L_ExtU3PhRef = FALSE;
	McuData.PX_ExtU3PhRefRmp = 200.0;
	McuData.L_EnRmpU3PhRef = FALSE;
	McuData.PX_U3PhRefRmp1 = 200.0;
	McuData.PX_U3PhRefRmp2 = 50.0;
	McuData.PX_U3PhRefRmpSel = 0.9;

	/*U3PhCl 4ms*/
	McuData.L_En3PhCl = TRUE;
	McuData.L_EnU3PhOpLoCl = FALSE;
	McuData.PX_KpU3PhCl = 0.8;
	McuData.PT_U3PhCl = 50.0; //ms
	McuData.PU_3PhClMax = 75.0;
	McuData.PU_3PhClMin = -50.0;
	McuData.PU_3PhClRefMax = 395.0;
	McuData.PU_3PhClRefMin = 0.0;
	McuData.PX_TrfRtPr3Ph = 1.684;
	PI_U3PhCl.Kp = McuData.PX_KpU3PhCl;
	PI_U3PhCl.Ki = 1000.0 / McuData.PT_U3PhCl * McuData.PT_Tsc;
	PI_U3PhCl.Umax = McuData.PU_3PhClMax;
	PI_U3PhCl.Umin = McuData.PU_3PhClMin;
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
	F3PhRef();
	U3PhRef();
	U3PhCl();
}

/**/
void TFrefRmp(void) {
	McuData.XX_FRefRmpUp = 40.0;
	McuData.XX_FRefRmpDo = 40.0;
}

void FrefUDcLk(void) {

}

void FrefRmp(void) {
	if (McuData.A_CvOp == 1) {
		if (McuData.WF_3PhRmp < McuData.PF_3PhMin)
			McuData.WF_3PhRmp = McuData.PF_3PhMin;
		if (McuData.WF_3PhRmp < McuData.PF_3PhNom) {
			McuData.WF_3PhRmp += McuData.XX_FRefRmpUp * McuData.PT_Tsc;
			if (McuData.WF_3PhRmp > McuData.PF_3PhNom)
				McuData.WF_3PhRmp = McuData.PF_3PhNom;
		}
		if (McuData.WF_3PhRmp > McuData.PF_3PhNom) {
			McuData.WF_3PhRmp -= McuData.XX_FRefRmpDo * McuData.PT_Tsc;
			if (McuData.WF_3PhRmp < McuData.PF_3PhNom)
				McuData.WF_3PhRmp = McuData.PF_3PhNom;
		}
		if (McuData.WF_3PhRmp == McuData.PF_3PhNom)
			McuData.A_FNom = TRUE;
		else
			McuData.A_FNom = FALSE;
	} else {
		if (McuData.WF_3PhRmp < McuData.PF_3PhMin)
			McuData.WF_3PhRmp = McuData.PF_3PhMin;
		if (McuData.WF_3PhRmp > McuData.PF_3PhMin) {
			McuData.WF_3PhRmp -= McuData.XX_FRefRmpDo * McuData.PT_Tsc;
			if (McuData.WF_3PhRmp < McuData.PF_3PhMin)
				McuData.WF_3PhRmp = McuData.PF_3PhMin;
		}
		if (McuData.WF_3PhRmp == McuData.PF_3PhMin)
			McuData.A_FNom = TRUE;
		else
			McuData.A_FNom = FALSE;
	}
}

void UF3PhCmp(void) {
	if (McuData.A_CvOp && McuData.L_EnUF3PhCmp) {
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
//		McuData.F3PhSz.Fbk = -McuData.XU_3PhIm;
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

}

void F3PhRef(void) {
	McuData.WF_3PhDsp = McuData.WF_3PhRmp + McuData.WF_WF3PhCmp
			+ McuData.WF_UF3PhSz + McuData.WF_IPhCl;
	McuData.WF_3PhU3PhRef = McuData.WF_3PhDsp;
}

void U3PhRef(void) {
	float32 temp;
	if (!McuData.L_ExtU3PhRef) {
		if (McuData.WF_3PhU3PhRef < 0.0)
			temp = McuData.PU_U3PhRef1;
		if (McuData.WF_3PhU3PhRef >= 0.0
				&& McuData.WF_3PhU3PhRef < McuData.PF_U3PhRef2)
			temp = McuData.PU_U3PhRef1
					+ (McuData.WF_3PhU3PhRef - 0.0)
							/ (McuData.PF_U3PhRef2 - 0.0)
							* (McuData.PU_U3PhRef2 - McuData.PU_U3PhRef1);
		if (McuData.WF_3PhU3PhRef >= McuData.PF_U3PhRef2
				&& McuData.WF_3PhU3PhRef < McuData.PF_U3PhRef3)
			temp = McuData.PU_U3PhRef2
					+ (McuData.WF_3PhU3PhRef - McuData.PF_U3PhRef2)
							/ (McuData.PF_U3PhRef3 - McuData.PF_U3PhRef2)
							* (McuData.PU_U3PhRef3 - McuData.PU_U3PhRef2);
		if (McuData.WF_3PhU3PhRef >= McuData.PF_U3PhRef3
				&& McuData.WF_3PhU3PhRef < 100.0)
			temp = McuData.PU_U3PhRef3
					+ (McuData.WF_3PhU3PhRef - McuData.PF_U3PhRef3)
							/ (100.0 - McuData.PF_U3PhRef3)
							* (McuData.PU_U3PhRef4 - McuData.PU_U3PhRef3);
		if (McuData.WF_3PhU3PhRef >= 100.0)
			temp = McuData.PU_U3PhRef4;
	}

	if (!McuData.L_EnRmpU3PhRef) {
		McuData.WU_3PhUFRt = temp / SQRT3 * SQRT2; //œ‡µÁ—π∑Â÷µ
	}
}

void U3PhCl(void) {
	McuData.WU_3PhClIn = McuData.WU_3PhUFRt * McuData.PX_TrfRtPr3Ph;

	PI_U3PhCl.Ref = McuData.WU_3PhClIn + McuData.WU_UF3PhCmp
			+ McuData.WU_UF3PhSz;

	if (PI_U3PhCl.Ref < McuData.PU_3PhClRefMin)
		PI_U3PhCl.Ref = McuData.PU_3PhClRefMin;
	if (PI_U3PhCl.Ref > McuData.PU_3PhClRefMax)
		PI_U3PhCl.Ref = McuData.PU_3PhClRefMax;

	PI_U3PhCl.Fbk = DspData.XU_3PhAbs / SQRT3 * McuData.PX_TrfRtPr3Ph;

	if (McuData.B_EnU3PhCl) {
		PI_CONTROLLER(&PI_U3PhCl);
	} else {
		PI_U3PhCl.i1 = 0.0;
		PI_U3PhCl.v1 = 0.0;
		PI_U3PhCl.Out = 0.0;
	}
	McuData.WU_3PhCl = PI_U3PhCl.Ref + PI_U3PhCl.Out;
}

/**/
void Delay(volatile float32 *Dy, float32 Src) {

}
/**/
void LowPass(volatile float32 *Flt, float32 Src, float32 TsPerT1) {
	*Flt = (*Flt + Src * TsPerT1) / (1.0 + TsPerT1);
}

void CplxLowPass(cfloat32 *Flt, cfloat32 Src, float32 TsPerT1) {
	Flt->re = (Flt->re + Src.re * TsPerT1) / (1.0 + TsPerT1);
	Flt->im = (Flt->im + Src.im * TsPerT1) / (1.0 + TsPerT1);
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

void CPLX2FRAC(float32 *Re, float32 *Im, cfloat32 Z) {
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
	Z_conj.im = Z.im;
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

cfloat32 PH3TOCPLX(float32 a, float32 b, float32 c) {
	cfloat32 Z;
	Z.re = (a - 0.5 * (b + c)) * 2.0 / 3.0;
	Z.im = (b - c) * ONEbySQRT3;
	return Z;
}

void CPLXTO3PH(float32 *a, float32 *b, float32 *c, cfloat32 Z) {
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
