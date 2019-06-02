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
#define SQRT2bySQRT3    0.816397228637413   /*sqrt(2/3)*/
#define	PI  		  	3.14159265358979
#define	PI2  		  	6.28318530717959
#define TRUE 1
#define FALSE 0

/*TYPEDEFS*/
#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef TRUE
#define TRUE (0==0)
#endif

#ifndef FALSE
#define FALSE (0!=0)
#endif

#ifndef NOT
#define NOT !
#endif

#ifndef AND
#define AND &&
#endif

#ifndef OR
#define OR ||
#endif

#ifndef OK
#define OK 0
#endif

#ifndef ERROR
#define ERROR (-1)
#endif

#ifndef INVALID
#define INVALID 1
#endif

#ifndef FAST
#define FAST register
#endif

#ifndef IMPORT
#define IMPORT extern
#endif

#ifndef LOCAL
#define LOCAL static
#endif

#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int int16;
typedef long int32;
typedef long long int64;
typedef unsigned int Uint16;
typedef unsigned long Uint32;
typedef unsigned long long Uint64;
typedef float float32;
typedef long double float64;
#endif

/*CCS编译器实现的char为16位，所以最小计量字节也为16位*/
typedef unsigned int BOOL;
typedef unsigned int WORD;
typedef unsigned long DWORD;

typedef void VOID;

//typedef INT16 CC_ANALOG;
//typedef UINT8 CC_BCD4;
//typedef INT16 CC_BIFRACT200;
//typedef UINT16 CC_BITSET256[16];
//typedef UINT8 CC_BOOL;
//typedef UINT8 CC_BOOLEAN2;
//typedef BYTE CC_BYTE;
//typedef UINT32 CC_DATE;
//typedef struct dt {UINT32 date; UINT16 ms;} CC_DATE_AND_TIME;
//typedef INT32 CC_DINT;
//typedef DWORD CC_DWORD;
//typedef UINT8 CC_ENUM4;
//typedef INT32 CC_FIXED;
//typedef INT16 CC_INT;
//typedef float CC_REAL;
//typedef INT8 CC_SINT;
//typedef char CC_STRING[81];
//typedef INT32 CC_TIME;
//typedef OS_TIMEDATE48 CC_TIMEDATE48;
//typedef INT32 CC_TIME_OF_DAY;
//typedef UINT32 CC_UDINT;
//typedef UINT16 CC_UINT;
//typedef UINT16 CC_UNIFRACT;
//typedef UINT8 CC_USINT;
//typedef WORD CC_WORD;

//typedef CC_ANALOG MWT_ANALOG;
//typedef CC_BCD4 MWT_BCD4;
//typedef CC_BIFRACT200 MWT_BIFRACT200;
//typedef CC_BOOL MWT_BOOL;
//typedef CC_BOOLEAN2 MWT_BOOLEAN2;
//typedef CC_BYTE MWT_BYTE;
//typedef CC_DATE MWT_DATE;
//typedef CC_DATE_AND_TIME MWT_DATE_AND_TIME;
//typedef CC_DINT MWT_DINT;
//typedef CC_DWORD MWT_DWORD;
//typedef CC_ENUM4 MWT_ENUM4;
//typedef CC_FIXED MWT_FIXED;
//typedef CC_INT MWT_INT;
//typedef CC_REAL MWT_REAL;
//typedef CC_SINT MWT_SINT;
//typedef CC_STRING MWT_STRING;
//typedef CC_TIME MWT_TIME;
//typedef CC_TIME_OF_DAY MWT_TIME_OF_DAY;
//typedef CC_TIMEDATE48 MWT_TIMEDATE48;
//typedef CC_UDINT MWT_UDINT;
//typedef CC_UINT MWT_UINT;
//typedef CC_UNIFRACT MWT_UNIFRACT;
//typedef CC_USINT MWT_USINT;
//typedef CC_WORD MWT_WORD;

typedef struct {
	float32 re;
	float32 im;
} cfloat32;

struct LOGICAL_BITS {
	Uint16 Logic :1;
	Uint16 PreLogic :1;
	Uint16 RTrig :1;
	Uint16 FTrig :1;
	Uint16 rsvd1 :12;
};

union LOGICAL {
	Uint16 all;
	struct LOGICAL_BITS bit;
};

typedef struct DLYONOFF_N {
	union LOGICAL logic;
	Uint16 Cnt;
} TYPE_DLYONOFF_N;

