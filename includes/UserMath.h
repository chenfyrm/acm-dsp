
/**/
//#define	 TWObyTHREE	  0.66666666666667       /* 2/3 */
#define ONEbySQRT3		0.57735026918963    /* 1/sqrt(3) */
#define SQRT3byTWO   	0.86602540378444    /* sqrt(3)/2 */
#define SQRT3   		1.73205080756888    /* sqrt(3)/2 */
#define	SQRT2			1.41421356237310
#define	PI  		  	3.14159265358979
#define	PI2  		  	6.28318530717959
#define FALSE			0
#define	TRUE			1

/**/
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int                int16;
typedef long               int32;
typedef long long          int64;
typedef unsigned int       Uint16;
typedef unsigned long      Uint32;
typedef unsigned long long Uint64;
typedef float              float32;
#endif


typedef struct {
	float32	in;
	float32	out;
	float32	TsPerT1;//Tsample/T1
} TYPE_LOWPASS;

#define LOWPASS_DEFAULTS {\
	0,\
	0,\
	0.001,\
	}

#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern void LOWPASS(TYPE_LOWPASS* data);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif /* extern "C" */

extern float32	Min(float32	a,float32 b);
extern float32	Max(float32	a,float32 b);
extern float32	Limit(float32 x,float32 low,float32 up);

#ifdef __cplusplus
}
#endif


