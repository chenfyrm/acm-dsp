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
//闁插洦鐗遍妴浣瑰瘹娴狅拷
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
	float32 XU_PhABGt;					// AB閻╁摜鍤庨悽闈涘竾, V
	Uint16 NX_McuPlCn;				// MCU pulse(heartbeat) counter
	Uint16 NX_McuOpSt;				// MCU operation state
	Uint16 NX_McuVer;			// MCU version
	union MCUFLAG1_REG XX_McuFlag1;
};
volatile struct PX_In PX_In_Spf = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0x400,
		0x10, 0x00, };
//========================================================================
//娣囨繃濮㈤崐锟
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
volatile struct PX_InPr PX_InPr_Spf = { 1800.0,         		//閻╁瓨绁﹀В宥囧殠閻㈤潧甯囨稉濠囨
		0.0,         		//閻╁瓨绁﹀В宥囧殠閻㈤潧甯囨稉瀣
		0, 0, 10.0,         		//閻╁瓨绁﹀В宥囧殠閻㈠灚绁︽稉濠囨
		0, 300.0,         		//闁棗褰夐崳銊ㄧ翻閸戣櫣鏁稿ù浣风瑐闂勶拷
		0, 0, 0, 0.0, };         		//閻滎垰顣ㄥ〒鈺佸娑撳﹪妾
//-------------output-------------
//============================================================================================
struct WARN_BITS {
	Uint16 TA0 :1;		//閻╁瓨绁﹀В宥囧殠鏉╁洤甯囬妴浣圭懞閸樺绻氶幎锟
	Uint16 TA1 :1;		//閻╁瓨绁﹀В宥囧殠鏉╁洦绁︽穱婵囧Б
	Uint16 TA2 :1;		// Idc 闁插洦鐗辨穱婵囧Б
	Uint16 TA3 :1;		// Udc 闁插洦鐗辨穱婵囧Б
	Uint16 TA4 :1;		// DSP
	Uint16 TA5 :1;		//A閻╁摜鏁稿ù浣界箖濞翠椒绻氶幎锟
	Uint16 TA6 :1;		//B閻╁摜鏁稿ù浣界箖濞翠椒绻氶幎锟
	Uint16 TA7 :1;		//C閻╁摜鏁稿ù浣界箖濞翠椒绻氶幎锟
	Uint16 TA8 :1;		// Iac
	Uint16 TA9 :1;		// Ia
	Uint16 TA10 :1;		// Ib
	Uint16 TA11 :1;		// Ic
	Uint16 TA12 :1;		// Ia椤旓拷
	Uint16 TA13 :1;		// Ib椤旓拷
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
	Uint16 OvpCpAv :1;
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

//鏉堟挸鍤禍銈勭鞍閸婏拷
struct PX_Out {
	Uint16 XX_PwmMo;			// PWM mode  0x00  0x15
	Uint16 XT_PwmPdVv;   		// PWM period value,  for initialization
	Uint16 XX_Pwm1AVv;   		// PWM1A value
	Uint16 XX_Pwm2AVv;			// PWM2A value
	Uint16 XX_Pwm3AVv;			// PWM3A value
	Uint16 XX_Pwm4AVv;			// PWM4A value, chopper
	Uint16 XX_Pwm4BVv;			// PWM4B value, chopper
	float32 XU_PhAB_Rms;
	float32 XF_PhAB;
	float32 XI_PhA_Rms;		    // phase A current, RMS
	float32 XI_PhB_Rms;	    	// phase B current, RMS
	float32 XI_PhC_Rms;		    // phase C current, RMS
	float32 XP_Out;		    	// output power, kw
	float32 XQ_Out;
	float32 XI_DcLkEst;
	float32 XX_PhUbl;			// phase unbalance
	union WARN_REG XX_Flt1;			// 16娴ｅ秵鏅犻梾婊冪摟
	Uint16 SX_Run;
	Uint16 NX_DspPlCn;			// DSP2 pulse(heartbeat) counter
	union DSPST_REG NX_DspOpSt;	// NX_Dsp2OpSt: DSP2 operation state 0x11:閸掓繂顬婇崠鏍﹁厬      0x22:閸掓繂顬婇崠鏍с亼鐠愶拷   0x33:閸掓繂顬婇崠鏍х暚閹达拷
	union DSPST_REG oldDspSt;
	Uint16 NX_DspVer;			// DSP2 version
	union DSPFLAG1_REG XX_DspFlag1;
};
volatile struct PX_Out PX_Out_Spf = { 21,
		6944,			//閸欏矂鍣伴弽鍑ょ窗1450Hz:6465 1350Hz:6944
		3472, 3472, 3472, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0x0000,
		0x0000, 0x10, 0x0000, };
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
Uint16 Hold = 0;
volatile Uint16 Cnt_1ms = 0;
volatile Uint16 Cnt_4ms = 0;
volatile float32 Ext_U = 0.0;
volatile float32 Ext_F = 0.0;

int16 DA[8] = { 0 };

/* LOCAL FUNCTIONS */
void DPRAM_RD(void);
void DPRAM_WR(void);
void NX_Pr(void);
void EN_GPIO30(void);
void DIS_GPIO30(void);
interrupt void DPRAM_isr(void);
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

