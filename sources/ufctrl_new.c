/*
 * acclma.c
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#include <math.h>
#include "ufctrl_new.h"

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

void UFCOMAStep(TYPE_UFCOMA *data) {
	/**/
	TFrefRmp(data);
	/**/
//	FrefUDcLk(data);
	/**/
	FrefRmp(data);
	/**/
	UF3PhCmp(data);
	/**/
	F3PhSz(data);
	/**/
	U3PhSz(data);
	/**/
	IPhClGenOvLd(data);
	/**/
	F3PhRef(data);
	/**/
	U3PhRef(data);
	/**/
	U3PhCl(data);

	if (data->L_En3PhCl) {
		data->WU_3PhDsp = data->WU_3PhCl;
	}

//	data->WF_3PhDsp = 50.0;
//
//	if(data->WU_3PhDsp<50.0)
//	{
//		data->WU_3PhDsp += 0.1;
//		if(data->WU_3PhDsp>50.0)
//			data->WU_3PhDsp = 50.0;
//	}
//	if(data->WU_3PhDsp>50.0)
//	{
//		data->WU_3PhDsp -= 0.1;
//		if(data->WU_3PhDsp<50.0)
//			data->WU_3PhDsp = 50.0;
//	}
}

void DspStep(TYPE_UFCOMA *data) {
	/**/
	data->XX_M = data->WU_3PhDsp / data->XU_DcLk * SQRT3;

	data->svgen.Ualpha = data->XX_M
			* cos(data->XX_Theta + PI2 * data->WF_3PhDsp * data->PT_Tsc * 1.5);
	data->svgen.Ubeta = data->XX_M
			* sin(data->XX_Theta + PI2 * data->WF_3PhDsp * data->PT_Tsc * 1.5);
	SVGEN(&data->svgen);

//	data->XX_DutyA = data->svgen.Ta;
//	data->XX_DutyB = data->svgen.Tb;
//	data->XX_DutyC = data->svgen.Tc;

//---------------------
	data->minPwLim.Ta_in = data->svgen.Ta;
	data->minPwLim.Tb_in = data->svgen.Tb;
	data->minPwLim.Tc_in = data->svgen.Tc;
	data->minPwLim.Tmin = MINPW / TSC;
	MINPWLIM(&data->minPwLim);

	//-------------------------
	data->XX_DutyA = data->minPwLim.Ta_out;
	data->XX_DutyB = data->minPwLim.Tb_out;
	data->XX_DutyC = data->minPwLim.Tc_out;

	/**/
	data->XU_3PhPek = sqrt(
			data->XU_3PhAl * data->XU_3PhAl + data->XU_3PhBe * data->XU_3PhBe);
	data->LpFilterU3PhPek.XX_In = data->XU_3PhPek;
	data->LpFilterU3PhPek.XX_T = 1.0 / 10.0;
	data->LpFilterU3PhPek.XX_Ts = data->PT_Tsc;
	LPFILTER(&data->LpFilterU3PhPek);
	data->XU_3PhPek = data->LpFilterU3PhPek.XX_Out;

	data->park.Alpha = data->XU_3PhAl;
	data->park.Beta = data->XU_3PhBe;
	data->park.Sine = sin(data->XX_Theta + data->PD_TrfSfPr3Ph);
	data->park.Cosine = cos(data->XX_Theta + data->PD_TrfSfPr3Ph);
	PARK(&data->park);
	data->XU_3PhRe = data->park.Ds;
	data->XU_3PhIm = data->park.Qs;

	data->LpFilterU3PhIm.XX_In = data->XU_3PhIm;
	data->LpFilterU3PhIm.XX_T = 1.0 / 10.0;
	data->LpFilterU3PhIm.XX_Ts = data->PT_Tsc;
	LPFILTER(&data->LpFilterU3PhIm);
	data->XU_3PhIm = data->LpFilterU3PhIm.XX_Out;

	data->clarke.As = data->XI_PhA;
	data->clarke.Bs = data->XI_PhB;
	data->clarke.Cs = data->XI_PhC;
	CLARKE(&data->clarke);

	data->park.Alpha = data->clarke.Alpha;
	data->park.Beta = data->clarke.Beta;
	data->park.Sine = sin(data->XX_Theta);
	data->park.Cosine = cos(data->XX_Theta);
	PARK(&data->park);
	data->XI_PhAct = data->park.Ds;
	data->XI_PhRct = data->park.Qs;

	//update
	data->XX_Theta += PI2 * data->WF_3PhDsp * data->PT_Tsc;
	if (data->XX_Theta >= PI2)
		data->XX_Theta -= PI2;
	if (data->XX_Theta < 0)
		data->XX_Theta += PI2;

	if (!data->XX_Mode) {
		data->XX_Mode = 1;
	} else {
		data->XX_Mode = 0;
	}
}