typedef struct DLYONOFF_T {
	Uint16 PreIn;
	float32 Tm;
} TYPE_DLYONOFF_T;

/*STRUCTDEFS*/
struct Dsp_Data {
	/*ANINDA*/
	float32 XU_DcLk; //input
	float32 XI_DcLk;
	float32 XI_PhA;
	float32 XI_PhB;
	float32 XI_PhC;
	float32 XU_PhABLk;

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
	float32 XF_U3Ph;/*Frequency of measured 3-phase output load voltage*/

	float32 XU_3PhSqu;
	float32 XU_3PhRms;/*3-phase output load voltage, phase-phase, RMS value*/
	float32 XU_3PhRe;/*3-phase output load voltage, phase-phase, real part*/
	float32 XU_3PhIm;/*3-phase output load voltage, phase-phase, imaginary part*/
	float32 XU_3PhAbs;/*3-phase output load voltage, phase-phase, peak value*/
	float32 XU_3PhAbs_Notch;

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
	Uint16 S_IPhClTrsAv;
	float32 WU_IPhClTrs_Flt;

	Uint16 XX_CntPh1Rms;
	Uint16 XX_CntPh2Rms;
	Uint16 XX_CntPh3Rms;
	float32 XI_Ph1Squ;
	float32 XI_Ph2Squ;
	float32 XI_Ph3Squ;
	float32 XI_Ph1Rms;
	float32 XI_Ph2Rms;
	float32 XI_Ph3Rms;
	float32 XI_Ph1Rms_Flt;
	float32 XI_Ph2Rms_Flt;
	float32 XI_Ph3Rms_Flt;

	float32 WU_IPhClRms;
	Uint16 B_LimAct;

	/*UFCODA*/
	cfloat32 WU_3PhSec;
	cfloat32 WU_3PhPm;
	cfloat32 WU_3PhPmAB;
	float32 XU_DcLkStbFltSli;
	float32 XU_DcLkStbFltHev;
	float32 WU_DcLkStb;
	float32 WX_ThetaCv;
	float32 WU_Ref_Abs;
	float32 XX_MRef; //base Udc

	Uint16 S_3PhOvMd;
	float32 WU_OvMd;/*3-phase output load voltage manipulation due to over modulation*/
	float32 WU_3PhAbsOvMd;
	float32 WU_IPhClRmsRed;
	float32 WU_3PhAbs;
	cfloat32 WU_3PhAB;

	float32 XX_CrU;
	float32 XX_CrV;
	float32 XX_CrW;
	Uint16 S_UDcLkLow;

	/*PPG3*/
	float32 XT_Tsc;
	Uint16 XX_PwmPdVv;
	float32 XX_DutyA; //output
	float32 XX_DutyB;
	float32 XX_DutyC;
	Uint16 XX_Mode;
	Uint16 L_DsPlElm3PhMod; //TRUE

	/*SRTODA*/
	Uint16 A_CvOp;

	/**/
	float32 XP_Ovp;/*OVP power*/
	float32 XH_Ovp_Est;/*Estimated OVP temperature*/

	/*MEMS*/
	Uint16 B_U3PhRmsPlySvFl; //三相输出电压合理性监视

	/*ACLS*/
	Uint16 B_IPhClTmWnd1Fl;
	Uint16 B_IPhClRmsTmFl;

	/*OVPT*/
	float32 XX_Duty4A;
	Uint16 C_OvpFcTs;
	Uint16 A_OvpFcTsOk;

	Uint16 A_BtCpAv;

	Uint16 A_OvpAv;
	Uint16 S_OvpEn;

	/**/
	Uint16 B_DspOvLdFl;
	Uint16 S_DspWdAlm;
	Uint16 S_DspFpgaComFl;
	Uint16 B_DspStkSvFl;

};

struct Dsp_Param {
	float32 PN_IPhFixMcu_Flt;
	float32 PN_U3PhRms_Flt;
	float32 PN_UDcLk_Flt;
	float32 PN_URef_Flt;
	float32 PN_IPhActRct_Flt;
	float32 PN_IPhActRctMcu_Flt;
	float32 PN_IPhAbs_Flt;
	float32 PN_PQ3PhMcu_Flt;
	float32 PN_IPhDQ_Flt;
	float32 PN_URefIPhClTrs_Flt;
	float32 PN_IPhRms_Flt;

