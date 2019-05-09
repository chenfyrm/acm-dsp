/*
 * acclma.h
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#ifndef UFCTRL_NEW_H_
#define UFCTRL_NEW_H_

/**/
//#define	 TWObyTHREE	  0.66666666666667       /* 2/3 */
#define ONEbySQRT3		0.57735026918963    /* 1/sqrt(3) */
#define SQRT3byTWO   	0.86602540378444    /* sqrt(3)/2 */
#define SQRT3   		1.73205080756888    /* sqrt(3)/2 */
#define	SQRT2			1.41421356237310
#define	PI  		  	3.14159265358979
#define	PI2  		  	6.28318530717959
#define FALSE			0
#define	TRUE			1

/**/
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int                int16;
typedef long               int32;
typedef long long          int64;
typedef unsigned int       Uint16;
typedef unsigned long      Uint32;
typedef unsigned long long Uint64;
typedef float              float32;
#endif

/**/
typedef struct CLARKE
{
	float32  As;  		// Input: phase-a stator variable
	float32  Bs;		// Input: phase-b stator variable
	float32  Cs;		// Input: phase-c stator variable
	float32  Alpha;		// Output: stationary d-axis stator variable
	float32  Beta;
} TYPE_CLARKE;

/*-----------------------------------------------------------------------------
	Default initalizer for the CLARKE object.
-----------------------------------------------------------------------------*/
#define CLARKE_DEFAULTS {\
	0, \
	0, \
	0, \
	0, \
	0, \
	}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void CLARKE(TYPE_CLARKE *data);

#ifdef __cplusplus
}
#endif

/**/
typedef struct {  float32  Alpha;  		// Input: stationary d-axis stator variable
				  float32  Beta;	 	// Input: stationary q-axis stator variable
				  float32  Sine;		// Input:
				  float32  Cosine; 		// Input:
				  float32  Ds;			// Output: rotating d-axis stator variable
				  float32  Qs;			// Output: rotating q-axis stator variable
		 	 	} TYPE_PARK;

/*-----------------------------------------------------------------------------
Default initalizer for the PARK object.
-----------------------------------------------------------------------------*/
#define PARK_DEFAULTS {   0, \
                          0, \
                          0, \
                          0, \
                          0, \
						  0, \
              			  }

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void PARK(TYPE_PARK *data);

#ifdef __cplusplus
}
#endif

/**/
typedef struct {  float32  Alpha;  		// Output: stationary d-axis stator variable
				  float32  Beta;		// Output: stationary q-axis stator variable
				  float32  Ds;			// Input: rotating d-axis stator variable
				  float32  Qs;			// Input: rotating q-axis stator variable
				  float32  Sine;		// Input: Sine term
				  float32  Cosine;		// Input: Cosine term
		 	    } TYPE_IPARK;

/*-----------------------------------------------------------------------------
Default initalizer for the IPARK object.
-----------------------------------------------------------------------------*/
#define IPARK_DEFAULTS {  0, \
                          0, \
                          0, \
                          0, \
                          0, \
						  0, \
              		   }

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void IPARK(TYPE_IPARK *data);

#ifdef __cplusplus
}
#endif

/**/
typedef struct {  float32  Ref;   			// Input: reference set-point
				  float32  Fbk;   			// Input: feedback
				  float32  Out;   			// Output: controller output
				  float32  Kp;				// Parameter: proportional loop gain
				  float32  Ki;			    // Parameter: integral gain
				  float32  Umax;			// Parameter: upper saturation limit
				  float32  Umin;			// Parameter: lower saturation limit
				  float32  up;				// Data: proportional term
				  float32  ui;				// Data: integral term
				  float32  v1;				// Data: pre-saturated controller output
				  float32  i1;				// Data: integrator storage: ui(k-1)
				  float32  w1;				// Data: saturation record: [u(k-1) - v(k-1)]
				} TYPE_PI_CONTROLLER;