void UFCOMAInit(TYPE_UFCOMA *data) {
	data->PT_Tsc = TSC;
	data->WF_3PhRmp = 0.0;
	data->WF_3PhDsp = 0.0;
	data->WU_3PhUFRt = 0.0;
	data->WU_3PhDsp = 0.0;

	/*U3PhRef*/
	data->PF_U3PhRef2 = 6.0;
	data->PF_U3PhRef3 = 50.0;
	data->PU_U3PhRef1 = 0.0; //0Hz
	data->PU_U3PhRef2 = 0.0;
	data->PU_U3PhRef3 = 150.0;
	data->PU_U3PhRef4 = 150.0; //100Hz
	data->L_ExtU3PhRef = FALSE;
	data->PX_ExtU3PhRefRmp = 200.0;
	data->L_EnRmpU3PhRef = FALSE;
	data->PX_U3PhRefRmp1 = 200.0;
	data->PX_U3PhRefRmp2 = 50.0;
	data->PX_U3PhRefRmpSel = 0.9;

	/*U3PhCl 4ms*/
	data->L_En3PhCl = TRUE;
	data->L_EnU3PhOpLoCl = FALSE;
	data->PX_KpU3PhCl = 0.8;
	data->PT_U3PhCl = 50.0; //ms
	data->PU_3PhClMax = 75.0;
	data->PU_3PhClMin = -50.0;
	data->PU_3PhClRefMax = 395.0;
	data->PU_3PhClRefMin = 0.0;
	data->PX_TrfRtPr3Ph = 1.684;
	data->U3PhCl.Kp = data->PX_KpU3PhCl;
	data->U3PhCl.Ki = 1000.0 / data->PT_U3PhCl * data->PT_Tsc;
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

	/*UF3PhCmp 4ms*/
	data->L_EnUF3PhCmp = TRUE;
	data->PI_UF3PhCmpActHiLo = 4000.0;
	data->PF_UF3PhCmpActHiLo = -10.0;
	data->PI_UF3PhCmpRctHiLo = 4000.0;
	data->PU_UF3PhCmpRctHiLo = -100.0;

	/*F3PhSz 16ms*/
	data->PX_KpF3PhSzCl = 0.5;
	data->PT_F3PhSzCl = 800.0; //ms
//	data->PX_KpF3PhSzCl = 2.0;
//	data->PT_F3PhSzCl = 50.0;
//	data->PX_KpF3PhSzCl = 2.0*100.0*3.1415926;
//	data->PT_F3PhSzCl = 1000.0/(100.0*3.1415926*100.0*3.1415926);
	data->PF_UF3PhSzClMaxMin = 50.0;
	data->PF_UF3PhSzRdy = 0.3;
	data->PT_UF3PhSzRmp = 1000.0; //ms
	data->F3PhSz.Kp = data->PX_KpF3PhSzCl;
	data->F3PhSz.Ki = 1000.0 / data->PT_F3PhSzCl * data->PT_Tsc;
	data->F3PhSz.Umax = data->PF_UF3PhSzClMaxMin / (16.0 * 2.9);
	data->F3PhSz.Umin = -data->PF_UF3PhSzClMaxMin / (16.0 * 2.9);
	data->PD_TrfSfPr3Ph = PI / 3.0 - PI / 27.0;
//	data->PD_TrfSfPr3Ph = 0.0;

	/*U3PhSz 16ms*/
	data->PU_UF3PhSzClAdd = 0.0;
	data->PU_UF3PhSzClMaxMin = 100.0;
	data->PU_UF3PhSzRdy = 20.0;

}

void UFCOMATerm(TYPE_UFCOMA *data) {

}

void F3PhRef(TYPE_UFCOMA *data) {
	data->WF_3PhDsp = data->WF_3PhRmp + data->WF_WF3PhCmp + data->WF_UF3PhSz
			+ data->WF_IPhCl;
	data->WF_3PhU3PhRef = data->WF_3PhDsp;
}

