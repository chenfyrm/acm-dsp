//################################################################################
// FILE:    ACI3.c
// TITLE:
// DESCRIPTION:
//################################################################################



/*------------------------------------------------------------------------------
Following is the list of the Build Level choices.
------------------------------------------------------------------------------*/
#define LEVEL1  1      		//
#define LEVEL2  2           //
#define LEVEL3  3           //
#define LEVEL4  4           //转矩环
#define LEVEL5  5           //间接矢量
#define LEVEL6  6           //
#define LEVEL7  7           //
#define LEVEL8  8           //
#define LEVEL9  9           //

/*------------------------------------------------------------------------------
This line sets the BUILDLEVEL to one of the available choices.
------------------------------------------------------------------------------*/
#define   BUILDLEVEL LEVEL9

#ifndef BUILDLEVEL
#error  Critical: BUILDLEVEL must be defined !!
#endif  // BUILDLEVEL

//------------------------------------------------------------------------------
#define NP 				2				//parameter
#define RS 				(2.355/3)
#define RR 				(2.412/3)
#define LM 				(0.334/3)
#define LS 				(0.3486/3)
#define LR 				(0.3486/3)
#define PSIRMAX 		0.9
#define NBASE 			1000.0
#define NCP 			2500.0
#define TLIM 			20.0
#define ILIM 			8.0
#define BASE_CURRENT 	(11.5*1.414)
#define BASE_VOLTAGE 	(380/1.732*1.414)
#define BASE_FREQ		50

#define TSW   			0.0002        //开关周期
#define T    			(1.0*0.0002)    //运算周期
#define TI   			(1.5 *0.0002)  //延时
#define J   			(0.05*0.1)

//-----------------------------------------------------------------
#include "math.h"
#include "IQmathLib.h"
#include "ACI3.h"
#include "IndirectFluxCalc.h"
#include "FluxEstimate.h"
#include "aci_fe_const.h"
#include "aci_fe.h"
#include "aci_se_const.h"
#include "aci_se.h"

//----------------------------------------------------------
Input in = {0,0,0,0,0,0,0,0};

VoltageRebuild_F vr1 = VOLTAGEREBUILD_F_DEFAULTS;
CLARKE_F ck1 = CLARKE_F_DEFAULTS;
PARK_F pk1 = PARK_F_DEFAULTS;
PsirGen_F pg1 = PSIRGEN_F_DEFAULTS;
AFR_F afr1 = AFR_F_DEFAULTS;
ASR_F asr1 = ASR_F_DEFAULTS;
ATR_F atr1 = ATR_F_DEFAULTS;
ACR_CV_F acr1 = ACR_CV_F_DEFAULTS;
iPARK_F ipk1 = IPARK_F_DEFAULTS;
SVPWM_F svpwm1 = SVPWM_F_DEFAULTS;

IndirectFluxCalc_F fc1 = INDIRECTFLUXCALC_F_DEFAULTS;

FluxEstimate_F fe1 = FLUXESTIMATE_F_DEFAULTS;
ThetaCorrect_F tc1 = THETACORRECT_F_DEFAULTS;

ACIFE_CONST fe2_const = ACIFE_CONST_DEFAULTS;
ACIFE fe2 = ACIFE_DEFAULTS;
ThetaCorrect_F tc2 = THETACORRECT_F_DEFAULTS;
ACISE_CONST se2_const = ACISE_CONST_DEFAULTS;
ACISE se2 = ACISE_DEFAULTS;

FluxEstimate_F fe3 = FLUXESTIMATE_F_DEFAULTS;
ThetaCorrect_F tc3 = THETACORRECT_F_DEFAULTS;

FluxEstimate fe4 = FLUXESTIMATE_DEFAULTS;
ThetaCorrect_F tc4 = THETACORRECT_F_DEFAULTS;

Output out = {0,0,0};

float32 freq = 0;
float32 volt = 0;

float32 psir = 0;
float32 ws = 0;
float32 thetas = 0;

Uint16 cnt = 0;
Uint16 cnt_s = 0;

