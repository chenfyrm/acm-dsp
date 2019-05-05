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

/* INCLUDES */
#include "DSP28x_Project.h"

/* EXTERNAL FUNCTION PROTOTYPES */

/* DESCRIPTION */

/* DEFINES */
//--------------------------------------------------------------------------------


/* TYPEDEFS */


/*STRUCTDEFS*/
//-----------------input-------------------------
//采样、指令
struct MCUFLAG1_BITS
{
	Uint16	RstSa:1;
	Uint16	OvpAv:1;
	Uint16	CdAuLdCt:1;
	Uint16	RstFlt:1;
	Uint16	BtCpAv:1;
	Uint16	CvOp:1;
	Uint16	TA6:1;
	Uint16	TA7:1;
	Uint16	TA8:1;
	Uint16	TA9:1;
	Uint16	TA10:1;
	Uint16	TA11:1;
	Uint16	TA12:1;
	Uint16	TA13:1;
	Uint16	TA14:1;
	Uint16	TA15:1;
};

union MCUFLAG1_REG
{
	Uint16	all;
	struct MCUFLAG1_BITS bit;
};

struct PX_In
{
	float32 XU_DcLk;   		    		// DC-link voltage, V
    float32	XI_DcLk;   				// DC current, A
	float32 XI_PhA;						// phase A current, A
	float32 XI_PhB;						// phase B current, A
	float32	XI_PhC;			  	  		// phase C current, A
	float32 XU_PhABGt;					// AB相线电压, V
	Uint16 	NX_McuPlCn;				// MCU pulse(heartbeat) counter
	Uint16 	NX_McuOpSt;				// MCU operation state
	Uint16 	NX_McuVer;			// MCU version
	union MCUFLAG1_REG XX_McuFlag1;
};
volatile struct PX_In PX_In_Spf = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0,
		0x400,
		0x10,
		0x00,};
//========================================================================
//保护值
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
	float32  XH_AmTp_Max;         		// ambient temperature, C
};
volatile struct PX_InPr PX_InPr_Spf = {
		750.0,//直流母线电压上限
		36.0,//直流母线电压下限
		0,
		0,
		10.0,//直流母线电流上限
		0,
		100.0,//逆变器输出电流上限
		0,
		0,
		0,
		0.0,};//环境温度上限
//-------------output-------------
//============================================================================================
struct  WARN_BITS
{
    Uint16      TA0:1;		//直流母线过压、欠压保护
    Uint16      TA1:1;		//直流母线过流保护
    Uint16      TA2:1;		// Idc 采样保护
    Uint16      TA3:1;		// Udc 采样保护
    Uint16      TA4:1;		// DSP
    Uint16      TA5:1;		//A相电流过流保护
    Uint16      TA6:1;		//B相电流过流保护
    Uint16      TA7:1;		//C相电流过流保护
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
    Uint16             	all;
    struct WARN_BITS	bit;
};

struct DSPFLAG1_BITS
{
	Uint16	CdAuLdCt:1;
	Uint16	CvOp:1;
	Uint16	OvpFcTs:1;
	Uint16	OvpAv:1;
	Uint16	IPhClTrsAv:1;
	Uint16	OvMdAv:1;
	Uint16	BtCpAv:1;
	Uint16	TA7:1;
	Uint16	TA8:1;
	Uint16	TA9:1;
	Uint16	TA10:1;
	Uint16	TA11:1;
	Uint16	TA12:1;
	Uint16	TA13:1;
	Uint16	TA14:1;
	Uint16	TA15:1;
};

union DSPFLAG1_REG
{
	Uint16	all;
	struct DSPFLAG1_BITS bit;
};

struct DSPST_BITS
{
	Uint16	CvSt:8;
	Uint16	OvpCp:4;
	Uint16	BtCp:4;
};

union DSPST_REG
{
	Uint16	all;
	struct DSPST_BITS bit;
};