void U3PhRef(TYPE_UFCOMA *data) {
	float32 temp;
	if (!data->L_ExtU3PhRef) {
		if (data->WF_3PhU3PhRef < 0.0)
			temp = data->PU_U3PhRef1;
		if (data->WF_3PhU3PhRef >= 0.0
				&& data->WF_3PhU3PhRef < data->PF_U3PhRef2)
			temp = data->PU_U3PhRef1
					+ (data->WF_3PhU3PhRef - 0.0) / (data->PF_U3PhRef2 - 0.0)
							* (data->PU_U3PhRef2 - data->PU_U3PhRef1);
		if (data->WF_3PhU3PhRef >= data->PF_U3PhRef2
				&& data->WF_3PhU3PhRef < data->PF_U3PhRef3)
			temp = data->PU_U3PhRef2
					+ (data->WF_3PhU3PhRef - data->PF_U3PhRef2)
							/ (data->PF_U3PhRef3 - data->PF_U3PhRef2)
							* (data->PU_U3PhRef3 - data->PU_U3PhRef2);
		if (data->WF_3PhU3PhRef >= data->PF_U3PhRef3
				&& data->WF_3PhU3PhRef < 100.0)
			temp = data->PU_U3PhRef3
					+ (data->WF_3PhU3PhRef - data->PF_U3PhRef3)
							/ (100.0 - data->PF_U3PhRef3)
							* (data->PU_U3PhRef4 - data->PU_U3PhRef3);
		if (data->WF_3PhU3PhRef >= 100.0)
			temp = data->PU_U3PhRef4;
	}

	if (!data->L_EnRmpU3PhRef) {
		data->WU_3PhUFRt = temp / SQRT3 * SQRT2; //相电压峰值
	}
}

void U3PhCl(TYPE_UFCOMA *data) {
	data->WU_3PhClIn = data->WU_3PhUFRt * data->PX_TrfRtPr3Ph;

	data->U3PhCl.Ref = data->WU_3PhClIn + data->WU_UF3PhCmp + data->WU_UF3PhSz;

	if (data->U3PhCl.Ref < data->PU_3PhClRefMin)
		data->U3PhCl.Ref = data->PU_3PhClRefMin;
	if (data->U3PhCl.Ref > data->PU_3PhClRefMax)
		data->U3PhCl.Ref = data->PU_3PhClRefMax;

	data->U3PhCl.Fbk = data->XU_3PhPek / SQRT3 * data->PX_TrfRtPr3Ph;
	PI_CONTROLLER(&data->U3PhCl);
	if (data->B_EnU3PhCl) {
		data->WU_3PhCl = data->U3PhCl.Ref + data->U3PhCl.Out;
	} else {
		data->WU_3PhCl = data->U3PhCl.Ref;
	}
}

void TFrefRmp(TYPE_UFCOMA *data) {
	data->XX_FRefRmpUp = 40.0;
	data->XX_FRefRmpDo = 40.0;
}

void FrefUDcLk(TYPE_UFCOMA *data) {

}

void FrefRmp(TYPE_UFCOMA *data) {
	if (data->A_CvOp == 1) {
		if (data->WF_3PhRmp < data->PF_3PhMin)
			data->WF_3PhRmp = data->PF_3PhMin;
		if (data->WF_3PhRmp < data->PF_3PhNom) {
			data->WF_3PhRmp += data->XX_FRefRmpUp * data->PT_Tsc;
			if (data->WF_3PhRmp > data->PF_3PhNom)
				data->WF_3PhRmp = data->PF_3PhNom;
		}
		if (data->WF_3PhRmp > data->PF_3PhNom) {
			data->WF_3PhRmp -= data->XX_FRefRmpDo * data->PT_Tsc;
			if (data->WF_3PhRmp < data->PF_3PhNom)
				data->WF_3PhRmp = data->PF_3PhNom;
		}
		if (data->WF_3PhRmp == data->PF_3PhNom)
			data->A_FNom = TRUE;
		else
			data->A_FNom = FALSE;
	} else {
		if (data->WF_3PhRmp < data->PF_3PhMin)
			data->WF_3PhRmp = data->PF_3PhMin;
		if (data->WF_3PhRmp > data->PF_3PhMin) {
			data->WF_3PhRmp -= data->XX_FRefRmpDo * data->PT_Tsc;
			if (data->WF_3PhRmp < data->PF_3PhMin)
				data->WF_3PhRmp = data->PF_3PhMin;
		}
		if (data->WF_3PhRmp == data->PF_3PhMin)
			data->A_FNom = TRUE;
		else
			data->A_FNom = FALSE;
	}
}

void UF3PhCmp(TYPE_UFCOMA *data) {
	if (data->A_CvOp && data->L_EnUF3PhCmp) {
		data->WF_WF3PhCmp = data->PF_UF3PhCmpActHiLo / data->PI_UF3PhCmpActHiLo
				* data->XI_PhAct;
		data->WU_UF3PhCmp = data->PU_UF3PhCmpRctHiLo / data->PI_UF3PhCmpRctHiLo
				* data->XI_PhRct;
	} else {
		data->WF_WF3PhCmp = 0.0;
		data->WU_UF3PhCmp = 0.0;
	}
}

