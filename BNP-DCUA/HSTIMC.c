/*****************************************************************************
* COPYRIGHT : (c) 2004 Bombardier Transportation
******************************************************************************
* PROJECT : DCU2 - MCU/LIB
**
MODULE : HSTIMC.c
**
ABSTRACT : This module sends parameters from the MCU to the DSP
**
REMARKS : Version 0.0.1.1 of mcu2c containing this resource has been
* adapted to the function_template.c requirements of version
* 1.3.0.0 of the MTPE. Care must be taken to handle future
* adaptations.
*
******************************************************************************
* HISTORY :
**
1 04-10-05 13:07 Bertil Soderberg
* First version.
* 0.0.0.6 05-01-19 15:46 Bertil Soderberg
* Handling of communication area pointers.
* 0.0.0.7 05-01-31 13:46 Bertil Soderberg
* Sequence number put last in buffer (exchanged with checksum)
* 0.0.1.1 05-03-16 11:07 Bertil Soderberg
* Adapted to function_template.c of MTPE 1.3.0.0.
* 0.0.1.2 05-04-04 10:40 Bertil Soderberg
* Actual data transfer now placed in dsp_handler/dsp_transfer
* 0.0.3.7 05-07-04 15:57 Bertil Soderberg
* Interface signals changed from UINT32 to MWT_UDINT
* 3.0.0.0 09-02-20 Anders Persson
* #include TBD.H was deleted
*
******************************************************************************/
/*****************************************************************************
* INCLUDES
*/
#ifdef TARGET_SIM_DLL
#define aligned(i) 0
#define packed 0
#define __attribute__(a)
#include "../clib.h"
#include "../mwt_types.h"
#include "../firmware.h"
#endif
#include "rts_api.h"
#include "typedef.h"
#include "hw.h"
#include "dspIfaceApi.h"
#include "dspBinFile.h"
#include "HSTIMC.h"
/*#include "TBD.h"*/
/*****************************************************************************
* EXTERNAL FUNCTION PROTOTYPES
*/
/*****************************************************************************
* DESCRIPTION
*/
/*****************************************************************************
* DEFINES
*/
/*****************************************************************************
* TYPEDEFS
*/
/*****************************************************************************
* GLOBALS
*/
extern COM_AREA_STRUCT dspComArea[] ;
extern MWT_UDINT *hstip ;
/*****************************************************************************
* LOCALS
*/
/*****************************************************************************
* LOCAL FUNCTIONS
*/
/*
---------------------------------------------------------------------------
HSTIMC
---------------------------------------------------------------------------
Abstract:
This function sets a pointer to be used by dsp_transfer when
actually fetching the array of data from the DSP to the MCU
---------------------------------------------------------------------------
Parameters:
*data a pointer to the interface structure of the resource
---------------------------------------------------------------------------
Return value:
---------------------------------------------------------------------------
*/
void HSTIMC(TYPE_HSTIMC_IF* data)
{
hstip = &data->HSTIMC_Sig1 ; /* area starts with the first signal */
}