//==============================================================================
void ACI3_initialize(void)
{	
	float32 Tr = LR/RR;//0.145
	float32 sigma = 1.0 - LM*LM/LS/LR;  //0.08201
	float32 c = sigma*LS*LR/LM;

	float32 ar11 = -(RS+LM*LM/LR/LR*RR)/sigma/LS;
	float32 ar12 = LM/sigma/LS/LR/Tr;
	float32 ar21 = LM/Tr;
	float32 ar22 = -1/Tr;

	float32 wci = 0.5/(1.5*TSW)/1.5;    //1111
	float32 Tn = 1/wci;
	float32 hf = 5;
	float32 hn = 5;

	int i,j;
	float32 K=1.9;
	float32 b=-20;

	//--------------------------------------------------
	vr1.Tdead = 8e-6/TSW;

	//------------------------------------------------------
	pg1.psirmax = PSIRMAX;
	pg1.nbase = NBASE;
	pg1.ncp = NCP;

	//---------------------------------------------------
	//afr
	afr1.Kp = LR/RR/sqrt(hf)/Tn;
	afr1.Ki = LR/RR/hf/sqrt(hf)/Tn/Tn*T;
	afr1.Lm = LM;
	afr1.Umax = PSIRMAX/LM*1.2;
	afr1.Umin = PSIRMAX/LM*0.4;

	//-------------------------------------------------
	//asr
	asr1.Kp = J/sqrt(hn)/Tn;
	asr1.Ki = J/hn/sqrt(hn)/Tn/Tn*T*0.1;
	asr1.Umax = TLIM;
	asr1.Umin = -TLIM;

	//----------------------------------------------------
	atr1.K1 = 0.6666667*LR/LM/NP;//0.347
	atr1.K2 = LM/LR;
	atr1.Umax = ILIM;
	atr1.Umin = -ILIM;

	//----------------------------------------------------
	/*电流环*/
	//RS/(sigma*LS)  82.37571
	acr1.Kp = wci*sigma*LS;  //
	acr1.Ki = wci*RS;        //
	acr1.Ts = T;

	//---------------------------------
	fc1.Tr = Tr;
	fc1.Ts = T;
	fc1.Lm = LM;

	//---------------------------------------------------
	//极点放大K倍
	fe1.c = c;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			fe1.A[i][j] = 0;
		}
		for(j=0;j<2;j++)
		{
			fe1.B[i][j] = 0;
			fe1.G[i][j] = 0;
		}
	}

	fe1.A[0][0] = ar11;
	fe1.A[1][1] = fe1.A[0][0];

	fe1.A[0][2] = ar12;
	fe1.A[1][3] = fe1.A[0][2];

	fe1.A[2][0] = ar21;
	fe1.A[3][1] = fe1.A[2][0];

	fe1.A[2][2] = ar22;
	fe1.A[3][3] = fe1.A[2][2];

	fe1.B[0][0] = 1.0/sigma/LS;
	fe1.B[1][1] = fe1.B[0][0];

	fe1.K = K;
	fe1.G[0][0] = (K-1)*(ar11+ar22);
	fe1.G[1][1] = fe1.G[0][0];
	fe1.G[2][0] = (K*K-1)*(c*ar11+ar21)-c*(K-1)*(ar11+ar22);
	fe1.G[3][1] = fe1.G[2][0];

	fe1.Ts = T;

	//-----------------------------------------------------
	tc1.Kp = 1000;
	tc1.Ki = 0;
	tc1.Ts = T;
	tc1.Umax = 8;
	tc1.Umin = -8;

	//------------------------------------------------------
	//电压电流混合模型
	// Initialize the aci flux estimator constants module
	fe2_const.Rs = RS;
	fe2_const.Rr = RR;
	fe2_const.Ls = LS;
	fe2_const.Lr = LR;
	fe2_const.Lm = LM;
	fe2_const.Ib = BASE_CURRENT;
	fe2_const.Vb = BASE_VOLTAGE;
	fe2_const.Ts = T;
	ACIFE_CONST_MACRO(fe2_const);

	// Initialize the aci flux estimator module
	fe2.K1 = _IQ(fe2_const.K1);
	fe2.K2 = _IQ(fe2_const.K2);
	fe2.K3 = _IQ(fe2_const.K3);
	fe2.K4 = _IQ(fe2_const.K4);
	fe2.K5 = _IQ(fe2_const.K5);
	fe2.K6 = _IQ(fe2_const.K6);
	fe2.K7 = _IQ(fe2_const.K7);
	fe2.K8 = _IQ(fe2_const.K8);
	fe2.Kp = _IQ(2.8);
	fe2.Ki = _IQ(T/0.45);

	//-----------------------------------------------------
	tc2.Kp = 100;
	tc2.Ki = 0;
	tc2.Ts = T;
	tc2.Umax = 8;
	tc2.Umin = -8;

	// Initialize the aci speed estimator constants module
	se2_const.Rr = RR;
	se2_const.Lr = LR;
	se2_const.fb = BASE_FREQ;
	se2_const.fc = 3;
	se2_const.Ts = T;
	ACISE_CONST_MACRO(se2_const);

	// Initialize the  aci speed estimator module
	se2.K1 = _IQ(se2_const.K1);
	se2.K2 = _IQ21(se2_const.K2);
	se2.K3 = _IQ(se2_const.K3);
	se2.K4 = _IQ(se2_const.K4);
	se2.BaseRpm = 60*BASE_FREQ/NP;

	//---------------------------------------------------
	//极点平移b
	fe3.c = c;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			fe3.A[i][j] = 0;
		}
		for(j=0;j<2;j++)
		{
			fe3.G[i][j] = 0;
			fe3.B[i][j] = 0;
		}
	}

	fe3.A[0][0] = ar11;
	fe3.A[1][1] = fe3.A[0][0];

	fe3.A[0][2] = ar12;
	fe3.A[1][3] = fe3.A[0][2];

	fe3.A[2][0] = ar21;
	fe3.A[3][1] = fe3.A[2][0];

	fe3.A[2][2] = ar22;
	fe3.A[3][3] = fe3.A[2][2];

	fe3.B[0][0] = 1.0/sigma/LS;
	fe3.B[1][1] = fe3.B[0][0];

	fe3.b = b;

	fe3.K1 = c*(b*b+b*ar11);
	fe3.ar22 = ar22;
	fe3.G[0][0] = 2.0*b;
	fe3.G[1][1] = fe3.G[0][0];

	fe3.Ts = T;

	//-----------------------------------------------------
	tc3.Kp = 100;
	tc3.Ki = 0;
	tc3.Ts = T;
	tc3.Umax = 8;
	tc3.Umin = -8;

	//---------------------------------------------------
	//极点平移b
	fe4.c = c;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			fe4.A[i][j] = 0;
		}
		for(j=0;j<2;j++)
		{
			fe4.G[i][j] = 0;
			fe4.B[i][j] = 0;
		}
	}

	fe4.A[0][0] = ar11;
	fe4.A[1][1] = fe4.A[0][0];

	fe4.A[0][2] = ar12;
	fe4.A[1][3] = fe4.A[0][2];

	fe4.A[2][0] = ar21;
	fe4.A[3][1] = fe4.A[2][0];

	fe4.A[2][2] = ar22;
	fe4.A[3][3] = fe4.A[2][2];

	fe4.B[0][0] = 1.0/sigma/LS;
	fe4.B[1][1] = fe4.B[0][0];

	fe4.b = b;

	fe4.K1 = c*(b*b+b*ar11);
	fe4.ar22 = ar22;
	fe4.G[0][0] = 2.0*b;
	fe4.G[1][1] = fe4.G[0][0];

	fe4.Ts = T;

	//-----------------------------------------------------
	float32 wc = 2*3.1415926;
	tc4.Kp = 2*wc;
	tc4.Ki = wc*wc;
	tc4.Ts = T;
	tc4.Umax = 8;
	tc4.Umin = -8;

}


