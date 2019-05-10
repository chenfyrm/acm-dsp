#ifndef ACM_DSP_H
#define ACM_DSP_H

#ifdef __cplusplus
extern "C" {
#endif

/*DEFINES*/
#define	TWObyTHREE	  	0.66666666666667       /* 2/3 */
#define ONEbySQRT3		0.57735026918963    /* 1/sqrt(3) */
#define SQRT3byTWO   	0.86602540378444    /* sqrt(3)/2 */
#define SQRT3   		1.73205080756888    /* sqrt(3)/2 */
#define	SQRT2			1.41421356237310
#define	PI  		  	3.14159265358979
#define	PI2  		  	6.28318530717959
#define FALSE			0
#define	TRUE			1

/*TYPEDEFS*/
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int int16;
typedef long int32;
typedef long long int64;
typedef unsigned int Uint16;
typedef unsigned long Uint32;
typedef unsigned long long Uint64;
typedef float float32;
#endif

typedef struct {
	float32 re;
	float32 im;
} cfloat32;

/*STRUCTDEFS*/
struct Dsp_Data {
	/*HSTIDA*/
	float32 XU_DcLk; //input
	float32 XI_DcLk;
	float32 XI_PhA;
	float32 XI_PhB;
	float32 XI_PhC;
	float32 XU_PhABLk;
	float32 WF_3Ph;
	float32 WU_3Ph;

	/*HSTODA*/
	float32 XX_DutyA; //output
	float32 XX_DutyB;
	float32 XX_DutyC;
	Uint16 XX_Mode;

//	float32	XX_UPeakCom;
//	float32 XX_AngleCom;

	/*SIPRDA*/
	float32 XI_PhReFix;
	float32 XI_PhImFix;
	cfloat32 XI_PhAB;
	float32 XP_3Ph;
	float32 XQ_3Ph;
	float32 XI_PhAbs;
	float32 XI_PhAct;
	float32 XI_PhRct;
	cfloat32 XI_PhDQ;
	float32 WX_Theta;
	float32 XT_U3Ph;/*Period time of measured 3-phase output load voltage*/

	float32 XU_3PhRms;/*3-phase output load voltage, phase-phase, RMS value*/
	float32 XU_3PhRe;/*3-phase output load voltage, phase-phase, real part*/
	float32 XU_3PhIm;/*3-phase output load voltage, phase-phase, imaginary part*/
	float32 XU_3PhAbs;/*3-phase output load voltage, phase-phase, peak value*/

	float32 XU_DcLkDy;
	float32 XU_DcLkFlt;
	float32 WU_3PhAbs_Flt;

	float32 XI_PhAct_Flt;
	float32 XI_PhRct_Flt;
	float32 XI_PhAct_Flt2;
	float32 XI_PhRct_Flt2;
	float32 XI_PhAbs_Flt;
	cfloat32 XI_PhDQ_Flt;
	float32 XP_3Ph_Flt;
	float32 XQ_3Ph_Flt;

	/*ACCLDA*/
	float32 WU_IPhClTrs;/*3-phase output load voltage reference manipulation,transient phase current control*/
	Uint16 S_IPhClTrsAv :1;
	float32 WU_IPhClTrs_Flt;

	float32 XI_Ph1Rms;
	float32 XI_Ph2Rms;
	float32 XI_Ph3Rms;

	float32 WU_IPhClRms;
	Uint16 B_LimAct;

	/*UFCODA*/
	float32 WX_ThetaCv;
	float32 WU_Ref_Abs;

	Uint16 S_3PhOvMd :1;
	float32 WU_OvMd;/*3-phase output load voltage manipulation due to over modulation*/
	float32 WU_3PhAbsOvMd;
	float32 WU_IPhClRmsRed;
	float32 WU_3PhAbs;
	cfloat32 WU_3PhAB;

	float32 XX_CrU;
	float32 XX_CrV;
	float32 XX_CrW;

	/*PPG3*/
	float32 XT_Tsc;

	/*SRTODA*/
	Uint16 A_CvOp :1;
	Uint16 A_OvpCpOp:1;
	Uint16 A_BtCpOp:1;

	/**/
	float32 XP_Ovp;/*OVP power*/
	float32 XH_Ovp_Est;/*Estimated OVP temperature*/

//	float32 WU_IPhClRms;/*3-phase output load voltage manipulation,RMS phase current limitation*/
//	float32 WU_Flt;/*Filtered voltage reference*/
};

struct Dsp_Param {
	float32 PN_IPhFixMcu_Flt;
};

struct Mcu_Data {
	float32 PT_Tsc;

	/*F3PhRef*/
	float32 WF_3PhDsp;/**/
	float32 WF_3PhU3PhRef;

	/*U3PhRef*/
	float32 WU_3PhUFRt;
	float32 WU_3PhExt;
	float32 PF_U3PhRef2;
	float32 PF_U3PhRef3;
	float32 PU_U3PhRef1;
	float32 PU_U3PhRef2;
	float32 PU_U3PhRef3;
	float32 PU_U3PhRef4;
	Uint16 L_ExtU3PhRef;
	float32 PX_ExtU3PhRefRmp;
	Uint16 L_EnRmpU3PhRef;
	float32 PX_U3PhRefRmpSel;
	float32 PX_U3PhRefRmp1;
	float32 PX_U3PhRefRmp2;

	/*U3PhCl*/
	float32 WU_3PhDsp;/**/
	Uint16 L_En3PhCl;
	Uint16 L_EnU3PhOpLoCl;
	float32 WU_3PhClIn;
	float32 WU_3PhCl;
	float32 PX_KpU3PhCl;
	float32 PT_U3PhCl;
	float32 PU_3PhClMax;
	float32 PU_3PhClMin;
	float32 PU_3PhClRefMax;
	float32 PU_3PhClRefMin;
	float32 PX_TrfRtPr3Ph;

	/*TFrefRmp*/
	float32 PX_FRefRmpUp;
	float32 PX_FRefRmpUpSlaveAcm;
	float32 PX_FRefRmpDo1;
	float32 PX_FRefRmpDo2;
	float32 PX_FRefRmpDo3;
	float32 PF_FRefRmpDo12;
	float32 PF_FRefRmpDo23;

	/**/
	float32 WF_3PhUDcLk;

	/*FrefRmp*/
	float32 WF_3PhRmp;
	float32 XX_FRefRmpUp;
	float32 XX_FRefRmpDo;
	float32 PF_3PhNom;
	float32 PF_3PhMin;


	/*UF3PhCmp*/
	//	float32	XI_PhAct;//local
	//	float32	XI_PhRct;

	Uint16 L_EnUF3PhCmp;
	float32 PI_UF3PhCmpActHiLo;	//param
	float32 PF_UF3PhCmpActHiLo;
	float32 PI_UF3PhCmpRctHiLo;
	float32 PU_UF3PhCmpRctHiLo;
	float32 WF_WF3PhCmp;
	float32 WU_UF3PhCmp;

	/*F3PhSz*/
	float32 WF_UF3PhSz;
	float32 PX_KpF3PhSzCl;
	float32 PT_F3PhSzCl;
	float32 PF_UF3PhSzClMaxMin;
	float32 PF_UF3PhSzRdy;
	float32 PT_UF3PhSzRmp;
	float32 PD_TrfSfPr3Ph;	//变压器原边相电压与副边线电压相移

	/*U3PhSz*/
	float32 WU_UF3PhSz;
	float32 WU_UF3PhSzErr;
	float32 PU_UF3PhSzClAdd;
	float32 PU_UF3PhSzClMaxMin;
	float32 PU_UF3PhSzRdy;

	float32 PU_3PhBusAct;
	float32 PU_3PhBusIdle;

	float32 WF_IPhCl;

	Uint16 A_CvOp:1;
	Uint16 A_OvpCpOp:1;
	Uint16 A_BtCpOp:1;
	Uint16 A_FNom:1;
	Uint16 C_AuSz:1;
	Uint16 A_AuSz:1;
	Uint16 B_EnU3PhCl:1;
};

//struct Mcu_Param {
//
//};

/**/
extern volatile struct Dsp_Data DspData;
extern volatile struct Dsp_Param DspParam;
extern volatile struct Mcu_Data McuData;
//extern volatile struct Mcu_Param McuParam;

/*DSP*/
/*IRQB*/
//逆变
extern void DspStep(void);
extern void DspInit(void);

extern void ANIN_B(void);
extern void CSIV_B(void);
extern void MEMS_B(void);
extern void POCP_B(void);
extern void CALI_B(void);
extern void SIPR_B(void);
extern void ACCL_B(void);
extern void BACC_B(void);
extern void UFCO_B(void);
extern void PPG3_B(void);
extern void LOGB_B(void);

extern float32 OvMd(float32 M1);
extern void SVPWM(float32 *DutyA, float32 *DutyB, float32 *DutyC,
		cfloat32 _3PhAB);

/*500us*/

/*1ms*/
extern void HSTI_T2(void);
extern void ACCL_T2(void);
extern void OVPT_T2(void);
extern void HSTO_T2(void);

/*100ms*/
extern void SFSU_T3(void);
extern void DIAG_T3(void);
extern void DCUI_T3(void);
extern void HSTP_T3(void);
extern void HWSS_T3(void);

/*MCU*/
extern void McuInit(void);
extern void McuStep(void);

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

/*math*/
extern void Delay(volatile float32 *Dy, float32 Src);
extern void LowPass(volatile float32 *Flt, float32 Src, float32 TsPerT1);
extern void CplxLowPass(cfloat32 *Flt, cfloat32 Src, float32 TsPerT1);

extern float32 Min(float32 a, float32 b);
extern float32 Max(float32 a, float32 b);
extern float32 Limit(float32 x, float32 low, float32 up);

extern void CPLX2FRAC(float32 *Re, float32 *Im, cfloat32 Z);
extern cfloat32 FRAC2CPLX(float32 Re, float32 Im);
extern cfloat32 CPLXCONJ(cfloat32 Z);
extern cfloat32 CPLXMULT(cfloat32 Z1, cfloat32 Z2);
extern cfloat32 CPLXMULT_SHFT(cfloat32 Z1, cfloat32 Z2, int32 m);
extern float32 CPLXNORM(cfloat32 Z);
extern cfloat32 CPLXSCA(cfloat32 Z1, float32 a);
extern cfloat32 CPLXSCA_SHFT(cfloat32 Z1, float32 a, int32 m);
extern cfloat32 CPLXSHFT(cfloat32 Z, int32 m);
extern cfloat32 CPLXSUB(cfloat32 Z1, cfloat32 Z2);
extern cfloat32 CPLXADD(cfloat32 Z1, cfloat32 Z2);
extern cfloat32 _PREVCPLX(cfloat32 Z);
extern cfloat32 CPLXDIVSCA(cfloat32 Z1, float32 F, int32 m);

extern cfloat32 PH3TOCPLX(float32 a, float32 b, float32 c);
extern void CPLXTO3PH(float32 *a, float32 *b, float32 *c, cfloat32 Z);
extern cfloat32 POL2CPLX(float32 r, float32 fi);

#ifdef __cplusplus
}
#endif /* extern "C" */

typedef struct {
	float32 phase;	//input
	float32 alpha;	//output
	float32 beta;
	float32 Ts;	//param
	float32 w0;
	float32 K;
	float32 Ki;
	float32 oldPhase1;	//state
	float32 oldPhase2;
	float32 oldAlpha1;
	float32 oldAlpha2;
	float32 oldBeta1;
	float32 oldBeta2;
	float32 a;	//local
	float32 b;
	float32 w;
	float32 peak;
	float32 ErrF;
	float32 ComW;
} TYPE_SOGIOSGMA;

#define SOGIOSGMA_DEFAULTS {\
	0.0,\
	0.0,\
	0.0,\
	1.0/1350.0/2.0,\
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

extern void SOGIOSGFLL(TYPE_SOGIOSGMA *interface);

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

#endif
