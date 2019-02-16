//################################################################################
// FILE:    Main.c
// TITLE:	NUGTCU_DSP2
// DESCRIPTION: NUGTCU,T=250uS
//################################################################################
/*
 * HISTORY
 *
 *
 *
 * */

/*
 * INCLUDES
 * */
#include "DSP2833x_Device.h"     
#include "DSP2833x_Examples.h"  
#include "C28x_FPU_FastRTS.h"
#include <math.h>
/*
 * EXTERNAL FUNCTION PROTOTYPES
 * */

/*
 * DESCRIPTION
 * */

/*
 * DEFINES
 * */
//--------------------------------------------------------------------------------
#define	  IO_ABC_OVER		260
#define	  UDC_OVER			1850
#define	  TEMP_IGBT_OVER	70
#define	  TEMP_AMB_OVER		60
#define	  PI2             6.283185
#define   PI              3.141593
//--------------------------------------------------------------------------------

/*
 * TYPEDEFS
 * */

/*
 * STRUCTDEFS
 * */
//-----------------input-------------------------
struct PX_In
{
	float32  XU_DcLk;   		    	// DC-link voltage, V
    float32  XI_DcLk;   				// DC current, A
	float32  XI_PhA;					// phase A current, A
	float32  XI_PhB;					// phase B current, A
	float32  XI_PhC;			  	  	// phase C current, A
	float32  XV_SpdSn1; 		    	// rotate speed 1, rad/min
	float32  XV_SpdSn2;		    		// rotate speed 2, rad/min
	Uint16	 SX_AtDrTn;					// actual direction of train
	Uint16   XH_AxTpSn1;				// temperature 1 of axle, C
	Uint16   XH_AxTpSn2;		   		// temperature 2 of axle, C
	Uint16   XH_InnTp;	    			// inner temperature, C
	Uint16   XH_HtTp;		    		// heatsink temperature, C
	float32  XV_AtSpdTn;	    		// actual speed, km/h
	float32  CX_DrTn;   				// direction command
	float32  WM_TqCmd;					// torque command, kN*m
	float32  XX_TnWgh;					// train weight, Ton
	float32  XH_AmTp;         			// ambient temperature, C
};
volatile struct PX_In PX_In_Spf = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//========================================================================
struct PX_InPr
{
	float32  XU_DcLk_Max;   			// DC-link voltage, V
	float32  XU_DcLk_Min;   			// DC-link voltage, V
	Uint16   XU_DcLkOvCn;   			// DC-link over-voltage counter
	Uint16   XU_DcLkUnCn;   			// DC-link under-voltage counter
    float32  XI_DcLk_Max;   			// DC current, A
    Uint16   XI_DcLkOvCn;   			// DC-link over-current counter
	float32  XI_PhABC_Max;				// phase ABC maximum current, A
	Uint16   XI_PhAOvCn;				// phase A over current counter
	Uint16   XI_PhBOvCn;				// phase B over current counter
	Uint16   XI_PhCOvCn;				// phase C over current counter
	Uint16   XV_SpdSn1_Max; 		    // rotate speed 1, rad/min
	Uint16   XV_SpdSn2_Max;		    	// rotate speed 2, rad/min
	Uint16   XH_AxTpSn1_Max;			// temperature 1 of axle, C
	Uint16   XH_AxTpSn2_Max;		   	// temperature 2 of axle, C
	Uint16   XH_InnTp_Max;	    		// inner temperature, C
	Uint16   XH_HtTp_Max;		    	// heatsink temperature, C
	float32  XV_AtSpdTn_Max;	    	// actual speed, km/h
	float32  XH_AmTp_Max;         		// ambient temperature, C
};
volatile struct PX_InPr PX_InPr_Spf = {740,0,0,0,53,0,32,0,0,0,0,0,0,0,0,0,0,0};
//-------------output-------------
struct PX_Out
{
	Uint16   XX_PwmMo;				// PWM mode
	Uint16   XT_PwmPdVv;   		    // PWM period value,  for initialization
	Uint16   XX_Pwm1AVv;   			// PWM1A value
	Uint16   XX_Pwm2AVv;			// PWM2A value
	Uint16   XX_Pwm3AVv;			// PWM3A value
	Uint16   XX_Pwm4AVv;			// PWM4A value, chopper
	float32  XP_In; 		    	// input power, kw
	float32  XP_Out;		    	// output power, kw
	float32  XM_OutTq;				// output torque
	float32  XX_PhUbl;				// phase unbalance
	float32  XI_PhA_Rms;		    // phase A current, RMS
	float32  XI_PhB_Rms;	    	// phase B current, RMS
	float32  XI_PhC_Rms;		    // phase C current, RMS
	float32  XH_BrRsTp_Est;	    	// estimated temperature of brake resistor, C
	float32  XH_DcNdTp_Est;   		// estimated temperature of DC inductor, C
	Uint16	 XX_Flt2;				// 15 fault states
	Uint16	 XX_Flt3;				// 15 fault states
	Uint16	 XX_Flt4;				// 15 fault states
	Uint16	 XX_Flt5;				// 15 fault states
	float32  Time;
};
volatile struct PX_Out PX_Out_Spf = {21,7500,3750,3750,3750,3750,0,0,0,0,0,0,0,0,0,0,0,0,0,1/1040};
//============================================================================================
struct  COM_BITS
{							// XX_Flt1
    Uint16      TA0:1;		// Udc
    Uint16      TA1:1;		// Idc
    Uint16      TA2:1;		// Idc
    Uint16      TA3:1;		// Udc
    Uint16      TA4:1;		// DSP
    Uint16      TA5:1;		// Ia
    Uint16      TA6:1;		// Ib
    Uint16      TA7:1;		// Ic
    Uint16      TA8:1;		// Iac
    Uint16      TA9:1;		// Ia
    Uint16      TA10:1;		// Ib
    Uint16      TA11:1;		// Ic
    Uint16      TA12:1;		// Ia
    Uint16      TA13:1;		// Ib
    Uint16      TA14:1;		// Ic
    Uint16      TA15:1;		// Iac
};
union WARN_REG
{
    Uint16             all;
    struct COM_BITS    bit;
};
union  WARN_REG   XX_Flt1;				// 16 fault states
//======================================================================
/*
 * GLOBALS
 * */

