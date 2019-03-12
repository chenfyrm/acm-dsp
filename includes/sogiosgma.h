#ifndef SOGIOSGMA_H
#define SOGIOSGMA_H

//#ifndef DSP28_DATA_TYPES
//#define DSP28_DATA_TYPES
//typedef int                int16;
//typedef long               int32;
//typedef long long          int64;
//typedef unsigned int       Uint16;
//typedef unsigned long      Uint32;
//typedef unsigned long long Uint64;
//typedef float              float32;
//#endif
#include "typedefs.h"

typedef struct{
	float32 phase;//input
	float32 alpha;//output
	float32 beta;
	float32	Ts;//param
	float32	w;
	float32 K;
	float32 oldPhase1;//state
	float32 oldPhase2;
	float32 oldAlpha1;
	float32 oldAlpha2;
	float32 oldBeta1;
	float32 oldBeta2;
	float32 a;//local
	float32 b;
}TYPE_SOGIOSGMA_IF;

#define SOGIOSGMA_IF_DEFAULTS {\
	0.0,\
	0.0,\
	0.0,\
	1.0/1450.0/2.0,\
	100*3.1415926,\
	1.4142135,\
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

extern void SOGIOSGMA(TYPE_SOGIOSGMA_IF *interface);

#ifdef __cplusplus
}
#endif


#endif
