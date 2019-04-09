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
};
volatile struct PX_In PX_In_Spf = {
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
		0,
		0x11,
		0x10,};
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
		600.0,//直流母线电压上限
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
//输出交互值
struct PX_Out
{
	Uint16  		XX_PwmMo;			// PWM mode
	Uint16  		XT_PwmPdVv;   		// PWM period value,  for initialization
	Uint16  		XX_Pwm1AVv;   		// PWM1A value
	Uint16  		XX_Pwm2AVv;			// PWM2A value
	Uint16  		XX_Pwm3AVv;			// PWM3A value
	Uint16  		XX_Pwm4AVv;			// PWM4A value, chopper
	float32 		XP_Out;		    	// output power, kw
	float32 		XX_PhUbl;			// phase unbalance
	float32 		XI_PhA_Rms;		    // phase A current, RMS
	float32 		XI_PhB_Rms;	    	// phase B current, RMS
	float32 		XI_PhC_Rms;		    // phase C current, RMS
	union WARN_REG	XX_Flt1;			// 16位故障字
	Uint16			SX_Run;
	Uint16 			NX_DspPlCn;			// DSP2 pulse(heartbeat) counter
	Uint16 			NX_DspOpSt;			// NX_Dsp2OpSt: DSP2 operation state 0x11:初始化中      0x22:初始化失败    0x33:初始化完成
	Uint16 			NX_DspVer;			// DSP2 version
};
volatile struct PX_Out PX_Out_Spf = {
		21,
		6465,
		3232,
		3232,
		3232,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0x11,
		0x10,};
