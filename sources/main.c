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
struct MCUFLAG1_BITS {
	Uint16 RstSa :1;
	Uint16 OvpFcTsAv :1;
	Uint16 CdAuLdCt :1;
	Uint16 RstFlt :1;
	Uint16 BtCpAv :1;
	Uint16 CvOp :1;
	Uint16 OvpCpAv :1;
	Uint16 TA7 :1;
	Uint16 TA8 :1;
	Uint16 TA9 :1;
	Uint16 TA10 :1;
	Uint16 TA11 :1;
	Uint16 TA12 :1;
	Uint16 TA13 :1;
	Uint16 TA14 :1;
	Uint16 TA15 :1;
};

union MCUFLAG1_REG {
	Uint16 all;
	struct MCUFLAG1_BITS bit;
};

struct PX_In {
	float32 XU_DcLk;   		    		// DC-link voltage, V
	float32 XI_DcLk;   				// DC current, A
	float32 XI_PhA;						// phase A current, A
	float32 XI_PhB;						// phase B current, A
	float32 XI_PhC;			  	  		// phase C current, A
	float32 XU_PhABGt;					// AB相线电压, V
	Uint16 NX_McuPlCn;				// MCU pulse(heartbeat) counter
	Uint16 NX_McuOpSt;				// MCU operation state
	Uint16 NX_McuVer;			// MCU version
	union MCUFLAG1_REG XX_McuFlag1;
};
volatile struct PX_In PX_In_Spf = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0x400,
		0x10, 0x00, };
//========================================================================
//保护值
struct PX_InPr {
	float32 XU_DcLk_Max;   			// DC-link voltage, V
	float32 XU_DcLk_Min;   			// DC-link voltage, V
	Uint16 XU_DcLkOvCn;   			// DC-link over-voltage counter
	Uint16 XU_DcLkUnCn;   			// DC-link under-voltage counter
	float32 XI_DcLk_Max;   			// DC current, A
	Uint16 XI_DcLkOvCn;   			// DC-link over-current counter
	float32 XI_PhABC_Max;				// phase ABC maximum current, A
	Uint16 XI_PhAOvCn;				// phase A over current counter
	Uint16 XI_PhBOvCn;				// phase B over current counter
	Uint16 XI_PhCOvCn;				// phase C over current counter
	float32 XH_AmTp_Max;         		// ambient temperature, C
};
volatile struct PX_InPr PX_InPr_Spf = { 1800.0,         		//直流母线电压上限
		0.0,         		//直流母线电压下限
		0, 0, 10.0,         		//直流母线电流上限
		0, 300.0,         		//逆变器输出电流上限
		0, 0, 0, 0.0, };         		//环境温度上限
//-------------output-------------
//============================================================================================
struct WARN_BITS {
	Uint16 TA0 :1;		//直流母线过压、欠压保护
	Uint16 TA1 :1;		//直流母线过流保护
	Uint16 TA2 :1;		// Idc 采样保护
	Uint16 TA3 :1;		// Udc 采样保护
	Uint16 TA4 :1;		// DSP
	Uint16 TA5 :1;		//A相电流过流保护
	Uint16 TA6 :1;		//B相电流过流保护
	Uint16 TA7 :1;		//C相电流过流保护
	Uint16 TA8 :1;		// Iac
	Uint16 TA9 :1;		// Ia
	Uint16 TA10 :1;		// Ib
	Uint16 TA11 :1;		// Ic
	Uint16 TA12 :1;		// Ia
	Uint16 TA13 :1;		// Ib
	Uint16 TA14 :1;		// Ic
	Uint16 TA15 :1;		// Iac
};
union WARN_REG {
	Uint16 all;
	struct WARN_BITS bit;
};

struct DSPFLAG1_BITS {
	Uint16 CdAuLdCt :1;
	Uint16 CvOp :1;
	Uint16 OvpFcTs :1;
	Uint16 OvpFcTsAv :1;
	Uint16 IPhClTrsAv :1;
	Uint16 OvMdAv :1;
	Uint16 BtCpAv :1;
	Uint16 TA7 :1;
	Uint16 TA8 :1;
	Uint16 TA9 :1;
	Uint16 TA10 :1;
	Uint16 TA11 :1;
	Uint16 TA12 :1;
	Uint16 TA13 :1;
	Uint16 TA14 :1;
	Uint16 TA15 :1;
};

union DSPFLAG1_REG {
	Uint16 all;
	struct DSPFLAG1_BITS bit;
};

struct DSPST_BITS {
	Uint16 CvSt :8;
	Uint16 OvpCp :4;
	Uint16 BtCp :4;
};

union DSPST_REG {
	Uint16 all;
	struct DSPST_BITS bit;
};

