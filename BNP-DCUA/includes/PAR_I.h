/* ------------------------------------------------------------------------
Module : PAR_I
Abstract : Definition of initial values for resource PAR
Created : PC/P-Tool version 2.1.1.32 at 2017-01-19, 11:18:25
Project : DCUA MCX Gen 3 Appl. Engineer : PP4 MCX Team
Device : MCU/A Par. version : 0.0.0.0
Spare : -
Spare : -
Spare : -
Remarks : Import this file in MTPE into a resource named PAR
------------------------------------------------------------------------
Copyright : (c) 2006 Bombardier Transportation
------------------------------------------------------------------------ */
#ifndef PAR_I_H
#define PAR_I_H
#include "typedef.h"
/* independent parameters of PAR
*/
MWT_UINT PARTAP_NX_ParVer_GI = 0 ; /* initial value: DCU/A parameter version */
MWT_BOOL PARTGP_B_EnTxt_GI = TRUE ; /* initial value: Enable termtext output */
MWT_BOOL PARTGP_L_MmIPh3_GI = TRUE ; /* initial value: If TRUE: Phase 3 is measured If FALSE: Phase 2 is measured
*/
MWT_BOOL PARTGP_L_EnPctPrAct_GI = TRUE ; /* initial value: Enable line trip test, digital output test and test of pull-wires during active protective
action */
MWT_BOOL PARTGP_L_LtrSvEn_GI = TRUE ; /* initial value: Line trip supervision enabled */
MWT_TIME PARTGP_PT_DiInFiBase_GI = 32 ; /* initial value: Filter time constant for digital inputs Base I/O */
MWT_TIME PARTGP_PT_DiInFiMpp_GI = 32 ; /* initial value: Filter time constant for digital inputs LPP/MPP */
MWT_TIME PARTGP_PT_DiInFi43_GI = 32 ; /* initial value: Filter time constant for digital input 43 */
MWT_TIME PARTGP_PT_TrSafFl_GI = 50 ; /* initial value: Filter time for traction safe fault */
MWT_TIME PARTGP_PT_FiSpeSnSpFl_GI = 100 ; /* initial value: Filter time for speed sensor supply faults. Only valid for DCU2/M */
MWT_UINT PARTGP_P_NoHwFl_Max_GI = 2 ; /* initial value: Max number of hardware faults */
MWT_TIME PARTGP_PT_WiFl_GI = 1800000 ; /* initial value: Time window for counting faults */
MWT_BOOL PARTGP_L_TrpLvTsEn_GI = TRUE ; /* initial value: Enable Trip level test */
MWT_BOOL PARTGP_L_EnAi05_GI = TRUE ; /* initial value: Input AI05 is used. */
MWT_REAL PARTGP_PH_Ai05Mn_GI = -50.0 ; /* initial value: Min temperature analog in 05 */
MWT_REAL PARTGP_PH_Ai05Mx_GI = 100.0 ; /* initial value: Max temperature analog in 05 */
MWT_BOOL PARTGP_L_EnAi06_GI = TRUE ; /* initial value: Input AI06 is used. */
MWT_REAL PARTGP_PH_Ai06Mn_GI = -50.0 ; /* initial value: Min temperature analog in 06 */
MWT_REAL PARTGP_PH_Ai06Mx_GI = 100.0 ; /* initial value: Max temperature analog in 06 */
MWT_REAL PARTGP_PH_Ai07Mn_GI = -100.0 ; /* initial value: Min temperature analog in 07 */
MWT_REAL PARTGP_PH_Ai07Mx_GI = 500.0 ; /* initial value: Max temperature analog in 07 */
MWT_REAL PARTGP_PH_Ai08Mn_GI = -50.0 ; /* initial value: Min temperature analog in 08 */
MWT_REAL PARTGP_PH_Ai08Mx_GI = 500.0 ; /* initial value: Max temperature analog in 08 */
MWT_BOOL PARTGP_L_EnAi21_GI = FALSE ; /* initial value: Input AI21 is used. */
MWT_REAL PARTGP_PH_Ai21Mn_GI = -50.0 ; /* initial value: Min temperature analog in 21 */
MWT_REAL PARTGP_PH_Ai21Mx_GI = 500.0 ; /* initial value: Max temperature analog in 21 */
MWT_BOOL PARTGP_L_EnAi22_GI = FALSE ; /* initial value: Input AI22 is used. */
MWT_REAL PARTGP_PH_Ai22Mn_GI = -50.0 ; /* initial value: Min temperature analog in 22 */
MWT_REAL PARTGP_PH_Ai22Mx_GI = 500.0 ; /* initial value: Max temperature analog in 22 */
MWT_BOOL PARTGP_L_EnAi49_GI = FALSE ; /* initial value: Input AI49 is used. */
MWT_REAL PARTGP_PX_Ai49_GI = 400000.0 ; /* initial value: AI49 pressure at 20 mA to the DCU2-board */
MWT_REAL PARTGP_PH_TCoolCm_GI = 0.0 ; /* initial value: Cable compensation for Coolant/heatsink-temperature (remark: 40mOhm gives 1K)" */
MWT_TIME PARTGP_PT_NteSv_GI = 1000 ; /* initial value: Delay time for supervision of internal voltage */
MWT_UINT PARTGP_PT_DspWdg_GI = 2000 ; /* initial value: Timeout for DSP wathchdog supervision in FPGA1 (in us) */
MWT_BOOL PARTGP_L_EnDcu2ConfHPP_GI = FALSE ; /* initial value: Enable Opto8 as Pair of Arms (and not brake chopper) */
MWT_BOOL PARTGP_L_NteVSvEn_GI = FALSE ; /* initial value: Enable supervision of internal voltages */
MWT_BOOL PARTGP_B_EnParChgDet_GI = FALSE ; /* initial value: Enable parameter transfer to DSP without trigger command */
MWT_BOOL PARTGP_L_EnADComp_GI = FALSE ; /* initial value: Enable AD comparision supervision */
MWT_BOOL PARTGP_L_CnfHpp_GI = FALSE ; /* initial value: HPP Configuration */
MWT_BOOL PARTGP_L_CnfMpp_GI = TRUE ; /* initial value: MPP Configuration */
MWT_BOOL PARTGP_L_CnfLpp_GI = FALSE ; /* initial value: LPP Configuration */
MWT_BOOL PARTGP_L_CnfDcuA_GI = TRUE ; /* initial value: DCU/A Configuration */
MWT_BOOL PARTGP_L_CnfDcuM_GI = FALSE ; /* initial value: DCU/M Configuration */
MWT_BOOL PARTGP_L_CnfDcuL_GI = FALSE ; /* initial value: DCU/L Configuration */
MWT_BOOL PARTGP_B_EnCanComHPP_GI = FALSE ; /* initial value: Enable HPP CAN communication (via HPP expansion board) */
MWT_BOOL PARTGP_B_CntMtd_GI = TRUE ; /* initial value: Count method for MCU2/G faults (False=count nr. of reset from driver/application, True=count nr.
of failures) */
MWT_UDINT PARTGP_XX_TskTmThrT4_GI = 3200 ; /* initial value: Warning level/threshold for task executiuon time (us) */
MWT_UDINT PARTGP_XX_TskTmThrT16_GI = 12800 ; /* initial value: Warning level/threshold for task executiuon time (us) */
MWT_UDINT PARTGP_XX_TskTmThrT64_GI = 51200 ; /* initial value: Warning level/threshold for task executiuon time (us) */
MWT_UDINT PARTGP_XX_TskTmThrT1024_GI = 819200 ; /* initial value: Warning level/threshold for task executiuon time (us) */
MWT_INT PARTGP_WI_DTDX751A_GI = 41 ; /* initial value: Current reference, DTDX751A, (Opto LPP/MPP) */
MWT_INT PARTGP_WI_DTDX753B_GI = 41 ; /* initial value: Current reference, DTDX753B, (Opto LPP/MPP) */
MWT_INT PARTGP_WI_DTDX751C_GI = 41 ; /* initial value: Current reference, DTDX751C */
MWT_INT PARTGP_WI_DTDX752A_GI = 54 ; /* initial value: Current reference, DTDX752A, (Opto HPP plastic) */
MWT_INT PARTGP_WI_DTDX752B_GI = 40 ; /* initial value: Current reference, DTDX752B and DTDX752A channel 10, (Opto HPP, glass) */
MWT_BOOL PARTGP_B_EnOptoOutCal_GI = FALSE ; /* initial value: Enable calibration of optical output current */
MWT_UINT PARTGP_P_NoDspFl_Max_GI = 2 ; /* initial value: Max number of DSP failures before isolation request is set, 0 will leave DSP in failure mode
without reset */
MWT_TIME PARTGP_PT_WiDspFl_GI = 1800000 ; /* initial value: Time window for counting Dsp failures */
MWT_BOOL PARTGP_B_EnCnNtHwFl_GI = TRUE ; /* initial value: Enable HW re-init and counter for HwFl during Nt */
MWT_UINT PARTGP_P_NoLtrOpFl_Max_GI = 2 ; /* initial value: Max number of line trip opening failures before isolation */
MWT_BOOL PARTGP_B_EnTxtSel_GI = TRUE ; /* initial value: Enable selected termtexts */
MWT_UINT PARTGP_P_NoOptEnFl_Max_GI = 2 ; /* initial value: Max number of opto enable failures before isolation */
MWT_BOOL PARTGP_B_DTDX_GI = TRUE ; /* initial value: Optoboard mounted? */
MWT_BOOL PARTGP_B_DTEX_GI = TRUE ; /* initial value: Expansionboard mounted? */
MWT_INT PARTGP_PX_DspRamTsLv_GI = 2 ; /* initial value: DSP ram test level
0 = No test, returns OK
1 = Data bus and address bus test
2 = Data bus, address bus and device test */
MWT_BOOL PARTGP_B_TrmTxtAelogEn_GI = FALSE ; /* initial value: termtext+AE_ERROR? */
MWT_REAL PARTDP_PX_IPhSnRt_GI = 3000.0 ; /* initial value: Phase current measurement ratio (Ratio of Phase current measurement device) */
MWT_BOOL PARTDP_L_IPh1MmNg_GI = FALSE ; /* initial value: Phase current 1 measurement inverted (FALSE=Positive direction into 3-phase, TRUE=Positive
direction into DC-link) */
MWT_BOOL PARTDP_L_IPh2MmNg_GI = FALSE ; /* initial value: Phase current 2 measurement inverted (FALSE=Positive direction into 3-phase, TRUE=Positive
direction into DC-link) */
MWT_BOOL PARTDP_L_UDcLkSnU_GI = FALSE ; /* initial value: DC-link voltage sensor output (FALSE=Current (V/A), TRUE=Voltage (V/V)) */
MWT_REAL PARTDP_PX_UDcLkSnRt_GI = 40000.0 ; /* initial value: DC-link voltage measurement ratio (Ratio of DC-link voltage measurement device) */
MWT_REAL PARTDP_PX_UDcLk2SnRt_GI = 20000.0 ; /* initial value: DC-link voltage 2 measurement ratio (Ratio of DC-link voltage measurement device) */
MWT_BOOL PARTDP_L_U3PhSnU_GI = TRUE ; /* initial value: 3-phase output load voltage sensor output (FALSE=Current (V/A), TRUE=Voltage (V/V)) */
MWT_REAL PARTDP_PX_IDcLnErfSnRt_GI = 1000.0 ; /* initial value: DC-link earth fault current measurement ratio (Ratio of earth fault current
measurement device) */
MWT_REAL PARTDP_PX_IBtCgSnRt_GI = 3500.0 ; /* initial value: Battery charger current measurement ratio (Ratio of battery charger current measurement
device) */
MWT_REAL PARTDP_PX_IBtSnRt_GI = 3500.0 ; /* initial value: Battery current measurement ratio (Ratio of battery current measurement device) */
MWT_REAL PARTDP_PX_UPhInSnRt_GI = 20000.0 ; /* initial value: AC input phase voltage measurement ratio (Ratio of AC input phase voltage measurement
device) */
MWT_BOOL PARTDP_L_UPhInMmNg_GI = TRUE ; /* initial value: AC input phase voltage measurement inverted (FALSE=Positive direction into DC-link,
TRUE=Positive direction into AC-line) */
MWT_REAL PARTDP_PX_IPhInSnRt_GI = 1000.0 ; /* initial value: AC input phase current measurement ratio (Ratio of AC input phase current measurement
device) */
MWT_BOOL PARTDP_L_IPhInMmNg_GI = FALSE ; /* initial value: AC input phase current measurement inverted (FALSE=Positive direction into DC-link,
TRUE=Positive direction into AC-line) */
MWT_UDINT PARTDP_PT_Ovs2qc_GI = 20 ; /* initial value: Time between oversamplings for AC input phase current 2QC */
MWT_UDINT PARTDP_PX_NoOvs2qc_GI = 8 ; /* initial value: Number of oversamplings of AC input phase current 2QC */
MWT_REAL PARTDP_PX_IDfInSnRt_GI = 10000.0 ; /* initial value: Differential current measurement ratio (Ratio of differential current measurement
device) */
MWT_REAL PARTDP_PX_IRctSnRt_GI = 10000.0 ; /* initial value: HPP rectifier current measurement ratio (Ratio of differential current measurement
device) */
MWT_BOOL PARTDP_L_IRct1MmNg_GI = FALSE ; /* initial value: HPP rectifier current 1 measurement inverted (FALSE=Positive direction into rectifier,
TRUE=Positive direction into DC-link) */
MWT_BOOL PARTDP_L_IRct2MmNg_GI = FALSE ; /* initial value: HPP rectifier current 2 measurement inverted (FALSE=Positive direction into rectifier,
TRUE=Positive direction into DC-link) */
MWT_BOOL PARTDP_L_IRct3MmNg_GI = FALSE ; /* initial value: HPP rectifier current 3 measurement inverted (FALSE=Positive direction into rectifier,
TRUE=Positive direction into DC-link) */
MWT_REAL PARTDP_PX_AI24SnRt_GI = 1.0 ; /* initial value: AI24 measurement ratio */
MWT_REAL PARTDP_PX_AI29SnRt_GI = 1.0 ; /* initial value: AI29 measurement ratio */
MWT_BOOL PARTAP_L_En2ndU3Ph_GI = FALSE ; /* initial value: Enable 2nd 3-phase output voltage measurement */
MWT_REAL PARTAP_PI_PhMmSvSrOp_GI = 1.0 ; /* initial value: Phase current, level min during start operation, detection of missing measurement, RMS value
*/
MWT_TIME PARTAP_PT_IPhMmSvSrOp_GI = 1000 ; /* initial value: Phase current measurement supervision during start operation, detection time, detection
of missing measurement */
MWT_REAL PARTAP_PI_PhMmSvNg_GI = -20.0 ; /* initial value: Phase current, negative level, detection of faulty current direction, peak value */
MWT_TIME PARTAP_PT_IPhMmSvNg_GI = 500 ; /* initial value: Phase current measurement, detection time, detection of faulty current direction */
MWT_BOOL PARTAP_L_EnU3PhMmSvMin_GI = TRUE ; /* initial value: Enable 3-phase output load voltage measurement supervision, level min, detection of
missing measurement */
MWT_REAL PARTAP_PU_U3PhMmSvMin_GI = 100.0 ; /* initial value: 3-phase output load voltage RMS value, level min, detection of missing measurement. If
the RMS value is below the limit during the detection time a measurement failure is detected. */
MWT_TIME PARTAP_PT_U3PhMmSvOpLo_GI = 999000 ; /* initial value: 3-phase output load voltage RMS value, detection time for open loop control,
detection of missing measurement */
MWT_BOOL PARTAP_L_EnPrActU3PhMmFl_GI = TRUE ; /* initial value: Enable protective action due to 3-phase output load voltage measurement failure */
MWT_BOOL PARTAP_L_EnSltRqU3PhMmFl_GI = FALSE ; /* initial value: Enable isolation request due to 3-phase output load voltage measurement failure */
MWT_TIME PARTAP_PT_U3PhMmSvMin_GI = 3000 ; /* initial value: 3-phase output load voltage, detection time for protective action, detection of missing
measurement */
MWT_REAL PARTDP_PX_IPhMmSvMax_GI = 0.9 ; /* initial value: Phase current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PX_UDcLkMmSvDer_GI = 10000000.0 ; /* initial value: DC-link voltage measurement supervision, derivative limit */
MWT_REAL PARTDP_PX_UDcLkMmSvPo_GI = 0.9 ; /* initial value: DC-link voltage measurement supervision, positive limit, ratio of full scale */
MWT_REAL PARTDP_PU_DcLkMmSvNg_GI = -50.0 ; /* initial value: DC-link voltage measurement supervision, negative limit */
MWT_REAL PARTDP_PU_DcLkMmSvRip_GI = 2000.0 ; /* initial value: DC-link voltage measurement supervision, ripple limit */
MWT_BOOL PARTDP_L_UDcLkMmSvDf_GI = FALSE ; /* initial value: Enable DC-link voltage deviation supervision */
MWT_REAL PARTDP_PU_DcLkMmSvDf_GI = 300.0 ; /* initial value: DC-link voltage voltage measurement supervision, maximum difference between DC-link
voltage 1 and DC-link voltage 2 */
MWT_REAL PARTDP_PT_UDcLkMmSvDfDy_GI = 0.001 ; /* initial value: DC-link voltage voltage measurement supervision, detection time, maximum difference
between DC-link voltage 1 and DC-link voltage 2 */
MWT_REAL PARTDP_PX_U3PhMmSvMax_GI = 0.9 ; /* initial value: 3-phase output load voltage measurement supervision, max limit, ratio of full scale */
MWT_BOOL PARTDP_L_U3PhRmsPlySv_GI = TRUE ; /* initial value: Enable 3-phase output load voltage RMS plausibility supervision */
MWT_REAL PARTDP_PU_U3PhRmsPlySvLim_GI = 35.0 ; /* initial value: 3-phase output load voltage RMS plausibility supervision, max limit */
MWT_REAL PARTDP_PT_U3PhRmsPlySvDy_GI = 1.0 ; /* initial value: 3-phase output load voltage RMS plausibility supervision, detection time, max limit */
MWT_REAL PARTDP_PU_BtMmSvPo_GI = 160.0 ; /* initial value: Battery voltage measurement supervision, level max */
MWT_REAL PARTDP_PU_BtMmSvNg_GI = -10.0 ; /* initial value: Battery voltage measurement supervision, level min */
MWT_REAL PARTDP_PU_BtMmSvRip_GI = 30.0 ; /* initial value: Battery voltage measurement supervision, ripple limit */
MWT_REAL PARTDP_PX_IBtCgMmSvPo_GI = 0.9 ; /* initial value: Battery charger current measurement supervision, postive limit, ratio of full scale */
MWT_REAL PARTDP_PI_BtCgMmSvNg_GI = -50.0 ; /* initial value: Battery charger current measurement supervision, negative limit */
MWT_REAL PARTDP_PI_BtCgMmSvRip_GI = 1000.0 ; /* initial value: Battery charger current measurement supervision, ripple limit */
MWT_REAL PARTDP_PX_IBtMmSvMax_GI = 0.9 ; /* initial value: Battery current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PI_BtMmSvRip_GI = 100.0 ; /* initial value: Battery current measurement supervision, ripple limit */
MWT_REAL PARTDP_PX_IBtCpMmSvPo_GI = 0.9 ; /* initial value: Battery chopper current measurement supervision, postive limit, ratio of full scale */
MWT_REAL PARTDP_PI_BtCpMmSvNg_GI = -50.0 ; /* initial value: Battery chopper current measurement supervision, negative limit */
MWT_REAL PARTDP_PI_BtCpMmSvRip_GI = 1000.0 ; /* initial value: Battery chopper current measurement supervision, ripple limit */
MWT_REAL PARTDP_PX_UPhInMmSvMax_GI = 0.9 ; /* initial value: AC input phase voltage measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PX_IPhInMmSvMax_GI = 0.9 ; /* initial value: AC input phase current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PI_PhInRmsMmSvDf_GI = 1000.0 ; /* initial value: AC input phase current measurement supervision, maximum difference between AC input
phase current reference and RMS value */
MWT_REAL PARTDP_PT_IPhInRmsMmSvDy_GI = 1.0 ; /* initial value: AC input phase current measurement supervision, detection time, maximum difference
between AC input phase current reference and RMS value */
MWT_REAL PARTDP_PX_IDfInMmSvMax_GI = 0.9 ; /* initial value: Differential current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PX_IRctMmSvMax_GI = 0.9 ; /* initial value: HPP rectifier current measurement supervision, max limit, ratio of full scale */
MWT_REAL PARTDP_PI_SumRctMmSvMax_GI = 1000.0 ; /* initial value: Maximum sum of HPP rectifier currents */
MWT_REAL PARTDP_PT_IRctSumMmSvDfDy_GI = 0.3 ; /* initial value: Maximum sum of HPP rectifier currents, detection time */
MWT_DINT PARTDP_PX_DcLk1SvMax_GI = 4 ; /* initial value: Max number of DC-link voltage derivative faults within 3s time window */
MWT_REAL PARTDP_PN_UDcLk_Flt_GI = 100.0 ; /* initial value: DC-link voltage, filter constant for LP-filter */
MWT_REAL PARTDP_PN_U3PhRms_Flt_GI = 5.0 ; /* initial value: 3-phase output load voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_UBt_Flt_GI = 120.0 ; /* initial value: Battery voltage, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IBtCg1_Flt_GI = 200.0 ; /* initial value: Battery charger current, filter constant for LP-filter 1 for battery charger current
limitation and overcurrent protection in DSP (For LP-filtering two LP-filters are cascade coupled) */
MWT_REAL PARTDP_PN_IBtCg2_Flt_GI = 1000.0 ; /* initial value: Battery charger current, filter constant for LP-filter 2 for battery charger overcurrent
protection in MCU2/A (For LP-filtering two LP-filters are cascade coupled) */
MWT_REAL PARTDP_PN_IBt_Flt_GI = 20.0 ; /* initial value: Battery current, filter constant for LP-filter */
MWT_REAL PARTDP_PN_UPhIn_Flt_GI = 33.3 ; /* initial value: AC input phase voltage, filter constant for elimination of DC-component */
MWT_REAL PARTDP_PN_IDfIn_Flt_GI = 0.03 ; /* initial value: Differential current, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IPhActRct_Flt_GI = 2000.0 ; /* initial value: Phase current, active and reactive part, used for AC current limitation, filter
constant for LP-filter */
MWT_REAL PARTDP_PN_IPhActRctMcu_Flt_GI = 20.0 ; /* initial value: Phase current, active and reactive part, used in the MCU, filter constant for
LP-filter */
MWT_REAL PARTDP_PN_IPhAbs_Flt_GI = 60.0 ; /* initial value: Phase current, absolute value, used in the MCU, filter constant for LP-filter */
MWT_REAL PARTDP_PN_PQ3PhMcu_Flt_GI = 60.0 ; /* initial value: 3-phase inverter output power, used in the MCU, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IPhDQ_Flt_GI = 18.0 ; /* initial value: Phase current, dq, filter constant */
MWT_REAL PARTDP_PN_IPhAB_Flt_GI = 2000.0 ; /* initial value: Phase current, ab, filter constant */
MWT_REAL PARTDP_PN_URef_Flt_GI = 600.0 ; /* initial value: Voltage reference from modulation, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IRctRms_Flt_GI = 5.0 ; /* initial value: HPP rectifier currents, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_AI24_Flt_GI = 20.0 ; /* initial value: AI24 filter constant */
MWT_REAL PARTDP_PN_AI29_Flt_GI = 20.0 ; /* initial value: AI29 filter constant */
MWT_BOOL PARTAP_L_EnU3PhOpLoCl_GI = FALSE ; /* initial value: Enable 3-phase output load voltage open loop control (3-phase output load voltage is not
measured) */
MWT_REAL PARTAP_PX_FRefRmpUpIPhInHgh_GI = 100.0 ; /* initial value: Output frequency reference derivative, ramp up at high AC input phase current
and low AC input phase voltage */
MWT_REAL PARTAP_PX_FRefRmpDo1_GI = 40.0 ; /* initial value: Output frequency reference derivative, ramp down, when output frequency is below
FRefRmpDo12 */
MWT_REAL PARTAP_PX_FRefRmpDo2_GI = 40.0 ; /* initial value: Output frequency reference derivative, ramp down, when output frequency is between
FRefRmpDo12 and FRefRmpDo12 */
MWT_REAL PARTAP_PX_FRefRmpDo3_GI = 40.0 ; /* initial value: Output frequency reference derivative, ramp down, when output frequency is above
FRefRmpDo23 */
MWT_REAL PARTAP_PF_FRefRmpDo12_GI = 4.0 ; /* initial value: Output frequency point 1, for output frequency reference derivative, ramp down */
MWT_REAL PARTAP_PF_FRefRmpDo23_GI = 30.0 ; /* initial value: Output frequency point 2, for output frequency reference derivative, ramp down */
MWT_REAL PARTAP_PF_3PhIPhDcClEn_GI = 50.0 ; /* initial value: Output frequency when DC-current control and supervision shall be enabled */
MWT_REAL PARTAP_PF_UDcLkMin_GI = 50.0 ; /* initial value: Output frequency reference at minimum DC-link voltage */
MWT_REAL PARTAP_PU_DcLkFRefLow_GI = 1000.0 ; /* initial value: DC-link voltage, where output frequency reference is reduced */
MWT_REAL PARTAP_PU_DcLkFRefMin_GI = 1000.0 ; /* initial value: Min DC-link voltage level breakpoint for output frequency reference */
MWT_REAL PARTAP_PX_FRefRmpUDcLkUp_GI = 40.0 ; /* initial value: Output frequency reference derivative, ramp up at low DC-link voltage */
MWT_REAL PARTAP_PX_FRefRmpUDcLkDo_GI = 40.0 ; /* initial value: Output frequency reference derivative, ramp down at low DC-link voltage */
MWT_REAL PARTAP_PF_3PhMin_GI = 3.0 ; /* initial value: Output frequency reference, minimum value */
MWT_REAL PARTAP_PU_PhInFRefRmp_GI = 0.0 ; /* initial value: AC input phase RMS voltage min limit, when output frequency reference is reduced */
MWT_REAL PARTAP_PI_PhInFRefRmp_GI = 22500.0 ; /* initial value: AC input phase RMS current max limit, when output frequency reference is reduced */
MWT_BOOL PARTAP_L_F3PhRedSwcEn_GI = FALSE ; /* initial value: Enable a direct switch to the requested output frequency reference instead of ramping
down to the requested output frequency reference, when starting switching. */
MWT_REAL PARTAP_PU_3PhClRefMin_GI = 0.0 ; /* initial value: Minimum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_3PhClMax_GI = 75.0 ; /* initial value: Maximum output from 3-phase output load voltage controller, phase-neutral, peak value */
MWT_REAL PARTAP_PU_3PhClMin_GI = -50.0 ; /* initial value: Minimum output from 3-phase output load voltage controller, phase-neutral, peak value */
MWT_REAL PARTAP_PX_KpU3PhCl_GI = 0.8 ; /* initial value: Proportional part, 3-phase output load voltage controller */
MWT_REAL PARTAP_PT_U3PhCl_GI = 50.0 ; /* initial value: Time constant, 3-phase output load voltage controller */
MWT_REAL PARTAP_PF_U3PhRef2_GI = 6.0 ; /* initial value: Output frequency reference, U/f-ratio, breakpoint 2 */
MWT_REAL PARTAP_PF_U3PhRef3_GI = 50.0 ; /* initial value: Output frequency reference, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef1_GI = 0.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 0 Hz */
MWT_REAL PARTAP_PU_U3PhRef2_GI = 0.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 2 */
MWT_TIME PARTAP_PT_FRefUDcLk_GI = 100 ; /* initial value: Filter constant for DC-link voltage, used for output frequency reference function as a
function of DC-link voltage */
MWT_BOOL PARTAP_L_ExtF3PhRef_GI = FALSE ; /* initial value: Use output frequency reference from MVB */
MWT_BOOL PARTAP_L_ExtU3PhRef_GI = FALSE ; /* initial value: Use 3-phase output load voltage reference from MVB */
MWT_BOOL PARTAP_B_En3PhClFqAda_GI = TRUE ; /* initial value: Enable frequency adaptation of 3-phase controller gain */
MWT_REAL PARTAP_PX_ExtU3PhRefRmp_GI = 200.0 ; /* initial value: 3-phase output load voltage reference derivative, when using 3-phase output load
voltage reference from MVB */
MWT_BOOL PARTAP_L_EnRmpU3PhRef_GI = FALSE ; /* initial value: Enable ramped voltage reference to U3Ph control (Only used for HPP HEP) */
MWT_REAL PARTAP_PX_U3PhRefRmp1_GI = 200.0 ; /* initial value: 3-phase output load voltage reference derivative, level 1, only used if
PARTAP_L_EnRmpU3PhRef is TRUE */
MWT_REAL PARTAP_PX_U3PhRefRmp2_GI = 50.0 ; /* initial value: 3-phase output load voltage reference derivative, level 2, only used if
PARTAP_L_EnRmpU3PhRef is TRUE */
MWT_REAL PARTAP_PX_U3PhRefRmpSel_GI = 0.9 ; /* initial value: Ratio of destination 3-phase output load voltage reference
when ramp derivative is shifted from level 1 to level 2, only used if PARTAP_L_EnRmpU3PhRef is TRUE */
MWT_BOOL PARTDP_L_UDcLkStbEn_GI = TRUE ; /* initial value: Enable DC-link voltage stabilization */
MWT_REAL PARTDP_PN_UDcLkStbSliSmt_GI = 2200.0 ; /* initial value: DC-link voltage stabilization, filter constant for slightly smoothed DC-link voltage
*/
MWT_REAL PARTDP_PN_UDcLkStbHevSmt_GI = 13.5 ; /* initial value: DC-link voltage stabilization, filter constant for heavily smoothed DC-link voltage
*/
MWT_REAL PARTDP_PU_DcLkStbMaxMin_GI = 100.0 ; /* initial value: DC-link voltage stabilization, max/min output, phase-neutral, peak value */
MWT_REAL PARTDP_PZ_3PhFiCaRe_GI = 0.00025 ; /* initial value: 3-phase filter impedance, capacitor, resistance */
MWT_UDINT PARTDP_PX_3PhMod_GI = 0 ; /* initial value: Type of 3-phase inverter modulation 0=SVM, 1=DM, 2=SM (SVM=Space vector modulation, DM=60
degrees discontinuous modulation, SM=Sinus modulation) */
MWT_BOOL PARTDP_L_En3PhOvMod_GI = TRUE ; /* initial value: Enable 3-phase inverter overmodulation (only possible for the modulation methods SVM and DM)
*/
MWT_REAL PARTDP_PN_UDcLkVoStbSmt_GI = 1200.0 ; /* initial value: DC-link voltage stabilization, filter constant for frequency contribution */
MWT_REAL PARTDP_PR_IPhStb_GI = 0.01 ; /* initial value: Virtual resistance for phase current stabilization (set value to zero to disable this
feature) */
MWT_REAL PARTDP_PX_IPhStbRfc_GI = 0.4 ; /* initial value: Virtual resistor, reduction factor */
MWT_BOOL PARTDP_L_DsFiThetaCm_GI = TRUE ; /* initial value: Disable 3-phase filter and trafo compensation theta angle */
MWT_BOOL PARTAP_L_En3PhCl_GI = TRUE ; /* initial value: Enable 3-phase output load voltage control, not battery voltage control (If battery voltage
is measured, the parameter shall be set to FALSE, else TRUE) */
MWT_REAL PARTAP_PI_UBtRef_GI = 228.0 ; /* initial value: Max battery charger current level breakpoint for battery voltage reference */
MWT_TIME PARTAP_PT_BtRfCg_GI = 0 ; /* initial value: Maximum time for battery refresh charging */
MWT_REAL PARTAP_PX_UBtRefRmpUp_GI = 133.0 ; /* initial value: Battery voltage reference derivative, ramp up */
MWT_REAL PARTAP_PX_UBtRefRmpDo_GI = 667.0 ; /* initial value: Battery voltage reference derivative, ramp down */
MWT_REAL PARTAP_PU_UBtClMax_GI = 75.0 ; /* initial value: Maximum output from battery voltage controller, phase-neutral, peak value */
MWT_REAL PARTAP_PU_UBtClMin_GI = -50.0 ; /* initial value: Minimum output from battery voltage controller, phase-neutral, peak value */
MWT_REAL PARTAP_PX_KpUBtCl_GI = 0.8 ; /* initial value: Proportional part, battery voltage control */
MWT_REAL PARTAP_PT_UBtCl_GI = 50.0 ; /* initial value: Time constant, battery voltage control */
MWT_REAL PARTAP_PX_TrfRtBt3Ph_GI = 0.205 ; /* initial value: Transformer ratio, battery to 3-phase winding */
MWT_REAL PARTAP_PX_TrfRtPrBt_GI = 12.05 ; /* initial value: Transformer ratio, primary to battery winding */
MWT_REAL PARTAP_PH_RctHtRef1_GI = 75.0 ; /* initial value: Battery rectifier heat-sink temperature, where battery voltage reference is reduced */
MWT_REAL PARTAP_PH_RctHtRef2_GI = 80.0 ; /* initial value: Max battery rectifier heat-sink temp level breakpoint for batt voltage ref */
MWT_REAL PARTAP_PX_RctHtHBtRef_GI = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery rectifier heat-sink temperature level
breakpoint */
MWT_REAL PARTAP_PX_UBtCpRefRmp_GI = 4.0 ; /* initial value: Battery voltage reference ramp up derative at start of Battery chopper */
MWT_REAL PARTAP_PF_IPhClMin_GI = 50.0 ; /* initial value: Minimum output frequency, AC current limitation, general overload control */
MWT_REAL PARTAP_PF_IPhClMinErr_GI = 25.0 ; /* initial value: Minimum frequency error to AC current limitation, general overload control */
MWT_REAL PARTAP_PX_IPhClIntMax_GI = 20000.0 ; /* initial value: Maximum integrator input to AC current limitation, general overload control */
MWT_REAL PARTAP_PX_IPhClIntMin_GI = 0.0 ; /* initial value: Minimum integrator input to AC current limitation, general overload control */
MWT_TIME PARTAP_PT_IPhClInt_GI = 100 ; /* initial value: Integration time constant to AC current limitation, general overload control */
MWT_REAL PARTAP_PI_IPhClActMax_GI = 400.0 ; /* initial value: Maximum active phase current reference, post-transient control */
MWT_REAL PARTAP_PI_IPhClActMin_GI = 100.0 ; /* initial value: Minimum active phase current reference, post-transient control */
MWT_REAL PARTAP_PI_IPhClActPsTrs_GI = 450.0 ; /* initial value: Active phase current limit, post-transient control */
MWT_REAL PARTAP_PI_IPhClActOs_GI = 100.0 ; /* initial value: Active phase current reference offset contribution, post-transient control */
MWT_REAL PARTAP_PX_IPhClActDe_GI = 200.0 ; /* initial value: Active phase current reference derivative, post-transient control */
MWT_REAL PARTAP_PI_IPhClRctMax_GI = 400.0 ; /* initial value: Maximum reactive phase current reference, post-transient control */
MWT_REAL PARTAP_PI_IPhClRctMin_GI = 0.0 ; /* initial value: Minimum reactive phase current reference, post-transient control */
MWT_REAL PARTAP_PI_IPhClRctPsTrs_GI = 300.0 ; /* initial value: Reactive phase current limit, post-transient control */
MWT_REAL PARTAP_PI_IPhClRctOs_GI = 100.0 ; /* initial value: Reactive phase current reference offset contribution, post-transient control */
MWT_REAL PARTAP_PX_IPhClRctDePos_GI = 200.0 ; /* initial value: Reactive phase current reference derivative, ramp up, post-transient control */
MWT_REAL PARTAP_PX_IPhClRctDeNg_GI = 200.0 ; /* initial value: Reactive phase current reference derivative, ramp down, post-transient control */
MWT_REAL PARTAP_PI_IPhClPsTrsLim_GI = 600.0 ; /* initial value: Peak phase current limit, post-transient control */
MWT_REAL PARTDP_PX_IPhClTrsKpAct_GI = 0.005 ; /* initial value: Active phase current amplification, transient control, to DSP */
MWT_REAL PARTDP_PX_IPhClTrsKpRct_GI = 0.03 ; /* initial value: Reactive phase current amplification, transient control, to DSP */
MWT_REAL PARTDP_PX_IPhClTrsKpAbs_GI = 0.0 ; /* initial value: Active and Reactive phase current amplification, transient control, to DSP */
MWT_REAL PARTDP_PI_PhClTrsAbsLim_GI = 600.0 ; /* initial value: Phase current limitation, transient control limit */
MWT_REAL PARTDP_PU_PhClTrsMax_GI = 75.0 ; /* initial value: Max reduction of voltage reference from transient and post-transient control in the DSP,
phase-neutral, peak value, If set to zero the AC current limitation, transient and post-transient control, is disabled */
MWT_REAL PARTDP_PN_URefIPhClTrs_Flt_GI = 20.0 ; /* initial value: 3-phase output load voltage manipulation from AC current control, transient control,
filter constant for LP-filter */
MWT_REAL PARTDP_PX_IPhClRmsRmpUp_GI = 1000.0 ; /* initial value: RMS phase current limitation derivative at nominal frequency. */
MWT_REAL PARTDP_PX_IPhClRmsRfc_GI = 0.75 ; /* initial value: RMS phase current limitation, reduction factor of the previous value */
MWT_BOOL PARTDP_L_EnIPhClRms_GI = FALSE ; /* initial value: Enable RMS phase current limitation */
MWT_REAL PARTDP_PI_PhClRmsLim_GI = 800.0 ; /* initial value: RMS phase current limitation, current limit */
MWT_REAL PARTDP_PN_IPhRms_Flt_GI = 30.0 ; /* initial value: Phase current filter constant of RMS value */
MWT_REAL PARTAP_PX_IBtCgRmp_GI = 10.0 ; /* initial value: Battery charger current derivative, used for ramping the battery charger current reference
*/
MWT_REAL PARTDP_PX_IBtCgDeLim_GI = 4999.0 ; /* initial value: Battery charger current, positive derivative limit */
MWT_REAL PARTDP_PI_BtCgMinAvDe_GI = 0.0 ; /* initial value: Min battery charger current to activate positive derivative limit */
MWT_REAL PARTAP_PI_RfCgLim_GI = 4999.0 ; /* initial value: Battery charger current limit, refresh charging limit */
MWT_REAL PARTDP_PX_KpIBtCgCl_GI = 0.04 ; /* initial value: Proportional part, battery charger current control */
MWT_REAL PARTDP_PX_KiIBtCgCl_GI = 0.0 ; /* initial value: Integrational part, battery charger current control */
MWT_REAL PARTDP_PU_IBtCgClMax_GI = 0.0 ; /* initial value: Maximum voltage contribution from battery charger current control, phase-neutral, peak value
*/
MWT_REAL PARTAP_PX_KpIBtCl_GI = 0.1 ; /* initial value: Proportional part, battery current control */
MWT_REAL PARTAP_PU_IBtClMax_GI = 50.0 ; /* initial value: Maximum voltage contribution from battery current control, battery voltage */
MWT_BOOL PARTDP_L_EnIPhDcCl_GI = TRUE ; /* initial value: Enable suppression of DC-components in phase currents */
MWT_REAL PARTDP_PU_IPhDcClMaxMin_GI = 3.0 ; /* initial value: Max/min output from DC-current suppression controller, phase-neutral, peak value */
MWT_REAL PARTDP_PX_KpIPhDcCl_GI = 0.2 ; /* initial value: Proportional part, DC-current suppression controller */
MWT_REAL PARTDP_PX_KiIPhDcCl_GI = 0.0001 ; /* initial value: Integral part, DC-current suppression controller */
MWT_BOOL PARTAP_L_EnUF3PhCmp_GI = TRUE ; /* initial value: Enable voltage and frequency compounding */
MWT_REAL PARTAP_PI_UF3PhCmpActHiLo_GI = 4000.0 ; /* initial value: Active phase current at output frequency breakpoint */
MWT_REAL PARTAP_PF_UF3PhCmpActHiLo_GI = -10.0 ; /* initial value: Output frequency breakpoint */
MWT_REAL PARTAP_PI_UF3PhCmpRctHiLo_GI = 4000.0 ; /* initial value: Reactive phase current at 3-phase output load voltage breakpoint */
MWT_REAL PARTAP_PF_UF3PhSzClMaxMin_GI = 50.0 ; /* initial value: Max/min output from output frequency synchronization controller */
MWT_TIME PARTAP_PT_UF3PhSzRmp_GI = 1000 ; /* initial value: Ramp time for ending synchronization */
MWT_REAL PARTAP_PU_UF3PhSzClAdd_GI = 0.0 ; /* initial value: Amplitude addition during synchronization to 3-phase auxiliary 3-phase bus, phase to
neutral, peak value */
MWT_REAL PARTAP_PU_UF3PhSzClMaxMin_GI = 100.0 ; /* initial value: Max/min output from 3-phase output load voltage synchronization controller,
phase-neutral, peak value */
MWT_TIME PARTAP_PT_UF3PhSzFl_GI = 5000 ; /* initial value: Time delay before detection synchronization failure to 3-phase auxiliary bus */
MWT_UDINT PARTDP_PX_UPhInNtFltDy_GI = 0 ; /* initial value: Compensation for notch filter delay, when removing frequencies from the AC input phase
voltage for line synchronization */
MWT_BOOL PARTDP_L_DsPlElm3PhMod_GI = TRUE ; /* initial value: Disable pulse elimination at low or high 3-phase inverter control ratio */
MWT_BOOL PARTDP_L_EnTPrDdCmp_GI = FALSE ; /* initial value: Enable pre-control of interlocking times */
MWT_REAL PARTDP_PX_DdCmpFa_GI = 1.0 ; /* initial value: Dead time compensation factor */
MWT_REAL PARTDP_PI_DdCmpFu_GI = 50.0 ; /* initial value: Phase current level for full dead time compensation */
MWT_REAL PARTDP_PI_DdCmpDs_GI = 10.0 ; /* initial value: Phase current level for no dead time compensation */
MWT_REAL PARTDP_PF_2qcSg_GI = 2000.0 ; /* initial value: 2QC switching frequency (Connected to IRQD cycle time) */
MWT_REAL PARTDP_PF_2qcSgChg_GI = 20.0 ; /* initial value: 2QC switching frequency change as a function of MVB address */
MWT_BOOL PARTAP_L_ExtCtCl_GI = FALSE ; /* initial value: External control of contactors with DX via MVB */
MWT_BOOL PARTAP_L_ExtDiOut1En_GI = FALSE ; /* initial value: Enable external control of digital output 1 */
MWT_BOOL PARTAP_L_ExtDiOut2En_GI = FALSE ; /* initial value: Enable external control of digital output 2 */
MWT_BOOL PARTAP_L_ExtDiOut3En_GI = FALSE ; /* initial value: Enable external control of digital output 3 */
MWT_BOOL PARTAP_L_ExtDiOut4En_GI = FALSE ; /* initial value: Enable external control of digital output 4 */
MWT_BOOL PARTAP_L_ExtDiOut5En_GI = FALSE ; /* initial value: Enable external control of digital output 5 */
MWT_BOOL PARTAP_L_ExtDiOut6En_GI = FALSE ; /* initial value: Enable external control of digital output 6 */
MWT_BOOL PARTAP_L_DcLkChCt_GI = TRUE ; /* initial value: Charging contactor in use */
MWT_BOOL PARTAP_L_DcLkSrCt_GI = TRUE ; /* initial value: Separation contactor in use */
MWT_REAL PARTAP_PU_DcLkUHgh_GI = 900.0 ; /* initial value: DC-link voltage level regarded as charged, used when separation contactor or charging
contactor is in use */
MWT_TIME PARTAP_PT_2qcOpChRdy_GI = 500 ; /* initial value: Time for DC-link charging ready after 2QC in operation */
MWT_BOOL PARTAP_L_3PhCvDh_GI = FALSE ; /* initial value: Discharge of DC-link via 3 phase inverter */
MWT_REAL PARTAP_PU_3PhDcLkCvDh_GI = 50.0 ; /* initial value: 3-phase output load voltage reference during DC-link discharging via 3-phase inverter */
MWT_REAL PARTAP_PF_3PhDcLkCvDh_GI = 0.0 ; /* initial value: Output frequency reference during DC-link discharging via 3-phase inverter */
MWT_REAL PARTAP_PU_3PhIdlCmp_GI = 40.0 ; /* initial value: Maximum voltage for detecting an idle 3-phase bus, phase-phase, RMS value */
MWT_REAL PARTAP_PU_3PhActCmp_GI = 250.0 ; /* initial value: Minimum voltage for detecting an active 3-phase bus, phase-phase, RMS value */
MWT_BOOL PARTAP_L_BcOpSrCt_GI = FALSE ; /* initial value: Enable blocking with opening of contactors */
MWT_TIME PARTAP_PT_DySrCtOp_GI = 100 ; /* initial value: Delay time for opening of contactors in protective shutdown */
MWT_TIME PARTAP_PT_DyAuLdCtOp_GI = 100 ; /* initial value: Delay time for opening of auxiliary load contactor in protective shutdown */
MWT_BOOL PARTAP_L_EnTmOutPrSd_GI = FALSE ; /* initial value: Enable isolation after protective shutdown time-out */
MWT_BOOL PARTAP_L_EnTmOutFsSd_GI = FALSE ; /* initial value: Enable isolation after fast shutdown time-out */
MWT_BOOL PARTAP_L_EnTmOutSfSd_GI = FALSE ; /* initial value: Enable isolation after soft shutdown time-out */
MWT_BOOL PARTAP_L_EnTmOutPrBc_GI = FALSE ; /* initial value: Enable isolation after protective blocking time-out */
MWT_TIME PARTAP_PT_TmOutPrSd_GI = 1800000 ; /* initial value: Time for isolation after protective shutdown time-out */
MWT_TIME PARTAP_PT_TmOutFsSd_GI = 1800000 ; /* initial value: Time for isolation after fast shutdown time-out */
MWT_TIME PARTAP_PT_TmOutSfSd_GI = 1800000 ; /* initial value: Time for isolation after soft shutdown time-out */
MWT_TIME PARTAP_PT_TmOutPrBc_GI = 1800000 ; /* initial value: Time for isolation after protective blocking time-out */
MWT_BOOL PARTAP_L_EnMvbWdg2Sv_GI = TRUE ; /* initial value: Enable MVB watchdog supervision on T2 (16 ms) */
MWT_BOOL PARTAP_L_EnMvbWdg3Sv_GI = TRUE ; /* initial value: Enable MVB watchdog supervision on T3 (64 ms) */
MWT_BOOL PARTAP_L_EnMvbWdg4Sv_GI = TRUE ; /* initial value: Enable MVB watchdog supervision on T4 (1024 ms) */
MWT_INT PARTAP_PX_NoFlMvbCy_Hgh_GI = 13 ; /* initial value: Amount of samples for MVB disturbance warning */
MWT_INT PARTAP_PX_NoFlMvbCy_Max_GI = 30 ; /* initial value: Maximum samples of MVB watchdog counter error */
MWT_UDINT PARTDP_PT_PrDdPoa_GI = 6 ; /* initial value: Phase interlocking time in a POA */
MWT_UDINT PARTDP_PT_PoaOnMin_GI = 16 ; /* initial value: Minimum switching-ON-time for IGBT in a POA */
MWT_UDINT PARTDP_PT_OvpOfMin_GI = 16 ; /* initial value: Minimum switching-OFF-time for OVP */
MWT_UDINT PARTDP_PT_OvpOnMin_GI = 16 ; /* initial value: Minimum switching-ON-time for OVP */
MWT_UDINT PARTDP_PT_2qcOfMin_GI = 16 ; /* initial value: Minimum switching-OFF-time for 2QC */
MWT_UDINT PARTDP_PT_2qcOnMin_GI = 16 ; /* initial value: Minimum switching-ON-time for 2QC */
MWT_UDINT PARTDP_PT_BtCpOnMin_GI = 1 ; /* initial value: Minimum switching-ON-time for Battery chopper IGBT */
MWT_UDINT PARTDP_PT_BtCpOfMin_GI = 1 ; /* initial value: Minimum switching-OFF-time for Battery chopper IGBT */
MWT_UDINT PARTDP_PT_UDcLkMaxDy_GI = 6 ; /* initial value: DC-link overvoltage protection, detection time for level max */
MWT_BOOL PARTAP_L_EnOvp_GI = TRUE ; /* initial value: Enable OVP */
MWT_REAL PARTDP_PU_DcLkHgh4_GI = 1950.0 ; /* initial value: DC-link overvoltage protection, level high4 */
MWT_REAL PARTDP_PT_UDcLkHgh4Dy_GI = 0.5 ; /* initial value: DC-link overvoltage protection, detection time, level high4 */
MWT_BOOL PARTAP_L_EnUDcLkHgh12_GI = TRUE ; /* initial value: Enable DC-link overvoltage protection, level high1 and level high2 */
MWT_TIME PARTAP_PT_UDcLkHgh2_GI = 2000 ; /* initial value: DC-link overvoltage protection, detection time, level high2 */
MWT_REAL PARTAP_PU_DcLkHghRst_GI = 1850.0 ; /* initial value: DC-link overvoltage protection, reset level for level high2 and level high1 */
MWT_TIME PARTAP_PT_UDcLkLowDy_GI = 1000 ; /* initial value: DC link voltage low level, delay */
MWT_REAL PARTDP_PT_SiPhBcPoaTmWnd1_GI = 0.01 ; /* initial value: Single phase blocking (SPB) supervision POA, time window 1 */
MWT_DINT PARTDP_PX_SiPhBcPoaMaxWnd1_GI = 14 ; /* initial value: Single Phase Blocking (SPB) supervision POA, maximum number of SPB within time
window 1 */
MWT_REAL PARTDP_PT_SiPhBcPoaTmWnd2_GI = 5.0 ; /* initial value: Single Phase Blocking (SPB) supervision POA, time window 2 */
MWT_DINT PARTDP_PX_SiPhBcPoaMaxWnd2_GI = 100 ; /* initial value: Single Phase Blocking (SPB) supervision POA, maximum number of time window 1 within
time window 2 */
MWT_REAL PARTDP_PI_PhMax_GI = 850.0 ; /* initial value: Phase overcurrent protection, level max */
MWT_UDINT PARTDP_PT_IPhMaxDy_GI = 2 ; /* initial value: Phase overcurrent protection, detection time for level max */
MWT_REAL PARTDP_PI_PhHi4_GI = 700.0 ; /* initial value: Phase overcurrent protection, level high4, activation of Single Phase Blocking (SPB) POA */
MWT_UDINT PARTDP_PT_IBtCpMaxDy_GI = 0 ; /* initial value: Battery chopper overcurrent protection, detection time for level max */
MWT_REAL PARTDP_PI_BtCpHi4_GI = 4999.0 ; /* initial value: Battery chopper overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) */
MWT_UDINT PARTDP_PT_IBtCpHi4Dy_GI = 0 ; /* initial value: Battery chopper overcurrent protection, detection time for level high 4 */
MWT_REAL PARTDP_PT_SiPhBcBtCpTmWnd1_GI = 0.002 ; /* initial value: Single phase blocking (SPB) supervision BtCp, time window 1 */
MWT_DINT PARTDP_PX_SiPhBcBtCpMaxWnd1_GI = 15 ; /* initial value: Single Phase Blocking (SPB) supervision BtCp, maximum number of SPB within time
window 1 */
MWT_UINT PARTAP_PX_IBtCpTmWndFl_GI = 2 ; /* initial value: Supervision of Battery chopper current SPB, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IBtCpTmWndFl_GI = 1800000 ; /* initial value: Supervision of Battery chopper current SPB, time window for monitoring the number of
failures */
MWT_REAL PARTDP_PT_IPhClRmsTmWnd1_GI = 180.0 ; /* initial value: RMS phase current limitation supervision, time window 1 */
MWT_DINT PARTDP_PX_IPhClRmsMaxWnd1_GI = 25 ; /* initial value: RMS phase current limitation supervision, maximum number of RMS phase current limitation
within time window 1 */
MWT_REAL PARTDP_PI_PhClRmsSvMax_GI = 500.0 ; /* initial value: RMS phase current limitation supervision, level max */
MWT_REAL PARTDP_PT_IPhClRmsSvDy_GI = 12.0 ; /* initial value: RMS phase current limitation supervision, detection time for level max */
MWT_TIME PARTAP_PT_IAcLimTmSvDy_GI = 30000 ; /* initial value: AC current limitation time supervision delay */
MWT_TIME PARTAP_PT_IPhClTrsAvTof_GI = 512 ; /* initial value: Time-off delay to fetch short transient or post transient indications */
MWT_BOOL PARTAP_L_EnIPhDcSv_GI = TRUE ; /* initial value: Enable phase current DC supervision */
MWT_REAL PARTAP_PI_PhDcSvMax_GI = 9.0 ; /* initial value: Phase current DC supervision max level, peak value */
MWT_TIME PARTAP_PT_IPhDcSvMaxDy_GI = 30000 ; /* initial value: Phase current DC supervision max level delay */
MWT_BOOL PARTAP_L_EnIBalSv_GI = TRUE ; /* initial value: Enable phase current unbalance protection */
MWT_TIME PARTAP_PT_IBalSvDelDy_GI = 5000 ; /* initial value: Phase current unbalance protection, detection time, level max */
MWT_TIME PARTAP_PT_IBalSvDyCvOp_GI = 15000 ; /* initial value: Phase current unbalance protection, delay before activation after start operation */
MWT_BOOL PARTAP_L_BlkSiFl_GI = FALSE ; /* initial value: Block the converter at single feedback failure */
MWT_BOOL PARTAP_L_En3PhGduFbCk_GI = TRUE ; /* initial value: Enable 3-phase inverter GDU feedback check at start */
MWT_BOOL PARTAP_L_En2qcGduFbCk_GI = FALSE ; /* initial value: Enable 2QC GDU feedback check during DC-link charging */
MWT_TIME PARTAP_PT_GduFbCk_Mx_GI = 500 ; /* initial value: Maximum time for GDU feedback check at start and during DC-link charging */
MWT_REAL PARTDP_PU_DcLkShtCrSv_GI = 0.0 ; /* initial value: DC-link voltage level to detect a DC-link short circuit if both GDU feedbacks in POA
shows on */
MWT_REAL PARTDP_PT_GduBoFbOnPoaDy_GI = 0.0 ; /* initial value: Both GDU feedback in POA shows on, detection time for supervision in DSP */
MWT_BOOL PARTAP_L_UceGduFb_GI = TRUE ; /* initial value: UCE-feedback is used */
MWT_REAL PARTDP_PU_DcLkGduFbSvAv_GI = 1000.0 ; /* initial value: Minimum DC-link voltage level to activate GDU feedback supervision if UCE-feedback
is used. */
MWT_BOOL PARTDP_L_EnGduFbSvPoa_GI = TRUE ; /* initial value: Enable GDU feedback supervision POA */
MWT_BOOL PARTDP_L_EnGduFbSvOvp_GI = TRUE ; /* initial value: Enable GDU feedback supervision OVP */
MWT_BOOL PARTDP_L_EnGduFbSv2qc_GI = FALSE ; /* initial value: Enable GDU feedback supervision 2QC */
MWT_UDINT PARTDP_PX_NoGduFbFlPoa_Max_GI = 10 ; /* initial value: Max allowed number of GDU feedback failures for POA */
MWT_UDINT PARTDP_PX_NoGduFbFlOvp_Max_GI = 10 ; /* initial value: Max allowed number of GDU feedback failures for OVP */
MWT_UDINT PARTDP_PX_NoGduFbFl2qc_Max_GI = 10 ; /* initial value: Max allowed number of GDU feedback failures for 2QC */
MWT_BOOL PARTDP_L_EnGduShtCrSv_GI = FALSE ; /* initial value: Enable DC-link short circuit supervision (Supervision of if both GDU feedbacks in POA
show on) */
MWT_BOOL PARTDP_L_EnGduShtCrPraFpga_GI = TRUE ; /* initial value: Protective action in FPGA in case of DC-link short circuit (Supervision of if both
GDU feedbacks in POA show on. If FALSE the protective action is in the DSP) */
MWT_UDINT PARTDP_PT_MskGduFbPoa_GI = 38 ; /* initial value: GDU feedback masking time in a POA, must be greater than (2*Tdead+Tglitch) */
MWT_UDINT PARTDP_PT_MskGduFbOvp_GI = 10 ; /* initial value: GDU feedback masking time for OVP, must be greater than PARTDP_PT_GltFiGduFbOvp */
MWT_UDINT PARTDP_PT_MskGduFb2qc_GI = 15 ; /* initial value: GDU feedback masking time for 2QC, must be greater than PARTDP_PT_GltFiGduFb2qc */
MWT_UDINT PARTDP_PT_GltFiGduFbPoa_GI = 1 ; /* initial value: Glitch filter time for GDU feedback supervision POA */
MWT_UDINT PARTDP_PT_GltFiGduFbOvp_GI = 1 ; /* initial value: Glitch filter time for GDU feedback supervision OVP */
MWT_UDINT PARTDP_PT_GltFiGduFb2qc_GI = 3 ; /* initial value: Glitch filter time for GDU feedback supervision 2QC */
MWT_UDINT PARTDP_PX_NoGduFbFlBtCp_Max_GI = 10 ; /* initial value: Max allowed number of GDU feedback failures for Battery chopper */
MWT_UDINT PARTDP_PT_GltFiGduFbBtCp_GI = 3 ; /* initial value: Glitch filter time for GDU feedback supervision Battery chopper */
MWT_UDINT PARTDP_PT_MskGduFbBtCp_GI = 30 ; /* initial value: GDU feedback masking time in Battery chopper, must be greater than
PARTDP_PT_GltFiGduFbBtCp */
MWT_UINT PARTAP_PX_GduFbSvBtCp_GI = 10 ; /* initial value: GDU feedback supervision BtCp, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_GduFbSvBtCp_GI = 1800000 ; /* initial value: GDU feedback supervision BtCp, time window for monitoring the number of failures */
MWT_BOOL PARTAP_L_EnU3PhRmsMaxSv_GI = TRUE ; /* initial value: Enable 3-phase output load overvoltage protection */
MWT_REAL PARTAP_PU_3PhRmsMax_GI = 437.0 ; /* initial value: 3-phase output load overvoltage protection, level max, phase-phase, RMS value */
MWT_TIME PARTAP_PT_U3PhRmsMax_GI = 3000 ; /* initial value: 3-phase output load overvoltage protection, detection time, level max */
MWT_UINT PARTAP_PX_OvU3Ph_GI = 2 ; /* initial value: 3-phase output load overvoltage protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_OvU3Ph_GI = 1800000 ; /* initial value: 3-phase output load overvoltage protection, time window for monitoring the number of
failures */
MWT_BOOL PARTAP_L_UBtHghLowSvEn_GI = FALSE ; /* initial value: Enable Battery high and low voltage supervision */
MWT_REAL PARTAP_PU_BtMax_GI = 137.5 ; /* initial value: Battery voltage, level max */
MWT_REAL PARTAP_PU_BtHgh_GI = 130.0 ; /* initial value: Battery voltage, level high */
MWT_TIME PARTAP_PT_UBtHghDy_GI = 1000 ; /* initial value: Battery voltage, level high, delay */
MWT_REAL PARTAP_PU_BtHghRst_GI = 127.0 ; /* initial value: Battery voltage, level max and level high reset */
MWT_REAL PARTAP_PU_BtMin_GI = 77.0 ; /* initial value: Battery voltage, level min */
MWT_TIME PARTAP_PT_UBtMinDy_GI = 400 ; /* initial value: Battery voltage, level min, delay */
MWT_REAL PARTAP_PU_BtMinRst_GI = 74.0 ; /* initial value: Battery voltage, level min reset */
MWT_BOOL PARTAP_L_UBtDepAuLdCtClEn_GI = FALSE ; /* initial value: Enable Battery dependant auxiliary load contactor control */
MWT_REAL PARTAP_PU_BtOpAuLdCt_GI = 111.0 ; /* initial value: Battery voltage level to open auxiliary contactor */
MWT_TIME PARTAP_PT_UBtOpAuLdCtDy_GI = 5000 ; /* initial value: Battery voltage level to open auxiliary contactor, delay */
MWT_REAL PARTAP_PU_BtCdAuLdCt_GI = 114.0 ; /* initial value: Battery voltage level to close auxiliary contactor */
MWT_TIME PARTAP_PT_BtMinChTm_GI = 0 ; /* initial value: Minimum charging time */
MWT_BOOL PARTAP_L_OvIBtCgHghEn_GI = FALSE ; /* initial value: Enable battery charger overcurrent protection, level high */
MWT_BOOL PARTDP_L_OvIBtCgEn_GI = FALSE ; /* initial value: Enable battery charger overcurrent protection, level max */
MWT_REAL PARTDP_PI_BtCgMax_GI = 4999.0 ; /* initial value: Battery charger overcurrent, level max */
MWT_REAL PARTDP_PT_IBtCgMaxDy_GI = 0.1 ; /* initial value: Battery charger overcurrent, detection time, level max */
MWT_TIME PARTAP_PT_IBtCgFltHghDy_GI = 20 ; /* initial value: Filtered battery charger current detection time, level high */
MWT_BOOL PARTAP_L_OvIBtCpHghEn_GI = FALSE ; /* initial value: Enable battery chopper overcurrent protection, level high */
MWT_REAL PARTAP_PI_BtCpFltHgh_GI = 95.0 ; /* initial value: Filtered battery chopper current high level */
MWT_TIME PARTAP_PT_IBtCpFltHghDy_GI = 20 ; /* initial value: Filtered battery chopper current detection time, level high */
MWT_BOOL PARTAP_L_IBtCgTmSvEn_GI = FALSE ; /* initial value: Enable battery charger current limitation time-out supervision */
MWT_BOOL PARTAP_L_PraEnIBtCgTmSv_GI = FALSE ; /* initial value: Enable protective action due to battery charger current time-out failure */
MWT_BOOL PARTAP_L_SltEnIBtCgTmSv_GI = FALSE ; /* initial value: Enable isolation request after protective action due to battery charger current
time-out failure */
MWT_REAL PARTAP_PX_IBtCgLimHghFr_GI = 1.0 ; /* initial value: Battery charger current limit high fraction */
MWT_TIME PARTAP_PT_OffGhIBtCgLimHghDy_GI = 30000 ; /* initial value: Battery charger current limit high, off-glitch delay */
MWT_TIME PARTAP_PT_IBtCgLimHghDy_GI = 100000000 ; /* initial value: Battery charger current limit high, delay */
MWT_REAL PARTAP_PI_BtCgLim_GI = 5000.0 ; /* initial value: Battery charger current limit */
MWT_BOOL PARTAP_L_IBtTmSvEn_GI = FALSE ; /* initial value: Enable battery current limitation time-out supervision */
MWT_BOOL PARTAP_L_PraEnIBtTmSv_GI = TRUE ; /* initial value: Enable protective action due to battery current time-out failure */
MWT_BOOL PARTAP_L_SltEnIBtTmSv_GI = TRUE ; /* initial value: Enable isolation request after protective action due to battery current time-out failure
*/
MWT_REAL PARTAP_PX_IBtLimHghFr_GI = 1.0 ; /* initial value: Battery current limit high fraction */
MWT_TIME PARTAP_PT_OffGhIBtLimHghDy_GI = 600000 ; /* initial value: Battery current limit high, off-glitch delay */
MWT_BOOL PARTAP_L_EnChRsTpSm_GI = TRUE ; /* initial value: Enable Charging resistor temperature simulation */
MWT_REAL PARTAP_PH_AmTp_Max_GI = 70.0 ; /* initial value: Ambient temperature worst case */
MWT_REAL PARTAP_PT_ChRsCoTmCns_GI = 1400.0 ; /* initial value: Charging resistor coolant time constant */
MWT_REAL PARTAP_PH_ChRsTp_UpThr_GI = 250.0 ; /* initial value: Charging resistor upper temperature threshold */
MWT_REAL PARTAP_PH_ChRsTp_LowThr_GI = 200.0 ; /* initial value: Charging resistor lower temperature threshold */
MWT_REAL PARTAP_PR_ChRs_GI = 50.0 ; /* initial value: Charging resistor resistance */
MWT_REAL PARTAP_PK_ChRs_GI = 350.0 ; /* initial value: Charging resistor thermal capacitance */
MWT_REAL PARTAP_PC_DcLk_GI = 0.0027 ; /* initial value: Total DC-link capacitance */
MWT_BOOL PARTAP_L_EnChDcLkCnt_GI = FALSE ; /* initial value: Enable supervision of number of DC-link charging attempts */
MWT_UINT PARTAP_PN_ChDcLkCnt_GI = 3 ; /* initial value: Number of DC-link charging attempts within time window */
MWT_TIME PARTAP_PT_ChDcLkCnt_GI = 0 ; /* initial value: Time window for number of DC-link charging attempts */
MWT_BOOL PARTAP_L_EnChCtSv_GI = TRUE ; /* initial value: Enable charging contactor supervision */
MWT_BOOL PARTAP_L_EnSrCtSv_GI = TRUE ; /* initial value: Enable separation contactor supervision */
MWT_TIME PARTAP_PT_CtOnDy_GI = 500 ; /* initial value: Time on delay for contactor feedback supervision */
MWT_TIME PARTAP_PT_CtOfDy_GI = 500 ; /* initial value: Time off delay for contactor feedback supervision */
MWT_TIME PARTAP_PT_CtFi_GI = 32 ; /* initial value: Glitch filter time for contactor supervision */
MWT_BOOL PARTAP_L_SoCdAuLdCt_GI = FALSE ; /* initial value: Stop converter before auxiliary load contactor closing (The converter is stopped if the
converter is switching and the auxiliary load contactor shall be closed, mainly used when DCU controls an integrated battery charger) */
MWT_TIME PARTAP_PT_AuLdCtOnDy_GI = 3000 ; /* initial value: Auxiliary load contactor on time delay */
MWT_TIME PARTAP_PT_AuLdCtFi_GI = 32 ; /* initial value: Auxiliary load contactor glitch time */
MWT_TIME PARTAP_PT_AuLdCtOfDy_GI = 2000 ; /* initial value: Auxiliary load contactor off time delay */
MWT_REAL PARTAP_PU_DcLkChLv1_GI = 300.0 ; /* initial value: DC-link voltage, level 1 */
MWT_REAL PARTAP_PX_DcLkChLv2_GI = 0.8 ; /* initial value: DC-link voltage, level 2, fraction of AC input phase voltage, RMS value */
MWT_TIME PARTAP_PT_DcLkChDyLv1_GI = 300 ; /* initial value: Time delay before checking DC-link voltage, level 1 */
MWT_TIME PARTAP_PT_DcLkChDyLv2_GI = 1500 ; /* initial value: Time delay before checking DC-link voltage, level 2, only 2QC */
MWT_REAL PARTAP_PU_DhDcLk_Max_GI = 100.0 ; /* initial value: DC-link voltage discharged level and maximum DC-link voltage to switch on GDU power
supply */
MWT_TIME PARTAP_PT_DcLkDhDy_GI = 600 ; /* initial value: Delay time for DC-link discharge (Maximum time before protective action is
PT_DcLkDhDy+PT_FrOvp) */
MWT_TIME PARTAP_PT_FrOvp_GI = 500 ; /* initial value: Time to fire OVP */
MWT_BOOL PARTAP_L_EnDhDcLkCvSl_GI = TRUE ; /* initial value: Enable DC-link discharging in converter isolation state */
MWT_REAL PARTAP_PU_DcLkCvSlDh_GI = 1000.0 ; /* initial value: Voltage threshold to discharge DC-link in isolation state */
MWT_BOOL PARTAP_L_EnOvpFcTs_GI = TRUE ; /* initial value: Enable OVP functional test */
MWT_TIME PARTAP_PT_DyOvpFcTs_GI = 500 ; /* initial value: Max time for OVP functional test */
MWT_REAL PARTAP_PU_DcLkU_OvpFcTs_GI = 1000.0 ; /* initial value: Minimum DC-link voltage to run OVP test */
MWT_REAL PARTDP_PX_OvpFcTsClRt_GI = 0.25 ; /* initial value: OVP test during DC-link charging, control ratio */
MWT_REAL PARTDP_PT_OvpFcTsFrMax_GI = 0.005 ; /* initial value: OVP test during DC-link charging, OVP maximum firing time */
MWT_REAL PARTDP_PU_OvpFcTsRdy_GI = 30.0 ; /* initial value: OVP test during DC-link charging, minimum DC-link voltage drop to pass test */
MWT_BOOL PARTDP_L_OvpRsTpSvEn_GI = TRUE ; /* initial value: Enable OVP resistor overtemperature protection */
MWT_REAL PARTDP_PR_Ovp_GI = 4.0 ; /* initial value: OVP resistor overtemperature protection, resistance */
MWT_REAL PARTDP_PK_Ovp_GI = 875.0 ; /* initial value: OVP resistor overtemperature protection, thermal capacitance */
MWT_REAL PARTDP_PT_OvpCoCns_GI = 600.0 ; /* initial value: OVP resistor overtemperature protection, cooling time constant */
MWT_REAL PARTDP_PH_OvpMax_GI = 250.0 ; /* initial value: OVP resistor overtemperature protection, maximum OVP temperature */
MWT_REAL PARTDP_PH_OvpRst_GI = 225.0 ; /* initial value: OVP resistor overtemperature protection, reset OVP temperature */
MWT_REAL PARTAP_PI_SrCtISv_GI = 500.0 ; /* initial value: Max current for opening of contactor (For 2QC, AC input phase current, in DC system an
external DC current measurement is needed) */
MWT_REAL PARTAP_PI_ChCtISv_GI = 500.0 ; /* initial value: Max current for opening of charging contactor (For 2QC, AC input phase current, in DC system
an external DC current measurement is needed. If no DC-current is measured the parameter value 0 can be used to always request PrSd to avoid opening with current)
*/
MWT_TIME PARTAP_PT_SrCtISvDy_GI = 200 ; /* initial value: Max time opening of contactors can be disabled due to high current */
MWT_BOOL PARTAP_L_EnHHtSv_GI = TRUE ; /* initial value: Enable heatsink temperature supervision */
MWT_BOOL PARTAP_L_EnIgbtOvLdSv_GI = TRUE ; /* initial value: Enable IGBT overload protection */
MWT_REAL PARTAP_PH_HtSvMax_GI = 80.0 ; /* initial value: Heatsink temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_HtSvHgh2_GI = 100.0 ; /* initial value: Heatsink temperature supervision, level high2, opening of auxiliary load contactor */
MWT_REAL PARTAP_PH_HtSvHgh1_GI = 75.0 ; /* initial value: Heatsink temperature supervision, level high1, indication level */
MWT_REAL PARTAP_PH_HtSvRst_GI = 70.0 ; /* initial value: Heatsink temperature supervision, reset level */
MWT_TIME PARTAP_PT_HHtSvMax_GI = 1000 ; /* initial value: Heatsink temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HHtSvHgh2_GI = 1000 ; /* initial value: Heatsink temperature supervision, detection time for level high2 */
MWT_TIME PARTAP_PT_HHtSvHgh1_GI = 1000 ; /* initial value: Heatsink temperature supervision, detection time for level high1 */
MWT_REAL PARTAP_PI_HtSvHgh2_GI = 250.0 ; /* initial value: Phase current limit at converter heatsink temperature, level high2, peak value */
MWT_REAL PARTAP_PX_HtSvCntLim_GI = 0.67 ; /* initial value: Continuous current level, fraction of full phase current limit */
MWT_TIME PARTAP_PT_HtSvOvLdLim_GI = 5000 ; /* initial value: IGBT overload failure (current limit), detection time */
MWT_UINT PARTAP_PX_HHtSvMax_GI = 2 ; /* initial value: Heatsink temperature supervision, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_HHtSvMaxTmWn_GI = 1800000 ; /* initial value: Heatsink temperature supervision, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_IgbtOvLd_GI = 2 ; /* initial value: IGBT overload supervision (current limit), maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_IgbtOvLd_GI = 1800000 ; /* initial value: IGBT overload supervision (current limit), time window for monitoring the number of
failures */
MWT_REAL PARTAP_PH_RctHtMax_GI = 80.0 ; /* initial value: Battery rectifier heat-sink supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_RctHtSvHgh_GI = 70.0 ; /* initial value: Battery rectifier heat-sink temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_RctHtSvRst_GI = 70.0 ; /* initial value: Battery rectifier heat-sink temperature supervision, reset level */
MWT_TIME PARTAP_PT_RctHtSvMax_GI = 1000 ; /* initial value: Battery rectifier heat-sink temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_RctHtSvHgh_GI = 1000 ; /* initial value: Battery rectifier heat-sink temperature supervision, detection time for level high */
MWT_BOOL PARTAP_L_EnHTfSv_GI = FALSE ; /* initial value: Enable transformer temperature supervision */
MWT_REAL PARTAP_PH_TfSvMax_GI = 227.0 ; /* initial value: Transformer temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_TfSvHgh2_GI = 227.0 ; /* initial value: Transformer temperature supervision, level high2, opening of auxiliary load contactor */
MWT_REAL PARTAP_PH_TfSvHgh1_GI = 227.0 ; /* initial value: Transformer temperature supervision, level high1, indication level */
MWT_REAL PARTAP_PH_TfSvRst_GI = 227.0 ; /* initial value: Transformer temperature supervision, reset level */
MWT_TIME PARTAP_PT_HTfSvMax_GI = 1000 ; /* initial value: Transformer temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HTfSvHgh2_GI = 1000 ; /* initial value: Transformer temperature supervision, detection time for level high2 */
MWT_TIME PARTAP_PT_HTfSvHgh1_GI = 1000 ; /* initial value: Transformer temperature supervision, detection time for level high1 */
MWT_BOOL PARTAP_L_EnLngTmOvLdSv_GI = TRUE ; /* initial value: Enable long-term overload protection */
MWT_TIME PARTAP_PT_LngTmOvLdInt_GI = 180000 ; /* initial value: Time constant, load integral, long-term overload protection */
MWT_REAL PARTAP_PI_LngTmOvLdMax_GI = 330.0 ; /* initial value: Long-term overload protection, peak phase current, level max */
MWT_REAL PARTAP_PI_LngTmOvLdHgh_GI = 310.0 ; /* initial value: Long-term overload protection, peak phase current, level high */
MWT_REAL PARTAP_PI_LngTmOvLdRst_GI = 290.0 ; /* initial value: Long-term overload protection, peak phase current, reset level */
MWT_TIME PARTAP_PT_LngTmOvLdHgh_GI = 300000 ; /* initial value: Long-term overload protection, detection time for level high */
MWT_BOOL PARTAP_L_EnHBtSv_GI = TRUE ; /* initial value: Enable battery temperature supervision */
MWT_TIME PARTAP_PT_HBtSvMax_GI = 1000 ; /* initial value: Battery temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HBtSvHgh_GI = 1000 ; /* initial value: Battery temperature supervision, detection time for level high */
MWT_BOOL PARTAP_L_EnHNteArSv_GI = TRUE ; /* initial value: Enable internal air temperature supervision */
MWT_REAL PARTAP_PH_NteArSvMax_GI = 75.0 ; /* initial value: Internal air temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_NteArSvHgh2_GI = 150.0 ; /* initial value: Internal air temperature supervision, level high2, opening of auxilaty load contactor */
MWT_REAL PARTAP_PH_NteArSvHgh1_GI = 150.0 ; /* initial value: Internal air temperature supervision, level high1, indication level */
MWT_REAL PARTAP_PH_NteArSvRst_GI = 70.0 ; /* initial value: Internal air temperature supervision, reset level */
MWT_TIME PARTAP_PT_HNteArSvMax_GI = 1000 ; /* initial value: Internal air temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HNteArSvHgh2_GI = 1000 ; /* initial value: Internal air temperature supervision, detection time for level high2 */
MWT_TIME PARTAP_PT_HNteArSvHgh1_GI = 1000 ; /* initial value: Internal air temperature supervision, detection time for level high1 */
MWT_BOOL PARTAP_L_EnHNd1Sv_GI = FALSE ; /* initial value: Enable inductor 1 temperature supervision */
MWT_BOOL PARTAP_L_EnHNd2Sv_GI = FALSE ; /* initial value: Enable inductor 2 temperature supervision */
MWT_BOOL PARTAP_L_EnHNd3Sv_GI = FALSE ; /* initial value: Enable inductor 3 temperature supervision */
MWT_REAL PARTAP_PH_NdSvMax_GI = 160.0 ; /* initial value: Inductor temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_NdSvHgh_GI = 150.0 ; /* initial value: Inductor temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_NdSvRst_GI = 50.0 ; /* initial value: Inductor temperature supervision, reset level */
MWT_TIME PARTAP_PT_HNdSvMax_GI = 1000 ; /* initial value: Inductor temperature supervision, detection time for level max */
MWT_TIME PARTAP_PT_HNdSvHgh_GI = 1000 ; /* initial value: Inductor temperature supervision, detection time for level high */
MWT_TIME PARTAP_PT_HNdSnFl_GI = 2048 ; /* initial value: Detection time, double inductor sensor failure */
MWT_BOOL PARTAP_L_DcCrBkSvEn_GI = FALSE ; /* initial value: Enable DC circuit breaker supervision */
MWT_BOOL PARTAP_L_DcCrBkSvSltEn_GI = FALSE ; /* initial value: Enable DC circuit breaker isolation request */
MWT_REAL PARTAP_PU_DcLkLowDcCrBkSv_GI = 0.0 ; /* initial value: DC link voltage low level DC circuit breaker supervision */
MWT_TIME PARTAP_PT_DcCrBkSvDy_GI = 0 ; /* initial value: DC circuit breaker supervision delay */
MWT_TIME PARTAP_PT_DcCrBkTrpRunTm_GI = 0 ; /* initial value: DC circuit breaker tripped allowed running time, before isolation request */
MWT_BOOL PARTAP_L_FnCrBkSvEn_GI = FALSE ; /* initial value: Enable fan circuit breaker supervision */
MWT_BOOL PARTAP_L_FnCrBkSvPrBcEn_GI = FALSE ; /* initial value: Enable protective blocking due to fan circuit breaker time-out failure */
MWT_BOOL PARTAP_L_FnCrBkSvSltEn_GI = FALSE ; /* initial value: Enable isolation request due to fan circuit breaker time-out failure */
MWT_TIME PARTAP_PT_FnCrBkFbOpGhDy_GI = 64 ; /* initial value: Fan circuit breaker feedback open glitch delay */
MWT_TIME PARTAP_PT_FnCrBkOffGhCvOpDy_GI = 600000 ; /* initial value: Converter in operation off glitch delay */
MWT_TIME PARTAP_PT_FnCrBkTrpRunTm_GI = 100000000 ; /* initial value: Fan circuit breaker tripped allowed running time */
MWT_BOOL PARTAP_L_FnCtSvEn_GI = FALSE ; /* initial value: Enable fan contactor supervision */
MWT_BOOL PARTAP_L_FnCtSvPrBcEn_GI = FALSE ; /* initial value: Enable protective action due to fan contactor on time-out failure */
MWT_BOOL PARTAP_L_FnCtSvSltEn_GI = FALSE ; /* initial value: Enable isolation request due to fan contactor on time-out failure */
MWT_TIME PARTAP_PT_FnCtRp_GI = 500 ; /* initial value: Fan contactor response time */
MWT_TIME PARTAP_PT_FnCtOnTmOutFlHHtVd_GI = 100000000 ; /* initial value: Fan contactor on time-out failure and high heatsink temp valid, waiting time
*/
MWT_REAL PARTDP_PI_DcLnErfMax_GI = 400.0 ; /* initial value: DC-link earth fault detection, level max */
MWT_BOOL PARTDP_L_DsTrpLvSvDcLnErf_GI = TRUE ; /* initial value: Disable trip level supervision of earth fault current */
MWT_BOOL PARTDP_L_DsErfDet_GI = TRUE ; /* initial value: Disable earth fault detection */
MWT_REAL PARTDP_PX_ErfCntThr_GI = 10.0 ; /* initial value: Earth fault counter threshold */
MWT_REAL PARTAP_PI_DfInFltMax2qc_GI = 100.0 ; /* initial value: Filtered differential input current max level (2QC) */
MWT_TIME PARTAP_PT_DfInFltMaxDy2qc_GI = 1000 ; /* initial value: Filtered differential input current max level delay (2QC) */
MWT_BOOL PARTAP_L_EnErfSvIDf2qc_GI = FALSE ; /* initial value: Enable earth fault supervision (2QC) */
MWT_BOOL PARTAP_L_PraEnErfSvIDf2qc_GI = FALSE ; /* initial value: Protective action enable earth fault supervision (2QC) */
MWT_REAL PARTDP_PT_2qcCal_GI = 0.1 ; /* initial value: Calibration time for 2QC signals */
MWT_REAL PARTDP_PT_3PhCal_GI = 0.1 ; /* initial value: Calibration time for 3-phase inverter signals */
MWT_TIME PARTAP_PT_EnIPhCalDy_GI = 100 ; /* initial value: Time delay to enable calibration of phase currents after fulfilled criteria */
MWT_REAL PARTDP_PI_PhCalOsMax_Rw_GI = 20.0 ; /* initial value: Phase current calibration, maximum offset */
MWT_REAL PARTDP_PI_PhCalRipMax_Rw_GI = 20.0 ; /* initial value: Phase current calibration, maximum ripple */
MWT_TIME PARTAP_PT_EnUDcLkCalDy_GI = 100 ; /* initial value: Time delay to enable calibration of DC-link voltage after fulfilled criteria */
MWT_REAL PARTDP_PU_DcLkCalOsMax_Rw_GI = 20.0 ; /* initial value: DC-link voltage calibration, maximum offset */
MWT_REAL PARTDP_PU_DcLkCalRipMax_Rw_GI = 30.0 ; /* initial value: DC-link voltage calibration, maximum ripple */
MWT_TIME PARTAP_PT_EnU3PhCalDy_GI = 100 ; /* initial value: Time delay to enable calibration of 3-phase output load voltage after fulfilled criteria
*/
MWT_REAL PARTDP_PU_3PhCalOsMax_Rw_GI = 10.0 ; /* initial value: 3-phase output load voltage calibration, maximum offset */
MWT_REAL PARTDP_PU_3PhCalRipMax_Rw_GI = 10.0 ; /* initial value: 3-phase output load voltage calibration, maximum ripple */
MWT_TIME PARTAP_PT_EnIPhInCalDy_GI = 100 ; /* initial value: Time delay to enable calibration of AC input phase current after fulfilled criteria */
MWT_REAL PARTDP_PI_PhInCalOsMax_Rw_GI = 25.0 ; /* initial value: AC input phase current calibration, maximum offset */
MWT_REAL PARTDP_PI_PhInCalRipMax_Rw_GI = 25.0 ; /* initial value: AC input phase current calibration, maximum ripple */
MWT_TIME PARTAP_PT_EnIDfInCalDy_GI = 100 ; /* initial value: Time delay to enable calibration of differential current after fulfilled criteria */
MWT_REAL PARTDP_PI_DfInCalOsMax_Rw_GI = 15.0 ; /* initial value: Differential current, maximum offset */
MWT_REAL PARTDP_PI_DfInCalRipMax_Rw_GI = 15.0 ; /* initial value: Differential current, maximum ripple */
MWT_REAL PARTDP_PI_RctCalOsMax_Rw_GI = 10.0 ; /* initial value: HPP rectifier current calibration, maximum offset */
MWT_REAL PARTDP_PI_RctCalRipMax_Rw_GI = 10.0 ; /* initial value: HPP rectifier current calibration, maximum ripple */
MWT_UINT PARTAP_PX_CalFl_GI = 2 ; /* initial value: Calibration supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_CalFl_GI = 1800000 ; /* initial value: Calibration supervision, time window for monitoring the number of failures */
MWT_REAL PARTAP_PU_DcLkOnGduPSp_GI = 50.0 ; /* initial value: Maximum DC-link voltage to switch on GDU power supply */
MWT_TIME PARTAP_PT_OnGduPSpDy_GI = 1000 ; /* initial value: Switch on GDU power supply, delay */
MWT_REAL PARTDP_PX_AnMmDfMax_GI = 0.05 ; /* initial value: Maximum difference between A/D-converters, ratio of full scale */
MWT_REAL PARTDP_PT_AnMmDfDy_GI = 0.04 ; /* initial value: Detection time, maximum difference between fast A/D-converters */
MWT_BOOL PARTDP_L_FSgSvIgbtPoaEn_GI = FALSE ; /* initial value: Enable switching frequency supervision 3-phase inverter, switching command */
MWT_BOOL PARTDP_L_FSgSvIgbt2qcEn_GI = FALSE ; /* initial value: Enable switching frequency supervision 2QC, switching command */
MWT_BOOL PARTDP_L_FSgSvGduPoaEn_GI = FALSE ; /* initial value: Enable switching frequency supervision 3-phase inverter, switching feedback */
MWT_BOOL PARTDP_L_FSgSvGdu2qcEn_GI = FALSE ; /* initial value: Enable switching frequency supervision 2QC, switching feedback */
MWT_REAL PARTDP_PX_FSgSvDvMax_GI = 1.0 ; /* initial value: Switching frequency supervision, max deviation, ratio of switching frequency */
MWT_BOOL PARTDP_L_EnIRctFpgaSv_GI = FALSE ; /* initial value: Enable HPP rectifier overcurrent protection, level max */
MWT_REAL PARTDP_PI_RctMax_GI = 800.0 ; /* initial value: HPP rectifier overcurrent protection, level max */
MWT_UDINT PARTDP_PT_IRctMaxDy_GI = 0 ; /* initial value: HPP rectifier overcurrent protection, detection time for level max */
MWT_BOOL PARTAP_L_EnIRctBalSv_GI = FALSE ; /* initial value: Enable HPP rectifier current unbalance protection */
MWT_REAL PARTAP_PI_RctBalSvMax_GI = 120.0 ; /* initial value: HPP rectifier current unbalance protection, level max */
MWT_TIME PARTAP_PT_IRctBalSvDy_GI = 2500 ; /* initial value: HPP rectifier current unbalance protection, detection time, level max */
MWT_BOOL PARTAP_L_2qcEn_GI = FALSE ; /* initial value: Enable 2QC operation */
MWT_BOOL PARTDP_L_2qcUDcLk2Mm_GI = FALSE ; /* initial value: Use DC-link voltage 2 for DC-link voltage control */
MWT_REAL PARTDP_PN_UDcLkRef_GI = 1.0 ; /* initial value: DC-link voltage reference, filter constant for LP-filter */
MWT_REAL PARTAP_PI_PhInRmsHgh2_GI = 3000.0 ; /* initial value: AC input phase current RMS high 2 level */
MWT_TIME PARTAP_PT_IPhInRmsHgh2Dy_GI = 120000 ; /* initial value: AC Input phase current RMS high 2 level, delay */
MWT_REAL PARTAP_PI_PhInRmsHgh1_GI = 3000.0 ; /* initial value: AC input phase current RMS high 1 level */
MWT_TIME PARTAP_PT_IPhInRmsHgh1Dy_GI = 120000 ; /* initial value: AC Input phase current RMS high 1 level, delay */
MWT_REAL PARTDP_PT_SiPhBc2qcTmWnd1_GI = 10.0 ; /* initial value: Single phase blocking (SPB) supervision 2QC, time window 1 */
MWT_DINT PARTDP_PX_SiPhBc2qcMaxWnd1_GI = 200 ; /* initial value: Single Phase Blocking (SPB) supervision 2QC, maximum number of SPB within time
window 1 */
MWT_REAL PARTDP_PT_SiPhBc2qcTmWnd2_GI = 10.0 ; /* initial value: Single Phase Blocking (SPB) supervision 2QC, time window 2 */
MWT_DINT PARTDP_PX_SiPhBc2qcMaxWnd2_GI = 950 ; /* initial value: Single Phase Blocking (SPB) supervision 2QC, maximum number of time window 1 within
time window 2 */
MWT_REAL PARTDP_PI_PhIn2qcMax_GI = 5000.0 ; /* initial value: AC input phase overcurrent protection, level max */
MWT_UDINT PARTDP_PT_IPhIn2qcMaxDy_GI = 256 ; /* initial value: AC input phase overcurrent protection, detection time for level max */
MWT_BOOL PARTAP_L_EnPBalSv_GI = FALSE ; /* initial value: Enable power balance supervision */
MWT_REAL PARTAP_PP_BalSv_GI = 10000.0 ; /* initial value: Maximum difference between 2QC input power and output power */
MWT_TIME PARTAP_PT_PBalSv_GI = 500 ; /* initial value: Power balance supervision, detection time */
MWT_UINT PARTAP_PX_UBtMmFl_GI = 2 ; /* initial value: Battery voltage measurement supervision, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_UBtMmFl_GI = 1800000 ; /* initial value: Battery voltage measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IPhMmFl_GI = 2 ; /* initial value: Phase current measurement supervision, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_IPhMmFl_GI = 1800000 ; /* initial value: Phase current measurement supervision, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_U3PhMmFl_GI = 2 ; /* initial value: 3-phase output load voltage measurement supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_U3PhMmFl_GI = 1800000 ; /* initial value: 3-phase output load voltage measurement supervision, time window for monitoring the
number of failures */
MWT_UINT PARTAP_PX_IPhInMmFl_GI = 2 ; /* initial value: AC input phase current measurement supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IPhInMmFl_GI = 1800000 ; /* initial value: AC input phase current measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UPhInMmFl_GI = 2 ; /* initial value: AC input phase voltage measurement supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_UPhInMmFl_GI = 1800000 ; /* initial value: AC input phase voltage measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UDcLkMmFl_GI = 2 ; /* initial value: DC-link voltage measurement supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_UDcLkMmFl_GI = 1800000 ; /* initial value: DC-link voltage measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IDfInMmFl_GI = 2 ; /* initial value: Differential current measurement supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IDfInMmFl_GI = 1800000 ; /* initial value: Differential current measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UDcLkDfFl_GI = 2 ; /* initial value: DC-link voltage difference supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_UDcLkDfFl_GI = 1800000 ; /* initial value: DC-link voltage difference supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IBtCgMmFl_GI = 2 ; /* initial value: Battery charger current measurement supervision, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IBtCgMmFl_GI = 1800000 ; /* initial value: Battery charger current measurement supervision, time window for monitoring the number
of failures */
MWT_UINT PARTAP_PX_IBtMmFl_GI = 2 ; /* initial value: Battery current measurement supervision, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_IBtMmFl_GI = 1800000 ; /* initial value: Battery current measurement supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IRctMmFl_GI = 2 ; /* initial value: HPP rectifier current measurement supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_IRctMmFl_GI = 1800000 ; /* initial value: HPP rectifier current measurement supervision, time window for monitoring the number of
failures */
MWT_REAL PARTDP_PT_3PhMmSvRipDy_GI = 110.0 ; /* initial value: Delay to detect ripple failure of measured 3-phase converter signals */
MWT_REAL PARTDP_PT_2qcMmSvRipDy_GI = 110.0 ; /* initial value: Delay to detect ripple failure of measured 2QC signals */
MWT_REAL PARTDP_PT_BtCpMmSvRipDy_GI = 110.0 ; /* initial value: Delay to detect ripple failure of measured BtCp signals */
MWT_UINT PARTAP_PX_GduFbOnPoaFl_GI = 2 ; /* initial value: Both GDU feedback shows on in POA, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_GduFbOnPoaFl_GI = 1800000 ; /* initial value: Both GDU feedback shows on in POA, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_GduFbSvPoa_GI = 2 ; /* initial value: GDU feedback supervision POA, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_GduFbSvPoa_GI = 1800000 ; /* initial value: GDU feedback supervision POA, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_GduFbSvOvp_GI = 2 ; /* initial value: GDU feedback supervision OVP, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_GduFbSvOvp_GI = 1800000 ; /* initial value: GDU feedback supervision OVP, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_GduFbSv2qc_GI = 1 ; /* initial value: GDU feedback supervision 2QC, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_GduFbSv2qc_GI = 1800000 ; /* initial value: GDU feedback supervision 2QC, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvUDcLk_GI = 1000 ; /* initial value: DC-link overvoltage protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_OvUDcLk_GI = 1000 ; /* initial value: DC-link overvoltage protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_UnUDcLk_GI = 1000 ; /* initial value: DC-link undervoltage protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_UnUDcLk_GI = 1000 ; /* initial value: DC-link undervoltage protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvIPh_GI = 2 ; /* initial value: Phase overcurrent protection, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_OvIPh_GI = 1800000 ; /* initial value: Phase overcurrent protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_IPhTmWndFl_GI = 2 ; /* initial value: Supervision of phase current SPB, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_IPhTmWndFl_GI = 1800000 ; /* initial value: Supervision of phase current SPB, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_IPhClTmOut_GI = 2 ; /* initial value: AC current limitation time-out supervision, maximum number of allowed failures within a
fixed time window
*/
MWT_TIME PARTAP_PT_IPhClTmOut_GI = 1800000 ; /* initial value: AC current limitation time-out supervision, time window for monitoring the number of
failures
*/
MWT_UINT PARTAP_PX_IPhClRmsTmFl_GI = 2 ; /* initial value: RMS phase current limitation time-out failure, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IPhClRmsTmFl_GI = 1800000 ; /* initial value: RMS phase current limitation time-out failure, time window for monitoring the number
of failures */
MWT_UINT PARTAP_PX_IPhClTmWnd1Fl_GI = 2 ; /* initial value: Too many RMS phase current limitations in time window, maximum number of allowed
failures within a fixed time window */
MWT_TIME PARTAP_PT_IPhClTmWnd1Fl_GI = 1800000 ; /* initial value: Too many RMS phase current limitations in time window, time window for monitoring
the number of failures */
MWT_UINT PARTAP_PX_IPhDcFl_GI = 2 ; /* initial value: High DC-current component in phase currents, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_IPhDcFl_GI = 1800000 ; /* initial value: High DC-current component in phase currents, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IPhBalFl_GI = 2 ; /* initial value: Phase current unbalance protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_IPhBalFl_GI = 1800000 ; /* initial value: Phase current unbalance protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_CtFbSvFl_GI = 2 ; /* initial value: Contactor supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_CtFbSvFl_GI = 1800000 ; /* initial value: Contactor supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_AuLdCtFbSvFl_GI = 2 ; /* initial value: Auxiliary load contactor supervision, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_AuLdCtFbSvFl_GI = 1800000 ; /* initial value: Auxiliary load contactor supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UDcLkChSv_GI = 2 ; /* initial value: DC-link voltage check during DC-link charging, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_UDcLkChSv_GI = 1800000 ; /* initial value: DC-link voltage check during DC-link charging, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UDcLkDhSv_GI = 2 ; /* initial value: DC-link voltage check during DC-link discharging, maximum number of allowed failures within
a fixed time window */
MWT_TIME PARTAP_PT_UDcLkDhSv_GI = 1800000 ; /* initial value: DC-link voltage check during DC-link discharging, time window for monitoring the number
of failures */
MWT_UINT PARTAP_PX_OvpFcTsFl_GI = 2 ; /* initial value: OVP test during DC-link charging, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_OvpFcTsFl_GI = 1800000 ; /* initial value: OVP test during DC-link charging, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvpRsTpFl_GI = 2 ; /* initial value: OVP resistor temperature protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_OvpRsTpFl_GI = 1800000 ; /* initial value: OVP resistor temperature protection, time window for monitoring the number of failures
*/
MWT_UINT PARTAP_PX_SrCtISv_GI = 2 ; /* initial value: Check of current through separation contactor, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_SrCtISv_GI = 1800000 ; /* initial value: Check of current through separation contactor, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_3PhSzFl_GI = 2 ; /* initial value: Synchronization to 3-phase bus, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_3PhSzFl_GI = 500000 ; /* initial value: Synchronization to 3-phase bus, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_PBalFl_GI = 2 ; /* initial value: Power balance supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_PBalFl_GI = 1800000 ; /* initial value: Power balance supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvUPhInRmsFl_GI = 4 ; /* initial value: AC input phase overvoltage protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_OvUPhInRmsFl_GI = 1800000 ; /* initial value: AC input phase overvoltage protection, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_UnUPhInRmsFl_GI = 2 ; /* initial value: AC input phase undervoltage protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_UnUPhInRmsFl_GI = 1800000 ; /* initial value: AC input phase undervoltage protection, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_OvIPhIn_2qc_GI = 2 ; /* initial value: AC input phase overcurrent protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_OvIPhIn_2qc_GI = 1800000 ; /* initial value: AC input phase overcurrent protection, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_OvIPhInRms_GI = 2 ; /* initial value: AC input phase phase current supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_OvIPhInRms_GI = 1800000 ; /* initial value: AC input phase phase current supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IPhInTmWndFl_GI = 2 ; /* initial value: Supervision of AC input phase current SPB, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_IPhInTmWndFl_GI = 1800000 ; /* initial value: Supervision of AC input phase current SPB, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IDfInErf_GI = 2 ; /* initial value: Earth fault detection (2QC), maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_IDfInErf_GI = 1800000 ; /* initial value: Earth fault detection (2QC), time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvUBtFl_GI = 2 ; /* initial value: Battery overvoltage protection, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_OvUBtFl_GI = 1800000 ; /* initial value: Battery overvoltage protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_UnUBtFl_GI = 2 ; /* initial value: Battery undervoltage protection, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_UnUBtFl_GI = 1800000 ; /* initial value: Battery undervoltage protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvIBtCg_GI = 2 ; /* initial value: Battery charger overcurrent protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_OvIBtCg_GI = 1800000 ; /* initial value: Battery charger overcurrent protection, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_IBtClTmOut_GI = 2 ; /* initial value: Battery charger current limitation time supervision, maximum number of allowed failures
within a fixed time window */
MWT_TIME PARTAP_PT_IBtClTmOut_GI = 600000 ; /* initial value: Battery charger current limitation time supervision, time window for monitoring the
number of failures */
MWT_UINT PARTAP_PX_DcCrBrTp_GI = 2 ; /* initial value: DC circuit breaker supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_DcCrBrTp_GI = 1800000 ; /* initial value: DC circuit breaker supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_FnCrFl_GI = 2 ; /* initial value: Fan power circuit supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_FnCrFl_GI = 1800000 ; /* initial value: Fan power circuit supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_HTfSvMax_GI = 2 ; /* initial value: Transformer overtemperature protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_HTfSvMaxTmWn_GI = 1800000 ; /* initial value: Transformer overtemperature protection, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_LngTmOvLd_GI = 1 ; /* initial value: Long-term overload protection, maximum number of allowed failures within a fixed time window
*/
MWT_TIME PARTAP_PT_LngTmOvLd_GI = 7200000 ; /* initial value: Long-term overload protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_HBtSvMax_GI = 2 ; /* initial value: Battery overtemperature protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_HBtSvMaxTmWn_GI = 1800000 ; /* initial value: Battery overtemperature protection, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_HNteArSvMax_GI = 2 ; /* initial value: Internal air overtemperature protection, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_HNteArSvMaxTmWn_GI = 1800000 ; /* initial value: Internal air overtemperature protection, time window for monitoring the number
of failures */
MWT_UINT PARTAP_PX_HNdSvMax_GI = 2 ; /* initial value: Inductor overtemperature protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_HNdSvMaxTmWn_GI = 1800000 ; /* initial value: Inductor overtemperature protection, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_FSgFl_GI = 2 ; /* initial value: IGBT switching frequency supervision, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_FSgFl_GI = 1800000 ; /* initial value: IGBT switching frequency supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_PSpFl_GI = 2 ; /* initial value: Power supply unit failure detection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_PSpFl_GI = 1000 ; /* initial value: Power supply unit failure detection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_MvbWdgFl_GI = 1000 ; /* initial value: MVB supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_MvbWdgFl_GI = 30000 ; /* initial value: MVB supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_AdcMmFl_GI = 2 ; /* initial value: AD-converter supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_AdcMmFl_GI = 1800000 ; /* initial value: AD-converter supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_DspOvLdFl_GI = 2 ; /* initial value: DSP overload and DSP stack supervision, maximum number of allowed failures within a fixed
time window */
MWT_TIME PARTAP_PT_DspOvLdFl_GI = 1800000 ; /* initial value: DSP overload and DSP stack supervision, time window for monitoring the number of
failures */
MWT_UINT PARTAP_PX_Nte15VFl_GI = 2 ; /* initial value: Internal ¡À15V supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_Nte15VFl_GI = 1800000 ; /* initial value: Internal ¡À15V supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_25MHzSvFl_GI = 2 ; /* initial value: 25 MHz clock supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_25MHzSvFl_GI = 1800000 ; /* initial value: 25 MHz clock supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_DspWdAlm_GI = 2 ; /* initial value: DSP watchdog supervision, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_DspWdAlm_GI = 1800000 ; /* initial value: DSP watchdog supervision, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_DspFpgaComFl_GI = 2 ; /* initial value: DSP-FPGA communication failure, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_DspFpgaComFl_GI = 1800000 ; /* initial value: DSP-FPGA communication failure, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_OvIRct_GI = 2 ; /* initial value: HPP rectifier overcurrent protection, maximum number of allowed failures within a fixed time
window */
MWT_TIME PARTAP_PT_OvIRct_GI = 1800000 ; /* initial value: HPP rectifier overcurrent protection, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_IRctBalSv_GI = 2 ; /* initial value: HPP rectifier current unbalance protection, maximum number of allowed failures within a
fixed time window */
MWT_TIME PARTAP_PT_IRctBalSv_GI = 1800000 ; /* initial value: HPP rectifier current unbalance protection, time window for monitoring the number of
failures */
MWT_BOOL PARTAP_L_PrlAcm_GI = TRUE ; /* initial value: Select Parallel ACM operation */
MWT_TIME PARTAP_PT_CvOpMn_GI = 3000 ; /* initial value: Minimum time between activations */
MWT_TIME PARTAP_PT_SfSdCvSa_GI = 3000 ; /* initial value: Minimum time from Soft shutdown request to activation */
MWT_TIME PARTAP_PT_FsSdCvSa_GI = 3000 ; /* initial value: Minimum time from Fast shutdown request to activation */
MWT_TIME PARTAP_PT_PrSdCvSa_GI = 3000 ; /* initial value: Minimum time from Protective shutdown request to charging */
MWT_UINT PARTAP_PX_NteCoFl_GI = 2 ; /* initial value: Internal cooling failure, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_NteCoFl_GI = 1800000 ; /* initial value: Internal cooling failure, time window for monitoring the number of failures */
MWT_UINT PARTAP_PX_TpSnFl_GI = 2 ; /* initial value: Temperature sensor failure, maximum number of allowed failures within a fixed time window */
MWT_TIME PARTAP_PT_TpSnFl_GI = 1800000 ; /* initial value: Temperature sensor failure failure, time window for monitoring the number of failures */
MWT_TIME PARTAP_PT_AyActMtFn_GI = 1000 ; /* initial value: Time delay to start fan when auxiliary voltage is available */
MWT_REAL PARTAP_PV_ExtFnTnHgh_GI = 7.0 ; /* initial value: High vehicle speed, upper level */
MWT_REAL PARTAP_PV_ExtFnTnLow_GI = 5.0 ; /* initial value: High vehicle speed, lower level */
MWT_REAL PARTAP_PH_HtFuSpeOnHgh_GI = 55.0 ; /* initial value: Heat sink temp 1/1-speed on, high vehicle speed */
MWT_REAL PARTAP_PH_HtFuSpeOfHgh_GI = 40.0 ; /* initial value: Heat sink temp 1/1-speed off, high vehicle speed */
MWT_REAL PARTAP_PH_HtFuSpeOnLow_GI = 60.0 ; /* initial value: Heat sink temp 1/1-speed on, low vehicle speed */
MWT_REAL PARTAP_PH_HtFuSpeOfLow_GI = 50.0 ; /* initial value: Heat sink temp 1/1-speed off, low vehicle speed */
MWT_REAL PARTAP_PH_NteArFuSpeOnHgh_GI = 55.0 ; /* initial value: Internal air temp 1/1-speed on, high vehicle speed */
MWT_REAL PARTAP_PH_NteArFuSpeOfHgh_GI = 45.0 ; /* initial value: Internal air temp 1/1-speed off, high vehicle speed */
MWT_REAL PARTAP_PH_NteArFuSpeOnLow_GI = 60.0 ; /* initial value: Internal air temp 1/1-speed on, low vehicle speed */
MWT_REAL PARTAP_PH_NteArFuSpeOfLow_GI = 50.0 ; /* initial value: Internal air temp 1/1-speed off, low vehicle speed */
MWT_TIME PARTAP_PT_ExtFnFl_GI = 10000 ; /* initial value: Allowed time between external fan order and acknowledge */
MWT_TIME PARTAP_PT_DyHfFuExtFnSpe_GI = 4000 ; /* initial value: Time delay 1/2-1/1-speed order external fan */
MWT_TIME PARTAP_PT_DyFuHfExtFnSpe_GI = 6000 ; /* initial value: Time delay 1/1-1/2-speed order external fan */
MWT_TIME PARTAP_PT_HfExtFnSpeMn_GI = 20000 ; /* initial value: Minimum time between 1/2-speed orders external fan */
MWT_BOOL PARTAP_L_ExtTwoSpFn_GI = TRUE ; /* initial value: Two speed external fan in use */
MWT_REAL PARTAP_PH_BrdFuSpeOfLow_GI = 80.0 ; /* initial value: DCU board temp 1/1-speed off, low vehicle speed */
MWT_REAL PARTAP_PH_BrdFuSpeOnLow_GI = 85.0 ; /* initial value: DCU board temp 1/1-speed on, low vehicle speed */
MWT_REAL PARTAP_PH_BrdFuSpeOfHgh_GI = 80.0 ; /* initial value: DCU board temp 1/1-speed off, high vehicle speed */
MWT_REAL PARTAP_PH_BrdFuSpeOnHgh_GI = 85.0 ; /* initial value: DCU board temp 1/1-speed on, high vehicle speed */
MWT_TIME PARTAP_PT_FnOfDy_GI = 60000 ; /* initial value: Delay time to keep fan enabled after activation order has withdrawn */
MWT_REAL PARTAP_PH_NteTpDfMax_GI = 100.0 ; /* initial value: Temperature difference to indicate internal cooling problem */
MWT_TIME PARTAP_PT_NteTpDf_GI = 5000 ; /* initial value: Time filter for internal cooling problem supervision */
MWT_BOOL PARTAP_L_SfSdNteCoFl_GI = FALSE ; /* initial value: Select Soft Shutdown in case of internal cooling failure */
MWT_BOOL PARTAP_L_BcDcuBrdTpNotVd_GI = FALSE ; /* initial value: Select to block converter at faulty board temperature sensor */
MWT_BOOL PARTAP_L_BcHtCoTpNotVd_GI = FALSE ; /* initial value: Select to block converter at faulty heat sink temperature sensor */
MWT_BOOL PARTAP_L_BcNteArTpNotVd_GI = FALSE ; /* initial value: Select to block converter at faulty conv. air temperature sensor */
MWT_REAL PARTAP_PH_HtCoOs_GI = 10.0 ; /* initial value: Temp. offset added to external heatsink at faulty internal heatsink measurement */
MWT_REAL PARTAP_PH_DcuBrdOs_GI = 0.0 ; /* initial value: DCU board temperature offset for internal air calculation */
MWT_BOOL PARTAP_L_MltTpSnSvEn_GI = FALSE ; /* initial value: Multiple temperature sensor supervision enabled */
MWT_TIME PARTAP_PT_TpSnDy_GI = 5000 ; /* initial value: Delay time for multiple sensor failure */
MWT_INT PARTAP_PX_IdPrSdPcl_GI = 1 ; /* initial value: Event identification (start) of DSP/FPGA PrSd process client */
MWT_INT PARTAP_PX_IdFsSdPcl_GI = 24 ; /* initial value: Event identification (start) of DSP/FPGA FsSd process client */
MWT_INT PARTAP_PX_IdSfSdPcl_GI = 30 ; /* initial value: Event identification (start) of DSP/FPGA SfSd process client */
MWT_INT PARTAP_PX_IdPrBcPcl_GI = 41 ; /* initial value: Event identification (start) of DSP/FPGA PrBc process client */
MWT_INT PARTAP_PX_IdClPcl_GI = 1 ; /* initial value: Event identification (start) of control process client */
MWT_INT PARTAP_PX_IdHwPcl_GI = 1 ; /* initial value: Event identification (start) of hardware process client */
MWT_INT PARTAP_PX_IdTpPcl_GI = 1 ; /* initial value: Event identification (start) of temperature process client */
MWT_REAL PARTAP_PI_BtCpThr_GI = 999.0 ; /* initial value: Battery charger current level to enable certain protections at blocked battery chopper */
MWT_TIME PARTAP_PT_BtCpCurBc_GI = 50 ; /* initial value: Time for battery chopper current to fall after blocking of battery chopper */
MWT_REAL PARTAP_PT_BtCpSfBc_GI = 0.2 ; /* initial value: Battery chopper soft blocking time */
MWT_TIME PARTAP_PT_BtCpAvTm_GI = 5000 ; /* initial value: Battery chopper activation cycle time */
MWT_REAL PARTDP_PX_KpIBtCpCl_GI = 0.001 ; /* initial value: Proportional part battery chopper current control */
MWT_REAL PARTDP_PX_KiIBtCpCl_GI = 0.0001 ; /* initial value: Integrational part battery chopper current control */
MWT_REAL PARTDP_PF_BtCpSg_GI = 2500.0 ; /* initial value: Battery chopper switching frequency */
MWT_REAL PARTDP_PI_IBtCp_Max_GI = 340.0 ; /* initial value: Battery chopper current, maximum value */
MWT_REAL PARTDP_PN_IEstBtCg_Flt_GI = 125.0 ; /* initial value: Estimated battery charger current, filter constant for LP-filter */
MWT_REAL PARTDP_PN_UBtCp_Flt_GI = 1500.0 ; /* initial value: Battery voltage, filter constant for LP-filter */
MWT_BOOL PARTAP_L_EnCtSm_GI = TRUE ; /* initial value: Enable simulated contactor feedback in converter simulation mode */
MWT_INT PARTGP_NX_DevCodFpga2_GI = 2 ; /* initial value: Device code for the FPGA2
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
MWT_INT PARTGP_NX_VerCodFd1Fpga2_GI = 1 ; /* initial value: Version code for field 1, Fundamental change (version 1-15) */
MWT_INT PARTGP_NX_VerCodFd2Fpga2_GI = 0 ; /* initial value: Version code for field 2, Major functional change (version 0-31) */
MWT_INT PARTGP_NX_VerCodFd3Fpga2_GI = 11 ; /* initial value: Version code for field 3, Error correction, backward compatible (version 0-127) */
MWT_INT PARTGP_NX_VerCodFd4Fpga2_GI = 0 ; /* initial value: Version code for field 4, Development version (version 0-127) */
MWT_INT PARTGP_NX_VerCodFd5Fpga2_GI = 0 ; /* initial value: Version code for field 5,Project specific version based on DCU2 product (version 0-15) */
MWT_INT PARTGP_NX_DevCodDsp_GI = 1 ; /* initial value: Device code for the DSP
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
MWT_INT PARTGP_NX_VerCodFd1Dsp_GI = 1 ; /* initial value: Version code for field 1, Fundamental change (version 1-15) */
MWT_INT PARTGP_NX_VerCodFd2Dsp_GI = 0 ; /* initial value: Version code for field 2, Major functional change (version 0-31) */
MWT_INT PARTGP_NX_VerCodFd3Dsp_GI = 11 ; /* initial value: Version code for field 3, Error correction, backward compatible (version 0-127) */
MWT_INT PARTGP_NX_VerCodFd4Dsp_GI = 107 ; /* initial value: Version code for field 4, Development version (version 0-127) */
MWT_INT PARTGP_NX_VerCodFd5Dsp_GI = 2 ; /* initial value: Version code for field 5,Project specific version based on DCU2 product (version 0-15) */
MWT_REAL PARTDP_PU_BtCpClFl_GI = 5.0 ; /* initial value: Voltage threshold for battery chopper control failure, block battery chopper */
MWT_REAL PARTDP_PT_BtCpClFlDy_GI = 2.0 ; /* initial value: Time delay for battery chopper control failure, block battery chopper */
MWT_BOOL PARTDP_L_3PhRndEn_GI = TRUE ; /* initial value: Enable randomization of 3-phase inverter switching frequency */
MWT_REAL PARTDP_PI_BtCgCalOsMax_Rw_GI = 20.0 ; /* initial value: Battery charger calibration offset maximum */