//========================================================
struct PI_Rms
{
	float32 Square;
	float32 Rms;
};
volatile struct PI_Rms PI_PhARms = {0, 0};
volatile struct PI_Rms PI_PhBRms = {0, 0};
volatile struct PI_Rms PI_PhCRms = {0, 0};
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
	//--------------------------------------------------------------------------------
		/*MCU状态
		 * 0x404:系统初始化完成状态
		 *		 *
		 *  0x409:系统运行状态
		 *  */
        if((PX_In_Spf.NX_McuOpSt == 0x409) && (PX_Out_Spf.NX_DspOpSt == 0x33) && (PX_Out_Spf.XX_Flt1.all == 0))
        	PX_Out_Spf.SX_Run = 1;
        else
        	PX_Out_Spf.SX_Run = 0;
	}
}
//==============================================================================
interrupt void DPRAM_isr(void)   					//after DSP1 has written to DPRAM, trigger the interrupt
{  
	PX_Out_Spf.NX_DspPlCn++;
	if(PX_Out_Spf.NX_DspPlCn > 32767)
		PX_Out_Spf.NX_DspPlCn = 0;

	DIS_GPIO30();
	DPRAM_RD(); //读MCU交互信息

	acmctrl.XI_PhA = PX_In_Spf.XI_PhA;
	acmctrl.XI_PhB = PX_In_Spf.XI_PhB;
	acmctrl.XI_PhC = PX_In_Spf.XI_PhC;
	acmctrl.XU_DcLk = PX_In_Spf.XU_DcLk;
	acmctrl.XI_DcLk = PX_In_Spf.XI_DcLk;
	acmctrl.XU_PhABLk = PX_In_Spf.XU_PhABGt;

//	PI_RmsClc();
//	PX_Out_Spf.XI_PhA_Rms = PI_PhARms.Rms;
//	PX_Out_Spf.XI_PhB_Rms = PI_PhBRms.Rms;
//	PX_Out_Spf.XI_PhC_Rms = PI_PhCRms.Rms;

	sogiosg.phase = PX_In_Spf.XU_PhABGt;
	SOGIOSGFLL(&sogiosg);

	acmctrl.XX_UPeakCom = 1.0;
	acmctrl.XX_AngleCom = PI/2.0;

	acmctrl.XU_3PhAl = (sogiosg.alpha*cos(acmctrl.XX_AngleCom) - sogiosg.beta*sin(acmctrl.XX_AngleCom))*acmctrl.XX_UPeakCom;
	acmctrl.XU_3PhBe = (sogiosg.alpha*sin(acmctrl.XX_AngleCom) + sogiosg.beta*cos(acmctrl.XX_AngleCom))*acmctrl.XX_UPeakCom;

	acmctrl.XU_3PhPek = sogiosg.peak;

	NX_Pr();

	/**/
	if(PX_Out_Spf.SX_Run == 1)
	{
		Cnt_Period ++;
		if(Cnt_Period>=2900)
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


		acmctrl.B_EnU3PhCl = FALSE;
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
	if(PX_Out_Spf.NX_DspOpSt == 0x11)						// DSP initializing
	{
		UFCOMAInit(&acmctrl);
		PX_Out_Spf.NX_DspOpSt = 0x33;
	}
	else
	{
		if(PX_Out_Spf.NX_DspOpSt == 0x33)				//DSP initialized
		{
			PX_In_Spf.XU_DcLk = *(XintfZone7 + 0x6) * 0.1 * 2.0;		// DC-link voltage, V
			PX_In_Spf.XI_DcLk = 0;// DC-link current, V
			PX_In_Spf.XI_PhA = *(XintfZone7 + 0x8)*0.1/2.0*(-1.0);				// phase A current, A
			PX_In_Spf.XI_PhB = *(XintfZone7 + 0xA)*0.1/2.0*(-1.0);				// phase B current, A
			PX_In_Spf.XI_PhC = *(XintfZone7 + 0x9)*0.1/2.0*(-1.0);				// phase C current, A
//			PX_In_Spf.XU_PhABGt= *(XintfZone7 + 0x7) * 0.1;			// AB相输出线电压, V
			PX_In_Spf.XU_PhABGt= *(XintfZone7 + 0x7) * 0.1*2.0;			// AB相输出线电压, V 采样滤波对幅值的衰减 50Hz时衰减为0.5
		}
	}
}
//==============================================================================
void DPRAM_WR(void)//DSP-->MCU
{
	*(XintfZone7 + 0x2) =  PX_Out_Spf.NX_DspOpSt;		// NX_Dsp2OpSt: DSP2 operation state
	*(XintfZone7 + 0x3) =  PX_Out_Spf.NX_DspVer;		// DSP2 version
	*(XintfZone7 + 0x15) = PX_Out_Spf.XX_PwmMo;     		// PWM  mode configuration
	*(XintfZone7 + 0x16) = PX_Out_Spf.XT_PwmPdVv;			// PWM period value
	*(XintfZone7 + 0x17) = PX_Out_Spf.XX_Pwm1AVv;			// PWM1A value
	*(XintfZone7 + 0x18) = PX_Out_Spf.XX_Pwm2AVv;			// PWM2A value
	*(XintfZone7 + 0x19) = PX_Out_Spf.XX_Pwm3AVv;			// PWM3A value
	*(XintfZone7 + 0x1A) = PX_Out_Spf.XX_Pwm4AVv;			// PWM4A value, chopper
//	*(XintfZone7 + 0x1C) = PX_Out_Spf.XP_Out * 10;		    	// output power, 0.1kw (left value)
//	*(XintfZone7 + 0x1E) = PX_Out_Spf.XX_PhUbl * 100;			// phase unbalance, 1% (left value)
//	*(XintfZone7 + 0x21) = PX_Out_Spf.XI_PhA_Rms * 10;		    // phase A current, RMS, 0.1A (left value)
//	*(XintfZone7 + 0x22) = PX_Out_Spf.XI_PhB_Rms * 10;	    	// phase B current, RMS, 0.1A (left value)
//	*(XintfZone7 + 0x23) = PX_Out_Spf.XI_PhC_Rms * 10;		    // phase C current, RMS, 0.1A (left value)

	*(XintfZone7 + 0x26) = PX_Out_Spf.XX_Flt1.all;		// ACM故障状态
	/*上位机*/
	/**/
//	*(XintfZone7 + 0x24) = sogiosgma.w/PI2*10.0;
//	*(XintfZone7 + 0x25) = fabs(sogiosgma.ErrF)*1000.0;
//	*(XintfZone7 + 0x27) = fabs(srfpll.aqr.Ref)*1000.0;
//	*(XintfZone7 + 0x28) = fabs(srfpll.aqr.Out)/PI2*10.0;
//	*(XintfZone7 + 0x29) = srfpll.Upeak*10.0;
//	*(XintfZone7 + 0x2A) = srfpll.w/PI2*10.0;
	/**/
	*(XintfZone7 + 0x24) = acmctrl.WF_3PhDsp*10.0;
	*(XintfZone7 + 0x25) = acmctrl.WU_3PhDsp*10.0;
	*(XintfZone7 + 0x27) = acmctrl.XU_3PhRe*10.0;
	*(XintfZone7 + 0x28) = acmctrl.XU_3PhIm*10.0;
	*(XintfZone7 + 0x29) = acmctrl.XU_3PhPek*10.0;
	*(XintfZone7 + 0x2A) = acmctrl.XX_M*100.0;
	/**/
//	*(XintfZone7 + 0x24) = acmctrl.XU_3PhPek*10.0;
//	*(XintfZone7 + 0x25) = acmctrl.XF_3Ph*10.0;
//	*(XintfZone7 + 0x27) = dosgpll.Upeak*10.0;
//	*(XintfZone7 + 0x28) = dosgpll.w/PI2*10.0;
//	*(XintfZone7 + 0x29) = (acmctrl.XX_Theta-(dosgpll.theta+acmctrl.XX_AngleCom))*100;
//	*(XintfZone7 + 0x2A) = acmctrl.XX_M*100.0;
	/*DA输出*/
	/**/
//	DA[3] = PX_In_Spf.XU_PhABGt*10.0;//
//	DA[4] = (acmctrl.XX_Theta - (dosgpll.theta + acmctrl.XX_AngleCom))*100.0;//
//	DA[5] = acmctrl.XX_Theta *100.0;//
//	DA[6] = dosgpll.Upeak*10.0;
////	DA[7] = dosgpll.theta*100.0;
//	Theta = dosgpll.theta + PI/2.0;
//	if(Theta >= PI2)
//		Theta -= PI2;
//	if(Theta < 0)
//		Theta += PI2;
//	DA[7] = Theta*100.0;
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
//	Theta += 100.0*PI*8.0/150.0/1000000.0*PX_Out_Spf.XT_PwmPdVv;
//	if(Theta>=PI2)
//		Theta -=PI2;
//	if(Theta<0)
//		Theta +=PI2;
//
//	*(XintfZone7 + 0x28) = 0.0;
//	*(XintfZone7 + 0x29) = 0.0;
//	*(XintfZone7 + 0x2A) = 0.0;
//	*(XintfZone7 + 0x2B) = Theta*500;
//	*(XintfZone7 + 0x2C) = 1000.0*sin(Theta);
//	*(XintfZone7 + 0x2D) = 2000.0*sin(Theta);
//	*(XintfZone7 + 0x2E) = 3000.0*sin(Theta);
//	*(XintfZone7 + 0x2F) = 4000.0*sin(Theta);

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
		Cnt_Period++;
	}
	if(Cnt_Period>=256)
	{
		PI_PhARms.Rms = __ffsqrtf(PI_PhARms.Square * 0.00390625);		// 0.00390625 = 1/256  square root function
		PI_PhBRms.Rms = __ffsqrtf(PI_PhBRms.Square * 0.00390625);		// 0.00390625 = 1/256
		PI_PhCRms.Rms = __ffsqrtf(PI_PhARms.Square * 0.00390625);		// 0.00390625 = 1/256
		PI_PhARms.Square = 0;
		PI_PhBRms.Square = 0;
		PI_PhCRms.Square = 0;
		Cnt_Period=0;
	}
}