//输出交互值
struct PX_Out {
	Uint16 XX_PwmMo;			// PWM mode  0x00  0x15
	Uint16 XT_PwmPdVv;   		// PWM period value,  for initialization
	Uint16 XX_Pwm1AVv;   		// PWM1A value
	Uint16 XX_Pwm2AVv;			// PWM2A value
	Uint16 XX_Pwm3AVv;			// PWM3A value
	Uint16 XX_Pwm4AVv;			// PWM4A value, chopper
	Uint16 XX_Pwm4BVv;			// PWM4B value, chopper
	float32 XP_Out;		    	// output power, kw
	float32 XX_PhUbl;			// phase unbalance
	float32 XI_PhA_Rms;		    // phase A current, RMS
	float32 XI_PhB_Rms;	    	// phase B current, RMS
	float32 XI_PhC_Rms;		    // phase C current, RMS
	float32 XU_PhAB_Rms;
	union WARN_REG XX_Flt1;			// 16位故障字
	Uint16 SX_Run;
	Uint16 NX_DspPlCn;			// DSP2 pulse(heartbeat) counter
	union DSPST_REG NX_DspOpSt;	// NX_Dsp2OpSt: DSP2 operation state 0x11:初始化中      0x22:初始化失败    0x33:初始化完成
	union DSPST_REG oldDspSt;
	Uint16 NX_DspVer;			// DSP2 version
	union DSPFLAG1_REG XX_DspFlag1;
};
volatile struct PX_Out PX_Out_Spf = { 21,
		6944,			//双采样：1450Hz:6465 1350Hz:6944
		3472, 3472, 3472, 0, 0, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0x0000, 0x0000,
		0x10, 0x0000, };
//========================================================
struct PI_Rms {
	float32 Square;
	float32 Rms;
};
volatile struct PI_Rms PI_PhARms = { 0, 0 };
volatile struct PI_Rms PI_PhBRms = { 0, 0 };
volatile struct PI_Rms PI_PhCRms = { 0, 0 };
volatile struct PI_Rms PU_PhABRms = { 0, 0 };
//======================================================================
/* GLOBALS */

/* LOCALS */
//int16	*XintfZone0=(int16 *)0x004000;//Unused
//int16	*XintfZone6=(int16 *)0x100000;//Unused
int16 *XintfZone7 = (int16 *) 0x200000;			//DP RAM
//=======================================================================
Uint16 GPIO_Temp181, GPIO_Temp182;
//TYPE_UFCTRL_IF acmctrl = UFCTRL_IF_DEFAULTS;
//TYPE_DOSGPLL dosgpll = DOSGPLL_DEFAULTS;

TYPE_SOGIOSGMA sogiosg = SOGIOSGMA_DEFAULTS;
//===========================================================================
Uint16 Cnt_Period = 0;
Uint16 Cnt_us = 0;
Uint16 Cnt_sec = 0;
Uint16 Cnt_min = 0;
Uint16 Sign = 0;
float32 IOvA = 0;
float32 IOvB = 0;
float32 IOvC = 0;
float32 Theta = 0.0;
//Uint16	sign = 0;