/*
 * LOCALS
 * */
int16	*XintfZone0=(int16 *)0x004000;//Unused
int16	*XintfZone6=(int16 *)0x100000;//Unused
int16	*XintfZone7=(int16 *)0x200000;//DP RAM
//=======================================================================
volatile int16 NX_Dsp1OpSt;				// DSP1 operation state
volatile int16 NX_Dsp2OpSt = 0x11;		// DSP2 operation state
volatile int16 NX_Dsp2Ver;				// DSP2 version

volatile Uint16 NX_Dsp1PlCn;		// DSP1 pulse(heartbeat) counter
volatile Uint16 NX_Dsp2PlCn;		// DSP2 pulse(heartbeat) counter

volatile float32 PX_DcLkStbU;		// DC-link voltage stabilized
volatile float32 PX_DcLkOscSpr;		// DC-link oscillation suppressed

Uint16	GPIO_Temp181,GPIO_Temp182;
Uint16 SX_Run = 0;		// DSP2 running state, 1 means running, 0 means stop
Uint16 SX_Dsp2Rd = 0;	// Dsp2 Ready state
//===========================================================================
//--------------------------------------------------------------------------------
/*
 * LOCAL FUNCTIONS
 * */
void DPRAM_RD(void);
void NX_Pr(void);
void DPRAM_WR(void);
void EN_GPIO30(void);
void DIS_GPIO30(void);
//===========================================================================
interrupt void DPRAM_isr(void);
//=================================================================================

/*
 * MAIN
 * */