/* system 1 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_1I = 1 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_1I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_1I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_1I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_1I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_1I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_1I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_1I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_1I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_1I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_1I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_1I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_1I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_1I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_1I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_1I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_1I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_1I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_1I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_1I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_1I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_1I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_1I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_1I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_1I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_1I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_1I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_1I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_1I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_1I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_1I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_1I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_1I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_1I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_1I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_1I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_1I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_1I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_1I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_1I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_1I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_1I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_1I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_1I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_1I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_1I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_1I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_1I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_1I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_1I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_1I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_1I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_1I = 2150.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_1I = 2100.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_1I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_1I = 1000.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_1I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_1I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_1I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_1I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_1I = FALSE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_1I = FALSE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_1I = FALSE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_1I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_1I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_1I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_1I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTAP_PU_UF3PhSzRdy_1I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_1I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_1I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_1I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_1I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_1I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_1I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_1I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_1I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_1I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_1I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4_1I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_1I = 125.32 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_1I = 125.32 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_1I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_1I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_1I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_1I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_1I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_1I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_1I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_1I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_1I = FALSE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_1I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_1I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_1I = FALSE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_1I = FALSE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_1I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_1I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_1I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_1I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_1I = 65.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_1I = 63.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_1I = 55.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_1I = 133.5 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_1I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_1I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_1I = 44.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_1I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_1I = 2000.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_1I = 4000.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_1I = 30000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_1I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_1I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_1I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_1I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 2 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_2I = 2 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_2I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_2I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_2I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_2I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_2I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_2I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_2I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_2I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_2I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_2I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_2I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_2I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_2I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_2I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_2I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_2I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_2I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_2I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_2I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_2I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_2I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_2I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_2I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_2I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_2I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_2I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_2I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_2I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_2I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_2I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_2I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_2I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_2I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_2I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_2I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_2I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_2I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_2I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_2I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_2I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_2I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_2I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_2I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_2I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_2I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_2I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_2I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_2I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_2I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_2I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_2I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_2I = 2150.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_2I = 2100.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_2I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_2I = 1000.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_2I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_2I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_2I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_2I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_2I = TRUE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_2I = TRUE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_2I = TRUE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_2I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_2I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_2I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_2I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTAP_PU_UF3PhSzRdy_2I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_2I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_2I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_2I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_2I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_2I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_2I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_2I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_2I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_2I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_2I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4_2I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_2I = 125.32 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_2I = 125.32 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_2I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_2I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_2I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_2I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_2I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_2I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_2I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_2I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_2I = TRUE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_2I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_2I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_2I = TRUE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_2I = TRUE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_2I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_2I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_2I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_2I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_2I = 65.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_2I = 63.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_2I = 55.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_2I = 133.5 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_2I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_2I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_2I = 44.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_2I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_2I = 2000.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_2I = 4000.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_2I = 30000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_2I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_2I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_2I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_2I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 3 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_3I = 3 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_3I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_3I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_3I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_3I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_3I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_3I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_3I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_3I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_3I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_3I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_3I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_3I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_3I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_3I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_3I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_3I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_3I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_3I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_3I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_3I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_3I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_3I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_3I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_3I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_3I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_3I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_3I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_3I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_3I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_3I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_3I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_3I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_3I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_3I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_3I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_3I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_3I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_3I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_3I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_3I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_3I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_3I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_3I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_3I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_3I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_3I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_3I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_3I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_3I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_3I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_3I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_3I = 2170.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_3I = 2120.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_3I = 2070.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_3I = 950.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_3I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_3I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_3I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_3I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_3I = FALSE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_3I = FALSE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_3I = FALSE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_3I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_3I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_3I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_3I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTAP_PU_UF3PhSzRdy_3I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_3I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_3I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_3I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_3I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_3I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_3I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_3I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_3I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_3I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_3I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4_3I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_3I = 127.2 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_3I = 127.2 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_3I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_3I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_3I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_3I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_3I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_3I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_3I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_3I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_3I = FALSE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_3I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_3I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_3I = FALSE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_3I = FALSE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_3I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_3I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_3I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_3I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_3I = 50.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_3I = 48.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_3I = 45.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_3I = 137.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_3I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_3I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_3I = 32.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_3I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_3I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_3I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_3I = 2000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_3I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_3I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_3I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_3I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 4 specific parameters of PAR
*/