	float32 PD_ThetaFiOs; //1.047

	float32 PU_PhClTrsMax; //	75
	float32 PI_PhClTrsAbsLim; //	600

	float32 PF_IRQBMax; //Dsp外部中断最大频率，计算最小间隔时间，计数单步时间

	float32 PX_DdCmpFa;
	float32 PI_DdCmpFu;
	float32 PI_DdCmpDs;

	float32 PX_3PhClRtHgh;
	float32 PX_3PhClRtLow;

	/**/
	float32 PZ_3PhFiNdRe; //	0,078 滤波电感电阻
	float32 PZ_3PhFiNdIm; //	0,207滤波电感电抗
	float32 PZ_3PhFiCaIm; //	-5,47 滤波电容电抗折算到一次侧
	float32 PZ_3PhTfRe; //	0
	float32 PZ_3PhTfIm; //	0
	cfloat32 PZ_3PhFiNd;
	cfloat32 PZ_3PhFiCa;
	cfloat32 PZ_3PhTf;

	Uint16 L_UDcLkStbEn; //	TRUE
	float32 PN_UDcLkStbSliSmt; //	2200
	float32 PN_UDcLkStbHevSmt; //	13,5
	float32 PU_DcLkStbMaxMin; //	100
	float32 PX_KpUDcLkStb;
	float32 PX_KpUDcLkVoStbFb;

	float32 PX_3PhRndMax; //	0,0345
	Uint16 L_3PhRndEn; //	TRUE
	float32 PF_3PhSg; //1350

	Uint16 L_EnTPrDdCmp;
	Uint16 L_DsPlElm3PhMod;

	//DUVP
	float32 PARTDP_PU_DcLkMin; //	1000

	//DOVP
	float32 PARTDP_PU_DcLkHgh4; //	1950

	//MEMS
	float32 PX_U3PhMmSvMax;	//0,9
	float32 L_U3PhRmsPlySv;	//TRUE
	float32 PU_U3PhRmsPlySvLim;	//35	V
	float32 PT_U3PhRmsPlySvDy;	//1	s

	//ACCL
	Uint16 L_EnIPhClRms;	//	FALSE
	float32 PI_PhClRmsLim;	//	800	A

};

struct Mcu_Data {
	/*ACCLMA*/
	/*IPhClGenOvLd 4ms*/
	float32 WF_IPhCl;
	Uint16 S_IPhClGenOvLdAv;

	/*IPhClPsTrs 4ms*/
	float32 WI_PhActDsp;
	float32 WI_PhRctDsp;

	float32 XX_IPhClTrsKpActDsp;
	float32 XX_IPhClTrsKpRctDsp;
	float32 XX_IPhClTrsKpAbsDsp;

	/*IPhDcCl*/
	float32 WU_IPhDcClDsp;

	/*COMPMA*/
	/*UF3PhCmp*/
	float32 WF_UF3PhCmp;
	float32 WU_UF3PhCmp;

	/*UFCOMA*/
	/*F3PhRef*/
	float32 WF_3PhDsp;/**/
	float32 WF_3PhU3PhRef;

	/*U3PhRef*/
	float32 WU_3PhU3PhRef;
	float32 WU_3PhRmp;
	float32 WU_3PhExt;

	/*U3PhCl*/
	float32 WU_3PhDsp;/**/
	float32 WU_3PhClIn;
	float32 WU_U3PhClOut;

	/*TFrefRmp 16ms*/
	float32 XX_FRefRmpUp;
	float32 XX_FRefRmpDo;

	/*FrefUDcLk 16ms*/
	float32 XU_DcLkFlt2;
	float32 WF_3PhUDcLk;

	/*FrefRmp 16ms*/
	float32 WF_3PhRmp;
	Uint16 A_FNom;
//	Uint16 A_FMin;

	/*AUSZMA*/
	/*F3PhSz 16ms*/
	float32 WF_UF3PhSz;
	float32 WF_UF3PhSzErr;

	/*U3PhSz 16ms*/
	float32 WU_UF3PhSz;
	float32 WU_UF3PhSzErr;

	/*UF3PhSz 16ms*/
	Uint16 A_AuSz;