/*-----------------------------------------------------------------------------
Default initalisation values for the PI_GRANDO objects
-----------------------------------------------------------------------------*/

#define PI_CONTROLLER_DEFAULTS {		\
	0, 			\
	0, 			\
	0, 			\
	1.0,	\
	0.0,	\
	1.0,	\
	-1.0, 	\
	0.0,	\
	0.0, 	\
	0.0,	\
	0.0,	\
	1.0 	\
	}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void PI_CONTROLLER(TYPE_PI_CONTROLLER *data);

#ifdef __cplusplus
}
#endif

/**/
typedef struct 	{ float32  Ualpha; 			// Input: reference alpha-axis phase voltage
				  float32  Ubeta;			// Input: reference beta-axis phase voltage
				  float32  Ta;				// Output: reference phase-a switching function
				  float32  Tb;				// Output: reference phase-b switching function
				  float32  Tc;				// Output: reference phase-c switching function
				  float32  tmp1;			// Variable: temp variable
				  float32  tmp2;			// Variable: temp variable
				  float32  tmp3;			// Variable: temp variable
				  Uint16 VecSector;		// Space vector sector
				} TYPE_SVGEN;


/*-----------------------------------------------------------------------------
Default initalizer for the SVGEN object.
-----------------------------------------------------------------------------*/
#define SVGEN_DEFAULTS { 0,0,0,0,0,0.0,0.0,0.0,3}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void SVGEN(TYPE_SVGEN *data);

#ifdef __cplusplus
}
#endif

/*
 * LPFILTER
 * */
typedef struct LPFILTER
{
	float32	XX_In;
	float32 XX_Out;
	float32	XX_Ts;
	float32	XX_T;
}TYPE_LPFILTER;

#define LPFILTER_DEFAULTS {\
	0.0,\
	0.0,\
	1.0/1450.0/2.0,\
	1.0/30.0,\
	}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void LPFILTER(TYPE_LPFILTER *interface);

#ifdef __cplusplus
}
#endif

/**/
typedef struct
{
	float32	Ta_in;//input
	float32	Tb_in;
	float32	Tc_in;
	float32	Ta_out;//output
	float32	Tb_out;
	float32	Tc_out;
	float32	Tmin;//param
}TYPE_MINPWLIM;

#define	MINPWLIM_DEFAULTS	{\
	0,\
	0,\
	0,\
	0,\
	0,\
	0,\
	0.0,\
	}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void MINPWLIM(TYPE_MINPWLIM *data);

#ifdef __cplusplus
}
#endif

typedef struct{
	float32 phase;//input
	float32 alpha;//output
	float32 beta;
	float32	Ts;//param
	float32	w0;
	float32 K;
	float32	Ki;
	float32 oldPhase1;//state
	float32 oldPhase2;
	float32 oldAlpha1;
	float32 oldAlpha2;
	float32 oldBeta1;
	float32 oldBeta2;
	float32 a;//local
	float32 b;
	float32 w;
	float32 peak;
	float32 ErrF;
	float32 ComW;
}TYPE_SOGIOSGMA;

#define SOGIOSGMA_DEFAULTS {\
	0.0,\
	0.0,\
	0.0,\
	1.0/1450.0/2.0,\
	100*3.1415926,\
	1.4142135,\
	10000,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	100*3.1415926,\
	0.0,\
	0.0,\
	0.0,\
	}


#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void SOGIOSGMA(TYPE_SOGIOSGMA *interface);
extern void SOGIOSGFLL(TYPE_SOGIOSGMA *interface);

#ifdef __cplusplus
}
#endif