MWT_INT PARTGP_XX_ParSet_4I = 4 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_4I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_4I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_4I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_4I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_4I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_4I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_4I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_4I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_4I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_4I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_4I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_4I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_4I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_4I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_4I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_4I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_4I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_4I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_4I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_4I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_4I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_4I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_4I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_4I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_4I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_4I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_4I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_4I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_4I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_4I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_4I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_4I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_4I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_4I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_4I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_4I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_4I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_4I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_4I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_4I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_4I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_4I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_4I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_4I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_4I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_4I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_4I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_4I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_4I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_4I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_4I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_4I = 2170.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_4I = 2120.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_4I = 2070.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_4I = 950.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_4I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_4I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_4I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_4I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_4I = TRUE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_4I = TRUE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_4I = TRUE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_4I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_4I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_4I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_4I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTAP_PU_UF3PhSzRdy_4I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_4I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_4I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_4I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_4I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_4I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_4I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_4I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_4I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_4I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_4I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4_4I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_4I = 127.2 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_4I = 127.2 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_4I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_4I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_4I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_4I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_4I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_4I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_4I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_4I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_4I = TRUE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_4I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_4I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_4I = TRUE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_4I = TRUE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_4I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_4I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_4I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_4I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_4I = 50.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_4I = 48.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_4I = 45.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_4I = 137.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_4I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_4I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_4I = 32.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_4I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_4I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_4I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_4I = 2000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_4I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_4I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_4I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_4I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 5 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_5I = 5 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_5I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_5I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_5I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_5I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_5I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_5I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_5I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_5I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_5I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_5I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_5I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_5I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_5I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_5I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_5I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_5I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_5I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_5I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_5I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_5I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_5I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_5I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_5I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_5I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_5I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_5I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_5I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_5I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_5I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_5I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_5I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_5I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_5I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_5I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_5I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_5I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_5I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_5I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_5I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_5I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_5I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_5I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_5I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_5I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_5I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_5I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_5I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_5I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_5I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_5I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_5I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_5I = 2150.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_5I = 2100.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_5I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_5I = 1000.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_5I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_5I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_5I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_5I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_5I = FALSE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_5I = FALSE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_5I = FALSE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_5I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_5I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_5I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_5I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTAP_PU_UF3PhSzRdy_5I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_5I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_5I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_5I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_5I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_5I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_5I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_5I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_5I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_5I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_5I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4_5I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_5I = 128.4 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_5I = 128.4 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_5I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_5I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_5I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_5I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_5I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_5I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_5I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_5I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_5I = FALSE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_5I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_5I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_5I = FALSE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_5I = FALSE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_5I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_5I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_5I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_5I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_5I = 60.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_5I = 58.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_5I = 50.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_5I = 132.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_5I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_5I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_5I = 44.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_5I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_5I = 2000.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_5I = 4000.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_5I = 30000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_5I = 18.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_5I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_5I = 0.05 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_5I = 18000000 ; /* initial value: Battery current limit high, delay */