	/*SRTOMA*/
	/*CvOpSaSq*/
	Uint16 C_Ck3PhGduFb;
	Uint16 C_CdAuLdCt;
	Uint16 C_CvOpSa;
	Uint16 C_AuSz;	//开始同步
	Uint16 NX_SqStCvOpSa;
	Uint16 A_CvOpSa;
	/*CvOpSoSq*/
	Uint16 C_CvBc;
	Uint16 C_CkSrCtI;	//(*Command check of current through contactors*)
	Uint16 C_OpAuLdCt;
	Uint16 C_OpChCt;
	Uint16 C_OpSrCt;
	Uint16 NX_SqStCvOpSo;
	Uint16 A_CvOpSo;
	/*CvOpSa_X*/
	Uint16 C_CvOpSaDsp;
	Uint16 C_Sa2qcDsp;
	Uint16 B_EnU3PhCl;	//开始闭环
	Uint16 B_EnU3PhOpLoCl;
	Uint16 B_EnUBtCl;
	Uint16 B_EnIBtCl;
	Uint16 A_CvCl;

	/*BAUCMA*/
	/*BtCpURef*/
	float32 WU_BtDsp;

	/*BTCPMA*/
	Uint16 B_RqBtCpSfBc;
	Uint16 B_RqBtCpPrBc;
	Uint16 B_RqBtCpSlt;
	Uint16 B_RqBtCpSa;
	Uint16 B_RqBtCpSo;
	Uint16 S_BtCpAv;

	/*OVPTMA*/
	Uint16 C_OvpFcTsDsp;

	Uint16 C_DspNt;
	Uint16 C_SaDsp;
	Uint16 C_RstDsp;
	Uint16 C_ResetDspDl;
	Uint16 B_DspRamTsSa;

	Uint16 B_FrOvpDsp;

	Uint16 NX_McuSqNo;

	/*ISCSMA*/
	Uint16 A_SrCtIOk;

	/*DIGIMA*/
	Uint16 A_CdAuLdCt;
	Uint16 A_CdChCt;
	Uint16 A_CdSrCt;

	/*ALCSMA*/
	Uint16 C_CdAuLdCt_ALCS;
	Uint16 B_RqPrBcReSa_ALCS;
	Uint16 B_3PhDsOpAuLdCt;

	Uint16 B_RqPrBc_ALCS;
	Uint16 B_AuLdCtOnFl;
	Uint16 B_AuLdCtOfFl;

	/*SFPAMA*/
	Uint16 A_GduFb3PhOk;

	/*SSSCMA*/
	Uint16 C_CvOpSa_MnSq;
	Uint16 C_CvOpSo_MnSq;
	Uint16 B_BcOpSrCt;	//通过打开分离接触器封锁

	/*DCCHMA*/
	Uint16 C_Sa2qc;

	/*DCDHMA*/
	Uint16 C_So2qc;

	/*CVISMA*/
	Uint16 B_RqCvBc;
	Uint16 C_So2qc_slt;

	/*PRSDMA*/
	Uint16 C_FpgaPrSd;

	/*FSSDMA*/
	Uint16 C_FpgaFsSd;

	/*SFSDMA*/
	Uint16 C_FpgSfSd;

	/*PRBCMA*/
	Uint16 C_FpgaPrBc;

	/*MEMSMA*/
	Uint16 B_EnU3PhOpLoCl_mem;

	/*IUCLMA*/
	Uint16 S_IdlAcmBu;

};

struct Mcu_Param {
	/*ACCLMA*/
	/*IPhClGenOvLd*/
	float32 PF_IPhClMin;	//	50
	float32 PF_IPhClMinErr;	//	25
	float32 PX_IPhClIntMax;	//	20000
	float32 PX_IPhClIntMin;	//	0
	float32 PT_IPhClInt;	//	100

	/*IPhClPsTrs*/
	float32 PI_IPhClActMax;	//	400
	float32 PI_IPhClActMin;	//	100
	float32 PI_IPhClActPsTrs;	//	450
	float32 PI_IPhClActOs;	//	100
	float32 PX_IPhClActDe;	//	200
	float32 PI_IPhClRctMax;	//400
	float32 PI_IPhClRctMin;	//0
	float32 PI_IPhClRctPsTrs;	//	300
	float32 PI_IPhClRctOs;	//100
	float32 PX_IPhClRctDePos;	//200
	float32 PX_IPhClRctDeNg;	//200
	float32 PI_IPhClPsTrsLim;	//	600
	float32 PX_IPhClTrsKpAct;	//	0,005
	float32 PX_IPhClTrsKpRct;	//	0,03
	float32 PX_IPhClTrsKpAbs;	//	0

