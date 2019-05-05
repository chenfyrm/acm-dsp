#include "acm_dsp.h"

volatile struct Dsp_Data DspData;
volatile struct Dsp_Param DspParam;


void DspStep(void)
{
	OvMd();
	SVPWM();

	DspData.XX_DutyA = Limit(DspData.XX_DutyA,0.1,0.9);
	DspData.XX_DutyB = Limit(DspData.XX_DutyB,0.1,0.9);
	DspData.XX_DutyC = Limit(DspData.XX_DutyC,0.1,0.9);

	DspData.XX_Mode = fabs(1-DspData.XX_Mode);

	DspData.XX_Theta += 100*PI*DspData.XX_Tsc;
	DspData.XX_Theta = fmod(DspData.XX_Theta,2*PI);
}

void SIPRDA(void)
{


}

void UFCODA(void)
{

}

void OvMd(void)
{
	//[0 1/sqrt(3) 0.579 0.6038 0.6057]
	//[0 1/sqrt(3) 0.58  0.6389 0.6667]

	if (DspData.XX_MRef < 0)
		DspData.XX_MOvMd  = 0;
	else if (DspData.XX_MRef  < 1.0/sqrt(3))
		DspData.XX_MOvMd = DspData.XX_MRef;
	else if (DspData.XX_MRef  < 0.579)
		DspData.XX_MOvMd = 1.0/sqrt(3) + (0.58-1.0/sqrt(3))/(0.579-1.0/sqrt(3))*(DspData.XX_MRef -1.0/sqrt(3));
	else if (DspData.XX_MRef  < 0.6038)
		DspData.XX_MOvMd = 0.58 + (0.6389-0.58)/(0.6038-0.579)*(DspData.XX_MRef -0.579);
	else if (DspData.XX_MRef  < 0.6057)
		DspData.XX_MOvMd = 0.6389 + (0.6667-0.6389)/(0.6057-0.6038)*(DspData.XX_MRef -0.6038);
	else
		DspData.XX_MOvMd = 0.6667;
}

void SVPWM(void)
{
	float32	a,b,c,min,max,NrmFa,Cml;

	a = DspData.XX_MOvMd*cos(DspData.XX_Theta);
	b = DspData.XX_MOvMd*cos(DspData.XX_Theta-2.0/3.0*PI);
	c = DspData.XX_MOvMd*cos(DspData.XX_Theta-4.0/3.0*PI);

	min = Min(a,Min(b,c));
	max = Max(a,Max(b,c));

	NrmFa = Max(1.0,max-min);
	Cml = (max + min)*(-0.5);

	DspData.XX_DutyA = (a + Cml)/NrmFa + 0.5;
	DspData.XX_DutyB = (b + Cml)/NrmFa + 0.5;
	DspData.XX_DutyC = (c + Cml)/NrmFa + 0.5;
}

float32 LowPass(float32 oldFlt,float32 Src,float32 TsPerT1)
{
	return (oldFlt + Src*TsPerT1)/(1.0 + TsPerT1);
}

cfloat32 CplxLowPass(cfloat32 oldFlt,cfloat32 Src,float32 TsPerT1)
{
	cfloat32 temp;
	temp.re = (oldFlt.re + Src.re*TsPerT1)/(1.0 + TsPerT1);
	temp.im = (oldFlt.im + Src.im*TsPerT1)/(1.0 + TsPerT1);
	return temp;
}

float32	Min(float32	a,float32 b)
{
	if(a<=b)
		return a;
	else
		return b;
}

float32	Max(float32	a,float32 b)
{
	if(a<=b)
		return b;
	else
		return a;
}

float32	Limit(float32 x,float32 low,float32 up)
{
	return Max(low,Min(x,up));
}
