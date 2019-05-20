//################################################################################
// FILE:    DSP2833x_DCU1.c
// TITLE:	NUGTCU_MCU
// DESCRIPTION: NUGTCU,Tint=250uS
//################################################################################
#include	"DSP2833x_Device.h"
#include	"DSP2833x_Examples.h"

#include "DSP2833x_D013.h"
//===================�����Ϣ=============================================================
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG1_BITS {		   // bits	 description
	Uint16	rsvd1				:6;//	0~5 ȱʡ
	Uint16	XMPRF001			:1;//	6	��е���ϣ�һ��ָ�Ĺ���
	Uint16	IAOTMM_S_Tp_Hgh		:1;//	7	�������ڲ�����
	Uint16	rsvd2				:1;//	8	ȱʡ
	Uint16	MDCCOVF1			:1;//	9	OVP1�����쳣
	Uint16	MDCCOVF2			:1;//	10	OVP2�����쳣
	Uint16	XOTPF001			:1;//	11	����¶ȴ���������
	Uint16	XSTAF002			:1;//	12	MCM�г�----MVB��������ķ���
	Uint16	XFANHIFL			:1;//	13	�ⲿ����ȫ�ٹ���
	Uint16	XFANLOFL			:1;//	14	�ⷽ���Ȱ��ٹ���
	Uint16	TXYF012				:1;//	15	�ڲ��������
};
union	TCU_MM_OUT4_DIAG1{
	Uint16						all;
	struct	MM_OUT4_DIAG1_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG2_BITS {		   // bits	 description
	Uint16	GANIF004			:1;//	0	ɢ�����¶Ȳ�������
	Uint16	GANIF005			:1;//	1	�����¶Ȳ�������
	Uint16	ZDCCF001			:1;//	2	ֱ��Ԥ�����
	Uint16	GSSSF001			:1;//	3	ʱ�����
	Uint16	MDCDF003			:1;//	4	ֱ����ŵ����
	Uint16	ZPCTF001			:1;//	5	PCT����
	Uint16	MPRAF039			:1;//	6	���е��ٶȴ���������
	Uint16	MDIRF001			:1;//	7	����ѡ�����
	Uint16	MBRTF001			:1;//	8	�ƶ��������
	Uint16	MMTPF001			:1;//	9	�������1����
	Uint16	MMTPF002			:1;//	10	�������2����
	Uint16	MMTPF003			:1;//	11	�������3����
	Uint16	MMTPF004			:1;//	12	�������4����
	Uint16	MOSPOSPE			:1;//	13	�������
	Uint16	MPBDF001			:1;//	14	����ƽ�����
	Uint16	MLSPF001			:1;//	15	ֱ�������
};
union	TCU_MM_OUT4_DIAG2{
	Uint16						all;
	struct	MM_OUT4_DIAG2_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG3_BITS {		   // bits	 description
	Uint16	MPRAF040			:1;//	0	�������������
	Uint16	MMTPSHI1			:1;//	1	�������1����
	Uint16	MMTPSHI2			:1;//	2	�������2����
	Uint16	MMTPSHI3			:1;//	3	�������3����
	Uint16	MMTPSHI4			:1;//	4	�������4����
	Uint16	XLTRF001			:1;//	5	��բ�̵����պϹ���
	Uint16	GDHSLTFL			:1;//	6	��բ�̵����Ͽ�����
	Uint16	XSTAF001			:1;//	7	MCM�������
	Uint16	MPRAF015			:1;//	8	IGBT1��������
	Uint16	MPRAF016			:1;//	9	IGBT2��������
	Uint16	MPRAF017			:1;//	10	IGBT3��������
	Uint16	MPRAF018			:1;//	11	IGBT4��������
	Uint16	MPRAF019			:1;//	12	IGBT5��������
	Uint16	MPRAF020			:1;//	13	IGBT6��������
	Uint16	MPRAF021			:1;//	14	IGBT7��������
	Uint16	MPRAF022			:1;//	15	IGBT8��������
};
union	TCU_MM_OUT4_DIAG3{
	Uint16						all;
	struct	MM_OUT4_DIAG3_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG4_BITS {		   // bits	 description
	Uint16	MPRAF040			:1;//	0	������ɢ��������
	Uint16	MMTPSHI1			:1;//	1	�ڲ�������߶Ͽ�
	Uint16	MMTPSHI2			:1;//	2	�ⲿȫ��/���ٷ��ȹ���
	Uint16	MMTPSHI3			:1;//	3	ֱ����Ƿѹ
	Uint16	MMTPSHI4			:1;//	4	���ݹ���
	Uint16	XLTRF001			:1;//	5	���ݹ������
	Uint16	GDHSLTFL			:1;//	6	���A���������
	Uint16	XSTAF001			:1;//	7	���B���������
	Uint16	MPRAF015			:1;//	8	���C���������
	Uint16	MPRAF016			:1;//	9	ֱ�����ѹ
	Uint16	MPRAF017			:1;//	10	MCU����
	Uint16	MPRAF018			:1;//	11	ǣ����ȫ/����ʹ�ܹ���
	Uint16	MPRAF019			:1;//	12	None
	Uint16	MPRAF020			:1;//	13	�����ԹضϹ���
	Uint16	MPRAF021			:1;//	14	������ɢ��������
	Uint16	MPRAF022			:1;//	15	�ӵع���
};
union	TCU_MM_OUT4_DIAG4{
	Uint16						all;
	struct	MM_OUT4_DIAG4_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG5_BITS {		   // bits	 description
	Uint16	MMPRF002			:1;//	0	���1��ת
	Uint16	GDOTF001			:1;//	1	�忨����
	Uint16	MOTPF002			:1;//	2	�������ڲ��¶ȹ��¹���
	Uint16	MPRAF003			:1;//	3	FPGA����Ƶ�ʹ���
	Uint16	MMPRF003			:1;//	4	���2��ת
	Uint16	GCHSF002			:1;//	5	Ԥ��Ӵ����Ͽ�����
	Uint16	GCHSF001			:1;//	6	Ԥ��Ӵ����պϹ���
	Uint16	XSTAF005			:1;//	7	Ԥ�������¹���
	Uint16	MPRAHWFL			:1;//	8	DCUӲ������
	Uint16	MPRAF004			:1;//	9	ֱ�����ѹ��������
	Uint16	MPRAF005			:1;//	10	ֱ���������������
	Uint16	MPRAF006			:1;//	11	�����A��������
	Uint16	MPRAF007			:1;//	12	�����B��������
	Uint16	ZAPSF001			:1;//	13	MVBͨѶ����
	Uint16	GSESF002004			:1;//	14	����Ӵ����Ͽ�����
	Uint16	GSESF001003			:1;//	15	����Ӵ����պϹ���
};
union	TCU_MM_OUT4_DIAG5{
	Uint16						all;
	struct	MM_OUT4_DIAG5_BITS	bit;
};
//-------------------------------------------------------------------
struct	MM_OUT4_DIAG6_BITS {		   // bits	 description
	Uint16	MPRAF031			:1;//	0	����1����
	Uint16	MPRAF032			:1;//	1	����2����
	Uint16	MPRAF033			:1;//	2	����3����
	Uint16	MPRAF034			:1;//	3	����4����
	Uint16	GANIF007			:1;//	4	�忨�¶Ȳ�������
	Uint16	GANIF011			:1;//	5	���1���²�������
	Uint16	GANIF012			:1;//	6	���2���²�������
	Uint16	GANIF013			:1;//	7	���3���²�������
	Uint16	GANIF014			:1;//	8	���4���²�������
	Uint16	GCALF003			:1;//	9	ֱ�������У׼����
	Uint16	GCALF004			:1;//	10	ֱ�����ѹУ׼����
	Uint16	GCALF002			:1;//	11	�����У׼����
	Uint16	MPRAF014			:1;//	12	����ʱ�����
	Uint16	TSYF001				:1;//	13	��ת���д���
	Uint16	XVTEF001			:1;//	14	ǣ��/�ƶ��������Թ���
	Uint16	MBRTHTOV			:1;//	15	�ƶ��������
};
union	TCU_MM_OUT4_DIAG6{
	Uint16						all;
	struct	MM_OUT4_DIAG6_BITS	bit;
};

extern const uint16_t car1_number[9];//��������˿ںţ���ͬ�Ķ˿ں�ֻҪ�޸������ж��ڵ�Ԫ�ؼ���
extern const uint16_t car2_number[9];//��������˿ںţ���ͬ�Ķ˿ں�ֻҪ�޸������ж��ڵ�Ԫ�ؼ���
extern const uint16_t car3_number[9];//��������˿ںţ���ͬ�Ķ˿ں�ֻҪ�޸������ж��ڵ�Ԫ�ؼ���
extern const uint16_t car4_number[9];//��������˿ںţ���ͬ�Ķ˿ں�ֻҪ�޸������ж��ڵ�Ԫ�ؼ���
extern uint16_t car1_flag,car2_flag,car3_flag,car4_flag;

extern set_HMI_TBUF(int i, unsigned char val);

union TCU_MM_OUT4_DIAG1	BIT_MM_OUT4_DIAG1;
union TCU_MM_OUT4_DIAG2	BIT_MM_OUT4_DIAG2;
union TCU_MM_OUT4_DIAG3	BIT_MM_OUT4_DIAG3;
union TCU_MM_OUT4_DIAG4	BIT_MM_OUT4_DIAG4;
union TCU_MM_OUT4_DIAG5	BIT_MM_OUT4_DIAG5;
union TCU_MM_OUT4_DIAG6	BIT_MM_OUT4_DIAG6;
Uint16 MyTemp =0;
int16 MVB_Address;//MVB��ַ��
int16 MVB_Sink_FN;//SINK800���볬ʱ����
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
			d013main_car1 (); // ����1��(M1)�˿���Ϣ
			car1_flag=1;
			break;
		}
		case 0x4c:
		{
			d013main_car2 ();// ����2��(M2)�˿���Ϣ
			car2_flag=1;
			break;
		}
		case 0x4d:
		{
			d013main_car3 ();// ����3��(M3)�˿���Ϣ
			car3_flag=1;
			break;
		}
		case 0x48:
		{
			d013main_car4 ();// ����4��(M4)�˿���Ϣ
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
/*	FPGA_WR[0]|=0X0200;	//DI���Խ���
	FPGA_WR[0]|=0X0100;	//������ʹ��
//	FPGA_WR[0]|=0X2000;	//FPGA����ʹ��
	FPGA_WR[0]|=0X1000;	//���ʹ��*/

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
		FPGA_WR[0]|=0X0200;	//DI���Խ���
		FPGA_WR[0]|=0X0100;	//������ʹ��
		FPGA_WR[0]|=0X2000;	//FPGA����ʹ��
		FPGA_WR[0]|=0X1000;	//���ʹ��
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
	
	if(AI[12]>=0)iTemp=(Uint16)(AI[12]*10); 	//ֱ�����ѹ
	else	iTemp=~(abs)(AI[12]*10)+1;
	HMI_TBUF[12] = (iTemp >> 8) & 0x00FF;
	HMI_TBUF[13] = iTemp & 0x00FF;
	
	if(AI[13]>=0)iTemp=(Uint16)(AI[13]*10); 	//ֱ�������
	else	iTemp=~(abs)(AI[13]*10)+1;
	HMI_TBUF[14] = (iTemp >> 8) & 0x00FF;	
	HMI_TBUF[15] = iTemp & 0x00FF;
	
	if(AI[14]>=0)iTemp=(Uint16)(AI[14]*10); 	//����A�����
	else	iTemp=~(abs)(AI[14]*10)+1;
	HMI_TBUF[16] = (iTemp >> 8) & 0x00FF;//����A�����
	HMI_TBUF[17] = iTemp & 0x00FF;

	
	if(AI[15]>=0)iTemp=(Uint16)(AI[15]*10); 	//����B�����
	else	iTemp=~(abs)(AI[15]*10)+1;
	HMI_TBUF[18] = (iTemp >> 8) & 0x00FF;
	HMI_TBUF[19] = iTemp & 0x00FF;

	
	if(AI[16]>=0)iTemp=(Uint16)(AI[16]*10); 	//����C�����
	else	iTemp=~(abs)(AI[16]*10)+1;
	HMI_TBUF[20] = (iTemp >> 8) & 0x00FF;	
	HMI_TBUF[21] = iTemp & 0x00FF;

	
	if(AI[7]>=0)iTemp=(Uint16)AI[7];		//���1ת�ٲ���ֵ
	else	iTemp=~(abs)(AI[7])+1;
	HMI_TBUF[22] = (iTemp >> 8) & 0x00FF;		
	HMI_TBUF[23] = iTemp & 0x00FF;
	
	if(AI[8]>=0)iTemp=(Uint16)AI[8];		//���2ת�ٲ���ֵ
	else	iTemp=~(abs)(AI[8])+1;
	HMI_TBUF[24] = (iTemp >> 8) & 0x00FF;		
	HMI_TBUF[25] = iTemp & 0x00FF;

	HMI_TBUF[26] = (Uint16)(AI[11]) & 0x00FF;			//�������

	
	//�����¶�
	HMI_TBUF[27] = (Uint16)(AI[0]+40) & 0x00FF;			
	//ɢ�����¶�	
	HMI_TBUF[28] = (Uint16)(AI[1]+40) & 0x00FF;
	//M1�¶�
	HMI_TBUF[29] = (Uint16)(AI[2]+40) & 0x00FF;
	//M2�¶�
	HMI_TBUF[30] = (Uint16)(AI[3]+40) & 0x00FF;		
	
	HMI_TBUF[32] = (((Uint16)FPGA_RD[2] >> 8) & 0x00FF);
	HMI_TBUF[33] = ((Uint16)FPGA_RD[2] & 0x00FF);

	HMI_TBUF[34] = (((Uint16)DPRAM_RD[24] >> 8) & 0x00FF);
	HMI_TBUF[35] = ((Uint16)DPRAM_RD[24] & 0x00FF);

	//HMI_TBUF[36] = (((Uint16)FPGA_RD[0] >> 8) & 0x00FF);
	//HMI_TBUF[37] = ((Uint16)FPGA_RD[0] & 0x00FF);
	HMI_TBUF[36] = ((Uint16)FPGA_RD[0] & 0x001F)+(((Uint16)FPGA_RD[0] & 0x0080)>>2)+(((Uint16)FPGA_RD[0] & 0x0020)<<1)+(((Uint16)FPGA_RD[0] & 0x0100)>>1);	//����״ָ̬ʾ��EF��TR_Safe��LTRB��DI5��DI4��DI3��DI2��DI1
	HMI_TBUF[37] = ((Uint16)FPGA_WR[0] & 0x007F)+(((Uint16)FPGA_WR[0] & 0x0100)>>1); 		//����״ָ̬ʾ��OPTOEN��DO7��DO6��DO5��DO4��DO3��DO2��DO1

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
/*	if(car1_flag==1)//1��(M1)���ݷ��ͽ���
	{
		if((d%16)==0)//T2-16ms����
		{
			T2_data_TRx();
		}

		if((d%64)==0)//T3-64ms����
		{
			T3_data_TRx();
		}

		if((d%1024)==0)//T4-1024ms����
		{
			T4_data_TRx();
			d=0;//����
		}
	}

	if(car2_flag==1)//2��(M2)���ݷ��ͽ���
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
			d=0;//����
		}
	}

	if(car3_flag==1)//3��(M3)���ݷ��ͽ���
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
			d=0;//����
		}
	}

	if(car4_flag==1)//4��(M4)���ݷ��ͽ���
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
			d=0;//����
		}
	}


	MVB2_SRC4X0_T2[0] = 0x0102;
	MVB2_SRC4X0_T2[1] = 0x0304;
	ttt0 = MVB2_SINK4X8_T2[0];
	ttt1 = MVB2_SINK4X8_T2[1];*/
}