	/*IPhDcCl*/
	Uint16 L_EnIPhDcCl;	//	TRUE
	float32 PU_IPhDcClMaxMin;	//	3
	float32 PX_KpIPhDcCl;	//	0,2
	float32 PX_KiIPhDcCl;	//	0,0001

	/*TFrefRmp*/
	float32 PX_FRefRmpUp;
	float32 PX_FRefRmpUpSlaveAcm;
	float32 PX_FRefRmpDo1;
	float32 PX_FRefRmpDo2;
	float32 PX_FRefRmpDo3;
	float32 PF_FRefRmpDo12;
	float32 PF_FRefRmpDo23;

	/*FrefUDcLk*/
	float32 PF_UDcLkMin;	//	50
	float32 PU_DcLkFRefMin;	//	1000
	float32 PU_DcLkFRefLow;	//	1000
	float32 PX_FRefRmpUDcLkUp;	//	40
	float32 PX_FRefRmpUDcLkDo;	//	40
	float32 PT_FRefUDcLk;	//100ms

	/*FrefRmp*/
	float32 PF_3PhNom;
	float32 PF_3PhMin;

	/*UF3PhCmp*/
	Uint16 L_EnUF3PhCmp;
	float32 PI_UF3PhCmpActHiLo;	//param
	float32 PF_UF3PhCmpActHiLo;
	float32 PI_UF3PhCmpRctHiLo;
	float32 PU_UF3PhCmpRctHiLo;

	/*F3PhSz*/
	float32 PX_KpF3PhSzCl;
	float32 PT_F3PhSzCl;
	float32 PF_UF3PhSzClMaxMin;
	float32 PT_UF3PhSzRmp;

	/*U3PhSz*/
	float32 PU_UF3PhSzClAdd;
	float32 PU_UF3PhSzClMaxMin;

	/*UF3PhSz*/
	float32 PF_UF3PhSzRdy;
	float32 PU_UF3PhSzRdy;
	float32 PT_UF3PhSzRdy;
	float32 PT_UF3PhSzFl;

	/*U3PhRef*/
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
	Uint16 B_En3PhClFqAda;
	Uint16 L_En3PhCl;
	Uint16 L_EnU3PhOpLoCl;
	float32 PX_KpU3PhCl;
	float32 PT_U3PhCl;
	float32 PU_3PhClMax;
	float32 PU_3PhClMin;
	float32 PU_3PhClRefMax;
	float32 PU_3PhClRefMin;
	float32 PX_TrfRtPr3Ph;

	/*CvOpSaSq*/
	float32 PU_3PhIdlCmp;
	float32 PU_3PhActCmp;

	/*CvOpSa*/
	Uint16 L_PrlAcm;	//	TRUE

	/*DCDS*/
//	PARTAP_PU_DhDcLk_Max	100	V
//	PARTAP_PT_DcLkDhDy	600	ms
//	PARTAP_PT_FrOvp	500	ms
//	PARTAP_L_EnDhDcLkCvSl	TRUE
//	PARTAP_PU_DcLkCvSlDh	1000	V
};

/**/
extern volatile struct Dsp_Data DspData;
extern volatile struct Dsp_Param DspParam;
extern volatile struct Mcu_Data McuData;
extern volatile struct Mcu_Param McuParam;

/*DSP*/
/*IRQB*/
//逆变
extern void DspInit(void);

extern void DspTask_185us(void);	//同步锁相

extern void DspTask_B(void);
extern void DspTask_C(void);
extern void DspTask_T2(void);
extern void DspTask_T3(void);

/*MCU*/
extern void McuInit(void);

extern void McuTask_4ms(void);
extern void McuTask_16ms(void);
extern void McuTask_64ms(void);
extern void McuTask_1024ms(void);

/*math*/
extern float32 Delay1(float32 In, volatile float32* PreIn);
extern float32 DelayN(float32 In, volatile float32* PreInArr32, Uint16 N);
extern void LowPass(volatile float32 *Flt, float32 Src, float32 TsPerT1);
extern void CplxLowPass(volatile cfloat32 *Flt, cfloat32 Src, float32 TsPerT1);
extern void RmsClc(volatile float32 *rms, float32 Src, Uint16 N,
		volatile float32 *Square, volatile Uint16 *cnt);
