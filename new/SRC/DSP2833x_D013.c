//################################################################################
// FILE:    DSP2833x_DCU1.c
// TITLE:	NUGTCU_MCU
// DESCRIPTION: NUGTCU,Tint=250uS
//################################################################################
#include	"DSP2833x_Device.h"
#include	"DSP2833x_Examples.h"

#include "DSP2833x_D013.h"
//===================诊断信息=============================================================
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG1_BITS {		   // bits	 description
	Uint16	rsvd1				:6;//	0~5 缺省
	Uint16	XMPRF001			:1;//	6	机械故障，一般指的过流
	Uint16	IAOTMM_S_Tp_Hgh		:1;//	7	变流器内部过温
	Uint16	rsvd2				:1;//	8	缺省
	Uint16	MDCCOVF1			:1;//	9	OVP1测试异常
	Uint16	MDCCOVF2			:1;//	10	OVP2测试异常
	Uint16	XOTPF001			:1;//	11	多个温度传感器故障
	Uint16	XSTAF002			:1;//	12	MCM切除----MVB输入命令的反馈
	Uint16	XFANHIFL			:1;//	13	外部风扇全速故障
	Uint16	XFANLOFL			:1;//	14	外方风扇半速故障
	Uint16	TXYF012				:1;//	15	内部制冷故障
};
union	TCU_MM_OUT4_DIAG1{
	Uint16						all;
	struct	MM_OUT4_DIAG1_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG2_BITS {		   // bits	 description
	Uint16	GANIF004			:1;//	0	散热器温度测量故障
	Uint16	GANIF005			:1;//	1	制冷温度测量故障
	Uint16	ZDCCF001			:1;//	2	直流预充故障
	Uint16	GSSSF001			:1;//	3	时序故障
	Uint16	MDCDF003			:1;//	4	直流侧放电故障
	Uint16	ZPCTF001			:1;//	5	PCT故障
	Uint16	MPRAF039			:1;//	6	所有的速度传感器故障
	Uint16	MDIRF001			:1;//	7	方向选择故障
	Uint16	MBRTF001			:1;//	8	制动电阻过温
	Uint16	MMTPF001			:1;//	9	电机轴温1过温
	Uint16	MMTPF002			:1;//	10	电机轴温2过温
	Uint16	MMTPF003			:1;//	11	电机轴温3过温
	Uint16	MMTPF004			:1;//	12	电机轴温4过温
	Uint16	MOSPOSPE			:1;//	13	电机超速
	Uint16	MPBDF001			:1;//	14	功率平衡故障
	Uint16	MLSPF001			:1;//	15	直流侧过流
};
union	TCU_MM_OUT4_DIAG2{
	Uint16						all;
	struct	MM_OUT4_DIAG2_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG3_BITS {		   // bits	 description
	Uint16	MPRAF040			:1;//	0	变流器方向故障
	Uint16	MMTPSHI1			:1;//	1	电机轴温1高温
	Uint16	MMTPSHI2			:1;//	2	电机轴温2高温
	Uint16	MMTPSHI3			:1;//	3	电机轴温3高温
	Uint16	MMTPSHI4			:1;//	4	电机轴温4高温
	Uint16	XLTRF001			:1;//	5	跳闸继电器闭合故障
	Uint16	GDHSLTFL			:1;//	6	跳闸继电器断开故障
	Uint16	XSTAF001			:1;//	7	MCM隔离完成
	Uint16	MPRAF015			:1;//	8	IGBT1反馈故障
	Uint16	MPRAF016			:1;//	9	IGBT2反馈故障
	Uint16	MPRAF017			:1;//	10	IGBT3反馈故障
	Uint16	MPRAF018			:1;//	11	IGBT4反馈故障
	Uint16	MPRAF019			:1;//	12	IGBT5反馈故障
	Uint16	MPRAF020			:1;//	13	IGBT6反馈故障
	Uint16	MPRAF021			:1;//	14	IGBT7反馈故障
	Uint16	MPRAF022			:1;//	15	IGBT8反馈故障
};
union	TCU_MM_OUT4_DIAG3{
	Uint16						all;
	struct	MM_OUT4_DIAG3_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG4_BITS {		   // bits	 description
	Uint16	MPRAF040			:1;//	0	变流器散热器高温
	Uint16	MMTPSHI1			:1;//	1	内部电池跳线断开
	Uint16	MMTPSHI2			:1;//	2	外部全速/半速风扇故障
	Uint16	MMTPSHI3			:1;//	3	直流侧欠压
	Uint16	MMTPSHI4			:1;//	4	电容故障
	Uint16	XLTRF001			:1;//	5	电容管理故障
	Uint16	GDHSLTFL			:1;//	6	电机A相电流过流
	Uint16	XSTAF001			:1;//	7	电机B相电流过流
	Uint16	MPRAF015			:1;//	8	电机C相电流过流
	Uint16	MPRAF016			:1;//	9	直流侧过压
	Uint16	MPRAF017			:1;//	10	MCU过载
	Uint16	MPRAF018			:1;//	11	牵引安全/光纤使能故障
	Uint16	MPRAF019			:1;//	12	None
	Uint16	MPRAF020			:1;//	13	保护性关断故障
	Uint16	MPRAF021			:1;//	14	变流器散热器过温
	Uint16	MPRAF022			:1;//	15	接地故障
};
union	TCU_MM_OUT4_DIAG4{
	Uint16						all;
	struct	MM_OUT4_DIAG4_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG5_BITS {		   // bits	 description
	Uint16	MMPRF002			:1;//	0	电机1堵转
	Uint16	GDOTF001			:1;//	1	板卡过温
	Uint16	MOTPF002			:1;//	2	变流器内部温度过温故障
	Uint16	MPRAF003			:1;//	3	FPGA开关频率故障
	Uint16	MMPRF003			:1;//	4	电机2堵转
	Uint16	GCHSF002			:1;//	5	预充接触器断开故障
	Uint16	GCHSF001			:1;//	6	预充接触器闭合故障
	Uint16	XSTAF005			:1;//	7	预充电阻过温故障
	Uint16	MPRAHWFL			:1;//	8	DCU硬件故障
	Uint16	MPRAF004			:1;//	9	直流侧电压测量故障
	Uint16	MPRAF005			:1;//	10	直流侧输入电流故障
	Uint16	MPRAF006			:1;//	11	相电流A测量故障
	Uint16	MPRAF007			:1;//	12	相电流B测量故障
	Uint16	ZAPSF001			:1;//	13	MVB通讯故障
	Uint16	GSESF002004			:1;//	14	分离接触器断开故障
	Uint16	GSESF001003			:1;//	15	分离接触器闭合故障
};
union	TCU_MM_OUT4_DIAG5{
	Uint16						all;
	struct	MM_OUT4_DIAG5_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG6_BITS {		   // bits	 description
	Uint16	MPRAF031			:1;//	0	数传1故障
	Uint16	MPRAF032			:1;//	1	数传2故障
	Uint16	MPRAF033			:1;//	2	数传3故障
	Uint16	MPRAF034			:1;//	3	数传4故障
	Uint16	GANIF007			:1;//	4	板卡温度测量故障
	Uint16	GANIF011			:1;//	5	电机1轴温测量故障
	Uint16	GANIF012			:1;//	6	电机2轴温测量故障
	Uint16	GANIF013			:1;//	7	电机3轴温测量故障
	Uint16	GANIF014			:1;//	8	电机4轴温测量故障
	Uint16	GCALF003			:1;//	9	直流侧电流校准故障
	Uint16	GCALF004			:1;//	10	直流侧电压校准故障
	Uint16	GCALF002			:1;//	11	相电流校准故障
	Uint16	MPRAF014			:1;//	12	开关时间故障
	Uint16	TSYF001				:1;//	13	空转滑行触发
	Uint16	XVTEF001			:1;//	14	牵引/制动力似真性故障
	Uint16	MBRTHTOV			:1;//	15	制动电阻高温
};
union	TCU_MM_OUT4_DIAG6{
	Uint16						all;
	struct	MM_OUT4_DIAG6_BITS	bit;
};

extern const uint16_t car1_number[9];//用来分配端口号，不同的端口号只要修改数组中对于的元素即可
extern const uint16_t car2_number[9];//用来分配端口号，不同的端口号只要修改数组中对于的元素即可
extern const uint16_t car3_number[9];//用来分配端口号，不同的端口号只要修改数组中对于的元素即可
extern const uint16_t car4_number[9];//用来分配端口号，不同的端口号只要修改数组中对于的元素即可
extern uint16_t car1_flag,car2_flag,car3_flag,car4_flag;

extern set_HMI_TBUF(int i, unsigned char val);

union TCU_MM_OUT4_DIAG1	BIT_MM_OUT4_DIAG1;
union TCU_MM_OUT4_DIAG2	BIT_MM_OUT4_DIAG2;
union TCU_MM_OUT4_DIAG3	BIT_MM_OUT4_DIAG3;
union TCU_MM_OUT4_DIAG4	BIT_MM_OUT4_DIAG4;
union TCU_MM_OUT4_DIAG5	BIT_MM_OUT4_DIAG5;
union TCU_MM_OUT4_DIAG6	BIT_MM_OUT4_DIAG6;
Uint16 MyTemp =0;
int16 MVB_Address;//MVB地址线
int16 MVB_Sink_FN;//SINK800输入超时故障
int dddd;
unsigned char inb(unsigned short addr)
{
	extern int16	*XintfZone6;
	uint16_t v0 = *(XintfZone6 + 127 + (int16)addr);
	unsigned char v1 = (unsigned char)(v0 & 0x00ff);
	return v1;
}
void outb(unsigned char data, unsigned short addr)
{
	extern int16	*XintfZone6;
	uint16_t v = (uint16_t)data;
	*(XintfZone6 + 127 + (int16)addr) = v;
}

void delay_ms(int ms)
{
	DELAY_US(abs(ms) * 1000L);
}

//
// RX-TXD0-Write(0x) : 43 d0 18 53
// RX-TXD0-Read(0x)  : d0 18
#define addrDAT		(0)		// RX-TXD0 : read & write
#define addrSTA		(1)		// STAT0   : read only

extern void InitDGMVB(void);	// D013 RESET
//extern int d013main(void);		// D013 APP

extern void T2_data_TRx();
extern void T3_data_TRx();
extern void T4_data_TRx();
extern int d013main_car1 (void);
extern int d013main_car2 (void);
extern int d013main_car3 (void);
extern int d013main_car4 (void);
void MVB_Device_init(void);
void d013_ini(void);

void MVB_Device_init()
{

	MVB_Address = 0x11;
	switch (MVB_Address)
	{
		case 0x49:
		{
			d013main_car1 (); // 配置1车(M1)端口信息
			car1_flag=1;
			break;
		}
		case 0x4c:
		{
			d013main_car2 ();// 配置2车(M2)端口信息
			car2_flag=1;
			break;
		}
		case 0x4d:
		{
			d013main_car3 ();// 配置3车(M3)端口信息
			car3_flag=1;
			break;
		}
		case 0x48:
		{
			d013main_car4 ();// 配置4车(M4)端口信息
			car4_flag=1;
			break;
		}

		default:
		break;
	}

}

void d013_ini(void)
{
	volatile int a = 0;
    volatile int b = 0;
    volatile int c = 0;

	InitDGMVB();
	DELAY_US(1000000L);

//	outb(0x43, addrDAT);
//	outb(0xd0, addrDAT);
//	outb(0x18, addrDAT);
//	outb(0x53, addrDAT);
//	DELAY_US(1L);
//	a = inb(addrDAT);
//	b = inb(addrDAT);
//	c = a;
	MVB_Device_init();

//	d013main_car1();
}


void d013_1ms(void)
{
	uint32_t ttt0, ttt1;
	static int d = 1;
	static int aa = 1;
	static int ddd = 1;
	static Uint16 iTemp = 1;

	d ++;
/*	if(aa==0)
	{
		aa++;
		FPGA_WR[0]|=0x0001;
	}
	else	if(aa==1)
	{
		aa=0;
		FPGA_WR[0]&=0xfffe;
	}
	FPGA_WR[0]|=0x2100;*/
//	dddd=FPGA_WR[0]&0x0001;
/*	FPGA_WR[0]|=0X0200;	//DI测试禁能
	FPGA_WR[0]|=0X0100;	//光纤总使能
//	FPGA_WR[0]|=0X2000;	//FPGA保护使能
	FPGA_WR[0]|=0X1000;	//逆变使能*/

	if(MyTemp++==1)
	{
		FPGA_WR[0]|=0X0400;
		return;
	}
	else	if(MyTemp==10)
	{
		FPGA_WR[0]&=0xfbff;
		return;
	}
	else	if(MyTemp==12000)
	{
		FPGA_WR[0]|=0X0200;	//DI测试禁能
		FPGA_WR[0]|=0X0100;	//光纤总使能
		FPGA_WR[0]|=0X2000;	//FPGA保护使能
		FPGA_WR[0]|=0X1000;	//逆变使能
		return;
	}
	else	if(MyTemp>=24000)
	{
		MyTemp=0;
		return;
	}
	else return;



	BIT_MM_OUT4_DIAG1.all=12;
	BIT_MM_OUT4_DIAG2.all=23;
	BIT_MM_OUT4_DIAG3.all=34;
	BIT_MM_OUT4_DIAG4.all=45;
	BIT_MM_OUT4_DIAG5.all=56;
	BIT_MM_OUT4_DIAG6.all=67;



	HMI_TBUF[2] = 24;
	HMI_TBUF[3] = ((Uint16)AI[11] & 0x00FF);
	HMI_TBUF[4] = 0x01;
	HMI_TBUF[5] = 0x84;

	AO[4]=FPGA_RD[2];
	
	if(AI[12]>=0)iTemp=(Uint16)(AI[12]*10); 	//直流侧电压
	else	iTemp=~(abs)(AI[12]*10)+1;
	HMI_TBUF[12] = (iTemp >> 8) & 0x00FF;
	HMI_TBUF[13] = iTemp & 0x00FF;
	
	if(AI[13]>=0)iTemp=(Uint16)(AI[13]*10); 	//直流侧电流
	else	iTemp=~(abs)(AI[13]*10)+1;
	HMI_TBUF[14] = (iTemp >> 8) & 0x00FF;	
	HMI_TBUF[15] = iTemp & 0x00FF;
	
	if(AI[14]>=0)iTemp=(Uint16)(AI[14]*10); 	//交流A相电流
	else	iTemp=~(abs)(AI[14]*10)+1;
	HMI_TBUF[16] = (iTemp >> 8) & 0x00FF;//交流A相电流
	HMI_TBUF[17] = iTemp & 0x00FF;

	
	if(AI[15]>=0)iTemp=(Uint16)(AI[15]*10); 	//交流B相电流
	else	iTemp=~(abs)(AI[15]*10)+1;
	HMI_TBUF[18] = (iTemp >> 8) & 0x00FF;
	HMI_TBUF[19] = iTemp & 0x00FF;

	
	if(AI[16]>=0)iTemp=(Uint16)(AI[16]*10); 	//交流C相电流
	else	iTemp=~(abs)(AI[16]*10)+1;
	HMI_TBUF[20] = (iTemp >> 8) & 0x00FF;	
	HMI_TBUF[21] = iTemp & 0x00FF;

	
	if(AI[7]>=0)iTemp=(Uint16)AI[7];		//电机1转速采样值
	else	iTemp=~(abs)(AI[7])+1;
	HMI_TBUF[22] = (iTemp >> 8) & 0x00FF;		
	HMI_TBUF[23] = iTemp & 0x00FF;
	
	if(AI[8]>=0)iTemp=(Uint16)AI[8];		//电机2转速采样值
	else	iTemp=~(abs)(AI[8])+1;
	HMI_TBUF[24] = (iTemp >> 8) & 0x00FF;		
	HMI_TBUF[25] = iTemp & 0x00FF;

	HMI_TBUF[26] = (Uint16)(AI[11]) & 0x00FF;			//电机方向

	
	//环境温度
	HMI_TBUF[27] = (Uint16)(AI[0]+40) & 0x00FF;			
	//散热器温度	
	HMI_TBUF[28] = (Uint16)(AI[1]+40) & 0x00FF;
	//M1温度
	HMI_TBUF[29] = (Uint16)(AI[2]+40) & 0x00FF;
	//M2温度
	HMI_TBUF[30] = (Uint16)(AI[3]+40) & 0x00FF;		
	
	HMI_TBUF[32] = (((Uint16)FPGA_RD[2] >> 8) & 0x00FF);
	HMI_TBUF[33] = ((Uint16)FPGA_RD[2] & 0x00FF);

	HMI_TBUF[34] = (((Uint16)DPRAM_RD[24] >> 8) & 0x00FF);
	HMI_TBUF[35] = ((Uint16)DPRAM_RD[24] & 0x00FF);

	//HMI_TBUF[36] = (((Uint16)FPGA_RD[0] >> 8) & 0x00FF);
	//HMI_TBUF[37] = ((Uint16)FPGA_RD[0] & 0x00FF);
	HMI_TBUF[36] = ((Uint16)FPGA_RD[0] & 0x001F)+(((Uint16)FPGA_RD[0] & 0x0080)>>2)+(((Uint16)FPGA_RD[0] & 0x0020)<<1)+(((Uint16)FPGA_RD[0] & 0x0100)>>1);	//采样状态指示灯EF、TR_Safe、LTRB、DI5、DI4、DI3、DI2、DI1
	HMI_TBUF[37] = ((Uint16)FPGA_WR[0] & 0x007F)+(((Uint16)FPGA_WR[0] & 0x0100)>>1); 		//采样状态指示灯OPTOEN、DO7、DO6、DO5、DO4、DO3、DO2、DO1

	HMI_TBUF[38] = ((Uint16)FPGA_RD[1] & 0x00FF);

	HMI_TBUF[39] = (((Uint16)DPRAM_WR[1] >> 8) & 0x00FF);
	HMI_TBUF[40] = ((Uint16)DPRAM_WR[1] & 0x00FF);
	DPRAM_RD[1]=ddd;
	HMI_TBUF[53] = (((Uint16)DPRAM_RD[1] >> 8) & 0x00FF);
	HMI_TBUF[54] = ((Uint16)DPRAM_RD[1] & 0x00FF);

	ddd++;
	/*if(ddd>=5000)
		ddd=0;

	if((ddd%2510)==0)
		FPGA_WR[0] |= 0x0080;
	if((ddd%4510)==0)
		FPGA_WR[0] &= 0xFF7F;
*/
/*	if(car1_flag==1)//1车(M1)数据发送接收
	{
		if((d%16)==0)//T2-16ms周期
		{
			T2_data_TRx();
		}

		if((d%64)==0)//T3-64ms周期
		{
			T3_data_TRx();
		}

		if((d%1024)==0)//T4-1024ms周期
		{
			T4_data_TRx();
			d=0;//清零
		}
	}

	if(car2_flag==1)//2车(M2)数据发送接收
	{
		if((d%16)==0)//T2-16ms
		{
			T2_data_TRx();
		}

		if((d%64)==0)//T3-64ms
		{
			T3_data_TRx();
		}

		if((d%1024)==0)//T4-1024ms
		{
			T4_data_TRx();
			d=0;//清零
		}
	}

	if(car3_flag==1)//3车(M3)数据发送接收
	{
		if((d%16)==0)//T2-16ms
		{
			T2_data_TRx();
		}

		if((d%64)==0)//T3-64ms
		{
			T3_data_TRx();
		}

		if((d%1024)==0)//T4-1024ms
		{
			T4_data_TRx();
			d=0;//清零
		}
	}

	if(car4_flag==1)//4车(M4)数据发送接收
	{
		if((d%16)==0)//T2-16ms
		{
			T2_data_TRx();
		}

		if((d%64)==0)//T3-64ms
		{
			T3_data_TRx();
		}

		if((d%1024)==0)//T4-1024ms
		{
			T4_data_TRx();
			d=0;//清零
		}
	}


	MVB2_SRC4X0_T2[0] = 0x0102;
	MVB2_SRC4X0_T2[1] = 0x0304;
	ttt0 = MVB2_SINK4X8_T2[0];
	ttt1 = MVB2_SINK4X8_T2[1];*/
}
