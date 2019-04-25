#include "UserMath.h"

void LOWPASS(TYPE_LOWPASS* data)
{
	data->out = (data->out + data->in*data->TsPerT1)/(1.0 + data->TsPerT1);
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
