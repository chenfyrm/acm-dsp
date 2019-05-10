/*
 * acclma.c
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#include <math.h>
#include "ufctrl_new.h"

TYPE_UFCOMA acmctrl = UFCOMA_DEFAULTS;

//#define KP 0.3
//#define KI 40

#define TSC  		(1.0/1350.0/2.0)
#define DEADTIME	(0.0*0.000001)
#define	MINPW		(16.0*0.000001)

//#define KP 2.167
//#define KI 243

//#define KP 0.6767
//#define KI 232
//
//#define KP_U 0.09
//#define KI_U 58

void UFCOMAStep(void) {
	/**/
	TFrefRmp();
	/**/
//	FrefUDcLk();
	/**/
	FrefRmp();
	/**/
	UF3PhCmp();
	/**/
	F3PhSz();
	/**/
	U3PhSz();
	/**/
	IPhClGenOvLd();
	/**/
	F3PhRef();
	/**/
	U3PhRef();
	/**/
	U3PhCl();

	if (acmctrl.L_En3PhCl) {
		acmctrl.WU_3PhDsp = acmctrl.WU_3PhCl;
	}

//	acmctrl.WF_3PhDsp = 50.0;
//
//	if(acmctrl.WU_3PhDsp<50.0)
//	{
//		acmctrl.WU_3PhDsp += 0.1;
//		if(acmctrl.WU_3PhDsp>50.0)
//			acmctrl.WU_3PhDsp = 50.0;
//	}
//	if(acmctrl.WU_3PhDsp>50.0)
//	{
//		acmctrl.WU_3PhDsp -= 0.1;
//		if(acmctrl.WU_3PhDsp<50.0)
//			acmctrl.WU_3PhDsp = 50.0;
//	}
}

void DspStep(void) {
	/**/
	acmctrl.XX_M = acmctrl.WU_3PhDsp / acmctrl.XU_DcLk;

	OvMd();
	SVPWM();

	//-------------------------
	acmctrl.XX_DutyA = Limit(acmctrl.XX_DutyA, 0.1, 0.9);
	acmctrl.XX_DutyB = Limit(acmctrl.XX_DutyB, 0.1, 0.9);
	acmctrl.XX_DutyC = Limit(acmctrl.XX_DutyC, 0.1, 0.9);

	/**/
	acmctrl.XU_3PhPek = sqrt(
			acmctrl.XU_3PhAl * acmctrl.XU_3PhAl
					+ acmctrl.XU_3PhBe * acmctrl.XU_3PhBe);
	acmctrl.LpFilterU3PhPek.XX_In = acmctrl.XU_3PhPek;
	acmctrl.LpFilterU3PhPek.XX_T = 1.0 / 10.0;
	acmctrl.LpFilterU3PhPek.XX_Ts = acmctrl.PT_Tsc;
	LPFILTER(&acmctrl.LpFilterU3PhPek);
	acmctrl.XU_3PhPek = acmctrl.LpFilterU3PhPek.XX_Out;

	acmctrl.park.Alpha = acmctrl.XU_3PhAl;
	acmctrl.park.Beta = acmctrl.XU_3PhBe;
	acmctrl.park.Sine = sin(acmctrl.XX_Theta + acmctrl.PD_TrfSfPr3Ph);
	acmctrl.park.Cosine = cos(acmctrl.XX_Theta + acmctrl.PD_TrfSfPr3Ph);
	PARK(&acmctrl.park);
	acmctrl.XU_3PhRe = acmctrl.park.Ds;
	acmctrl.XU_3PhIm = acmctrl.park.Qs;

	acmctrl.LpFilterU3PhIm.XX_In = acmctrl.XU_3PhIm;
	acmctrl.LpFilterU3PhIm.XX_T = 1.0 / 10.0;
	acmctrl.LpFilterU3PhIm.XX_Ts = acmctrl.PT_Tsc;
	LPFILTER(&acmctrl.LpFilterU3PhIm);
	acmctrl.XU_3PhIm = acmctrl.LpFilterU3PhIm.XX_Out;

	acmctrl.clarke.As = acmctrl.XI_PhA;
	acmctrl.clarke.Bs = acmctrl.XI_PhB;
	acmctrl.clarke.Cs = acmctrl.XI_PhC;
	CLARKE(&acmctrl.clarke);

	acmctrl.park.Alpha = acmctrl.clarke.Alpha;
	acmctrl.park.Beta = acmctrl.clarke.Beta;
	acmctrl.park.Sine = sin(acmctrl.XX_Theta);
	acmctrl.park.Cosine = cos(acmctrl.XX_Theta);
	PARK(&acmctrl.park);
	acmctrl.XI_PhAct = acmctrl.park.Ds;
	acmctrl.XI_PhRct = acmctrl.park.Qs;

	//update
	acmctrl.XX_Theta += PI2 * acmctrl.WF_3PhDsp * acmctrl.PT_Tsc;
	if (acmctrl.XX_Theta >= PI2)
		acmctrl.XX_Theta -= PI2;
	if (acmctrl.XX_Theta < 0)
		acmctrl.XX_Theta += PI2;

	if (!acmctrl.XX_Mode) {
		acmctrl.XX_Mode = 1;
	} else {
		acmctrl.XX_Mode = 0;
	}
}

