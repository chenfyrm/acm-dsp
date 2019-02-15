//################################################################################
// FILE:    Main.c
// TITLE:	NUGTCU_DSP2
// DESCRIPTION: NUGTCU,T=250uS
//################################################################################
#include "DSP2833x_Device.h"     
#include "DSP2833x_Examples.h"  
#include "C28x_FPU_FastRTS.h"
#include <math.h>

//--------------------------------------------------------------------------------
#define	  Ver_DSP2			0x10

#define	  IO_ABC_OVER		260
//鐢垫祦淇濇姢鏈夋晥鍊�
#define	  IO_RMS_OVER		70

#define	  UDC_OVER			1850
#define	  TEMP_IGBT_OVER	70
#define	  TEMP_AMB_OVER		60
#define	  PI2             6.283185
//#define   PI              3.141593
//--------------------------------------------------------------------------------
#define   UDC_KP_UL  55  
#define   UDC_KI_UL  60  
#define   UDC_KP_LL  -90 
#define   UDC_KI_LL  -90 
//--------------------------------------------------------------------------------

int16	*XintfZone0=(int16 *)0x004000;//Unused
int16	*XintfZone6=(int16 *)0x100000;//Unused
int16	*XintfZone7=(int16 *)0x200000;//DP RAM
//--------------------------------------------------------------------------------
Uint16	Cnt_Period,Cnt_us,Cnt_sec,Cnt_min,Cnt_IORMS,ERR_IORMS,Cnt_UDC,ERR_UDC;
Uint16	Ua_CMPA,Ub_CMPA,Uc_CMPA,Ua_CMPB,Ub_CMPB,Uc_CMPB,GPIO_Temp181,GPIO_Temp182;
int16	Ver_DSP1=0,Ver_FPGA=0;
int16	Num_com,In_UDC;

//--------------------------------------------------------------------------------
float32	UDC_Kp=0.3;
float32	sinVal,cosVal;   
//--------------------------------------------------------------------------------
volatile int16	DPRAM_SAM[50];
volatile Uint16	TCU_Mode;


//--------------------------------------------------------------------------------
struct PI_Rms
{
	float32 Square;
	float32 Rms;
};
volatile struct PI_Rms PI_PhARms = {0, 0};
volatile struct PI_Rms PI_PhBRms = {0, 0};
volatile struct PI_Rms PI_PhCRms = {0, 0};

volatile struct ABC VO_abc;//涓夌浉鐢靛帇ABC
volatile struct ABC IO_abc = {0,0,0,0};//涓夌浉鐢垫祦ABC
                                                    


volatile int16 NX_Dsp1OpSt;				// DSP1 operation state
volatile int16 NX_Dsp2OpSt = 0x11;		// DSP2 operation state
volatile int16 NX_Dsp2Ver;				// DSP2 version

volatile Uint16 NX_Dsp1PlCn;		// DSP1 pulse(heartbeat) counter
volatile Uint16 NX_Dsp2PlCn;		// DSP2 pulse(heartbeat) counter

volatile float32 WU_DcLk_Nom;		// nominal voltage reference of DC link
volatile float32 WI_DcLk_Nom;		// nominal current reference of DC link
volatile float32 WI_Ac_Nom;			// nominal AC current reference

volatile float32 PX_DcLkStbU;		// DC-link voltage stabilized
volatile float32 PX_DcLkOscSpr;		// DC-link oscillation suppressed
volatile Uint16 WU_BrCp;			// voltage reference of brake chopper

volatile float32 WU_OpLo;			// voltage   reference for open loop
volatile float32 WF_OpLo;			// frequency reference for open loop


struct PF_HybMod					// frequency of hybrid modulation
{
	float32 PF_AsMod;				// asynchronous modulation
	float32 PF_SynRt21Mod;			// synchronous modulation ratio=21
	float32 PF_SynRt15Mod;			// synchronous modulation ratio=15
	float32 PF_SynRt7Mod;			// synchronous modulation ratio=7
	float32 PF_SynRt5Mod;			// synchronous modulation ratio=5
	float32 PF_SynRt3Mod;			// synchronous modulation ratio=3
};

struct PF_HybMod PF_HybMod_Spf = {0,0,48,56,64,72};

struct PX_Mt 					// motor parameters
{
	Uint16  PX_Ppa;				// pole pairs
	Uint16 	PF_SxFr_Nom;		// stator rated(nominal) frequency, Hz
	Uint16 	PX_SxRxLm;			// mutual inductance, mH
	Uint16	PX_SxLl;			// stator leakage inductance, mH
	Uint16  PX_RxLl;			// rotor leakage inductance referred to the stator, mH
	Uint16  PR_SxRs;			// stator resistance, mOhm
	Uint16  PR_RxRs;			// rotor resistance referred to the stator, mOhm
	Uint16  PY_RxMag_Nom;		// rotor rated(nominal) flux magnitude, WB
};

volatile struct PX_Mt PX_AsMt  = {2,80,300,20,20,200,230,1.86};