void F3PhSz(TYPE_UFCOMA *data) {
	if (data->C_AuSz) {
		float32 temp = sqrt(
				data->XU_3PhRe * data->XU_3PhRe
						+ data->XU_3PhIm * data->XU_3PhIm);
		data->F3PhSz.Ref = 0.0;
		if (temp < 0.001) {
			data->F3PhSz.Fbk = -data->XU_3PhIm / 0.001;
		} else {
			data->F3PhSz.Fbk = -data->XU_3PhIm / temp;
		}
//		data->F3PhSz.Fbk = -data->XU_3PhIm;
		PI_CONTROLLER(&data->F3PhSz);
		data->WF_UF3PhSz = data->F3PhSz.Out;
	} else {
		data->WF_UF3PhSz = 0.0;
	}
}

void U3PhSz(TYPE_UFCOMA *data) {
	if (data->C_AuSz) {
		float32 temp = data->XU_3PhPek / SQRT3 * data->PX_TrfRtPr3Ph
				- data->WU_3PhDsp;

		if (data->WU_UF3PhSz < temp) {
			data->WU_UF3PhSz += 1.0;
			if (data->WU_UF3PhSz > temp)
				data->WU_UF3PhSz = temp;
		}
		if (data->WU_UF3PhSz > temp) {
			data->WU_UF3PhSz -= 1.0;
			if (data->WU_UF3PhSz < temp)
				data->WU_UF3PhSz = temp;
		}
		data->WU_UF3PhSz += data->PU_UF3PhSzClAdd;
		data->WU_UF3PhSzErr = -temp;
	} else {
		data->WU_UF3PhSz = 0.0;
	}
}

void IPhClGenOvLd(TYPE_UFCOMA *data) {
	data->WF_IPhCl = 0.0;
}

void IPhClPsTrs(TYPE_UFCOMA *data) {

}

/**/
void CLARKE(TYPE_CLARKE *data) {
	data->Alpha = (data->As - 0.5 * (data->Bs + data->Cs)) * 2.0 / 3.0;
	data->Beta = (data->Bs - data->Cs) * ONEbySQRT3;
}

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
void SVGEN(TYPE_SVGEN *data) {
	data->tmp1 = data->Ubeta;
	data->tmp2 = data->Ubeta * 0.5 + data->Ualpha * SQRT3byTWO;
	data->tmp3 = data->tmp2 - data->tmp1;

	data->VecSector = 3;
	data->VecSector =
			(data->tmp2 > 0) ? (data->VecSector - 1) : data->VecSector;
	data->VecSector =
			(data->tmp3 > 0) ? (data->VecSector - 1) : data->VecSector;
	data->VecSector =
			(data->tmp1 < 0) ? (7 - data->VecSector) : data->VecSector;

	if (data->VecSector == 1 || data->VecSector == 4) {
		data->Ta = data->tmp2;
		data->Tb = data->tmp1 - data->tmp3;
		data->Tc = -data->tmp2;
	} else if (data->VecSector == 2 || data->VecSector == 5) {
		data->Ta = data->tmp3 + data->tmp2;
		data->Tb = data->tmp1;
		data->Tc = -data->tmp1;
	} else {
		data->Ta = data->tmp3;
		data->Tb = -data->tmp3;
		data->Tc = -(data->tmp1 + data->tmp2);
	}

	/*从[-1 1]变换[0 1]*/
	data->Ta = data->Ta * 0.5 + 0.5;
	data->Tb = data->Tb * 0.5 + 0.5;
	data->Tc = data->Tc * 0.5 + 0.5;

}

/**/
void MINPWLIM(TYPE_MINPWLIM *data) {
	data->Ta_out = data->Ta_in;
	data->Tb_out = data->Tb_in;
	data->Tc_out = data->Tc_in;

	if (data->Ta_in <= data->Tmin)
		data->Ta_out = data->Tmin;
	if (data->Ta_in >= (1.0 - data->Tmin))
		data->Ta_out = (1.0 - data->Tmin);

	if (data->Tb_in <= data->Tmin)
		data->Tb_out = data->Tmin;
	if (data->Tb_in >= (1.0 - data->Tmin))
		data->Tb_out = (1.0 - data->Tmin);

	if (data->Tc_in <= data->Tmin)
		data->Tc_out = data->Tmin;
	if (data->Tc_in >= (1.0 - data->Tmin))
		data->Tc_out = (1.0 - data->Tmin);

}

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

