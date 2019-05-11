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
//閲囨牱銆佹寚浠�
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
	float32 XU_PhABGt;					// AB鐩哥嚎鐢靛帇, V
	Uint16 NX_McuPlCn;				// MCU pulse(heartbeat) counter
	Uint16 NX_McuOpSt;				// MCU operation state
	Uint16 NX_McuVer;			// MCU version
	union MCUFLAG1_REG XX_McuFlag1;
};
volatile struct PX_In PX_In_Spf = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0x400,
		0x10, 0x00, };
//========================================================================
//淇濇姢鍊�
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
volatile struct PX_InPr PX_InPr_Spf = { 1800.0,         		//鐩存祦姣嶇嚎鐢靛帇涓婇檺
		0.0,         		//鐩存祦姣嶇嚎鐢靛帇涓嬮檺
		0, 0, 10.0,         		//鐩存祦姣嶇嚎鐢垫祦涓婇檺
		0, 300.0,         		//閫嗗彉鍣ㄨ緭鍑虹數娴佷笂闄�
		0, 0, 0, 0.0, };         		//鐜娓╁害涓婇檺
//-------------output-------------
//============================================================================================
struct WARN_BITS {
	Uint16 TA0 :1;		//鐩存祦姣嶇嚎杩囧帇銆佹瑺鍘嬩繚鎶�
	Uint16 TA1 :1;		//鐩存祦姣嶇嚎杩囨祦淇濇姢
	Uint16 TA2 :1;		// Idc 閲囨牱淇濇姢
	Uint16 TA3 :1;		// Udc 閲囨牱淇濇姢
	Uint16 TA4 :1;		// DSP
	Uint16 TA5 :1;		//A鐩哥數娴佽繃娴佷繚鎶�
	Uint16 TA6 :1;		//B鐩哥數娴佽繃娴佷繚鎶�
	Uint16 TA7 :1;		//C鐩哥數娴佽繃娴佷繚鎶�
	Uint16 TA8 :1;		// Iac
	Uint16 TA9 :1;		// Ia
	Uint16 TA10 :1;		// Ib
	Uint16 TA11 :1;		// Ic
	Uint16 TA12 :1;		// Ia顔�
	Uint16 TA13 :1;		// Ib顔�
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

//杈撳嚭浜や簰鍊�
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
	union WARN_REG XX_Flt1;			// 16浣嶆晠闅滃瓧
	Uint16 SX_Run;
	Uint16 NX_DspPlCn;			// DSP2 pulse(heartbeat) counter
	union DSPST_REG NX_DspOpSt;	// NX_Dsp2OpSt: DSP2 operation state 0x11:鍒濆鍖栦腑      0x22:鍒濆鍖栧け璐�   0x33:鍒濆鍖栧畬鎴�
	union DSPST_REG oldDspSt;
	Uint16 NX_DspVer;			// DSP2 version
	union DSPFLAG1_REG XX_DspFlag1;
};
volatile struct PX_Out PX_Out_Spf = { 21,
		6944,			//鍙岄噰鏍凤細1450Hz:6465 1350Hz:6944
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
		GPIO_Temp181 = GpioDataRegs.GPADAT.bit.GPIO18;			//澶栭儴涓柇杈撳叆鏍囧織浣�
		DELAY_US(2L);
		//涓昏鏄负浜嗗垽鏂槸鍚﹂暱鏃堕棿鏈繘鍏ヤ腑鏂浣嶏紝姝ゅ鍙噰鐢ㄦ棤鏁堝欢鏃讹紝鎴栬�鎻掑叆鍏朵粬鏈夋晥鐨勬墽琛屼换鍔�
		GPIO_Temp182 = GpioDataRegs.GPADAT.bit.GPIO18;
		if ((GPIO_Temp181 == 0) && (GPIO_Temp182 == 0)) {
			PX_In_Spf.NX_McuPlCn = *(XintfZone7 + 0x7FFF);//澶栭儴涓柇澶嶄綅璇彞,SDRAM璇绘搷浣�
		}
	}
}
//==============================================================================
interrupt void DPRAM_isr(void) //after DSP1 has written to DPRAM, trigger the interrupt
{
	PX_Out_Spf.NX_DspPlCn++;
	if (PX_Out_Spf.NX_DspPlCn > 32767)
		PX_Out_Spf.NX_DspPlCn = 0;

	Tsc = DspData.XT_Tsc;

//	Cnt_Period++;
//	if (Cnt_Period >= 2700) {
//		Cnt_sec++;
//		Cnt_Period = 0;
//	}
//	if (Cnt_sec >= 60) {
//		Cnt_min++;
//		Cnt_sec = 0;
//	}
//	if (Cnt_min >= 60) {
//		Cnt_min = 60;
//	}

	DIS_GPIO30();
	DPRAM_RD(); //璇籑CU浜や簰淇℃伅

	NX_Pr();

	DspStCl();
	McuStep();
	DspStep();

	/**/
	if (PX_Out_Spf.SX_Run == 1) {

//		McuData.XX_DutyA = 0.5;
//		McuData.XX_DutyB = 0.5;
//		McuData.XX_DutyC = 0.5;

		if (DspData.XX_Mode == 1) {
			PX_Out_Spf.XX_PwmMo = 21; // FPGA閫昏緫锛氳鏁板櫒鍊煎ぇ浜庢瘮杈冨櫒鍊间负楂橈紝鍔犳鍖猴紝鍙栧弽锛岀粡鍏夌氦鏉垮啀鍙嶅悜
			PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv
					* (1.0 - DspData.XX_DutyA);
			PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv
					* (1.0 - DspData.XX_DutyB);
			PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv
					* (1.0 - DspData.XX_DutyC);
		}
		if (DspData.XX_Mode == 0) {
			PX_Out_Spf.XX_PwmMo = 0; // FPGA閫昏緫锛氳鏁板櫒鍊煎皬浜庢瘮杈冨櫒鍊间负楂橈紝鍔犳鍖猴紝鍙栧弽锛岀粡鍏夌氦鏉垮啀鍙嶅悜
			PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv * DspData.XX_DutyA;
			PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv * DspData.XX_DutyB;
			PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv * DspData.XX_DutyC;
		}
	} else {
		PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv * 0.5;
		PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv * 0.5;
		PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv * 0.5;
	}

	DPRAM_WR(); //鍐檇sp浜や簰淇℃伅
	PieCtrlRegs.PIEACK.all |= PIEACK_GROUP1;

	EN_GPIO30();
}
//==============================================================================
void DPRAM_RD(void) //MCU-->DSP
{
	//----------------------------------------------------
	PX_In_Spf.NX_McuPlCn = *(XintfZone7 + 0x7FFF); // MCU pulse(heartbeat) counter    (RAM 0x7FFF clear) 姝よ鏈�厛璇伙紝浜х敓DPRAM涓柇婧�
	//---------------------------------------------------------------------
	PX_In_Spf.NX_McuOpSt = *(XintfZone7 + 0x0001);		// MCU operation state
//	PX_In_Spf.NX_McuVer = 0x10;
	PX_In_Spf.XX_McuFlag1.all = *(XintfZone7 + 0x0014);

	DspData.XU_DcLk = *(XintfZone7 + 0x6) * 0.1 * 2.0;	// DC-link voltage, V
	DspData.XI_DcLk = 0;		// DC-link current, V
	DspData.XI_PhA = *(XintfZone7 + 0x8) * 0.1 / 2.0 * (-1.0);// phase A current, A
	DspData.XI_PhB = *(XintfZone7 + 0xA) * 0.1 / 2.0 * (-1.0);// phase B current, A
	DspData.XI_PhC = *(XintfZone7 + 0x9) * 0.1 / 2.0 * (-1.0);// phase C current, A
	DspData.XU_PhABLk = *(XintfZone7 + 0x7) * 0.1 * 2.0;// AB鐩歌緭鍑虹嚎鐢靛帇, V 閲囨牱婊ゆ尝瀵瑰箙鍊肩殑琛板噺 50Hz鏃惰“鍑忎负0.5
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
	*(XintfZone7 + 0x26) = PX_Out_Spf.XX_Flt1.all;		// DSP鏁呴殰鐘舵�

	/*涓婁綅鏈�*/
	*(XintfZone7 + 0x27) = McuData.WU_3PhDsp;
	*(XintfZone7 + 0x28) = McuData.WF_3PhDsp;
	*(XintfZone7 + 0x29) = DspData.XU_3PhAbs;
	*(XintfZone7 + 0x2A) = DspData.XU_3PhAbs/DspData.XU_DcLk;

	/*DA杈撳嚭*/
	DA[3] = 0.0;
	DA[4] = 0.0;
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

//---------------------------------------------------
	*(XintfZone7 + 0x7FFE) = PX_Out_Spf.NX_DspPlCn;		//姝よ鏈�悗鍐欙紝DPRAM浜х敓涓柇婧�
//------------------------------------------------------------

}
//==============================================================================
/* 淇濇姢 */
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