/* system 6 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_6I = 6 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_6I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_6I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_6I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_6I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_6I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_6I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_6I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_6I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_6I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_6I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_6I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_6I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_6I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_6I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_6I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_6I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_6I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_6I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_6I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_6I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_6I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_6I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_6I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_6I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_6I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_6I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_6I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_6I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_6I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_6I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_6I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_6I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_6I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_6I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_6I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_6I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_6I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_6I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_6I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_6I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_6I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_6I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_6I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_6I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_6I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_6I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_6I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_6I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_6I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_6I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_6I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_6I = 2150.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_6I = 2100.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_6I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_6I = 1000.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_6I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_6I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_6I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_6I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_6I = TRUE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_6I = TRUE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_6I = TRUE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_6I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_6I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_6I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_6I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTAP_PU_UF3PhSzRdy_6I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_6I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_6I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_6I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_6I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_6I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_6I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_6I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_6I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_6I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_6I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4_6I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_6I = 133.6 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_6I = 133.6 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_6I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_6I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_6I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_6I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_6I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_6I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_6I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_6I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_6I = TRUE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_6I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_6I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_6I = TRUE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_6I = TRUE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_6I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_6I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_6I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_6I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_6I = 60.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_6I = 58.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_6I = 50.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_6I = 132.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_6I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_6I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_6I = 40.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_6I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_6I = 2000.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_6I = 4000.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_6I = 30000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_6I = 18.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_6I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_6I = 0.05 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_6I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 7 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_7I = 7 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_7I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_7I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_7I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_7I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_7I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_7I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_7I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_7I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_7I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_7I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_7I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_7I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_7I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_7I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_7I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_7I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_7I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_7I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_7I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_7I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_7I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_7I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_7I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_7I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_7I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_7I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_7I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_7I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_7I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_7I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_7I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_7I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_7I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_7I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_7I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_7I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_7I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_7I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_7I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_7I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_7I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_7I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_7I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_7I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_7I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_7I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_7I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_7I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_7I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_7I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_7I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_7I = 2170.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_7I = 2120.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_7I = 2070.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_7I = 950.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_7I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_7I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_7I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_7I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_7I = FALSE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_7I = FALSE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_7I = FALSE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_7I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_7I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_7I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_7I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTAP_PU_UF3PhSzRdy_7I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_7I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_7I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_7I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_7I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_7I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_7I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_7I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_7I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_7I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_7I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4_7I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_7I = 129.6 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_7I = 129.6 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_7I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_7I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_7I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_7I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_7I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_7I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_7I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_7I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_7I = FALSE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_7I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_7I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_7I = FALSE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_7I = FALSE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_7I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_7I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_7I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_7I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_7I = 50.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_7I = 48.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_7I = 45.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_7I = 137.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_7I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_7I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_7I = 30.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_7I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_7I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_7I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_7I = 2000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_7I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_7I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_7I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_7I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 8 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_8I = 8 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_8I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_8I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_8I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_8I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_8I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_8I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_8I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_8I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_8I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_8I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_8I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_8I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_8I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_8I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_8I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_8I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_8I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_8I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_8I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_8I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_8I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_8I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_8I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_8I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_8I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_8I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_8I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_8I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_8I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_8I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_8I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_8I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_8I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_8I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_8I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_8I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_8I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_8I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_8I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_8I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_8I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_8I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_8I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_8I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_8I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_8I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_8I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_8I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_8I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_8I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_8I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_8I = 2170.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_8I = 2120.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_8I = 2070.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_8I = 950.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_8I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_8I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_8I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_8I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_8I = TRUE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_8I = TRUE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_8I = TRUE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_8I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_8I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_8I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_8I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTAP_PU_UF3PhSzRdy_8I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_8I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_8I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_8I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_8I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_8I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_8I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_8I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_8I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_8I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_8I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4_8I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_8I = 129.6 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_8I = 129.6 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_8I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_8I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_8I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_8I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_8I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_8I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_8I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_8I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_8I = TRUE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_8I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_8I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_8I = TRUE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_8I = TRUE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_8I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_8I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_8I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_8I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_8I = 50.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_8I = 48.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_8I = 45.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_8I = 137.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_8I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_8I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_8I = 30.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_8I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_8I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_8I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_8I = 2000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_8I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_8I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_8I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_8I = 18000000 ; /* initial value: Battery current limit high, delay */

