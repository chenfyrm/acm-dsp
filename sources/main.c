//################################################################################
// FILE:    Main.c
// TITLE:	NUGTCU_DSP2
// DESCRIPTION: NUGTCU,T=250uS
//################################################################################
#include "DSP2833x_Device.h"     
#include "DSP2833x_Examples.h"  
#include "C28x_FPU_FastRTS.h"
#include <math.h>
#include "IQmathLib.h"
#include "ACI3.h"
#include "IndirectFluxCalc.h"
#include "aci_fe_const.h"
#include "aci_fe.h"
#include "aci_se_const.h"
#include "aci_se.h"

//--------------------------------------------------------------------------------
#define	  Ver_DSP2			0x10

#define	  IO_ABC_OVER		260
//电流保护有效值
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

//volatile float32	DPRAM_SAM1[1000];
//volatile float32	DPRAM_SAM2[1000];
//int Cnt = 0;
//--------------------------------------------------------------------------------
struct PI_Rms
{
	float32 Square;
	float32 Rms;
};
volatile struct PI_Rms PI_PhARms = {0, 0};
volatile struct PI_Rms PI_PhBRms = {0, 0};
volatile struct PI_Rms PI_PhCRms = {0, 0};

volatile struct ABC VO_abc;//三相电压ABC
volatile struct ABC IO_abc = {0,0,0,0};//三相电流ABC
                                                    


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
    Uint16      TA0:1;		// Udc过压/欠压
    Uint16      TA1:1;		// Idc过流
    Uint16      TA2:1;		// Idc采样失效
    Uint16      TA3:1;		// Udc采样失效
    Uint16      TA4:1;		// DSP过载
    Uint16      TA5:1;		// Ia过流
    Uint16      TA6:1;		// Ib过流
    Uint16      TA7:1;		// Ic过流
    Uint16      TA8:1;		// Iac（交流电流）不平衡
    Uint16      TA9:1;		// Ia失相
    Uint16      TA10:1;		// Ib失相
    Uint16      TA11:1;		// Ic失相
    Uint16      TA12:1;		// Ia观测故障
    Uint16      TA13:1;		// Ib观测故障
    Uint16      TA14:1;		// Ic观测故障
    Uint16      TA15:1;		// Iac（交流电流）采样失效
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
//float32 ID_Buffer[1000] ={0};
//float32 IQ_Buffer[1000] ={0};
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

	XX_Flt1.all = 0;

   	InitSysCtrl();//In SysCtrl.c,Disable watchdog,Disable Unused CLK
   	InitGpio();//In Gpio.c,Set GPIO30,GPIO18,GPIO19
	InitXintf();//In Xintf.c,Set 
	
	DELAY_US(10000L);//Delay 10ms, Wait for DSP1
