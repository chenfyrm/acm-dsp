/*****************************************************************************
* COPYRIGHT : (c) 2017 Bombardier Transportation BTPC
*****************************************************************************
**
MODULE : PAR.h
**
ABSTRACT : Interface definition for resource 'PAR'
**
CREATOR : PMAKE 4.0.0.5
**
REMARKS : ANY CHANGES TO THIS FILE WILL BE LOST !!!
*
****************************************************************************/
#ifndef PAR_H
#define PAR_H
//#ifndef TARGET_SIM_DLL
#include "typedef.h"
//#include "usertypes.h"
//#endif
typedef struct dataBlock_PAR
{
/* Group: Default */
MWT_INT SYSCMG_WX_ParSetRq; /* input Parameter set requested by system change */
MWT_BOOL PCTHMZ_A_PctMo; /* input PCT active */
MWT_INT PCTHMZ_WX_PaSetUpPct; /* input PCT mode */
MWT_UINT PARTAP_NX_ParVer; /* output DCU/A parameter version */
MWT_BOOL PARTGP_B_EnTxt; /* output Enable termtext output */
MWT_BOOL PARTGP_L_MmIPh3; /* output If TRUE: Phase 3 is measured If FALSE: Phase 2 is measured */
MWT_BOOL PARTGP_L_EnPctPrAct; /* output Enable line trip test, digital output test and test of pull-wires during active
protective action */
MWT_BOOL PARTGP_L_LtrSvEn; /* output Line trip supervision enabled */
MWT_TIME PARTGP_PT_DiInFiBase; /* output Filter time constant for digital inputs Base I/O */
MWT_TIME PARTGP_PT_DiInFiMpp; /* output Filter time constant for digital inputs LPP/MPP */
MWT_TIME PARTGP_PT_DiInFi43; /* output Filter time constant for digital input 43 */
MWT_TIME PARTGP_PT_TrSafFl; /* output Filter time for traction safe fault */
MWT_TIME PARTGP_PT_FiSpeSnSpFl; /* output Filter time for speed sensor supply faults. Only valid for DCU2/M */
MWT_UINT PARTGP_P_NoHwFl_Max; /* output Max number of hardware faults */
MWT_TIME PARTGP_PT_WiFl; /* output Time window for counting faults */
MWT_BOOL PARTGP_L_TrpLvTsEn; /* output Enable Trip level test */
MWT_BOOL PARTGP_L_EnAi05; /* output Input AI05 is used. */
MWT_REAL PARTGP_PH_Ai05Mn; /* output Min temperature analog in 05 */
MWT_REAL PARTGP_PH_Ai05Mx; /* output Max temperature analog in 05 */
MWT_BOOL PARTGP_L_EnAi06; /* output Input AI06 is used. */
MWT_REAL PARTGP_PH_Ai06Mn; /* output Min temperature analog in 06 */
MWT_REAL PARTGP_PH_Ai06Mx; /* output Max temperature analog in 06 */
MWT_REAL PARTGP_PH_Ai07Mn; /* output Min temperature analog in 07 */
MWT_REAL PARTGP_PH_Ai07Mx; /* output Max temperature analog in 07 */
MWT_REAL PARTGP_PH_Ai08Mn; /* output Min temperature analog in 08 */
MWT_REAL PARTGP_PH_Ai08Mx; /* output Max temperature analog in 08 */
MWT_BOOL PARTGP_L_EnAi21; /* output Input AI21 is used. */
MWT_REAL PARTGP_PH_Ai21Mn; /* output Min temperature analog in 21 */
MWT_REAL PARTGP_PH_Ai21Mx; /* output Max temperature analog in 21 */
MWT_BOOL PARTGP_L_EnAi22; /* output Input AI22 is used. */
MWT_REAL PARTGP_PH_Ai22Mn; /* output Min temperature analog in 22 */
MWT_REAL PARTGP_PH_Ai22Mx; /* output Max temperature analog in 22 */
MWT_BOOL PARTGP_L_EnAi49; /* output Input AI49 is used. */
MWT_REAL PARTGP_PX_Ai49; /* output AI49 pressure at 20 mA to the DCU2-board */
MWT_REAL PARTGP_PH_TCoolCm; /* output Cable compensation for Coolant/heatsink-temperature (remark: 40mOhm gives 1K)" */
MWT_TIME PARTGP_PT_NteSv; /* output Delay time for supervision of internal voltage */
MWT_UINT PARTGP_PT_DspWdg; /* output Timeout for DSP wathchdog supervision in FPGA1 (in us) */
MWT_BOOL PARTGP_L_EnDcu2ConfHPP; /* output Enable Opto8 as Pair of Arms (and not brake chopper) */
MWT_BOOL PARTGP_L_NteVSvEn; /* output Enable supervision of internal voltages */
MWT_BOOL PARTGP_B_EnParChgDet; /* output Enable parameter transfer to DSP without trigger command */
MWT_BOOL PARTGP_L_EnADComp; /* output Enable AD comparision supervision */
MWT_BOOL PARTGP_L_CnfHpp; /* output HPP Configuration */
MWT_BOOL PARTGP_L_CnfMpp; /* output MPP Configuration */
MWT_BOOL PARTGP_L_CnfLpp; /* output LPP Configuration */
MWT_BOOL PARTGP_L_CnfDcuA; /* output DCU/A Configuration */
MWT_BOOL PARTGP_L_CnfDcuM; /* output DCU/M Configuration */
MWT_BOOL PARTGP_L_CnfDcuL; /* output DCU/L Configuration */
MWT_BOOL PARTGP_B_EnCanComHPP; /* output Enable HPP CAN communication (via HPP expansion board) */
MWT_BOOL PARTGP_B_CntMtd; /* output Count method for MCU2/G faults (False=count nr. of reset from driver/application,
True=count nr. of failures) */
MWT_UDINT PARTGP_XX_TskTmThrT4; /* output Warning level/threshold for task executiuon time (us) */
MWT_UDINT PARTGP_XX_TskTmThrT16; /* output Warning level/threshold for task executiuon time (us) */
MWT_UDINT PARTGP_XX_TskTmThrT64; /* output Warning level/threshold for task executiuon time (us) */
MWT_UDINT PARTGP_XX_TskTmThrT1024; /* output Warning level/threshold for task executiuon time (us) */
MWT_INT PARTGP_WI_DTDX751A; /* output Current reference, DTDX751A, (Opto LPP/MPP) */
MWT_INT PARTGP_WI_DTDX753B; /* output Current reference, DTDX753B, (Opto LPP/MPP) */
MWT_INT PARTGP_WI_DTDX751C; /* output Current reference, DTDX751C */
MWT_INT PARTGP_WI_DTDX752A; /* output Current reference, DTDX752A, (Opto HPP plastic) */
MWT_INT PARTGP_WI_DTDX752B; /* output Current reference, DTDX752B and DTDX752A channel 10, (Opto HPP, glass) */
MWT_BOOL PARTGP_B_EnOptoOutCal; /* output Enable calibration of optical output current */
MWT_UINT PARTGP_P_NoDspFl_Max; /* output Max number of DSP failures before isolation request is set, 0 will leave DSP in failure
mode without reset */
MWT_TIME PARTGP_PT_WiDspFl; /* output Time window for counting Dsp failures */
MWT_BOOL PARTGP_B_EnCnNtHwFl; /* output Enable HW re-init and counter for HwFl during Nt */
MWT_UINT PARTGP_P_NoLtrOpFl_Max; /* output Max number of line trip opening failures before isolation */
MWT_BOOL PARTGP_B_EnTxtSel; /* output Enable selected termtexts */
MWT_UINT PARTGP_P_NoOptEnFl_Max; /* output Max number of opto enable failures before isolation */
MWT_BOOL PARTGP_B_DTDX; /* output Optoboard mounted? */
MWT_BOOL PARTGP_B_DTEX; /* output Expansionboard mounted? */
MWT_INT PARTGP_PX_DspRamTsLv; /* output DSP ram test level
0 = No test, returns OK
1 = Data bus and address bus test
2 = Data bus, address bus and device test */
MWT_BOOL PARTGP_B_TrmTxtAelogEn; /* output termtext+AE_ERROR? */
MWT_REAL PARTDP_PX_IPhSnRt; /* output Phase current measurement ratio (Ratio of Phase current measurement device) */
MWT_BOOL PARTDP_L_IPh1MmNg; /* output Phase current 1 measurement inverted (FALSE=Positive direction into 3-phase,
TRUE=Positive direction into DC-link) */
MWT_BOOL PARTDP_L_IPh2MmNg; /* output Phase current 2 measurement inverted (FALSE=Positive direction into 3-phase,
TRUE=Positive direction into DC-link) */
MWT_BOOL PARTDP_L_UDcLkSnU; /* output DC-link voltage sensor output (FALSE=Current (V/A), TRUE=Voltage (V/V)) */
MWT_REAL PARTDP_PX_UDcLkSnRt; /* output DC-link voltage measurement ratio (Ratio of DC-link voltage measurement device) */
MWT_REAL PARTDP_PX_UDcLk2SnRt; /* output DC-link voltage 2 measurement ratio (Ratio of DC-link voltage measurement device) */
MWT_BOOL PARTDP_L_U3PhSnU; /* output 3-phase output load voltage sensor output (FALSE=Current (V/A), TRUE=Voltage (V/V)) */
MWT_REAL PARTDP_PX_IDcLnErfSnRt; /* output DC-link earth fault current measurement ratio (Ratio of earth fault current measurement
device) */
MWT_REAL PARTDP_PX_IBtCgSnRt; /* output Battery charger current measurement ratio (Ratio of battery charger current measurement
device) */
MWT_REAL PARTDP_PX_IBtSnRt; /* output Battery current measurement ratio (Ratio of battery current measurement device) */
MWT_REAL PARTDP_PX_UPhInSnRt; /* output AC input phase voltage measurement ratio (Ratio of AC input phase voltage measurement
device) */
MWT_BOOL PARTDP_L_UPhInMmNg; /* output AC input phase voltage measurement inverted (FALSE=Positive direction into DC-link,
TRUE=Positive direction into AC-line) */
MWT_REAL PARTDP_PX_IPhInSnRt; /* output AC input phase current measurement ratio (Ratio of AC input phase current measurement
device) */
MWT_BOOL PARTDP_L_IPhInMmNg; /* output AC input phase current measurement inverted (FALSE=Positive direction into DC-link,
TRUE=Positive direction into AC-line) */
MWT_UDINT PARTDP_PT_Ovs2qc; /* output Time between oversamplings for AC input phase current 2QC */
MWT_UDINT PARTDP_PX_NoOvs2qc; /* output Number of oversamplings of AC input phase current 2QC */
MWT_REAL PARTDP_PX_IDfInSnRt; /* output Differential current measurement ratio (Ratio of differential current measurement device)
*/
MWT_REAL PARTDP_PX_IRctSnRt; /* output HPP rectifier current measurement ratio (Ratio of differential current measurement
device) */
MWT_BOOL PARTDP_L_IRct1MmNg; /* output HPP rectifier current 1 measurement inverted (FALSE=Positive direction into rectifier,
TRUE=Positive direction into DC-link) */
MWT_BOOL PARTDP_L_IRct2MmNg; /* output HPP rectifier current 2 measurement inverted (FALSE=Positive direction into rectifier,
TRUE=Positive direction into DC-link) */
MWT_BOOL PARTDP_L_IRct3MmNg; /* output HPP rectifier current 3 measurement inverted (FALSE=Positive direction into rectifier,
TRUE=Positive direction into DC-link) */
MWT_REAL PARTDP_PX_AI24SnRt; /* output AI24 measurement ratio */
MWT_REAL PARTDP_PX_AI29SnRt; /* output AI29 measurement ratio */
MWT_BOOL PARTAP_L_En2ndU3Ph; /* output Enable 2nd 3-phase output voltage measurement */
MWT_REAL PARTAP_PI_PhMmSvSrOp; /* output Phase current, level min during start operation, detection of missing measurement, RMS
value */
MWT_TIME PARTAP_PT_IPhMmSvSrOp; /* output Phase current measurement supervision during start operation, detection time, detection
of missing measurement */
MWT_REAL PARTAP_PI_PhMmSvNg; /* output Phase current, negative level, detection of faulty current direction, peak value */
MWT_TIME PARTAP_PT_IPhMmSvNg; /* output Phase current measurement, detection time, detection of faulty current direction */
MWT_BOOL PARTAP_L_EnU3PhMmSvMin; /* output Enable 3-phase output load voltage measurement supervision, level min, detection of
missing measurement */
MWT_REAL PARTAP_PU_U3PhMmSvMin; /* output 3-phase output load voltage RMS value, level min, detection of missing measurement. If
the RMS value is below the limit during the detection time a measurement failure is detected. */
MWT_TIME PARTAP_PT_U3PhMmSvOpLo; /* output 3-phase output load voltage RMS value, detection time for open loop control, detection of
missing measurement */
MWT_BOOL PARTAP_L_EnPrActU3PhMmFl; /* output Enable protective action due to 3-phase output load voltage measurement failure */
MWT_BOOL PARTAP_L_EnSltRqU3PhMmFl; /* output Enable isolation request due to 3-phase output load voltage measurement failure */
MWT_TIME PARTAP_PT_U3PhMmSvMin; /* output 3-phase output load voltage, detection time for protective action, detection of missing
measurement */
MWT_REAL PARTDP_PX_IPhMmSvMax; /* output Phase current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PX_UDcLkMmSvDer; /* output DC-link voltage measurement supervision, derivative limit */
MWT_REAL PARTDP_PX_UDcLkMmSvPo; /* output DC-link voltage measurement supervision, positive limit, ratio of full scale */
MWT_REAL PARTDP_PU_DcLkMmSvNg; /* output DC-link voltage measurement supervision, negative limit */
MWT_REAL PARTDP_PU_DcLkMmSvRip; /* output DC-link voltage measurement supervision, ripple limit */
MWT_BOOL PARTDP_L_UDcLkMmSvDf; /* output Enable DC-link voltage deviation supervision */
MWT_REAL PARTDP_PU_DcLkMmSvDf; /* output DC-link voltage voltage measurement supervision, maximum difference between DC-link
voltage 1 and DC-link voltage 2 */
MWT_REAL PARTDP_PT_UDcLkMmSvDfDy; /* output DC-link voltage voltage measurement supervision, detection time, maximum difference
between DC-link voltage 1 and DC-link voltage 2 */
MWT_REAL PARTDP_PX_U3PhMmSvMax; /* output 3-phase output load voltage measurement supervision, max limit, ratio of full scale */
MWT_BOOL PARTDP_L_U3PhRmsPlySv; /* output Enable 3-phase output load voltage RMS plausibility supervision */
MWT_REAL PARTDP_PU_U3PhRmsPlySvLim; /* output 3-phase output load voltage RMS plausibility supervision, max limit */
MWT_REAL PARTDP_PT_U3PhRmsPlySvDy; /* output 3-phase output load voltage RMS plausibility supervision, detection time, max limit */
MWT_REAL PARTDP_PU_BtMmSvPo; /* output Battery voltage measurement supervision, level max */
MWT_REAL PARTDP_PU_BtMmSvNg; /* output Battery voltage measurement supervision, level min */
MWT_REAL PARTDP_PU_BtMmSvRip; /* output Battery voltage measurement supervision, ripple limit */
MWT_REAL PARTDP_PX_IBtCgMmSvPo; /* output Battery charger current measurement supervision, postive limit, ratio of full scale */
MWT_REAL PARTDP_PI_BtCgMmSvNg; /* output Battery charger current measurement supervision, negative limit */
MWT_REAL PARTDP_PI_BtCgMmSvRip; /* output Battery charger current measurement supervision, ripple limit */
MWT_REAL PARTDP_PX_IBtMmSvMax; /* output Battery current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PI_BtMmSvRip; /* output Battery current measurement supervision, ripple limit */
MWT_REAL PARTDP_PX_IBtCpMmSvPo; /* output Battery chopper current measurement supervision, postive limit, ratio of full scale */
MWT_REAL PARTDP_PI_BtCpMmSvNg; /* output Battery chopper current measurement supervision, negative limit */
MWT_REAL PARTDP_PI_BtCpMmSvRip; /* output Battery chopper current measurement supervision, ripple limit */
MWT_REAL PARTDP_PX_UPhInMmSvMax; /* output AC input phase voltage measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PX_IPhInMmSvMax; /* output AC input phase current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PI_PhInRmsMmSvDf; /* output AC input phase current measurement supervision, maximum difference between AC input phase
current reference and RMS value */
MWT_REAL PARTDP_PT_IPhInRmsMmSvDy; /* output AC input phase current measurement supervision, detection time, maximum difference
between AC input phase current reference and RMS value */
MWT_REAL PARTDP_PX_IDfInMmSvMax; /* output Differential current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PX_IRctMmSvMax; /* output HPP rectifier current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PI_SumRctMmSvMax; /* output Maximum sum of HPP rectifier currents */
MWT_REAL PARTDP_PT_IRctSumMmSvDfDy; /* output Maximum sum of HPP rectifier currents, detection time */
MWT_DINT PARTDP_PX_DcLk1SvMax; /* output Max number of DC-link voltage derivative faults within 3s time window */
MWT_REAL PARTDP_PN_UDcLk_Flt; /* output DC-link voltage, filter constant for LP-filter */
MWT_REAL PARTDP_PN_U3PhRms_Flt; /* output 3-phase output load voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_UBt_Flt; /* output Battery voltage, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IBtCg1_Flt; /* output Battery charger current, filter constant for LP-filter 1 for battery charger current
limitation and overcurrent protection in DSP (For LP-filtering two LP-filters are cascade coupled) */
MWT_REAL PARTDP_PN_IBtCg2_Flt; /* output Battery charger current, filter constant for LP-filter 2 for battery charger overcurrent
protection in MCU2/A (For LP-filtering two LP-filters are cascade coupled) */
MWT_REAL PARTDP_PN_IBt_Flt; /* output Battery current, filter constant for LP-filter */
MWT_REAL PARTDP_PN_UPhIn_Flt; /* output AC input phase voltage, filter constant for elimination of DC-component */
MWT_REAL PARTDP_PN_IDfIn_Flt; /* output Differential current, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IPhActRct_Flt; /* output Phase current, active and reactive part, used for AC current limitation, filter constant
for LP-filter */
MWT_REAL PARTDP_PN_IPhActRctMcu_Flt; /* output Phase current, active and reactive part, usedin the MCU, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IPhAbs_Flt; /* output Phase current, absolute value, used in the MCU, filter constant for LP-filter */
MWT_REAL PARTDP_PN_PQ3PhMcu_Flt; /* output 3-phase inverter output power, used in the MCU, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IPhDQ_Flt; /* output Phase current, dq, filter constant */
MWT_REAL PARTDP_PN_IPhAB_Flt; /* output Phase current, ab, filter constant */
MWT_REAL PARTDP_PN_URef_Flt; /* output Voltage reference from modulation, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IRctRms_Flt; /* output HPP rectifier currents, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_AI24_Flt; /* output AI24 filter constant */
MWT_REAL PARTDP_PN_AI29_Flt; /* output AI29 filter constant */
MWT_BOOL PARTAP_L_EnU3PhOpLoCl; /* output Enable 3-phase output load voltage open loop control (3-phase output load voltage is not
measured) */
MWT_REAL PARTAP_PX_FRefRmpUpIPhInHgh; /* output Output frequency reference derivative, ramp up at high AC input phase current and low AC
input phase voltage */
MWT_REAL PARTAP_PX_FRefRmpDo1; /* output Output frequency reference derivative, ramp down, when output frequency is below
FRefRmpDo12 */
MWT_REAL PARTAP_PX_FRefRmpDo2; /* output Output frequency reference derivative, ramp down, when output frequency is between
FRefRmpDo12 and FRefRmpDo12 */
MWT_REAL PARTAP_PX_FRefRmpDo3; /* output Output frequency reference derivative, ramp down, when output frequency is above
FRefRmpDo23 */
MWT_REAL PARTAP_PF_FRefRmpDo12; /* output Output frequency point 1, for output frequency reference derivative, ramp down */
MWT_REAL PARTAP_PF_FRefRmpDo23; /* output Output frequency point 2, for output frequency reference derivative, ramp down */
MWT_REAL PARTAP_PF_3PhIPhDcClEn; /* output Output frequency when DC-current control and supervision shall be enabled */
MWT_REAL PARTAP_PF_UDcLkMin; /* output Output frequency reference at minimum DC-link voltage */
MWT_REAL PARTAP_PU_DcLkFRefLow; /* output DC-link voltage, where output frequency reference is reduced */
MWT_REAL PARTAP_PU_DcLkFRefMin; /* output Min DC-link voltage level breakpoint for output frequency reference */
MWT_REAL PARTAP_PX_FRefRmpUDcLkUp; /* output Output frequency reference derivative, ramp up at low DC-link voltage */
MWT_REAL PARTAP_PX_FRefRmpUDcLkDo; /* output Output frequency reference derivative, ramp down at low DC-link voltage */
MWT_REAL PARTAP_PF_3PhMin; /* output Output frequency reference, minimum value */
MWT_REAL PARTAP_PU_PhInFRefRmp; /* output AC input phase RMS voltage min limit, when output frequency reference is reduced */
MWT_REAL PARTAP_PI_PhInFRefRmp; /* output AC input phase RMS current max limit, when output frequency reference is reduced */
MWT_BOOL PARTAP_L_F3PhRedSwcEn; /* output Enable a direct switch to the requested output frequency reference instead of ramping
down to the requested output frequency reference, when starting switching. */
MWT_REAL PARTAP_PU_3PhClRefMin; /* output Minimum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_3PhClMax; /* output Maximum output from 3-phase output load voltage controller, phase-neutral, peak value */
MWT_REAL PARTAP_PU_3PhClMin; /* output Minimum output from 3-phase output load voltage controller, phase-neutral, peak value */
MWT_REAL PARTAP_PX_KpU3PhCl; /* output Proportional part, 3-phase output load voltage controller */
MWT_REAL PARTAP_PT_U3PhCl; /* output Time constant, 3-phase output load voltage controller */
MWT_REAL PARTAP_PF_U3PhRef2; /* output Output frequency reference, U/f-ratio, breakpoint 2 */
MWT_REAL PARTAP_PF_U3PhRef3; /* output Output frequency reference, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef1; /* output 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 0 Hz */
MWT_REAL PARTAP_PU_U3PhRef2; /* output 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 2 */
MWT_TIME PARTAP_PT_FRefUDcLk; /* output Filter constant for DC-link voltage, used for output frequency reference function as a
function of DC-link voltage */
MWT_BOOL PARTAP_L_ExtF3PhRef; /* output Use output frequency reference from MVB */
MWT_BOOL PARTAP_L_ExtU3PhRef; /* output Use 3-phase output load voltage reference from MVB */
MWT_BOOL PARTAP_B_En3PhClFqAda; /* output Enable frequency adaptation of 3-phase controller gain */
MWT_REAL PARTAP_PX_ExtU3PhRefRmp; /* output 3-phase output load voltage reference derivative, when using 3-phase output load voltage
reference from MVB */
MWT_BOOL PARTAP_L_EnRmpU3PhRef; /* output Enable ramped voltage reference to U3Ph control (Only used for HPP HEP) */
MWT_REAL PARTAP_PX_U3PhRefRmp1; /* output 3-phase output load voltage reference derivative, level 1, only used if
PARTAP_L_EnRmpU3PhRef is TRUE */
MWT_REAL PARTAP_PX_U3PhRefRmp2; /* output 3-phase output load voltage reference derivative, level 2, only used if
PARTAP_L_EnRmpU3PhRef is TRUE */
MWT_REAL PARTAP_PX_U3PhRefRmpSel; /* output Ratio of destination 3-phase output load voltage reference
when ramp derivative is shifted from level 1 to level 2, only used if PARTAP_L_EnRmpU3PhRef is TRUE */
MWT_BOOL PARTDP_L_UDcLkStbEn; /* output Enable DC-link voltage stabilization */
MWT_REAL PARTDP_PN_UDcLkStbSliSmt; /* output DC-link voltage stabilization, filter constant for slightly smoothed DC-link voltage */
MWT_REAL PARTDP_PN_UDcLkStbHevSmt; /* output DC-link voltage stabilization, filter constant for heavily smoothed DC-link voltage */
MWT_REAL PARTDP_PU_DcLkStbMaxMin; /* output DC-link voltage stabilization, max/min output, phase-neutral, peak value */
MWT_REAL PARTDP_PZ_3PhFiCaRe; /* output 3-phase filter impedance, capacitor, resistance */
MWT_UDINT PARTDP_PX_3PhMod; /* output Type of 3-phase inverter modulation 0=SVM, 1=DM, 2=SM (SVM=Space vector modulation, DM=60
degrees discontinuous modulation, SM=Sinus modulation) */
MWT_BOOL PARTDP_L_En3PhOvMod; /* output Enable 3-phase inverter overmodulation (only possible for the modulation methods SVM and
DM) */
MWT_REAL PARTDP_PN_UDcLkVoStbSmt; /* output DC-link voltage stabilization, filter constant for frequency contribution */
MWT_REAL PARTDP_PR_IPhStb; /* output Virtual resistance for phase current stabilization (set value to zero to disable this
feature) */
MWT_REAL PARTDP_PX_IPhStbRfc; /* output Virtual resistor, reduction factor */
MWT_BOOL PARTDP_L_DsFiThetaCm; /* output Disable 3-phase filter and trafo compensation theta angle */
MWT_BOOL PARTAP_L_En3PhCl; /* output Enable 3-phase output load voltage control, not battery voltage control (If battery
voltage is measured, the parameter shall be set to FALSE, else TRUE) */
MWT_REAL PARTAP_PI_UBtRef; /* output Max battery charger current level breakpoint for battery voltage reference */
MWT_TIME PARTAP_PT_BtRfCg; /* output Maximum time for battery refresh charging */
MWT_REAL PARTAP_PX_UBtRefRmpUp; /* output Battery voltage reference derivative, ramp up */
MWT_REAL PARTAP_PX_UBtRefRmpDo; /* output Battery voltage reference derivative, ramp down */
MWT_REAL PARTAP_PU_UBtClMax; /* output Maximum output from battery voltage controller, phase-neutral, peak value */
MWT_REAL PARTAP_PU_UBtClMin; /* output Minimum output from battery voltage controller, phase-neutral, peak value */
MWT_REAL PARTAP_PX_KpUBtCl; /* output Proportional part, battery voltage control */
MWT_REAL PARTAP_PT_UBtCl; /* output Time constant, battery voltage control */
MWT_REAL PARTAP_PX_TrfRtBt3Ph; /* output Transformer ratio, battery to 3-phase winding */
MWT_REAL PARTAP_PX_TrfRtPrBt; /* output Transformer ratio, primary to battery winding */
MWT_REAL PARTAP_PH_RctHtRef1; /* output Battery rectifier heat-sink temperature, where battery voltage reference is reduced */
MWT_REAL PARTAP_PH_RctHtRef2; /* output Max battery rectifier heat-sinktemp level breakpoint for batt voltage ref */
MWT_REAL PARTAP_PX_RctHtHBtRef; /* output Ratio of nominal battery voltage at max battery rectifier heat-sink temperature level
breakpoint */
MWT_REAL PARTAP_PX_UBtCpRefRmp; /* output Battery voltage reference ramp up derative at start of Battery chopper */
MWT_REAL PARTAP_PF_IPhClMin; /* output Minimum output frequency, AC current limitation, general overload control */
MWT_REAL PARTAP_PF_IPhClMinErr; /* output Minimum frequency error to AC current limitation, general overload control */
MWT_REAL PARTAP_PX_IPhClIntMax; /* output Maximum integrator input to AC current limitation, general overload control */
MWT_REAL PARTAP_PX_IPhClIntMin; /* output Minimum integrator input to AC current limitation, general overload control */
MWT_TIME PARTAP_PT_IPhClInt; /* output Integration time constant to AC current limitation, general overload control */
MWT_REAL PARTAP_PI_IPhClActMax; /* output Maximum active phase current reference, post-transient control */
MWT_REAL PARTAP_PI_IPhClActMin; /* output Minimum active phase current reference, post-transient control */
MWT_REAL PARTAP_PI_IPhClActPsTrs; /* output Active phase current limit, post-transient control */
MWT_REAL PARTAP_PI_IPhClActOs; /* output Active phase current reference offset contribution, post-transient control */
MWT_REAL PARTAP_PX_IPhClActDe; /* output Active phase current reference derivative, post-transient control */
MWT_REAL PARTAP_PI_IPhClRctMax; /* output Maximum reactive phase current reference, post-transient control */
MWT_REAL PARTAP_PI_IPhClRctMin; /* output Minimum reactive phase current reference, post-transient control */
MWT_REAL PARTAP_PI_IPhClRctPsTrs; /* output Reactive phase current limit, post-transient control */
MWT_REAL PARTAP_PI_IPhClRctOs; /* output Reactive phase current reference offset contribution, post-transient control */
MWT_REAL PARTAP_PX_IPhClRctDePos; /* output Reactive phase current reference derivative, ramp up, post-transient control */
MWT_REAL PARTAP_PX_IPhClRctDeNg; /* output Reactive phase current reference derivative, ramp down, post-transient control */
MWT_REAL PARTAP_PI_IPhClPsTrsLim; /* output Peak phase current limit, post-transient control */
MWT_REAL PARTDP_PX_IPhClTrsKpAct; /* output Active phase current amplification, transient control, to DSP */
MWT_REAL PARTDP_PX_IPhClTrsKpRct; /* output Reactive phase current amplification, transient control, to DSP */
MWT_REAL PARTDP_PX_IPhClTrsKpAbs; /* output Active and Reactive phase current amplification, transient control, to DSP */
MWT_REAL PARTDP_PI_PhClTrsAbsLim; /* output Phase current limitation, transient control limit */
MWT_REAL PARTDP_PU_PhClTrsMax; /* output Max reduction of voltage reference from transient and post-transient control in the DSP,
phase-neutral, peak value, If set to zero the AC current limitation, transient and post-transient control, is disabled */
MWT_REAL PARTDP_PN_URefIPhClTrs_Flt; /* output 3-phase output load voltage manipulation from AC current control, transient control,
filter constant for LP-filter */
MWT_REAL PARTDP_PX_IPhClRmsRmpUp; /* output RMS phase current limitation derivative at nominal frequency. */
MWT_REAL PARTDP_PX_IPhClRmsRfc; /* output RMS phase current limitation, reduction factor of the previous value */
MWT_BOOL PARTDP_L_EnIPhClRms; /* output Enable RMS phase current limitation */
MWT_REAL PARTDP_PI_PhClRmsLim; /* output RMS phase current limitation, current limit */

MWT_REAL PARTDP_PN_IPhRms_Flt; /* output Phase current filter constant of RMS value */
MWT_REAL PARTAP_PX_IBtCgRmp; /* output Battery charger current derivative, used for ramping the battery charger current
reference */
MWT_REAL PARTDP_PX_IBtCgDeLim; /* output Battery charger current, positive derivative limit */
MWT_REAL PARTDP_PI_BtCgMinAvDe; /* output Min battery charger current to activate positive derivative limit */
MWT_REAL PARTAP_PI_RfCgLim; /* output Battery charger current limit, refresh charging limit */
MWT_REAL PARTDP_PX_KpIBtCgCl; /* output Proportional part, battery charger current control */
MWT_REAL PARTDP_PX_KiIBtCgCl; /* output Integrational part, battery charger current control */
MWT_REAL PARTDP_PU_IBtCgClMax; /* output Maximum voltage contribution from battery charger current control, phase-neutral, peak
value */
MWT_REAL PARTAP_PX_KpIBtCl; /* output Proportional part, battery current control */
MWT_REAL PARTAP_PU_IBtClMax; /* output Maximum voltage contribution from battery current control, battery voltage */
MWT_BOOL PARTDP_L_EnIPhDcCl; /* output Enable suppression of DC-components in phase currents */
MWT_REAL PARTDP_PU_IPhDcClMaxMin; /* output Max/min output from DC-current suppression controller, phase-neutral, peak value */
MWT_REAL PARTDP_PX_KpIPhDcCl; /* output Proportional part, DC-current suppression controller */
MWT_REAL PARTDP_PX_KiIPhDcCl; /* output Integral part, DC-current suppression controller */
MWT_BOOL PARTAP_L_EnUF3PhCmp; /* output Enable voltage and frequency compounding */
MWT_REAL PARTAP_PI_UF3PhCmpActHiLo; /* output Active phase current at output frequency breakpoint */
MWT_REAL PARTAP_PF_UF3PhCmpActHiLo; /* output Output frequency breakpoint */
MWT_REAL PARTAP_PI_UF3PhCmpRctHiLo; /* output Reactive phase current at 3-phase output load voltage breakpoint */
MWT_REAL PARTAP_PF_UF3PhSzClMaxMin; /* output Max/min output from output frequency synchronization controller */
MWT_TIME PARTAP_PT_UF3PhSzRmp; /* output Ramp time for ending synchronization */
MWT_REAL PARTAP_PU_UF3PhSzClAdd; /* output Amplitude addition during synchronization to 3-phase auxiliary 3-phase bus, phase to
neutral, peak value */
MWT_REAL PARTAP_PU_UF3PhSzClMaxMin; /* output Max/min output from 3-phase output load voltage synchronization controller,
phase-neutral, peak value */
MWT_TIME PARTAP_PT_UF3PhSzFl; /* output Time delay before detection synchronization failure to 3-phase auxiliary bus */
MWT_UDINT PARTDP_PX_UPhInNtFltDy; /* output Compensation for notch filter delay, when removing frequencies from the AC input phase
voltage for line synchronization */
MWT_BOOL PARTDP_L_DsPlElm3PhMod; /* output Disable pulse elimination at low or high 3-phase inverter control ratio */
MWT_BOOL PARTDP_L_EnTPrDdCmp; /* output Enable pre-control of interlocking times */
MWT_REAL PARTDP_PX_DdCmpFa; /* output Dead time compensation factor */
MWT_REAL PARTDP_PI_DdCmpFu; /* output Phase current level for full dead time compensation */
MWT_REAL PARTDP_PI_DdCmpDs; /* output Phase current level for no dead time compensation */
MWT_REAL PARTDP_PF_2qcSg; /* output 2QC switching frequency (Connected to IRQD cycle time) */
MWT_REAL PARTDP_PF_2qcSgChg; /* output 2QC switching frequency change as a function of MVB address */
MWT_BOOL PARTAP_L_ExtCtCl; /* output External control of contactors with DX via MVB */
MWT_BOOL PARTAP_L_ExtDiOut1En; /* output Enable external control of digital output 1 */
MWT_BOOL PARTAP_L_ExtDiOut2En; /* output Enable external control of digital output 2 */
MWT_BOOL PARTAP_L_ExtDiOut3En; /* output Enable external control of digital output 3 */
MWT_BOOL PARTAP_L_ExtDiOut4En; /* output Enable external control of digital output 4 */
MWT_BOOL PARTAP_L_ExtDiOut5En; /* output Enable external control of digital output 5 */
MWT_BOOL PARTAP_L_ExtDiOut6En; /* output Enable external control of digital output 6 */
MWT_BOOL PARTAP_L_DcLkChCt; /* output Charging contactor in use */
MWT_BOOL PARTAP_L_DcLkSrCt; /* output Separation contactor in use */
MWT_REAL PARTAP_PU_DcLkUHgh; /* output DC-link voltage level regarded as charged, used when separation contactor or charging
contactor is in use */
MWT_TIME PARTAP_PT_2qcOpChRdy; /* output Time for DC-link charging ready after 2QC in operation */
MWT_BOOL PARTAP_L_3PhCvDh; /* output Discharge of DC-link via 3 phase inverter */
MWT_REAL PARTAP_PU_3PhDcLkCvDh; /* output 3-phase output load voltage reference during DC-link discharging via 3-phase inverter */
MWT_REAL PARTAP_PF_3PhDcLkCvDh; /* output Output frequency reference during DC-link discharging via 3-phase inverter */
MWT_REAL PARTAP_PU_3PhIdlCmp; /* output Maximum voltage for detecting an idle 3-phase bus, phase-phase, RMS value */
MWT_REAL PARTAP_PU_3PhActCmp; /* output Minimum voltage for detecting an active 3-phase bus, phase-phase, RMS value */
MWT_BOOL PARTAP_L_BcOpSrCt; /* output Enable blocking with opening of contactors */
MWT_TIME PARTAP_PT_DySrCtOp; /* output Delay time for opening of contactors in protective shutdown */
MWT_TIME PARTAP_PT_DyAuLdCtOp; /* output Delay time for opening of auxiliary load contactor in protective shutdown */
MWT_BOOL PARTAP_L_EnTmOutPrSd; /* output Enable isolation after protective shutdown time-out */
MWT_BOOL PARTAP_L_EnTmOutFsSd; /* output Enable isolation after fast shutdown time-out */
MWT_BOOL PARTAP_L_EnTmOutSfSd; /* output Enable isolation after soft shutdown time-out */
MWT_BOOL PARTAP_L_EnTmOutPrBc; /* output Enable isolation after protective blocking time-out */
MWT_TIME PARTAP_PT_TmOutPrSd; /* output Time for isolation after protective shutdown time-out */
MWT_TIME PARTAP_PT_TmOutFsSd; /* output Time for isolation after fast shutdown time-out */
MWT_TIME PARTAP_PT_TmOutSfSd; /* output Time for isolation after soft shutdown time-out */
MWT_TIME PARTAP_PT_TmOutPrBc; /* output Time for isolation after protective blocking time-out */
MWT_BOOL PARTAP_L_EnMvbWdg2Sv; /* output Enable MVB watchdog supervision on T2 (16 ms) */
MWT_BOOL PARTAP_L_EnMvbWdg3Sv; /* output Enable MVB watchdog supervision on T3 (64 ms) */
MWT_BOOL PARTAP_L_EnMvbWdg4Sv; /* output Enable MVB watchdog supervision on T4 (1024 ms) */
MWT_INT PARTAP_PX_NoFlMvbCy_Hgh; /* output Amount of samples for MVB disturbance warning */
MWT_INT PARTAP_PX_NoFlMvbCy_Max; /* output Maximum samples of MVB watchdog counter error */
MWT_UDINT PARTDP_PT_PrDdPoa; /* output Phase interlocking time in a POA */
MWT_UDINT PARTDP_PT_PoaOnMin; /* output Minimum switching-ON-time for IGBT in a POA */
MWT_UDINT PARTDP_PT_OvpOfMin; /* output Minimum switching-OFF-time for OVP */
MWT_UDINT PARTDP_PT_OvpOnMin; /* output Minimum switching-ON-time for OVP */
MWT_UDINT PARTDP_PT_2qcOfMin; /* output Minimum switching-OFF-time for 2QC */
MWT_UDINT PARTDP_PT_2qcOnMin; /* output Minimum switching-ON-time for 2QC */
MWT_UDINT PARTDP_PT_BtCpOnMin; /* output Minimum switching-ON-time for Battery chopper IGBT */
MWT_UDINT PARTDP_PT_BtCpOfMin; /* output Minimum switching-OFF-time for Battery chopper IGBT */
MWT_UDINT PARTDP_PT_UDcLkMaxDy; /* output DC-link overvoltage protection, detection time for level max */
MWT_BOOL PARTAP_L_EnOvp; /* output Enable OVP */
MWT_REAL PARTDP_PU_DcLkHgh4; /* output DC-link overvoltage protection, level high4 */
MWT_REAL PARTDP_PT_UDcLkHgh4Dy; /* output DC-link overvoltage protection, detection time, level high4 */
MWT_BOOL PARTAP_L_EnUDcLkHgh12; /* output Enable DC-link overvoltage protection, level high1 and level high2 */
MWT_TIME PARTAP_PT_UDcLkHgh2; /* output DC-link overvoltage protection, detection time, level high2 */
MWT_REAL PARTAP_PU_DcLkHghRst; /* output DC-link overvoltage protection, reset level for level high2 and level high1 */
MWT_TIME PARTAP_PT_UDcLkLowDy; /* output DC link voltage low level, delay */
MWT_REAL PARTDP_PT_SiPhBcPoaTmWnd1; /* output Single phase blocking (SPB) supervision POA, time window 1 */
MWT_DINT PARTDP_PX_SiPhBcPoaMaxWnd1; /* output Single Phase Blocking (SPB) supervision POA, maximum number of SPB within time window 1
*/
MWT_REAL PARTDP_PT_SiPhBcPoaTmWnd2; /* output Single Phase Blocking (SPB) supervision POA, time window 2 */
MWT_DINT PARTDP_PX_SiPhBcPoaMaxWnd2; /* output Single Phase Blocking (SPB) supervision POA, maximum number of time window 1 within time
window 2 */
MWT_REAL PARTDP_PI_PhMax; /* output Phase overcurrent protection, level max */
MWT_UDINT PARTDP_PT_IPhMaxDy; /* output Phase overcurrent protection, detection time for level max */
MWT_REAL PARTDP_PI_PhHi4; /* output Phase overcurrent protection, level high4, activation of Single Phase Blocking (SPB) POA
*/
MWT_UDINT PARTDP_PT_IBtCpMaxDy; /* output Battery chopper overcurrent protection, detection time for level max */
MWT_REAL PARTDP_PI_BtCpHi4; /* output Battery chopper overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) */
MWT_UDINT PARTDP_PT_IBtCpHi4Dy; /* output Battery chopper overcurrent protection, detection time for level high 4 */
MWT_REAL PARTDP_PT_SiPhBcBtCpTmWnd1; /* output Single phase blocking (SPB) supervision BtCp, time window 1 */
MWT_DINT PARTDP_PX_SiPhBcBtCpMaxWnd1; /* output Single Phase Blocking (SPB) supervision BtCp, maximum number of SPB within time window 1
*/
MWT_UINT PARTAP_PX_IBtCpTmWndFl; /* output Supervision of Battery chopper current SPB, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IBtCpTmWndFl; /* output Supervision of Battery chopper current SPB, time window for monitoring the number of
failures */
MWT_REAL PARTDP_PT_IPhClRmsTmWnd1; /* output RMS phase current limitation supervision, time window 1 */
MWT_DINT PARTDP_PX_IPhClRmsMaxWnd1; /* output RMS phase current limitation supervision, maximum number of RMS phase current limitation
within time window 1 */
MWT_REAL PARTDP_PI_PhClRmsSvMax; /* output RMS phase current limitation supervision, level max */
MWT_REAL PARTDP_PT_IPhClRmsSvDy; /* output RMS phase current limitation supervision, detection time for level max */
MWT_TIME PARTAP_PT_IAcLimTmSvDy; /* output AC current limitation time supervision delay */
MWT_TIME PARTAP_PT_IPhClTrsAvTof; /* output Time-off delay to fetch short transient or post transient indications */
MWT_BOOL PARTAP_L_EnIPhDcSv; /* output Enable phase current DC supervision */
MWT_REAL PARTAP_PI_PhDcSvMax; /* output Phase current DC supervision max level, peak value */
MWT_TIME PARTAP_PT_IPhDcSvMaxDy; /* output Phase current DC supervision max level delay */
MWT_BOOL PARTAP_L_EnIBalSv; /* output Enable phase current unbalance protection */
MWT_TIME PARTAP_PT_IBalSvDelDy; /* output Phase current unbalance protection, detection time, level max */
MWT_TIME PARTAP_PT_IBalSvDyCvOp; /* output Phase current unbalance protection, delay before activation after start operation */
MWT_BOOL PARTAP_L_BlkSiFl; /* output Block the converter at single feedback failure */
MWT_BOOL PARTAP_L_En3PhGduFbCk; /* output Enable 3-phase inverter GDU feedback check at start */
MWT_BOOL PARTAP_L_En2qcGduFbCk; /* output Enable 2QC GDU feedback check during DC-link charging */
MWT_TIME PARTAP_PT_GduFbCk_Mx; /* output Maximum time for GDU feedback check at start and during DC-link charging */
MWT_REAL PARTDP_PU_DcLkShtCrSv; /* output DC-link voltage level to detect a DC-link short circuit if both GDU feedbacks in POA
shows on */
MWT_REAL PARTDP_PT_GduBoFbOnPoaDy; /* output Both GDU feedback in POA shows on, detection time for supervision in DSP */
MWT_BOOL PARTAP_L_UceGduFb; /* output UCE-feedback is used */
MWT_REAL PARTDP_PU_DcLkGduFbSvAv; /* output Minimum DC-link voltage level to activate GDU feedback supervision if UCE-feedback is
used. */
MWT_BOOL PARTDP_L_EnGduFbSvPoa; /* output Enable GDU feedback supervision POA */
MWT_BOOL PARTDP_L_EnGduFbSvOvp; /* output Enable GDU feedback supervision OVP */
MWT_BOOL PARTDP_L_EnGduFbSv2qc; /* output Enable GDU feedback supervision 2QC */
MWT_UDINT PARTDP_PX_NoGduFbFlPoa_Max; /* output Max allowed number of GDU feedback failures for POA */
MWT_UDINT PARTDP_PX_NoGduFbFlOvp_Max; /* output Max allowed number of GDU feedback failures for OVP */
MWT_UDINT PARTDP_PX_NoGduFbFl2qc_Max; /* output Max allowed number of GDU feedback failures for 2QC */
MWT_BOOL PARTDP_L_EnGduShtCrSv; /* output Enable DC-link short circuit supervision (Supervision of if both GDU feedbacks in POA
show on) */
MWT_BOOL PARTDP_L_EnGduShtCrPraFpga; /* output Protective action in FPGA in case of DC-link short circuit (Supervision of if both GDU
feedbacks in POA show on. If FALSE the protective action is in the DSP) */
MWT_UDINT PARTDP_PT_MskGduFbPoa; /* output GDU feedback masking time in a POA, must be greater than (2*Tdead+Tglitch) */
MWT_UDINT PARTDP_PT_MskGduFbOvp; /* output GDU feedback masking time for OVP, must be greater than PARTDP_PT_GltFiGduFbOvp */
MWT_UDINT PARTDP_PT_MskGduFb2qc; /* output GDU feedback masking time for 2QC, must be greater than PARTDP_PT_GltFiGduFb2qc */
MWT_UDINT PARTDP_PT_GltFiGduFbPoa; /* output Glitch filter time for GDU feedback supervision POA */
MWT_UDINT PARTDP_PT_GltFiGduFbOvp; /* output Glitch filter time for GDU feedback supervision OVP */
MWT_UDINT PARTDP_PT_GltFiGduFb2qc; /* output Glitch filter time for GDU feedback supervision 2QC */
MWT_UDINT PARTDP_PX_NoGduFbFlBtCp_Max; /* output Max allowed number of GDU feedback failures for Battery chopper */
MWT_UDINT PARTDP_PT_GltFiGduFbBtCp; /* output Glitch filter time for GDU feedback supervision Battery chopper */
MWT_UDINT PARTDP_PT_MskGduFbBtCp; /* output GDU feedback masking time in Battery chopper, must be greater than
PARTDP_PT_GltFiGduFbBtCp */
MWT_UINT PARTAP_PX_GduFbSvBtCp; /* output GDU feedback supervision BtCp, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_GduFbSvBtCp; /* output GDU feedback supervision BtCp, time window for monitoring the number of failures */
MWT_BOOL PARTAP_L_EnU3PhRmsMaxSv; /* output Enable 3-phase output load overvoltage protection */
MWT_REAL PARTAP_PU_3PhRmsMax; /* output 3-phase output load overvoltage protection, level max, phase-phase, RMS value */
MWT_TIME PARTAP_PT_U3PhRmsMax; /* output 3-phase output load overvoltage protection, detection time, level max */
MWT_UINT PARTAP_PX_OvU3Ph; /* output 3-phase output load overvoltage protection, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_OvU3Ph; /* output 3-phase output load overvoltage protection, time window for monitoring the number of
failures */
MWT_BOOL PARTAP_L_UBtHghLowSvEn; /* output Enable Battery high and low voltage supervision */
MWT_REAL PARTAP_PU_BtMax; /* output Battery voltage, level max */
MWT_REAL PARTAP_PU_BtHgh; /* output Battery voltage, level high */
MWT_TIME PARTAP_PT_UBtHghDy; /* output Battery voltage, level high, delay */
MWT_REAL PARTAP_PU_BtHghRst; /* output Battery voltage, level max and level high reset */
MWT_REAL PARTAP_PU_BtMin; /* output Battery voltage, level min */
MWT_TIME PARTAP_PT_UBtMinDy; /* output Battery voltage, level min, delay */
MWT_REAL PARTAP_PU_BtMinRst; /* output Battery voltage, level min reset */
MWT_BOOL PARTAP_L_UBtDepAuLdCtClEn; /* output Enable Battery dependant auxiliary load contactor control */
MWT_REAL PARTAP_PU_BtOpAuLdCt; /* output Battery voltage level to open auxiliary contactor */
MWT_TIME PARTAP_PT_UBtOpAuLdCtDy; /* output Battery voltage level to open auxiliary contactor, delay */
MWT_REAL PARTAP_PU_BtCdAuLdCt; /* output Battery voltage level to close auxiliary contactor */
MWT_TIME PARTAP_PT_BtMinChTm; /* output Minimum charging time */
MWT_BOOL PARTAP_L_OvIBtCgHghEn; /* output Enable battery charger overcurrent protection, level high */
MWT_BOOL PARTDP_L_OvIBtCgEn; /* output Enable battery charger overcurrent protection, level max */
MWT_REAL PARTDP_PI_BtCgMax; /* output Battery charger overcurrent, level max */
MWT_REAL PARTDP_PT_IBtCgMaxDy; /* output Battery charger overcurrent, detection time, level max */
MWT_TIME PARTAP_PT_IBtCgFltHghDy; /* output Filtered battery charger current detection time, level high */
MWT_BOOL PARTAP_L_OvIBtCpHghEn; /* output Enable battery chopper overcurrent protection, level high */
MWT_REAL PARTAP_PI_BtCpFltHgh; /* output Filtered battery chopper current high level */
MWT_TIME PARTAP_PT_IBtCpFltHghDy; /* output Filtered battery chopper current detection time, level high */
MWT_BOOL PARTAP_L_IBtCgTmSvEn; /* output Enable battery charger current limitation time-out supervision */
MWT_BOOL PARTAP_L_PraEnIBtCgTmSv; /* output Enable protective action due to battery charger current time-out failure */
MWT_BOOL PARTAP_L_SltEnIBtCgTmSv; /* output Enable isolation request after protective action due to battery charger current time-out
failure */
MWT_REAL PARTAP_PX_IBtCgLimHghFr; /* output Battery charger current limit high fraction */
MWT_TIME PARTAP_PT_OffGhIBtCgLimHghDy; /* output Battery charger current limit high, off-glitch delay */
MWT_TIME PARTAP_PT_IBtCgLimHghDy; /* output Battery charger current limit high, delay */
MWT_REAL PARTAP_PI_BtCgLim; /* output Battery charger current limit */
MWT_BOOL PARTAP_L_IBtTmSvEn; /* output Enable battery current limitation time-out supervision */
MWT_BOOL PARTAP_L_PraEnIBtTmSv; /* output Enable protective action due to battery current time-out failure */
MWT_BOOL PARTAP_L_SltEnIBtTmSv; /* output Enable isolation request after protective action due to battery current time-out failure
*/
MWT_REAL PARTAP_PX_IBtLimHghFr; /* output Battery current limit high fraction */
MWT_TIME PARTAP_PT_OffGhIBtLimHghDy; /* output Battery current limit high, off-glitch delay */
MWT_BOOL PARTAP_L_EnChRsTpSm; /* output Enable Charging resistor temperature simulation */
MWT_REAL PARTAP_PH_AmTp_Max; /* output Ambient temperature worst case */
MWT_REAL PARTAP_PT_ChRsCoTmCns; /* output Charging resistor coolant time constant */
MWT_REAL PARTAP_PH_ChRsTp_UpThr; /* output Charging resistor upper temperature threshold */
MWT_REAL PARTAP_PH_ChRsTp_LowThr; /* output Charging resistor lower temperature threshold */
MWT_REAL PARTAP_PR_ChRs; /* output Charging resistor resistance */
MWT_REAL PARTAP_PK_ChRs; /* output Charging resistor thermal capacitance */
MWT_REAL PARTAP_PC_DcLk; /* output Total DC-link capacitance */
MWT_BOOL PARTAP_L_EnChDcLkCnt; /* output Enable supervision of number of DC-link charging attempts */
MWT_UINT PARTAP_PN_ChDcLkCnt; /* output Number of DC-link charging attempts within time window */
MWT_TIME PARTAP_PT_ChDcLkCnt; /* output Time window for number of DC-link charging attempts */
MWT_BOOL PARTAP_L_EnChCtSv; /* output Enable charging contactor supervision */
MWT_BOOL PARTAP_L_EnSrCtSv; /* output Enable separation contactor supervision */
MWT_TIME PARTAP_PT_CtOnDy; /* output Time on delay for contactor feedback supervision */
MWT_TIME PARTAP_PT_CtOfDy; /* output Time off delay for contactor feedback supervision */
MWT_TIME PARTAP_PT_CtFi; /* output Glitch filter time for contactor supervision */
MWT_BOOL PARTAP_L_SoCdAuLdCt; /* output Stop converter before auxiliary load contactor closing (The converter is stopped if the
converter is switching and the auxiliary load contactor shall be closed, mainly used when DCU controls an integrated battery charger) */
MWT_TIME PARTAP_PT_AuLdCtOnDy; /* output Auxiliary load contactor on time delay */
MWT_TIME PARTAP_PT_AuLdCtFi; /* output Auxiliary load contactor glitch time */
MWT_TIME PARTAP_PT_AuLdCtOfDy; /* output Auxiliary load contactor off time delay */
MWT_REAL PARTAP_PU_DcLkChLv1; /* output DC-link voltage, level 1 */
MWT_REAL PARTAP_PX_DcLkChLv2; /* output DC-link voltage, level 2, fraction of AC input phase voltage, RMS value */
MWT_TIME PARTAP_PT_DcLkChDyLv1; /* output Time delay before checking DC-link voltage, level 1 */
MWT_TIME PARTAP_PT_DcLkChDyLv2; /* output Time delay before checking DC-link voltage, level 2, only 2QC */
MWT_REAL PARTAP_PU_DhDcLk_Max; /* output DC-link voltage discharged level and maximum DC-link voltage to switch on GDU power
supply */
MWT_TIME PARTAP_PT_DcLkDhDy; /* output Delay time for DC-link discharge (Maximum time before protective action is
PT_DcLkDhDy+PT_FrOvp) */
MWT_TIME PARTAP_PT_FrOvp; /* output Time to fire OVP */
MWT_BOOL PARTAP_L_EnDhDcLkCvSl; /* output Enable DC-link discharging in converter isolation state */
MWT_REAL PARTAP_PU_DcLkCvSlDh; /* output Voltage threshold to discharge DC-link in isolation state */
MWT_BOOL PARTAP_L_EnOvpFcTs; /* output Enable OVP functional test */
MWT_TIME PARTAP_PT_DyOvpFcTs; /* output Max time for OVP functional test */
MWT_REAL PARTAP_PU_DcLkU_OvpFcTs; /* output Minimum DC-link voltage to run OVP test */
MWT_REAL PARTDP_PX_OvpFcTsClRt; /* output OVP test during DC-link charging, control ratio */
MWT_REAL PARTDP_PT_OvpFcTsFrMax; /* output OVP test during DC-link charging, OVP maximum firing time */
MWT_REAL PARTDP_PU_OvpFcTsRdy; /* output OVP test during DC-link charging, minimum DC-link voltage drop to pass test */
MWT_BOOL PARTDP_L_OvpRsTpSvEn; /* output Enable OVP resistor overtemperature protection */
MWT_REAL PARTDP_PR_Ovp; /* output OVP resistor overtemperature protection, resistance */
MWT_REAL PARTDP_PK_Ovp; /* output OVP resistor overtemperature protection, thermal capacitance */
MWT_REAL PARTDP_PT_OvpCoCns; /* output OVP resistor overtemperature protection, cooling time constant */
MWT_REAL PARTDP_PH_OvpMax; /* output OVP resistor overtemperature protection, maximum OVP temperature */
MWT_REAL PARTDP_PH_OvpRst; /* output OVP resistor overtemperature protection, reset OVP temperature */
MWT_REAL PARTAP_PI_SrCtISv; /* output Max current for opening of contactor (For 2QC, AC input phase current, in DC system an
external DC current measurement is needed) */
MWT_REAL PARTAP_PI_ChCtISv; /* output Max current for opening of charging contactor (For 2QC, AC input phase current, in DC
system an external DC current measurement is needed. If no DC-current is measured the parameter value 0 can be used to always request PrSd to avoid opening with
current) */
MWT_TIME PARTAP_PT_SrCtISvDy; /* output Max time opening of contactors can be disabled due to high current */
MWT_BOOL PARTAP_L_EnHHtSv; /* output Enable heatsink temperature supervision */
MWT_BOOL PARTAP_L_EnIgbtOvLdSv; /* output Enable IGBT overload protection */
MWT_REAL PARTAP_PH_HtSvMax; /* output Heatsink temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_HtSvHgh2; /* output Heatsink temperature supervision, level high2, opening of auxiliary load contactor */
MWT_REAL PARTAP_PH_HtSvHgh1; /* output Heatsink temperature supervision, level high1, indication level */
MWT_REAL PARTAP_PH_HtSvRst; /* output Heatsink temperature supervision, reset level */
MWT_TIME PARTAP_PT_HHtSvMax; /* output Heatsink temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HHtSvHgh2; /* output Heatsink temperature supervision, detection time for level high2 */
MWT_TIME PARTAP_PT_HHtSvHgh1; /* output Heatsink temperature supervision, detection time for level high1 */
MWT_REAL PARTAP_PI_HtSvHgh2; /* output Phase current limit at converter heatsink temperature, level high2, peak value */
MWT_REAL PARTAP_PX_HtSvCntLim; /* output Continuous current level, fraction of full phase current limit */
MWT_TIME PARTAP_PT_HtSvOvLdLim; /* output IGBT overload failure (current limit), detection time */
MWT_UINT PARTAP_PX_HHtSvMax; /* output Heatsink temperature supervision, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_HHtSvMaxTmWn; /* output Heatsink temperature supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_IgbtOvLd; /* output IGBT overload supervision (current limit), maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IgbtOvLd; /* output IGBT overload supervision (current limit), time window for monitoring the number of
failures */
MWT_REAL PARTAP_PH_RctHtMax; /* output Battery rectifier heat-sink supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_RctHtSvHgh; /* output Battery rectifier heat-sink temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_RctHtSvRst; /* output Battery rectifier heat-sink temperature supervision, reset level */
MWT_TIME PARTAP_PT_RctHtSvMax; /* output Battery rectifier heat-sink temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_RctHtSvHgh; /* output Battery rectifier heat-sink temperature supervision, detection time for level high */
MWT_BOOL PARTAP_L_EnHTfSv; /* output Enable transformer temperature supervision */
MWT_REAL PARTAP_PH_TfSvMax; /* output Transformer temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_TfSvHgh2; /* output Transformer temperature supervision, level high2, opening of auxiliary load contactor */
MWT_REAL PARTAP_PH_TfSvHgh1; /* output Transformer temperature supervision, level high1, indication level */
MWT_REAL PARTAP_PH_TfSvRst; /* output Transformer temperature supervision, reset level */
MWT_TIME PARTAP_PT_HTfSvMax; /* output Transformer temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HTfSvHgh2; /* output Transformer temperature supervision, detection time for level high2 */
MWT_TIME PARTAP_PT_HTfSvHgh1; /* output Transformer temperature supervision, detection time for level high1 */
MWT_BOOL PARTAP_L_EnLngTmOvLdSv; /* output Enable long-term overload protection */
MWT_TIME PARTAP_PT_LngTmOvLdInt; /* output Time constant, load integral, long-term overload protection */
MWT_REAL PARTAP_PI_LngTmOvLdMax; /* output Long-term overload protection, peak phase current, level max */
MWT_REAL PARTAP_PI_LngTmOvLdHgh; /* output Long-term overload protection, peak phase current, level high */
MWT_REAL PARTAP_PI_LngTmOvLdRst; /* output Long-term overload protection, peak phase current, reset level */
MWT_TIME PARTAP_PT_LngTmOvLdHgh; /* output Long-term overload protection, detection time for level high */
MWT_BOOL PARTAP_L_EnHBtSv; /* output Enable battery temperature supervision */
MWT_TIME PARTAP_PT_HBtSvMax; /* output Battery temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HBtSvHgh; /* output Battery temperature supervision, detection time for level high */
MWT_BOOL PARTAP_L_EnHNteArSv; /* output Enable internal air temperature supervision */
MWT_REAL PARTAP_PH_NteArSvMax; /* output Internal air temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_NteArSvHgh2; /* output Internal air temperature supervision, level high2, opening of auxilaty load contactor */
MWT_REAL PARTAP_PH_NteArSvHgh1; /* output Internal air temperature supervision, level high1, indication level */
MWT_REAL PARTAP_PH_NteArSvRst; /* output Internal air temperature supervision, reset level */
MWT_TIME PARTAP_PT_HNteArSvMax; /* output Internal air temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HNteArSvHgh2; /* output Internal air temperature supervision, detection time for level high2 */
MWT_TIME PARTAP_PT_HNteArSvHgh1; /* output Internal air temperature supervision, detection time for level high1 */
MWT_BOOL PARTAP_L_EnHNd1Sv; /* output Enable inductor 1 temperature supervision */
MWT_BOOL PARTAP_L_EnHNd2Sv; /* output Enable inductor 2 temperature supervision */
MWT_BOOL PARTAP_L_EnHNd3Sv; /* output Enable inductor 3 temperature supervision */
MWT_REAL PARTAP_PH_NdSvMax; /* output Inductor temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_NdSvHgh; /* output Inductor temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_NdSvRst; /* output Inductor temperature supervision, reset level */
MWT_TIME PARTAP_PT_HNdSvMax; /* output Inductor temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HNdSvHgh; /* output Inductor temperature supervision, detection time for level high */
MWT_TIME PARTAP_PT_HNdSnFl; /* output Detection time, double inductor sensor failure */
MWT_BOOL PARTAP_L_DcCrBkSvEn; /* output Enable DC circuit breaker supervision */
MWT_BOOL PARTAP_L_DcCrBkSvSltEn; /* output Enable DC circuit breaker isolation request */
MWT_REAL PARTAP_PU_DcLkLowDcCrBkSv; /* output DC link voltage low level DC circuit breaker supervision */
MWT_TIME PARTAP_PT_DcCrBkSvDy; /* output DC circuit breaker supervision delay */
MWT_TIME PARTAP_PT_DcCrBkTrpRunTm; /* output DC circuit breaker tripped allowed running time, before isolation request */
MWT_BOOL PARTAP_L_FnCrBkSvEn; /* output Enable fan circuit breaker supervision */
MWT_BOOL PARTAP_L_FnCrBkSvPrBcEn; /* output Enable protective blocking due to fan circuit breaker time-out failure */
MWT_BOOL PARTAP_L_FnCrBkSvSltEn; /* output Enable isolation request due to fan circuit breaker time-out failure */
MWT_TIME PARTAP_PT_FnCrBkFbOpGhDy; /* output Fan circuit breaker feedback open glitch delay */
MWT_TIME PARTAP_PT_FnCrBkOffGhCvOpDy; /* output Converter in operation off glitch delay */
MWT_TIME PARTAP_PT_FnCrBkTrpRunTm; /* output Fan circuit breaker tripped allowed running time */
MWT_BOOL PARTAP_L_FnCtSvEn; /* output Enable fan contactor supervision */
MWT_BOOL PARTAP_L_FnCtSvPrBcEn; /* output Enable protective action due to fan contactor on time-out failure */
MWT_BOOL PARTAP_L_FnCtSvSltEn; /* output Enable isolation request due to fan contactor on time-out failure */
MWT_TIME PARTAP_PT_FnCtRp; /* output Fan contactor response time */
MWT_TIME PARTAP_PT_FnCtOnTmOutFlHHtVd; /* output Fan contactor on time-out failure and high heatsink temp valid, waiting time */
MWT_REAL PARTDP_PI_DcLnErfMax; /* output DC-link earth fault detection, level max */
MWT_BOOL PARTDP_L_DsTrpLvSvDcLnErf; /* output Disable trip level supervision of earth fault current */
MWT_BOOL PARTDP_L_DsErfDet; /* output Disable earth fault detection */
MWT_REAL PARTDP_PX_ErfCntThr; /* output Earth fault counter threshold */
MWT_REAL PARTAP_PI_DfInFltMax2qc; /* output Filtered differential input current max level (2QC) */
MWT_TIME PARTAP_PT_DfInFltMaxDy2qc; /* output Filtered differential input current max level delay (2QC) */
MWT_BOOL PARTAP_L_EnErfSvIDf2qc; /* output Enable earth fault supervision (2QC) */
MWT_BOOL PARTAP_L_PraEnErfSvIDf2qc; /* output Protective action enable earth fault supervision (2QC) */
MWT_REAL PARTDP_PT_2qcCal; /* output Calibration time for 2QC signals */
MWT_REAL PARTDP_PT_3PhCal; /* output Calibration time for 3-phase inverter signals */
MWT_TIME PARTAP_PT_EnIPhCalDy; /* output Time delay to enable calibration of phase currents after fulfilled criteria */
MWT_REAL PARTDP_PI_PhCalOsMax_Rw; /* output Phase current calibration, maximum offset */
MWT_REAL PARTDP_PI_PhCalRipMax_Rw; /* output Phase current calibration, maximum ripple */
MWT_TIME PARTAP_PT_EnUDcLkCalDy; /* output Time delay to enable calibration of DC-link voltage after fulfilled criteria */
MWT_REAL PARTDP_PU_DcLkCalOsMax_Rw; /* output DC-link voltage calibration, maximum offset */
MWT_REAL PARTDP_PU_DcLkCalRipMax_Rw; /* output DC-link voltage calibration, maximum ripple */
MWT_TIME PARTAP_PT_EnU3PhCalDy; /* output Time delay to enable calibration of 3-phase output load voltage after fulfilled criteria
*/
MWT_REAL PARTDP_PU_3PhCalOsMax_Rw; /* output 3-phase output load voltage calibration, maximum offset */
MWT_REAL PARTDP_PU_3PhCalRipMax_Rw; /* output 3-phase output load voltage calibration, maximum ripple */
MWT_TIME PARTAP_PT_EnIPhInCalDy; /* output Time delay to enable calibration of AC input phase current after fulfilled criteria */
MWT_REAL PARTDP_PI_PhInCalOsMax_Rw; /* output AC input phase current calibration, maximum offset */
MWT_REAL PARTDP_PI_PhInCalRipMax_Rw; /* output AC input phase current calibration, maximum ripple */
MWT_TIME PARTAP_PT_EnIDfInCalDy; /* output Time delay to enable calibration of differential current after fulfilled criteria */
MWT_REAL PARTDP_PI_DfInCalOsMax_Rw; /* output Differential current, maximum offset */
MWT_REAL PARTDP_PI_DfInCalRipMax_Rw; /* output Differential current, maximum ripple */
MWT_REAL PARTDP_PI_RctCalOsMax_Rw; /* output HPP rectifier current calibration, maximum offset */
MWT_REAL PARTDP_PI_RctCalRipMax_Rw; /* output HPP rectifier current calibration, maximum ripple */
MWT_UINT PARTAP_PX_CalFl; /* output Calibration supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_CalFl; /* output Calibration supervision, time window for monitoring the number of failures */
MWT_REAL PARTAP_PU_DcLkOnGduPSp; /* output Maximum DC-link voltage to switch on GDU power supply */
MWT_TIME PARTAP_PT_OnGduPSpDy; /* output Switch on GDU power supply, delay */
MWT_REAL PARTDP_PX_AnMmDfMax; /* output Maximum difference between A/D-converters, ratio of full scale */
MWT_REAL PARTDP_PT_AnMmDfDy; /* output Detection time, maximum difference between fast A/D-converters */
MWT_BOOL PARTDP_L_FSgSvIgbtPoaEn; /* output Enable switching frequency supervision 3-phase inverter, switching command */
MWT_BOOL PARTDP_L_FSgSvIgbt2qcEn; /* output Enable switching frequency supervision 2QC, switching command */
MWT_BOOL PARTDP_L_FSgSvGduPoaEn; /* output Enable switching frequency supervision 3-phase inverter, switching feedback */
MWT_BOOL PARTDP_L_FSgSvGdu2qcEn; /* output Enable switching frequency supervision 2QC, switching feedback */
MWT_REAL PARTDP_PX_FSgSvDvMax; /* output Switching frequency supervision, max deviation, ratio of switching frequency */
MWT_BOOL PARTDP_L_EnIRctFpgaSv; /* output Enable HPP rectifier overcurrent protection, level max */
MWT_REAL PARTDP_PI_RctMax; /* output HPP rectifier overcurrent protection, level max */
MWT_UDINT PARTDP_PT_IRctMaxDy; /* output HPP rectifier overcurrent protection, detection time for level max */
MWT_BOOL PARTAP_L_EnIRctBalSv; /* output Enable HPP rectifier current unbalance protection */
MWT_REAL PARTAP_PI_RctBalSvMax; /* output HPP rectifier current unbalance protection, level max */
MWT_TIME PARTAP_PT_IRctBalSvDy; /* output HPP rectifier current unbalance protection, detection time, level max */
MWT_BOOL PARTAP_L_2qcEn; /* output Enable 2QC operation */
MWT_BOOL PARTDP_L_2qcUDcLk2Mm; /* output Use DC-link voltage 2 for DC-link voltage control */
MWT_REAL PARTDP_PN_UDcLkRef; /* output DC-link voltage reference, filter constant for LP-filter */
MWT_REAL PARTAP_PI_PhInRmsHgh2; /* output AC input phase current RMS high 2 level */
MWT_TIME PARTAP_PT_IPhInRmsHgh2Dy; /* output AC Input phase current RMS high 2 level, delay */
MWT_REAL PARTAP_PI_PhInRmsHgh1; /* output AC input phase current RMS high 1 level */
MWT_TIME PARTAP_PT_IPhInRmsHgh1Dy; /* output AC Input phase current RMS high 1 level, delay */
MWT_REAL PARTDP_PT_SiPhBc2qcTmWnd1; /* output Single phase blocking (SPB) supervision 2QC, time window 1 */
MWT_DINT PARTDP_PX_SiPhBc2qcMaxWnd1; /* output Single Phase Blocking (SPB) supervision 2QC, maximum number of SPB within time window 1
*/
MWT_REAL PARTDP_PT_SiPhBc2qcTmWnd2; /* output Single Phase Blocking (SPB) supervision 2QC, time window 2 */
MWT_DINT PARTDP_PX_SiPhBc2qcMaxWnd2; /* output Single Phase Blocking (SPB) supervision 2QC, maximum number of time window 1 within time
window 2 */
MWT_REAL PARTDP_PI_PhIn2qcMax; /* output AC input phase overcurrent protection, level max */
MWT_UDINT PARTDP_PT_IPhIn2qcMaxDy; /* output AC input phase overcurrent protection, detection time for level max */
MWT_BOOL PARTAP_L_EnPBalSv; /* output Enable power balance supervision */
MWT_REAL PARTAP_PP_BalSv; /* output Maximum difference between 2QC input power and output power */
MWT_TIME PARTAP_PT_PBalSv; /* output Power balance supervision, detection time */
MWT_UINT PARTAP_PX_UBtMmFl; /* output Battery voltage measurement supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_UBtMmFl; /* output Battery voltage measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IPhMmFl; /* output Phase current measurement supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_IPhMmFl; /* output Phase current measurement supervision, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_U3PhMmFl; /* output 3-phase output load voltage measurement supervision, maximum number of allowed failures
within a fixed time window */
MWT_TIME PARTAP_PT_U3PhMmFl; /* output 3-phase output load voltage measurement supervision, time window for monitoring the
number of failures */
MWT_UINT PARTAP_PX_IPhInMmFl; /* output AC input phase current measurement supervision, maximum number of allowed failures within
a fixed time window */
MWT_TIME PARTAP_PT_IPhInMmFl; /* output AC input phase current measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UPhInMmFl; /* output AC input phase voltage measurement supervision, maximum number of allowed failures within
a fixed time window */
MWT_TIME PARTAP_PT_UPhInMmFl; /* output AC input phase voltage measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UDcLkMmFl; /* output DC-link voltage measurement supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_UDcLkMmFl; /* output DC-link voltage measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IDfInMmFl; /* output Differential current measurement supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IDfInMmFl; /* output Differential current measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UDcLkDfFl; /* output DC-link voltage difference supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_UDcLkDfFl; /* output DC-link voltage difference supervision, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_IBtCgMmFl; /* output Battery charger current measurement supervision, maximum number of allowed failures
within a fixed time window */
MWT_TIME PARTAP_PT_IBtCgMmFl; /* output Battery charger current measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IBtMmFl; /* output Battery current measurement supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IBtMmFl; /* output Battery current measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IRctMmFl; /* output HPP rectifier current measurement supervision, maximum number of allowed failures within
a fixed time window */
MWT_TIME PARTAP_PT_IRctMmFl; /* output HPP rectifier current measurement supervision, time window for monitoring the number of
failures */
MWT_REAL PARTDP_PT_3PhMmSvRipDy; /* output Delay to detect ripple failure of measured 3-phase converter signals */
MWT_REAL PARTDP_PT_2qcMmSvRipDy; /* output Delay to detect ripple failure of measured 2QC signals */
MWT_REAL PARTDP_PT_BtCpMmSvRipDy; /* output Delay to detect ripple failure of measured BtCp signals */
MWT_UINT PARTAP_PX_GduFbOnPoaFl; /* output Both GDU feedback shows on in POA, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_GduFbOnPoaFl; /* output Both GDU feedback shows on in POA, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_GduFbSvPoa; /* output GDU feedback supervision POA, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_GduFbSvPoa; /* output GDU feedback supervision POA, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_GduFbSvOvp; /* output GDU feedback supervision OVP, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_GduFbSvOvp; /* output GDU feedback supervision OVP, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_GduFbSv2qc; /* output GDU feedback supervision 2QC, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_GduFbSv2qc; /* output GDU feedback supervision 2QC, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvUDcLk; /* output DC-link overvoltage protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_OvUDcLk; /* output DC-link overvoltage protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_UnUDcLk; /* output DC-link undervoltage protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_UnUDcLk; /* output DC-link undervoltage protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvIPh; /* output Phase overcurrent protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_OvIPh; /* output Phase overcurrent protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_IPhTmWndFl; /* output Supervision of phase current SPB, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_IPhTmWndFl; /* output Supervision of phase current SPB, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_IPhClTmOut; /* output AC current limitation time-out supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IPhClTmOut; /* output AC current limitation time-out supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IPhClRmsTmFl; /* output RMS phase current limitation time-out failure, maximum number of allowed failures within
a fixed time window */
MWT_TIME PARTAP_PT_IPhClRmsTmFl; /* output RMS phase current limitation time-out failure, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IPhClTmWnd1Fl; /* output Too many RMS phase current limitations in time window, maximum number of allowed failures
within a fixed time window */
MWT_TIME PARTAP_PT_IPhClTmWnd1Fl; /* output Too many RMS phase current limitations in time window, time window for monitoring the
number of failures */
MWT_UINT PARTAP_PX_IPhDcFl; /* output High DC-current component in phase currents, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IPhDcFl; /* output High DC-current component in phase currents, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IPhBalFl; /* output Phase current unbalance protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_IPhBalFl; /* output Phase current unbalance protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_CtFbSvFl; /* output Contactor supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_CtFbSvFl; /* output Contactor supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_AuLdCtFbSvFl; /* output Auxiliary load contactor supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_AuLdCtFbSvFl; /* output Auxiliary load contactor supervision, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_UDcLkChSv; /* output DC-link voltage check during DC-link charging, maximum number of allowed failures within
a fixed time window */
MWT_TIME PARTAP_PT_UDcLkChSv; /* output DC-link voltage check during DC-link charging, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UDcLkDhSv; /* output DC-link voltage check during DC-link discharging, maximum number of allowed failures
within a fixed time window */
MWT_TIME PARTAP_PT_UDcLkDhSv; /* output DC-link voltage check during DC-link discharging, time window for monitoring the number
of failures */
MWT_UINT PARTAP_PX_OvpFcTsFl; /* output OVP test during DC-link charging, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_OvpFcTsFl; /* output OVP test during DC-link charging, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvpRsTpFl; /* output OVP resistor temperature protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_OvpRsTpFl; /* output OVP resistor temperature protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_SrCtISv; /* output Check of current through separation contactor, maximum number of allowed failures within
a fixed time window */
MWT_TIME PARTAP_PT_SrCtISv; /* output Check of current through separation contactor, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_3PhSzFl; /* output Synchronization to 3-phase bus, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_3PhSzFl; /* output Synchronization to 3-phase bus, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_PBalFl; /* output Power balance supervision, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_PBalFl; /* output Power balance supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvUPhInRmsFl; /* output AC input phase overvoltage protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_OvUPhInRmsFl; /* output AC input phase overvoltage protection, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_UnUPhInRmsFl; /* output AC input phase undervoltage protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_UnUPhInRmsFl; /* output AC input phase undervoltage protection, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_OvIPhIn_2qc; /* output AC input phase overcurrent protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_OvIPhIn_2qc; /* output AC input phase overcurrent protection, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_OvIPhInRms; /* output AC input phase phase current supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_OvIPhInRms; /* output AC input phase phase current supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IPhInTmWndFl; /* output Supervision of AC input phase current SPB, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IPhInTmWndFl; /* output Supervision of AC input phase current SPB, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IDfInErf; /* output Earth fault detection (2QC), maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_IDfInErf; /* output Earth fault detection (2QC), time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvUBtFl; /* output Battery overvoltage protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_OvUBtFl; /* output Battery overvoltage protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_UnUBtFl; /* output Battery undervoltage protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_UnUBtFl; /* output Battery undervoltage protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvIBtCg; /* output Battery charger overcurrent protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_OvIBtCg; /* output Battery charger overcurrent protection, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_IBtClTmOut; /* output Battery charger current limitation time supervision, maximum number of allowed failures
within a fixed time window */
MWT_TIME PARTAP_PT_IBtClTmOut; /* output Battery charger current limitation time supervision, time window for monitoring the
number of failures */
MWT_UINT PARTAP_PX_DcCrBrTp; /* output DC circuit breaker supervision, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_DcCrBrTp; /* output DC circuit breaker supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_FnCrFl; /* output Fan power circuit supervision, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_FnCrFl; /* output Fan power circuit supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_HTfSvMax; /* output Transformer overtemperature protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_HTfSvMaxTmWn; /* output Transformer overtemperature protection, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_LngTmOvLd; /* output Long-term overload protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_LngTmOvLd; /* output Long-term overload protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_HBtSvMax; /* output Battery overtemperature protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_HBtSvMaxTmWn; /* output Battery overtemperature protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_HNteArSvMax; /* output Internal air overtemperature protection, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_HNteArSvMaxTmWn; /* output Internal air overtemperature protection, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_HNdSvMax; /* output Inductor overtemperature protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_HNdSvMaxTmWn; /* output Inductor overtemperature protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_FSgFl; /* output IGBT switching frequency supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_FSgFl; /* output IGBT switching frequency supervision, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_PSpFl; /* output Power supply unit failure detection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_PSpFl; /* output Power supply unit failure detection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_MvbWdgFl; /* output MVB supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_MvbWdgFl; /* output MVB supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_AdcMmFl; /* output AD-converter supervision, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_AdcMmFl; /* output AD-converter supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_DspOvLdFl; /* output DSP overload and DSP stack supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_DspOvLdFl; /* output DSP overload and DSP stack supervision, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_Nte15VFl; /* output Internal ¡À15V supervision, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_Nte15VFl; /* output Internal ¡À15V supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_25MHzSvFl; /* output 25 MHz clock supervision, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_25MHzSvFl; /* output 25 MHz clock supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_DspWdAlm; /* output DSP watchdog supervision, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_DspWdAlm; /* output DSP watchdog supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_DspFpgaComFl; /* output DSP-FPGA communication failure, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_DspFpgaComFl; /* output DSP-FPGA communication failure, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvIRct; /* output HPP rectifier overcurrent protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_OvIRct; /* output HPP rectifier overcurrent protection, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_IRctBalSv; /* output HPP rectifier current unbalance protection, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IRctBalSv; /* output HPP rectifier current unbalance protection, time window for monitoring the number of
failures */
MWT_BOOL PARTAP_L_PrlAcm; /* output Select Parallel ACM operation */
MWT_TIME PARTAP_PT_CvOpMn; /* output Minimum time between activations */
MWT_TIME PARTAP_PT_SfSdCvSa; /* output Minimum time from Soft shutdown request to activation */
MWT_TIME PARTAP_PT_FsSdCvSa; /* output Minimum time from Fast shutdown request to activation */
MWT_TIME PARTAP_PT_PrSdCvSa; /* output Minimum time from Protective shutdown request to charging */
MWT_UINT PARTAP_PX_NteCoFl; /* output Internal cooling failure, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_NteCoFl; /* output Internal cooling failure, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_TpSnFl; /* output Temperature sensor failure, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_TpSnFl; /* output Temperature sensor failure failure, time window for monitoring the number of failures */
MWT_TIME PARTAP_PT_AyActMtFn; /* output Time delay to start fan when auxiliary voltage is available */
MWT_REAL PARTAP_PV_ExtFnTnHgh; /* output High vehicle speed, upper level */
MWT_REAL PARTAP_PV_ExtFnTnLow; /* output High vehicle speed, lower level */
MWT_REAL PARTAP_PH_HtFuSpeOnHgh; /* output Heat sink temp 1/1-speed on, high vehicle speed */
MWT_REAL PARTAP_PH_HtFuSpeOfHgh; /* output Heat sink temp 1/1-speed off, high vehicle speed */
MWT_REAL PARTAP_PH_HtFuSpeOnLow; /* output Heat sink temp 1/1-speed on, low vehicle speed */
MWT_REAL PARTAP_PH_HtFuSpeOfLow; /* output Heat sink temp 1/1-speed off, low vehicle speed */
MWT_REAL PARTAP_PH_NteArFuSpeOnHgh; /* output Internal air temp 1/1-speed on, high vehicle speed */
MWT_REAL PARTAP_PH_NteArFuSpeOfHgh; /* output Internal air temp 1/1-speed off, high vehicle speed */
MWT_REAL PARTAP_PH_NteArFuSpeOnLow; /* output Internal air temp 1/1-speed on, low vehicle speed */
MWT_REAL PARTAP_PH_NteArFuSpeOfLow; /* output Internal air temp 1/1-speed off, low vehicle speed */
MWT_TIME PARTAP_PT_ExtFnFl; /* output Allowed time between external fan order and acknowledge */
MWT_TIME PARTAP_PT_DyHfFuExtFnSpe; /* output Time delay 1/2-1/1-speed order external fan */
MWT_TIME PARTAP_PT_DyFuHfExtFnSpe; /* output Time delay 1/1-1/2-speed order external fan */
MWT_TIME PARTAP_PT_HfExtFnSpeMn; /* output Minimum time between 1/2-speed orders external fan */
MWT_BOOL PARTAP_L_ExtTwoSpFn; /* output Two speed external fan in use */
MWT_REAL PARTAP_PH_BrdFuSpeOfLow; /* output DCU board temp 1/1-speed off, low vehicle speed */
MWT_REAL PARTAP_PH_BrdFuSpeOnLow; /* output DCU board temp 1/1-speed on, low vehicle speed */
MWT_REAL PARTAP_PH_BrdFuSpeOfHgh; /* output DCU board temp 1/1-speed off, high vehicle speed */
MWT_REAL PARTAP_PH_BrdFuSpeOnHgh; /* output DCU board temp 1/1-speed on, high vehicle speed */
MWT_TIME PARTAP_PT_FnOfDy; /* output Delay time to keep fan enabled after activation order has withdrawn */
MWT_REAL PARTAP_PH_NteTpDfMax; /* output Temperature difference to indicate internal cooling problem */
MWT_TIME PARTAP_PT_NteTpDf; /* output Time filter for internal cooling problem supervision */
MWT_BOOL PARTAP_L_SfSdNteCoFl; /* output Select Soft Shutdown in case of internal cooling failure */
MWT_BOOL PARTAP_L_BcDcuBrdTpNotVd; /* output Select to block converter at faulty board temperature sensor */
MWT_BOOL PARTAP_L_BcHtCoTpNotVd; /* output Select to block converter at faulty heat sink temperature sensor */
MWT_BOOL PARTAP_L_BcNteArTpNotVd; /* output Select to block converter at faulty conv. air temperature sensor */
MWT_REAL PARTAP_PH_HtCoOs; /* output Temp. offset added to external heatsink at faulty internal heatsink measurement */
MWT_REAL PARTAP_PH_DcuBrdOs; /* output DCU board temperature offset for internal air calculation */
MWT_BOOL PARTAP_L_MltTpSnSvEn; /* output Multiple temperature sensor supervision enabled */
MWT_TIME PARTAP_PT_TpSnDy; /* output Delay time for multiple sensor failure */
MWT_INT PARTAP_PX_IdPrSdPcl; /* output Event identification (start) of DSP/FPGA PrSd process client */
MWT_INT PARTAP_PX_IdFsSdPcl; /* output Event identification (start) of DSP/FPGA FsSd process client */
MWT_INT PARTAP_PX_IdSfSdPcl; /* output Event identification (start) of DSP/FPGA SfSd process client */
MWT_INT PARTAP_PX_IdPrBcPcl; /* output Event identification (start) of DSP/FPGA PrBc process client */
MWT_INT PARTAP_PX_IdClPcl; /* output Event identification (start) of control process client */
MWT_INT PARTAP_PX_IdHwPcl; /* output Event identification (start) of hardware process client */
MWT_INT PARTAP_PX_IdTpPcl; /* output Event identification (start) of temperature process client */
MWT_REAL PARTAP_PI_BtCpThr; /* output Battery charger current level to enable certain protections at blocked battery chopper */
MWT_TIME PARTAP_PT_BtCpCurBc; /* output Time for battery chopper current to fall after blocking of battery chopper */
MWT_REAL PARTAP_PT_BtCpSfBc; /* output Battery chopper soft blocking time */
MWT_TIME PARTAP_PT_BtCpAvTm; /* output Battery chopper activation cycle time */
MWT_REAL PARTDP_PX_KpIBtCpCl; /* output Proportional part battery chopper current control */
MWT_REAL PARTDP_PX_KiIBtCpCl; /* output Integrational part battery chopper current control */
MWT_REAL PARTDP_PF_BtCpSg; /* output Battery chopper switching frequency */
MWT_REAL PARTDP_PI_IBtCp_Max; /* output Battery chopper current, maximum value */
MWT_REAL PARTDP_PN_IEstBtCg_Flt; /* output Estimated battery charger current, filter constant for LP-filter */
MWT_REAL PARTDP_PN_UBtCp_Flt; /* output Battery voltage, filter constant for LP-filter */
MWT_BOOL PARTAP_L_EnCtSm; /* output Enable simulated contactor feedback in converter simulation mode */
MWT_INT PARTGP_NX_DevCodFpga2; /* output Device code for the FPGA2
0 = HTA
1 = A
2 = AL
4 = M-H
5 = M-ML
6 = M-LIN
7 = 4QC
8 = SD
9 = SU
10 = TL */
MWT_INT PARTGP_NX_VerCodFd1Fpga2; /* output Version code for field 1, Fundamental change (version 1-15) */
MWT_INT PARTGP_NX_VerCodFd2Fpga2; /* output Version code for field 2, Major functional change (version 0-31) */
MWT_INT PARTGP_NX_VerCodFd3Fpga2; /* output Version code for field 3, Error correction, backward compatible (version 0-127) */
MWT_INT PARTGP_NX_VerCodFd4Fpga2; /* output Version code for field 4, Development version (version 0-127) */
MWT_INT PARTGP_NX_VerCodFd5Fpga2; /* output Version code for field 5,Project specific version based on DCU2 product (version 0-15) */
MWT_INT PARTGP_NX_DevCodDsp; /* output Device code for the DSP
0 = HTA
1 = A
2 = AL
4 = M-H
5 = M-ML
6 = M-LIN
7 = 4QC
8 = SD
9 = SU
10 = TL */
MWT_INT PARTGP_NX_VerCodFd1Dsp; /* output Version code for field 1, Fundamental change (version 1-15) */
MWT_INT PARTGP_NX_VerCodFd2Dsp; /* output Version code for field 2, Major functional change (version 0-31) */
MWT_INT PARTGP_NX_VerCodFd3Dsp; /* output Version code for field 3, Error correction, backward compatible (version 0-127) */
MWT_INT PARTGP_NX_VerCodFd4Dsp; /* output Version code for field 4, Development version (version 0-127) */
MWT_INT PARTGP_NX_VerCodFd5Dsp; /* output Version code for field 5,Project specific version based on DCU2 product (version 0-15) */
MWT_REAL PARTDP_PU_BtCpClFl; /* output Voltage threshold for battery chopper control failure, block battery chopper */
MWT_REAL PARTDP_PT_BtCpClFlDy; /* output Time delay for battery chopper control failure, block battery chopper */
MWT_BOOL PARTDP_L_3PhRndEn; /* output Enable randomization of 3-phase inverter switching frequency */
MWT_REAL PARTDP_PI_BtCgCalOsMax_Rw; /* output Battery charger calibration offset maximum */
MWT_INT PARTGP_XX_ParSet; /* output Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef; /* output DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl; /* output DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl; /* output DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn; /* output Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0; /* output Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1; /* output Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2; /* output Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1; /* output Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim; /* output DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2; /* output Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf; /* output DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn; /* output Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl; /* output AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl; /* output AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl; /* output AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl; /* output AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl; /* output AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin; /* output AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim; /* output DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn; /* output AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul; /* output AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf; /* output AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy; /* output AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy; /* output Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom; /* output Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin; /* output AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy; /* output Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin; /* output AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn; /* output Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy; /* output Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy; /* output Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4; /* output AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax; /* output AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy; /* output AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow; /* output AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy; /* output AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin; /* output AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy; /* output AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt; /* output AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt; /* output AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt; /* output 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom; /* output Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms; /* output Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa; /* output Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa; /* output Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo; /* output Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo; /* output Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds; /* output Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a
file in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh; /* output DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl; /* output Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl; /* output Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax; /* output DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8; /* output DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7; /* output DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin; /* output DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow; /* output DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax; /* output Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg; /* output 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl; /* output Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08; /* output Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07; /* output Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp; /* output Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En; /* output Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt; /* output 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp; /* output Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy; /* output Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready
*/
MWT_REAL PARTAP_PU_UF3PhSzRdy; /* output Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs; /* output Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph; /* output Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe; /* output 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm; /* output 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm; /* output 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be =0),
shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe; /* output Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm; /* output Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh; /* output Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax; /* output Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3; /* output 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4; /* output 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt; /* output Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg; /* output Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt; /* output Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl; /* output Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl; /* output Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim; /* output Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim; /* output Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom; /* output Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo; /* output 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax; /* output Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp; /* output Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn; /* output Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn; /* output Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl; /* output Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv; /* output Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy; /* output Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy; /* output Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax; /* output Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt; /* output Phase current, real and imaginary part, fixed projection, usedfor extracting DC component
from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax; /* output Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh; /* output Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst; /* output Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc; /* output Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv; /* output Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef; /* output Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim; /* output Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4; /* output Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2; /* output DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1; /* output DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1; /* output DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt; /* output Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb; /* output DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb; /* output DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy; /* output Battery current limit high, delay */
MWT_BOOL PARTGP_L_DcLnIMmEn; /* output DC line current measurement enabled (only used in MCU2G) */
MWT_REAL PARTGP_PU_BuInTsHghURef; /* output Burn in test voltage reference limit */
MWT_REAL PARTGP_PX_BuInTsCpIKp; /* output Burn in test chopper controller gain */
MWT_REAL PARTGP_PX_BuInTsCpIT; /* output Burn in test chopper controller integration time */
MWT_REAL PARTGP_PX_BuInTsHghBrCpDtyCy; /* output Burn in test brake chopper duty cycle limit */
MWT_REAL PARTGP_PX_BuInTsIKp; /* output Burn in test current controller gain */
MWT_REAL PARTGP_PX_BuInTsIT; /* output Burn in test current controller integration time */
MWT_REAL PARTGP_PI_BrCpRefIBrRs; /* output Brake resistor current reference for Brake chopper test */
MWT_REAL PARTGP_PI_BrCpRefIDc; /* output Line current reference for Brake chopper test */
MWT_REAL PARTGP_PI_BrCpTsOkIBrRs; /* output Brake resistor current limit for Brake chopper test OK */
MWT_REAL PARTGP_PI_BrCpTsOkIDc; /* output Line current limit for Brake chopper test OK */
MWT_REAL PARTGP_PR_Cp; /* output Brake chopper resistance value */
MWT_TIME PARTGP_PT_BrCpTs; /* output Brake chopper test time */
MWT_REAL PARTGP_PU_BrCpTsRef; /* output Voltage reference for chopper control ratio */
MWT_REAL PARTGP_PI_BuInTsCpRef02; /* output Burn in test Line current reference break point 2 */
MWT_REAL PARTGP_PI_BuInTsCpRef03; /* output Burn in test Line current reference break point 3 */
MWT_REAL PARTGP_PI_BuInTsRef01; /* output Burn in test current reference break point 1 */
MWT_REAL PARTGP_PI_BuInTsRef02; /* output Burn in test current reference break point 2 */
MWT_REAL PARTGP_PI_BuInTsRef03; /* output Burn in test current reference break point 3 */
MWT_REAL PARTGP_PI_BuInTsRef04; /* output Burn in test current reference break point 4 */
MWT_REAL PARTGP_PI_BuInTsRef05; /* output Burn in test current reference break point 5 */
MWT_REAL PARTGP_PI_BuInTsRef06; /* output Burn in test current reference break point 6 */
MWT_REAL PARTGP_PI_BuInTsRef07; /* output Burn in test current reference break point 7 */
MWT_REAL PARTGP_PI_BuInTsRef08; /* output Burn in test current reference break point 8 */
MWT_REAL PARTGP_PT_BuInTsCpRef01; /* output Burn in test Line current reference, time break point 1 */
MWT_REAL PARTGP_PT_BuInTsCpRef02; /* output Burn in test Line current reference, time break point 2 */
MWT_REAL PARTGP_PT_BuInTsCpRef03; /* output Burn in test Line current reference, time break point 3 */
MWT_REAL PARTGP_PT_BuInTsCpRef04; /* output Burn in test Line current reference, time break point 4 */
MWT_REAL PARTGP_PT_BuInTsDtyCyTm; /* output Burn in test duty cycle time */
MWT_REAL PARTGP_PT_BuInTsRef01; /* output Burn in test time break point 1 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef02; /* output Burn in test time break point 2 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef03; /* output Burn in test time break point 3 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef04; /* output Burn in test time break point 4 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef05; /* output Burn in test time break point 5 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef06; /* output Burn in test time break point 6 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef07; /* output Burn in test time break point 7 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef08; /* output Burn in test time break point 8 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsTm; /* output Burn in test total time 1.0=1 s */
MWT_BOOL PARTGP_L_EnChDcLkSiPoTs; /* output Allow DC-link charging at single position test */
MWT_REAL PARTGP_PI_CmtTsRef; /* output Current reference for Commutation test */
MWT_REAL PARTGP_PI_CmtTsTrp; /* output Commutation test trip level */
MWT_REAL PARTGP_PI_DefTrp; /* output Default phase current trip level */
MWT_REAL PARTGP_PI_HghLodTsRef; /* output Current reference for High load test */
MWT_REAL PARTGP_PI_HghLodtsTrp; /* output High load test trip level */
MWT_REAL PARTGP_PI_LwLodTsTrp; /* output Low load test trip level */
MWT_REAL PARTGP_PI_ManLodtsTrp; /* output Manual load test trip level */
MWT_TIME PARTGP_PT_CmtTsDy; /* output Test activation delaytime commutation test */
MWT_TIME PARTGP_PT_CmtTsRefRmp; /* output Test activation time commutation test */
MWT_TIME PARTGP_PT_HghLodTsAvTm; /* output Test activation time High load test */
MWT_TIME PARTGP_PT_HghLodTsDy; /* output Test activation delaytime High load test */
MWT_TIME PARTGP_PT_LwLodTsAvTm; /* output Test activation time Low load test */
MWT_TIME PARTGP_PT_LwLodTsDy; /* output Test activation delaytime Low load test */
MWT_TIME PARTGP_PT_ManLodTsAvTm; /* output Test activation time Manual load test */
MWT_TIME PARTGP_PT_ManLodTsDy; /* output Test activation delay time Manual load test */
MWT_REAL PARTGP_PU_CmtTsHghRef; /* output High voltage level for Commutation test */
MWT_REAL PARTGP_PU_DcLkPctDdCmp01; /* output Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp02; /* output Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp03; /* output Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp04; /* output Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_HghLodTsHghRef; /* output High voltage level for High load test */
MWT_REAL PARTGP_PU_LwLodTsRef; /* output Voltage reference for Low load test */
MWT_REAL PARTGP_PU_ManLodTsRef; /* output Voltage reference for Manual load test */
MWT_REAL PARTGP_PU_RefPctDdCmp01; /* output Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp02; /* output Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp03; /* output Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp04; /* output Used to calculate voltage compensation due to dead time */
MWT_TIME PARTGP_PT_IgbtAvTsTm; /* output IGBT Activation test time */
MWT_REAL PARTGP_PI_HghLodTsDfMax; /* output Max phase current difference in high load test */
MWT_REAL PARTGP_PI_HghLodTsIRefDfMax; /* output Max difference between phase and reference current in high load test */
MWT_REAL PARTGP_PI_LwLodTs_Max; /* output Max phase current in low load test */
MWT_REAL PARTGP_PI_LwLodTs_Min; /* output Min phase current in low load test */
MWT_TIME PARTGP_PT_LwLodTs; /* output Low load test time */
MWT_REAL PARTGP_PU_DCLkMaxLwUTs; /* output Maximum DC-link voltage for low voltage test (Single position test and digital output
test) */
MWT_TIME PARTGP_PT_IndPhCpAv_Max; /* output Max time for chopper activation */
MWT_REAL PARTGP_PU_IndPhTsRef; /* output Voltage reference for chopper control */
MWT_REAL PARTGP_PU_PsvDhTmMmSa; /* output Time measurement starts at this voltage */
MWT_REAL PARTGP_PU_PsvDhTmMmSo; /* output Time measurement stops at this voltage */
MWT_INT PARTGP_PX_PsvDhTm_Max; /* output Maximum allowable discharge time */
MWT_INT PARTGP_PX_PsvDhTm_Min; /* output Minimum allowable discharge time */
MWT_REAL PARTGP_PX_CmtTsPctCl; /* output Current control time constant for Commutation test */
MWT_REAL PARTGP_PX_CmtTsPctClKp; /* output Current control Proportional gain for Commutation test */
MWT_REAL PARTGP_PX_CmtTsRefRmp; /* output Derivative for Iref ramp for Commutation test */
MWT_REAL PARTGP_PX_HghLodTsPctCl; /* output Current control time constant for High load test */
MWT_REAL PARTGP_PX_HghLodTsPctClKp; /* output Current control Proportional gain for High load test */
MWT_REAL PARTGP_PX_HghLodTsRefRmp; /* output Derivative for Iref ramp for High load test */
MWT_REAL PARTGP_PX_LwLodTsRefRmp; /* output Derivative for Uref ramp for Low load test */
MWT_REAL PARTGP_PX_ManLodTsRefRmp; /* output Derivative for Uref ramp for Manual load test */
MWT_REAL PARTGP_PF_BuInTsRef; /* output Frequency reference at burn in test. */
} TYPE_PAR_IF;

#ifdef __cplusplus
extern "C" {
#endif

void PAR(TYPE_PAR_IF *interface);

#ifdef __cplusplus
}
#endif

#endif /* PAR_H_ */