int16 DA[8] = { 0 };

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
void main(void) {

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

	while (1) {
		//--------------------------------------------------------------------------------
		GPIO_Temp181 = GpioDataRegs.GPADAT.bit.GPIO18;			//外部中断输入标志位
		DELAY_US(2L);
		//主要是为了判断是否长时间未进入中断复位，此处可采用无效延时，或者插入其他有效的执行任务
		GPIO_Temp182 = GpioDataRegs.GPADAT.bit.GPIO18;
		if ((GPIO_Temp181 == 0) && (GPIO_Temp182 == 0)) {
			PX_In_Spf.NX_McuPlCn = *(XintfZone7 + 0x7FFF);	//外部中断复位语句,SDRAM读操作
		}
	}
}
//==============================================================================
interrupt void DPRAM_isr(void) //after DSP1 has written to DPRAM, trigger the interrupt
{
	PX_Out_Spf.NX_DspPlCn++;
	if (PX_Out_Spf.NX_DspPlCn > 32767)
		PX_Out_Spf.NX_DspPlCn = 0;

	Cnt_Period++;
	if (Cnt_Period >= 2700) {
		Cnt_sec++;
		Cnt_Period = 0;
	}
	if (Cnt_sec >= 60) {
		Cnt_min++;
		Cnt_sec = 0;
	}
	if (Cnt_min >= 60) {
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
	sogiosg.Ts = 1.0 / 2700.0;
	sogiosg.w = 100 * 3.1415926;
	sogiosg.K = sqrt(2);
	SOGIOSGFLL(&sogiosg);

	acmctrl.XX_UPeakCom = 1.04;
	acmctrl.XX_AngleCom = PI / 2.0;

	acmctrl.XU_3PhAl = (sogiosg.alpha * cos(acmctrl.XX_AngleCom)
			- sogiosg.beta * sin(acmctrl.XX_AngleCom)) * acmctrl.XX_UPeakCom;
	acmctrl.XU_3PhBe = (sogiosg.alpha * sin(acmctrl.XX_AngleCom)
			+ sogiosg.beta * cos(acmctrl.XX_AngleCom)) * acmctrl.XX_UPeakCom;

	acmctrl.XU_3PhRms = sogiosg.peak / SQRT2;

	NX_Pr();

	DspStCl();

	/**/
	if (PX_Out_Spf.SX_Run == 1) {

		UFCOMAStep();
		DspStep();

//		acmctrl.XX_DutyA = 0.5;
//		acmctrl.XX_DutyB = 0.5;
//		acmctrl.XX_DutyC = 0.5;

		if (acmctrl.XX_Mode == 1) {
			PX_Out_Spf.XX_PwmMo = 21; // FPGA逻辑：计数器值大于比较器值为高，加死区，取反，经光纤板再反向
			PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv
					* (1.0 - acmctrl.XX_DutyA);
			PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv
					* (1.0 - acmctrl.XX_DutyB);
			PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv
					* (1.0 - acmctrl.XX_DutyC);
		}
		if (acmctrl.XX_Mode == 0) {
			PX_Out_Spf.XX_PwmMo = 0; // FPGA逻辑：计数器值小于比较器值为高，加死区，取反，经光纤板再反向
			PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv * acmctrl.XX_DutyA;
			PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv * acmctrl.XX_DutyB;
			PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv * acmctrl.XX_DutyC;
		}
	} else {
		PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv * 0.5;
		PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv * 0.5;
		PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv * 0.5;
	}

	DPRAM_WR(); //写dsp交互信息
	PieCtrlRegs.PIEACK.all |= PIEACK_GROUP1;

	EN_GPIO30();
}
//==============================================================================
void DPRAM_RD(void) //MCU-->DSP
{
	//----------------------------------------------------
	PX_In_Spf.NX_McuPlCn = *(XintfZone7 + 0x7FFF); // MCU pulse(heartbeat) counter    (RAM 0x7FFF clear) 此行最先读，产生DPRAM中断源
	//---------------------------------------------------------------------
	PX_In_Spf.NX_McuOpSt = *(XintfZone7 + 0x0001);		// MCU operation state
//	PX_In_Spf.NX_McuVer = 0x10;
	PX_In_Spf.XX_McuFlag1.all = *(XintfZone7 + 0x0014);

	PX_In_Spf.XU_DcLk = *(XintfZone7 + 0x6) * 0.1 * 2.0;// DC-link voltage, V
	PX_In_Spf.XI_DcLk = 0;		// DC-link current, V
	PX_In_Spf.XI_PhA = *(XintfZone7 + 0x8) * 0.1 / 2.0 * (-1.0);// phase A current, A
	PX_In_Spf.XI_PhB = *(XintfZone7 + 0xA) * 0.1 / 2.0 * (-1.0);// phase B current, A
	PX_In_Spf.XI_PhC = *(XintfZone7 + 0x9) * 0.1 / 2.0 * (-1.0);// phase C current, A
	PX_In_Spf.XU_PhABGt = *(XintfZone7 + 0x7) * 0.1 * 2.0;// AB相输出线电压, V 采样滤波对幅值的衰减 50Hz时衰减为0.5
}
//==============================================================================
void DPRAM_WR(void)			//DSP-->MCU
{
	*(XintfZone7 + 0x2) = PX_Out_Spf.NX_DspOpSt.all;// NX_Dsp2OpSt: DSP2 operation state
	*(XintfZone7 + 0x3) = PX_Out_Spf.NX_DspVer;		// DSP version
	*(XintfZone7 + 0x15) = PX_Out_Spf.XX_PwmMo;     // PWM  mode configuration
	*(XintfZone7 + 0x16) = PX_Out_Spf.XT_PwmPdVv;			// PWM period value
	*(XintfZone7 + 0x17) = PX_Out_Spf.XX_Pwm1AVv;			// PWM1A value
	*(XintfZone7 + 0x18) = PX_Out_Spf.XX_Pwm2AVv;			// PWM2A value
	*(XintfZone7 + 0x19) = PX_Out_Spf.XX_Pwm3AVv;			// PWM3A value
	*(XintfZone7 + 0x1A) = PX_Out_Spf.XX_Pwm4AVv;		// PWM4A value, chopper

	*(XintfZone7 + 0x24) = PX_Out_Spf.NX_DspOpSt.all;
	*(XintfZone7 + 0x25) = PX_Out_Spf.XX_DspFlag1.all;
	*(XintfZone7 + 0x26) = PX_Out_Spf.XX_Flt1.all;		// DSP故障状态

	/*上位机*/
	*(XintfZone7 + 0x27) = acmctrl.WU_3PhDsp;
	*(XintfZone7 + 0x28) = acmctrl.WF_3PhDsp;
	*(XintfZone7 + 0x29) = acmctrl.XU_3PhPek;
	*(XintfZone7 + 0x2A) = acmctrl.XX_M;

	/*DA输出*/
	DA[3] = acmctrl.XU_3PhAl * 10.0;
	DA[4] = acmctrl.XU_3PhBe * 10.0;
	DA[5] = 0.0;
	DA[6] = 0.0;
	DA[7] = 0.0;

	if (DA[3] >= 4095)
		DA[3] = 4095;
	if (DA[3] <= -4095)
		DA[3] = -4095;
	if (DA[4] >= 4095)
		DA[4] = 4095;
	if (DA[4] <= -4095)
		DA[4] = -4095;
	if (DA[5] >= 4095)
		DA[5] = 4095;
	if (DA[5] <= -4095)
		DA[5] = -4095;
	if (DA[6] >= 4095)
		DA[6] = 4095;
	if (DA[6] <= -4095)
		DA[6] = -4095;
	if (DA[7] >= 4095)
		DA[7] = 4095;
	if (DA[7] <= -4095)
		DA[7] = -4095;
	*(XintfZone7 + 0x2B) = DA[3];
	*(XintfZone7 + 0x2C) = DA[4];
	*(XintfZone7 + 0x2D) = DA[5];
	*(XintfZone7 + 0x2E) = DA[6];
	*(XintfZone7 + 0x2F) = DA[7];

//	int16 *ptr;
//	ptr = XintfZone7;
//
//	*(ptr+2) = 0x5432;
//	*(ptr+3) = 0x5432;
//	int i;
//
//	for(i=21;i<48;i++)
//	{
//		*(ptr+i) = 0x5432;
//	}

//	*(ptr+0x7FFE) = 0x5432;

//---------------------------------------------------
	*(XintfZone7 + 0x7FFE) = PX_Out_Spf.NX_DspPlCn;		//此行最后写，DPRAM产生中断源
//------------------------------------------------------------

}
//==============================================================================
/* 保护 */
void NX_Pr(void) {
//-------------------Udc over-voltage--------------------
	if (PX_In_Spf.XU_DcLk > PX_InPr_Spf.XU_DcLk_Max) {
		PX_InPr_Spf.XU_DcLkOvCn++;
		if (PX_InPr_Spf.XU_DcLkOvCn > 3) {
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA0 = 1;
			PX_InPr_Spf.XU_DcLkOvCn = 4;
		}
	} else
		PX_InPr_Spf.XU_DcLkOvCn = 0;

//------------------Udc under-voltage---------------------
	if ((PX_In_Spf.XU_DcLk < PX_InPr_Spf.XU_DcLk_Min)
			&& PX_Out_Spf.SX_Run == 1) {
		PX_InPr_Spf.XU_DcLkUnCn++;
		if (PX_InPr_Spf.XU_DcLkUnCn > 3) {
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA0 = 1;
			PX_InPr_Spf.XU_DcLkUnCn = 4;
		}
	} else
		PX_InPr_Spf.XU_DcLkUnCn = 0;

//-----------------------DC-link over-current--------------------------------
	if (PX_In_Spf.XI_DcLk > PX_InPr_Spf.XI_DcLk_Max) {
		PX_InPr_Spf.XI_DcLkOvCn++;
		if (PX_InPr_Spf.XI_DcLkOvCn > 3) {
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA1 = 1;
			PX_InPr_Spf.XI_DcLkOvCn = 4;
		}
	} else
		PX_InPr_Spf.XI_DcLkOvCn = 0;

//-----------------------phase A over-current------------------------
	if ((PX_In_Spf.XI_PhA > PX_InPr_Spf.XI_PhABC_Max)
			|| (PX_In_Spf.XI_PhA < -PX_InPr_Spf.XI_PhABC_Max)) {
		PX_InPr_Spf.XI_PhAOvCn++;
		if (PX_InPr_Spf.XI_PhAOvCn > 3) {
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA5 = 1;
			PX_InPr_Spf.XI_PhAOvCn = 4;
			IOvA = PX_In_Spf.XI_PhA;
		}
	} else
		PX_InPr_Spf.XI_PhAOvCn = 0;

//-----------------------phase B over-current------------------------
	if ((PX_In_Spf.XI_PhB > PX_InPr_Spf.XI_PhABC_Max)
			|| (PX_In_Spf.XI_PhB < -PX_InPr_Spf.XI_PhABC_Max)) {
		PX_InPr_Spf.XI_PhBOvCn++;
		if (PX_InPr_Spf.XI_PhBOvCn > 3) {
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA6 = 1;
			PX_InPr_Spf.XI_PhBOvCn = 4;
			IOvB = PX_In_Spf.XI_PhB;
		}
	} else
		PX_InPr_Spf.XI_PhBOvCn = 0;

//-----------------------phase C over-current------------------------
	if ((PX_In_Spf.XI_PhC > PX_InPr_Spf.XI_PhABC_Max)
			|| (PX_In_Spf.XI_PhC < -PX_InPr_Spf.XI_PhABC_Max)) {
		PX_InPr_Spf.XI_PhCOvCn++;

		if (PX_InPr_Spf.XI_PhCOvCn > 3) {
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_Flt1.bit.TA7 = 1;
			PX_InPr_Spf.XI_PhCOvCn = 4;
			IOvC = PX_In_Spf.XI_PhC;
		}
	} else
		PX_InPr_Spf.XI_PhCOvCn = 0;

}
//==============================================================================
void EN_GPIO30(void) {
	EALLOW;
	GpioDataRegs.GPASET.bit.GPIO30 = 1;
	EDIS;
}
//==============================================================================
void DIS_GPIO30(void) {
	EALLOW;
	GpioDataRegs.GPACLEAR.bit.GPIO30 = 1;
	EDIS;
}

//==============================================================================
void PI_RmsClc(void) {
	if (Cnt_Period < 256) {
		PI_PhARms.Square += (PX_In_Spf.XI_PhA * PX_In_Spf.XI_PhA);
		PI_PhBRms.Square += (PX_In_Spf.XI_PhB * PX_In_Spf.XI_PhB);
		PI_PhCRms.Square += (PX_In_Spf.XI_PhC * PX_In_Spf.XI_PhC);
		PU_PhABRms.Square += (PX_In_Spf.XU_PhABGt * PX_In_Spf.XU_PhABGt);
		Cnt_Period++;
	}
	if (Cnt_Period >= 256) {
		PI_PhARms.Rms = __ffsqrtf(PI_PhARms.Square * 0.00390625);// 0.00390625 = 1/256  square root function
		PI_PhBRms.Rms = __ffsqrtf(PI_PhBRms.Square * 0.00390625);// 0.00390625 = 1/256
		PI_PhCRms.Rms = __ffsqrtf(PI_PhARms.Square * 0.00390625);// 0.00390625 = 1/256
		PU_PhABRms.Rms = __ffsqrtf(PU_PhABRms.Square * 0.00390625);	// 0.00390625 = 1/256
		PI_PhARms.Square = 0;
		PI_PhBRms.Square = 0;
		PI_PhCRms.Square = 0;
		PU_PhABRms.Square = 0;
		Cnt_Period = 0;
	}
}

//=================
void OvpCp(void) {

}
//=================
void BtCp(void) {

}
//==================
void DspStCl(void) {

//	DSP运行状态（地址0x0002）
//		0x0000	初始化命令
//
//		0x0010	初始化1	DSP初始化检测
//
//		0x0020	初始化2	参数初始化
//
//		0x0030	初始化完成
//
//	第4-7位逆变主状态第0-3位逆变子状态
//		0x40	启动命令
//		0x41	闭输出接触器（无交流网压）
//		0x42	Gdu测试
//		0x43	启动逆变器命令
//		0x44	斜坡启动
//		0x45	控制使能
//		0x46	同步
//		0x47	闭输出接触器（完成同步）
//		0x48	启动完成（运行）
//
//		0x50	停止命令
//		0x51	断输出接触器
//		0x52	停止逆变器命令
//		0x53	斜坡停止
//		0x54	控制禁能
//		0x55	停止完成
//
//		0x60	错误
//
//	第8-11位OVP斩波状态  (DSP初始化完成后斩波使能)
//		0x0	OVP斩波初始
//		0x1	OVP斩波测试
//		0x2	OVP斩波测试完成
//		0x3	OVP斩波启动	不用
//		0x4	OVP斩波启动完成（正常运行）
//		0x5	OVP斩波停止	不用
//		0x6	OVP斩波停止完成
//
//	第12-15位蓄电池斩波状态  (DSP初始化完成后斩波使能)
//		0x0	蓄电池斩波初始
//		0x1	蓄电池斩波启动	不用
//		0x2	蓄电池斩波启动完成（运行）
//		0x3	蓄电池斩波停止	不用
//		0x4	蓄电池斩波停止完成
//
//
//	DSP-->MCU标志位1（0x0025）
//	DSP标志位1
//	（0x0025）
//	低8位	0	闭/断三相输出接触器	1：请求闭三相输出接触器
//	0：请求断三相输出接触器
//		1	逆变运行	1：逆变运行
//	0：逆变关闭
//		2	OVP测试	1：OVP测试通过
//	0：OVP测试失败
//		3	OVP激活	1：OVP激活状态
//	0：OVP未激活
//		4	三相电流过流瞬态控制激活	1：激活
//	0：未激活
//		5	过调制控制激活	1：激活
//	0：未激活
//		6	电池充电斩波激活	1：激活
//	0：未激活
//		7
//	DSP标志位1
//	（0x0025）
//	高8位	8
//		9
//		10
//		11
//		12
//		13
//		14
//		15
//
//	DSP故障
//	（0x0026）
//	低8位	0	Udc过压
//		1	Udc欠压
//		2
//		3
//		4
//		5	5247，Ia过流
//		6	5248，Ib过流
//		7	5249，Ic过流
//	DSP故障
//	（0x0026）
//	高8位	8
//		9
//		10
//		11
//		12
//		13
//		14
//		15
//
//	MCU运行状态（地址0x0001）
//	MCU运行状态	功能	总使能
//	（逆变+OVP斩波+蓄电池斩波）	逆变使能	斩波使能	蓄电池斩波	DSP状态（待讨论）
//	12-15位：蓄电池斩波
//	8-11位：OVP斩波状态
//	0-7位：逆变状态
//	0x401：硬件初始化；	MCU板卡启动过程	×	×	×	×	0x0000（0~7bit）
//	0x402：硬件初始化完成；	MCU板卡启动过程	×	×	×	×	0x0010（0~7bit）
//	0x403：Converter初始化；	MCU板卡启动过程，等待DSP反馈0x0010（初始化完成状态）
//	根据保护条件，进入关断类保护状态；	×	×	×	×	0x0020（0~7bit）0x0030（0~7bit）
//	0x404：Converter初始化完成（待机状态）；	MCU板卡启动完成，准备接收MVB下发的预充指令。
//	进入预充（0x405）的条件：
//	DSP状态为0x0030（初始化完成状态）+MVB预充指令
//	根据保护条件，进入关断类保护状态；	×	×	×	√？	0x0030（0~7bit）
//	0x405：预充；	通过检测直流侧电压电流，完成RC的充电逻辑。
//	DSP状态为0x0030（初始化完成状态）+预充完成后进入0x406
//	DSP状态为非法时，请求保护性关断
//	RC预充电压正常达到阈值后，MCU发送OVP测试请求（MCU标志位1.bit1=1），DSP反馈0x0130、0x0230；
//	待反馈结果是0x2030时，判断OVP结果（DSP标志位1.bit2=1），如果成功，跳入0x406；
//	否则进入保护性关断（0x41C）
//	根据保护条件，进入5类保护状态；
//
//		√	×	√	√？	0x0030（0~7bit）
//	OVP测试部分：
//	0x0130
//	0x0230
//	0x406：预充完成；	MVB放电命令，进入系统放电（0x40C）;
//	否则，进入0x408
//	根据保护条件，进入5类保护状态；	√	×	√	√？	0x0230
//	0x408：启动运行；	发送：MCU标志位1.bit5=1，DSP反馈0x0040，之后等待DSP反馈的0x0041或0x0047时，DSP标志位1.bit0=1，执行闭合输出接触器，将输出接触器状态发送给DSP（MCU标志位1.bit2=1）
//	当DSP反馈状态为0x0048时均进入0x409；
//	根据保护条件，进入5类保护状态；	√	√	√	√？	0x0040（0~7bit）
//	0x0041（0~7bit）
//	0x0047（0~7bit）
//	0x0048（0~7bit）
//	0x409：系统运行；	无方向指令/放电命令等多种条件都可以进入停止运行（0x40A）；
//	根据保护条件，进入5类保护状态；	√	√	√	√？	0x0048（0~7bit）
//	0x40A：停止运行；	MCU发送停止逆变命令到DSP(MCU标志位1=0)；DSP反馈0x0050；等待DSP反馈0x0051同时DSP标志位1.bit0=0；MCU反馈输出接触器的状态（MCU标志位1.bit2=0）；
//	等待DSP反馈0x0055，系统状态切换到0x406	√	√	√	√？	0x0050（0~7bit）
//	0x0051（0~7bit）
//	0x0055（0~7bit）
//	0x40B：停止运行完成；		-	-	-	√？
//	0x40C：系统放电；	DSP反馈的状态0x0600（斩波完成），即认为系统放电完成；MCU进入初始化（0x404）
//	根据保护条件，进入关断类保护状态；	√	×	√	√？	0x0630（8~11bit）
//	0x414：软封锁；	/	√	√	√	√？	/
//	0x415：软封锁完成；	/	√	√	√	√	/
//	0x417：保护性封锁；	禁止逆变使能，断开输出接触器，发送输出接触器状态（MCU标志位1.bit2=0），等待DSP反馈一个状态为0x0055，系统状态切换到0x418；
//	根据保护条件，进入5类保护状态；	√	×	√	√？	0x0055（0~7bit）
//	0x418：保护性封锁完成；	等待故障恢复或者重启
//	根据保护条件，进入5类保护状态；	√	×	√	√？	0x0230
//	0x41A：软关断；	禁止逆变使能，断开SC/CC，断开输出接触器，发送输出接触器状态（MCU标志位1.bit2=0），DSP在接收到输出接触器断开状态后，开启斩波；MCU等待DSP反馈一个状态为0x0655，系统状态切换到0x41B；
//	根据保护条件，进入5类保护状态；	√	×	√	√？	0x0655
//	0x41B：软关断完成；	等待故障恢复或者重启
//	根据保护条件，进入5类保护状态；	×	×	×	√？	0x0030
//	0x41C：保护性关断；	断开跳闸继电器，禁止逆变使能，断开SC/CC，断开输出接触器，发送输出接触器状态（MCU标志位1.bit2=0），DSP在接收到输出接触器断开状态后，开启斩波；MCU等待DSP反馈一个状态为0x0655，系统状态切换到0x41D；
//	根据保护条件，进入5类保护状态；	√	×	√	√？	0x0655
//	0x41D：保护性关断完成；	等待故障恢复或者重启
//	根据保护条件，进入5类保护状态；	×	×	×	√？	0x0030
//	0x41E：隔离；	断开SC/CC、输出接触器，断开跳闸继电器，等待DSP反馈0x0655（斩波完成），等待DSP反馈一个状态为0x0030（初始化完成状态）时，进入隔离完成	√	×	√	√？	0x0655
//	0x41F：隔离完成；	等待重启	×	×	×	√?	0x0030
//	0x426：快速关断；	禁止逆变使能，断开SC/CC，断开输出接触器，发送输出接触器状态（MCU标志位1.bit2=0），DSP在接收到输出接触器断开状态后，开启斩波；MCU等待DSP反馈一个状态为0x0655，系统状态切换到0x427；
//	根据保护条件，进入5类保护状态；	√	×	√	√?	0x0655
//	0x427：快速关断完成；	等待故障恢复或者重启
//	根据保护条件，进入5类保护状态；	×	×	×	√?	0x0030
//	注：√？：蓄电池斩波使能的判断逻辑：网侧电压>100VAC，开启蓄电池斩波使能
//	MCUDSP的标志位1（地址？）
//	MCU标志位1
//	（？）
//	低8位	0	DSP软件重启	1：请求DSP软件重启
//	0：禁止DSP软件重启
//		1	OVP斩波测试激活请求位	1：请求激活OVP
//	0：禁止激活OVP
//		2	三相电压输出接触器状态	1：闭合
//	0：断开
//		3	DSP故障复位	1：DSP故障复位命令
//	0：DSP故障不复位
//		4	蓄电池斩波激活请求	1: 请求激活BtCp
//	0: 禁止激活BtCp
//		5	逆变功能	1：请求启动逆变
//	0：请求停止逆变
//		6	预留
//		7	预留
//	MCU标志位1
//	（？）
//	高8位
//		8	预留
//		9	预留
//		10	预留
//		11	预留
//		12	预留
//		13	预留
//		14	预留
//		15	预留

	if (PX_In_Spf.XX_McuFlag1.bit.RstSa == 1) {
		PX_Out_Spf.XX_DspFlag1.all = 0x0000;
		PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0000;
	}

	if (PX_In_Spf.XX_McuFlag1.bit.RstFlt == 1) {
		PX_Out_Spf.XX_Flt1.all = 0x0000;
	}

	//PrBc
	if (PX_In_Spf.NX_McuOpSt == 0x417) {
		if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0) {
			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0030;
		}
		if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
		}
	}

	//PrSd
	if (PX_In_Spf.NX_McuOpSt == 0x41C) {
		if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0) {
			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0030;
		}
		if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
		}
	}

	//SfSd
	if (PX_In_Spf.NX_McuOpSt == 0x41A) {
		if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0) {
			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0030;
		}
		if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
		}
	}

	//FsSd
	if (PX_In_Spf.NX_McuOpSt == 0x426) {
		if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0) {
			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0030;
		}
		if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
		}
	}

	//Inso
	if (PX_In_Spf.NX_McuOpSt == 0x41E) {
		if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0) {
			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0030;
		}
		if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
		}
	}

	//-------------------------------------------
	//初始化
	if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x00) {
		//
		//
		if (PX_In_Spf.NX_McuOpSt == 0x401) {
		} else if (PX_In_Spf.NX_McuOpSt == 0x402)
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x10;
		else {
			//PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x60;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x10) {
		//---
		//---
		if (PX_In_Spf.NX_McuOpSt == 0x402) {
		} else if (PX_In_Spf.NX_McuOpSt == 0x403)
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x20;
		else {
			//PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x60;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x20) {
		//参数初始化
		UFCOMAInit();

		if (PX_In_Spf.NX_McuOpSt == 0x403) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x30;
		} else {
			//PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x60;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x30) {
		if ((PX_In_Spf.NX_McuOpSt == 0x403) || (PX_In_Spf.NX_McuOpSt == 0x404)
				|| (PX_In_Spf.NX_McuOpSt == 0x405)
				|| (PX_In_Spf.NX_McuOpSt == 0x406)) {
		} else if ((PX_In_Spf.NX_McuOpSt == 0x408)) {
			if (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		} else {
			//PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x60;
		}
	}

	//------------------------------------------------------------
	//启动
	else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x40) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (acmctrl.XU_3PhRms < 50.0) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x41;
				PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 1;
			}
			if (acmctrl.XU_3PhRms > 370.0) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x42;
			}
		} else {
			//PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x60;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x41) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x42;
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x42) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x43;
			acmctrl.A_CvOp = TRUE;
			PX_Out_Spf.SX_Run = 1;
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x43) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (acmctrl.A_CvOp == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x44;
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x44) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (acmctrl.A_FNom == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x45;
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x45) {
		//
		//
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 1) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x48;
				acmctrl.B_EnU3PhCl = TRUE;
			} else {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x46;
				acmctrl.C_AuSz = 1;
			}
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x46) {

		//
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {

			if (acmctrl.A_AuSz == 1) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x47;
				PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 1;
			}
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x47) {
		//
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 1) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x48;
				acmctrl.B_EnU3PhCl = TRUE;
			}
		} else
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;

	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x48) {

		//
		if (PX_In_Spf.NX_McuOpSt == 0x40A) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x50;
		} else {
		}
	}
	//--------------------------------------------------------
	//停止
	else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x50) {
		if ((PX_In_Spf.NX_McuOpSt == 0x40A)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 0)) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x51;
			PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 0;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x51) {
		//
		if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x52;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x52) {
		acmctrl.A_CvOp = FALSE;
		if (acmctrl.A_CvOp == 0)
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x53;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x53) {
		if (acmctrl.A_FNom == 1)
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x54;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x54) {
		PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x55;
		PX_Out_Spf.SX_Run = 0;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x55) {
		if (PX_In_Spf.NX_McuOpSt == 0x406) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x30;
		}
	}
	//------------------------------------------------
	//错误
	else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x60) {
		PX_Out_Spf.SX_Run = 0;
	}
	//---------------------------------------
	//OvpCp
	/**/
	if (PX_Out_Spf.oldDspSt.bit.OvpCp == 0x0) {
		if ((PX_In_Spf.NX_McuOpSt == 0x405)
				&& (PX_In_Spf.XX_McuFlag1.bit.OvpFcTsAv == 1)
				&& (PX_Out_Spf.oldDspSt.bit.CvSt == 0x30))
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x1;
	} else if (PX_Out_Spf.oldDspSt.bit.OvpCp == 0x1) {
		//
		PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x2;
	} else if (PX_Out_Spf.oldDspSt.bit.OvpCp == 0x2) {
		//
		PX_Out_Spf.XX_DspFlag1.bit.OvpFcTs = 1;
		if (PX_In_Spf.NX_McuOpSt == 0x404) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x0;
			PX_Out_Spf.XX_DspFlag1.bit.OvpFcTs = 0;
		}
		if (PX_In_Spf.NX_McuOpSt == 0x40C) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
			acmctrl.A_OvpCpOp = 1;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.OvpCp == 0x4) {
		//
		PX_Out_Spf.XX_DspFlag1.bit.OvpFcTsAv = 1;
		if ((PX_In_Spf.NX_McuOpSt == 0x40C) || (PX_In_Spf.NX_McuOpSt == 0x417)
				|| (PX_In_Spf.NX_McuOpSt == 0x41C)
				|| (PX_In_Spf.NX_McuOpSt == 0x41A)
				|| (PX_In_Spf.NX_McuOpSt == 0x426)
				|| (PX_In_Spf.NX_McuOpSt == 0x41E)) {
			if (PX_In_Spf.XU_DcLk < 36.0) {
				PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x6;
				acmctrl.A_OvpCpOp = 0;
			}
		}
	} else if (PX_Out_Spf.oldDspSt.bit.OvpCp == 0x6) {
		//
		PX_Out_Spf.XX_DspFlag1.bit.OvpFcTsAv = 0;
		if ((PX_In_Spf.NX_McuOpSt == 0x404)|| (PX_In_Spf.NX_McuOpSt == 0x418)
				|| (PX_In_Spf.NX_McuOpSt == 0x41D)
				|| (PX_In_Spf.NX_McuOpSt == 0x41B)
				|| (PX_In_Spf.NX_McuOpSt == 0x427)
				|| (PX_In_Spf.NX_McuOpSt == 0x41F)) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x0;
		}
	}
	//---------------------------------------------

	//-------------
	//BtCp
	if (PX_Out_Spf.oldDspSt.bit.BtCp == 0x0) {
		PX_Out_Spf.NX_DspOpSt.bit.BtCp = 0x4;
	} else if (PX_Out_Spf.oldDspSt.bit.BtCp == 0x2) {
		PX_Out_Spf.XX_DspFlag1.bit.BtCpAv = 0x1;
		if (PX_In_Spf.XX_McuFlag1.bit.BtCpAv == 0) {
			PX_Out_Spf.NX_DspOpSt.bit.BtCp = 0x4;
			acmctrl.A_BtCpOp = 0;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.BtCp == 0x4) {
		PX_Out_Spf.XX_DspFlag1.bit.BtCpAv = 0x0;
		if (PX_In_Spf.XX_McuFlag1.bit.BtCpAv == 1) {
			PX_Out_Spf.NX_DspOpSt.bit.BtCp = 0x2;
			acmctrl.A_BtCpOp = 1;
		}
	}

	PX_Out_Spf.oldDspSt.all = PX_Out_Spf.NX_DspOpSt.all;
	//------------------------------------------
}


//===============================================================================================
//=========================================THE END===============================================
//===============================================================================================
