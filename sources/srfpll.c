#include <math.h>
#include "srfpll.h"

void SRFPLL(TYPE_SRFPLL_IF *data)
{
	data->aqr.Kp = 2*100*3.1415926;
	data->aqr.Ki = 100*3.1415926*100*3.1415926*data->Ts;
	data->aqr.Umax = 100;
	data->aqr.Umin = -100;
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
	/**/
	data->w = data->w0 + data->aqr.Out;
/**/
	data->theta += data->w*data->Ts;
	if(data->theta >= 2*3.1415926)
		data->theta -= 2*3.1415926;
	if(data->theta < 0)
		data->theta += 2*3.1415926;
}
