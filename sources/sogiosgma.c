#include <math.h>
#include "sogiosgma.h"


void SOGIOSGMA(TYPE_SOGIOSGMA_IF *data)
{
	data->Ts = 1.0/2900.0;
	data->w = 100*3.1415926;
	data->K = sqrt(2);

	/**/
	data->a = data->Ts*data->w/2.0 + 2.0/data->Ts/data->w;
	data->b = data->Ts*data->w/2.0 - 2.0/data->Ts/data->w;

	data->alpha = data->K/(data->a+data->K)\
			*(data->phase-data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
			-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
	data->beta = data->K/(data->a+data->K)*(data->a+data->b)/2.0\
			*(data->phase+2.0*data->oldPhase1+data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldBeta1\
			-(data->a-data->K)/(data->a+data->K)*data->oldBeta2;

	/*update*/
	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;
	data->oldBeta2 = data->oldBeta1;
	data->oldBeta1 = data->beta;

}

void SOGIOSGFLL(TYPE_SOGIOSGMA_IF *data)
{
	data->Ts = 1.0/2900.0;
	data->w0 = 100*3.1415926;
	data->K = sqrt(2);
	data->Ki = 10000;

	/**/
	data->a = data->Ts*data->w/2.0 + 2.0/data->Ts/data->w;
	data->b = data->Ts*data->w/2.0 - 2.0/data->Ts/data->w;

	data->alpha = data->K/(data->a+data->K)\
			*(data->phase-data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldAlpha1\
			-(data->a-data->K)/(data->a+data->K)*data->oldAlpha2;
	data->beta = data->K/(data->a+data->K)*(data->a+data->b)/2.0\
			*(data->phase+2.0*data->oldPhase1+data->oldPhase2)\
			-2.0*data->b/(data->a+data->K)*data->oldBeta1\
			-(data->a-data->K)/(data->a+data->K)*data->oldBeta2;

	data->ErrF = (data->phase-data->alpha)*data->beta;
	data->ComW +=data->ErrF*(-1.0)*data->Ki*data->Ts;

	/*update*/
	data->w = data->w0 + data->ComW;

	data->oldPhase2 = data->oldPhase1;
	data->oldPhase1 = data->phase;
	data->oldAlpha2 = data->oldAlpha1;
	data->oldAlpha1 = data->alpha;
	data->oldBeta2 = data->oldBeta1;
	data->oldBeta1 = data->beta;

}