void main(void)
{
	InitSysCtrl();
	InitGpio();
	InitXintf();

	DELAY_US(10000L);

	DINT;
	IER = 0x0000;
	IFR = 0x0000;
	InitPieCtrl();
	InitPieVectTable();

	EALLOW;
	PieVectTable.XINT1 = &DPRAM_isr;
	EDIS;

	InitCpuTimers();
	InitXInterrupt();
	IER = M_INT1;
	PieCtrlRegs.PIEIER1.bit.INTx4 = 1;

	EINT;
	ERTM;

	while(1)
	{
	//--------------------------------------------------------------------------------
		GPIO_Temp181 = GpioDataRegs.GPADAT.bit.GPIO18;//外部中断输入标志位
		DELAY_US(2L);//主要是为了判断是否长时间未进入中断复位，此处可采用无效延时，或者插入其他有效的执行任务
		GPIO_Temp182 = GpioDataRegs.GPADAT.bit.GPIO18;
		if((GPIO_Temp181 == 0) && (GPIO_Temp182 == 0))
		{
			//INTR复位语句
		}
	//--------------------------------------------------------------------------------
        if(((NX_Dsp1OpSt == 0x33) || (NX_Dsp1OpSt == 0x44)) && (NX_Dsp2OpSt == 0x33) && (XX_Flt1.all == 0))
        	SX_Dsp2Rd = 1;
        else
        	SX_Dsp2Rd = 0;
	}
}
//==============================================================================
interrupt void DPRAM_isr(void)   					//after DSP1 has written to DPRAM, trigger the interrupt
{  
	DIS_GPIO30();

	DPRAM_RD(); //读dsp1交互信息
	NX_Pr();

	NX_Dsp2PlCn++;
	if(NX_Dsp2PlCn > 32767)
		NX_Dsp2PlCn = 0;

	/**/
	if(SX_Dsp2Rd == 1)
	{

		SX_Run = 1;
	}
	else
	{
		PX_Out_Spf.XX_Pwm1AVv = 9014;
		PX_Out_Spf.XX_Pwm2AVv =	9014;
		PX_Out_Spf.XX_Pwm3AVv = 9014;
		SX_Run = 0;
	}

	DPRAM_WR();//写dsp2交互信息
    PieCtrlRegs.PIEACK.all|=PIEACK_GROUP1;

    EN_GPIO30();
}
//==============================================================================
void DPRAM_RD(void)
{
	NX_Dsp1PlCn = *(XintfZone7 + 0x7FFF);		// DSP1 pulse(heartbeat) counter    (RAM 0x7FFF clear)
	NX_Dsp1OpSt = *(XintfZone7 + 0x1);			// DSP1 operation state
	if(NX_Dsp2OpSt == 0x11)						// DSP2 initializing
	{
			NX_Dsp2OpSt = 0x33;
	}
	else if(NX_Dsp2OpSt == 0x33)				//DSP2 initialized
	{
		PX_In_Spf.XU_DcLk = *(XintfZone7 + 0x6) * 0.1;		// DC-link voltage, V
		PX_In_Spf.XI_DcLk = *(XintfZone7 + 0x7) * 0.1;			// DC current, A
		PX_In_Spf.XI_PhA = *(XintfZone7 + 0x8)*0.1;				// phase A current, A
		PX_In_Spf.XI_PhB = *(XintfZone7 + 0xA)*0.1;				// phase B current, A
		PX_In_Spf.XI_PhC = *(XintfZone7 + 0x9)*0.1;				// phase C current, A
		PX_In_Spf.XV_SpdSn1 = *(XintfZone7 + 0xB);			// rotate speed 1, rad/min
		PX_In_Spf.XV_SpdSn2 = *(XintfZone7 + 0xC);			// rotate speed 2, rad/min
		PX_In_Spf.SX_AtDrTn = *(XintfZone7 + 0xD);			// actual direction of train
		PX_In_Spf.XH_AxTpSn1 = *(XintfZone7 + 0xE) & 0x00FF;			// temperature 1 of axle, C
		PX_In_Spf.XH_AxTpSn2 = *(XintfZone7 + 0xE) & 0xFF00;			// temperature 2 of axle, C
		PX_In_Spf.XH_InnTp = *(XintfZone7 + 0xF) & 0x00FF;			// inner temperature, C
		PX_In_Spf.XH_HtTp = *(XintfZone7 + 0xF) & 0xFF00;			// heatsink temperature, C
		PX_In_Spf.XV_AtSpdTn = *(XintfZone7 + 0x10) * 0.01;		// actual speed, km/h   0.01->0.1
		PX_In_Spf.CX_DrTn = *(XintfZone7 + 0x11);		        // direction command
		PX_In_Spf.WM_TqCmd = *(XintfZone7 + 0x12);		// torque command, kN*m
		PX_In_Spf.XX_TnWgh = *(XintfZone7 + 0x13) * 0.1;		// train weight, Ton
		PX_In_Spf.XH_AmTp = *(XintfZone7 + 0x14) * 0.01;		// ambient temperature, C
	}
}