//  while((Ver_DSP1 != 0x11) || (Ver_FPGA != 0x11))
/*	{
		GPIO_Temp181 = GpioDataRegs.GPADAT.bit.GPIO18;
		DELAY_NS(10L);
		GPIO_Temp182 = GpioDataRegs.GPADAT.bit.GPIO18;
		if((GPIO_Temp181 == 0) && (GPIO_Temp182 == 0))
		{
//			Ver_DSP1 = *(XintfZone7 + 0x7FFF);
			Ver_DSP1 = ((*(XintfZone7 + 0x7FFF)) & 0x00FF);
			Ver_FPGA = (((*(XintfZone7 + 0x7FFF))>>8) & 0x00FF);
			if((Ver_DSP1 == 0x11) && (Ver_FPGA == 0x11))
			{
				*(XintfZone7 + 2) = Ver_DSP2;
				*(XintfZone7 + 0x7FFE) = 0x1111;
			}	
		}
	}
*/

	DINT; 
	IER=0x0000;
   	IFR=0x0000;
	InitPieCtrl();
	InitPieVectTable();	
	EALLOW;
	PieVectTable.XINT1 = &DPRAM_isr;
	EDIS;   
	InitCpuTimers();
	InitXInterrupt();//GPIO18,Low Pulse
	InitVariables();
	IER |= M_INT1;
	PieCtrlRegs.PIEIER1.bit.INTx4 = 1;

	//-------------------------------------------------------------------------
	//修改处
	ACI3_initialize();  //电机控制参数初始化
    //-------------------------------------------------------------------------

   	EINT;
   	ERTM;

	while(1)
	{
//--------------------------------------------------------------------------------
		GPIO_Temp181 = GpioDataRegs.GPADAT.bit.GPIO18;
		DELAY_US(2L);//主要是为了判断是否长时间未进入中断复位，此处可采用无效延时，或者插入其他有效的执行任务
		GPIO_Temp182 = GpioDataRegs.GPADAT.bit.GPIO18;
		if((GPIO_Temp181 == 0) && (GPIO_Temp182 == 0))
		{
			Ver_DSP1 = *(XintfZone7 + 0x7FFF);//INTR复位语句
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
	Cnt_us++;
/*	Cnt++;
	if(Cnt>=1000)
	{

			Cnt=0;
	}
*/
	if(Cnt_us>=4000)
	{
		Cnt_sec++;
		Cnt_us=0;
	}
	if(Cnt_sec>=300)
		Cnt_sec=0;



	DPRAM_RD();
	NX_Pr();

//	if(XX_Flt1.all == 0)
		NX_Dsp2PlCn++;
	if(NX_Dsp2PlCn > 32767)
		NX_Dsp2PlCn = 0;

	PI_RmsClc();

//--------------------------------------------------------------------------------------
	//输入!需修改
	in.Vdc = PX_In_Spf.XU_DcLk;         //直流母线电压   V
	in.isa = PX_In_Spf.XI_PhA;		   //A相电流  A
	in.isb = PX_In_Spf.XI_PhB;		   //B相电流   A
	in.isc = PX_In_Spf.XI_PhC;          //C相电流   A
	in.wm = PX_In_Spf.XV_SpdSn1/60*PI2;    //速度  r/min转为rad/s

//	PX_In_Spf.WM_TqCmd = *(XintfZone7 + 0x12) * 0.01;		// torque command, kN*m

	in.wm_ref = PX_In_Spf.WM_TqCmd*100/60*PI2*20;  //指令，作为转速  r/min转为rad/s
//	in.wm_ref = PX_In_Spf.WM_TqCmd*100;        //指令，作为频率Hz 需乘以100
//	in.wm_ref = PX_In_Spf.WM_TqCmd*100;       //指令，作为d轴电流 需乘以100
//	in.thetas = PX_In_Spf.WM_TqCmd*1000/180*3.1415926; //指令，作为角度，0~36
//	in.Ki_i = PX_In_Spf.WM_TqCmd*5000;         //指令，
//	in.wm_ref = PX_In_Spf.WM_TqCmd*100;       //指令，作为q轴电流 需乘以100

//	PX_In_Spf.XV_AtSpdTn = *(XintfZone7 + 0x10) * 0.01;		// actual speed, km/h
//	PX_In_Spf.CX_DrTn = *(XintfZone7 + 0x11);		// direction command

//	in.Kp_i = PX_In_Spf.XV_AtSpdTn*0.2; //
//	in.Kp = PX_In_Spf.XV_AtSpdTn*0.2;



//------------------------------------------------------------------------------------

	if(SX_Dsp2Rd == 1)
	{
		//-----------------------------------------------------------------------------------
		//执行!需修改
		ACI3_step();

//		PX_Out_Spf.XX_Pwm1AVv = 0.2 * PX_Out_Spf.XT_PwmPdVv ;
//		PX_Out_Spf.XX_Pwm2AVv = 0.4 * PX_Out_Spf.XT_PwmPdVv ;
//		PX_Out_Spf.XX_Pwm3AVv = 0.7 * PX_Out_Spf.XT_PwmPdVv ;

//		PX_Out_Spf.XX_Pwm1AVv = out.Taon * PX_Out_Spf.XT_PwmPdVv*2 ;
//		PX_Out_Spf.XX_Pwm2AVv = out.Tbon * PX_Out_Spf.XT_PwmPdVv*2 ;
//		PX_Out_Spf.XX_Pwm3AVv = out.Tcon * PX_Out_Spf.XT_PwmPdVv*2 ;

		PX_Out_Spf.XX_Pwm1AVv = (1-out.Taon*2 )* PX_Out_Spf.XT_PwmPdVv ;
		PX_Out_Spf.XX_Pwm2AVv = (1-out.Tbon*2 )* PX_Out_Spf.XT_PwmPdVv ;
		PX_Out_Spf.XX_Pwm3AVv = (1-out.Tcon*2 )* PX_Out_Spf.XT_PwmPdVv ;

/*
		if(Buffer_cnt<1000)
		{
			ID_Buffer[Buffer_cnt] = out.id;
			IQ_Buffer[Buffer_cnt] = out.iq;
			Buffer_cnt ++;
		}
*/

		SX_Run = 1;
		//---------------------------------------------------------------------------------------
	}
	else
	{
		PX_Out_Spf.XX_Pwm1AVv = 3750;
		PX_Out_Spf.XX_Pwm2AVv =	3750;
		PX_Out_Spf.XX_Pwm3AVv = 3750;
		SX_Run = 0;

		ACI3_terminate();

		Buffer_cnt = 0;
	}

	DPRAM_WR();

	//-----------------------------------------------------------
	/*将dq轴电流传出，0.5s刷新一次*/
    if(SX_Run == 0)
    {
    	/*
    	if(TIME_cnt<5000)
    	{
    		TIME_cnt++;
    	}
    	else
    	{
    		if(Buffer_cnt1<1000)
    		{
    			*(XintfZone7 + 0x29) = ID_Buffer[Buffer_cnt1]*100;
    			*(XintfZone7 + 0x2a) = IQ_Buffer[Buffer_cnt1]*100;
    			Buffer_cnt1 ++;
    		}
    		else
    		{
    			Buffer_cnt1 = 0;
    		}
    		TIME_cnt = 0;
    	}*/
    }
    else
    {
    	TIME_cnt = 0;
    	Buffer_cnt1 = 0;
    }

//---------------------------------------------------------------------
    PieCtrlRegs.PIEACK.all=PIEACK_GROUP1;
    EN_GPIO30();
}
//==============================================================================
void DPRAM_RD(void)
{

	NX_Dsp1PlCn = *(XintfZone7 + 0x7FFF);		// DSP1 pulse(heartbeat) counter    (RAM 0x7FFF clear)


/*	for(i=0;i<27;i++)//采样输入参数
	{
		DPRAM_SAM[i] = *(XintfZone7 + 3 + i);
	}

	IO_abc.a=IO_abc.a * 0.999 + DPRAM_SAM[0] * 0.001;
	IO_abc.c=IO_abc.c * 0.999 + DPRAM_SAM[1] * 0.001;
*/
	NX_Dsp1OpSt = *(XintfZone7 + 0x1);			// DSP1 operation state

	if(NX_Dsp2OpSt == 0x11)						// on DSP2 initial state
	{
		/*
			参数名称	存储地址	传输方向	最大数据范围	精度
			极对（低8）+额定频率（高8）	0x0006	DSP1DSP2	0～255Hz	1=1/1Hz
			电机互感	0x0007	DSP1DSP2	0～32767mH	1=1mH
			电机定子漏感	0x0008	DSP1DSP2	0～32767mH	1=1mH
			电机转子漏感	0x0009	DSP1DSP2	0～32767mH	1=1mH
			电机定子电阻	0x000A	DSP1DSP2	0～32767mΩ	1=1mΩ
			电机转子电阻	0x000B	DSP1DSP2	0～32767mΩ	1=1mΩ
			电机定子磁链(设置参数？)	0x000C	DSP1DSP2	0～32767WB	1=1WB
			D轴Kp参数	0x000D	DSP1DSP2	0～32767	1=1
			D轴Ki参数	0x000E	DSP1DSP2	0～32767	1=1
			Q轴Kp参数	0x000F	DSP1DSP2	0～32767	1=1
			Q轴Ki参数	0x0010	DSP1DSP2	0～32767	1=1
			直流额定电压	0x0011	DSP1DSP2	0～3276.7V	10=1V
			直流额定电流	0x0012	DSP1DSP2	0～3276.7A	10=1A
			交流额定电流	0x0013	DSP1DSP2	0～3276.7A	10=1A
			直流侧稳压控制参数	0x0014	DSP1DSP2	0～32767	1=1
			直流侧振荡抑制参数	0x0015	DSP1DSP2	0～32767	1=1
			制动斩波器参考电压	0x0016	DSP1DSP2	0～32767	1=1
			异步调制区段的基波频率	0x0017	DSP1DSP2	0～32767	10=1Hz
			载波比为21的同步调制区段的基波频率	0x0018	DSP1DSP2	0～32767	10=1Hz
			载波比为15的同步调制区段的基波频率	0x0019	DSP1DSP2	0～32767	10=1Hz
			载波比为7的同步调制区段的基波频率	0x001A	DSP1DSP2	0～32767	10=1Hz
			载波比为5的同步调制区段的基波频率	0x001B	DSP1DSP2	0～32767	10=1Hz
			载波比为3的同步调制区段的基波频率	0x001C	DSP1DSP2	0～32767	10=1Hz
			指令电压（开环调试用）	0x001D	DSP1DSP2	0～3276.7	10=1V
			指令频率（开环调试用）	0x001F	DSP1DSP2	0～3276.7	10=1Hz
		 */

		PX_AsMt.PX_Ppa = *(XintfZone7 + 0x6) & 0x00FF;			// pole pairs
		PX_AsMt.PF_SxFr_Nom = *(XintfZone7 + 0x6) & 0xFF00;		// stator rated(nominal) frequency, Hz

		PX_AsMt.PX_SxRxLm = *(XintfZone7 + 0x7);		// mutual inductance, mH
		PX_AsMt.PX_SxLl = *(XintfZone7 + 0x8);		// stator leakage inductance, mH
		PX_AsMt.PX_RxLl = *(XintfZone7 + 0x9);		// rotor leakage inductance referred to the stator, mH
		PX_AsMt.PR_SxRs = *(XintfZone7 + 0xA);		// stator resistance, mOhm
		PX_AsMt.PR_RxRs = *(XintfZone7 + 0xB);		// rotor resistance referred to the stator, mOhm
		PX_AsMt.PY_RxMag_Nom = *(XintfZone7 + 0xC);		// rotor rated(nominal) flux magnitude, WB

		AsMtDAx.Kp = *(XintfZone7 + 0xD);		// d-axis PI control
		AsMtDAx.Ki = *(XintfZone7 + 0xE);
		AsMtQAx.Kp = *(XintfZone7 + 0xF);		// q-axis PI control
		AsMtQAx.Ki = *(XintfZone7 + 0x10);

		WU_DcLk_Nom = *(XintfZone7 + 0x11) * 0.1;		// nominal voltage reference of DC link, V
		WI_DcLk_Nom = *(XintfZone7 + 0x12) * 0.1;		// nominal current reference of DC link, A
		WI_Ac_Nom = *(XintfZone7 + 0x13) * 0.1;		// nominal AC current reference, A

		PX_DcLkStbU = *(XintfZone7 + 0x14);		// DC-link voltage stabilized parameter
		PX_DcLkOscSpr = *(XintfZone7 + 0x15);	// DC-link oscillation suppressed parameter
		WU_BrCp = *(XintfZone7 + 0x16);		// voltage reference of brake chopper

		PF_HybMod_Spf.PF_AsMod = *(XintfZone7 + 0x17) * 0.1;		// asynchronous modulation, Hz
		PF_HybMod_Spf.PF_SynRt21Mod = *(XintfZone7 + 0x18) * 0.1;		// synchronous modulation ratio=21, Hz
		PF_HybMod_Spf.PF_SynRt15Mod = *(XintfZone7 + 0x19) * 0.1;		// synchronous modulation ratio=15, Hz
		PF_HybMod_Spf.PF_SynRt7Mod = *(XintfZone7 + 0x1A) * 0.1;		// synchronous modulation ratio=7, Hz
		PF_HybMod_Spf.PF_SynRt5Mod = *(XintfZone7 + 0x1B) * 0.1;		// synchronous modulation ratio=5, Hz
		PF_HybMod_Spf.PF_SynRt3Mod = *(XintfZone7 + 0x1C) * 0.1;		// synchronous modulation ratio=3, Hz

		WU_OpLo = *(XintfZone7 + 0x1D) * 0.1;			// voltage   reference for open loop
		WF_OpLo = *(XintfZone7 + 0x1F) * 0.1;			// frequency reference for open loop

//		Nt_Warn();		// initialization warn

		if(SX_NtFlt == 1)						// initialization fault bit
		{
			XX_NtFltCn++;
			NX_Dsp2OpSt = 0x11;				// start initialization
		}
		else
		{
			XX_NtFltCn = 0;
			NX_Dsp2OpSt = 0x33;				// initialization finished
		}

		if(XX_NtFltCn > 3)
			NX_Dsp2OpSt = 0x22;					// 0x22: DSP2 initialization failed

	}
	else if(NX_Dsp2OpSt == 0x33)
	{
		/*
		参数名称	存储地址	传输方向	最大数据范围	精度
		DSP1的运行状态	0x0001	专用	DSP1DSP2	-32767～32767
		直流电压	0x0006	DSP1DSP2	0～3276.7V	10=1V
		直流电流	0x0007	DSP1DSP2	0～3276.7A	10=1A
		交流电流A（瞬时值）	0x0008	DSP1DSP2	-3276.7～3276.7A	10=1A
		交流电流B（瞬时值）	0x0009	DSP1DSP2	-3276.7～3276.7A	10=1A
		交流电流C（瞬时值）	0x000A	DSP1DSP2	-3276.7～3276.7A	10=1A
		转速1	0x000B	DSP1DSP2	0～32767rad/min	1=1rad/min
		转速2	0x000C	DSP1DSP2	0～32767rad/min	1=1rad/min
		实际方向	0x000D	DSP1DSP2	0x1111代表前进		0x2222代表后退	-
		轴温1（低8）+轴温2（高8）	0x000E	DSP1DSP2	0～255℃	1=1℃
		内温（低8）+散热器温（高8）	0x000F	DSP1DSP2	0～255℃	1=1℃
		实际车速（VCU下发）	0x0010	DSP1DSP2	0～327.67	100=1kM/h
		方向指令（VCU下发）	0x0011	DSP1DSP2	0x1111代表前进		0x2222代表后退	-
		转矩/牵引力指令（VCU下发）	0x0012	DSP1DSP2	-327.67～327.67	100=1kN
		列车重量（VCU下发）	0x0013	DSP1DSP2	0～3276.7	10=1Ton
		环温（VCU下发）	0x0014	DSP1DSP2	0～327.67	100=1℃
		DSP1的心跳信息	0x7FFF	专用，用以DPRAM的INTR信号置位	DSP1DSP2	0～32767循环
		*/
		PX_In_Spf.XU_DcLk = *(XintfZone7 + 0x6) * 0.1;			// DC-link voltage, V
		PX_In_Spf.XI_DcLk = *(XintfZone7 + 0x7) * 0.1;			// DC current, A
		PX_In_Spf.XI_PhA = *(XintfZone7 + 0x8) * 0.1*(-1.0);	// phase A current, A
		PX_In_Spf.XI_PhC = *(XintfZone7 + 0x9) * 0.1*(-1.0);	// phase B current, A
		PX_In_Spf.XI_PhB = *(XintfZone7 + 0xA) * 0.1*(-1.0);	// phase C current, A
		PX_In_Spf.XV_SpdSn1 = *(XintfZone7 + 0xB);				// rotate speed 1, rad/min
		PX_In_Spf.XV_SpdSn2 = *(XintfZone7 + 0xC);				// rotate speed 2, rad/min
		PX_In_Spf.SX_AtDrTn = *(XintfZone7 + 0xD);				// actual direction of train
		PX_In_Spf.XH_AxTpSn1 = *(XintfZone7 + 0xE) & 0x00FF;	// temperature 1 of axle, C
		PX_In_Spf.XH_AxTpSn2 = *(XintfZone7 + 0xE) & 0xFF00;	// temperature 2 of axle, C
		PX_In_Spf.XH_InnTp = *(XintfZone7 + 0xF) & 0x00FF;		// inner temperature, C
		PX_In_Spf.XH_HtTp = *(XintfZone7 + 0xF) & 0xFF00;		// heatsink temperature, C
		PX_In_Spf.XV_AtSpdTn = *(XintfZone7 + 0x10) * 0.01;		// actual speed, km/h
		PX_In_Spf.CX_DrTn = *(XintfZone7 + 0x11);				// direction command
		PX_In_Spf.WM_TqCmd = *(XintfZone7 + 0x12) * 0.01;		// torque command, kN*m
		PX_In_Spf.XX_TnWgh = *(XintfZone7 + 0x13) * 0.1;		// train weight, Ton
		PX_In_Spf.XH_AmTp = *(XintfZone7 + 0x14) * 0.01;		// ambient temperature, C
	}
}


//==============================================================================
void DPRAM_WR(void)
{
	/*
		DSP2的运行状态	0x0002	专用	DSP2DSP1	-32767～32767
		DSP2的版本信息	0x0003	专用	DSP2DSP1	-
		PWM周期数值	0x0015	DSP2DSP1	0～32767	-
		PWM1A比较器数值	0x0016	DSP2DSP1	0～32767	-
		PWM2A比较器数值	0x0017	DSP2DSP1	0～32767	-
		PWM3A比较器数值	0x0018	DSP2DSP1	0～32767	-
		PWM4A比较器数值（斩波）	0x0019	DSP2DSP1	0～32767	-
		输入功率	0x001A	DSP2DSP1	0～3276.7	10=1kW
		输出功率	0x001B	DSP2DSP1	0～3276.7	10=1kW
		输出转矩	0x001C	DSP2DSP1	-3276.7～3276.7	10=1kN
		相不平衡度	0x001D	DSP2DSP1	0～327.67	100=1%
		交流电流A（RMS）	0x001F	DSP2DSP1	0～3276.7	10=1A
		交流电流B（RMS）	0x0020	DSP2DSP1	0～3276.7	10=1A
		交流电流C（RMS）	0x0021	DSP2DSP1	0～3276.7	10=1A
		制动电阻温度估算值	0x0022	DSP2DSP1	0～3276.7	10=1℃
		电抗器温度估算值	0x0023	DSP2DSP1	0～3276.7	10=1℃
		故障状态值1	0x0024	DSP2DSP1	15种故障标志	-
		故障状态值2	0x0025	DSP2DSP1	15种故障标志	-
		故障状态值3	0x0026	DSP2DSP1	15种故障标志	-
		故障状态值4	0x0027	DSP2DSP1	15种故障标志	-
		故障状态值5	0x0028	DSP2DSP1	15种故障标志	-
		增加DA输出0~6，共计7路，对应DPRAM地址为43~49，硬件对应于X101的20~26脚，其中21~24在IOB板上有调理电路，可以在IOB板上引出测试，其他脚直接是DA输出，没有调理，只能在X101上引出测试
		DA      0x0043           13bit   -4096~4096
		DSP2的心跳信息	0x7FFE	专用，用以DPRAM的INTL信号置位	DSP2DSP1	0～32767循环
	 */
	*(XintfZone7 + 0x2) = NX_Dsp2OpSt;		// NX_Dsp2OpSt: DSP2 operation state
	*(XintfZone7 + 0x3) = NX_Dsp2Ver;		// DSP2 version

//	*(XintfZone7 + 0x15) = (PX_Out_Spf.XT_PwmHSPCLKDIV << 8) | PX_Out_Spf.XT_PwmCLKDIV;		// PWM period module configuration
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

//	*(XintfZone7 + 0x25) = sqrt(fe2.PsiDrS*fe2.PsiDrS+fe2.PsiQrS*fe2.PsiQrS);
//	*(XintfZone7 + 0x26) = fe2.ThetaFlux;

	*(XintfZone7 + 0x25) = psir*100;
	*(XintfZone7 + 0x26) = thetas*100;

//	*(XintfZone7 + 0x27) = fe1.psir*100;
//	*(XintfZone7 + 0x28) = tc1.thetas*100;

	*(XintfZone7 + 0x27) = acr1.usM;
	*(XintfZone7 + 0x28) = acr1.usT;

//	*(XintfZone7 + 0x25) = asr1.Ref*100;
//	*(XintfZone7 + 0x26) = asr1.Fbk*100;

//	*(XintfZone7 + 0x27) = asr1.Out*100;
//	*(XintfZone7 + 0x28) = ws*100;

	*(XintfZone7 + 0x29) = acr1.isM*10;
	*(XintfZone7 + 0x2a) = acr1.isT*10;

//	*(XintfZone7 + 0x27) = acr1.isM_ref*10;
//	*(XintfZone7 + 0x28) = acr1.isM*10;

//	*(XintfZone7 + 0x29) = acr1.isT_ref*10;
//	*(XintfZone7 + 0x2a) = acr1.isT*10;

	*(XintfZone7 + 0x2b) = 0x1FFF;
	*(XintfZone7 + 0x2c) = 0x1001;
	*(XintfZone7 + 0x2d) = 0x1000;
	*(XintfZone7 + 0x2e) = 0x0FFF;
	*(XintfZone7 + 0x2f) = 0x0001;
	*(XintfZone7 + 0x30) = 0x0000;
	*(XintfZone7 + 0x31) = 0x0ABC;

	*(XintfZone7 + 0x7FFE) = NX_Dsp2PlCn;		// DSP2 pulse(heartbeat) counter	 (RAM 0x7FFE clear)
}

//==============================================================================
void Nt_Warn(void)		// initialization warn    根据实际情况再修改
{
	SX_NtFlt = 0;

	if(PX_AsMt.PX_Ppa > 50 || PX_AsMt.PX_Ppa < 1)			// pole pairs
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PX_AsMt.PF_SxFr_Nom > 512 || PX_AsMt.PF_SxFr_Nom < 1)		// stator rated(nominal) frequency
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PX_AsMt.PX_SxRxLm > 3000)		// mutual inductance, mH
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PX_AsMt.PX_SxLl > 1500 || PX_AsMt.PX_SxLl > PX_AsMt.PX_SxRxLm)		// stator leakage inductance, mH
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PX_AsMt.PX_RxLl > 1500 || PX_AsMt.PX_RxLl > PX_AsMt.PX_SxRxLm)		// rotor leakage inductance referred to the stator
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PX_AsMt.PR_SxRs > 5000)		// stator resistance, mOhm
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PX_AsMt.PR_RxRs > 5000)		// rotor resistance referred to the stator, mOhm
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PX_AsMt.PY_RxMag_Nom > 500)		// rotor rated(nominal) flux magnitude
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(WU_DcLk_Nom > 20000 || WU_DcLk_Nom < 0)		// nominal voltage reference of DC link
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(WI_DcLk_Nom > 50000 || WI_DcLk_Nom < 0)		// nominal current reference of DC link
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(WI_Ac_Nom > 50000 || WI_Ac_Nom < 0)		// nominal AC current reference
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(WU_BrCp > 22000 || WU_BrCp < 10)		// voltage reference of brake chopper
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PF_HybMod_Spf.PF_AsMod > 1000 && PF_HybMod_Spf.PF_AsMod < 0)		// asynchronous modulation
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PF_HybMod_Spf.PF_SynRt21Mod > PX_AsMt.PF_SxFr_Nom || PF_HybMod_Spf.PF_SynRt21Mod < 0)		// synchronous modulation ratio=21
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PF_HybMod_Spf.PF_SynRt15Mod > PX_AsMt.PF_SxFr_Nom || PF_HybMod_Spf.PF_SynRt15Mod < PF_HybMod_Spf.PF_SynRt21Mod)		// synchronous modulation ratio=15
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PF_HybMod_Spf.PF_SynRt7Mod > PX_AsMt.PF_SxFr_Nom || PF_HybMod_Spf.PF_SynRt7Mod < PF_HybMod_Spf.PF_SynRt15Mod)		// synchronous modulation ratio=7
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