extern void RAMP2(volatile float32 *Y, float32 X, float32 Dr, float32 Df,
		float32 Init, Uint16 Set, Uint16 Hold);
extern void RAMP(volatile float32 *Y, float32 X, float32 TsPerTr,
		float32 TsPerTf, float32 Init, Uint16 Set, Uint16 Hold, float32 Max);
extern float32 Cycle(void);
extern void INTEGR(volatile float32 *Y, float32 X, float32 T, float32 Init,
		float32 Max, float32 Min, Uint16 Set, Uint16 Hold);
extern float32 FKG4(float32 X, float32 X1, float32 Y1, float32 X2, float32 Y2,
		float32 X3, float32 Y3, float32 X4, float32 Y4);
extern float32 PIREG();

extern float32 Min(float32 a, float32 b);
extern float32 Max(float32 a, float32 b);
extern float32 Limit(float32 x, float32 low, float32 up);

extern void CPLX2FRAC(volatile float32 *Re, volatile float32 *Im, cfloat32 Z);
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

extern cfloat32 CPLXDIV(cfloat32 Z1, cfloat32 Z2);
extern void CPLX2POL(volatile float32 *r, volatile float32 *fi,
		volatile cfloat32 Z);

extern cfloat32 PH3TOCPLX(float32 a, float32 b, float32 c);
extern void CPLXTO3PH(volatile float32 *a, volatile float32 *b,
		volatile float32 *c, cfloat32 Z);
extern cfloat32 POL2CPLX(float32 r, float32 fi);

/*Logical*/
extern Uint16 RTRIG(Uint16 In, volatile Uint16* PreIn);
extern Uint16 FTRIG(Uint16 In, volatile Uint16* PreIn);
extern void RS(volatile Uint16* Q, Uint16 Set, Uint16 Reset);
extern void SR(volatile Uint16* Q, Uint16 Set, Uint16 Reset);
extern Uint16 DLYON_N(Uint16 In, Uint16 N, volatile TYPE_DLYONOFF_N* data);
extern Uint16 DLYOFF_N(Uint16 In, Uint16 N, volatile TYPE_DLYONOFF_N* data);
extern Uint16 DLYON_T(Uint16 In, float32 T, volatile TYPE_DLYONOFF_T* data,
		float32 CT);
extern Uint16 DLYOFF_T(Uint16 In, float32 T, volatile TYPE_DLYONOFF_T* data,
		float32 CT);
extern Uint16 MONO(Uint16 In, Uint16 N, volatile TYPE_DLYONOFF_N* data);

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
typedef struct {
	float32 Ref;   			// Input: reference set-point
	float32 Fbk;   			// Input: feedback
	float32 Out;   			// Output: controller output
	float32 Kp;				// Parameter: proportional loop gain
	float32 Ki;			    // Parameter: integral gain
	float32 Umax;			// Parameter: upper saturation limit
	float32 Umin;			// Parameter: lower saturation limit
	float32 up;				// Data: proportional term
	float32 ui;				// Data: integral term
	float32 v1;				// Data: pre-saturated controller output
	float32 i1;				// Data: integrator storage: ui(k-1)
	float32 w1;				// Data: saturation record: [u(k-1) - v(k-1)]
} TYPE_PI_CONTROLLER;

/*-----------------------------------------------------------------------------
 Default initalisation values for the PI_GRANDO objects
 -----------------------------------------------------------------------------*/

#define PI_CONTROLLER_DEFAULTS {		\
	0, 		\
	0, 		\
	0, 		\
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

typedef struct {
	float32 In;				//input
	float32 Out;				//output
	float32 a1;				//param
	float32 a2;
	float32 b0;
	float32 b1;
	float32 b2;
	float32 oldIn1;				//state
	float32 oldIn2;
	float32 oldOut1;
	float32 oldOut2;
} TYPE_IIRFILTER_2ND;

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void IIRFilter_2nd(TYPE_IIRFILTER_2ND *data);
extern void AdaptIIRNotchFilter(TYPE_IIRFILTER_2ND *data, float32 W0,
		float32 Ts);

#ifdef __cplusplus
}
#endif

extern TYPE_SOGIOSGMA sogiosg;
extern TYPE_IIRFILTER_2ND U3PhRe, U3PhIm;
extern TYPE_PI_CONTROLLER PI_F3PhSz;
extern TYPE_PI_CONTROLLER PI_U3PhCl;

#endif