//==============================================================================
void DPRAM_WR(void)
{
	*(XintfZone7 + 0x2) = NX_Dsp2OpSt;		// NX_Dsp2OpSt: DSP2 operation state
	*(XintfZone7 + 0x3) = NX_Dsp2Ver;		// DSP2 version
	*(XintfZone7 + 0x15) = PX_Out_Spf.XX_PwmMo;     		// PWM  mode configuration
	*(XintfZone7 + 0x16) = PX_Out_Spf.XT_PwmPdVv;			// PWM period value
	*(XintfZone7 + 0x17) = PX_Out_Spf.XX_Pwm1AVv;			// PWM1A value
	*(XintfZone7 + 0x18) = PX_Out_Spf.XX_Pwm2AVv;			// PWM2A value
	*(XintfZone7 + 0x19) = PX_Out_Spf.XX_Pwm3AVv;			// PWM3A value
	*(XintfZone7 + 0x1A) = PX_Out_Spf.XX_Pwm4AVv;			// PWM4A value, chopper
	*(XintfZone7 + 0x1B) = PX_Out_Spf.XP_In * 10; 		    	// input power, 0.1kw (left value)
	*(XintfZone7 + 0x1C) = PX_Out_Spf.XP_Out * 10;		    	// output power, 0.1kw (left value)
	*(XintfZone7 + 0x1D) = PX_Out_Spf.XM_OutTq * 10;				// output torque, 0.1kN (left value)
	*(XintfZone7 + 0x1E) = PX_Out_Spf.XX_PhUbl * 100;				// phase unbalance, 1% (left value)
	*(XintfZone7 + 0x1F) = PX_Out_Spf.XI_PhA_Rms * 10;		    // phase A current, RMS, 0.1A (left value)
	*(XintfZone7 + 0x20) = PX_Out_Spf.XI_PhB_Rms * 10;	    	// phase B current, RMS, 0.1A (left value)
	*(XintfZone7 + 0x21) = PX_Out_Spf.XI_PhC_Rms * 10;		    // phase C current, RMS, 0.1A (left value)
	*(XintfZone7 + 0x22) = PX_Out_Spf.XH_BrRsTp_Est * 10;	    // estimated temperature of brake resistor, 0.1C (left value)
	*(XintfZone7 + 0x23) = PX_Out_Spf.XH_DcNdTp_Est * 10;   		// estimated temperature of DC inductor, 0.1C (left value)
	*(XintfZone7 + 0x24) = XX_Flt1.all;						// 15 fault states
	/*上位机*/
	*(XintfZone7 + 0x25) = SX_Run;				//
	*(XintfZone7 + 0x26) = 0;			// 调制标志位，5：异步，4:15分频，3:11分频。2:7分频，1:3分频，方波是自动的
	*(XintfZone7 + 0x27) = 0;		//d轴电流指令
	*(XintfZone7 + 0x28) = 0;		//q轴电流指令
	*(XintfZone7 + 0x29) = 0;      //d轴电压指令
	*(XintfZone7 + 0x2A) = 0;		//q轴电压指令
	/*DA输出*/
	*(XintfZone7 + 0x2B) = 0;   //d轴实际电流
	*(XintfZone7 + 0x2C) = 0;   //q轴实际电流
	*(XintfZone7 + 0x2D) = 0;   //d轴参考电流
	*(XintfZone7 + 0x2E) = 0;   //q轴参考电流
	*(XintfZone7 + 0x2F) = 0;  //alpha轴磁链
	*(XintfZone7 + 0x30) = 0;  //beta轴磁链
	*(XintfZone7 + 0x31) = 0;
}
//==============================================================================
/*
 * 保护
 * */
