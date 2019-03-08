#ifndef SRFPLL_H
#define SRFPLL_H

#include "typedefs.h"
#include "IQmathLib.h"
#include "park.h"
#include "pi_ctrl.h"

typedef struct{
	float32	alpha;//input
	float32	beta;
	float32	theta;//output
	float32	Upeak;
	float32	w;
	flaot32	w0;//param
	PARK	park;//local
	PI_CONTROLLER	aqr;
}TYPE_SRFPLL_IF;

#define SRFPLL_IF_DEFAULTS	{\
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

extern void SRFPLL(TYPE_SRFPLL_IF *interface);

#ifdef __cplusplus
}
#endif


#endif