void UFCOMAInit(void) {
	acmctrl.PT_Tsc = TSC;
	acmctrl.WF_3PhRmp = 0.0;
	acmctrl.WF_3PhDsp = 0.0;
	acmctrl.WU_3PhUFRt = 0.0;
	acmctrl.WU_3PhDsp = 0.0;

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

}

void UFCOMATerm(void) {

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
		acmctrl.WU_3PhUFRt = temp / SQRT3 * SQRT2; //相电压峰值
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

void ACCL_B(void) {

	float32 PU_PhclTrsMax = 75.0;
	float32 PI_PhclTrsAbsLim = 600.0;

	float32 PX_IPhClTrsKpAct = 0.005;
	float32 PX_IPhClTrsKpRct = 0.03;
	float32 PX_IPhClTrsKpAbs = 0.0;

//	float32 act,rct,abs;
//	act =
}
void Clarke(float32 *alpha,float32 *beta,float32 a,float32 b,float32 c)
{
	*alpha = (a - 0.5*(b + c))*2.0/3.0;
	*beta = (b-c)*ONEbySQRT3;
}
///**/
//void CLARKE(TYPE_CLARKE *data) {
//	data->Alpha = (data->As - 0.5 * (data->Bs + data->Cs)) * 2.0 / 3.0;
//	data->Beta = (data->Bs - data->Cs) * ONEbySQRT3;
//}

/**/
void PARK(TYPE_PARK *data) {
	data->Ds = data->Alpha * data->Cosine + data->Beta * data->Sine;
	data->Qs = data->Beta * data->Cosine - data->Alpha * data->Sine;
}
/**/
void IPARK(TYPE_IPARK *data) {
	data->Alpha = data->Ds * data->Cosine - data->Qs * data->Sine;
	data->Beta = data->Qs * data->Cosine + data->Ds * data->Sine;
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
//void SVGEN(TYPE_SVGEN *data) {
//	data->tmp1 = data->Ubeta;
//	data->tmp2 = data->Ubeta * 0.5 + data->Ualpha * SQRT3byTWO;
//	data->tmp3 = data->tmp2 - data->tmp1;
//
//	data->VecSector = 3;
//	data->VecSector =
//			(data->tmp2 > 0) ? (data->VecSector - 1) : data->VecSector;
//	data->VecSector =
//			(data->tmp3 > 0) ? (data->VecSector - 1) : data->VecSector;
//	data->VecSector =
//			(data->tmp1 < 0) ? (7 - data->VecSector) : data->VecSector;
//
//	if (data->VecSector == 1 || data->VecSector == 4) {
//		data->Ta = data->tmp2;
//		data->Tb = data->tmp1 - data->tmp3;
//		data->Tc = -data->tmp2;
//	} else if (data->VecSector == 2 || data->VecSector == 5) {
//		data->Ta = data->tmp3 + data->tmp2;
//		data->Tb = data->tmp1;
//		data->Tc = -data->tmp1;
//	} else {
//		data->Ta = data->tmp3;
//		data->Tb = -data->tmp3;
//		data->Tc = -(data->tmp1 + data->tmp2);
//	}
//
//	/*从[-1 1]变换[0 1]*/
//	data->Ta = data->Ta * 0.5 + 0.5;
//	data->Tb = data->Tb * 0.5 + 0.5;
//	data->Tc = data->Tc * 0.5 + 0.5;
//
//}
//
///**/
//void MINPWLIM(TYPE_MINPWLIM *data) {
//	data->Ta_out = data->Ta_in;
//	data->Tb_out = data->Tb_in;
//	data->Tc_out = data->Tc_in;
//
//	if (data->Ta_in <= data->Tmin)
//		data->Ta_out = data->Tmin;
//	if (data->Ta_in >= (1.0 - data->Tmin))
//		data->Ta_out = (1.0 - data->Tmin);
//
//	if (data->Tb_in <= data->Tmin)
//		data->Tb_out = data->Tmin;
//	if (data->Tb_in >= (1.0 - data->Tmin))
//		data->Tb_out = (1.0 - data->Tmin);
//
//	if (data->Tc_in <= data->Tmin)
//		data->Tc_out = data->Tmin;
//	if (data->Tc_in >= (1.0 - data->Tmin))
//		data->Tc_out = (1.0 - data->Tmin);
//
//}

/**/
void LPFILTER(TYPE_LPFILTER *data) {
	/**/
	data->XX_Out = (data->XX_Out + data->XX_Ts / data->XX_T * data->XX_In)
			/ (1.0 + data->XX_Ts / data->XX_T);
}

void SOGIOSGMA(TYPE_SOGIOSGMA *data) {
//	data->Ts = 1.0/2700.0;
//	data->w = 100*3.1415926;
//	data->K = sqrt(2);

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

	/*update*/
	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;
	data->oldBeta2 = data->oldBeta1;
	data->oldBeta1 = data->beta;

}

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

void OvMd(void) {
	//[0 1/sqrt(3) 0.579 0.6038 0.6057]
	//[0 1/sqrt(3) 0.58  0.6389 0.6667]

	if (acmctrl.XX_M < 0)
		acmctrl.XX_MOvMd = 0;
	else if (acmctrl.XX_M < 1.0 / sqrt(3))
		acmctrl.XX_MOvMd = acmctrl.XX_M;
	else if (acmctrl.XX_M < 0.579)
		acmctrl.XX_MOvMd = 1.0 / sqrt(3)
				+ (0.58 - 1.0 / sqrt(3)) / (0.579 - 1.0 / sqrt(3))
						* (acmctrl.XX_M - 1.0 / sqrt(3));
	else if (acmctrl.XX_M < 0.6038)
		acmctrl.XX_MOvMd = 0.58
				+ (0.6389 - 0.58) / (0.6038 - 0.579) * (acmctrl.XX_M - 0.579);
	else if (acmctrl.XX_M < 0.6057)
		acmctrl.XX_MOvMd = 0.6389
				+ (0.6667 - 0.6389) / (0.6057 - 0.6038)
						* (acmctrl.XX_M - 0.6038);
	else {
		acmctrl.XX_MOvMd = 0.6667;
		acmctrl.WU_OvMd = (acmctrl.XX_M - 0.6057) * acmctrl.XU_DcLk;
	}
}

void SVPWM(void) {
	float32 a, b, c, min, max, NrmFa, Cml;

	a = acmctrl.XX_MOvMd * cos(acmctrl.XX_Theta);
	b = acmctrl.XX_MOvMd * cos(acmctrl.XX_Theta - 2.0 / 3.0 * PI);
	c = acmctrl.XX_MOvMd * cos(acmctrl.XX_Theta - 4.0 / 3.0 * PI);

	min = Min(a, Min(b, c));
	max = Max(a, Max(b, c));

	NrmFa = Max(1.0, max - min);
	Cml = (max + min) * (-0.5);

	acmctrl.XX_DutyA = (a + Cml) / NrmFa + 0.5;
	acmctrl.XX_DutyB = (b + Cml) / NrmFa + 0.5;
	acmctrl.XX_DutyC = (c + Cml) / NrmFa + 0.5;
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