//===============================================================================
void ACI3_step(void)
{

#if (BUILDLEVEL==LEVEL1)

	in.wm_ref = 50;

	if(freq<in.wm_ref)
	{
		freq += T/10*in.wm_ref; //启动时间10s
		freq = (freq>in.wm_ref)?in.wm_ref:freq;
	}
	if(freq>in.wm_ref)
	{
		freq -= T/10*in.wm_ref;
		freq = (freq<in.wm_ref)?in.wm_ref:freq;
	}

	volt = 5 + freq/50*220; //抬高电压5V
	volt = (volt>220)?220:volt;

	thetas += 2*3.1415926*freq*T;
	if(thetas>2*3.1415926)
	{
		thetas -=2*3.1415926;
	}
	if(thetas<0)
	{
		thetas +=2*3.1415926;
	}


	ipk1.alpha = 1.414*volt*cos(thetas);
	ipk1.beta = 1.414*volt*sin(thetas);

	svpwm1.Ualpha = ipk1.alpha*1.732051/in.vdc;
	svpwm1.Ubeta = ipk1.beta*1.732051/in.vdc;
	SVPWM_F_MACRO(svpwm1);

	out.Taon = svpwm1.Taon;
	out.Tbon = svpwm1.Tbon;
	out.Tcon = svpwm1.Tcon;

	if(freq = in.wm_ref)
	{
		if(Buffer_cnt<1000)
		{
//			DQ_Buffer1[Buffer_cnt] = thetas;
//			DQ_Buffer2[Buffer_cnt] = svpwm1.Ualpha;
//			DQ_Buffer3[Buffer_cnt] = svpwm1.Ubeta;
			DQ_Buffer[Buffer_cnt] = svpwm1.Taon;
			Buffer_cnt ++;
			if(Buffer_cnt>999)
			{
				Buffer_cnt = 0;
			}
		}
	}

	/*
	//--------------------------------------
	thetas += 2*3.1415926*22*T;

	ipk1.alpha = 100*cos(thetas);
	ipk1.beta = 100*sin(thetas);

	//--------------------------------------
	svpwm1.Ualpha = ipk1.alpha*1.732051/in.Vdc;
	svpwm1.Ubeta = ipk1.beta*1.732051/in.Vdc;
	SVPWM_F_MACRO(svpwm1);

	//-------------------------------------------
	out.Taon = svpwm1.Taon;
	out.Tbon = svpwm1.Tbon;
	out.Tcon = svpwm1.Tcon;
	*/

#endif

#if (BUILDLEVEL==LEVEL2)

	vr1.Vdc = in.Vdc;
	vr1.Ta = (1.0 - out.Taon*2.0);
	vr1.Tb = (1.0 - out.Tbon*2.0);
	vr1.Tc = (1.0 - out.Tcon*2.0);
	VoltageRebuild_F_MACRO(vr1);

	//----------------------------------------
	/* isalpha isbeta */
	ck1.a = in.isa;
	ck1.b = in.isb;
	ck1.c = in.isc;
	CLARKE_F_MACRO(ck1);

	//----------------------------------------
	/* psir psiralpha psirbeta thetas */
	fe1.usalpha = vr1.ualpha;
	fe1.usbeta = vr1.ubeta;
	fe1.isalpha_s = ck1.alpha;
	fe1.isbeta_s = ck1.beta;
	fe1.wr = in.wm*NP;
	FluxEstimate_F_MACRO(fe1);

	out.psir = fe1.psir;
	out.thetas = fe1.thetas;

	//----------------------------------------
	/* isM isT */
	pk1.alpha = ck1.alpha;
	pk1.beta = ck1.beta;
	pk1.zero = ck1.zero;
	pk1.sin = sin(0);
	pk1.cos = cos(0);
	PARK_F_MACRO(pk1);

	out.id = pk1.d;
	out.iq = pk1.q;

	//---------------------------------------
	/* usM usT */
	acr1.isM_ref = 8;
	acr1.isT_ref = 0;
	acr1.isM = pk1.d;
	acr1.isT = pk1.q;
//	acr1.isM = 0;
//	acr1.isT = 0;
	acr1.ws = 0;
	acr1.Vdc = in.Vdc;
	acr1.uws = 0;
	acr1.Kp = in.Kp_i;
	acr1.Ki = in.Ki_i;
	ACR_CV_F_MACRO(acr1);

	out.ud = acr1.usM;
	out.uq = acr1.usT;

	//--------------------------------------
	/* usalpha usbeta */
	ipk1.d = acr1.usM;
	ipk1.q = acr1.usT;
	ipk1.z = 0.0;
	ipk1.sin = sin(0);
	ipk1.cos = cos(0);
	iPARK_F_MACRO(ipk1);

	ipk1.alpha = (ipk1.alpha>20)?20:ipk1.alpha;
	ipk1.alpha = (ipk1.alpha<-20)?-20:ipk1.alpha;
	ipk1.beta = (ipk1.beta>20)?20:ipk1.beta;
	ipk1.beta = (ipk1.beta<-20)?-20:ipk1.beta;

	out.ualpha = ipk1.alpha;
	out.ubeta = ipk1.beta;

	//--------------------------------------
	/*Taon Tbon Tcon*/
	svpwm1.Ualpha = ipk1.alpha*1.732051/in.Vdc;
	svpwm1.Ubeta = ipk1.beta*1.732051/in.Vdc;
	SVPWM_F_MACRO(svpwm1);

	//-------------------------------------------
	/**/
	out.Taon = svpwm1.Taon;
	out.Tbon = svpwm1.Tbon;
	out.Tcon = svpwm1.Tcon;


#endif

#if (BUILDLEVEL==LEVEL3)
	//-------------------------------------------
	/* isalpha isbeta */
	ck1.a = in.isa;
	ck1.b = in.isb;
	ck1.c = in.isc;
	CLARKE_F_MACRO(ck1);

	out.id = ck1.alpha;
	out.iq = ck1.beta;

	//--------------------------------------
	/*Taon Tbon Tcon*/
	svpwm1.Ualpha = 15*cos(in.thetas)*1.732051/in.Vdc;
	svpwm1.Ubeta = 15*sin(in.thetas)*1.732051/in.Vdc;
	SVPWM_F_MACRO(svpwm1);

	//-------------------------------------------
	/**/
	out.Taon = svpwm1.Taon;
	out.Tbon = svpwm1.Tbon;
	out.Tcon = svpwm1.Tcon;

#endif

#if (BUILDLEVEL==LEVEL4)
	if(cnt<(Uint16)(1.0/T))
	{
		cnt ++;
	}
	else
	{
		cnt_s ++;
		cnt = 0;
	}



	vr1.Vdc = in.Vdc;
	vr1.Ta = (1.0 - out.Taon*2.0);
	vr1.Tb = (1.0 - out.Tbon*2.0);
	vr1.Tc = (1.0 - out.Tcon*2.0);
	VoltageRebuild_F_MACRO(vr1);

	//----------------------------------------
	/* isalpha isbeta */
	ck1.a = in.isa;
	ck1.b = in.isb;
	ck1.c = in.isc;
	CLARKE_F_MACRO(ck1);

	//----------------------------------------
	/* isM isT */
	pk1.alpha = ck1.alpha;
	pk1.beta = ck1.beta;
	pk1.zero = ck1.zero;
	pk1.sin = sin(thetas);
	pk1.cos = cos(thetas);
	PARK_F_MACRO(pk1);

	//----------------------------------------
	/* psir_ref */
	pg1.n = in.wm*30/3.1415926;
	PsirGen_F_MACRO(pg1);
//	pg1.psir_ref = PSIRMAX;

	//----------------------------------------
	/* isM_ref  磁链环 */
	afr1.Ref = pg1.psir_ref;
	afr1.Fbk = psir;
//	AFR_F_MACRO(afr1);
	afr1.Out = pg1.psir_ref/LM;

	//---------------------------------------
	/* Te_ref */
	asr1.Ref = in.wm_ref;
	asr1.Fbk = in.wm;
//	ASR_F_MACRO(asr1);
	asr1.Out = in.wm_ref;

	//----------------------------------------
	/* isT_ref  */
	atr1.psir_ref = pg1.psir_ref;
	atr1.psir = psir;
	atr1.Te_ref = asr1.Out;
	if(cnt_s<60)
	{
		atr1.PreFieldFlag = 1;
		cnt_s ++;
	}
	else
	{
		atr1.PreFieldFlag = 0;
	}
	ATR_F_MACRO(atr1);

	//---------------------------------------
	/* usM usT */
	acr1.isM_ref = afr1.Out;
	acr1.isT_ref = atr1.isT_ref;
	acr1.isM = pk1.d;
	acr1.isT = pk1.q;
	acr1.ws = ws;
	acr1.Vdc = in.Vdc;
	acr1.uws = LM/LR*acr1.ws*psir;
	ACR_CV_F_MACRO(acr1);

	//--------------------------------------
	/* usalpha usbeta */
	ipk1.d = acr1.usM;
	ipk1.q = acr1.usT;
	ipk1.z = 0.0;
	ipk1.sin = sin(thetas);
	ipk1.cos = cos(thetas);
	iPARK_F_MACRO(ipk1);

	//--------------------------------------
	/*Taon Tbon Tcon*/
	svpwm1.Ualpha = ipk1.alpha*1.732051/in.Vdc;
	svpwm1.Ubeta = ipk1.beta*1.732051/in.Vdc;
	SVPWM_F_MACRO(svpwm1);

	//-----------------------------------------
	/*间接矢量，电流模型*/
//	fc1.wr = in.wm*NP;
//	fc1.wsl = acr1.isT_ref/LR*RR/acr1.isM_ref;
//	fc1.isM = pk1.d;
//	IndirectFluxCalc_F_MACRO(fc1);
/*
	vr1.ualpha = 380/1.732*1.414*cos(thetas);
	vr1.ubeta = 380/1.732*1.414*cos(thetas+3.14/2);
	ck1.alpha = 11.5*1.414*cos(thetas-3.14/6);
	ck1.beta = 11.5*1.414*cos(thetas-3.14/6+3.14/2);
	in.wm = 1465/30*3.14;
*/
	//----------------------------------------
	/* psir psiralpha psirbeta thetas */
	fe1.usalpha = vr1.ualpha;
	fe1.usbeta = vr1.ubeta;
	fe1.isalpha_s = ck1.alpha;
	fe1.isbeta_s = ck1.beta;
	fe1.wr = in.wm*NP;
	FluxEstimate_F_MACRO1(fe1);

	//-------------------------------------------
	/**/
	tc1.wr = in.wm*NP;
	tc1.wsl = atr1.wsl_ref;
	tc1.psiralpha = fe1.psiralpha;
	tc1.psirbeta = fe1.psirbeta;
	ThetaCorrect_F_MACRO(tc1);

	//----------------------------------------
	/* psir psiralpha psirbeta thetas */
//	fe3.usalpha = vr1.ualpha;
//	fe3.usbeta = vr1.ubeta;
//	fe3.isalpha_s = ck1.alpha;
//	fe3.isbeta_s = ck1.beta;
//	fe3.wr = in.wm*NP;
//	FluxEstimate_F_MACRO2(fe3);

	//-------------------------------------------
	/**/
//	tc3.wr = in.wm*NP;
//	tc3.wsl = atr1.wsl_ref;
//	tc3.psiralpha = fe3.psiralpha;
//	tc3.psirbeta = fe3.psirbeta;
//	ThetaCorrect_F_MACRO(tc3);

	//---------------------------------------------
	//电压、电流混合模型
//	fe2.UDsS = vr1.ualpha/BASE_VOLTAGE;
//	fe2.UQsS = vr1.ubeta/BASE_VOLTAGE;
//	fe2.IDsS = ck1.alpha/BASE_CURRENT;
//	fe2.IQsS = ck1.beta/BASE_CURRENT;
//	ACIFE_MACRO(fe2);

	//-------------------------------------------
	/**/
//	tc2.wr = in.wm*NP;
//	tc2.wsl = LM*acr1.isT_ref/LR*RR/(psir + 0.0001);
//	tc2.wsl = acr1.isT_ref/LR*RR/acr1.isM_ref;
//	tc2.psiralpha = fe2.PsiDrS*LM*BASE_CURRENT;
//	tc2.psirbeta = fe2.PsiQrS*LM*BASE_CURRENT;
//	ThetaCorrect_F_MACRO(tc2);

	//---------------------------------------------
	//Update
//	ws = fc1.ws;
//	thetas = fc1.thetas;
//	psir = fc1.psir;

	ws = tc1.ws;
	thetas = tc1.thetas;
	psir = fe1.psir;

//	ws = tc2.ws;
//	thetas = tc2.thetas;
//	psir = sqrt(tc2.psiralpha*tc2.psiralpha+tc2.psirbeta*tc2.psirbeta)*LM*BASE_CURRENT;

//	ws = tc3.ws;
//	thetas = tc3.thetas;
//	psir = fe3.psir;

//	thetas += 2*3.14*50*T;

	//-------------------------------------------
	/**/
	out.Taon = svpwm1.Taon;
	out.Tbon = svpwm1.Tbon;
	out.Tcon = svpwm1.Tcon;

#endif
	
#if (BUILDLEVEL==LEVEL5)
		vr1.Vdc = in.Vdc;
		vr1.Ta = (1.0 - out.Taon*2.0);
		vr1.Tb = (1.0 - out.Tbon*2.0);
		vr1.Tc = (1.0 - out.Tcon*2.0);
		VoltageRebuild_F_MACRO(vr1);

		//----------------------------------------
		/* isalpha isbeta */
		ck1.a = in.isa;
		ck1.b = in.isb;
		ck1.c = in.isc;
		CLARKE_F_MACRO(ck1);

		//----------------------------------------
		/* psir psiralpha psirbeta thetas */
/*
		thetas += 2*3.1415926*50*T;
		if(thetas>2*3.1415926)
		{
			thetas -=2*3.1415926;
		}
		if(thetas<0)
		{
			thetas +=2*3.1415926;
		}
*/
/*
		fe1.usalpha = BASE_VOLTAGE*cos(thetas);
		fe1.usbeta = BASE_VOLTAGE*sin(thetas);
		fe1.isalpha_s = BASE_CURRENT*cos(thetas-0.55);
		fe1.isbeta_s = BASE_CURRENT*sin(thetas-0.55);
		fe1.wr = 1465/60*2*3.1415926*NP;
//		if(in.wm > 100/60*2*3.1415926)
//		{
			FluxEstimate_F_MACRO1(fe1);
//		}
*/

				fe1.usalpha = vr1.ualpha;
				fe1.usbeta = vr1.ubeta;
				fe1.isalpha_s = ck1.alpha;
				fe1.isbeta_s = ck1.beta;
				fe1.wr = in.wm*NP;
		//		if(in.wm > 100/60*2*3.1415926)
		//		{
					FluxEstimate_F_MACRO1(fe1);
		//		}

		// ------------------------------------------------------------------------------
		//    Connect inputs of the ACI module and call the flux estimation macro
		// ------------------------------------------------------------------------------
/*

		fe2.UDsS = cos(thetas);
		fe2.UQsS = sin(thetas);
		fe2.IDsS = cos(thetas-0.55);
		fe2.IQsS = sin(thetas-0.55);
		*/
/*
		fe2.UDsS = vr1.ualpha/BASE_VOLTAGE;
		fe2.UQsS = vr1.ubeta/BASE_VOLTAGE;
		fe2.IDsS = ck1.alpha/BASE_CURRENT;
		fe2.IQsS = ck1.beta/BASE_CURRENT;
		*/
//		ACIFE_MACRO(fe2);

//		fe2.PsiDrS *= LM*BASE_CURRENT;
//		fe2.PsiQrS *= LM*BASE_CURRENT;

		//----------------------------------------
		/* psir_ref */
	//	pg1.n = in.wm*30/3.1415926;
	//	PsirGen_F_MACRO(pg1);
		pg1.psir_ref = PSIRMAX;

		//----------------------------------------
		/* isM_ref  磁链环 */
	//	afr1.Ref = pg1.psir_ref;
	//	afr1.Fbk = fe1.psir;
	//	AFR_F_MACRO(afr1);
		afr1.Out = pg1.psir_ref/LM;

		//---------------------------------------
		/* Te_ref */
		asr1.Ref = in.wm_ref;
		asr1.Fbk = in.wm;
		ASR_F_MACRO(asr1);

		//----------------------------------------
		/* isT_ref  预励磁*/
//	  	atr1.psir_ref = pg1.psir_ref;
//		atr1.psir = fe1.psir;
//		atr1.Te_ref = asr1.Out;
//		ATR_F_MACRO(atr1);
		atr1.isT_ref = asr1.Out/pg1.psir_ref*atr1.K2;
		atr1.isT_ref = (atr1.isT_ref>atr1.Umax)?atr1.Umax:atr1.isT_ref;
		atr1.isT_ref = (atr1.isT_ref<atr1.Umin)?atr1.Umin:atr1.isT_ref;

		//------------------------------------------
		/*psir ws thetas*/
		fc1.isM_ref = afr1.Out;
		fc1.isT_ref = atr1.isT_ref;
		fc1.wr = in.wm*NP;
		fc1.isalpha = ck1.alpha;
		fc1.isbeta = ck1.beta;
		IndirectFluxCalc_F_MACRO(fc1);

		//----------------------------------------
		/* isM isT */
		pk1.alpha = ck1.alpha;
		pk1.beta = ck1.beta;
		pk1.zero = ck1.zero;
		pk1.sin = sin(fc1.thetas);
		pk1.cos = cos(fc1.thetas);
		PARK_F_MACRO(pk1);

		//---------------------------------------
		/* usM usT */
		acr1.isM_ref = afr1.Out;
		acr1.isT_ref = atr1.isT_ref;
		acr1.isM = pk1.d;
		acr1.isT = pk1.q;
		acr1.ws = fc1.ws;
		acr1.Vdc = in.Vdc;
		acr1.uws = LM/LR*fc1.ws*fc1.psir;
		ACR_CV_F_MACRO(acr1);

		//--------------------------------------
		/* usalpha usbeta */
		ipk1.d = acr1.usM;
		ipk1.q = acr1.usT;
		ipk1.z = 0.0;
		ipk1.sin = sin(fc1.thetas);
		ipk1.cos = cos(fc1.thetas);
		iPARK_F_MACRO(ipk1);

		//--------------------------------------
		/*Taon Tbon Tcon*/
		svpwm1.Ualpha = ipk1.alpha*1.732051/in.Vdc;
		svpwm1.Ubeta = ipk1.beta*1.732051/in.Vdc;
		SVPWM_F_MACRO(svpwm1);

		//-------------------------------------------
		/**/
		out.Taon = svpwm1.Taon;
		out.Tbon = svpwm1.Tbon;
		out.Tcon = svpwm1.Tcon;


#endif
#if (BUILDLEVEL==LEVEL6)
	//----------------------------------------
	/* usalpha_rb  usbeta_rb */
	vr1.Vdc = in.Vdc;
	vr1.Ta = (1.0 - out.Taon*2.0);
	vr1.Tb = (1.0 - out.Tbon*2.0);
	vr1.Tc = (1.0 - out.Tcon*2.0);
	VoltageRebuild_F_MACRO(vr1);

	//----------------------------------------
	/* isalpha isbeta */
	ck1.a = in.isa;
	ck1.b = in.isb;
	ck1.c = in.isc;
	CLARKE_F_MACRO(ck1);

	//----------------------------------------
	/* isM isT */
	pk1.alpha = ck1.alpha;
	pk1.beta = ck1.beta;
	pk1.zero = ck1.zero;
	pk1.sin = sin(thetas);
	pk1.cos = cos(thetas);
	PARK_F_MACRO(pk1);

	//----------------------------------------
	/* psir_ref */
//	pg1.n = in.wm*30/3.1415926;
//	PsirGen_F_MACRO(pg1);
	pg1.psir_ref = PSIRMAX;

	//----------------------------------------
	/* isM_ref  磁链环 */
//	afr1.Ref = PSIRMAX;
//	afr1.Fbk = psir;
//	AFR_F_MACRO(afr1);
	afr1.Out = pg1.psir_ref/LM;

	//---------------------------------------
	/* Te_ref */
	asr1.Ref = in.wm_ref;
	asr1.Fbk = in.wm;
	ASR_F_MACRO(asr1);

	//----------------------------------------
	/* isT_ref  预励磁*/
	atr1.psir_ref = pg1.psir_ref;
	atr1.psir = psir;
	atr1.Te_ref = asr1.Out;
	ATR_F_MACRO(atr1);

	//---------------------------------------
	/* usM usT */
	acr1.isM_ref = afr1.Out;
	acr1.isT_ref = atr1.isT_ref;
	acr1.isM = pk1.d;
	acr1.isT = pk1.q;
	acr1.ws = ws;
	acr1.Vdc = in.Vdc;
	acr1.uws = LM/LR*acr1.ws*psir;
	ACR_CV_F_MACRO(acr1);

	//--------------------------------------
	/* usalpha usbeta */
	ipk1.d = acr1.usM;
	ipk1.q = acr1.usT;
	ipk1.z = 0.0;
	ipk1.sin = sin(thetas);
	ipk1.cos = cos(thetas);
	iPARK_F_MACRO(ipk1);

	//-----------------------------------------
	/**/
	fc1.wr = in.wm*NP;
	fc1.wsl = atr1.isT_ref/LR*RR/afr1.Out;
	fc1.isM = pk1.d;
	IndirectFluxCalc_F_MACRO(fc1);

//	fe1.psir = fc1.psir*(1-in.wm/150) + fe1.psir*in.wm/150;


	//----------------------------------------
	/* psir psiralpha psirbeta thetas */
//	fe1.usalpha = vr1.ualpha;
//	fe1.usbeta = vr1.ubeta;
//	fe1.isalpha_s = ck1.alpha;
//	fe1.isbeta_s = ck1.beta;
//	fe1.wr = in.wm*NP;
//	FluxEstimate_F_MACRO1(fe1);

	//-------------------------------------------
	/**/
//	tc1.wr = in.wm*NP;
//	tc1.wsl = LM*atr1.isT_ref/LR*RR/afr1.Ref;
//	tc1.psiralpha = fe1.psiralpha;
//	tc1.psirbeta = fe1.psirbeta;
//	ThetaCorrect_F_MACRO(tc1);

	//---------------------------------------------
	//电压、电流混合模型
//	fe2.UDsS = vr1.ualpha/BASE_VOLTAGE;
//	fe2.UQsS = vr1.ubeta/BASE_VOLTAGE;
//	fe2.IDsS = ck1.alpha/BASE_CURRENT;
//	fe2.IQsS = ck1.beta/BASE_CURRENT;
//	ACIFE_MACRO(fe2);

	//-------------------------------------------
	/**/
//	tc2.wr = in.wm*NP;
//	tc2.wsl = LM*acr1.isT_ref/LR*RR/afr1.Ref;
//	tc2.psiralpha = fe2.PsiDrS*LM*BASE_CURRENT;
//	tc2.psirbeta = fe2.PsiQrS*LM*BASE_CURRENT;
//	ThetaCorrect_F_MACRO(tc2);

	//-------------------------------------------
		ws = fc1.ws;
		thetas = fc1.thetas;
		psir = fc1.psir;

//	ws = tc1.ws;
//	thetas = tc1.thetas;
//	psir = fe1.psir;

//	ws = tc2.ws;
//	thetas = tc2.thetas;
//	psir = fe2.psir;


	//--------------------------------------
	/*Taon Tbon Tcon*/
	svpwm1.Ualpha = ipk1.alpha*1.732051/in.Vdc;
	svpwm1.Ubeta = ipk1.beta*1.732051/in.Vdc;
	SVPWM_F_MACRO(svpwm1);

	//-------------------------------------------
	out.Taon = svpwm1.Taon;
	out.Tbon = svpwm1.Tbon;
	out.Tcon = svpwm1.Tcon;

#endif

#if(BUILDLEVEL==LEVEL7)
	if(cnt<5000)
	{
		cnt++;
	}
	else
	{
		cnt = 0;
		cnt_s++;
	}

	//----------------------------------------
	/* usalpha_rb  usbeta_rb */
	vr1.Vdc = in.Vdc;
	vr1.Ta = (1.0 - out.Taon*2.0);
	vr1.Tb = (1.0 - out.Tbon*2.0);
	vr1.Tc = (1.0 - out.Tcon*2.0);
	VoltageRebuild_F_MACRO(vr1);

	//----------------------------------------
		/* isalpha isbeta */
		ck1.a = in.isa;
		ck1.b = in.isb;
		ck1.c = in.isc;
		CLARKE_F_MACRO(ck1);

		//----------------------------------------
		/* isM isT */
		pk1.alpha = ck1.alpha;
		pk1.beta = ck1.beta;
		pk1.zero = ck1.zero;
		pk1.sin = sin(thetas);
		pk1.cos = cos(thetas);
		PARK_F_MACRO(pk1);

		//----------------------------------------
		/* psir_ref */
		pg1.n = in.wm*30/3.1415926;
	//	PsirGen_F_MACRO(pg1);
		pg1.psir_ref = 0.9;

		//----------------------------------------
		/* isM_ref  磁链环 */
		afr1.Ref = pg1.psir_ref;
		afr1.Fbk = psir;
	//	AFR_F_MACRO(afr1);
		afr1.Out = pg1.psir_ref/LM;

		//---------------------------------------
		/* Te_ref */
		asr1.Ref = in.wm_ref;
		asr1.Fbk = in.wm;
		ASR_F_MACRO(asr1);
//		asr1.Out = 0;

		//----------------------------------------
		/* isT_ref  预励磁*/
		atr1.psir_ref = pg1.psir_ref;
		atr1.psir = psir;
		atr1.Te_ref = asr1.Out;
		ATR_F_MACRO(atr1);

		//---------------------------------------
		/* usM usT */
		acr1.isM_ref = afr1.Out;
		acr1.isT_ref = atr1.isT_ref;
		acr1.isM = pk1.d;
		acr1.isT = pk1.q;
		acr1.ws = ws;
		acr1.Vdc = in.Vdc;
		acr1.uws = LM/LR*acr1.ws*psir;
		ACR_CV_F_MACRO(acr1);

		//--------------------------------------
		/* usalpha usbeta */
		ipk1.d = acr1.usM;
		ipk1.q = acr1.usT;
		ipk1.z = 0.0;
		ipk1.sin = sin(thetas);
		ipk1.cos = cos(thetas);
		iPARK_F_MACRO(ipk1);

		//-----------------------------------------
		/**/
		fc1.wr = in.wm*NP;
		fc1.wsl = LM*atr1.isT_ref/LR*RR/(psir+0.0001);
		fc1.wsl = (fc1.wsl>8)?8:fc1.wsl;
		fc1.wsl = (fc1.wsl<-8)?-8:fc1.wsl;
		fc1.isM = pk1.d;
		IndirectFluxCalc_F_MACRO(fc1);

		//----------------------------------------
		/* psir psiralpha psirbeta thetas */
		fe2.UDsS = vr1.ualpha/BASE_VOLTAGE;
		fe2.UQsS = vr1.ubeta/BASE_VOLTAGE;
		fe2.IDsS = ck1.alpha/BASE_CURRENT;
		fe2.IQsS = ck1.beta/BASE_CURRENT;
		ACIFE_MACRO(fe2);

		//-------------------------------------------
		/**/
		/*
		tc1.wr = in.wm*NP;
		tc1.wsl = LM*atr1.isT_ref/LR*RR/(psir+0.0001);
		tc1.psiralpha = fe2.PsiDrS*LM*BASE_CURRENT;
		tc1.psirbeta = fe2.PsiQrS*LM*BASE_CURRENT;
		ThetaCorrect_F_MACRO(tc1);
		*/

		//-------------------------------------------
		/**/
		/*
		se1.IDsS = ck1.alpha/BASE_CURRENT;
		se1.IQsS = ck1.beta/BASE_CURRENT;
		se1.PsiDrS = fe2.PsiDrS;
		se1.PsiQrS = fe2.PsiQrS;
		se1.ThetaFlux = fe2.ThetaFlux/2/3.1415926;
		ACISE_MACRO(se1);
		*/

		//-------------------------------------------
		/*
		if(in.wm<1000/30*3.1415926)
		{
			psir = fc1.psir;
			thetas = fc1.thetas;
			ws = fc1.ws;
		}
		else
		{
			psir = fe1.psir;
			thetas = tc1.thetas;
			ws = tc1.ws;
		}
		*/
//		psir = sqrt(fe2.PsiDrS*fe2.PsiDrS+fe2.PsiQrS*fe2.PsiQrS)*LM*BASE_CURRENT;
//		thetas = tc1.thetas;
//		thetas = fe2.ThetaFlux*2*3.1415926;
//		ws = tc1.ws;
//		ws = se1.WSyn*2*3.1415926*BASE_FREQ;

		if(cnt_s < 300)
		{
			psir = fc1.psir;
			ws = fc1.ws;
			thetas = fc1.thetas;
		}
		else
		{
			psir = sqrt(fe2.PsiDrS*fe2.PsiDrS+fe2.PsiQrS*fe2.PsiQrS)*LM*BASE_CURRENT;
			ws = fc1.ws;
			thetas = fe2.ThetaFlux*2*3.1415926 + ws*T;
			thetas = (thetas>2*3.1415926)?(thetas-2*3.1415926):thetas;
			thetas = (thetas<0)?(thetas+2*3.1415926):thetas;
		}

		//--------------------------------------
		/*Taon Tbon Tcon*/
		svpwm1.Ualpha = ipk1.alpha*1.732051/in.Vdc;
		svpwm1.Ubeta = ipk1.beta*1.732051/in.Vdc;
		SVPWM_F_MACRO(svpwm1);

		//-------------------------------------------
		out.Taon = svpwm1.Taon;
		out.Tbon = svpwm1.Tbon;
		out.Tcon = svpwm1.Tcon;

#endif

#if (BUILDLEVEL==LEVEL8)
		if(cnt<(Uint16)(1.0/T))
		{
			cnt ++;
		}
		else
		{
			cnt_s ++;
			cnt = 0;
		}

		//----------------------------------------------
		vr1.Vdc = in.Vdc;
		vr1.Ta = (1.0 - out.Taon*2.0 - vr1.Tdead);
		vr1.Tb = (1.0 - out.Tbon*2.0 - vr1.Tdead);
		vr1.Tc = (1.0 - out.Tcon*2.0 - vr1.Tdead);
		VoltageRebuild_F_MACRO(vr1);

		//----------------------------------------
		/* isalpha isbeta */
		ck1.a = in.isa;
		ck1.b = in.isb;
		ck1.c = in.isc;
		CLARKE_F_MACRO(ck1);

		//----------------------------------------
		/* isM isT */
		pk1.alpha = ck1.alpha;
		pk1.beta = ck1.beta;
		pk1.zero = ck1.zero;
		pk1.sin = sin(thetas);
		pk1.cos = cos(thetas);
		PARK_F_MACRO(pk1);

		//----------------------------------------
		/* psir_ref */
		pg1.n = in.wm*30/3.1415926;
		PsirGen_F_MACRO(pg1);
	//	pg1.psir_ref = PSIRMAX;

		//----------------------------------------
		/* isM_ref  磁链环 */
		afr1.Ref = pg1.psir_ref;
		afr1.Fbk = psir;
		AFR_F_MACRO(afr1);
	//	afr1.Out = pg1.psir_ref/LM;

		//---------------------------------------
		/* Te_ref */
		asr1.Ref = in.wm_ref;
		asr1.Fbk = in.wm;
		ASR_F_MACRO(asr1);
	//	asr1.Out = in.wm_ref;

		//----------------------------------------
		/* isT_ref  */
		atr1.psir_ref = pg1.psir_ref;
		atr1.psir = psir;
		atr1.Te_ref = asr1.Out;
		if(cnt_s<60)
		{
			atr1.PreFieldFlag = 1;
			cnt_s ++;
		}
		else
		{
			atr1.PreFieldFlag = 0;
		}
		ATR_F_MACRO(atr1);

		//---------------------------------------
		/* usM usT */
		acr1.isM_ref = afr1.Out;
		acr1.isT_ref = atr1.isT_ref;
		acr1.isM = pk1.d;
		acr1.isT = pk1.q;
		acr1.ws = ws;
		acr1.Vdc = in.Vdc;
		acr1.uws = LM/LR*acr1.ws*psir;
		ACR_CV_F_MACRO(acr1);

		//--------------------------------------
		/* usalpha usbeta */
		ipk1.d = acr1.usM;
		ipk1.q = acr1.usT;
		ipk1.z = 0.0;
		ipk1.sin = sin(thetas);
		ipk1.cos = cos(thetas);
		iPARK_F_MACRO(ipk1);

		//--------------------------------------
		/*Taon Tbon Tcon*/
		svpwm1.Ualpha = ipk1.alpha*1.732051/in.Vdc;
		svpwm1.Ubeta = ipk1.beta*1.732051/in.Vdc;
		SVPWM_F_MACRO(svpwm1);

		//----------------------------------------
		/* psir psiralpha psirbeta thetas */
		fe1.usalpha = vr1.ualpha;
		fe1.usbeta = vr1.ubeta;
		fe1.isalpha_s = ck1.alpha;
		fe1.isbeta_s = ck1.beta;
		fe1.wr = in.wm*NP;
		FluxEstimate_F_MACRO1(fe1);

		//-------------------------------------------
		/**/
		tc1.wr = in.wm*NP;
		tc1.wsl = atr1.wsl_ref;
		tc1.psiralpha = fe1.psiralpha;
		tc1.psirbeta = fe1.psirbeta;
		ThetaCorrect_F_MACRO(tc1);

		//---------------------------------------------
		//Update
		psir = fe1.psir;
		ws = tc1.ws;
		thetas = tc1.thetas;

		//-------------------------------------------
		/**/
		out.Taon = svpwm1.Taon;
		out.Tbon = svpwm1.Tbon;
		out.Tcon = svpwm1.Tcon;
#endif

#if (BUILDLEVEL==LEVEL9)
		if(cnt<(Uint16)(1.0/T))
		{
			cnt ++;
		}
		else
		{
			cnt_s ++;
			cnt = 0;
		}

		//----------------------------------------------
		vr1.Vdc = in.Vdc;
		vr1.Ta = (1.0 - out.Taon*2.0 - vr1.Tdead);
		vr1.Tb = (1.0 - out.Tbon*2.0 - vr1.Tdead);
		vr1.Tc = (1.0 - out.Tcon*2.0 - vr1.Tdead);
		VoltageRebuild_F_MACRO(vr1);

		//----------------------------------------
		/* isalpha isbeta */
		ck1.a = in.isa;
		ck1.b = in.isb;
		ck1.c = in.isc;
		CLARKE_F_MACRO(ck1);

		//----------------------------------------
		/* isM isT */
		pk1.alpha = ck1.alpha;
		pk1.beta = ck1.beta;
		pk1.zero = ck1.zero;
		pk1.sin = sin(thetas);
		pk1.cos = cos(thetas);
		PARK_F_MACRO(pk1);

		//----------------------------------------
		/* psir_ref */
		pg1.n = in.wm*30/3.1415926;
		PsirGen_F_MACRO(pg1);
	//	pg1.psir_ref = PSIRMAX;

		//----------------------------------------
		/* isM_ref  磁链环 */
		afr1.Ref = pg1.psir_ref;
		afr1.Fbk = psir;
	//	AFR_F_MACRO(afr1);
		afr1.Out = pg1.psir_ref/LM;

		//---------------------------------------
		/* Te_ref */
		asr1.Ref = in.wm_ref;
		asr1.Fbk = in.wm;
		ASR_F_MACRO(asr1);
	//	asr1.Out = in.wm_ref;

		//----------------------------------------
		/* isT_ref  */
		atr1.psir_ref = pg1.psir_ref;
		atr1.psir = psir;
		atr1.Te_ref = asr1.Out;
		if(cnt_s<1)
		{
			atr1.PreFieldFlag = 1;
		}
		else
		{
			atr1.PreFieldFlag = 0;
		}
		ATR_F_MACRO(atr1);

		//---------------------------------------
		/* usM usT */
		acr1.isM_ref = afr1.Out;
		acr1.isT_ref = atr1.isT_ref;
		acr1.isM = pk1.d;
		acr1.isT = pk1.q;
		acr1.ws = ws;
		acr1.Vdc = in.Vdc;
		acr1.uws = LM/LR*acr1.ws*psir;
		ACR_CV_F_MACRO(acr1);

		//--------------------------------------
		/* usalpha usbeta */
		ipk1.d = acr1.usM;
		ipk1.q = acr1.usT;
		ipk1.z = 0.0;
		ipk1.sin = sin(thetas);
		ipk1.cos = cos(thetas);
		iPARK_F_MACRO(ipk1);

		//--------------------------------------
		/*Taon Tbon Tcon*/
		svpwm1.Ualpha = ipk1.alpha*1.732051/in.Vdc;
		svpwm1.Ubeta = ipk1.beta*1.732051/in.Vdc;
		SVPWM_F_MACRO(svpwm1);

		//----------------------------------------
		/* psir psiralpha psirbeta thetas */
		fe4.usalpha = vr1.ualpha;
		fe4.usbeta = vr1.ubeta;
		fe4.isalpha_s = ck1.alpha;
		fe4.isbeta_s = ck1.beta;
		fe4.wr = in.wm*NP;

		fe4.G[2][0] = -fe4.b*fe4.c;
		fe4.G[3][1] = fe4.G[2][0];
		fe4.G[3][0] = -fe4.K1*fe4.wr/(fe4.ar22*fe4.ar22+fe4.wr*fe4.wr);
		fe4.G[2][1] = -fe4.G[3][0];
		if(tc4.ws<2*3.1415926*2)
		{
			fe4.G[3][0] = -fe4.K1*fe4.wr/(fe4.ar22*fe4.ar22+fe4.wr*fe4.wr)/2.0;
			fe4.G[2][1] = -fe4.G[3][0];
		}

		if(atr1.PreFieldFlag==0)
		{
			fe4.k_co = 3.0;
		}
		else
		{
			if(tc4.ws<2*3.1415926*10)
			{
				fe4.k_co = 2.0;
			}
			else
			{
				fe4.k_co = 2.0 - (tc4.ws-2*3.1415926*10)*0.15;
				if(fe4.k_co<0.001)
				{
					fe4.k_co = 0.0;
				}
			}
		}

		fe4.ErrIsalpha = (ck1.alpha-fe4.isalpha)/2.0;
		fe4.ErrIsbeta = (ck1.beta-fe4.isbeta)/2.0;

		if(fe4.ErrIsalpha>1.0)
		{
			fe4.ErrIsalpha=1.0;
		}
		if(fe4.ErrIsalpha<-1.0)
		{
			fe4.ErrIsalpha=-1.0;
		}

		if(fe4.ErrIsbeta>1.0)
		{
			fe4.ErrIsbeta=1.0;
		}
		if(fe4.ErrIsbeta<-1.0)
		{
			fe4.ErrIsbeta=-1.0;
		}

		fe4.usalpha += fe4.k_co*fe4.ErrIsalpha*10;
		fe4.usbeta += fe4.k_co*fe4.ErrIsbeta*10;

		FluxEstimate_MACRO(fe4);

		//-------------------------------------------
		/**/
		tc4.wr = in.wm*NP;
		tc4.wsl = atr1.wsl_ref;
		tc4.psiralpha = fe4.psiralpha;
		tc4.psirbeta = fe4.psirbeta;
		tc4.psir = fe4.psir;
		ThetaCorrect_F_MACRO(tc4);

		//---------------------------------------------
		//Update
		float32 k_co1 = 1.0;
		if(tc4.ws<2*3.1415926*20)
		{
			k_co1 = 1.0;
		}
		else
		{
			k_co1 = 1.0 - (tc4.ws-2*3.1415926*20)*0.159;
			if(k_co1 < 0.001)
			{
				k_co1 = 0;
			}
		}

//		psir = k_co1*LM*pk1.d+(1.0-k_co1)*fe4.psir;


		float32 psir_tmp = k_co1*LM*pk1.d+(1.0-k_co1)*fe4.psir;
		psir = psir + (psir_tmp - psir)*2*3.1415926*20*T;
		if(psir>0.9*1.2)
		{
			psir = 0.9*1.2;
		}
		if(psir<0.2)
		{
			psir = 0.2;
		}

		ws = tc4.ws;
		thetas = tc4.thetas;

		//-------------------------------------------
		/**/
		out.Taon = svpwm1.Taon;
		out.Tbon = svpwm1.Tbon;
		out.Tcon = svpwm1.Tcon;

#endif
}

