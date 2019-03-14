#ifndef DOSGPLL_H
#define DOSGPLL_H

#include "typedefs.h"
#include "IQmathLib.h"
#include "park.h"
#include "pi_ctrl.h"

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
	PARK	park;
	PI_CONTROLLER	aqr;
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

#ifdef __cplusplus
}
#endif


#endif