	DspInit();
	McuInit();

	while (1) {
		//--------------------------------------------------------------------------------
		GPIO_Temp181 = GpioDataRegs.GPADAT.bit.GPIO18;			//婢舵牠鍎存稉顓熸焽鏉堟挸鍙嗛弽鍥х箶娴ｏ拷
		DELAY_US(2L);
		//娑撴槒顪呴弰顖欒礋娴滃棗鍨介弬顓熸Ц閸氾箓鏆遍弮鍫曟？閺堫亣绻橀崗銉よ厬閺傤厼顦炬担宥忕礉濮濄倕顦甸崣顖炲櫚閻劍妫ら弫鍫濇閺冭绱濋幋鏍拷閹绘帒鍙嗛崗鏈电铂閺堝鏅ラ惃鍕⒔鐞涘奔鎹㈤崝锟
		GPIO_Temp182 = GpioDataRegs.GPADAT.bit.GPIO18;
		if ((GPIO_Temp181 == 0) && (GPIO_Temp182 == 0)) {
			PX_In_Spf.NX_McuPlCn = *(XintfZone7 + 0x7FFF);//婢舵牠鍎存稉顓熸焽婢跺秳缍呯拠顓炲綖,SDRAM鐠囩粯鎼锋担锟�
		}
	}
}
//==============================================================================
interrupt void DPRAM_isr(void) //after DSP1 has written to DPRAM, trigger the interrupt
{
	/*淇濇姢鐜板満*/
	float32 tmp = Tsc;
	Tsc = DspData.XT_Tsc;

	/**/
	PX_Out_Spf.NX_DspPlCn++;
	if (PX_Out_Spf.NX_DspPlCn > 32767)
		PX_Out_Spf.NX_DspPlCn = 0;

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
	DPRAM_RD(); //鐠囩睉CU娴溿倓绨版穱鈩冧紖

	NX_Pr();

	DspStCl();


		DspStep();

		Cnt_1ms++;
		if (Cnt_1ms >= 3) {
			float32 tmp = Tsc;
			Tsc = tmp * 3.0;

//		HSTI_T2();
			ACCL_T2();
//		OVPT_T2();
//		HSTO_T2();

			Cnt_1ms = 0;
			Tsc = tmp;
		}

		Cnt_4ms++;
		if (Cnt_4ms >= 11) {
			float32 tmp = Tsc;
			Tsc = tmp * 11.0;

			McuParam.PF_3PhNom = Limit(Ext_F, 40.0, 60.0);
			McuParam.PU_U3PhRef3 = Limit(Ext_U, 50.0, 100.0) * SQRT2bySQRT3;
			McuParam.PU_U3PhRef4 = McuParam.PU_U3PhRef3;

			McuStep();

			Cnt_4ms = 0;
			Tsc = tmp;
		}


	/**/
	if (PX_Out_Spf.SX_Run == 1) {
		if (DspData.XX_Mode == 1) {
			PX_Out_Spf.XX_PwmMo = 21; // FPGA闁槒绶敍姘愁吀閺佹澘娅掗崐鐓庛亣娴滃孩鐦潏鍐ㄦ珤閸婇棿璐熸姗堢礉閸旂姵顒撮崠鐚寸礉閸欐牕寮介敍宀�病閸忓姘﹂弶鍨晙閸欏秴鎮�
			PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv
					* (1.0 - DspData.XX_DutyA);
			PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv
					* (1.0 - DspData.XX_DutyB);
			PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv
					* (1.0 - DspData.XX_DutyC);
		}
		if (DspData.XX_Mode == 0) {
			PX_Out_Spf.XX_PwmMo = 0; // FPGA闁槒绶敍姘愁吀閺佹澘娅掗崐鐓庣毈娴滃孩鐦潏鍐ㄦ珤閸婇棿璐熸姗堢礉閸旂姵顒撮崠鐚寸礉閸欐牕寮介敍宀�病閸忓姘﹂弶鍨晙閸欏秴鎮�
			PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv * DspData.XX_DutyA;
			PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv * DspData.XX_DutyB;
			PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv * DspData.XX_DutyC;
		}
	} else {
		PX_Out_Spf.XX_PwmMo = 0;
		PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv * 0.5;
		PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv * 0.5;
		PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv * 0.5;
	}

	PX_Out_Spf.XU_PhAB_Rms = DspData.XU_3PhAbs / SQRT2;
	PX_Out_Spf.XF_PhAB = DspData.XF_U3Ph;
	PX_Out_Spf.XI_PhA_Rms = DspData.XI_Ph1Rms_Flt;
	PX_Out_Spf.XI_PhB_Rms = DspData.XI_Ph2Rms_Flt;
	PX_Out_Spf.XI_PhC_Rms = DspData.XI_Ph3Rms_Flt;
	PX_Out_Spf.XP_Out = DspData.XP_3Ph_Flt;
	PX_Out_Spf.XQ_Out = DspData.XQ_3Ph_Flt;
	PX_Out_Spf.XI_DcLkEst = DspData.XP_3Ph_Flt / DspData.XU_DcLkFlt;

	DPRAM_WR(); //閸愭獓sp娴溿倓绨版穱鈩冧紖

	EN_GPIO30();

	/*鎭㈠鐜板満*/
	Tsc = tmp;

	PieCtrlRegs.PIEACK.all |= PIEACK_GROUP1;
}
//==============================================================================
void DPRAM_RD(void) //MCU-->DSP
{
	//----------------------------------------------------
	PX_In_Spf.NX_McuPlCn = *(XintfZone7 + 0x7FFF); // MCU pulse(heartbeat) counter    (RAM 0x7FFF clear) 濮濄倛顢戦張锟藉帥鐠囦紮绱濇禍褏鏁揇PRAM娑擃厽鏌囧┃锟�
	//---------------------------------------------------------------------
	PX_In_Spf.NX_McuOpSt = *(XintfZone7 + 0x0001);		// MCU operation state
//	PX_In_Spf.NX_McuVer = 0x10;
	PX_In_Spf.XX_McuFlag1.all = *(XintfZone7 + 0x0014);

	DspData.XU_DcLk = *(XintfZone7 + 0x6) * 0.1 * 2.0;	// DC-link voltage, V
	DspData.XI_DcLk = 0;		// DC-link current, V
	DspData.XI_PhA = *(XintfZone7 + 0x8) * 0.1 / 2.0 * (-1.0);// phase A current, A
	DspData.XI_PhB = *(XintfZone7 + 0xA) * 0.1 / 2.0 * (-1.0);// phase B current, A
	DspData.XI_PhC = *(XintfZone7 + 0x9) * 0.1 / 2.0 * (-1.0);// phase C current, A
	DspData.XU_PhABLk = *(XintfZone7 + 0x7) * 0.1 * 2.0;// AB閻╂瓕绶崙铏瑰殠閻㈤潧甯� V 闁插洦鐗卞銈嗗皾鐎电懓绠欓崐鑲╂畱鐞涙澘鍣�50Hz閺冩儼鈥滈崙蹇庤礋0.5
	Ext_U = *(XintfZone7 + 0x11) * 10.0;
	Ext_F = *(XintfZone7 + 0x12) * 1.0;
}
//==============================================================================
void DPRAM_WR(void)			//DSP-->MCU
{
	/*閲嶆柊鐑у啓FPGA锛岀‘璁ゆ鍖哄拰PWM鍙戞尝
	 *
	 *
	 *
	 ************************************************************* */
//	DspData.XX_DutyA = 0.2;
//	DspData.XX_DutyB = 0.3;
//	DspData.XX_DutyC = 0.6;
//
//	PX_Out_Spf.XT_PwmPdVv = 6944;
//
//	if (DspData.XX_Mode) {
//		PX_Out_Spf.XX_PwmMo = 21; // FPGA闁槒绶敍姘愁吀閺佹澘娅掗崐鐓庛亣娴滃孩鐦潏鍐ㄦ珤閸婇棿璐熸姗堢礉閸旂姵顒撮崠鐚寸礉閸欐牕寮介敍宀�病閸忓姘﹂弶鍨晙閸欏秴鎮�
//		PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv
//				* (1.0 - DspData.XX_DutyA);
//		PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv
//				* (1.0 - DspData.XX_DutyB);
//		PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv
//				* (1.0 - DspData.XX_DutyC);
//	} else {
//		PX_Out_Spf.XX_PwmMo = 0; // FPGA闁槒绶敍姘愁吀閺佹澘娅掗崐鐓庣毈娴滃孩鐦潏鍐ㄦ珤閸婇棿璐熸姗堢礉閸旂姵顒撮崠鐚寸礉閸欐牕寮介敍宀�病閸忓姘﹂弶鍨晙閸欏秴鎮�
//		PX_Out_Spf.XX_Pwm1AVv = PX_Out_Spf.XT_PwmPdVv * DspData.XX_DutyA;
//		PX_Out_Spf.XX_Pwm2AVv = PX_Out_Spf.XT_PwmPdVv * DspData.XX_DutyB;
//		PX_Out_Spf.XX_Pwm3AVv = PX_Out_Spf.XT_PwmPdVv * DspData.XX_DutyC;
//	}
/*******************************************************************************/
	/*
	 *
	 *
	 *
	 * */
	*(XintfZone7 + 0x2) = PX_Out_Spf.NX_DspOpSt.all; // NX_Dsp2OpSt: DSP2 operation state
	*(XintfZone7 + 0x3) = PX_Out_Spf.NX_DspVer;		// DSP version
	*(XintfZone7 + 0x15) = PX_Out_Spf.XX_PwmMo;     // PWM  mode configuration
	*(XintfZone7 + 0x16) = PX_Out_Spf.XT_PwmPdVv;			// PWM period value
	*(XintfZone7 + 0x17) = PX_Out_Spf.XX_Pwm1AVv;			// PWM1A value
	*(XintfZone7 + 0x18) = PX_Out_Spf.XX_Pwm2AVv;			// PWM2A value
	*(XintfZone7 + 0x19) = PX_Out_Spf.XX_Pwm3AVv;			// PWM3A value
	*(XintfZone7 + 0x1A) = PX_Out_Spf.XX_Pwm4AVv;		// PWM4A value, chopper
	*(XintfZone7 + 0x1B) = PX_Out_Spf.XX_Pwm4BVv;

	*(XintfZone7 + 0x1C) = PX_Out_Spf.XU_PhAB_Rms;
	*(XintfZone7 + 0x1D) = PX_Out_Spf.XF_PhAB;
	*(XintfZone7 + 0x1E) = PX_Out_Spf.XI_PhA_Rms;
	*(XintfZone7 + 0x1F) = PX_Out_Spf.XI_PhB_Rms;
	*(XintfZone7 + 0x20) = PX_Out_Spf.XI_PhC_Rms;
	*(XintfZone7 + 0x21) = PX_Out_Spf.XP_Out;
	*(XintfZone7 + 0x22) = PX_Out_Spf.XQ_Out;
	*(XintfZone7 + 0x23) = PX_Out_Spf.XI_DcLkEst;

	*(XintfZone7 + 0x24) = PX_Out_Spf.NX_DspOpSt.all;
	*(XintfZone7 + 0x25) = PX_Out_Spf.XX_DspFlag1.all;

	*(XintfZone7 + 0x26) = PX_Out_Spf.XX_Flt1.all;		// DSP閺佸懘娈伴悩鑸碉拷

	/*娑撳﹣缍呴張锟�*/
//	*(XintfZone7 + 0x27) = McuData.WU_3PhDsp*10;
//	*(XintfZone7 + 0x28) = McuData.WF_3PhDsp*10;
//	*(XintfZone7 + 0x29) = DspData.XX_MRef*100;
//	*(XintfZone7 + 0x2A) = DspData.XI_Ph1Rms_Flt*10;
//	*(XintfZone7 + 0x27) = fabs((DspData.WU_3PhAbs / DspData.XU_DcLk) * 100);
//	*(XintfZone7 + 0x28) = fabs(PX_Out_Spf.XI_DcLkEst * 100);
//	*(XintfZone7 + 0x29) = fabs(PX_Out_Spf.XU_PhAB_Rms);
//	*(XintfZone7 + 0x2A) = fabs(PX_Out_Spf.XI_PhA_Rms);
//	*(XintfZone7 + 0x27) = fabs();
//	*(XintfZone7 + 0x28) = fabs();
//	*(XintfZone7 + 0x29) = fabs();
//	*(XintfZone7 + 0x2A) = fabs();
	//	DspData.WU_Ref_Abs
	//				DspData.WU_DcLkStb
	//	McuData.WU_3PhDsp
	//	 McuData.WU_3PhClIn
	//  McuData.WU_U3PhClOut
	//sogiosg.ComW
	//DspData.WU_3PhSec
	//DspData.WU_3PhPm
//	*(XintfZone7 + 0x27) = fabs(DspData.WU_Ref_Abs*10);
//	*(XintfZone7 + 0x28) = fabs(DspData.WU_DcLkStb*10);
//	*(XintfZone7 + 0x29) = fabs(McuData.WU_3PhDsp*10);
//	*(XintfZone7 + 0x2A) = fabs(McuData.WU_3PhClIn*10);
	*(XintfZone7 + 0x27) = fabs(McuData.WU_U3PhClOut * 10);
	*(XintfZone7 + 0x28) = fabs(DspData.XU_3PhAbs * 10);
	*(XintfZone7 + 0x29) = fabs(PI_U3PhCl.Ref * 10);
	*(XintfZone7 + 0x2A) = fabs(DspData.WU_3PhAbs * 10);

	//	*(XintfZone7 + 0x27) = fabs(DspData.WU_3PhSec.re*10);
	//	*(XintfZone7 + 0x28) = fabs(DspData.WU_3PhSec.im*10);
	//	*(XintfZone7 + 0x29) = fabs(DspData.WU_3PhPm.re*10);
	//	*(XintfZone7 + 0x2A) = fabs(DspData.WU_3PhPm.im*10);


	/*
	 *
	 * */

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
	*(XintfZone7 + 0x7FFE) = PX_Out_Spf.NX_DspPlCn;		//濮濄倛顢戦張锟芥倵閸愭瑱绱滵PRAM娴溠呮晸娑擃厽鏌囧┃锟�
//------------------------------------------------------------

}
//==============================================================================
/* 娣囨繃濮�*/
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
	if ((PX_In_Spf.NX_McuOpSt == 0x417) || (PX_In_Spf.NX_McuOpSt == 0x41C)
			|| (PX_In_Spf.NX_McuOpSt == 0x41A)
			|| (PX_In_Spf.NX_McuOpSt == 0x426)
			|| (PX_In_Spf.NX_McuOpSt == 0x41E)) {
		if ((PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0)
				&& (PX_Out_Spf.NX_DspOpSt.bit.CvSt > 0x0030)) {
			PX_Out_Spf.SX_Run = 0;
			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0020;
			if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
				PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
			}
		}
	}