//===============================================================================================
//=========================================THE END===============================================
//===============================================================================================

///*
// * HSTIMA - Host interface signals from DSP to MCU
// * */
//struct
//{
//	float32 XU_DcLk;//DC-link voltage
//	float32 XU_3PhPek;//3-Phase output load voltage,phase-phase,peak value
//	float32 XI_PhPek;//Phase current,peak value
//	float32 XI_PhAct;//Active phase current
//	float32 XI_PhRct;//Reactive phase current
//	float32 XI_BtCg;//Battery charger current
//	float32 XI_Bt;//Battery current
//	float32 XU_PhInRms;//
//	float32 XI_PhInRms;
//	float32 WU_IPhClTrs;
//	float32 WU_IBtCgCl;
//	float32 WU_OvMd;
//	float32 WU_IPhClRms;
//	float32 XU_Bt;
//	float32 XI_Ph1Rms;
//	float32 XI_Ph2Rms;
//	float32 XI_Ph3Rms;
//	float32 XU_3PhRms;
//	float32 XU_3PhRe;
//	float32 XU_3PhIm;
//	float32 XT_U3Ph;//Period time of measured 3-phase output load voltage
//	float32 XI_PhReFix;
//	float32 XI_PhImFix;
//	float32 XP_2qc;
//	float32 XP_3Ph;//3-phase output power
//	float32 XP_Ovp;
//	float32 XX_AI24;
//	float32 XX_AI29;
//	float32 XQ_3Ph;
//	float32 XI_DfInFlt;
//	float32 WU_Flt;
//	float32 XU_DcLk2;
//	float32 XH_Ovp_Est;
//	float32 XI_Rct1_Rms;
//	float32 XI_BtCp;//不确定
//};

