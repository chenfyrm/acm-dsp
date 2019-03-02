/*****************************************************************************
* COPYRIGHT : (c) 2004 Bombardier Transportation
******************************************************************************
* PROJECT : DCU2 - MCU/LIB
**
MODULE : HSTPMC.c
**
ABSTRACT : This module sends parameters from the MCU to the DSP
**
REMARKS : Version 0.0.1.1 of mcu2c containing this resource has been
* adapted to the function_template.c requirements of version
* 1.3.0.0 of the MTPE. Care must be taken to handle future
* adaptations.
*
******************************************************************************
HISTORY :
0.0.0.4 04-12-13 11:00 Bertil Soderberg
Only send when a change has been detected
0.0.0.6 05-01-19 15:46 Bertil Soderberg
Handling of communication area pointers.
0.0.0.7 05-01-31 13:46 Bertil Soderberg
Sequence number put last in buffer (exchanged with checksum)
0.0.1.1 05-03-16 11:07 Bertil Soderberg
Adapted to function_template.c of MTPE 1.3.0.0.
0.0.1.2 05-04-04 10:40 Bertil Soderberg
Actual data transfer now placed in dsp_handler/dsp_transfer
0.0.3.1 05-06-09 14:06 Bertil Soderberg
New input signal, PARADP_B_ParCalcRdy, which shall force
the sending of the parameters when set high
0.0.3.2 05-06-14 10:31 Bertil Soderberg
New input signal, PARAGP_B_EnParChgDet, which enables the
detection of parameter changes to cause a sending
0.0.3.3 05-06-15 09:23 Bertil Soderberg
The input signal _SeqNoPar removed, the sequence number
generation handled internally by setting a global
variable SeqNoPar ;
new output signal (at least temporarily): _SeqNoPar,
reflecting the internally generated sequence number;
new input signal, DHWIMG_C_DspRst, which will cause the
parameter sequence number to be reset
0.0.4.1 05-09-30 10:31 Bertil Soderberg
The input signal _ParCalcRdy renamed to _ParCalcRd
Rev 2 09-09-04 13:45 Martin Torelm
The input PARADP_B_ParCalcRd changed name to PARPDP_B_ParCalcRd
CR_1527
******************************************************************************/
/*****************************************************************************
* INCLUDES
* */
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
#include "SymbFile.h"
#include "HSTPMC.h"
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
extern MWT_UDINT *hstpp ;
extern MWT_UDINT SeqNoPar ;
/*****************************************************************************
* LOCALS
*/
TYPE_HSTPMC_IF oldpars ;
/*****************************************************************************
* LOCAL FUNCTIONS
* */
LOCAL BOOL dcu2_mptd_check(TYPE_HSTPMC_IF* data) ;
/*
---------------------------------------------------------------------------
HSTPMC
---------------------------------------------------------------------------
Abstract:
This function sets a pointer to be used by dsp_transfer when
actually writing the array of data from the MCU to the DSP
---------------------------------------------------------------------------
Parameters:
*data a pointer to the interface structure of the resource
---------------------------------------------------------------------------
*/
void HSTPMC(TYPE_HSTPMC_IF* data)
{
static BOOL oval = FALSE ;
/* extract the start address of the first signal
*/
hstpp = &data->HSTPMZ_Par1 ;
data->HSTPMZ_Changed = FALSE ;
/* check if parameter sequence number shall be reset
*/
if (data->DHWIMG_C_DspRst)
SeqNoPar = 0 ;
/* check if a change is made of any parameter
*/
if (data->PARAGP_B_EnParChgDet)
{
if (dcu2_mptd_check(data))
data->HSTPMZ_Changed = TRUE ;
}
/* check if input signal indicates send parameters
*/
if (data->PARPDP_B_ParCalcRd && !oval)
data->HSTPMZ_Changed = TRUE ;
oval = data->PARPDP_B_ParCalcRd ;
/* check if parameters shall be sent: increment sequence number
*/
if (data->HSTPMZ_Changed)
SeqNoPar++ ;
data->HSTPMZ_SeqNoPar = SeqNoPar ;
}
LOCAL BOOL dcu2_mptd_check(TYPE_HSTPMC_IF* data)
{
BOOL retval = FALSE ;
MWT_UDINT *addr ;
MWT_UDINT *dest ;
int i ;
/* compare new parameter data with the internal structure
*/
addr = &data->HSTPMZ_Par1 ;
dest = &oldpars.HSTPMZ_Par1 ;
for (i = 0 ; i < DSP_HSTPMC_ENTRIES - 2 ; i++)
{
if (*dest++ != *addr++) break ; /* difference found, exit loop */
}
/* check if loop exited prematurely -> change detected in parameters
*/
if (i < DSP_HSTPMC_ENTRIES - 3) retval = TRUE ;
/* copy new data to internal structure for next sample
*/
addr = &data->HSTPMZ_Par1 ;
dest = &oldpars.HSTPMZ_Par1 ;
for (i = 0 ; i < DSP_HSTPMC_ENTRIES - 2 ; i++)
*dest++ = *addr++ ;
return retval ;
}
