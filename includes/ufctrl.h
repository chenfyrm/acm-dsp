/*
 * acclma.h
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#ifndef UFCTRL_H_
#define UFCTRL_H_

/**/
//#define	 TWObyTHREE	  0.66666666666667       /* 2/3 */
#define ONEbySQRT3		0.57735026918963    /* 1/sqrt(3) */
#define SQRT3byTWO   	0.86602540378444    /* sqrt(3)/2 */
#define SQRT3   		1.73205080756888    /* sqrt(3)/2 */
#define	PI  		  	3.14159265358979

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

/*
 * RAMP
 * */
typedef struct RAMP
{
	float32	XX_In;
	float32 XX_Out;
	float32	XX_Step;
}TYPE_RAMP;

#define RAMP_DEFAULTS {\
	0.0,\
	0.0,\
	0.1,\
	}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void RAMP(TYPE_RAMP *interface);

#ifdef __cplusplus
}
#endif

/**/
typedef struct{
	float32 phase;//input
	float32	theta;//output
	float32	Upeak;
	float32	w;
	float32	Ts;//param
	float32	w0;
	float32 K;
	float32 T_dFlt;
	float32 oldPhase1;//state
	float32 oldPhase2;
	float32 oldAlpha1;
	float32 oldAlpha2;
	float32 alpha;//local
	float32 beta;
	float32 dFlt;
	float32 a;
	float32 b;
	TYPE_PARK	park;
	TYPE_PI_CONTROLLER	aqr;
}TYPE_DOSGPLL_IF;

#define DOSGPLL_IF_DEFAULTS {\
	0.0,\
	0.0,\
	1.0,\
	1.0,\
	1.0/1450.0/2.0,\
	100*3.1415926,\
	1.4142135,\
	0.003,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	PARK_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	}


#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void DOSGPLL(TYPE_DOSGPLL_IF *interface);
extern void DOSGPLL_1(TYPE_DOSGPLL_IF *interface);

#ifdef __cplusplus
}
#endif

/**/
typedef struct
{
	float32	phase;//
	float32	alpha;//
	float32	w;//
	float32	k;
	float32	Tsc;
	float32	oldPhase1;//
	float32	oldPhase2;
	float32	oldAlpha1;
	float32	oldAlpha2;
	float32	a;//
	float32	b;
}TYPE_BPFILTER;

#define	BPFILTER_DEFAULTS	{\
	0,\
	0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void BPFILTER(TYPE_BPFILTER *data);

#ifdef __cplusplus
}
#endif

/*死区补偿*/
typedef struct
{
	float32	Ia;//input
	float32	Ib;
	float32 Ic;
	Uint16	mode;
	float32	TaCom;//output
	float32	TbCom;
	float32	TcCom;
	float32	dt;//param
}TYPE_DEADTIMECOM;

#define	DEADTIMECOM_DEFAULTS	{\
	0,\
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

extern void DEADTIMECOM(TYPE_DEADTIMECOM *data);
extern void DEADTIMECOM_1(TYPE_DEADTIMECOM *data);

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

/*
 *
 * */

typedef struct UFCTRL_IF
{
	float32 WU_3PhDsp;//input
	float32	WF_3PhDsp;
	float32	XI_PhA;
	float32 XI_PhB;
	float32 XI_PhC;
	float32	XU_DcLk;
	float32 XI_DcLk;
	float32	XU_PhAB;
	Uint16	XX_Mode;//output 0(0x000000):计数器值小于比较器值为高    21(0x010101):计数器值大于比较器值为高
	float32	XX_DutyA;
	float32 XX_DutyB;
	float32	XX_DutyC;
	float32 XX_Ts;//parameter
	float32 XX_UPeakCom;//幅值补偿系数
	float32 XX_AngleCom;//相位补偿系数
	float32 XU_3PhPek;//local
	float32	XF_3Ph;
	float32 XX_Theta;
	float32 XX_M;
	float32 XI_Act3Ph;
	float32 XI_Rct3Ph;
	float32 XI_Act3PhFlt;
	float32 XI_Rct3PhFlt;
	float32 XU_PhAl;
	float32 XU_PhBe;
	float32 XU_Act3Ph;
	float32 XU_Rct3Ph;
	float32 XU_Act3PhFlt;
	float32 XU_Rct3PhFlt;
	TYPE_CLARKE	clarke;
	TYPE_PARK	park;
	TYPE_DOSGPLL_IF	dosgpll;
	TYPE_RAMP rampId;
	TYPE_RAMP rampIq;
	TYPE_LPFILTER	LpFilterId;
	TYPE_LPFILTER	LpFilterIq;
	TYPE_LPFILTER	LpFilterUd;
	TYPE_LPFILTER	LpFilterUq;
	TYPE_PI_CONTROLLER	acrd;
	TYPE_PI_CONTROLLER	acrq;
	TYPE_PI_CONTROLLER	aurd;
	TYPE_PI_CONTROLLER	aurq;
	TYPE_IPARK	ipark;
	TYPE_SVGEN	svgen;
	TYPE_BPFILTER		BpFilterIa;
	TYPE_BPFILTER		BpFilterIb;
	TYPE_BPFILTER		BpFilterIc;
	TYPE_DEADTIMECOM	dtCom;
	TYPE_MINPWLIM		minPwLim;
	float32	RefId;
	float32	RefIq;
}TYPE_UFCTRL_IF;

#define UFCTRL_IF_DEFAULTS {\
	0.0,	/**/			\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0,/**/\
	0.5,\
	0.5,\
	0.5,\
	1.0/1450.0/2.0,/**/\
	1.0,\
	-3.1415926/2,\
	0.0,/**/\
	5.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	CLARKE_DEFAULTS,/**/\
	PARK_DEFAULTS,\
	DOSGPLL_IF_DEFAULTS,\
	RAMP_DEFAULTS,\
	RAMP_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	IPARK_DEFAULTS,\
	SVGEN_DEFAULTS,\
	BPFILTER_DEFAULTS,\
	BPFILTER_DEFAULTS,\
	BPFILTER_DEFAULTS,\
	DEADTIMECOM_DEFAULTS,\
	MINPWLIM_DEFAULTS,\
	0.0,\
	0.0,\
	}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void UFCTRLINIT(TYPE_UFCTRL_IF *data);
extern void UFCTRLOpenLoop(TYPE_UFCTRL_IF *interface);
extern void UFCTRLSingleLoop(TYPE_UFCTRL_IF *interface);
extern void UFCTRLDoubleLoop(TYPE_UFCTRL_IF *interface);

#ifdef __cplusplus
}
#endif


#endif /* UFCTRL_H_ */
