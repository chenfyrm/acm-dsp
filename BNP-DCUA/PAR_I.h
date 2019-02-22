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
#include "mwt_types.h"
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1122
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1123
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1124
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1125
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1126
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1127
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1128
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1129
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1130
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1131
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1132
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1133
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1134
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1135
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1136
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1137
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1138
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
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1139
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
