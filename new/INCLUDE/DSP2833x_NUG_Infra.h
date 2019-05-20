// ------------------------------------------------------------------------
//          Copyright (C) 2018 NUG, Incorporated.
//                          All Rights Reserved.
// ==========================================================================
//
// FILE:   DSP2833x_NUG_Infra.h
//
// TITLE:  Prototypes and Definitions for the user system
//
//###########################################################################
// $TI Release: C28x Floating Point Unit Library V1.30 $
// $Release Date: January 01, 2018 $
//###########################################################################

#ifndef DSP2833x_NUG_INFRA_H
#define DSP2833x_NUG_INFRA_H

#ifdef __cplusplus
extern "C" {
#endif

//===========================================================================
#define F_150M 150.0e6
#define _150M 6.66666667e-9
//===========================================================================
#define	C_SIN45	0.707214
#define	C_COS60	0.5                 //cos60
#define	C_SIN60	0.866025      	//sin60
#define	C_32COEF	0.816497      	//sqrt(2/3)
#define	C_23COEF	1.224745      	//sqrt(3/2)
#define	C_2SQRT	1.414214      	//sqrt(2)
#define	C_13SQRT	0.577350      	//sqrt(1/3)
//===========================================================================
#define	UDC_DELT	0.00025	//对应4KHz delt_t , 每隔0.00025s 采样一次
#define	PI2	6.2831853
#define	PI	3.1415927 
//===========================================================================
#define	RFFT_STAGES	8
#define	RFFT_SIZE	(1 << RFFT_STAGES)
//===========================================================================
#define TX485()	GpioDataRegs.GPBSET.bit.GPIO48=1
#define RX485()	GpioDataRegs.GPBCLEAR.bit.GPIO48=1
//===========================================================================
#define EN_PWM()	GpioDataRegs.GPASET.bit.GPIO13=1
#define DIS_PWM()	GpioDataRegs.GPACLEAR.bit.GPIO13=1
//===========================================================================
#define EN_DA()	GpioDataRegs.GPBSET.bit.GPIO54=1
#define DIS_DA()	GpioDataRegs.GPBCLEAR.bit.GPIO54=1
//===========================================================================
#define FPGA_ALL_RST_EN()	GpioDataRegs.GPASET.bit.GPIO1=1
#define FPGA_ALL_RST_DIS()	GpioDataRegs.GPACLEAR.bit.GPIO1=1
//===========================================================================
#define FPGA_Err_RST_EN()	GpioDataRegs.GPASET.bit.GPIO3=1
#define FPGA_Err_RST_DIS()	GpioDataRegs.GPACLEAR.bit.GPIO3=1
//===========================================================================
#define MCU_Err_EN()	GpioDataRegs.GPASET.bit.GPIO5=1
#define MCU_Err_DIS()	GpioDataRegs.GPACLEAR.bit.GPIO5=1
//===========================================================================
#define EN_INT()	GpioDataRegs.GPASET.bit.GPIO12=1
#define DIS_INT()	GpioDataRegs.GPACLEAR.bit.GPIO12=1
//===========================================================================
#define MCU_WDH()	GpioDataRegs.GPASET.bit.GPIO29=1
#define MCU_WDL()	GpioDataRegs.GPACLEAR.bit.GPIO29=1
//===========================================================================
#define EN_GPIO35()     GpioDataRegs.GPBSET.bit.GPIO35=1
#define DIS_GPIO35()     GpioDataRegs.GPBCLEAR.bit.GPIO35=1
//===========================================================================
#define EN_MVBRST()     GpioDataRegs.GPBSET.bit.GPIO56=1
#define DIS_MVBRST()     GpioDataRegs.GPBCLEAR.bit.GPIO56=1
//===========================================================================
#define EN_FPGATBD()     GpioDataRegs.GPBSET.bit.GPIO57=1
#define DIS_FPGATBD()     GpioDataRegs.GPBCLEAR.bit.GPIO57=1
//===========================================================================
#define EN_LTPEN()     GpioDataRegs.GPBCLEAR.bit.GPIO60=1
#define DIS_LTPEN()     GpioDataRegs.GPBSET.bit.GPIO60=1
//===========================================================================
#define EN_OPTOEN()     GpioDataRegs.GPBSET.bit.GPIO61=1
#define DIS_OPTOEN()     GpioDataRegs.GPBCLEAR.bit.GPIO61=1
//********************************************************************

struct  flagsci_BITS {        // bit    
   Uint16 Recv_byt:1;         // 0           
   Uint16 Overtime:1;   // 1     
   Uint16 Keyrunorstp:1;       // 2   
   Uint16 rsvd1:13;       // 15:3        
}; 
union flagsci_REG {
   Uint16              all;
   struct flagsci_BITS  bit;
};

extern volatile struct flagsci_BITS flagsci;
//extern int16 paramet[170];
extern Uint16 scitx_sta;
extern Uint16 SW_ID;
extern Uint16 Cnt_250us;
extern Uint16 Cnt_ms,Cnt_Sec,Cnt_Min,Cnt_Hour,Cnt_Day,Cnt_Year;

// standard C99 include
#include <stdint.h>
#include <stdio.h>

// system-tasks initialized flag
typedef struct
{
	uint16_t tms	:1;		// ecan-b
	uint16_t term 	:1;		// sci-b
	uint16_t stor	:1; 	// i2c-a
	uint16_t res	:13;	// reserved...
} tasks_ini_t;

extern tasks_ini_t tasks_ini;

extern void TaskECan_ini(void);
extern void TaskECan_run(void);
extern void TaskSci_ini(void);
extern void TaskSci_run(void);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of DSP2833x_USER_H

//===========================================================================
// End of file.
//===========================================================================
