#include "math.h"
#include "acm_dsp.h"

volatile struct Dsp_Data DspData;
volatile struct Dsp_Param DspParam;
volatile struct Mcu_Data McuData;
volatile struct Mcu_Param McuParam;

void DspInit(void) {

	DspData.XT_Tsc = 1.0 / 1350.0 / 2.0;

	DspParam.PT_Tsc = 1.0 / 1350.0 / 2.0;
}

void DspStep(void) {
	SIPR_B();
	ACCL_B();
	UFCO_B();
	PPG3_B();

	DspData.XX_Mode = fabs(1 - DspData.XX_Mode);


}

void SIPR_B(void) {

	DspData.WX_Theta += 100 * PI * DspData.XT_Tsc;
	DspData.WX_Theta = fmod(DspData.XX_Theta, 2 * PI);
}

void ACCL_B(void) {

}

void UFCO_B(void) {
//	DspData.

	SVPWM(&DspData.XX_CrU,&DspData.XX_CrV,&DspData.XX_CrW,);

}

void PPG3_B(void) {
	DspData.XX_DutyA = Limit(DspData.XX_CrU, 0.1, 0.9);
	DspData.XX_DutyB = Limit(DspData.XX_CrV, 0.1, 0.9);
	DspData.XX_DutyC = Limit(DspData.XX_CrW, 0.1, 0.9);
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

void SVPWM(float32 *DutyA,float32 *DutyB,float32 *DutyC,cfloat32 _3PhAB)
{
	float32 a, b, c, min, max, NrmFa, Cml;

	CPLXTO3PH(&a,&b,&c,_3PhAB);

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
	acmctrl.WF_3PhRmp = 0.0;
	acmctrl.WF_3PhDsp = 0.0;
	acmctrl.WU_3PhUFRt = 0.0;
	acmctrl.WU_3PhDsp = 0.0;

	/*TFrefRmp*/
	acmctrl.PX_FRefRmpUp = 40.0;
	acmctrl.PX_FRefRmpUpSlaveAcm = 100.0;
	acmctrl.PX_FRefRmpDo1 = 40.0;
	acmctrl.PX_FRefRmpDo2 = 40.0;
	acmctrl.PX_FRefRmpDo3 = 40.0;
	acmctrl.PF_FRefRmpDo12 = 4.0;
	acmctrl.PF_FRefRmpDo23 = 30.0;

	/*FrefRmp*/
	acmctrl.PF_3PhNom = 50.3;
	acmctrl.PF_3PhMin = 3.0;

	/*UF3PhCmp 4ms*/
	acmctrl.L_EnUF3PhCmp = TRUE;
	acmctrl.PI_UF3PhCmpActHiLo = 4000.0;
	acmctrl.PF_UF3PhCmpActHiLo = -10.0;
	acmctrl.PI_UF3PhCmpRctHiLo = 4000.0;
	acmctrl.PU_UF3PhCmpRctHiLo = -100.0;

	/*F3PhSz 16ms*/
	acmctrl.PX_KpF3PhSzCl = 0.5;
	acmctrl.PT_F3PhSzCl = 800.0; //ms
	//	acmctrl.PX_KpF3PhSzCl = 2.0;
	//	acmctrl.PT_F3PhSzCl = 50.0;
	//	acmctrl.PX_KpF3PhSzCl = 2.0*100.0*3.1415926;
	//	acmctrl.PT_F3PhSzCl = 1000.0/(100.0*3.1415926*100.0*3.1415926);
	acmctrl.PF_UF3PhSzClMaxMin = 50.0;
	acmctrl.PF_UF3PhSzRdy = 0.3;
	acmctrl.PT_UF3PhSzRmp = 1000.0; //ms
	acmctrl.F3PhSz.Kp = acmctrl.PX_KpF3PhSzCl;
	acmctrl.F3PhSz.Ki = 1000.0 / acmctrl.PT_F3PhSzCl * acmctrl.PT_Tsc;
	acmctrl.F3PhSz.Umax = acmctrl.PF_UF3PhSzClMaxMin / (16.0 * 2.9);
	acmctrl.F3PhSz.Umin = -acmctrl.PF_UF3PhSzClMaxMin / (16.0 * 2.9);
	acmctrl.PD_TrfSfPr3Ph = PI / 3.0 - PI / 27.0;
	//	acmctrl.PD_TrfSfPr3Ph = 0.0;

	/*U3PhSz 16ms*/
	acmctrl.PU_UF3PhSzClAdd = 0.0;
	acmctrl.PU_UF3PhSzClMaxMin = 100.0;
	acmctrl.PU_UF3PhSzRdy = 20.0;

	acmctrl.PU_3PhBusAct = 370.0;
	acmctrl.PU_3PhBusIdle = 50.0;

	/*U3PhRef*/
	acmctrl.PF_U3PhRef2 = 6.0;
	acmctrl.PF_U3PhRef3 = 50.0;
	acmctrl.PU_U3PhRef1 = 0.0; //0Hz
	acmctrl.PU_U3PhRef2 = 0.0;  //6Hz
	acmctrl.PU_U3PhRef3 = 100.0;  //50Hz
	acmctrl.PU_U3PhRef4 = 100.0; //100Hz
	acmctrl.L_ExtU3PhRef = FALSE;
	acmctrl.PX_ExtU3PhRefRmp = 200.0;
	acmctrl.L_EnRmpU3PhRef = FALSE;
	acmctrl.PX_U3PhRefRmp1 = 200.0;
	acmctrl.PX_U3PhRefRmp2 = 50.0;
	acmctrl.PX_U3PhRefRmpSel = 0.9;

	/*U3PhCl 4ms*/
	acmctrl.L_En3PhCl = TRUE;
	acmctrl.L_EnU3PhOpLoCl = FALSE;
	acmctrl.PX_KpU3PhCl = 0.8;
	acmctrl.PT_U3PhCl = 50.0; //ms
	acmctrl.PU_3PhClMax = 75.0;
	acmctrl.PU_3PhClMin = -50.0;
	acmctrl.PU_3PhClRefMax = 395.0;
	acmctrl.PU_3PhClRefMin = 0.0;
	acmctrl.PX_TrfRtPr3Ph = 1.684;
	acmctrl.U3PhCl.Kp = acmctrl.PX_KpU3PhCl;
	acmctrl.U3PhCl.Ki = 1000.0 / acmctrl.PT_U3PhCl * acmctrl.PT_Tsc;
	acmctrl.U3PhCl.Umax = acmctrl.PU_3PhClMax;
	acmctrl.U3PhCl.Umin = acmctrl.PU_3PhClMin;
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
	acmctrl.XX_FRefRmpUp = 40.0;
	acmctrl.XX_FRefRmpDo = 40.0;
}

void FrefUDcLk(void) {

}

void FrefRmp(void) {
	if (acmctrl.A_CvOp == 1) {
		if (acmctrl.WF_3PhRmp < acmctrl.PF_3PhMin)
			acmctrl.WF_3PhRmp = acmctrl.PF_3PhMin;
		if (acmctrl.WF_3PhRmp < acmctrl.PF_3PhNom) {
			acmctrl.WF_3PhRmp += acmctrl.XX_FRefRmpUp * acmctrl.PT_Tsc;
			if (acmctrl.WF_3PhRmp > acmctrl.PF_3PhNom)
				acmctrl.WF_3PhRmp = acmctrl.PF_3PhNom;
		}
		if (acmctrl.WF_3PhRmp > acmctrl.PF_3PhNom) {
			acmctrl.WF_3PhRmp -= acmctrl.XX_FRefRmpDo * acmctrl.PT_Tsc;
			if (acmctrl.WF_3PhRmp < acmctrl.PF_3PhNom)
				acmctrl.WF_3PhRmp = acmctrl.PF_3PhNom;
		}
		if (acmctrl.WF_3PhRmp == acmctrl.PF_3PhNom)
			acmctrl.A_FNom = TRUE;
		else
			acmctrl.A_FNom = FALSE;
	} else {
		if (acmctrl.WF_3PhRmp < acmctrl.PF_3PhMin)
			acmctrl.WF_3PhRmp = acmctrl.PF_3PhMin;
		if (acmctrl.WF_3PhRmp > acmctrl.PF_3PhMin) {
			acmctrl.WF_3PhRmp -= acmctrl.XX_FRefRmpDo * acmctrl.PT_Tsc;
			if (acmctrl.WF_3PhRmp < acmctrl.PF_3PhMin)
				acmctrl.WF_3PhRmp = acmctrl.PF_3PhMin;
		}
		if (acmctrl.WF_3PhRmp == acmctrl.PF_3PhMin)
			acmctrl.A_FNom = TRUE;
		else
			acmctrl.A_FNom = FALSE;
	}
}

void UF3PhCmp(void) {
	if (acmctrl.A_CvOp && acmctrl.L_EnUF3PhCmp) {
		acmctrl.WF_WF3PhCmp = acmctrl.PF_UF3PhCmpActHiLo
				/ acmctrl.PI_UF3PhCmpActHiLo * acmctrl.XI_PhAct;
		acmctrl.WU_UF3PhCmp = acmctrl.PU_UF3PhCmpRctHiLo
				/ acmctrl.PI_UF3PhCmpRctHiLo * acmctrl.XI_PhRct;
	} else {
		acmctrl.WF_WF3PhCmp = 0.0;
		acmctrl.WU_UF3PhCmp = 0.0;
	}
}

void F3PhSz(void) {
	if (acmctrl.C_AuSz) {
		float32 temp = sqrt(
				acmctrl.XU_3PhRe * acmctrl.XU_3PhRe
						+ acmctrl.XU_3PhIm * acmctrl.XU_3PhIm);
		acmctrl.F3PhSz.Ref = 0.0;
		if (temp < 0.001) {
			acmctrl.F3PhSz.Fbk = -acmctrl.XU_3PhIm / 0.001;
		} else {
			acmctrl.F3PhSz.Fbk = -acmctrl.XU_3PhIm / temp;
		}
//		acmctrl.F3PhSz.Fbk = -acmctrl.XU_3PhIm;
		PI_CONTROLLER(&acmctrl.F3PhSz);
		acmctrl.WF_UF3PhSz = acmctrl.F3PhSz.Out;
	} else {
		acmctrl.WF_UF3PhSz = 0.0;
	}
}

void U3PhSz(void) {
	if (acmctrl.C_AuSz) {
		float32 temp = acmctrl.XU_3PhPek / SQRT3 * acmctrl.PX_TrfRtPr3Ph
				- acmctrl.WU_3PhDsp;

		if (acmctrl.WU_UF3PhSz < temp) {
			acmctrl.WU_UF3PhSz += 1.0;
			if (acmctrl.WU_UF3PhSz > temp)
				acmctrl.WU_UF3PhSz = temp;
		}
		if (acmctrl.WU_UF3PhSz > temp) {
			acmctrl.WU_UF3PhSz -= 1.0;
			if (acmctrl.WU_UF3PhSz < temp)
				acmctrl.WU_UF3PhSz = temp;
		}
		acmctrl.WU_UF3PhSz += acmctrl.PU_UF3PhSzClAdd;
		acmctrl.WU_UF3PhSzErr = -temp;
	} else {
		acmctrl.WU_UF3PhSz = 0.0;
	}
}

void IPhClGenOvLd(void) {
	acmctrl.WF_IPhCl = 0.0;
}

void IPhClPsTrs(void) {

}

void F3PhRef(void) {
	acmctrl.WF_3PhDsp = acmctrl.WF_3PhRmp + acmctrl.WF_WF3PhCmp
			+ acmctrl.WF_UF3PhSz + acmctrl.WF_IPhCl;
	acmctrl.WF_3PhU3PhRef = acmctrl.WF_3PhDsp;
}

void U3PhRef(void) {
	float32 temp;
	if (!acmctrl.L_ExtU3PhRef) {
		if (acmctrl.WF_3PhU3PhRef < 0.0)
			temp = acmctrl.PU_U3PhRef1;
		if (acmctrl.WF_3PhU3PhRef >= 0.0
				&& acmctrl.WF_3PhU3PhRef < acmctrl.PF_U3PhRef2)
			temp = acmctrl.PU_U3PhRef1
					+ (acmctrl.WF_3PhU3PhRef - 0.0)
							/ (acmctrl.PF_U3PhRef2 - 0.0)
							* (acmctrl.PU_U3PhRef2 - acmctrl.PU_U3PhRef1);
		if (acmctrl.WF_3PhU3PhRef >= acmctrl.PF_U3PhRef2
				&& acmctrl.WF_3PhU3PhRef < acmctrl.PF_U3PhRef3)
			temp = acmctrl.PU_U3PhRef2
					+ (acmctrl.WF_3PhU3PhRef - acmctrl.PF_U3PhRef2)
							/ (acmctrl.PF_U3PhRef3 - acmctrl.PF_U3PhRef2)
							* (acmctrl.PU_U3PhRef3 - acmctrl.PU_U3PhRef2);
		if (acmctrl.WF_3PhU3PhRef >= acmctrl.PF_U3PhRef3
				&& acmctrl.WF_3PhU3PhRef < 100.0)
			temp = acmctrl.PU_U3PhRef3
					+ (acmctrl.WF_3PhU3PhRef - acmctrl.PF_U3PhRef3)
							/ (100.0 - acmctrl.PF_U3PhRef3)
							* (acmctrl.PU_U3PhRef4 - acmctrl.PU_U3PhRef3);
		if (acmctrl.WF_3PhU3PhRef >= 100.0)
			temp = acmctrl.PU_U3PhRef4;
	}

	if (!acmctrl.L_EnRmpU3PhRef) {
		acmctrl.WU_3PhUFRt = temp / SQRT3 * SQRT2; //œ‡µÁ—π∑Â÷µ
	}
}

void U3PhCl(void) {
	acmctrl.WU_3PhClIn = acmctrl.WU_3PhUFRt * acmctrl.PX_TrfRtPr3Ph;

	acmctrl.U3PhCl.Ref = acmctrl.WU_3PhClIn + acmctrl.WU_UF3PhCmp
			+ acmctrl.WU_UF3PhSz;

	if (acmctrl.U3PhCl.Ref < acmctrl.PU_3PhClRefMin)
		acmctrl.U3PhCl.Ref = acmctrl.PU_3PhClRefMin;
	if (acmctrl.U3PhCl.Ref > acmctrl.PU_3PhClRefMax)
		acmctrl.U3PhCl.Ref = acmctrl.PU_3PhClRefMax;

	acmctrl.U3PhCl.Fbk = acmctrl.XU_3PhPek / SQRT3 * acmctrl.PX_TrfRtPr3Ph;

	if (acmctrl.B_EnU3PhCl) {
		PI_CONTROLLER(&acmctrl.U3PhCl);
	} else {
		acmctrl.U3PhCl.i1 = 0.0;
		acmctrl.U3PhCl.v1 = 0.0;
		acmctrl.U3PhCl.Out = 0.0;
	}
	acmctrl.WU_3PhCl = acmctrl.U3PhCl.Ref + acmctrl.U3PhCl.Out;
}

/**/
void LowPass(float32 *Flt, float32 Src, float32 TsPerT1) {
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

}

cfloat32 CPLXSHFT(cfloat32 Z, int32 m) {

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