/* system 9 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_9I = 9 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_9I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_9I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_9I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_9I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_9I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_9I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_9I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_9I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_9I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_9I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_9I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_9I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_9I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_9I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_9I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_9I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_9I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_9I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_9I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_9I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_9I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_9I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_9I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_9I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_9I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_9I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_9I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_9I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_9I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_9I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_9I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_9I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_9I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_9I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_9I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_9I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_9I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_9I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_9I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_9I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_9I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_9I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_9I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_9I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_9I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_9I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_9I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_9I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_9I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_9I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_9I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_9I = 2150.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_9I = 2100.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_9I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_9I = 1000.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_9I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_9I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_9I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_9I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_9I = FALSE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_9I = FALSE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_9I = FALSE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_9I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_9I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_9I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_9I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTAP_PU_UF3PhSzRdy_9I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_9I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_9I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_9I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_9I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_9I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_9I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_9I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_9I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_9I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_9I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3 */
MWT_REAL PARTAP_PU_U3PhRef4_9I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_9I = 125.32 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_9I = 125.32 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_9I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_9I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_9I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_9I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_9I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_9I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_9I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_9I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_9I = FALSE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_9I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_9I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_9I = FALSE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_9I = FALSE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_9I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_9I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_9I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_9I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_9I = 65.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_9I = 63.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_9I = 55.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_9I = 133.5 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_9I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_9I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_9I = 44.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_9I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_9I = 2000.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_9I = 4000.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_9I = 30000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_9I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_9I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_9I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_9I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 10 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_10I = 10 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_10I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_10I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_10I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_10I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_10I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_10I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_10I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_10I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_10I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_10I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_10I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_10I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_10I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_10I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_10I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_10I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_10I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_10I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_10I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_10I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_10I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_10I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_10I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_10I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_10I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_10I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_10I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_10I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_10I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_10I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_10I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_10I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_10I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_10I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_10I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_10I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_10I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_10I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_10I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_10I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_10I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_10I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_10I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_10I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_10I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_10I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_10I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_10I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_10I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_10I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_10I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_10I = 2150.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_10I = 2100.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_10I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_10I = 1000.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_10I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_10I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_10I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_10I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_10I = TRUE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_10I = TRUE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_10I = TRUE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_10I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_10I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_10I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_10I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready
*/
MWT_REAL PARTAP_PU_UF3PhSzRdy_10I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_10I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_10I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_10I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_10I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_10I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_10I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_10I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_10I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_10I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_10I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3
*/
MWT_REAL PARTAP_PU_U3PhRef4_10I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_10I = 125.06 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_10I = 125.06 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_10I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_10I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_10I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_10I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_10I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_10I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_10I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_10I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_10I = TRUE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_10I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_10I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_10I = TRUE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_10I = TRUE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_10I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_10I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_10I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_10I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_10I = 65.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_10I = 63.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_10I = 55.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_10I = 133.5 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_10I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_10I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_10I = 36.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_10I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_10I = 2000.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_10I = 4000.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_10I = 30000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_10I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_10I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_10I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_10I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 11 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_11I = 11 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_11I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_11I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_11I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_11I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_11I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_11I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_11I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_11I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_11I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_11I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_11I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_11I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_11I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_11I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_11I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_11I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_11I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_11I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_11I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_11I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_11I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_11I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_11I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_11I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_11I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_11I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_11I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_11I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_11I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_11I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_11I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_11I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_11I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_11I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_11I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_11I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_11I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_11I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_11I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_11I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_11I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_11I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_11I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_11I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_11I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_11I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_11I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_11I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_11I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_11I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_11I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_11I = 2170.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_11I = 2120.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_11I = 2070.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_11I = 950.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_11I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_11I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_11I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_11I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_11I = FALSE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_11I = FALSE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_11I = FALSE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_11I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_11I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_11I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_11I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready
*/
MWT_REAL PARTAP_PU_UF3PhSzRdy_11I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_11I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_11I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_11I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_11I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_11I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_11I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_11I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_11I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_11I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_11I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3
*/
MWT_REAL PARTAP_PU_U3PhRef4_11I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_11I = 127.2 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_11I = 127.2 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_11I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_11I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_11I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_11I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_11I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_11I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_11I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_11I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_11I = FALSE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_11I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_11I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_11I = FALSE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_11I = FALSE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_11I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_11I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_11I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_11I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_11I = 50.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_11I = 48.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_11I = 45.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_11I = 137.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_11I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_11I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_11I = 32.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_11I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_11I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_11I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_11I = 2000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_11I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_11I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_11I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_11I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 12 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_12I = 12 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_12I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_12I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_12I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_12I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_12I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_12I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_12I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_12I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_12I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_12I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_12I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_12I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_12I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_12I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_12I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_12I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_12I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_12I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_12I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_12I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_12I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_12I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_12I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_12I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_12I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_12I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_12I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_12I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_12I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_12I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_12I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_12I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_12I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_12I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_12I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_12I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_12I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_12I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_12I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_12I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_12I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_12I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_12I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_12I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_12I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_12I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_12I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_12I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_12I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_12I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_12I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_12I = 2170.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_12I = 2120.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_12I = 2070.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_12I = 950.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_12I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_12I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_12I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_12I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_12I = TRUE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_12I = TRUE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_12I = TRUE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_12I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_12I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_12I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_12I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready
*/
MWT_REAL PARTAP_PU_UF3PhSzRdy_12I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_12I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_12I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_12I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_12I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_12I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_12I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_12I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_12I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_12I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_12I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3
*/
MWT_REAL PARTAP_PU_U3PhRef4_12I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_12I = 121.6 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_12I = 127.2 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_12I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_12I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_12I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_12I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_12I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_12I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_12I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_12I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_12I = TRUE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_12I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_12I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_12I = TRUE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_12I = TRUE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_12I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_12I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_12I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_12I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_12I = 50.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_12I = 48.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_12I = 45.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_12I = 137.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_12I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_12I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_12I = 60.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_12I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_12I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_12I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_12I = 2000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_12I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_12I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_12I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_12I = 18000000 ; /* initial value: Battery current limit high, delay */

