/*
 * acclma.h
 *
 *  Created on: 2019-2-18
 *      Author: 700363
 */

#ifndef ACCLMA_H_
#define ACCLMA_H_

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

#include "IQmathLib.h"
#include "clarke.h"
#include "park.h"
#include "ipark.h"
#include "pi.h"
#include "svgen.h"

typedef struct ACCLMA_IF
{
	float32	XI_PhAlpha;//input
	float32 XI_PhBeta;
	float32 XU_PhAlphaGt;
	float32	XU_PhBetaGt;
	float32	XI_PhAlphaGt;
	float32	XI_PhBetaGt;
	float32	XU_PhAlphaLk;
	float32	XU_PhBetaLk;
	float32	XU_DcLk;
	float32	XX_DutyA;//output
	float32 XX_DutyB;
	float32	XX_DutyC;
	float32 XX_Ts;//parameter
	float32	XF_3Ph;
	float32 XU_3PhPek;
	float32 XX_M;
	float32 XX_Theta;//variable
	CLARKE	clarke;
	PARK	park;
	PI_CONTROLLER	acr;
	PI_CONTROLLER	aur;
	IPARK	ipark;
	SVGEN	svgen;
}TYPE_ACCLMA_IF;

#define ACCLMA_IF_DEFAULTS {\
	0.0,	/**/			\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	0.5,\
	0.5,\
	0.5,\
	1.0/1450.0/2.0,\
	0.0,\
	0.0,\
	0.0,\
	0.0,\
	CLARKE_DEFAULTS,\
	PARK_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	PI_CONTROLLER_DEFAULTS,\
	IPARK_DEFAULTS,\
	SVGEN_DEFAULTS,\
	}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void ACCLMA(TYPE_ACCLMA_IF *interface);

#ifdef __cplusplus
}
#endif

#endif /* ACCLMA_H_ */