///*
// * HSTOMA - Host interface signals from MCU to DSP *
// * */
//struct WORD1_BITS
//{
//	Uint16	C_CvOpSaDsp:1;//SRTOMA:Command Start Converter Operation to Dsp
//	Uint16	C_Sa2qcDsp:1;//SRTOMA:Command Start 2QC Operation to DSP
//	Uint16	C_FpgaPrSd:1;
//	Uint16	C_FpgaFsSd:1;
//	Uint16	C_FpgaSfSd:1;
//	Uint16	C_FpgaPrBc:1;
//	Uint16	RstPrSd:1;
//	Uint16	RstFsSd:1;
//	Uint16	RstSfSd:1;
//	Uint16	RstPrBc:1;
//	Uint16	C_FrOvp:1;//两处来源
//	Uint16	C_OvpFcTsDsp:1;
//	Uint16	B_3PhCvDh:1;//DCDSMA:Command 3 phase inverter discharge
//
//
//
//};
//union WORD1_REG
//{
//	Uint32				all;
//	struct WORD1_BITS	bit;
//};
//
//struct WORD2_BITS
//{
//	Uint16	A_PctMo:1;
//	Uint16	B_EnSiPoTs;
//	Uint16	B_FrcSiPoTs;
//
//};
//union WORD2_REG
//{
//	Uint32				all;
//	struct WORD2_BITS	bit;
//};
//
//struct WORD3_BITS
//{
//
//
//};
//union WORD3_REG
//{
//	Uint32				all;
//	struct WORD3_BITS	bit;
//};
//
//struct RSWDFPGA1_BITS
//{
//
//
//};
//union RSWDFPGA1_REG
//{
//	Uint32				all;
//	struct WORD3_BITS	bit;
//};
//
//struct
//{
//	float32 		WU_3PhDsp; //BAUC1MA
//	float32 		WF_3PhDsp; //UFCO1MA
//	float32 		WI_PhActDsp; //ACCLMA:Active phase current limit,post-transsient control,to the DSP
//	float32 		WI_PhRctDsp; //ACCLMA:
//	float32 		XX_IPhClTrsKpActDsp;//ACCLMA
//	float32 		XX_IPhClTrsKpRctDsp;//ACCLMA
//	float32 		XX_IPhClTrsKpAbsDsp;//ACCLMA
//	float32 		WI_BtCgLim;//BACCMA
//	float32 		WU_3PhReDsp;//PCTS2MA
//	float32 		WU_3PhImDsp;//PCTS2MA
//	float32 		WI_PctParSelTrip;//PGCLMG
//	float32 		XX_DdCmpFa;//APSIMA:Dead time compensation factor
//	Uint32  		Z_PrSd;//HSTIMA:Protective shutdown word
//	Uint32  		Z_FsSd;//HSTIMA:Fast shutdown word
//	Uint32  		Z_SfSd;//HSTIMA:Soft shutdown word
//	Uint32  		Z_PrBc;//HSTIMA:Protective blocking word
//	Uint32  		Z_BtCpPrBc;//HSTIMA:BtCp Protective blocking word
//	Uint32  		Z_Fpga203;//HSTIMA:Protective action word from FPGA,203
//	Uint32  		Z_Fpga205;//HSTIMA:Protective action word from FPGA,205
//	Uint32  		Z_Fpga206;//HSTIMA:Protective action word from FPGA,206
//	float32 		WU_BtDsp;//BAUC1MA:Battery voltage reference to DSP for BtCp control
//	union WORD1_REG	WORD1;
//	union WORD2_REG	WORD2;
//	union WORD3_REG	WORD3;
//	union WORD1_REG	RSWDFPGA1;
//};
//
