#include <math.h>
#include "dosgpll.h"


void DOSGPLL(TYPE_DOSGPLL_IF *data)
{
	data->Ts = 1.0/2900.0;
	data->w0 = 100*3.1415926;
	data->K = sqrt(2);
	/**/
	data->aqr.Kp = 2*100*3.1415926;
	data->aqr.Ki = 100*3.1415926*100*3.1415926*data->Ts;
	data->aqr.Umax = 100;
	data->aqr.Umin = -100;
	/**/
	data->a = data->Ts*data->w/2.0 + 2.0/data->Ts/data->w;
	data->b = data->Ts*data->w/2.0 - 2.0/data->Ts/data->w;
	/**/
	data->alpha = data->K/(data->a+data->K)\
			*(data->phase-data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
			-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
/**/
	data->park.Alpha = data->alpha;
	data->park.Beta = data->beta;
	data->park.Sine = sin(data->theta);
	data->park.Cosine = cos(data->theta);
	PARK_MACRO(data->park);
	/**/
	data->Upeak = fabs(data->park.Ds);
	if(data->Upeak < 0.001)
	data->Upeak = 0.001;
/**/
	data->aqr.Ref = data->park.Qs/data->Upeak;
	data->aqr.Fbk = 0;
	PI_MACRO(data->aqr);

	/*update*/
	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;
	/**/
	data->w = data->w0 + data->aqr.Out;
/**/
	data->theta += data->w*data->Ts;
	if(data->theta >= 2*3.1415926)
		data->theta -= 2*3.1415926;
	if(data->theta < 0)
		data->theta += 2*3.1415926;
	/**/
	data->dFlt = (1.0-data->Ts/data->T_dFlt)*data->dFlt + data->Ts/data->T_dFlt*data->park.Ds;
	data->beta = data->dFlt*sin(data->theta);
}

void DOSGPLL_1(TYPE_DOSGPLL_IF *data)
{
	data->Ts = 1.0/2900.0;
	data->w0 = 100*3.1415926;
	data->K = sqrt(2);
	/**/
	data->aqr.Kp = 2*100*3.1415926;
	data->aqr.Ki = 100*3.1415926*100*3.1415926*data->Ts;
	data->aqr.Umax = 100;
	data->aqr.Umin = -100;
	/**/
	data->a = data->Ts*data->w/2.0 + 2.0/data->Ts/data->w;
	data->b = data->Ts*data->w/2.0 - 2.0/data->Ts/data->w;
	/**/
//	data->alpha = data->K/(data->a+data->K)\
//			*(data->phase-data->oldPhase2)\
//			-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
//			-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
	data->alpha = -data->K/(data->a+data->K)*(data->a+data->b)/2.0\
				*(data->phase+2.0*data->oldPhase1+data->oldPhase2)\
				-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
				-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
/**/
	data->park.Alpha = data->alpha;
	data->park.Beta = data->beta;
	data->park.Sine = sin(data->theta);
	data->park.Cosine = cos(data->theta);
	PARK_MACRO(data->park);
	/**/
	data->Upeak = fabs(data->park.Ds);
	if(data->Upeak < 0.001)
	data->Upeak = 0.001;
/**/
	data->aqr.Ref = data->park.Qs/data->Upeak;
	data->aqr.Fbk = 0;
	PI_MACRO(data->aqr);

	/*update*/
	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;
	/**/
	data->w = data->w0 + data->aqr.Out;
/**/
	data->theta += data->w*data->Ts;
	if(data->theta >= 2*3.1415926)
		data->theta -= 2*3.1415926;
	if(data->theta < 0)
		data->theta += 2*3.1415926;
	/**/
	data->dFlt = (1.0-data->Ts/data->T_dFlt)*data->dFlt + data->Ts/data->T_dFlt*data->park.Ds;
	data->beta = data->dFlt*sin(data->theta);
}