/* system 13 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_13I = 13 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_13I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_13I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_13I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_13I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_13I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_13I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_13I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_13I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_13I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_13I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_13I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_13I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_13I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_13I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_13I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_13I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_13I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_13I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_13I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_13I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_13I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_13I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_13I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_13I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_13I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_13I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_13I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_13I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_13I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_13I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_13I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_13I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_13I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_13I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_13I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_13I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_13I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_13I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_13I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_13I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_13I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_13I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_13I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_13I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_13I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_13I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_13I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_13I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_13I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_13I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_13I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_13I = 2170.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_13I = 2120.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_13I = 2070.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_13I = 950.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_13I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_13I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_13I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_13I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_13I = FALSE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_13I = FALSE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_13I = FALSE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_13I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_13I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_13I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_13I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready
*/
MWT_REAL PARTAP_PU_UF3PhSzRdy_13I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_13I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_13I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_13I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_13I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_13I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_13I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_13I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_13I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_13I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_13I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3
*/
MWT_REAL PARTAP_PU_U3PhRef4_13I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_13I = 127.2 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_13I = 127.2 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_13I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_13I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_13I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_13I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_13I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_13I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_13I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_13I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_13I = FALSE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_13I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_13I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_13I = FALSE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_13I = FALSE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_13I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_13I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_13I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_13I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_13I = 50.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_13I = 48.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_13I = 45.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_13I = 137.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_13I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_13I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_13I = 32.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_13I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_13I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_13I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_13I = 2000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_13I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_13I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_13I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_13I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 14 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_14I = 14 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_14I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_14I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_14I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_14I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_14I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_14I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_14I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_14I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_14I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_14I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_14I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_14I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_14I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_14I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_14I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_14I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_14I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_14I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_14I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_14I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_14I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_14I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_14I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_14I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_14I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_14I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_14I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_14I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_14I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_14I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_14I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_14I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_14I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_14I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_14I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_14I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_14I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_14I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_14I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_14I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_14I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_14I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_14I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_14I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_14I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_14I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_14I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_14I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_14I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_14I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_14I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_14I = 2170.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_14I = 2120.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_14I = 2070.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_14I = 950.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_14I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_14I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_14I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_14I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_14I = TRUE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_14I = TRUE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_14I = TRUE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_14I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_14I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_14I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_14I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready
*/
MWT_REAL PARTAP_PU_UF3PhSzRdy_14I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_14I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_14I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_14I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_14I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_14I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_14I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_14I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_14I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_14I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_14I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3
*/
MWT_REAL PARTAP_PU_U3PhRef4_14I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_14I = 121.6 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_14I = 127.2 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_14I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_14I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_14I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_14I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_14I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_14I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_14I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_14I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_14I = TRUE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_14I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_14I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_14I = TRUE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_14I = TRUE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_14I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_14I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_14I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_14I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_14I = 50.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_14I = 48.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_14I = 45.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_14I = 137.0 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_14I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_14I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_14I = 60.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_14I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_14I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_14I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_14I = 2000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_14I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_14I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_14I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_14I = 18000000 ; /* initial value: Battery current limit high, delay */

/* system 15 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_15I = 15 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_15I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_15I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_15I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_15I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_15I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_15I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_15I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_15I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_15I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_15I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_15I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_15I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_15I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_15I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_15I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_15I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_15I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_15I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_15I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_15I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_15I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_15I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_15I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_15I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_15I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_15I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_15I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_15I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_15I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_15I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_15I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_15I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_15I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_15I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_15I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_15I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_15I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_15I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_15I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_15I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_15I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_15I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_15I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_15I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_15I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_15I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_15I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_15I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_15I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_15I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_15I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_15I = 2150.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_15I = 2100.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_15I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_15I = 1000.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_15I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_15I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_15I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_15I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_15I = FALSE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_15I = FALSE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_15I = FALSE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_15I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_15I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_15I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_15I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready
*/
MWT_REAL PARTAP_PU_UF3PhSzRdy_15I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_15I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_15I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_15I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_15I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_15I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_15I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_15I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_15I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_15I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_15I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3
*/
MWT_REAL PARTAP_PU_U3PhRef4_15I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_15I = 125.84 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_15I = 125.84 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_15I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_15I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_15I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_15I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_15I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_15I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_15I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_15I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_15I = FALSE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_15I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_15I = FALSE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_15I = FALSE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_15I = FALSE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_15I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_15I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_15I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_15I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_15I = 65.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_15I = 63.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_15I = 55.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_15I = 133.5 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_15I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_15I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_15I = 36.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_15I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_15I = 2000.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_15I = 4000.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_15I = 30000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_15I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_15I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_15I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_15I = 18000000 ; /* initial value: Battery current limit high, delay */
/* system 16 specific parameters of PAR
*/
MWT_INT PARTGP_XX_ParSet_16I = 16 ; /* initial value: Actual system */
MWT_REAL PARTDP_PU_2qcDcLkRef_16I = 750.0 ; /* initial value: DC-link voltage reference for 2QC */
MWT_REAL PARTDP_PX_KpUDcLkCl_16I = 7.5 ; /* initial value: DC-link voltage control, proportional part */
MWT_REAL PARTDP_PX_KiUDcLkCl_16I = 0.02 ; /* initial value: DC-link voltage control, integrational part */
MWT_BOOL PARTDP_L_UDcLkFlt2HmEn_16I = FALSE ; /* initial value: Enabling filtering of second harmonic DC-link voltage */
MWT_REAL PARTDP_PX_UDcLkClFiB0_16I = 0.87955117 ; /* initial value: Filter constant B0 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB1_16I = -1.64754962 ; /* initial value: Filter constant B1 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiB2_16I = 0.85278511 ; /* initial value: Filter constant B2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_UDcLkClFiA1_16I = -1.44910652 ; /* initial value: Filter constant A1 for 2nd harmonic filter */
MWT_REAL PARTDP_PI_PhInRmsLim_16I = 560.0 ; /* initial value: DC-link voltage control, AC input phase current, RMS limit */
MWT_REAL PARTDP_PX_UDcLkClFiA2_16I = 0.64412954 ; /* initial value: Filter constant A2 for 2nd harmonic filter */
MWT_REAL PARTDP_PX_KpUDcLkClFf_16I = 0.0 ; /* initial value: DC-link voltage control feed forward gain */
MWT_REAL PARTDP_PL_NdIn_16I = 0.0006 ; /* initial value: Total AC input inductance */
MWT_REAL PARTDP_PX_KpCon1IPhInCl_16I = 1.7 ; /* initial value: AC input phase current control, proportional factor 1, continuous current */
MWT_REAL PARTDP_PX_KpCon2IPhInCl_16I = 67.0 ; /* initial value: AC input phase current control, proportional factor 2, continuous current */
MWT_REAL PARTDP_PX_KpDis1IPhInCl_16I = 133.0 ; /* initial value: AC input phase current control, proportional factor 1, discontinuous current */
MWT_REAL PARTDP_PX_KpDis2IPhInCl_16I = 8.3 ; /* initial value: AC input phase current control, proportional factor 2, discontinuous current */
MWT_REAL PARTDP_PX_KiIPhInCl_16I = 0.00005 ; /* initial value: AC input phase current control, integrational part */
MWT_REAL PARTDP_PU_IPhInClIntMaxMin_16I = 100.0 ; /* initial value: AC input phase current control, maximum/minimum output from integration */
MWT_REAL PARTDP_PI_PhInPekLim_16I = 800.0 ; /* initial value: DC-link voltage control, AC input phase current, peak value limit limit */
MWT_REAL PARTDP_PI_PhInClEn_16I = 8.0 ; /* initial value: AC input phase current control, enable level */
MWT_REAL PARTDP_PX_UPhInFfMul_16I = 0.6 ; /* initial value: AC input phase current control, multiplication factor for AC input phase voltage
feed-forward */
MWT_REAL PARTDP_PX_UPhInFf_16I = 1.0 ; /* initial value: AC input phase voltage feed-forward factor for measured AC input phase voltage */
MWT_REAL PARTDP_PX_UPhInFfDy_16I = -0.29 ; /* initial value: AC input phase voltage feed-forward factor for delayed AC input phase voltage */
MWT_UDINT PARTDP_PX_UPhInFfNoSmpDy_16I = 30 ; /* initial value: Number of samples delay for delayed AC input phase voltage */
MWT_REAL PARTDP_PF_UPhInNom_16I = 195.0 ; /* initial value: Nominal AC input phase voltage frequency */
MWT_REAL PARTDP_PU_LnSzRmsMin_16I = 120.0 ; /* initial value: AC input phase voltage RMS level for synchronization failure */
MWT_REAL PARTDP_PT_LnSzDy_16I = 0.2 ; /* initial value: Detection time for synchronization failure */
MWT_REAL PARTDP_PU_PnBoRwMin_16I = 40.0 ; /* initial value: AC input phase raw voltage level for pantograph bounce detection */
MWT_BOOL PARTDP_L_PnBoEn_16I = FALSE ; /* initial value: Enable pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDy_16I = 0.01 ; /* initial value: Detection time for pantograph bounce detection */
MWT_REAL PARTDP_PT_PnBoDeBcDy_16I = 0.005 ; /* initial value: Time delay before deblocking after pantograph bounce detection */
MWT_REAL PARTDP_PI_PhIn2qcHi4_16I = 800.0 ; /* initial value: AC input phase overcurrent protection, level high4, activation of Single Phase Blocking
(SPB) 2QC */
MWT_REAL PARTAP_PU_PhInRmsMax_16I = 1000.0 ; /* initial value: AC input phase voltage RMS max level */
MWT_TIME PARTAP_PT_UPhInRmsMaxDy_16I = 1000 ; /* initial value: AC Input phase voltage RMS max level, delay */
MWT_REAL PARTAP_PU_PhInRmsLow_16I = 225.0 ; /* initial value: AC input phase voltage RMS Low level */
MWT_TIME PARTAP_PT_UPhInRmsLowDy_16I = 5000 ; /* initial value: AC Input phase voltage RMS Low level, delay */
MWT_REAL PARTAP_PU_PhInRmsMin_16I = 0.0 ; /* initial value: AC input phase voltage RMS Min level */
MWT_TIME PARTAP_PT_UPhInRmsMinDy_16I = 32000 ; /* initial value: AC Input phase voltage RMS Min level, delay */
MWT_REAL PARTDP_PN_UPhInRms_Flt_16I = 5.0 ; /* initial value: AC input phase voltage, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_IPhInRms_Flt_16I = 3.0 ; /* initial value: AC input phase current, filter constant for RMS calculation */
MWT_REAL PARTDP_PN_P2qcIn_Flt_16I = 7.0 ; /* initial value: 2QC input power, filter constant for LP-filter */
MWT_REAL PARTDP_PU_DcLkNom_16I = 680.0 ; /* initial value: Nominal DC-link voltage in simulation mode */
MWT_REAL PARTDP_PU_PhInNomRms_16I = 450.0 ; /* initial value: Nominal AC input phase voltage, RMS value */
MWT_REAL PARTAP_PU_DcLkOpSa_16I = 1050.0 ; /* initial value: Minimum DC-link voltage to start ACM */
MWT_TIME PARTAP_PT_DcLkUOpSa_16I = 2000 ; /* initial value: Time with DC-link voltage above minimum level before start command */
MWT_REAL PARTAP_PU_DcLkOpSo_16I = 125.0 ; /* initial value: Minimum DC-link voltage to keep ACM in operation mode */
MWT_TIME PARTAP_PT_DcLkUOpSo_16I = 100 ; /* initial value: Time with voltage below PARTAP_PU_DcLkOpSo to stop operation */
MWT_BOOL PARTGP_B_DspDg2Tds_16I = TRUE ; /* initial value: Transfer DSP transientrecorder data to TDS. If false, the data will be transfered to a file
in the defined working directory (normally DCU2) */
MWT_REAL PARTAP_PU_DcLkDh_16I = -100.0 ; /* initial value: DC-link voltage level when discharge order is set */
MWT_REAL PARTAP_PX_KpF3PhSzCl_16I = 0.5 ; /* initial value: Proportional part, output frequency synchronization control */
MWT_REAL PARTAP_PT_F3PhSzCl_16I = 800.0 ; /* initial value: Time constant, output frequency synchronization control */
MWT_REAL PARTDP_PU_DcLkMax_16I = 2150.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkHi8_16I = 2100.0 ; /* initial value: DC-link overvoltage protection, level high8, switch on OVP */
MWT_REAL PARTDP_PU_DcLkHi7_16I = 2050.0 ; /* initial value: DC-link overvoltage protection, level high7, switch off OVP */
MWT_REAL PARTDP_PU_DcLkMin_16I = 1000.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTAP_PU_DcLkLow_16I = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PX_3PhRndMax_16I = 0.0345 ; /* initial value: Maximum randomization of 3-phase inverter switching frequency, ratio of 3-phase inverter
switching frequency */
MWT_REAL PARTDP_PF_3PhSg_16I = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTAP_L_EnAuLdCtCl_16I = TRUE ; /* initial value: Auxiliary load contactor in use */
MWT_BOOL PARTGP_L_EnAi08_16I = TRUE ; /* initial value: Input AI08 is used. */
MWT_BOOL PARTGP_L_EnAi07_16I = TRUE ; /* initial value: Input AI07 is used. */
MWT_BOOL PARTAP_L_EnBtCp_16I = TRUE ; /* initial value: Battery chopper control enabled */
MWT_BOOL PARTAP_L_ExtDiOut7En_16I = TRUE ; /* initial value: Enable external control of digital output 7 */
MWT_REAL PARTDP_PX_U3PhSnRt_16I = 16.4 ; /* initial value: 3-phase output load voltage measurement ratio (Ratio of 3-phase output load voltage
measurement device) */
MWT_REAL PARTAP_PX_FRefRmpUp_16I = 25.0 ; /* initial value: Output frequency reference derivative, ramp up */
MWT_REAL PARTAP_PF_UF3PhSzRdy_16I = 0.3 ; /* initial value: Max frequency error limit for indication synchronization to 3-phase auxiliary bus ready
*/
MWT_REAL PARTAP_PU_UF3PhSzRdy_16I = 20.0 ; /* initial value: Max amplitude difference limit for indication synchronization to 3-phase auxiliary bus
ready, phase-phase, RMS value */
MWT_REAL PARTDP_PD_ThetaFiOs_16I = 4.97 ; /* initial value: Angel adjustment for synchronization */
MWT_REAL PARTAP_PX_TrfRtPr3Ph_16I = 1.684 ; /* initial value: Voltage ratio of 3-phase transformer, primary to secondary winding */
MWT_REAL PARTDP_PZ_3PhFiNdRe_16I = 0.078 ; /* initial value: 3-phase filter impedance, inductor, resistance */
MWT_REAL PARTDP_PZ_3PhFiNdIm_16I = 0.207 ; /* initial value: 3-phase filter impedance, inductor, reactance at nominal output frequency */
MWT_REAL PARTDP_PZ_3PhFiCaIm_16I = -5.47 ; /* initial value: 3-phase filter impedance, capacitor, reactance at nominal output frequency (Shall be
=0), shall be set to a large value (-10000) to not affect the 3-phase output voltage control */
MWT_REAL PARTDP_PZ_3PhTfRe_16I = 0.0 ; /* initial value: Transformer impedance, resistance */
MWT_REAL PARTDP_PZ_3PhTfIm_16I = 0.0 ; /* initial value: Transformer impedance, reactance at nominal output frequency */
MWT_REAL PARTAP_PI_BtCgFltHgh_16I = 300.0 ; /* initial value: Filtered battery charger current high level */
MWT_REAL PARTAP_PU_3PhClRefMax_16I = 395.0 ; /* initial value: Maximum 3-phase output load voltage reference, phase-phase, RMS value */
MWT_REAL PARTAP_PU_U3PhRef3_16I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, breakpoint 3
*/
MWT_REAL PARTAP_PU_U3PhRef4_16I = 380.0 ; /* initial value: 3-phase output load voltage reference, phase-phase, RMS value, U/f-ratio, 100 Hz */
MWT_REAL PARTAP_PU_NomBt_16I = 125.84 ; /* initial value: Nominal battery voltage */
MWT_REAL PARTAP_PU_BtRfCg_16I = 125.84 ; /* initial value: Battery voltage, refresh charging level */
MWT_REAL PARTDP_PN_IBtCp_Flt_16I = 25.0 ; /* initial value: Battery chopper current, filter constant for LP-filter */
MWT_REAL PARTDP_PX_KiBtCpCl_16I = 0.0001 ; /* initial value: Integral part, battery chopper control */
MWT_REAL PARTAP_PT_IBtCl_16I = 50.0 ; /* initial value: Time constant, battery current control */
MWT_REAL PARTAP_PI_HtSvMaxLim_16I = 388.0 ; /* initial value: Full phase current limit, peak value */
MWT_REAL PARTAP_PX_HtSvOvLdLim_16I = 0.86 ; /* initial value: Relative IGBT overload level, fraction of actual phase current limit */
MWT_REAL PARTAP_PF_3PhNom_16I = 50.3 ; /* initial value: Output frequency, nominal value */
MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_16I = -200.0 ; /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */
MWT_REAL PARTAP_PI_BalSvMax_16I = 16.0 ; /* initial value: Phase current unbalance protection, level max, RMS value */
MWT_BOOL PARTDP_L_EnGduFbSvBtCp_16I = TRUE ; /* initial value: Enable GDU feedback supervision Battery chopper */
MWT_BOOL PARTDP_L_FSgSvIgbtBtCpEn_16I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching command */
MWT_BOOL PARTDP_L_FSgSvGduBtCpEn_16I = TRUE ; /* initial value: Enable switching frequency supervision Battery chopper, switching feedback */
MWT_BOOL PARTDP_L_EnIBtMmFl_16I = TRUE ; /* initial value: Enable protective action at battery current measurement failure */
MWT_BOOL PARTAP_L_EnBtRctHtSv_16I = TRUE ; /* initial value: Enable battery rectifier heat sink temperature supervision */
MWT_TIME PARTAP_PT_DcLkChDy_16I = 1000 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_UF3PhSzRdy_16I = 250 ; /* initial value: Time delay for indication synchronization to 3-phase auxiliary bus ready */
MWT_REAL PARTDP_PI_BtCpMax_16I = 400.0 ; /* initial value: Battery chopper overcurrent protection, level max */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_16I = 4.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTAP_PH_BtSvMax_16I = 65.0 ; /* initial value: Battery temperature supervision, level max, protective blocking */
MWT_REAL PARTAP_PH_BtSvHgh_16I = 63.0 ; /* initial value: Battery temperature supervision, level high, indication level */
MWT_REAL PARTAP_PH_BtSvRst_16I = 55.0 ; /* initial value: Battery temperature supervision, reset level */
MWT_REAL PARTDP_PU_BtMax_BtCpBc_16I = 133.5 ; /* initial value: Battery voltage to high. Request: BtCp Protective blocking */
MWT_BOOL PARTAP_L_EnAuLdCtSv_16I = TRUE ; /* initial value: Enable auxiliary load contactor supervision */
MWT_REAL PARTAP_PX_UBtIBtCgRef_16I = 1.0 ; /* initial value: Ratio of nominal battery voltage at max battery charger current level breakpoint */
MWT_REAL PARTAP_PI_BtClLim_16I = 36.0 ; /* initial value: Battery current limit */
MWT_BOOL PARTDP_L_EnUDcLkHgh4_16I = FALSE ; /* initial value: Enable DC-link overvoltage protection, level high4 */
MWT_REAL PARTAP_PU_DcLkHgh2_16I = 2000.0 ; /* initial value: DC-link overvoltage protection, level high2 */
MWT_REAL PARTAP_PU_DcLkHgh1_16I = 4000.0 ; /* initial value: DC-link overvoltage protection, level high1 */
MWT_TIME PARTAP_PT_UDcLkHgh1_16I = 30000 ; /* initial value: DC-link overvoltage protection, detection time, level high1 */
MWT_REAL PARTDP_PN_3PhAbs_Flt_16I = 20.0 ; /* initial value: Filter time constant for filtering of 3-phase voltage absolute value, used for 3-phase
voltage control */
MWT_REAL PARTDP_PX_KpUDcLkStb_16I = 150.0 ; /* initial value: DC-link voltage stabilization, proportional part */
MWT_REAL PARTDP_PX_KpUDcLkVoStbFb_16I = 0.00002 ; /* initial value: DC-link voltage stabilization, frequency contribution gain */
MWT_TIME PARTAP_PT_IBtLimHghDy_16I = 18000000 ; /* initial value: Battery current limit high, delay */