//	//PrSd
//	if (PX_In_Spf.NX_McuOpSt == 0x41C) {
//		if ((PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0)
//				&& (PX_Out_Spf.NX_DspOpSt.bit.CvSt > 0x0030)) {
//			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
//			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0020;
//			if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
//				PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
//			}
//		}
//
//	}
//
//	//SfSd
//	if (PX_In_Spf.NX_McuOpSt == 0x41A) {
//		if ((PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0)
//				&& (PX_Out_Spf.NX_DspOpSt.bit.CvSt > 0x0030)) {
//			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
//			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0020;
//			if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
//				PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
//			}
//		}
//	}
//
//	//FsSd
//	if (PX_In_Spf.NX_McuOpSt == 0x426) {
//		if ((PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0)
//				&& (PX_Out_Spf.NX_DspOpSt.bit.CvSt > 0x0030)) {
//			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
//			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0020;
//			if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
//				PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
//			}
//		}
//	}
//
//	//Inso
//	if (PX_In_Spf.NX_McuOpSt == 0x41E) {
//		if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0) {
//			PX_Out_Spf.XX_DspFlag1.all = 0x0000;
//			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x0020;
//		}
//		if (PX_In_Spf.XX_McuFlag1.bit.OvpCpAv == 1) {
//			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
//		}
//	}

	//-------------------------------------------
	//閸掓繂顬婇崠锟�
	if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x00) {
		//
		//
		if (PX_In_Spf.NX_McuOpSt == 0x402)
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x10;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x10) {
		//---
		//---
		if (PX_In_Spf.NX_McuOpSt == 0x403)
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x20;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x20) {
		//閸欏倹鏆熼崚婵嗩瀶閸栵拷
		DspInit();
		McuInit();
		PX_Out_Spf.XX_DspFlag1.all = 0x0000;
		PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x30;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x30) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	}

	//------------------------------------------------------------
	//閸氼垰濮�
	else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x40) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (DspData.XU_3PhRms < 50.0) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x41;
			}
			if (DspData.XU_3PhRms > 370.0) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x42;
			}
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x41) {
		PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 1;
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
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x43) {
		DspData.C_CvOp = TRUE;
		PX_Out_Spf.SX_Run = 1;
		PX_Out_Spf.XX_DspFlag1.bit.CvOp = 1;
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (PX_Out_Spf.SX_Run == 1)
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x44;
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x44) {
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (McuData.A_FRmp == 1)
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

			} else {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x46;

			}
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x46) {

		//
		McuData.C_AuSz = 1;
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {

			if (McuData.A_AuSz == 1) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x47;

			}
		} else {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x47) {
		//
		PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 1;
		if ((PX_In_Spf.NX_McuOpSt == 0x408)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 1)) {
			if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 1) {
				PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x48;
			}
		} else
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x40;

	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x48) {

		//
		McuData.B_EnU3PhCl = TRUE;
		if (PX_In_Spf.NX_McuOpSt == 0x40A) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x50;
		} else {
		}
	}
	//--------------------------------------------------------
	//閸嬫粍顒�
	else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x50) {
		if ((PX_In_Spf.NX_McuOpSt == 0x40A)
				&& (PX_In_Spf.XX_McuFlag1.bit.CvOp == 0)) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x51;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x51) {
		//
		PX_Out_Spf.XX_DspFlag1.bit.CdAuLdCt = 0;
		if (PX_In_Spf.XX_McuFlag1.bit.CdAuLdCt == 0) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x52;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x52) {
		McuData.B_EnU3PhCl = FALSE;	//闂幆鎺у埗澶辨晥
		DspData.C_CvOp = FALSE;	//鐩爣棰戠巼涓烘渶灏忓�
		if (DspData.C_CvOp == 0)
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x53;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x53) {
		if (McuData.A_FRmp == 1)
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x54;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x54) {

		PX_Out_Spf.SX_Run = 0;
		PX_Out_Spf.XX_DspFlag1.bit.CvOp = 0;
		PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x55;
	} else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x55) {
		if (PX_In_Spf.NX_McuOpSt == 0x406) {
			PX_Out_Spf.NX_DspOpSt.bit.CvSt = 0x20;
		}
	}
	//------------------------------------------------
	//闁挎瑨顕�
	else if (PX_Out_Spf.oldDspSt.bit.CvSt == 0x60) {
		PX_Out_Spf.XX_DspFlag1.all = 0x0000;
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
		PX_Out_Spf.XX_DspFlag1.bit.OvpFcTs = 0;	//鏍囧織娓呴浂
		PX_Out_Spf.XX_DspFlag1.bit.OvpCpAv = 1;
		if (1) {
			PX_Out_Spf.XX_DspFlag1.bit.OvpFcTs = 1;
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x2;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.OvpCp == 0x2) {
		//
		PX_Out_Spf.XX_DspFlag1.bit.OvpCpAv = 0;

		if (PX_In_Spf.NX_McuOpSt == 0x404) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x0;
			PX_Out_Spf.XX_DspFlag1.bit.OvpFcTs = 0;
		}
		if ((PX_In_Spf.NX_McuOpSt == 0x40C) || (PX_In_Spf.NX_McuOpSt == 0x417)
				|| (PX_In_Spf.NX_McuOpSt == 0x41C)
				|| (PX_In_Spf.NX_McuOpSt == 0x41A)
				|| (PX_In_Spf.NX_McuOpSt == 0x426)
				|| (PX_In_Spf.NX_McuOpSt == 0x41E)) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x4;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.OvpCp == 0x4) {
		//
		DspData.C_OvpCpOp = 1;
		PX_Out_Spf.XX_DspFlag1.bit.OvpCpAv = 1;
		if ((PX_In_Spf.NX_McuOpSt == 0x40C) || (PX_In_Spf.NX_McuOpSt == 0x417)
				|| (PX_In_Spf.NX_McuOpSt == 0x41C)
				|| (PX_In_Spf.NX_McuOpSt == 0x41A)
				|| (PX_In_Spf.NX_McuOpSt == 0x426)
				|| (PX_In_Spf.NX_McuOpSt == 0x41E)) {
//			if (PX_In_Spf.XU_DcLk < 36.0) {
//				PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x6;
//			}
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x6;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.OvpCp == 0x6) {
		//
		DspData.C_OvpCpOp = 0;
		PX_Out_Spf.XX_DspFlag1.bit.OvpCpAv = 0;
		if ((PX_In_Spf.NX_McuOpSt == 0x404)) {
			PX_Out_Spf.NX_DspOpSt.bit.OvpCp = 0x0;
		}
	}
	//---------------------------------------------

	//-------------
	//BtCp
	if (PX_Out_Spf.oldDspSt.bit.BtCp == 0x0) {
		PX_Out_Spf.NX_DspOpSt.bit.BtCp = 0x4;
	} else if (PX_Out_Spf.oldDspSt.bit.BtCp == 0x2) {
		DspData.C_BtCpOp = 1;
		PX_Out_Spf.XX_DspFlag1.bit.BtCpAv = 0x1;
		if (PX_In_Spf.XX_McuFlag1.bit.BtCpAv == 0) {
			PX_Out_Spf.NX_DspOpSt.bit.BtCp = 0x4;
		}
	} else if (PX_Out_Spf.oldDspSt.bit.BtCp == 0x4) {
		DspData.C_BtCpOp = 0;
		PX_Out_Spf.XX_DspFlag1.bit.BtCpAv = 0x0;
		if (PX_In_Spf.XX_McuFlag1.bit.BtCpAv == 1) {
			PX_Out_Spf.NX_DspOpSt.bit.BtCp = 0x2;
		}
	}

	PX_Out_Spf.oldDspSt.all = PX_Out_Spf.NX_DspOpSt.all;
	//------------------------------------------
}

//===============================================================================================
//=========================================THE END===============================================
//===============================================================================================