struct PX_PID
{
	float32  Ref;   			// Input: Reference input
    float32  Fb;   				// Input: Feedback input
	float32  Err;				// Variable: Error
	float32  Kp;				// Parameter: Proportional gain
	float32  Ki;			    // Parameter: Integral gain
	float32  Kd; 		        // Parameter: Derivative gain
	float32  Up;				// Variable: Proportional output
	float32  Ui;				// Variable: Integral output
	float32  Ud;				// Variable: Derivative output
	float32  ItgMax;		    // Parameter: Maximum output
	float32  ItgMin;	    	// Parameter: Minimum output
	float32  OutMax;		    // Parameter: Maximum output
	float32  OutMin;	    	// Parameter: Minimum output
	float32  Out;   			// Output: PID output
	float32  Err_1;		   	    // History: Previous Error
};

volatile struct PX_PID AsMtDAx  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};		// d-axis of asynchronous motor
volatile struct PX_PID AsMtQAx  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};		// q-axis of asynchronous motor

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

struct PX_InPr
{
	float32  XU_DcLk_Max;   		// DC-link voltage, V
	float32  XU_DcLk_Min;   		// DC-link voltage, V
	Uint16   XU_DcLkOvCn;   		// DC-link over-voltage counter
	Uint16   XU_DcLkUnCn;   		// DC-link under-voltage counter
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
//	Uint16	 XX_Flt1;				// 15 fault states
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
    Uint16      TA0:1;		// Udc杩囧帇/娆犲帇
    Uint16      TA1:1;		// Idc杩囨祦
    Uint16      TA2:1;		// Idc閲囨牱澶辨晥
    Uint16      TA3:1;		// Udc閲囨牱澶辨晥
    Uint16      TA4:1;		// DSP杩囪浇
    Uint16      TA5:1;		// Ia杩囨祦
    Uint16      TA6:1;		// Ib杩囨祦
    Uint16      TA7:1;		// Ic杩囨祦
    Uint16      TA8:1;		// Iac锛堜氦娴佺數娴侊級涓嶅钩琛�
    Uint16      TA9:1;		// Ia澶辩浉
    Uint16      TA10:1;		// Ib澶辩浉
    Uint16      TA11:1;		// Ic澶辩浉
    Uint16      TA12:1;		// Ia瑙傛祴鏁呴殰
    Uint16      TA13:1;		// Ib瑙傛祴鏁呴殰
    Uint16      TA14:1;		// Ic瑙傛祴鏁呴殰
    Uint16      TA15:1;		// Iac锛堜氦娴佺數娴侊級閲囨牱澶辨晥
};

union WARN_REG
{
    Uint16             all;
    struct COM_BITS    bit;
};

union  WARN_REG   XX_Flt1;				// 16 fault states
//======================================================================

Uint16 SX_NtFlt = 0;	// initialization fault state
Uint16 XX_NtFltCn = 0;	//
Uint16 SX_Run = 0;		// DSP running state, 1 means running, 0 means stop
Uint16 SX_Dsp2Rd = 0;	// Dsp2 Ready state

//--------------------------------------------------------------------------------
Uint16 Buffer_cnt = 0;
Uint16 Buffer_cnt1 = 0;
Uint16 TIME_cnt = 0;

//--------------------------------------------------------------------------------
void DPRAM_RD(void);
void DPRAM_WR(void);
void PI_RmsClc(void);	// current RMS calculation
void Protect_L1(void);

void EN_GPIO30(void);
void DIS_GPIO30(void);
void InitVariables(void);
void InitMode(void);
void DIS_CAL(void);
void Nt_Warn(void);
void Scope(void);
float Uabc_PLL(float Ua,float Ub,float Uc);
void NX_Pr(void);
interrupt void DPRAM_isr(void);
//=================================================================================
void main(void)
{

}
//==============================================================================
interrupt void DPRAM_isr(void)   					//after DSP1 has written to DPRAM, trigger the interrupt
{  

}
//==============================================================================
void DPRAM_RD(void)
{

}


//==============================================================================
void DPRAM_WR(void)
{

}

//==============================================================================
void Nt_Warn(void)		// initialization warn    鏍规嵁瀹為檯鎯呭喌鍐嶄慨鏀�
{

}

//==============================================================================
void NX_Pr(void)
{

}
//==============================================================================
//==============================================================================
void PI_RmsClc(void)
{		

}
//===============================================================================================
void DIS_CAL(void)
{

}
//==============================================================================
void EN_GPIO30(void)
{
	EALLOW;  
    GpioDataRegs.GPASET.bit.GPIO30=1;
    EDIS;
}
void DIS_GPIO30(void)
{
	EALLOW;
    GpioDataRegs.GPACLEAR.bit.GPIO30=1;
    EDIS;
}
//==============================================================================================
void Protect_L1(void)
{

}

//==============================================================================================
void InitVariables(void)
{

}

void InitMode(void)
{

}
//===============================================================================================
//=========================================THE END===============================================
//===============================================================================================