//=================
void OvpCp(void) {

}
//=================
void BtCp(void) {

}
//==================
void DspStCl(void) {

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
	//鍒濆鍖�
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
		//鍙傛暟鍒濆鍖�
		DspInit();

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
	//鍚姩
	else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x40) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (DspData.XU_3PhRms < 50.0) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x41;
				PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 1;
			}
			if (DspData.XU_3PhRms > 370.0) {
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
			DspData.A_CvOp = TRUE;
			PX_Out_Spf.SX_Run = 1;
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x43) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (DspData.A_CvOp == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x44;
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x44) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (McuData.A_FNom == 1)
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
				McuData.B_EnU3PhCl = TRUE;
			} else {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x46;
				McuData.C_AuSz = 1;
			}
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x46) {

		//
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {

			if (McuData.A_AuSz == 1) {
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
				McuData.B_EnU3PhCl = TRUE;
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
	//鍋滄
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
		McuData.A_CvOp = FALSE;
		if (McuData.A_CvOp == 0)
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x53;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x53) {
		if (McuData.A_FNom == 1)
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
	//閿欒
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
			McuData.A_OvpCpOp = 1;
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
				McuData.A_OvpCpOp = 0;
			}
		}
	} else if (PX_Out_Spf.oldDspSt.bit.OvpCp == 0x6) {
		//
		PX_Out_Spf.XX_DspFlag1.bit.OvpFcTsAv = 0;
		if ((PX_In_Spf.NX_McuOpSt == 0x404) || (PX_In_Spf.NX_McuOpSt == 0x418)
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
			McuData.A_BtCpOp = 0;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.BtCp == 0x4) {
		PX_Out_Spf.XX_DspFlag1.bit.BtCpAv = 0x0;
		if (PX_In_Spf.XX_McuFlag1.bit.BtCpAv == 1) {
			PX_Out_Spf.NX_DspOpSt.bit.BtCp = 0x2;
			McuData.A_BtCpOp = 1;
		}
	}

	PX_Out_Spf.oldDspSt.all = PX_Out_Spf.NX_DspOpSt.all;
	//------------------------------------------
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

//===============================================================================================
//=========================================THE END===============================================
//===============================================================================================