typedef struct
{
	float32	XU_DcLk;//input
	float32	XI_DcLk;
	float32	XI_PhA;
	float32	XI_PhB;
	float32	XI_PhC;
	float32	XU_PhABLk;
	float32	XX_DutyA;//output
	float32	XX_DutyB;
	float32	XX_DutyC;
	Uint16	XX_Mode;
	float32	PT_Tsc;//param
	float32	XX_M;//
	float32 XX_MOvMd;
	float32	XX_Theta;//state

	TYPE_SVGEN svgen;
	TYPE_MINPWLIM minPwLim;
	TYPE_SOGIOSGMA sogiosg;
	TYPE_CLARKE	clarke;
	TYPE_PARK park;
	TYPE_LPFILTER	LpFilterU3PhPek;
	TYPE_LPFILTER	LpFilterU3PhIm;
	TYPE_PI_CONTROLLER U3PhCl;
	TYPE_PI_CONTROLLER F3PhSz;
	TYPE_PI_CONTROLLER U3PhSz;

	float32	XX_UPeakCom;
	float32 XX_AngleCom;

	float32	XU_3PhAl;
	float32	XU_3PhBe;
	float32	XU_3PhPek;/*3-phase output load voltage, phase-phase, peak value*/
	float32 XU_3PhRe;/*3-phase output load voltage, phase-phase, real part*/
	float32 XU_3PhIm;/*3-phase output load voltage, phase-phase, imaginary part*/
	float32 XU_3PhRms;/*3-phase output load voltage, phase-phase, RMS value*/
	float32 XT_U3Ph;/*Period time of measured 3-phase output load voltage*/

	float32	XI_PhPek;/*Phase current, peak value*/
	float32	XI_PhAct;/*Active phase current*/
	float32	XI_PhRct;/*Reactive phase current*/
	float32 XI_Ph1Rms;/*Phase current 1, RMS value*/
	float32 XI_Ph2Rms;/*Phase current 2, RMS value*/
	float32 XI_Ph3Rms;/*Phase current 3, RMS value*/
	float32 XI_PhReFix;/*Phase current, real part of fix projection*/
	float32 XI_PhImFix;/*Phase current, imaginary part of fix projection*/

	float32 XP_3Ph;/*3-phase output power*/
	float32 XQ_3Ph;/*3-phase output reactive power*/

	float32 XP_Ovp;/*OVP power*/
	float32 XH_Ovp_Est;/*Estimated OVP temperature*/
//	float32 WU_IPhClTrs;/*3-phase output load voltage reference manipulation,transient phase current control*/
//	float32 WU_IBtCgCl;/*3-Phase output load voltage manipulation from battery charger current control*/
//	float32 WU_OvMd;/*3-phase output load voltage manipulation due to over modulation*/
//	float32 WU_IPhClRms;/*3-phase output load voltage manipulation,RMS phase current limitation*/
//	float32 WU_Flt;/*Filtered voltage reference*/

	/*F3PhRef*/
	float32 WF_3PhDsp;/**/
	float32	WF_3PhU3PhRef;

	/*U3PhRef*/
	float32	WU_3PhUFRt;
	float32	WU_3PhExt;
	float32	PF_U3PhRef2;
	float32	PF_U3PhRef3;
	float32	PU_U3PhRef1;
	float32	PU_U3PhRef2;
	float32	PU_U3PhRef3;
	float32	PU_U3PhRef4;
	Uint16	L_ExtU3PhRef;
	float32	PX_ExtU3PhRefRmp;
	Uint16	L_EnRmpU3PhRef;
	float32	PX_U3PhRefRmpSel;
	float32	PX_U3PhRefRmp1;
	float32	PX_U3PhRefRmp2;

	/*U3PhCl*/
	float32	WU_3PhDsp;/**/
	Uint16	L_En3PhCl;
	Uint16	L_EnU3PhOpLoCl;
	Uint16	B_EnU3PhCl;
	float32	WU_3PhClIn;
	float32	WU_3PhCl;
	float32	PX_KpU3PhCl;
	float32	PT_U3PhCl;
	float32	PU_3PhClMax;
	float32	PU_3PhClMin;
	float32	PU_3PhClRefMax;
	float32	PU_3PhClRefMin;
	float32	PX_TrfRtPr3Ph;


	/*TFrefRmp*/
	float32 PX_FRefRmpUp;
	float32 PX_FRefRmpUpSlaveAcm;
	float32	PX_FRefRmpDo1;
	float32	PX_FRefRmpDo2;
	float32	PX_FRefRmpDo3;
	float32	PF_FRefRmpDo12;
	float32	PF_FRefRmpDo23;

	/**/
	float32 WF_3PhUDcLk;

	/*FrefRmp*/
	float32	WF_3PhRmp;
	float32	XX_FRefRmpUp;
	float32	XX_FRefRmpDo;
	float32	PF_3PhNom;
	float32	PF_3PhMin;
	Uint16	A_FNom;

	/*UF3PhCmp*/
//	float32	XI_PhAct;//local
//	float32	XI_PhRct;
	Uint16	A_CvOp;
	Uint16	L_EnUF3PhCmp;
	float32	PI_UF3PhCmpActHiLo;//param
	float32	PF_UF3PhCmpActHiLo;
	float32	PI_UF3PhCmpRctHiLo;
	float32	PU_UF3PhCmpRctHiLo;
	float32	WF_WF3PhCmp;
	float32	WU_UF3PhCmp;

	/*F3PhSz*/
	float32	WF_UF3PhSz;
	float32	PX_KpF3PhSzCl;
	float32 PT_F3PhSzCl;
	float32	PF_UF3PhSzClMaxMin;
	float32	PF_UF3PhSzRdy;
	float32	PT_UF3PhSzRmp;
	Uint16	C_AuSz;
	Uint16	A_AuSz;
	float32	PD_TrfSfPr3Ph;//变压器原边相电压与副边线电压相移


	/*U3PhSz*/
	float32	WU_UF3PhSz;
	float32	WU_UF3PhSzErr;
	float32	PU_UF3PhSzClAdd;
	float32	PU_UF3PhSzClMaxMin;
	float32	PU_UF3PhSzRdy;

	/**/
	float32	WF_IPhCl;

	/**/
	Uint16	C_CdAuLdCt;
	Uint16	A_CdAuLdCt;

	/**/
	Uint16	S_PaOp;
	Uint16	A_OvpCpOp;
	Uint16	A_BtCpOp;

	float32 PU_3PhBusAct;
	float32 PU_3PhBusIdle;

}TYPE_UFCOMA;