//输出交互值
struct PX_Out
{
	Uint16  		XX_PwmMo;			// PWM mode  0x00  0x15
	Uint16  		XT_PwmPdVv;   		// PWM period value,  for initialization
	Uint16  		XX_Pwm1AVv;   		// PWM1A value
	Uint16  		XX_Pwm2AVv;			// PWM2A value
	Uint16  		XX_Pwm3AVv;			// PWM3A value
	Uint16  		XX_Pwm4AVv;			// PWM4A value, chopper
	Uint16  		XX_Pwm4BVv;			// PWM4B value, chopper
	float32 		XP_Out;		    	// output power, kw
	float32 		XX_PhUbl;			// phase unbalance
	float32 		XI_PhA_Rms;		    // phase A current, RMS
	float32 		XI_PhB_Rms;	    	// phase B current, RMS
	float32 		XI_PhC_Rms;		    // phase C current, RMS
	float32			XU_PhAB_Rms;
	union WARN_REG	XX_Flt1;			// 16位故障字
	Uint16			SX_Run;
	Uint16 			NX_DspPlCn;			// DSP2 pulse(heartbeat) counter
	union DSPST_REG NX_DspOpSt;			// NX_Dsp2OpSt: DSP2 operation state 0x11:初始化中      0x22:初始化失败    0x33:初始化完成
	union DSPST_REG	oldDspSt;
	Uint16 			NX_DspVer;			// DSP2 version
	union DSPFLAG1_REG XX_DspFlag1;

};
volatile struct PX_Out PX_Out_Spf = {
		21,
		6944,//双采样：1450Hz:6465 1350Hz:6944
		3472,
		3472,
		3472,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0x0000,
		0x0000,
		0x10,
		0x00,};
//========================================================
struct PI_Rms
{
	float32 Square;
	float32 Rms;
};
volatile struct PI_Rms PI_PhARms = {0, 0};
volatile struct PI_Rms PI_PhBRms = {0, 0};
volatile struct PI_Rms PI_PhCRms = {0, 0};
volatile struct PI_Rms PU_PhABRms = {0, 0};
//======================================================================
/* GLOBALS */



/* LOCALS */
//int16	*XintfZone0=(int16 *)0x004000;//Unused
//int16	*XintfZone6=(int16 *)0x100000;//Unused
int16	*XintfZone7=(int16 *)0x200000;//DP RAM
//=======================================================================
Uint16	GPIO_Temp181,GPIO_Temp182;
//TYPE_UFCTRL_IF acmctrl = UFCTRL_IF_DEFAULTS;
//TYPE_DOSGPLL dosgpll = DOSGPLL_DEFAULTS;
TYPE_UFCOMA acmctrl = UFCOMA_DEFAULTS;
TYPE_SOGIOSGMA sogiosg = SOGIOSGMA_DEFAULTS;
//===========================================================================
Uint16	Cnt_Period =0;
Uint16	Cnt_us = 0;
Uint16 	Cnt_sec = 0;
Uint16	Cnt_min = 0;
Uint16	Sign = 0;
float32 IOvA = 0;
float32 IOvB = 0;
float32 IOvC = 0;
float32 Theta = 0.0;
//Uint16	sign = 0;

int16 DA[8] = {0};


