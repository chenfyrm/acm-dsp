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
	float32 XX_M;
	float32 XX_Theta;//variable
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
	}

typedef struct AUR_IF
{
	float32 Ref;
	float32 Fbk;
}TYPE_AUR_IF;

typedef struct ACR_IF
{
	float32 Ref;
	float32	Fbk;
}TYPE_ACR_IF;

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void AUR(TYPE_AUR_IF *interface);
extern void ACR(TYPE_ACR_IF *interface);

extern void ACCLMA(TYPE_ACCLMA_IF *interface);

#ifdef __cplusplus
}
#endif

#endif /* ACCLMA_H_ */