/*	if(PF_HybMod_Spf.PF_SynRt5Mod > PX_AsMt.PF_SxFr_Nom || PF_HybMod_Spf.PF_SynRt5Mod < PF_HybMod_Spf.PF_SynRt7Mod)		// synchronous modulation ratio=5
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(PF_HybMod_Spf.PF_SynRt3Mod > PX_AsMt.PF_SxFr_Nom || PF_HybMod_Spf.PF_SynRt3Mod < PF_HybMod_Spf.PF_SynRt5Mod)		// synchronous modulation ratio=3
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;
*/
	if(WU_OpLo > 20000 && WU_OpLo < 0)		// voltage   reference for open loop
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;

	if(WF_OpLo > 150 && WF_OpLo < 0)		// frequency reference for open loop
		SX_NtFlt = SX_NtFlt | 1;
	else
		SX_NtFlt = SX_NtFlt | 0;
}

//==============================================================================
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
//==============================================================================
void PI_RmsClc(void)
{		
	if(Cnt_Period<256)
	{
		PI_PhARms.Square += (PX_In_Spf.XI_PhA * PX_In_Spf.XI_PhA);
		PI_PhBRms.Square += (PX_In_Spf.XI_PhB * PX_In_Spf.XI_PhB);
		PI_PhCRms.Square += (PX_In_Spf.XI_PhC * PX_In_Spf.XI_PhC);
		Cnt_Period++;
	}		
}
//===============================================================================================
void DIS_CAL(void)
{
	if(Cnt_Period>=256)
	{
		Cnt_Period=256;

		PI_PhARms.Rms = __ffsqrtf(PI_PhARms.Square * 0.00390625);		// 0.00390625 = 1/256  square root function
		PI_PhBRms.Rms = __ffsqrtf(PI_PhBRms.Square * 0.00390625);		// 0.00390625 = 1/256
		PI_PhCRms.Rms = __ffsqrtf(PI_PhARms.Square * 0.00390625);		// 0.00390625 = 1/256
		PI_PhARms.Square = 0;
		PI_PhBRms.Square = 0;
		PI_PhCRms.Square = 0;

		Cnt_Period=0;
	}
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
	if((PI_PhARms.Rms>=IO_RMS_OVER)||(PI_PhBRms.Rms>=IO_RMS_OVER)||(PI_PhCRms.Rms>=IO_RMS_OVER))     //三相输出有效值过流
	{Cnt_IORMS++;}
	else
	{Cnt_IORMS=0;}
	if(Cnt_IORMS>=5)
	{Cnt_IORMS=5;ERR_IORMS=1;}
	else
	{ERR_IORMS=0;}   
}

//==============================================================================================
void InitVariables(void)
{
	Uint16 i=0;

	TCU_Mode = 0x00;                  
	Ver_DSP1 = 0;Ver_FPGA = 0;

	for(i=0;i<50;i++)
	{  
	  DPRAM_SAM[i] = 0;
	}
}

void InitMode(void)
{
	TCU_Mode = 0x00;
}
//===============================================================================================
//=========================================THE END===============================================
//===============================================================================================

