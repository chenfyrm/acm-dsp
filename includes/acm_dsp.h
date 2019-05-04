#ifndef ACM_DSP_H
#define ACM_DSP_H


#ifdef __cplusplus
extern "C" {
#endif

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

typedef struct
{
	float32	re;
	float32 im;
}cfloat32;

struct Dsp_Data
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
	float32	XX_Tsc;//param
	float32	XX_MRef;//
	float32	XX_MOvMd;//
	float32	XX_Theta;//state

	float32	XX_UPeakCom;
	float32 XX_AngleCom;

	/*SIPRDA*/
	float32 XI_PhReFix;
	float32 XI_PhImFix;
	cfloat32 XI_PhAB;
	float32 XP_3Ph;
	float32	XQ_3Ph;
	float32 XI_PhAbs;
	float32 XI_PhAct;
	float32	XI_PhRct;
	cfloat32 XI_PhDQ;
	float32 WX_Theta;

	float32 XT_U3Ph;/*Period time of measured 3-phase output load voltage*/
	float32	XU_3PhAl;
	float32	XU_3PhBe;

	float32	XU_3PhAbs;/*3-phase output load voltage, phase-phase, peak value*/
	float32 XU_3PhRe;/*3-phase output load voltage, phase-phase, real part*/
	float32 XU_3PhIm;/*3-phase output load voltage, phase-phase, imaginary part*/
	float32 XU_3PhRms;/*3-phase output load voltage, phase-phase, RMS value*/

	float32 XU_DcLkDy;
	float32 XU_DcLkFlt;

	float32 WU_3PhAbs_Flt;
	float32 XI_PhAbs_Flt;
	float32 XI_PhAct_Flt;
	float32	XI_PhRct_Flt;
	cfloat32 XI_PhDQ_Flt;
	float32 XP_3Ph_Flt;
	float32	XQ_3Ph_Flt;

	/**/
//	float32	XI_PhPek;/*Phase current, peak value*/
//	float32	XI_PhAct;/*Active phase current*/
//	float32	XI_PhRct;/*Reactive phase current*/
//	float32 XI_Ph1Rms;/*Phase current 1, RMS value*/
//	float32 XI_Ph2Rms;/*Phase current 2, RMS value*/
//	float32 XI_Ph3Rms;/*Phase current 3, RMS value*/
//	float32 XI_PhReFix;/*Phase current, real part of fix projection*/
//	float32 XI_PhImFix;/*Phase current, imaginary part of fix projection*/
//
//	float32 XP_3Ph;/*3-phase output power*/
//	float32 XQ_3Ph;/*3-phase output reactive power*/

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
	Uint16	L_ExtU3PhRef;
	Uint16	L_EnRmpU3PhRef;


	/*U3PhCl*/
	float32	WU_3PhDsp;/**/
	Uint16	L_En3PhCl;
	Uint16	L_EnU3PhOpLoCl;
	Uint16	B_EnU3PhCl;
	float32	WU_3PhClIn;
	float32	WU_3PhCl;



	/*TFrefRmp*/


	/**/
	float32 WF_3PhUDcLk;

	/*FrefRmp*/
	float32	WF_3PhRmp;
	float32	XX_FRefRmpUp;
	float32	XX_FRefRmpDo;
	Uint16	A_FNom;

	/*UF3PhCmp*/
//	float32	XI_PhAct;//local
//	float32	XI_PhRct;
	Uint16	A_CvOp;
	float32	WF_WF3PhCmp;
	float32	WU_UF3PhCmp;

	/*F3PhSz*/
	float32	WF_UF3PhSz;
	Uint16	C_AuSz;

	/*U3PhSz*/
	float32	WU_UF3PhSz;
	float32	WU_UF3PhSzErr;

	/**/
	float32	WF_IPhCl;

	/**/
	Uint16	C_CdAuLdCt;
	Uint16	A_CdAuLdCt;

	/**/
	Uint16	S_PaOp;

};

extern volatile struct Dsp_Data DspData;

struct Dsp_Param
{
	float32	PT_Tsc;//param


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

	Uint16	L_En3PhCl;
	Uint16	L_EnU3PhOpLoCl;
	Uint16	B_EnU3PhCl;

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



	/*FrefRmp*/

	float32	XX_FRefRmpUp;
	float32	XX_FRefRmpDo;
	float32	PF_3PhNom;
	float32	PF_3PhMin;
	Uint16	A_FNom;

	/*UF3PhCmp*/
	Uint16	A_CvOp;
	Uint16	L_EnUF3PhCmp;
	float32	PI_UF3PhCmpActHiLo;//param
	float32	PF_UF3PhCmpActHiLo;
	float32	PI_UF3PhCmpRctHiLo;
	float32	PU_UF3PhCmpRctHiLo;

	/*F3PhSz*/
	float32	PX_KpF3PhSzCl;
	float32 PT_F3PhSzCl;
	float32	PF_UF3PhSzClMaxMin;
	float32	PF_UF3PhSzRdy;
	float32	PT_UF3PhSzRmp;
	Uint16	C_AuSz;
	float32	PD_TrfSfPr3Ph;//变压器原边相电压与副边线电压相移

	/*U3PhSz*/
	float32	PU_UF3PhSzClAdd;
	float32	PU_UF3PhSzClMaxMin;
	float32	PU_UF3PhSzRdy;

	/**/

	/**/
	Uint16	C_CdAuLdCt;
	Uint16	A_CdAuLdCt;

	/**/
	Uint16	S_PaOp;
	/**/
	float32 PX_3PhClRtHgh;
	float32	PX_3PhClRtLow;
	float32 PX_3PhClRtMin;
	float32 PX_3PhClRtMax;


};

extern volatile struct Dsp_Param DspParam;

extern void DspStep(void);

extern void SIPRDA(void);
extern void ACCLDA(void);
extern void UFCODA(void);
extern void OvMd(void);
extern void SVPWM(void);
//extern void LimPulse();

struct Mcu_Data
{

};

extern volatile struct Mcu_Data McuData;

struct Mcu_Param
{

};

extern volatile struct Mcu_Param McuParam;

extern float32 LowPass(float32 oldFlt,float32 Src,float32 TsPerT1);
extern cfloat32 CplxLowPass(cfloat32 oldFlt,cfloat32 Src,float32 TsPerT1);

extern float32	Min(float32	a,float32 b);
extern float32	Max(float32	a,float32 b);
extern float32	Limit(float32 x,float32 low,float32 up);



#ifdef __cplusplus
}
#endif /* extern "C" */

#endif
