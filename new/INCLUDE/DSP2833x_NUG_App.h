// ------------------------------------------------------------------------
//          Copyright (C) 2018 NUG, Incorporated.
//                          All Rights Reserved.
// ==========================================================================
//
// FILE:   DSP2833x_NUG_Infra.h
//
// TITLE:  Prototypes and Definitions for the user system
//
//###########################################################################
// $TI Release: C28x Floating Point Unit Library V1.30 $
// $Release Date: January 01, 2018 $
//###########################################################################

#ifndef DSP2833x_NUG_APP_H
#define DSP2833x_NUG_APP_H
//----------------------------------------------------
extern float32 AI[20];
extern float32 AO[8];

extern int16 FPGA_RD[20];
extern int16 FPGA_WR[20];
extern int16 DPRAM_RD[30];
extern int16 DPRAM_WR[30];
extern int16 EEPROM_RD[40];
extern int16 EEPROM_WR[40];

extern Uint16 HMI_RBUF[20],HMI_TBUF[100];

//Ratation speed related paramete
struct Ro_speed
{
	unsigned int dir;	//��ת����, dir=1Ϊ��ת��dir=0Ϊ��ת
	float omega_m;		//��еת��,rad/s
	unsigned long int pos_cur;	//��ǰ��λʱ���¼�����ʱ�������������ֵ
	unsigned long int pos_pre;	//ǰһ�ε�λʱ���¼�����ʱ�������������ֵ
	long int pos_delta;	//���ε�λʱ���¼�֮�������������
	float up_prd;		//��λλ���¼�������ʱ��,s
	float omega_m_high;	//���ٲ������õ��Ľ��
	float omega_m_low;	//���ٲ������õ��Ľ��
	float omega_m_medium;
};
struct ABC
{
	float a;
	float b;
	float c;
	float n;
};

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of DSP2833x_NUG_APP_H

//===========================================================================
// End of file.
//===========================================================================