/* LOCAL FUNCTIONS */
void DPRAM_RD(void);
void DPRAM_WR(void);
void NX_Pr(void);
void EN_GPIO30(void);
void DIS_GPIO30(void);
interrupt void DPRAM_isr(void);
void PI_RmsClc(void);
void DspStCl(void);
void OvpFcTsCp(void);
void OvpCp(void);
void BtCp(void);
//=================================================================================
/* MAIN */
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
			PX_In_Spf.NX_McuPlCn = *(XintfZone7 + 0x7FFF);//INTR复位语句,SDRAM读操作,SDRAM产生中断源
		}
	}
}
//==============================================================================
interrupt void DPRAM_isr(void)   					//after DSP1 has written to DPRAM, trigger the interrupt
{  
	PX_Out_Spf.NX_DspPlCn++;
	if(PX_Out_Spf.NX_DspPlCn > 32767)
		PX_Out_Spf.NX_DspPlCn = 0;

	Cnt_Period ++;
	if(Cnt_Period>=2700)
	{
		Cnt_sec++;
		Cnt_Period = 0;
	}
	if(Cnt_sec>=60)
	{
		Cnt_min++;
		Cnt_sec = 0;
	}
	if(Cnt_min >=60)
	{
		Cnt_min = 60;
	}

	DIS_GPIO30();
	DPRAM_RD(); //读MCU交互信息

	acmctrl.XI_PhA = PX_In_Spf.XI_PhA;
	acmctrl.XI_PhB = PX_In_Spf.XI_PhB;
	acmctrl.XI_PhC = PX_In_Spf.XI_PhC;
	acmctrl.XU_DcLk = PX_In_Spf.XU_DcLk;
	acmctrl.XI_DcLk = PX_In_Spf.XI_DcLk;
	acmctrl.XU_PhABLk = PX_In_Spf.XU_PhABGt;

	PI_RmsClc();
	PX_Out_Spf.XI_PhA_Rms = PI_PhARms.Rms;
	PX_Out_Spf.XI_PhB_Rms = PI_PhBRms.Rms;
	PX_Out_Spf.XI_PhC_Rms = PI_PhCRms.Rms;
	PX_Out_Spf.XU_PhAB_Rms = PU_PhABRms.Rms;

	sogiosg.phase = PX_In_Spf.XU_PhABGt;
	sogiosg.Ts = 1.0/2700.0;
	sogiosg.w = 100*3.1415926;
	sogiosg.K = sqrt(2);
	SOGIOSGFLL(&sogiosg);

	acmctrl.XX_UPeakCom = 1.04;
	acmctrl.XX_AngleCom = PI/2.0;

	acmctrl.XU_3PhAl = (sogiosg.alpha*cos(acmctrl.XX_AngleCom) - sogiosg.beta*sin(acmctrl.XX_AngleCom))*acmctrl.XX_UPeakCom;
	acmctrl.XU_3PhBe = (sogiosg.alpha*sin(acmctrl.XX_AngleCom) + sogiosg.beta*cos(acmctrl.XX_AngleCom))*acmctrl.XX_UPeakCom;

	acmctrl.XU_3PhRms = sogiosg.peak/SQRT2;

	NX_Pr();

	DspStCl();

	/**/
	if(acmctrl.A_CvOp == 1)
	{
		UFCOMAStep(&acmctrl);
		DspStep(&acmctrl);

		if(acmctrl.XX_Mode == 1)
		{
			PX_Out_Spf.XX_PwmMo = 21;// FPGA逻辑：计数器值大于比较器值为高，加死区，取反，经光纤板再反向
			PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv*(1.0-acmctrl.XX_DutyA);
			PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv*(1.0-acmctrl.XX_DutyB);
			PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv*(1.0-acmctrl.XX_DutyC);
		}
		if(acmctrl.XX_Mode == 0)
		{
			PX_Out_Spf.XX_PwmMo = 0;// FPGA逻辑：计数器值小于比较器值为高，加死区，取反，经光纤板再反向
			PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv*acmctrl.XX_DutyA;
			PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv*acmctrl.XX_DutyB;
			PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv*acmctrl.XX_DutyC;
		}
	}
	else
	{
		PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv*0.5;
		PX_Out_Spf.XX_Pwm2AVv =	PX_Out_Spf.XT_PwmPdVv*0.5;
		PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv*0.5;
	}

	DPRAM_WR();//写dsp交互信息
    PieCtrlRegs.PIEACK.all|=PIEACK_GROUP1;

    EN_GPIO30();
}
//==============================================================================
void DPRAM_RD(void)//MCU-->DSP
{
	//----------------------------------------------------
	PX_In_Spf.NX_McuPlCn = *(XintfZone7 + 0x7FFF);		// MCU pulse(heartbeat) counter    (RAM 0x7FFF clear) 此行最先读，产生DPRAM中断源
	//---------------------------------------------------------------------
	PX_In_Spf.NX_McuOpSt = *(XintfZone7 + 0x0001);			// MCU operation state
//	PX_In_Spf.NX_McuVer = 0x10;
	PX_In_Spf.XX_McuFlag1.all = *(XintfZone7 + 0x0014);

	PX_In_Spf.XU_DcLk = *(XintfZone7 + 0x6) * 0.1 * 2.0;		// DC-link voltage, V
	PX_In_Spf.XI_DcLk = 0;// DC-link current, V
	PX_In_Spf.XI_PhA = *(XintfZone7 + 0x8)*0.1/2.0*(-1.0);				// phase A current, A
	PX_In_Spf.XI_PhB = *(XintfZone7 + 0xA)*0.1/2.0*(-1.0);				// phase B current, A
	PX_In_Spf.XI_PhC = *(XintfZone7 + 0x9)*0.1/2.0*(-1.0);				// phase C current, A
	PX_In_Spf.XU_PhABGt= *(XintfZone7 + 0x7) * 0.1*2.0;			// AB相输出线电压, V 采样滤波对幅值的衰减 50Hz时衰减为0.5
}
//==============================================================================
void DPRAM_WR(void)//DSP-->MCU
{
	*(XintfZone7 + 0x2) =  PX_Out_Spf.NX_DspOpSt.all;		// NX_Dsp2OpSt: DSP2 operation state
	*(XintfZone7 + 0x3) =  PX_Out_Spf.NX_DspVer;		// DSP version
	*(XintfZone7 + 0x15) = PX_Out_Spf.XX_PwmMo;     		// PWM  mode configuration
	*(XintfZone7 + 0x16) = PX_Out_Spf.XT_PwmPdVv;			// PWM period value
	*(XintfZone7 + 0x17) = PX_Out_Spf.XX_Pwm1AVv;			// PWM1A value
	*(XintfZone7 + 0x18) = PX_Out_Spf.XX_Pwm2AVv;			// PWM2A value
	*(XintfZone7 + 0x19) = PX_Out_Spf.XX_Pwm3AVv;			// PWM3A value
	*(XintfZone7 + 0x1A) = PX_Out_Spf.XX_Pwm4AVv;			// PWM4A value, chopper

	*(XintfZone7 + 0x25) = PX_Out_Spf.XX_DspFlag1.all;
	*(XintfZone7 + 0x26) = PX_Out_Spf.XX_Flt1.all;		// DSP故障状态
	/*上位机*/
	/*电压闭环*/
	*(XintfZone7 + 0x24) = acmctrl.WF_3PhDsp*100.0;
	*(XintfZone7 + 0x27) = acmctrl.U3PhCl.Ref*100.0;
	*(XintfZone7 + 0x28) = acmctrl.U3PhCl.Fbk*100.0;
	*(XintfZone7 + 0x29) = acmctrl.U3PhCl.Out*100.0;
	*(XintfZone7 + 0x2A) = acmctrl.XX_M*100.0;
	/*同步*/

	/*DA输出*/

	/**/
	DA[3] = acmctrl.XU_3PhAl*10.0;
	DA[4] = acmctrl.XU_3PhBe*10.0;
	DA[5] = 0.0;
	DA[6] = 0.0;
	DA[7] = 0.0;

	if(DA[3] >= 4095)
		DA[3] = 4095;
	if(DA[3] <= -4095)
		DA[3] = -4095;
	if(DA[4] >= 4095)
		DA[4] = 4095;
	if(DA[4] <= -4095)
		DA[4] = -4095;
	if(DA[5] >= 4095)
		DA[5] = 4095;
	if(DA[5] <= -4095)
		DA[5] = -4095;
	if(DA[6] >= 4095)
		DA[6] = 4095;
	if(DA[6] <= -4095)
		DA[6] = -4095;
	if(DA[7] >= 4095)
		DA[7] = 4095;
	if(DA[7] <= -4095)
		DA[7] = -4095;
	*(XintfZone7 + 0x2B) = DA[3];
	*(XintfZone7 + 0x2C) = DA[4];
	*(XintfZone7 + 0x2D) = DA[5];
	*(XintfZone7 + 0x2E) = DA[6];
	*(XintfZone7 + 0x2F) = DA[7];
	/*DA测试*/

//---------------------------------------------------
	*(XintfZone7 + 0x7FFE) = PX_Out_Spf.NX_DspPlCn;//此行最后写，DPRAM产生中断源
//------------------------------------------------------------
}
//==============================================================================
/* 保护 */
void NX_Pr(void)
{
//-------------------Udc over-voltage--------------------
	if(PX_In_Spf.XU_DcLk > PX_InPr_Spf.XU_DcLk_Max)
	{
		PX_InPr_Spf.XU_DcLkOvCn++;
		if(PX_InPr_Spf.XU_DcLkOvCn > 3)
		{
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA0 = 1;
			PX_InPr_Spf.XU_DcLkOvCn = 4;
		}
	}
	else
		PX_InPr_Spf.XU_DcLkOvCn = 0;

//------------------Udc under-voltage---------------------
	if((PX_In_Spf.XU_DcLk < PX_InPr_Spf.XU_DcLk_Min) && PX_Out_Spf.SX_Run == 1)
	{
		PX_InPr_Spf.XU_DcLkUnCn++;
		if(PX_InPr_Spf.XU_DcLkUnCn > 3)
		{
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA0 = 1;
			PX_InPr_Spf.XU_DcLkUnCn = 4;
		}
	}
	else
		PX_InPr_Spf.XU_DcLkUnCn = 0;

//-----------------------DC-link over-current--------------------------------
	if(PX_In_Spf.XI_DcLk > PX_InPr_Spf.XI_DcLk_Max)
	{
		PX_InPr_Spf.XI_DcLkOvCn ++;
		if(PX_InPr_Spf.XI_DcLkOvCn > 3)
		{
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA1 = 1;
			PX_InPr_Spf.XI_DcLkOvCn = 4;
		}
	}
	else
		PX_InPr_Spf.XI_DcLkOvCn = 0;

//-----------------------phase A over-current------------------------
	if((PX_In_Spf.XI_PhA > PX_InPr_Spf.XI_PhABC_Max) || (PX_In_Spf.XI_PhA < -PX_InPr_Spf.XI_PhABC_Max))
	{
		PX_InPr_Spf.XI_PhAOvCn++;
		if(PX_InPr_Spf.XI_PhAOvCn > 3)
		{
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA5 = 1;
			PX_InPr_Spf.XI_PhAOvCn = 4;
			IOvA = PX_In_Spf.XI_PhA;
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
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA6 = 1;
			PX_InPr_Spf.XI_PhBOvCn = 4;
			IOvB = PX_In_Spf.XI_PhB;
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
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA7 = 1;
			PX_InPr_Spf.XI_PhCOvCn = 4;
			IOvC = PX_In_Spf.XI_PhC;
		}
	}
	else
		PX_InPr_Spf.XI_PhCOvCn = 0;

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

//==============================================================================
void PI_RmsClc(void)
{
	if(Cnt_Period<256)
	{
		PI_PhARms.Square += (PX_In_Spf.XI_PhA * PX_In_Spf.XI_PhA);
		PI_PhBRms.Square += (PX_In_Spf.XI_PhB * PX_In_Spf.XI_PhB);
		PI_PhCRms.Square += (PX_In_Spf.XI_PhC * PX_In_Spf.XI_PhC);
		PU_PhABRms.Square += (PX_In_Spf.XU_PhABGt * PX_In_Spf.XU_PhABGt);
		Cnt_Period++;
	}
	if(Cnt_Period>=256)
	{
		PI_PhARms.Rms = __ffsqrtf(PI_PhARms.Square * 0.00390625);		// 0.00390625 = 1/256  square root function
		PI_PhBRms.Rms = __ffsqrtf(PI_PhBRms.Square * 0.00390625);		// 0.00390625 = 1/256
		PI_PhCRms.Rms = __ffsqrtf(PI_PhARms.Square * 0.00390625);		// 0.00390625 = 1/256
		PU_PhABRms.Rms = __ffsqrtf(PU_PhABRms.Square * 0.00390625);		// 0.00390625 = 1/256
		PI_PhARms.Square = 0;
		PI_PhBRms.Square = 0;
		PI_PhCRms.Square = 0;
		PU_PhABRms.Square = 0;
		Cnt_Period=0;
	}
}

//=================
void OvpCp(void)
{

}
//=================
void BtCp(void)
{

}
//==================
void DspStCl(void)
{
	//-------------------------------------------
	//初始化
		if(PX_Out_Spf.oldDspSt.all == 0x0000)
		{
			//
			//
			if(PX_In_Spf.NX_McuOpSt == 0x402)
				PX_Out_Spf.NX_DspOpSt.all = 0x0010;
		}
		else if(PX_Out_Spf.oldDspSt.all == 0x0010)
		{
			//---
			//---
			if(1)
			{
				if(PX_In_Spf.NX_McuOpSt == 0x403)
					PX_Out_Spf.NX_DspOpSt.all = 0x0020;
			}
			else
				PX_Out_Spf.NX_DspOpSt.all = 0x0060;
		}
		else if(PX_Out_Spf.oldDspSt.all == 0x0020)
		{
			//参数初始化
				UFCOMAInit(&acmctrl);
			//
			if(1)
				PX_Out_Spf.NX_DspOpSt.all = 0x0030;
			else
				PX_Out_Spf.NX_DspOpSt.all = 0x0060;
		}
		else if(PX_Out_Spf.oldDspSt.all == 0x0030)
		{
			if((PX_In_Spf.XX_McuFlag1.bit.OvpAv == 1)&&(PX_In_Spf.NX_McuOpSt == 0x405))
				PX_Out_Spf.NX_DspOpSt.all = 0x0130;
		}
		else if(PX_Out_Spf.oldDspSt.all == 0x0130)
		{
			//
			//
			PX_Out_Spf.NX_DspOpSt.all = 0x0230;
			PX_Out_Spf.XX_DspFlag1.bit.OvpFcTs = 1;
		}
		else if(PX_Out_Spf.oldDspSt.all == 0x0230)
		{
			if((PX_In_Spf.NX_McuOpSt == 0x406)&&(PX_In_Spf.XX_McuFlag1.bit.CvOp == 1))
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
			if(PX_In_Spf.NX_McuOpSt == 0x40C)
				PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x6;
		}
	//------------------------------------------------------------
		//启动
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x40)
		{
			if(acmctrl.XU_3PhRms<10.0)
			{
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x41;
			}
			if(acmctrl.XU_3PhRms>50.0)
			{
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x42;
			}
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x41)
		{
			PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 1;
			if(PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x42;
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x42)
		{
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x43;
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x43)
		{
			acmctrl.A_CvOp = TRUE;
			if(acmctrl.A_CvOp == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x44;
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x44)
		{
			if(acmctrl.A_FNom == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x45;
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x45)
		{
			//
			//
			if(PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x48;
			else
			{
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x46;
			}
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x46)
		{
			acmctrl.C_AuSz = 1;
			//
			if(acmctrl.A_AuSz == 1)
			{
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x47;
			}
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x47)
		{
			PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 1;
			//
			if(PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 1)
			{
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x48;
			}
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x48)
		{
			acmctrl.B_EnU3PhCl = TRUE;
			//
			if(PX_In_Spf.NX_McuOpSt == 0x40A)
			{
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x50;
			}
		}

		//--------------------------------------------------------
		//停止
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x50)
		{
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x51;
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x51)
		{
			PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 1;
			//
			if(PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 1)
			{
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x52;
			}
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x52)
		{
			acmctrl.A_CvOp = FALSE;
			if(acmctrl.A_CvOp == 0)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x53;
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x53)
		{
			if(acmctrl.A_FNom == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x54;
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x54)
		{
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x55;
		}
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x55)
		{
			if(PX_In_Spf.NX_McuOpSt == 0x406)
			{
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x30;
				PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x2;
			}
		}
		//------------------------------------------------
		//错误
		else if(PX_Out_Spf.oldDspSt.bit.CvSt == 0x60)
		{
			PX_Out_Spf.SX_Run = 0;
		}

		//---------------------------------------
		//OvpCp
		if(PX_Out_Spf.oldDspSt.bit.OvpCp == 0x0)
		{
			if(PX_In_Spf.XX_McuFlag1.bit.OvpAv)
				PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x2;
		}
		else if(PX_Out_Spf.oldDspSt.bit.OvpCp == 0x2)
		{
			//
			PX_Out_Spf.XX_DspFlag1.bit.OvpFcTs = 1;
		}
		else if(PX_Out_Spf.oldDspSt.bit.OvpCp == 0x4)
		{

			//
			acmctrl.A_OvpCpOp = 1;
		}
		else if(PX_Out_Spf.oldDspSt.bit.OvpCp == 0x6)
		{

			//
			acmctrl.A_OvpCpOp = 0;
		}

		//-------------
		//BtCp
		if(PX_Out_Spf.oldDspSt.bit.BtCp == 0x0)
		{

		}
		else if(PX_Out_Spf.oldDspSt.bit.BtCp == 0x2)
		{
			acmctrl.A_BtCpOp = 1;
		}
		else if(PX_Out_Spf.oldDspSt.bit.BtCp == 0x4)
		{
			acmctrl.A_BtCpOp = 0;
		}

		PX_Out_Spf.oldDspSt.all = PX_Out_Spf.NX_DspOpSt.all;
		//------------------------------------------
}

//===============================================================================================
//=========================================THE END===============================================
//===============================================================================================