#define UFCOMA_DEFAULTS	{\
	0,/**/\
	0,\
	0,\
	0,\
	0,\
	0,\
	0.5,/**/\
	0.5,\
	0.5,\
	0,\
	1.0/2700.0,/**/\
	0.0,\
	0.0,\
	0.0,\
	SVGEN_DEFAULTS,\
	MINPWLIM_DEFAULTS,\
	SOGIOSGMA_DEFAULTS,\
	CLARKE_DEFAULTS,\
	PARK_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	0,0,\
	0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,\
	0,0,\
	0,0,\
	0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,\
	0,\
	0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,\
	0,0,0,0,0,0,0,0,0,\
	0,0,0,0,0,\
	0,\
	0,0,\
	0,0,0,\
	}

extern TYPE_UFCOMA acmctrl;

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void UFCOMAInit(void);
extern void UFCOMAStep(void);
extern void UFCOMATerm(void);

extern void DspStep(void);

void F3PhRef(void);
void U3PhRef(void);
void U3PhCl(void);

void TFrefRmp(void);
void FrefUDcLk(void);
void FrefRmp(void);

void UF3PhCmp(void);

void F3PhSz(void);
void U3PhSz(void);
void UF3PhSz(void);

void IPhClGenOvLd(void);
void IPhClPsTrs(void);

extern void OvMd(void);
extern void SVPWM(void);

extern float32	Min(float32	a,float32 b);
extern float32	Max(float32	a,float32 b);
extern float32	Limit(float32 x,float32 low,float32 up);

#ifdef __cplusplus
}
#endif



#endif /* UFCTRL_H_ */