//==============================================================================
void ACI3_terminate(void)
{
	cnt = 0;
	cnt_s = 0;

	afr1.i1 = 0;

	asr1.i1 = 0;

	atr1.PreFieldFlag = 1;

	acr1.i1M = 0;
	acr1.i1T = 0;

	fc1.oldPsir = 0;
	fc1.oldThetas = 0;

	int i;
	for(i=0;i<4;i++)
	{
		fe1.X[i] = 0;
		fe1.X_p[i] = 0;
		fe1.pX_p[i] = 0;
		fe1.pX_c[i] = 0;
		i++;
	}

	tc1.oldThetas = 0;
	tc1.ui = 0;

	fe2.ThetaFlux = 0;

	tc2.oldThetas = 0;
	tc2.ui = 0;

	for(i=0;i<4;i++)
	{
		fe3.X[i] = 0;
		fe3.X_p[i] = 0;
		fe3.pX_p[i] = 0;
		fe3.pX_c[i] = 0;
		i++;
	}

	tc3.oldThetas = 0;
	tc3.ui = 0;

	for(i=0;i<4;i++)
	{
		fe4.X[i] = 0;
		fe4.pX[i] = 0;
		fe4.X_p_1[i] = 0;
		fe4.X_p_2[i] = 0;
		fe4.X_p_3[i] = 0;
	}

	tc4.oldThetas = 0;
	tc4.ui = 0;

	psir = 0;
	ws = 0;
	thetas = 0;

	out.Taon = 0;
	out.Tbon = 0;
	out.Tcon = 0;
}