/* PCT parameters of PAR
*/
MWT_BOOL PARTAP_L_DcLkChCt_1PCTI = TRUE ; /* initial value: Charging contactor in use */
MWT_BOOL PARTAP_L_DcLkChCt_2PCTI = TRUE ; /* initial value: Charging contactor in use */
MWT_BOOL PARTAP_L_DcLkChCt_3PCTI = TRUE ; /* initial value: Charging contactor in use */
MWT_BOOL PARTAP_L_DcLkSrCt_1PCTI = TRUE ; /* initial value: Separation contactor in use */
MWT_BOOL PARTAP_L_DcLkSrCt_2PCTI = TRUE ; /* initial value: Separation contactor in use */
MWT_BOOL PARTAP_L_DcLkSrCt_3PCTI = TRUE ; /* initial value: Separation contactor in use */
MWT_TIME PARTAP_PT_DcLkChDy_1PCTI = 1500 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_DcLkChDy_2PCTI = 1500 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_DcLkChDy_3PCTI = 1500 ; /* initial value: Time delay before indication DC-link voltage rising OK if not 2QC */
MWT_TIME PARTAP_PT_DcLkChDyLv1_1PCTI = 300 ; /* initial value: Time delay before checking DC-link voltage, level 1 */
MWT_TIME PARTAP_PT_DcLkChDyLv1_2PCTI = 300 ; /* initial value: Time delay before checking DC-link voltage, level 1 */
MWT_TIME PARTAP_PT_DcLkChDyLv1_3PCTI = 300 ; /* initial value: Time delay before checking DC-link voltage, level 1 */
MWT_TIME PARTAP_PT_DcLkChDyLv2_1PCTI = 1500 ; /* initial value: Time delay before checking DC-link voltage, level 2, only 2QC */
MWT_TIME PARTAP_PT_DcLkChDyLv2_2PCTI = 1500 ; /* initial value: Time delay before checking DC-link voltage, level 2, only 2QC */
MWT_TIME PARTAP_PT_DcLkChDyLv2_3PCTI = 1500 ; /* initial value: Time delay before checking DC-link voltage, level 2, only 2QC */
MWT_REAL PARTAP_PU_DcLkChLv1_1PCTI = 300.0 ; /* initial value: DC-link voltage, level 1 */
MWT_REAL PARTAP_PU_DcLkChLv1_2PCTI = 300.0 ; /* initial value: DC-link voltage, level 1 */
MWT_REAL PARTAP_PU_DcLkChLv1_3PCTI = 30.0 ; /* initial value: DC-link voltage, level 1 */
MWT_REAL PARTAP_PX_DcLkChLv2_1PCTI = 0.8 ; /* initial value: DC-link voltage, level 2, fraction of AC input phase voltage, RMS value */
MWT_REAL PARTAP_PX_DcLkChLv2_2PCTI = 0.8 ; /* initial value: DC-link voltage, level 2, fraction of AC input phase voltage, RMS value */
MWT_REAL PARTAP_PX_DcLkChLv2_3PCTI = 0.8 ; /* initial value: DC-link voltage, level 2, fraction of AC input phase voltage, RMS value */
MWT_TIME PARTAP_PT_DcLkDhDy_1PCTI = 600 ; /* initial value: Delay time for DC-link discharge (Maximum time before protective action is
PT_DcLkDhDy+PT_FrOvp)
SR_BJ14_ConvSpec-REQ-393 */
MWT_TIME PARTAP_PT_DcLkDhDy_2PCTI = 600 ; /* initial value: Delay time for DC-link discharge (Maximum time before protective action is
PT_DcLkDhDy+PT_FrOvp)
SR_BJ14_ConvSpec-REQ-393 */
MWT_TIME PARTAP_PT_DcLkDhDy_3PCTI = 600 ; /* initial value: Delay time for DC-link discharge (Maximum time before protective action is
PT_DcLkDhDy+PT_FrOvp)
SR_BJ14_ConvSpec-REQ-393 */
MWT_TIME PARTAP_PT_FrOvp_1PCTI = 500 ; /* initial value: Time to fire OVP
SR_BJ14_ConvSpec-REQ-394 */
MWT_TIME PARTAP_PT_FrOvp_2PCTI = 500 ; /* initial value: Time to fire OVP
SR_BJ14_ConvSpec-REQ-394 */
MWT_TIME PARTAP_PT_FrOvp_3PCTI = 500 ; /* initial value: Time to fire OVP
SR_BJ14_ConvSpec-REQ-394 */
MWT_REAL PARTAP_PU_DcLkCvSlDh_1PCTI = 0.0 ; /* initial value: Voltage threshold to discharge DC-link in isolation state */
MWT_REAL PARTAP_PU_DcLkCvSlDh_2PCTI = 0.0 ; /* initial value: Voltage threshold to discharge DC-link in isolation state */
MWT_REAL PARTAP_PU_DcLkCvSlDh_3PCTI = 0.0 ; /* initial value: Voltage threshold to discharge DC-link in isolation state */
MWT_REAL PARTAP_PU_DhDcLk_Max_1PCTI = 100.0 ; /* initial value: DC-link voltage discharged level and maximum DC-link voltage to switch on GDU power
supply
SR_BJ14_ConvSpec-REQ-392 */
MWT_REAL PARTAP_PU_DhDcLk_Max_2PCTI = 100.0 ; /* initial value: DC-link voltage discharged level and maximum DC-link voltage to switch on GDU power
supply
SR_BJ14_ConvSpec-REQ-392 */
MWT_REAL PARTAP_PU_DhDcLk_Max_3PCTI = 100.0 ; /* initial value: DC-link voltage discharged level and maximum DC-link voltage to switch on GDU power
supply
SR_BJ14_ConvSpec-REQ-392 */
MWT_REAL PARTDP_PU_DcLkMax_1PCTI = 2100.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkMax_2PCTI = 2100.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTDP_PU_DcLkMax_3PCTI = 2100.0 ; /* initial value: DC-link overvoltage protection, level max */
MWT_REAL PARTAP_PU_DcLkLow_1PCTI = 70.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTAP_PU_DcLkLow_2PCTI = 1000.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTAP_PU_DcLkLow_3PCTI = 50.0 ; /* initial value: DC link voltage low level */
MWT_REAL PARTDP_PU_DcLkMin_1PCTI = 70.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTDP_PU_DcLkMin_2PCTI = 1000.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_REAL PARTDP_PU_DcLkMin_3PCTI = 70.0 ; /* initial value: DC-link undervoltage protection, level min */
MWT_BOOL PARTGP_L_DcLnIMmEn_1PCTI = TRUE ; /* initial value: DC line current measurement enabled (only used in MCU2G) */
MWT_BOOL PARTGP_L_DcLnIMmEn_2PCTI = TRUE ; /* initial value: DC line current measurement enabled (only used in MCU2G) */
MWT_BOOL PARTGP_L_DcLnIMmEn_3PCTI = TRUE ; /* initial value: DC line current measurement enabled (only used in MCU2G) */
MWT_REAL PARTGP_PU_BuInTsHghURef_1PCTI = 0.0 ; /* initial value: Burn in test voltage reference limit */
MWT_REAL PARTGP_PU_BuInTsHghURef_2PCTI = 103.0 ; /* initial value: Burn in test voltage reference limit */
MWT_REAL PARTGP_PU_BuInTsHghURef_3PCTI = 0.0 ; /* initial value: Burn in test voltage reference limit */
MWT_REAL PARTGP_PX_BuInTsCpIKp_1PCTI = 0.004 ; /* initial value: Burn in test chopper controller gain */
MWT_REAL PARTGP_PX_BuInTsCpIKp_2PCTI = 0.004 ; /* initial value: Burn in test chopper controller gain */
MWT_REAL PARTGP_PX_BuInTsCpIKp_3PCTI = 0.004 ; /* initial value: Burn in test chopper controller gain */
MWT_REAL PARTGP_PX_BuInTsCpIT_1PCTI = 25.0 ; /* initial value: Burn in test chopper controller integration time */
MWT_REAL PARTGP_PX_BuInTsCpIT_2PCTI = 25.0 ; /* initial value: Burn in test chopper controller integration time */
MWT_REAL PARTGP_PX_BuInTsCpIT_3PCTI = 25.0 ; /* initial value: Burn in test chopper controller integration time */
MWT_REAL PARTGP_PX_BuInTsHghBrCpDtyCy_1PCTI = 0.001 ; /* initial value: Burn in test brake chopper duty cycle limit */
MWT_REAL PARTGP_PX_BuInTsHghBrCpDtyCy_2PCTI = 0.001 ; /* initial value: Burn in test brake chopper duty cycle limit */
MWT_REAL PARTGP_PX_BuInTsHghBrCpDtyCy_3PCTI = 0.001 ; /* initial value: Burn in test brake chopper duty cycle limit */
MWT_REAL PARTGP_PX_BuInTsIKp_1PCTI = 0.0 ; /* initial value: Burn in test current controller gain */
MWT_REAL PARTGP_PX_BuInTsIKp_2PCTI = 0.05 ; /* initial value: Burn in test current controller gain */
MWT_REAL PARTGP_PX_BuInTsIKp_3PCTI = 0.0 ; /* initial value: Burn in test current controller gain */
MWT_REAL PARTGP_PX_BuInTsIT_1PCTI = 25.0 ; /* initial value: Burn in test current controller integration time */
MWT_REAL PARTGP_PX_BuInTsIT_2PCTI = 25.0 ; /* initial value: Burn in test current controller integration time */
MWT_REAL PARTGP_PX_BuInTsIT_3PCTI = 25.0 ; /* initial value: Burn in test current controller integration time */
MWT_REAL PARTGP_PI_BrCpRefIBrRs_1PCTI = 0.0 ; /* initial value: Brake resistor current reference for Brake chopper test */
MWT_REAL PARTGP_PI_BrCpRefIBrRs_2PCTI = 0.0 ; /* initial value: Brake resistor current reference for Brake chopper test */
MWT_REAL PARTGP_PI_BrCpRefIBrRs_3PCTI = 0.0 ; /* initial value: Brake resistor current reference for Brake chopper test */
MWT_REAL PARTGP_PI_BrCpRefIDc_1PCTI = 0.0 ; /* initial value: Line current reference for Brake chopper test */
MWT_REAL PARTGP_PI_BrCpRefIDc_2PCTI = 0.0 ; /* initial value: Line current reference for Brake chopper test */
MWT_REAL PARTGP_PI_BrCpRefIDc_3PCTI = 0.0 ; /* initial value: Line current reference for Brake chopper test */
MWT_REAL PARTGP_PI_BrCpTsOkIBrRs_1PCTI = 0.0 ; /* initial value: Brake resistor current limit for Brake chopper test OK */
MWT_REAL PARTGP_PI_BrCpTsOkIBrRs_2PCTI = 0.0 ; /* initial value: Brake resistor current limit for Brake chopper test OK */
MWT_REAL PARTGP_PI_BrCpTsOkIBrRs_3PCTI = 0.0 ; /* initial value: Brake resistor current limit for Brake chopper test OK */
MWT_REAL PARTGP_PI_BrCpTsOkIDc_1PCTI = 0.0 ; /* initial value: Line current limit for Brake chopper test OK */
MWT_REAL PARTGP_PI_BrCpTsOkIDc_2PCTI = 0.0 ; /* initial value: Line current limit for Brake chopper test OK */
MWT_REAL PARTGP_PI_BrCpTsOkIDc_3PCTI = 0.0 ; /* initial value: Line current limit for Brake chopper test OK */
MWT_REAL PARTGP_PR_Cp_1PCTI = 0.0 ; /* initial value: Brake chopper resistance value */
MWT_REAL PARTGP_PR_Cp_2PCTI = 0.0 ; /* initial value: Brake chopper resistance value */
MWT_REAL PARTGP_PR_Cp_3PCTI = 0.0 ; /* initial value: Brake chopper resistance value */
MWT_TIME PARTGP_PT_BrCpTs_1PCTI = 0 ; /* initial value: Brake chopper test time */
MWT_TIME PARTGP_PT_BrCpTs_2PCTI = 0 ; /* initial value: Brake chopper test time */
MWT_TIME PARTGP_PT_BrCpTs_3PCTI = 0 ; /* initial value: Brake chopper test time */
MWT_REAL PARTGP_PU_BrCpTsRef_1PCTI = 0.0 ; /* initial value: Voltage reference for chopper control ratio */
MWT_REAL PARTGP_PU_BrCpTsRef_2PCTI = 0.0 ; /* initial value: Voltage reference for chopper control ratio */
MWT_REAL PARTGP_PU_BrCpTsRef_3PCTI = 0.0 ; /* initial value: Voltage reference for chopper control ratio */
MWT_REAL PARTGP_PI_BuInTsCpRef02_1PCTI = 0.0 ; /* initial value: Burn in test Line current reference break point 2 */
MWT_REAL PARTGP_PI_BuInTsCpRef02_2PCTI = 0.0 ; /* initial value: Burn in test Line current reference break point 2 */
MWT_REAL PARTGP_PI_BuInTsCpRef02_3PCTI = 0.0 ; /* initial value: Burn in test Line current reference break point 2 */
MWT_REAL PARTGP_PI_BuInTsCpRef03_1PCTI = 0.0 ; /* initial value: Burn in test Line current reference break point 3 */
MWT_REAL PARTGP_PI_BuInTsCpRef03_2PCTI = 0.0 ; /* initial value: Burn in test Line current reference break point 3 */
MWT_REAL PARTGP_PI_BuInTsCpRef03_3PCTI = 0.0 ; /* initial value: Burn in test Line current reference break point 3 */
MWT_REAL PARTGP_PI_BuInTsRef01_1PCTI = 0.0 ; /* initial value: Burn in test current reference break point 1 */
MWT_REAL PARTGP_PI_BuInTsRef01_2PCTI = 0.0 ; /* initial value: Burn in test current reference break point 1 */
MWT_REAL PARTGP_PI_BuInTsRef01_3PCTI = 0.0 ; /* initial value: Burn in test current reference break point 1 */
MWT_REAL PARTGP_PI_BuInTsRef02_1PCTI = 0.0 ; /* initial value: Burn in test current reference break point 2 */
MWT_REAL PARTGP_PI_BuInTsRef02_2PCTI = 200.0 ; /* initial value: Burn in test current reference break point 2 */
MWT_REAL PARTGP_PI_BuInTsRef02_3PCTI = 0.0 ; /* initial value: Burn in test current reference break point 2 */
MWT_REAL PARTGP_PI_BuInTsRef03_1PCTI = 0.0 ; /* initial value: Burn in test current reference break point 3 */
MWT_REAL PARTGP_PI_BuInTsRef03_2PCTI = 200.0 ; /* initial value: Burn in test current reference break point 3 */
MWT_REAL PARTGP_PI_BuInTsRef03_3PCTI = 0.0 ; /* initial value: Burn in test current reference break point 3 */
MWT_REAL PARTGP_PI_BuInTsRef04_1PCTI = 0.0 ; /* initial value: Burn in test current reference break point 4 */
MWT_REAL PARTGP_PI_BuInTsRef04_2PCTI = 200.0 ; /* initial value: Burn in test current reference break point 4 */
MWT_REAL PARTGP_PI_BuInTsRef04_3PCTI = 0.0 ; /* initial value: Burn in test current reference break point 4 */
MWT_REAL PARTGP_PI_BuInTsRef05_1PCTI = 0.0 ; /* initial value: Burn in test current reference break point 5 */
MWT_REAL PARTGP_PI_BuInTsRef05_2PCTI = 200.0 ; /* initial value: Burn in test current reference break point 5 */
MWT_REAL PARTGP_PI_BuInTsRef05_3PCTI = 0.0 ; /* initial value: Burn in test current reference break point 5 */
MWT_REAL PARTGP_PI_BuInTsRef06_1PCTI = 0.0 ; /* initial value: Burn in test current reference break point 6 */
MWT_REAL PARTGP_PI_BuInTsRef06_2PCTI = 0.0 ; /* initial value: Burn in test current reference break point 6 */
MWT_REAL PARTGP_PI_BuInTsRef06_3PCTI = 0.0 ; /* initial value: Burn in test current reference break point 6 */
MWT_REAL PARTGP_PI_BuInTsRef07_1PCTI = 0.0 ; /* initial value: Burn in test current reference break point 7 */
MWT_REAL PARTGP_PI_BuInTsRef07_2PCTI = 0.0 ; /* initial value: Burn in test current reference break point 7 */
MWT_REAL PARTGP_PI_BuInTsRef07_3PCTI = 0.0 ; /* initial value: Burn in test current reference break point 7 */
MWT_REAL PARTGP_PI_BuInTsRef08_1PCTI = 0.0 ; /* initial value: Burn in test current reference break point 8 */
MWT_REAL PARTGP_PI_BuInTsRef08_2PCTI = 0.0 ; /* initial value: Burn in test current reference break point 8 */
MWT_REAL PARTGP_PI_BuInTsRef08_3PCTI = 0.0 ; /* initial value: Burn in test current reference break point 8 */
MWT_REAL PARTGP_PT_BuInTsCpRef01_1PCTI = 0.0 ; /* initial value: Burn in test Line current reference, time break point 1 */
MWT_REAL PARTGP_PT_BuInTsCpRef01_2PCTI = 5.0 ; /* initial value: Burn in test Line current reference, time break point 1 */
MWT_REAL PARTGP_PT_BuInTsCpRef01_3PCTI = 0.0 ; /* initial value: Burn in test Line current reference, time break point 1 */
MWT_REAL PARTGP_PT_BuInTsCpRef02_1PCTI = 0.0 ; /* initial value: Burn in test Line current reference, time break point 2 */
MWT_REAL PARTGP_PT_BuInTsCpRef02_2PCTI = 52.0 ; /* initial value: Burn in test Line current reference, time break point 2 */
MWT_REAL PARTGP_PT_BuInTsCpRef02_3PCTI = 0.0 ; /* initial value: Burn in test Line current reference, time break point 2 */
MWT_REAL PARTGP_PT_BuInTsCpRef03_1PCTI = 0.0 ; /* initial value: Burn in test Line current reference, time break point 3 */
MWT_REAL PARTGP_PT_BuInTsCpRef03_2PCTI = 70.0 ; /* initial value: Burn in test Line current reference, time break point 3 */
MWT_REAL PARTGP_PT_BuInTsCpRef03_3PCTI = 0.0 ; /* initial value: Burn in test Line current reference, time break point 3 */
MWT_REAL PARTGP_PT_BuInTsCpRef04_1PCTI = 8000.0 ; /* initial value: Burn in test Line current reference, time break point 4 */
MWT_REAL PARTGP_PT_BuInTsCpRef04_2PCTI = 80.0 ; /* initial value: Burn in test Line current reference, time break point 4 */
MWT_REAL PARTGP_PT_BuInTsCpRef04_3PCTI = 8000.0 ; /* initial value: Burn in test Line current reference, time break point 4 */
MWT_REAL PARTGP_PT_BuInTsDtyCyTm_1PCTI = 0.0 ; /* initial value: Burn in test duty cycle time */
MWT_REAL PARTGP_PT_BuInTsDtyCyTm_2PCTI = 70.0 ; /* initial value: Burn in test duty cycle time */
MWT_REAL PARTGP_PT_BuInTsDtyCyTm_3PCTI = 0.0 ; /* initial value: Burn in test duty cycle time */
MWT_REAL PARTGP_PT_BuInTsRef01_1PCTI = 0.0 ; /* initial value: Burn in test time break point 1 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef01_2PCTI = 0.0 ; /* initial value: Burn in test time break point 1 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef01_3PCTI = 0.0 ; /* initial value: Burn in test time break point 1 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef02_1PCTI = 0.0 ; /* initial value: Burn in test time break point 2 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef02_2PCTI = 5.0 ; /* initial value: Burn in test time break point 2 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef02_3PCTI = 0.0 ; /* initial value: Burn in test time break point 2 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef03_1PCTI = 0.0 ; /* initial value: Burn in test time break point 3 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef03_2PCTI = 35.0 ; /* initial value: Burn in test time break point 3 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef03_3PCTI = 0.0 ; /* initial value: Burn in test time break point 3 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef04_1PCTI = 0.0 ; /* initial value: Burn in test time break point 4 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef04_2PCTI = 36.0 ; /* initial value: Burn in test time break point 4 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef04_3PCTI = 0.0 ; /* initial value: Burn in test time break point 4 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef05_1PCTI = 0.0 ; /* initial value: Burn in test time break point 5 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef05_2PCTI = 46.0 ; /* initial value: Burn in test time break point 5 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef05_3PCTI = 0.0 ; /* initial value: Burn in test time break point 5 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef06_1PCTI = 0.0 ; /* initial value: Burn in test time break point 6 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef06_2PCTI = 51.0 ; /* initial value: Burn in test time break point 6 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef06_3PCTI = 0.0 ; /* initial value: Burn in test time break point 6 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef07_1PCTI = 0.0 ; /* initial value: Burn in test time break point 7 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef07_2PCTI = 71.0 ; /* initial value: Burn in test time break point 7 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef07_3PCTI = 0.0 ; /* initial value: Burn in test time break point 7 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef08_1PCTI = 0.0 ; /* initial value: Burn in test time break point 8 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef08_2PCTI = 71.0 ; /* initial value: Burn in test time break point 8 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsRef08_3PCTI = 0.0 ; /* initial value: Burn in test time break point 8 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsTm_1PCTI = 0.0 ; /* initial value: Burn in test total time 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsTm_2PCTI = 7200.0 ; /* initial value: Burn in test total time 1.0=1 s */
MWT_REAL PARTGP_PT_BuInTsTm_3PCTI = 0.0 ; /* initial value: Burn in test total time 1.0=1 s */
MWT_BOOL PARTGP_L_EnChDcLkSiPoTs_1PCTI = FALSE ; /* initial value: Allow DC-link charging at single position test */
MWT_BOOL PARTGP_L_EnChDcLkSiPoTs_2PCTI = FALSE ; /* initial value: Allow DC-link charging at single position test */
MWT_BOOL PARTGP_L_EnChDcLkSiPoTs_3PCTI = FALSE ; /* initial value: Allow DC-link charging at single position test */
MWT_REAL PARTGP_PI_CmtTsRef_1PCTI = 0.0 ; /* initial value: Current reference for Commutation test */
MWT_REAL PARTGP_PI_CmtTsRef_2PCTI = 700.0 ; /* initial value: Current reference for Commutation test */
MWT_REAL PARTGP_PI_CmtTsRef_3PCTI = 0.0 ; /* initial value: Current reference for Commutation test */
MWT_REAL PARTGP_PI_CmtTsTrp_1PCTI = 100.0 ; /* initial value: Commutation test trip level */
MWT_REAL PARTGP_PI_CmtTsTrp_2PCTI = 600.0 ; /* initial value: Commutation test trip level */
MWT_REAL PARTGP_PI_CmtTsTrp_3PCTI = 100.0 ; /* initial value: Commutation test trip level */
MWT_REAL PARTGP_PI_DefTrp_1PCTI = 600.0 ; /* initial value: Default phase current trip level */
MWT_REAL PARTGP_PI_DefTrp_2PCTI = 600.0 ; /* initial value: Default phase current trip level */
MWT_REAL PARTGP_PI_DefTrp_3PCTI = 600.0 ; /* initial value: Default phase current trip level */
MWT_REAL PARTGP_PI_HghLodTsRef_1PCTI = 100.0 ; /* initial value: Current reference for High load test */
MWT_REAL PARTGP_PI_HghLodTsRef_2PCTI = 250.0 ; /* initial value: Current reference for High load test */
MWT_REAL PARTGP_PI_HghLodTsRef_3PCTI = 160.0 ; /* initial value: Current reference for High load test */
MWT_REAL PARTGP_PI_HghLodtsTrp_1PCTI = 160.0 ; /* initial value: High load test trip level */
MWT_REAL PARTGP_PI_HghLodtsTrp_2PCTI = 400.0 ; /* initial value: High load test trip level */
MWT_REAL PARTGP_PI_HghLodtsTrp_3PCTI = 300.0 ; /* initial value: High load test trip level */
MWT_REAL PARTGP_PI_LwLodTsTrp_1PCTI = 100.0 ; /* initial value: Low load test trip level */
MWT_REAL PARTGP_PI_LwLodTsTrp_2PCTI = 200.0 ; /* initial value: Low load test trip level */
MWT_REAL PARTGP_PI_LwLodTsTrp_3PCTI = 200.0 ; /* initial value: Low load test trip level */
MWT_REAL PARTGP_PI_ManLodtsTrp_1PCTI = 100.0 ; /* initial value: Manual load test trip level */
MWT_REAL PARTGP_PI_ManLodtsTrp_2PCTI = 200.0 ; /* initial value: Manual load test trip level */
MWT_REAL PARTGP_PI_ManLodtsTrp_3PCTI = 200.0 ; /* initial value: Manual load test trip level */
MWT_TIME PARTGP_PT_CmtTsDy_1PCTI = 2000 ; /* initial value: Test activation delay time commutation test */
MWT_TIME PARTGP_PT_CmtTsDy_2PCTI = 2000 ; /* initial value: Test activation delay time commutation test */
MWT_TIME PARTGP_PT_CmtTsDy_3PCTI = 2000 ; /* initial value: Test activation delay time commutation test */
MWT_TIME PARTGP_PT_CmtTsRefRmp_1PCTI = 100 ; /* initial value: Test activation time commutation test */
MWT_TIME PARTGP_PT_CmtTsRefRmp_2PCTI = 100 ; /* initial value: Test activation time commutation test */
MWT_TIME PARTGP_PT_CmtTsRefRmp_3PCTI = 100 ; /* initial value: Test activation time commutation test */
MWT_TIME PARTGP_PT_HghLodTsAvTm_1PCTI = 5000 ; /* initial value: Test activation time High load test */
MWT_TIME PARTGP_PT_HghLodTsAvTm_2PCTI = 5000 ; /* initial value: Test activation time High load test */
MWT_TIME PARTGP_PT_HghLodTsAvTm_3PCTI = 5000 ; /* initial value: Test activation time High load test */
MWT_TIME PARTGP_PT_HghLodTsDy_1PCTI = 200 ; /* initial value: Test activation delay time High load test */
MWT_TIME PARTGP_PT_HghLodTsDy_2PCTI = 500 ; /* initial value: Test activation delay time High load test */
MWT_TIME PARTGP_PT_HghLodTsDy_3PCTI = 200 ; /* initial value: Test activation delay time High load test */
MWT_TIME PARTGP_PT_LwLodTsAvTm_1PCTI = 4000 ; /* initial value: Test activation time Low load test */
MWT_TIME PARTGP_PT_LwLodTsAvTm_2PCTI = 4000 ; /* initial value: Test activation time Low load test */
MWT_TIME PARTGP_PT_LwLodTsAvTm_3PCTI = 4000 ; /* initial value: Test activation time Low load test */
MWT_TIME PARTGP_PT_LwLodTsDy_1PCTI = 192 ; /* initial value: Test activation delay time Low load test */
MWT_TIME PARTGP_PT_LwLodTsDy_2PCTI = 192 ; /* initial value: Test activation delay time Low load test */
MWT_TIME PARTGP_PT_LwLodTsDy_3PCTI = 192 ; /* initial value: Test activation delay time Low load test */
MWT_TIME PARTGP_PT_ManLodTsAvTm_1PCTI = 10000 ; /* initial value: Test activation time Manual load test */
MWT_TIME PARTGP_PT_ManLodTsAvTm_2PCTI = 10000 ; /* initial value: Test activation time Manual load test */
MWT_TIME PARTGP_PT_ManLodTsAvTm_3PCTI = 10000 ; /* initial value: Test activation time Manual load test */
MWT_TIME PARTGP_PT_ManLodTsDy_1PCTI = 2000 ; /* initial value: Test activation delay time Manual load test */
MWT_TIME PARTGP_PT_ManLodTsDy_2PCTI = 2000 ; /* initial value: Test activation delay time Manual load test */
MWT_TIME PARTGP_PT_ManLodTsDy_3PCTI = 2000 ; /* initial value: Test activation delay time Manual load test */
MWT_REAL PARTGP_PU_CmtTsHghRef_1PCTI = 375.0 ; /* initial value: High voltage level for Commutation test */
MWT_REAL PARTGP_PU_CmtTsHghRef_2PCTI = 67.0 ; /* initial value: High voltage level for Commutation test */
MWT_REAL PARTGP_PU_CmtTsHghRef_3PCTI = 0.0 ; /* initial value: High voltage level for Commutation test */
MWT_REAL PARTGP_PU_DcLkPctDdCmp01_1PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp01_2PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp01_3PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp02_1PCTI = 1720.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp02_2PCTI = 1720.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp02_3PCTI = 1720.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp03_1PCTI = 1820.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp03_2PCTI = 1820.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp03_3PCTI = 1820.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp04_1PCTI = 1920.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp04_2PCTI = 1920.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_DcLkPctDdCmp04_3PCTI = 1920.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_HghLodTsHghRef_1PCTI = 15.0 ; /* initial value: High voltage level for High load test */
MWT_REAL PARTGP_PU_HghLodTsHghRef_2PCTI = 46.0 ; /* initial value: High voltage level for High load test */
MWT_REAL PARTGP_PU_HghLodTsHghRef_3PCTI = 10.0 ; /* initial value: High voltage level for High load test */
MWT_REAL PARTGP_PU_LwLodTsRef_1PCTI = 3.25 ; /* initial value: Voltage reference for Low load test */
MWT_REAL PARTGP_PU_LwLodTsRef_2PCTI = 23.0 ; /* initial value: Voltage reference for Low load test */
MWT_REAL PARTGP_PU_LwLodTsRef_3PCTI = 2.7 ; /* initial value: Voltage reference for Low load test */
MWT_REAL PARTGP_PU_ManLodTsRef_1PCTI = 0.0 ; /* initial value: Voltage reference for Manual load test */
MWT_REAL PARTGP_PU_ManLodTsRef_2PCTI = 8.4 ; /* initial value: Voltage reference for Manual load test */
MWT_REAL PARTGP_PU_ManLodTsRef_3PCTI = 2.7 ; /* initial value: Voltage reference for Manual load test */
MWT_REAL PARTGP_PU_RefPctDdCmp01_1PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp01_2PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp01_3PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp02_1PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp02_2PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp02_3PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp03_1PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp03_2PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp03_3PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp04_1PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp04_2PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_REAL PARTGP_PU_RefPctDdCmp04_3PCTI = 0.0 ; /* initial value: Used to calculate voltage compensation due to dead time */
MWT_TIME PARTGP_PT_IgbtAvTsTm_1PCTI = 512 ; /* initial value: IGBT Activation test time */
MWT_TIME PARTGP_PT_IgbtAvTsTm_2PCTI = 512 ; /* initial value: IGBT Activation test time */
MWT_TIME PARTGP_PT_IgbtAvTsTm_3PCTI = 512 ; /* initial value: IGBT Activation test time */
MWT_REAL PARTGP_PI_HghLodTsDfMax_1PCTI = 15.0 ; /* initial value: Max phase current difference in high load test */
MWT_REAL PARTGP_PI_HghLodTsDfMax_2PCTI = 15.0 ; /* initial value: Max phase current difference in high load test */
MWT_REAL PARTGP_PI_HghLodTsDfMax_3PCTI = 15.0 ; /* initial value: Max phase current difference in high load test */
MWT_REAL PARTGP_PI_HghLodTsIRefDfMax_1PCTI = 1000.0 ; /* initial value: Max difference between phase and reference current in high load test */
MWT_REAL PARTGP_PI_HghLodTsIRefDfMax_2PCTI = 1000.0 ; /* initial value: Max difference between phase and reference current in high load test */
MWT_REAL PARTGP_PI_HghLodTsIRefDfMax_3PCTI = 1000.0 ; /* initial value: Max difference between phase and reference current in high load test */
MWT_REAL PARTGP_PI_LwLodTs_Max_1PCTI = 50.0 ; /* initial value: Max phase current in low load test */
MWT_REAL PARTGP_PI_LwLodTs_Max_2PCTI = 170.0 ; /* initial value: Max phase current in low load test */
MWT_REAL PARTGP_PI_LwLodTs_Max_3PCTI = 150.0 ; /* initial value: Max phase current in low load test */
MWT_REAL PARTGP_PI_LwLodTs_Min_1PCTI = 10.0 ; /* initial value: Min phase current in low load test */
MWT_REAL PARTGP_PI_LwLodTs_Min_2PCTI = 40.0 ; /* initial value: Min phase current in low load test */
MWT_REAL PARTGP_PI_LwLodTs_Min_3PCTI = 10.0 ; /* initial value: Min phase current in low load test */
MWT_TIME PARTGP_PT_LwLodTs_1PCTI = 4000 ; /* initial value: Low load test time */
MWT_TIME PARTGP_PT_LwLodTs_2PCTI = 4000 ; /* initial value: Low load test time */
MWT_TIME PARTGP_PT_LwLodTs_3PCTI = 4000 ; /* initial value: Low load test time */
MWT_REAL PARTGP_PU_DCLkMaxLwUTs_1PCTI = 50.0 ; /* initial value: Maximum DC-link voltage for low voltage test (Single position test and digital
output test) */
MWT_REAL PARTGP_PU_DCLkMaxLwUTs_2PCTI = 50.0 ; /* initial value: Maximum DC-link voltage for low voltage test (Single position test and digital
output test) */
MWT_REAL PARTGP_PU_DCLkMaxLwUTs_3PCTI = 50.0 ; /* initial value: Maximum DC-link voltage for low voltage test (Single position test and digital
output test) */
MWT_TIME PARTGP_PT_IndPhCpAv_Max_1PCTI = 0 ; /* initial value: Max time for chopper activation */
MWT_TIME PARTGP_PT_IndPhCpAv_Max_2PCTI = 0 ; /* initial value: Max time for chopper activation */
MWT_TIME PARTGP_PT_IndPhCpAv_Max_3PCTI = 0 ; /* initial value: Max time for chopper activation */
MWT_REAL PARTGP_PU_IndPhTsRef_1PCTI = 0.0 ; /* initial value: Voltage reference for chopper control */
MWT_REAL PARTGP_PU_IndPhTsRef_2PCTI = 0.0 ; /* initial value: Voltage reference for chopper control */
MWT_REAL PARTGP_PU_IndPhTsRef_3PCTI = 0.0 ; /* initial value: Voltage reference for chopper control */
MWT_REAL PARTGP_PU_PsvDhTmMmSa_1PCTI = 1000.0 ; /* initial value: Time measurement starts at this voltage */
MWT_REAL PARTGP_PU_PsvDhTmMmSa_2PCTI = 1600.0 ; /* initial value: Time measurement starts at this voltage */
MWT_REAL PARTGP_PU_PsvDhTmMmSa_3PCTI = 100.0 ; /* initial value: Time measurement starts at this voltage */
MWT_REAL PARTGP_PU_PsvDhTmMmSo_1PCTI = 50.0 ; /* initial value: Time measurement stops at this voltage */
MWT_REAL PARTGP_PU_PsvDhTmMmSo_2PCTI = 800.0 ; /* initial value: Time measurement stops at this voltage */
MWT_REAL PARTGP_PU_PsvDhTmMmSo_3PCTI = 50.0 ; /* initial value: Time measurement stops at this voltage */
MWT_INT PARTGP_PX_PsvDhTm_Max_1PCTI = 250 ; /* initial value: Maximum allowable discharge time */
MWT_INT PARTGP_PX_PsvDhTm_Max_2PCTI = 50 ; /* initial value: Maximum allowable discharge time */
MWT_INT PARTGP_PX_PsvDhTm_Max_3PCTI = 300 ; /* initial value: Maximum allowable discharge time */
MWT_INT PARTGP_PX_PsvDhTm_Min_1PCTI = 150 ; /* initial value: Minimum allowable discharge time */
MWT_INT PARTGP_PX_PsvDhTm_Min_2PCTI = 35 ; /* initial value: Minimum allowable discharge time */
MWT_INT PARTGP_PX_PsvDhTm_Min_3PCTI = 10 ; /* initial value: Minimum allowable discharge time */
MWT_BOOL PARTAP_L_EnOvpFcTs_1PCTI = FALSE ; /* initial value: Enable OVP functional test */
MWT_BOOL PARTAP_L_EnOvpFcTs_2PCTI = FALSE ; /* initial value: Enable OVP functional test */
MWT_BOOL PARTAP_L_EnOvpFcTs_3PCTI = FALSE ; /* initial value: Enable OVP functional test */
MWT_REAL PARTAP_PU_DcLkU_OvpFcTs_1PCTI = 1000.0 ; /* initial value: Minimum DC-link voltage to run OVP test */
MWT_REAL PARTAP_PU_DcLkU_OvpFcTs_2PCTI = 1000.0 ; /* initial value: Minimum DC-link voltage to run OVP test */
MWT_REAL PARTAP_PU_DcLkU_OvpFcTs_3PCTI = 1000.0 ; /* initial value: Minimum DC-link voltage to run OVP test */
MWT_REAL PARTDP_PU_OvpFcTsRdy_1PCTI = 30.0 ; /* initial value: OVP test during DC-link charging, minimum DC-link voltage drop to pass test */
MWT_REAL PARTDP_PU_OvpFcTsRdy_2PCTI = 30.0 ; /* initial value: OVP test during DC-link charging, minimum DC-link voltage drop to pass test */
MWT_REAL PARTDP_PU_OvpFcTsRdy_3PCTI = 30.0 ; /* initial value: OVP test during DC-link charging, minimum DC-link voltage drop to pass test */
MWT_REAL PARTGP_PX_CmtTsPctCl_1PCTI = 5.0 ; /* initial value: Current control time constant for Commutation test */
MWT_REAL PARTGP_PX_CmtTsPctCl_2PCTI = 5.0 ; /* initial value: Current control time constant for Commutation test */
MWT_REAL PARTGP_PX_CmtTsPctCl_3PCTI = 5.0 ; /* initial value: Current control time constant for Commutation test */
MWT_REAL PARTGP_PX_CmtTsPctClKp_1PCTI = 0.05 ; /* initial value: Current control Proportional gain for Commutation test */
MWT_REAL PARTGP_PX_CmtTsPctClKp_2PCTI = 0.05 ; /* initial value: Current control Proportional gain for Commutation test */
MWT_REAL PARTGP_PX_CmtTsPctClKp_3PCTI = 0.05 ; /* initial value: Current control Proportional gain for Commutation test */
MWT_REAL PARTGP_PX_CmtTsRefRmp_1PCTI = 0.0 ; /* initial value: Derivative for Iref ramp for Commutation test */
MWT_REAL PARTGP_PX_CmtTsRefRmp_2PCTI = 7000.0 ; /* initial value: Derivative for Iref ramp for Commutation test */
MWT_REAL PARTGP_PX_CmtTsRefRmp_3PCTI = 0.0 ; /* initial value: Derivative for Iref ramp for Commutation test */
MWT_REAL PARTGP_PX_HghLodTsPctCl_1PCTI = 25.0 ; /* initial value: Current control time constant for High load test */
MWT_REAL PARTGP_PX_HghLodTsPctCl_2PCTI = 50.0 ; /* initial value: Current control time constant for High load test */
MWT_REAL PARTGP_PX_HghLodTsPctCl_3PCTI = 25.0 ; /* initial value: Current control time constant for High load test */
MWT_REAL PARTGP_PX_HghLodTsPctClKp_1PCTI = 0.07 ; /* initial value: Current control Proportional gain for High load test */
MWT_REAL PARTGP_PX_HghLodTsPctClKp_2PCTI = 0.07 ; /* initial value: Current control Proportional gain for High load test */
MWT_REAL PARTGP_PX_HghLodTsPctClKp_3PCTI = 0.03 ; /* initial value: Current control Proportional gain for High load test */
MWT_REAL PARTGP_PX_HghLodTsRefRmp_1PCTI = 1000.0 ; /* initial value: Derivative for Iref ramp for High load test */
MWT_REAL PARTGP_PX_HghLodTsRefRmp_2PCTI = 900.0 ; /* initial value: Derivative for Iref ramp for High load test */
MWT_REAL PARTGP_PX_HghLodTsRefRmp_3PCTI = 1000.0 ; /* initial value: Derivative for Iref ramp for High load test */
MWT_REAL PARTGP_PX_LwLodTsRefRmp_1PCTI = 10.0 ; /* initial value: Derivative for Uref ramp for Low load test */
MWT_REAL PARTGP_PX_LwLodTsRefRmp_2PCTI = 100.0 ; /* initial value: Derivative for Uref ramp for Low load test */
MWT_REAL PARTGP_PX_LwLodTsRefRmp_3PCTI = 10.0 ; /* initial value: Derivative for Uref ramp for Low load test */
MWT_REAL PARTGP_PX_ManLodTsRefRmp_1PCTI = 500.0 ; /* initial value: Derivative for Uref ramp for Manual load test */
MWT_REAL PARTGP_PX_ManLodTsRefRmp_2PCTI = 500.0 ; /* initial value: Derivative for Uref ramp for Manual load test */
MWT_REAL PARTGP_PX_ManLodTsRefRmp_3PCTI = 500.0 ; /* initial value: Derivative for Uref ramp for Manual load test */
MWT_REAL PARTDP_PI_PhHi4_1PCTI = 650.0 ; /* initial value: Phase overcurrent protection, level high4, activation of Single Phase Blocking (SPB) POA */
MWT_REAL PARTDP_PI_PhHi4_2PCTI = 650.0 ; /* initial value: Phase overcurrent protection, level high4, activation of Single Phase Blocking (SPB) POA */
MWT_REAL PARTDP_PI_PhHi4_3PCTI = 650.0 ; /* initial value: Phase overcurrent protection, level high4, activation of Single Phase Blocking (SPB) POA */
MWT_REAL PARTDP_PF_2qcSg_1PCTI = 1600.0 ; /* initial value: 2QC switching frequency (Connected to IRQD cycle time) */
MWT_REAL PARTDP_PF_2qcSg_2PCTI = 1600.0 ; /* initial value: 2QC switching frequency (Connected to IRQD cycle time) */
MWT_REAL PARTDP_PF_2qcSg_3PCTI = 1600.0 ; /* initial value: 2QC switching frequency (Connected to IRQD cycle time) */
MWT_REAL PARTDP_PF_3PhSg_1PCTI = 500.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_REAL PARTDP_PF_3PhSg_2PCTI = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_REAL PARTDP_PF_3PhSg_3PCTI = 1350.0 ; /* initial value: 3-phase inverter switching frequency (Connected to IRQB cycle time) */
MWT_BOOL PARTDP_L_EnGduFbSvPoa_1PCTI = FALSE ; /* initial value: Enable GDU feedback supervision POA */
MWT_BOOL PARTDP_L_EnGduFbSvPoa_2PCTI = FALSE ; /* initial value: Enable GDU feedback supervision POA */
MWT_BOOL PARTDP_L_EnGduFbSvPoa_3PCTI = FALSE ; /* initial value: Enable GDU feedback supervision POA */
MWT_REAL PARTDP_PU_DcLkGduFbSvAv_1PCTI = 1000.0 ; /* initial value: Minimum DC-link voltage level to activate GDU feedback supervision if
UCE-feedback is used. */
MWT_REAL PARTDP_PU_DcLkGduFbSvAv_2PCTI = 1000.0 ; /* initial value: Minimum DC-link voltage level to activate GDU feedback supervision if
UCE-feedback is used. */
MWT_REAL PARTDP_PU_DcLkGduFbSvAv_3PCTI = 0.0 ; /* initial value: Minimum DC-link voltage level to activate GDU feedback supervision if UCE-feedback
is used. */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_1PCTI = 2.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_2PCTI = 30.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_REAL PARTDP_PN_IPhFixMcu_Flt_3PCTI = 30.0 ; /* initial value: Phase current, real and imaginary part, fixed projection, used for extracting DC
component from the phase currents, filter constant for LP-filter */
MWT_BOOL PARTAP_L_BcOpSrCt_1PCTI = FALSE ; /* initial value: Enable blocking with opening of contactors */
MWT_BOOL PARTAP_L_BcOpSrCt_2PCTI = FALSE ; /* initial value: Enable blocking with opening of contactors */
MWT_BOOL PARTAP_L_BcOpSrCt_3PCTI = FALSE ; /* initial value: Enable blocking with opening of contactors */
MWT_REAL PARTGP_PF_BuInTsRef_1PCTI = 0.0 ; /* initial value: Frequency reference at burn in test. */
MWT_REAL PARTGP_PF_BuInTsRef_2PCTI = 75.0 ; /* initial value: Frequency reference at burn in test. */
MWT_REAL PARTGP_PF_BuInTsRef_3PCTI = 0.0 ; /* initial value: Frequency reference at burn in test. */

#endif /* PAR_I_H */