void NX_Pr(void)
{
//-----------------------phase A over-current------------------------
	if((PX_In_Spf.XI_PhA > PX_InPr_Spf.XI_PhABC_Max) || (PX_In_Spf.XI_PhA < -PX_InPr_Spf.XI_PhABC_Max))
	{
		PX_InPr_Spf.XI_PhAOvCn++;
		if(PX_InPr_Spf.XI_PhAOvCn > 3)
		{
			SX_Run = 0;
			XX_Flt1.bit.TA5 = 1;
			SX_Dsp2Rd = 0;
			PX_InPr_Spf.XI_PhAOvCn = 4;
		}
	}
	else
		PX_InPr_Spf.XI_PhAOvCn = 0;

//-----------------------phase B over-current------------------------
	if((PX_In_Spf.XI_PhB > PX_InPr_Spf.XI_PhABC_Max) || (PX_In_Spf.XI_PhB < -PX_InPr_Spf.XI_PhABC_Max))
	{
		PX_InPr_Spf.XI_PhBOvCn++;
		if(PX_InPr_Spf.XI_PhBOvCn > 3)
		{
			SX_Run = 0;
			XX_Flt1.bit.TA6 = 1;
			SX_Dsp2Rd = 0;
			PX_InPr_Spf.XI_PhBOvCn = 4;
		}
	}
	else
		PX_InPr_Spf.XI_PhBOvCn = 0;

//-----------------------phase C over-current------------------------
	if((PX_In_Spf.XI_PhC > PX_InPr_Spf.XI_PhABC_Max) || (PX_In_Spf.XI_PhC < -PX_InPr_Spf.XI_PhABC_Max))
	{
		PX_InPr_Spf.XI_PhCOvCn++;
		if(PX_InPr_Spf.XI_PhCOvCn > 3)
		{
			SX_Run = 0;
			XX_Flt1.bit.TA7 = 1;
			SX_Dsp2Rd = 0;
			PX_InPr_Spf.XI_PhCOvCn = 4;
		}
	}
	else
		PX_InPr_Spf.XI_PhCOvCn = 0;

//-----------------------DC-link over-current------------------------
	if(PX_In_Spf.XI_DcLk > PX_InPr_Spf.XI_DcLk_Max)
	{
		PX_InPr_Spf.XI_DcLkOvCn = PX_InPr_Spf.XI_DcLkOvCn + 1;
		if(PX_InPr_Spf.XI_DcLkOvCn > 3)
		{
			SX_Run = 0;
			XX_Flt1.bit.TA1 = 1;
			SX_Dsp2Rd = 0;
			PX_InPr_Spf.XI_DcLkOvCn = 4;
		}
	}
	else
		PX_InPr_Spf.XU_DcLkOvCn = 0;

//---------------------DC-link current sample disabled---------------------
	XX_Flt1.bit.TA2 = 0;

//---------------------DC-link voltage sample disabled---------------------
	XX_Flt1.bit.TA3 = 0;

//-------------------Udc over-voltage--------------------
	if(PX_In_Spf.XU_DcLk > PX_InPr_Spf.XU_DcLk_Max)
	{
		PX_InPr_Spf.XU_DcLkOvCn = PX_InPr_Spf.XU_DcLkOvCn + 1;
		if(PX_InPr_Spf.XU_DcLkOvCn > 3)
		{
			SX_Run = 0;
			XX_Flt1.bit.TA0 = 1;
			SX_Dsp2Rd = 0;
			PX_InPr_Spf.XU_DcLkOvCn = 4;
		}
	}
	else
		PX_InPr_Spf.XU_DcLkOvCn = 0;

//------------------Udc under-voltage---------------------
	if(PX_In_Spf.XU_DcLk < PX_InPr_Spf.XU_DcLk_Min && SX_Run == 1)
	{
		PX_InPr_Spf.XU_DcLkUnCn++;
		if(PX_InPr_Spf.XU_DcLkUnCn > 3)
		{
			SX_Run = 0;
			XX_Flt1.bit.TA0 = 1;
			SX_Dsp2Rd = 0;
			PX_InPr_Spf.XU_DcLkUnCn = 4;
		}
	}
	else
		PX_InPr_Spf.XU_DcLkUnCn = 0;
//------------------DSP over-load---------------------
	XX_Flt1.bit.TA4 = 0;

//------------------AC current unbalance---------------------
	XX_Flt1.bit.TA8 = 0;

//------------------phase A fault---------------------
	XX_Flt1.bit.TA9 = 0;

//------------------phase B fault---------------------
	XX_Flt1.bit.TA10 = 0;

//------------------phase C fault---------------------
	XX_Flt1.bit.TA11 = 0;

//------------------phase A current sensor fault---------------------
	XX_Flt1.bit.TA12 = 0;

//------------------phase B current sensor fault---------------------
	XX_Flt1.bit.TA13 = 0;

//------------------phase C current sensor  fault---------------------
	XX_Flt1.bit.TA14 = 0;

//------------------AC current sampling fault---------------------
	XX_Flt1.bit.TA15 = 0;
}
//==============================================================================
void EN_GPIO30(void)
{
	EALLOW;  
    GpioDataRegs.GPASET.bit.GPIO30=1;
    EDIS;
}
//==============================================================================
void DIS_GPIO30(void)
{
	EALLOW;
    GpioDataRegs.GPACLEAR.bit.GPIO30=1;
    EDIS;
}

