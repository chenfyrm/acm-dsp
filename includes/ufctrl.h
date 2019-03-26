/*
 * acclma.h
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#ifndef UFCTRL_H_
#define UFCTRL_H_

#include "typedefs.h"
#include "IQmathLib.h"
#include "clarke.h"
#include "park.h"
#include "ipark.h"
#include "pi_ctrl.h"
#include "svgen.h"
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
	float32 XU_PhAl;
	float32 XU_PhBe;
	float32	XU_DcLk;
	float32 XI_DcLk;
	float32	XX_DutyA;//output
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
	float32 XU_Act3Ph;
	float32 XU_Rct3Ph;
	float32 XU_Act3PhFlt;
	float32 XU_Rct3PhFlt;
	CLARKE	clarke;
	PARK	park;
	TYPE_RAMP rampId;
	TYPE_RAMP rampIq;
	TYPE_LPFILTER	LpFilterId;
	TYPE_LPFILTER	LpFilterIq;
	TYPE_LPFILTER	LpFilterUd;
	TYPE_LPFILTER	LpFilterUq;
	PI_CONTROLLER	acrd;
	PI_CONTROLLER	acrq;
	PI_CONTROLLER	aur;
	IPARK	ipark;
	SVGEN	svgen;
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
	0.0,\
	0.5,/**/\
	0.5,\
	0.5,\
	1.0/1450.0/2.0,/**/\
	1.0,\
	0.0,\
	0.0,/**/\
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
	RAMP_DEFAULTS,\
	RAMP_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	LPFILTER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	IPARK_DEFAULTS,\
	SVGEN_DEFAULTS,\
	}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void UFCTRLOpenLoop(TYPE_UFCTRL_IF *interface);
extern void UFCTRLSingleLoop(TYPE_UFCTRL_IF *interface);
extern void UFCTRLDoubleLoop(TYPE_UFCTRL_IF *interface);

#ifdef __cplusplus
}
#endif




#endif /* ACCLMA_H_ */
