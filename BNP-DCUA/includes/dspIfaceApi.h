/*****************************************************************************
* COPYRIGHT : (c) 2004 Bombardier Transportation
******************************************************************************
* PROJECT : DCU2 - MCU/LIB
**
MODULE : dspIfaceApi.h
**
ABSTRACT : This module implements the MCU-DSP communication interface.
**
REMARKS :
*
******************************************************************************
* HISTORY :
**
1 04-09-21 14:01 Bertil Soderberg
* First version.
*
******************************************************************************/
/*****************************************************************************
* INCLUDES
*/
/*****************************************************************************
* LOCAL FUNCTIONS
*/
void dspReset () ;
void dspReleaseReset () ;
/*UINT32 dspHpicStatus () ; */
UINT32 dspHpicRead () ;
void dspHpicWrite (UINT16 hpic, UINT8 action) ;
UINT32 dspHpiaRead () ;
void dspHpiaWrite (UINT32 addr);
UINT32 dspHpidRead () ;
void dspHpidWrite (UINT32 data) ;
UINT32 dspHpidAutoincRead () ;
void dspHpidAutoincWrite (UINT32 data);
void dspWriteSingleWord (UINT32 addr, UINT32 data) ;
void dspWrite (UINT32 addr, UINT32 data[], UINT32 len) ;
UINT32 dspReadSingleWord (UINT32 addr) ;
void dspRead (UINT32 addr, UINT32 data[], UINT32 len) ;
void dspInterrupt () ;