//===============================================================================================
//=========================================THE END===============================================
//===============================================================================================

/*
 * HSTIMA - Host interface signals from DSP to MCU
 * */
struct
{
	float32 XU_DcLk;//DC-link voltage
	float32 XU_3PhPek;//3-Phase output load voltage,phase-phase,peak value
	float32 XI_PhPek;//Phase current,peak value
	float32 XI_PhAct;//Active phase current
	float32 XI_PhRct;//Reactive phase current
	float32 XI_BtCg;//Battery charger current
	float32 XI_Bt;//Battery current
	float32 XU_PhInRms;//
	float32 XI_PhInRms;
	float32 WU_IPhClTrs;
	float32 WU_IBtCgCl;
	float32 WU_OvMd;
	float32 WU_IPhClRms;
	float32 XU_Bt;
	float32 XI_Ph1Rms;
	float32 XI_Ph2Rms;
	float32 XI_Ph3Rms;
	float32 XU_3PhRms;
	float32 XU_3PhRe;
	float32 XU_3PhIm;
	float32 XT_U3Ph;//Period time of measured 3-phase output load voltage
	float32 XI_PhReFix;
	float32 XI_PhImFix;
	float32 XP_2qc;
	float32 XP_3Ph;//3-phase output power
	float32 XP_Ovp;
	float32 XX_AI24;
	float32 XX_AI29;
	float32 XQ_3Ph;
	float32 XI_DfInFlt;
	float32 WU_Flt;
	float32 XU_DcLk2;
	float32 XH_Ovp_Est;
	float32 XI_Rct1_Rms;
	float32 XI_BtCp;//不确定
};

/*
 * HSTOMA - Host interface signals from MCU to DSP
 *
 * */
struct
{
	float32 WU_3PhDsp;
	float32 WF_3PhDsp;
	float32 WI_PhActDsp;
	float32 WI_PhRctDsp;
	float32 XX_IPhClTrsKpActDsp;
	float32 XX_IPhClTrsKpRctDsp;
};

