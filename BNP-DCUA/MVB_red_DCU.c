/*****************************************************************************
* COPYRIGHT : (c) 2006 Bombardier Transportation BTPC
*****************************************************************************
**
MODULE : MVB_red_DCU.c
**
ABSTRACT :
**
PARAMETERS :
**
CREATOR : PPC/ESV: Christer Ohlsson
**
REMARKS :
*
****************************************************************************/
#include "MVB_Red_DCU.h"
#include "tcn.h"
/* Global references */
/* */
void MVB_Red_DCU(TYPE_MVB_RED_DCU_IF *interface)
{
lp_redundancy(0, LP_RED_ACTIVE);
}
