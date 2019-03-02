/*****************************************************************************
* COPYRIGHT : (c) 2017 Bombardier Transportation BTPC
*****************************************************************************
**
MODULE : MVB_Red_DCU.h
**
ABSTRACT : Interface definition for resource 'MVB_Red_DCU'
**
CREATOR : PMAKE 4.0.0.5
**
REMARKS : ANY CHANGES TO THIS FILE WILL BE LOST !!!
*
****************************************************************************/
#ifndef MVB_RED_DCU_H
#define MVB_RED_DCU_H
#ifndef TARGET_SIM_DLL
#include "mwt_types.h"
#include "usertypes.h"
#endif
typedef struct dataBlock_MVB_Red_DCU
{}
TYPE_MVB_RED_DCU_IF;
#ifdef __cplusplus
extern "C" {
#endif
void MVB_Red_DCU(TYPE_MVB_RED_DCU_IF *interface);
#ifdef __cplusplus
}
#endif
#endif /* MVB_RED_DCU_H */
