/* ------------------------------------------------------------------------
Module : PAR
Abstract : Source code for resource PAR
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
//#ifndef TARGET_SIM_DLL
//#include "rts_api.h"
//#else
//#include "clib.h"
//#endif
#include "PAR_I.h"
#include "PAR.h"
void PAR(TYPE_PAR_IF* data)
{
static MWT_BOOL first = TRUE ;
static MWT_INT lastSystem = 0 ;
static MWT_BOOL lastPct = FALSE ;
static MWT_INT lastPctMode = 0 ;
if ((first) || ((!data->PCTHMZ_A_PctMo) && lastPct))
{
/*
copying the init values of the system independent
parameters to the outputs
*/
data->PARTAP_NX_ParVer = PARTAP_NX_ParVer_GI ;
data->PARTGP_B_EnTxt = PARTGP_B_EnTxt_GI ;
data->PARTGP_L_MmIPh3 = PARTGP_L_MmIPh3_GI ;
data->PARTGP_L_EnPctPrAct = PARTGP_L_EnPctPrAct_GI ;
data->PARTGP_L_LtrSvEn = PARTGP_L_LtrSvEn_GI ;
data->PARTGP_PT_DiInFiBase = PARTGP_PT_DiInFiBase_GI ;
data->PARTGP_PT_DiInFiMpp = PARTGP_PT_DiInFiMpp_GI ;
data->PARTGP_PT_DiInFi43 = PARTGP_PT_DiInFi43_GI ;
data->PARTGP_PT_TrSafFl = PARTGP_PT_TrSafFl_GI ;
data->PARTGP_PT_FiSpeSnSpFl = PARTGP_PT_FiSpeSnSpFl_GI ;
data->PARTGP_P_NoHwFl_Max = PARTGP_P_NoHwFl_Max_GI ;
data->PARTGP_PT_WiFl = PARTGP_PT_WiFl_GI ;
data->PARTGP_L_TrpLvTsEn = PARTGP_L_TrpLvTsEn_GI ;
data->PARTGP_L_EnAi05 = PARTGP_L_EnAi05_GI ;
data->PARTGP_PH_Ai05Mn = PARTGP_PH_Ai05Mn_GI ;
data->PARTGP_PH_Ai05Mx = PARTGP_PH_Ai05Mx_GI ;
data->PARTGP_L_EnAi06 = PARTGP_L_EnAi06_GI ;
data->PARTGP_PH_Ai06Mn = PARTGP_PH_Ai06Mn_GI ;
data->PARTGP_PH_Ai06Mx = PARTGP_PH_Ai06Mx_GI ;
data->PARTGP_PH_Ai07Mn = PARTGP_PH_Ai07Mn_GI ;
data->PARTGP_PH_Ai07Mx = PARTGP_PH_Ai07Mx_GI ;
data->PARTGP_PH_Ai08Mn = PARTGP_PH_Ai08Mn_GI ;
data->PARTGP_PH_Ai08Mx = PARTGP_PH_Ai08Mx_GI ;
data->PARTGP_L_EnAi21 = PARTGP_L_EnAi21_GI ;
data->PARTGP_PH_Ai21Mn = PARTGP_PH_Ai21Mn_GI ;
data->PARTGP_PH_Ai21Mx = PARTGP_PH_Ai21Mx_GI ;
data->PARTGP_L_EnAi22 = PARTGP_L_EnAi22_GI ;
data->PARTGP_PH_Ai22Mn = PARTGP_PH_Ai22Mn_GI ;
data->PARTGP_PH_Ai22Mx = PARTGP_PH_Ai22Mx_GI ;
data->PARTGP_L_EnAi49 = PARTGP_L_EnAi49_GI ;
data->PARTGP_PX_Ai49 = PARTGP_PX_Ai49_GI ;
data->PARTGP_PH_TCoolCm = PARTGP_PH_TCoolCm_GI ;
data->PARTGP_PT_NteSv = PARTGP_PT_NteSv_GI ;
data->PARTGP_PT_DspWdg = PARTGP_PT_DspWdg_GI ;
data->PARTGP_L_EnDcu2ConfHPP = PARTGP_L_EnDcu2ConfHPP_GI ;
data->PARTGP_L_NteVSvEn = PARTGP_L_NteVSvEn_GI ;
data->PARTGP_B_EnParChgDet = PARTGP_B_EnParChgDet_GI ;
data->PARTGP_L_EnADComp = PARTGP_L_EnADComp_GI ;
data->PARTGP_L_CnfHpp = PARTGP_L_CnfHpp_GI ;
data->PARTGP_L_CnfMpp = PARTGP_L_CnfMpp_GI ;
data->PARTGP_L_CnfLpp = PARTGP_L_CnfLpp_GI ;
data->PARTGP_L_CnfDcuA = PARTGP_L_CnfDcuA_GI ;
data->PARTGP_L_CnfDcuM = PARTGP_L_CnfDcuM_GI ;
data->PARTGP_L_CnfDcuL = PARTGP_L_CnfDcuL_GI ;
data->PARTGP_B_EnCanComHPP = PARTGP_B_EnCanComHPP_GI ;
data->PARTGP_B_CntMtd = PARTGP_B_CntMtd_GI ;
data->PARTGP_XX_TskTmThrT4 = PARTGP_XX_TskTmThrT4_GI ;
data->PARTGP_XX_TskTmThrT16 = PARTGP_XX_TskTmThrT16_GI ;
data->PARTGP_XX_TskTmThrT64 = PARTGP_XX_TskTmThrT64_GI ;
data->PARTGP_XX_TskTmThrT1024 = PARTGP_XX_TskTmThrT1024_GI ;
data->PARTGP_WI_DTDX751A = PARTGP_WI_DTDX751A_GI ;
data->PARTGP_WI_DTDX753B = PARTGP_WI_DTDX753B_GI ;
data->PARTGP_WI_DTDX751C = PARTGP_WI_DTDX751C_GI ;
data->PARTGP_WI_DTDX752A = PARTGP_WI_DTDX752A_GI ;
data->PARTGP_WI_DTDX752B = PARTGP_WI_DTDX752B_GI ;
data->PARTGP_B_EnOptoOutCal = PARTGP_B_EnOptoOutCal_GI ;
data->PARTGP_P_NoDspFl_Max = PARTGP_P_NoDspFl_Max_GI ;
data->PARTGP_PT_WiDspFl = PARTGP_PT_WiDspFl_GI ;
data->PARTGP_B_EnCnNtHwFl = PARTGP_B_EnCnNtHwFl_GI ;
data->PARTGP_P_NoLtrOpFl_Max = PARTGP_P_NoLtrOpFl_Max_GI ;
data->PARTGP_B_EnTxtSel = PARTGP_B_EnTxtSel_GI ;
data->PARTGP_P_NoOptEnFl_Max = PARTGP_P_NoOptEnFl_Max_GI ;
data->PARTGP_B_DTDX = PARTGP_B_DTDX_GI ;
data->PARTGP_B_DTEX = PARTGP_B_DTEX_GI ;
data->PARTGP_PX_DspRamTsLv = PARTGP_PX_DspRamTsLv_GI ;
data->PARTGP_B_TrmTxtAelogEn = PARTGP_B_TrmTxtAelogEn_GI ;
data->PARTDP_PX_IPhSnRt = PARTDP_PX_IPhSnRt_GI ;
data->PARTDP_L_IPh1MmNg = PARTDP_L_IPh1MmNg_GI ;
data->PARTDP_L_IPh2MmNg = PARTDP_L_IPh2MmNg_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1041
data->PARTDP_L_UDcLkSnU = PARTDP_L_UDcLkSnU_GI ;
data->PARTDP_PX_UDcLkSnRt = PARTDP_PX_UDcLkSnRt_GI ;
data->PARTDP_PX_UDcLk2SnRt = PARTDP_PX_UDcLk2SnRt_GI ;
data->PARTDP_L_U3PhSnU = PARTDP_L_U3PhSnU_GI ;
data->PARTDP_PX_IDcLnErfSnRt = PARTDP_PX_IDcLnErfSnRt_GI ;
data->PARTDP_PX_IBtCgSnRt = PARTDP_PX_IBtCgSnRt_GI ;
data->PARTDP_PX_IBtSnRt = PARTDP_PX_IBtSnRt_GI ;
data->PARTDP_PX_UPhInSnRt = PARTDP_PX_UPhInSnRt_GI ;
data->PARTDP_L_UPhInMmNg = PARTDP_L_UPhInMmNg_GI ;
data->PARTDP_PX_IPhInSnRt = PARTDP_PX_IPhInSnRt_GI ;
data->PARTDP_L_IPhInMmNg = PARTDP_L_IPhInMmNg_GI ;
data->PARTDP_PT_Ovs2qc = PARTDP_PT_Ovs2qc_GI ;
data->PARTDP_PX_NoOvs2qc = PARTDP_PX_NoOvs2qc_GI ;
data->PARTDP_PX_IDfInSnRt = PARTDP_PX_IDfInSnRt_GI ;
data->PARTDP_PX_IRctSnRt = PARTDP_PX_IRctSnRt_GI ;
data->PARTDP_L_IRct1MmNg = PARTDP_L_IRct1MmNg_GI ;
data->PARTDP_L_IRct2MmNg = PARTDP_L_IRct2MmNg_GI ;
data->PARTDP_L_IRct3MmNg = PARTDP_L_IRct3MmNg_GI ;
data->PARTDP_PX_AI24SnRt = PARTDP_PX_AI24SnRt_GI ;
data->PARTDP_PX_AI29SnRt = PARTDP_PX_AI29SnRt_GI ;
data->PARTAP_L_En2ndU3Ph = PARTAP_L_En2ndU3Ph_GI ;
data->PARTAP_PI_PhMmSvSrOp = PARTAP_PI_PhMmSvSrOp_GI ;
data->PARTAP_PT_IPhMmSvSrOp = PARTAP_PT_IPhMmSvSrOp_GI ;
data->PARTAP_PI_PhMmSvNg = PARTAP_PI_PhMmSvNg_GI ;
data->PARTAP_PT_IPhMmSvNg = PARTAP_PT_IPhMmSvNg_GI ;
data->PARTAP_L_EnU3PhMmSvMin = PARTAP_L_EnU3PhMmSvMin_GI ;
data->PARTAP_PU_U3PhMmSvMin = PARTAP_PU_U3PhMmSvMin_GI ;
data->PARTAP_PT_U3PhMmSvOpLo = PARTAP_PT_U3PhMmSvOpLo_GI ;
data->PARTAP_L_EnPrActU3PhMmFl = PARTAP_L_EnPrActU3PhMmFl_GI ;
data->PARTAP_L_EnSltRqU3PhMmFl = PARTAP_L_EnSltRqU3PhMmFl_GI ;
data->PARTAP_PT_U3PhMmSvMin = PARTAP_PT_U3PhMmSvMin_GI ;
data->PARTDP_PX_IPhMmSvMax = PARTDP_PX_IPhMmSvMax_GI ;
data->PARTDP_PX_UDcLkMmSvDer = PARTDP_PX_UDcLkMmSvDer_GI ;
data->PARTDP_PX_UDcLkMmSvPo = PARTDP_PX_UDcLkMmSvPo_GI ;
data->PARTDP_PU_DcLkMmSvNg = PARTDP_PU_DcLkMmSvNg_GI ;
data->PARTDP_PU_DcLkMmSvRip = PARTDP_PU_DcLkMmSvRip_GI ;
data->PARTDP_L_UDcLkMmSvDf = PARTDP_L_UDcLkMmSvDf_GI ;
data->PARTDP_PU_DcLkMmSvDf = PARTDP_PU_DcLkMmSvDf_GI ;
data->PARTDP_PT_UDcLkMmSvDfDy = PARTDP_PT_UDcLkMmSvDfDy_GI ;
data->PARTDP_PX_U3PhMmSvMax = PARTDP_PX_U3PhMmSvMax_GI ;
data->PARTDP_L_U3PhRmsPlySv = PARTDP_L_U3PhRmsPlySv_GI ;
data->PARTDP_PU_U3PhRmsPlySvLim = PARTDP_PU_U3PhRmsPlySvLim_GI ;
data->PARTDP_PT_U3PhRmsPlySvDy = PARTDP_PT_U3PhRmsPlySvDy_GI ;
data->PARTDP_PU_BtMmSvPo = PARTDP_PU_BtMmSvPo_GI ;
data->PARTDP_PU_BtMmSvNg = PARTDP_PU_BtMmSvNg_GI ;
data->PARTDP_PU_BtMmSvRip = PARTDP_PU_BtMmSvRip_GI ;
data->PARTDP_PX_IBtCgMmSvPo = PARTDP_PX_IBtCgMmSvPo_GI ;
data->PARTDP_PI_BtCgMmSvNg = PARTDP_PI_BtCgMmSvNg_GI ;
data->PARTDP_PI_BtCgMmSvRip = PARTDP_PI_BtCgMmSvRip_GI ;
data->PARTDP_PX_IBtMmSvMax = PARTDP_PX_IBtMmSvMax_GI ;
data->PARTDP_PI_BtMmSvRip = PARTDP_PI_BtMmSvRip_GI ;
data->PARTDP_PX_IBtCpMmSvPo = PARTDP_PX_IBtCpMmSvPo_GI ;
data->PARTDP_PI_BtCpMmSvNg = PARTDP_PI_BtCpMmSvNg_GI ;
data->PARTDP_PI_BtCpMmSvRip = PARTDP_PI_BtCpMmSvRip_GI ;
data->PARTDP_PX_UPhInMmSvMax = PARTDP_PX_UPhInMmSvMax_GI ;
data->PARTDP_PX_IPhInMmSvMax = PARTDP_PX_IPhInMmSvMax_GI ;
data->PARTDP_PI_PhInRmsMmSvDf = PARTDP_PI_PhInRmsMmSvDf_GI ;
data->PARTDP_PT_IPhInRmsMmSvDy = PARTDP_PT_IPhInRmsMmSvDy_GI ;
data->PARTDP_PX_IDfInMmSvMax = PARTDP_PX_IDfInMmSvMax_GI ;
data->PARTDP_PX_IRctMmSvMax = PARTDP_PX_IRctMmSvMax_GI ;
data->PARTDP_PI_SumRctMmSvMax = PARTDP_PI_SumRctMmSvMax_GI ;
data->PARTDP_PT_IRctSumMmSvDfDy = PARTDP_PT_IRctSumMmSvDfDy_GI ;
data->PARTDP_PX_DcLk1SvMax = PARTDP_PX_DcLk1SvMax_GI ;
data->PARTDP_PN_UDcLk_Flt = PARTDP_PN_UDcLk_Flt_GI ;
data->PARTDP_PN_U3PhRms_Flt = PARTDP_PN_U3PhRms_Flt_GI ;
data->PARTDP_PN_UBt_Flt = PARTDP_PN_UBt_Flt_GI ;
data->PARTDP_PN_IBtCg1_Flt = PARTDP_PN_IBtCg1_Flt_GI ;
data->PARTDP_PN_IBtCg2_Flt = PARTDP_PN_IBtCg2_Flt_GI ;
data->PARTDP_PN_IBt_Flt = PARTDP_PN_IBt_Flt_GI ;
data->PARTDP_PN_UPhIn_Flt = PARTDP_PN_UPhIn_Flt_GI ;
data->PARTDP_PN_IDfIn_Flt = PARTDP_PN_IDfIn_Flt_GI ;
data->PARTDP_PN_IPhActRct_Flt = PARTDP_PN_IPhActRct_Flt_GI ;
data->PARTDP_PN_IPhActRctMcu_Flt = PARTDP_PN_IPhActRctMcu_Flt_GI ;
data->PARTDP_PN_IPhAbs_Flt = PARTDP_PN_IPhAbs_Flt_GI ;
data->PARTDP_PN_PQ3PhMcu_Flt = PARTDP_PN_PQ3PhMcu_Flt_GI ;
data->PARTDP_PN_IPhDQ_Flt = PARTDP_PN_IPhDQ_Flt_GI ;
data->PARTDP_PN_IPhAB_Flt = PARTDP_PN_IPhAB_Flt_GI ;
data->PARTDP_PN_URef_Flt = PARTDP_PN_URef_Flt_GI ;
data->PARTDP_PN_IRctRms_Flt = PARTDP_PN_IRctRms_Flt_GI ;
data->PARTDP_PN_AI24_Flt = PARTDP_PN_AI24_Flt_GI ;
data->PARTDP_PN_AI29_Flt = PARTDP_PN_AI29_Flt_GI ;
data->PARTAP_L_EnU3PhOpLoCl = PARTAP_L_EnU3PhOpLoCl_GI ;
data->PARTAP_PX_FRefRmpUpIPhInHgh = PARTAP_PX_FRefRmpUpIPhInHgh_GI ;
data->PARTAP_PX_FRefRmpDo1 = PARTAP_PX_FRefRmpDo1_GI ;
data->PARTAP_PX_FRefRmpDo2 = PARTAP_PX_FRefRmpDo2_GI ;
data->PARTAP_PX_FRefRmpDo3 = PARTAP_PX_FRefRmpDo3_GI ;
data->PARTAP_PF_FRefRmpDo12 = PARTAP_PF_FRefRmpDo12_GI ;
data->PARTAP_PF_FRefRmpDo23 = PARTAP_PF_FRefRmpDo23_GI ;
data->PARTAP_PF_3PhIPhDcClEn = PARTAP_PF_3PhIPhDcClEn_GI ;
data->PARTAP_PF_UDcLkMin = PARTAP_PF_UDcLkMin_GI ;
data->PARTAP_PU_DcLkFRefLow = PARTAP_PU_DcLkFRefLow_GI ;
data->PARTAP_PU_DcLkFRefMin = PARTAP_PU_DcLkFRefMin_GI ;
data->PARTAP_PX_FRefRmpUDcLkUp = PARTAP_PX_FRefRmpUDcLkUp_GI ;
data->PARTAP_PX_FRefRmpUDcLkDo = PARTAP_PX_FRefRmpUDcLkDo_GI ;
data->PARTAP_PF_3PhMin = PARTAP_PF_3PhMin_GI ;
data->PARTAP_PU_PhInFRefRmp = PARTAP_PU_PhInFRefRmp_GI ;
data->PARTAP_PI_PhInFRefRmp = PARTAP_PI_PhInFRefRmp_GI ;
data->PARTAP_L_F3PhRedSwcEn = PARTAP_L_F3PhRedSwcEn_GI ;
data->PARTAP_PU_3PhClRefMin = PARTAP_PU_3PhClRefMin_GI ;
data->PARTAP_PU_3PhClMax = PARTAP_PU_3PhClMax_GI ;
data->PARTAP_PU_3PhClMin = PARTAP_PU_3PhClMin_GI ;
data->PARTAP_PX_KpU3PhCl = PARTAP_PX_KpU3PhCl_GI ;
data->PARTAP_PT_U3PhCl = PARTAP_PT_U3PhCl_GI ;
data->PARTAP_PF_U3PhRef2 = PARTAP_PF_U3PhRef2_GI ;
data->PARTAP_PF_U3PhRef3 = PARTAP_PF_U3PhRef3_GI ;
data->PARTAP_PU_U3PhRef1 = PARTAP_PU_U3PhRef1_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1043
data->PARTAP_PU_U3PhRef2 = PARTAP_PU_U3PhRef2_GI ;
data->PARTAP_PT_FRefUDcLk = PARTAP_PT_FRefUDcLk_GI ;
data->PARTAP_L_ExtF3PhRef = PARTAP_L_ExtF3PhRef_GI ;
data->PARTAP_L_ExtU3PhRef = PARTAP_L_ExtU3PhRef_GI ;
data->PARTAP_B_En3PhClFqAda = PARTAP_B_En3PhClFqAda_GI ;
data->PARTAP_PX_ExtU3PhRefRmp = PARTAP_PX_ExtU3PhRefRmp_GI ;
data->PARTAP_L_EnRmpU3PhRef = PARTAP_L_EnRmpU3PhRef_GI ;
data->PARTAP_PX_U3PhRefRmp1 = PARTAP_PX_U3PhRefRmp1_GI ;
data->PARTAP_PX_U3PhRefRmp2 = PARTAP_PX_U3PhRefRmp2_GI ;
data->PARTAP_PX_U3PhRefRmpSel = PARTAP_PX_U3PhRefRmpSel_GI ;
data->PARTDP_L_UDcLkStbEn = PARTDP_L_UDcLkStbEn_GI ;
data->PARTDP_PN_UDcLkStbSliSmt = PARTDP_PN_UDcLkStbSliSmt_GI ;
data->PARTDP_PN_UDcLkStbHevSmt = PARTDP_PN_UDcLkStbHevSmt_GI ;
data->PARTDP_PU_DcLkStbMaxMin = PARTDP_PU_DcLkStbMaxMin_GI ;
data->PARTDP_PZ_3PhFiCaRe = PARTDP_PZ_3PhFiCaRe_GI ;
data->PARTDP_PX_3PhMod = PARTDP_PX_3PhMod_GI ;
data->PARTDP_L_En3PhOvMod = PARTDP_L_En3PhOvMod_GI ;
data->PARTDP_PN_UDcLkVoStbSmt = PARTDP_PN_UDcLkVoStbSmt_GI ;
data->PARTDP_PR_IPhStb = PARTDP_PR_IPhStb_GI ;
data->PARTDP_PX_IPhStbRfc = PARTDP_PX_IPhStbRfc_GI ;
data->PARTDP_L_DsFiThetaCm = PARTDP_L_DsFiThetaCm_GI ;
data->PARTAP_L_En3PhCl = PARTAP_L_En3PhCl_GI ;
data->PARTAP_PI_UBtRef = PARTAP_PI_UBtRef_GI ;
data->PARTAP_PT_BtRfCg = PARTAP_PT_BtRfCg_GI ;
data->PARTAP_PX_UBtRefRmpUp = PARTAP_PX_UBtRefRmpUp_GI ;
data->PARTAP_PX_UBtRefRmpDo = PARTAP_PX_UBtRefRmpDo_GI ;
data->PARTAP_PU_UBtClMax = PARTAP_PU_UBtClMax_GI ;
data->PARTAP_PU_UBtClMin = PARTAP_PU_UBtClMin_GI ;
data->PARTAP_PX_KpUBtCl = PARTAP_PX_KpUBtCl_GI ;
data->PARTAP_PT_UBtCl = PARTAP_PT_UBtCl_GI ;
data->PARTAP_PX_TrfRtBt3Ph = PARTAP_PX_TrfRtBt3Ph_GI ;
data->PARTAP_PX_TrfRtPrBt = PARTAP_PX_TrfRtPrBt_GI ;
data->PARTAP_PH_RctHtRef1 = PARTAP_PH_RctHtRef1_GI ;
data->PARTAP_PH_RctHtRef2 = PARTAP_PH_RctHtRef2_GI ;
data->PARTAP_PX_RctHtHBtRef = PARTAP_PX_RctHtHBtRef_GI ;
data->PARTAP_PX_UBtCpRefRmp = PARTAP_PX_UBtCpRefRmp_GI ;
data->PARTAP_PF_IPhClMin = PARTAP_PF_IPhClMin_GI ;
data->PARTAP_PF_IPhClMinErr = PARTAP_PF_IPhClMinErr_GI ;
data->PARTAP_PX_IPhClIntMax = PARTAP_PX_IPhClIntMax_GI ;
data->PARTAP_PX_IPhClIntMin = PARTAP_PX_IPhClIntMin_GI ;
data->PARTAP_PT_IPhClInt = PARTAP_PT_IPhClInt_GI ;
data->PARTAP_PI_IPhClActMax = PARTAP_PI_IPhClActMax_GI ;
data->PARTAP_PI_IPhClActMin = PARTAP_PI_IPhClActMin_GI ;
data->PARTAP_PI_IPhClActPsTrs = PARTAP_PI_IPhClActPsTrs_GI ;
data->PARTAP_PI_IPhClActOs = PARTAP_PI_IPhClActOs_GI ;
data->PARTAP_PX_IPhClActDe = PARTAP_PX_IPhClActDe_GI ;
data->PARTAP_PI_IPhClRctMax = PARTAP_PI_IPhClRctMax_GI ;
data->PARTAP_PI_IPhClRctMin = PARTAP_PI_IPhClRctMin_GI ;
data->PARTAP_PI_IPhClRctPsTrs = PARTAP_PI_IPhClRctPsTrs_GI ;
data->PARTAP_PI_IPhClRctOs = PARTAP_PI_IPhClRctOs_GI ;
data->PARTAP_PX_IPhClRctDePos = PARTAP_PX_IPhClRctDePos_GI ;
data->PARTAP_PX_IPhClRctDeNg = PARTAP_PX_IPhClRctDeNg_GI ;
data->PARTAP_PI_IPhClPsTrsLim = PARTAP_PI_IPhClPsTrsLim_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1044
data->PARTDP_PX_IPhClTrsKpAct = PARTDP_PX_IPhClTrsKpAct_GI ;
data->PARTDP_PX_IPhClTrsKpRct = PARTDP_PX_IPhClTrsKpRct_GI ;
data->PARTDP_PX_IPhClTrsKpAbs = PARTDP_PX_IPhClTrsKpAbs_GI ;
data->PARTDP_PI_PhClTrsAbsLim = PARTDP_PI_PhClTrsAbsLim_GI ;
data->PARTDP_PU_PhClTrsMax = PARTDP_PU_PhClTrsMax_GI ;
data->PARTDP_PN_URefIPhClTrs_Flt = PARTDP_PN_URefIPhClTrs_Flt_GI ;
data->PARTDP_PX_IPhClRmsRmpUp = PARTDP_PX_IPhClRmsRmpUp_GI ;
data->PARTDP_PX_IPhClRmsRfc = PARTDP_PX_IPhClRmsRfc_GI ;
data->PARTDP_L_EnIPhClRms = PARTDP_L_EnIPhClRms_GI ;
data->PARTDP_PI_PhClRmsLim = PARTDP_PI_PhClRmsLim_GI ;
data->PARTDP_PN_IPhRms_Flt = PARTDP_PN_IPhRms_Flt_GI ;
data->PARTAP_PX_IBtCgRmp = PARTAP_PX_IBtCgRmp_GI ;
data->PARTDP_PX_IBtCgDeLim = PARTDP_PX_IBtCgDeLim_GI ;
data->PARTDP_PI_BtCgMinAvDe = PARTDP_PI_BtCgMinAvDe_GI ;
data->PARTAP_PI_RfCgLim = PARTAP_PI_RfCgLim_GI ;
data->PARTDP_PX_KpIBtCgCl = PARTDP_PX_KpIBtCgCl_GI ;
data->PARTDP_PX_KiIBtCgCl = PARTDP_PX_KiIBtCgCl_GI ;
data->PARTDP_PU_IBtCgClMax = PARTDP_PU_IBtCgClMax_GI ;
data->PARTAP_PX_KpIBtCl = PARTAP_PX_KpIBtCl_GI ;
data->PARTAP_PU_IBtClMax = PARTAP_PU_IBtClMax_GI ;
data->PARTDP_L_EnIPhDcCl = PARTDP_L_EnIPhDcCl_GI ;
data->PARTDP_PU_IPhDcClMaxMin = PARTDP_PU_IPhDcClMaxMin_GI ;
data->PARTDP_PX_KpIPhDcCl = PARTDP_PX_KpIPhDcCl_GI ;
data->PARTDP_PX_KiIPhDcCl = PARTDP_PX_KiIPhDcCl_GI ;
data->PARTAP_L_EnUF3PhCmp = PARTAP_L_EnUF3PhCmp_GI ;
data->PARTAP_PI_UF3PhCmpActHiLo = PARTAP_PI_UF3PhCmpActHiLo_GI ;
data->PARTAP_PF_UF3PhCmpActHiLo = PARTAP_PF_UF3PhCmpActHiLo_GI ;
data->PARTAP_PI_UF3PhCmpRctHiLo = PARTAP_PI_UF3PhCmpRctHiLo_GI ;
data->PARTAP_PF_UF3PhSzClMaxMin = PARTAP_PF_UF3PhSzClMaxMin_GI ;
data->PARTAP_PT_UF3PhSzRmp = PARTAP_PT_UF3PhSzRmp_GI ;
data->PARTAP_PU_UF3PhSzClAdd = PARTAP_PU_UF3PhSzClAdd_GI ;
data->PARTAP_PU_UF3PhSzClMaxMin = PARTAP_PU_UF3PhSzClMaxMin_GI ;
data->PARTAP_PT_UF3PhSzFl = PARTAP_PT_UF3PhSzFl_GI ;
data->PARTDP_PX_UPhInNtFltDy = PARTDP_PX_UPhInNtFltDy_GI ;
data->PARTDP_L_DsPlElm3PhMod = PARTDP_L_DsPlElm3PhMod_GI ;
data->PARTDP_L_EnTPrDdCmp = PARTDP_L_EnTPrDdCmp_GI ;
data->PARTDP_PX_DdCmpFa = PARTDP_PX_DdCmpFa_GI ;
data->PARTDP_PI_DdCmpFu = PARTDP_PI_DdCmpFu_GI ;
data->PARTDP_PI_DdCmpDs = PARTDP_PI_DdCmpDs_GI ;
data->PARTDP_PF_2qcSg = PARTDP_PF_2qcSg_GI ;
data->PARTDP_PF_2qcSgChg = PARTDP_PF_2qcSgChg_GI ;
data->PARTAP_L_ExtCtCl = PARTAP_L_ExtCtCl_GI ;
data->PARTAP_L_ExtDiOut1En = PARTAP_L_ExtDiOut1En_GI ;
data->PARTAP_L_ExtDiOut2En = PARTAP_L_ExtDiOut2En_GI ;
data->PARTAP_L_ExtDiOut3En = PARTAP_L_ExtDiOut3En_GI ;
data->PARTAP_L_ExtDiOut4En = PARTAP_L_ExtDiOut4En_GI ;
data->PARTAP_L_ExtDiOut5En = PARTAP_L_ExtDiOut5En_GI ;
data->PARTAP_L_ExtDiOut6En = PARTAP_L_ExtDiOut6En_GI ;
data->PARTAP_L_DcLkChCt = PARTAP_L_DcLkChCt_GI ;
data->PARTAP_L_DcLkSrCt = PARTAP_L_DcLkSrCt_GI ;
data->PARTAP_PU_DcLkUHgh = PARTAP_PU_DcLkUHgh_GI ;
data->PARTAP_PT_2qcOpChRdy = PARTAP_PT_2qcOpChRdy_GI ;
data->PARTAP_L_3PhCvDh = PARTAP_L_3PhCvDh_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1045
data->PARTAP_PU_3PhDcLkCvDh = PARTAP_PU_3PhDcLkCvDh_GI ;
data->PARTAP_PF_3PhDcLkCvDh = PARTAP_PF_3PhDcLkCvDh_GI ;
data->PARTAP_PU_3PhIdlCmp = PARTAP_PU_3PhIdlCmp_GI ;
data->PARTAP_PU_3PhActCmp = PARTAP_PU_3PhActCmp_GI ;
data->PARTAP_L_BcOpSrCt = PARTAP_L_BcOpSrCt_GI ;
data->PARTAP_PT_DySrCtOp = PARTAP_PT_DySrCtOp_GI ;
data->PARTAP_PT_DyAuLdCtOp = PARTAP_PT_DyAuLdCtOp_GI ;
data->PARTAP_L_EnTmOutPrSd = PARTAP_L_EnTmOutPrSd_GI ;
data->PARTAP_L_EnTmOutFsSd = PARTAP_L_EnTmOutFsSd_GI ;
data->PARTAP_L_EnTmOutSfSd = PARTAP_L_EnTmOutSfSd_GI ;
data->PARTAP_L_EnTmOutPrBc = PARTAP_L_EnTmOutPrBc_GI ;
data->PARTAP_PT_TmOutPrSd = PARTAP_PT_TmOutPrSd_GI ;
data->PARTAP_PT_TmOutFsSd = PARTAP_PT_TmOutFsSd_GI ;
data->PARTAP_PT_TmOutSfSd = PARTAP_PT_TmOutSfSd_GI ;
data->PARTAP_PT_TmOutPrBc = PARTAP_PT_TmOutPrBc_GI ;
data->PARTAP_L_EnMvbWdg2Sv = PARTAP_L_EnMvbWdg2Sv_GI ;
data->PARTAP_L_EnMvbWdg3Sv = PARTAP_L_EnMvbWdg3Sv_GI ;
data->PARTAP_L_EnMvbWdg4Sv = PARTAP_L_EnMvbWdg4Sv_GI ;
data->PARTAP_PX_NoFlMvbCy_Hgh = PARTAP_PX_NoFlMvbCy_Hgh_GI ;
data->PARTAP_PX_NoFlMvbCy_Max = PARTAP_PX_NoFlMvbCy_Max_GI ;
data->PARTDP_PT_PrDdPoa = PARTDP_PT_PrDdPoa_GI ;
data->PARTDP_PT_PoaOnMin = PARTDP_PT_PoaOnMin_GI ;
data->PARTDP_PT_OvpOfMin = PARTDP_PT_OvpOfMin_GI ;
data->PARTDP_PT_OvpOnMin = PARTDP_PT_OvpOnMin_GI ;
data->PARTDP_PT_2qcOfMin = PARTDP_PT_2qcOfMin_GI ;
data->PARTDP_PT_2qcOnMin = PARTDP_PT_2qcOnMin_GI ;
data->PARTDP_PT_BtCpOnMin = PARTDP_PT_BtCpOnMin_GI ;
data->PARTDP_PT_BtCpOfMin = PARTDP_PT_BtCpOfMin_GI ;
data->PARTDP_PT_UDcLkMaxDy = PARTDP_PT_UDcLkMaxDy_GI ;
data->PARTAP_L_EnOvp = PARTAP_L_EnOvp_GI ;
data->PARTDP_PU_DcLkHgh4 = PARTDP_PU_DcLkHgh4_GI ;
data->PARTDP_PT_UDcLkHgh4Dy = PARTDP_PT_UDcLkHgh4Dy_GI ;
data->PARTAP_L_EnUDcLkHgh12 = PARTAP_L_EnUDcLkHgh12_GI ;
data->PARTAP_PT_UDcLkHgh2 = PARTAP_PT_UDcLkHgh2_GI ;
data->PARTAP_PU_DcLkHghRst = PARTAP_PU_DcLkHghRst_GI ;
data->PARTAP_PT_UDcLkLowDy = PARTAP_PT_UDcLkLowDy_GI ;
data->PARTDP_PT_SiPhBcPoaTmWnd1 = PARTDP_PT_SiPhBcPoaTmWnd1_GI ;
data->PARTDP_PX_SiPhBcPoaMaxWnd1 = PARTDP_PX_SiPhBcPoaMaxWnd1_GI ;
data->PARTDP_PT_SiPhBcPoaTmWnd2 = PARTDP_PT_SiPhBcPoaTmWnd2_GI ;
data->PARTDP_PX_SiPhBcPoaMaxWnd2 = PARTDP_PX_SiPhBcPoaMaxWnd2_GI ;
data->PARTDP_PI_PhMax = PARTDP_PI_PhMax_GI ;
data->PARTDP_PT_IPhMaxDy = PARTDP_PT_IPhMaxDy_GI ;
data->PARTDP_PI_PhHi4 = PARTDP_PI_PhHi4_GI ;
data->PARTDP_PT_IBtCpMaxDy = PARTDP_PT_IBtCpMaxDy_GI ;
data->PARTDP_PI_BtCpHi4 = PARTDP_PI_BtCpHi4_GI ;
data->PARTDP_PT_IBtCpHi4Dy = PARTDP_PT_IBtCpHi4Dy_GI ;
data->PARTDP_PT_SiPhBcBtCpTmWnd1 = PARTDP_PT_SiPhBcBtCpTmWnd1_GI ;
data->PARTDP_PX_SiPhBcBtCpMaxWnd1 = PARTDP_PX_SiPhBcBtCpMaxWnd1_GI ;
data->PARTAP_PX_IBtCpTmWndFl = PARTAP_PX_IBtCpTmWndFl_GI ;
data->PARTAP_PT_IBtCpTmWndFl = PARTAP_PT_IBtCpTmWndFl_GI ;
data->PARTDP_PT_IPhClRmsTmWnd1 = PARTDP_PT_IPhClRmsTmWnd1_GI ;
data->PARTDP_PX_IPhClRmsMaxWnd1 = PARTDP_PX_IPhClRmsMaxWnd1_GI ;
data->PARTDP_PI_PhClRmsSvMax = PARTDP_PI_PhClRmsSvMax_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1046
data->PARTDP_PT_IPhClRmsSvDy = PARTDP_PT_IPhClRmsSvDy_GI ;
data->PARTAP_PT_IAcLimTmSvDy = PARTAP_PT_IAcLimTmSvDy_GI ;
data->PARTAP_PT_IPhClTrsAvTof = PARTAP_PT_IPhClTrsAvTof_GI ;
data->PARTAP_L_EnIPhDcSv = PARTAP_L_EnIPhDcSv_GI ;
data->PARTAP_PI_PhDcSvMax = PARTAP_PI_PhDcSvMax_GI ;
data->PARTAP_PT_IPhDcSvMaxDy = PARTAP_PT_IPhDcSvMaxDy_GI ;
data->PARTAP_L_EnIBalSv = PARTAP_L_EnIBalSv_GI ;
data->PARTAP_PT_IBalSvDelDy = PARTAP_PT_IBalSvDelDy_GI ;
data->PARTAP_PT_IBalSvDyCvOp = PARTAP_PT_IBalSvDyCvOp_GI ;
data->PARTAP_L_BlkSiFl = PARTAP_L_BlkSiFl_GI ;
data->PARTAP_L_En3PhGduFbCk = PARTAP_L_En3PhGduFbCk_GI ;
data->PARTAP_L_En2qcGduFbCk = PARTAP_L_En2qcGduFbCk_GI ;
data->PARTAP_PT_GduFbCk_Mx = PARTAP_PT_GduFbCk_Mx_GI ;
data->PARTDP_PU_DcLkShtCrSv = PARTDP_PU_DcLkShtCrSv_GI ;
data->PARTDP_PT_GduBoFbOnPoaDy = PARTDP_PT_GduBoFbOnPoaDy_GI ;
data->PARTAP_L_UceGduFb = PARTAP_L_UceGduFb_GI ;
data->PARTDP_PU_DcLkGduFbSvAv = PARTDP_PU_DcLkGduFbSvAv_GI ;
data->PARTDP_L_EnGduFbSvPoa = PARTDP_L_EnGduFbSvPoa_GI ;
data->PARTDP_L_EnGduFbSvOvp = PARTDP_L_EnGduFbSvOvp_GI ;
data->PARTDP_L_EnGduFbSv2qc = PARTDP_L_EnGduFbSv2qc_GI ;
data->PARTDP_PX_NoGduFbFlPoa_Max = PARTDP_PX_NoGduFbFlPoa_Max_GI ;
data->PARTDP_PX_NoGduFbFlOvp_Max = PARTDP_PX_NoGduFbFlOvp_Max_GI ;
data->PARTDP_PX_NoGduFbFl2qc_Max = PARTDP_PX_NoGduFbFl2qc_Max_GI ;
data->PARTDP_L_EnGduShtCrSv = PARTDP_L_EnGduShtCrSv_GI ;
data->PARTDP_L_EnGduShtCrPraFpga = PARTDP_L_EnGduShtCrPraFpga_GI ;
data->PARTDP_PT_MskGduFbPoa = PARTDP_PT_MskGduFbPoa_GI ;
data->PARTDP_PT_MskGduFbOvp = PARTDP_PT_MskGduFbOvp_GI ;
data->PARTDP_PT_MskGduFb2qc = PARTDP_PT_MskGduFb2qc_GI ;
data->PARTDP_PT_GltFiGduFbPoa = PARTDP_PT_GltFiGduFbPoa_GI ;
data->PARTDP_PT_GltFiGduFbOvp = PARTDP_PT_GltFiGduFbOvp_GI ;
data->PARTDP_PT_GltFiGduFb2qc = PARTDP_PT_GltFiGduFb2qc_GI ;
data->PARTDP_PX_NoGduFbFlBtCp_Max = PARTDP_PX_NoGduFbFlBtCp_Max_GI ;
data->PARTDP_PT_GltFiGduFbBtCp = PARTDP_PT_GltFiGduFbBtCp_GI ;
data->PARTDP_PT_MskGduFbBtCp = PARTDP_PT_MskGduFbBtCp_GI ;
data->PARTAP_PX_GduFbSvBtCp = PARTAP_PX_GduFbSvBtCp_GI ;
data->PARTAP_PT_GduFbSvBtCp = PARTAP_PT_GduFbSvBtCp_GI ;
data->PARTAP_L_EnU3PhRmsMaxSv = PARTAP_L_EnU3PhRmsMaxSv_GI ;
data->PARTAP_PU_3PhRmsMax = PARTAP_PU_3PhRmsMax_GI ;
data->PARTAP_PT_U3PhRmsMax = PARTAP_PT_U3PhRmsMax_GI ;
data->PARTAP_PX_OvU3Ph = PARTAP_PX_OvU3Ph_GI ;
data->PARTAP_PT_OvU3Ph = PARTAP_PT_OvU3Ph_GI ;
data->PARTAP_L_UBtHghLowSvEn = PARTAP_L_UBtHghLowSvEn_GI ;
data->PARTAP_PU_BtMax = PARTAP_PU_BtMax_GI ;
data->PARTAP_PU_BtHgh = PARTAP_PU_BtHgh_GI ;
data->PARTAP_PT_UBtHghDy = PARTAP_PT_UBtHghDy_GI ;
data->PARTAP_PU_BtHghRst = PARTAP_PU_BtHghRst_GI ;
data->PARTAP_PU_BtMin = PARTAP_PU_BtMin_GI ;
data->PARTAP_PT_UBtMinDy = PARTAP_PT_UBtMinDy_GI ;
data->PARTAP_PU_BtMinRst = PARTAP_PU_BtMinRst_GI ;
data->PARTAP_L_UBtDepAuLdCtClEn = PARTAP_L_UBtDepAuLdCtClEn_GI ;
data->PARTAP_PU_BtOpAuLdCt = PARTAP_PU_BtOpAuLdCt_GI ;
data->PARTAP_PT_UBtOpAuLdCtDy = PARTAP_PT_UBtOpAuLdCtDy_GI ;
data->PARTAP_PU_BtCdAuLdCt = PARTAP_PU_BtCdAuLdCt_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1047
data->PARTAP_PT_BtMinChTm = PARTAP_PT_BtMinChTm_GI ;
data->PARTAP_L_OvIBtCgHghEn = PARTAP_L_OvIBtCgHghEn_GI ;
data->PARTDP_L_OvIBtCgEn = PARTDP_L_OvIBtCgEn_GI ;
data->PARTDP_PI_BtCgMax = PARTDP_PI_BtCgMax_GI ;
data->PARTDP_PT_IBtCgMaxDy = PARTDP_PT_IBtCgMaxDy_GI ;
data->PARTAP_PT_IBtCgFltHghDy = PARTAP_PT_IBtCgFltHghDy_GI ;
data->PARTAP_L_OvIBtCpHghEn = PARTAP_L_OvIBtCpHghEn_GI ;
data->PARTAP_PI_BtCpFltHgh = PARTAP_PI_BtCpFltHgh_GI ;
data->PARTAP_PT_IBtCpFltHghDy = PARTAP_PT_IBtCpFltHghDy_GI ;
data->PARTAP_L_IBtCgTmSvEn = PARTAP_L_IBtCgTmSvEn_GI ;
data->PARTAP_L_PraEnIBtCgTmSv = PARTAP_L_PraEnIBtCgTmSv_GI ;
data->PARTAP_L_SltEnIBtCgTmSv = PARTAP_L_SltEnIBtCgTmSv_GI ;
data->PARTAP_PX_IBtCgLimHghFr = PARTAP_PX_IBtCgLimHghFr_GI ;
data->PARTAP_PT_OffGhIBtCgLimHghDy = PARTAP_PT_OffGhIBtCgLimHghDy_GI ;
data->PARTAP_PT_IBtCgLimHghDy = PARTAP_PT_IBtCgLimHghDy_GI ;
data->PARTAP_PI_BtCgLim = PARTAP_PI_BtCgLim_GI ;
data->PARTAP_L_IBtTmSvEn = PARTAP_L_IBtTmSvEn_GI ;
data->PARTAP_L_PraEnIBtTmSv = PARTAP_L_PraEnIBtTmSv_GI ;
data->PARTAP_L_SltEnIBtTmSv = PARTAP_L_SltEnIBtTmSv_GI ;
data->PARTAP_PX_IBtLimHghFr = PARTAP_PX_IBtLimHghFr_GI ;
data->PARTAP_PT_OffGhIBtLimHghDy = PARTAP_PT_OffGhIBtLimHghDy_GI ;
data->PARTAP_L_EnChRsTpSm = PARTAP_L_EnChRsTpSm_GI ;
data->PARTAP_PH_AmTp_Max = PARTAP_PH_AmTp_Max_GI ;
data->PARTAP_PT_ChRsCoTmCns = PARTAP_PT_ChRsCoTmCns_GI ;
data->PARTAP_PH_ChRsTp_UpThr = PARTAP_PH_ChRsTp_UpThr_GI ;
data->PARTAP_PH_ChRsTp_LowThr = PARTAP_PH_ChRsTp_LowThr_GI ;
data->PARTAP_PR_ChRs = PARTAP_PR_ChRs_GI ;
data->PARTAP_PK_ChRs = PARTAP_PK_ChRs_GI ;
data->PARTAP_PC_DcLk = PARTAP_PC_DcLk_GI ;
data->PARTAP_L_EnChDcLkCnt = PARTAP_L_EnChDcLkCnt_GI ;
data->PARTAP_PN_ChDcLkCnt = PARTAP_PN_ChDcLkCnt_GI ;
data->PARTAP_PT_ChDcLkCnt = PARTAP_PT_ChDcLkCnt_GI ;
data->PARTAP_L_EnChCtSv = PARTAP_L_EnChCtSv_GI ;
data->PARTAP_L_EnSrCtSv = PARTAP_L_EnSrCtSv_GI ;
data->PARTAP_PT_CtOnDy = PARTAP_PT_CtOnDy_GI ;
data->PARTAP_PT_CtOfDy = PARTAP_PT_CtOfDy_GI ;
data->PARTAP_PT_CtFi = PARTAP_PT_CtFi_GI ;
data->PARTAP_L_SoCdAuLdCt = PARTAP_L_SoCdAuLdCt_GI ;
data->PARTAP_PT_AuLdCtOnDy = PARTAP_PT_AuLdCtOnDy_GI ;
data->PARTAP_PT_AuLdCtFi = PARTAP_PT_AuLdCtFi_GI ;
data->PARTAP_PT_AuLdCtOfDy = PARTAP_PT_AuLdCtOfDy_GI ;
data->PARTAP_PU_DcLkChLv1 = PARTAP_PU_DcLkChLv1_GI ;
data->PARTAP_PX_DcLkChLv2 = PARTAP_PX_DcLkChLv2_GI ;
data->PARTAP_PT_DcLkChDyLv1 = PARTAP_PT_DcLkChDyLv1_GI ;
data->PARTAP_PT_DcLkChDyLv2 = PARTAP_PT_DcLkChDyLv2_GI ;
data->PARTAP_PU_DhDcLk_Max = PARTAP_PU_DhDcLk_Max_GI ;
data->PARTAP_PT_DcLkDhDy = PARTAP_PT_DcLkDhDy_GI ;
data->PARTAP_PT_FrOvp = PARTAP_PT_FrOvp_GI ;
data->PARTAP_L_EnDhDcLkCvSl = PARTAP_L_EnDhDcLkCvSl_GI ;
data->PARTAP_PU_DcLkCvSlDh = PARTAP_PU_DcLkCvSlDh_GI ;
data->PARTAP_L_EnOvpFcTs = PARTAP_L_EnOvpFcTs_GI ;
data->PARTAP_PT_DyOvpFcTs = PARTAP_PT_DyOvpFcTs_GI ;
data->PARTAP_PU_DcLkU_OvpFcTs = PARTAP_PU_DcLkU_OvpFcTs_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1048
data->PARTDP_PX_OvpFcTsClRt = PARTDP_PX_OvpFcTsClRt_GI ;
data->PARTDP_PT_OvpFcTsFrMax = PARTDP_PT_OvpFcTsFrMax_GI ;
data->PARTDP_PU_OvpFcTsRdy = PARTDP_PU_OvpFcTsRdy_GI ;
data->PARTDP_L_OvpRsTpSvEn = PARTDP_L_OvpRsTpSvEn_GI ;
data->PARTDP_PR_Ovp = PARTDP_PR_Ovp_GI ;
data->PARTDP_PK_Ovp = PARTDP_PK_Ovp_GI ;
data->PARTDP_PT_OvpCoCns = PARTDP_PT_OvpCoCns_GI ;
data->PARTDP_PH_OvpMax = PARTDP_PH_OvpMax_GI ;
data->PARTDP_PH_OvpRst = PARTDP_PH_OvpRst_GI ;
data->PARTAP_PI_SrCtISv = PARTAP_PI_SrCtISv_GI ;
data->PARTAP_PI_ChCtISv = PARTAP_PI_ChCtISv_GI ;
data->PARTAP_PT_SrCtISvDy = PARTAP_PT_SrCtISvDy_GI ;
data->PARTAP_L_EnHHtSv = PARTAP_L_EnHHtSv_GI ;
data->PARTAP_L_EnIgbtOvLdSv = PARTAP_L_EnIgbtOvLdSv_GI ;
data->PARTAP_PH_HtSvMax = PARTAP_PH_HtSvMax_GI ;
data->PARTAP_PH_HtSvHgh2 = PARTAP_PH_HtSvHgh2_GI ;
data->PARTAP_PH_HtSvHgh1 = PARTAP_PH_HtSvHgh1_GI ;
data->PARTAP_PH_HtSvRst = PARTAP_PH_HtSvRst_GI ;
data->PARTAP_PT_HHtSvMax = PARTAP_PT_HHtSvMax_GI ;
data->PARTAP_PT_HHtSvHgh2 = PARTAP_PT_HHtSvHgh2_GI ;
data->PARTAP_PT_HHtSvHgh1 = PARTAP_PT_HHtSvHgh1_GI ;
data->PARTAP_PI_HtSvHgh2 = PARTAP_PI_HtSvHgh2_GI ;
data->PARTAP_PX_HtSvCntLim = PARTAP_PX_HtSvCntLim_GI ;
data->PARTAP_PT_HtSvOvLdLim = PARTAP_PT_HtSvOvLdLim_GI ;
data->PARTAP_PX_HHtSvMax = PARTAP_PX_HHtSvMax_GI ;
data->PARTAP_PT_HHtSvMaxTmWn = PARTAP_PT_HHtSvMaxTmWn_GI ;
data->PARTAP_PX_IgbtOvLd = PARTAP_PX_IgbtOvLd_GI ;
data->PARTAP_PT_IgbtOvLd = PARTAP_PT_IgbtOvLd_GI ;
data->PARTAP_PH_RctHtMax = PARTAP_PH_RctHtMax_GI ;
data->PARTAP_PH_RctHtSvHgh = PARTAP_PH_RctHtSvHgh_GI ;
data->PARTAP_PH_RctHtSvRst = PARTAP_PH_RctHtSvRst_GI ;
data->PARTAP_PT_RctHtSvMax = PARTAP_PT_RctHtSvMax_GI ;
data->PARTAP_PT_RctHtSvHgh = PARTAP_PT_RctHtSvHgh_GI ;
data->PARTAP_L_EnHTfSv = PARTAP_L_EnHTfSv_GI ;
data->PARTAP_PH_TfSvMax = PARTAP_PH_TfSvMax_GI ;
data->PARTAP_PH_TfSvHgh2 = PARTAP_PH_TfSvHgh2_GI ;
data->PARTAP_PH_TfSvHgh1 = PARTAP_PH_TfSvHgh1_GI ;
data->PARTAP_PH_TfSvRst = PARTAP_PH_TfSvRst_GI ;
data->PARTAP_PT_HTfSvMax = PARTAP_PT_HTfSvMax_GI ;
data->PARTAP_PT_HTfSvHgh2 = PARTAP_PT_HTfSvHgh2_GI ;
data->PARTAP_PT_HTfSvHgh1 = PARTAP_PT_HTfSvHgh1_GI ;
data->PARTAP_L_EnLngTmOvLdSv = PARTAP_L_EnLngTmOvLdSv_GI ;
data->PARTAP_PT_LngTmOvLdInt = PARTAP_PT_LngTmOvLdInt_GI ;
data->PARTAP_PI_LngTmOvLdMax = PARTAP_PI_LngTmOvLdMax_GI ;
data->PARTAP_PI_LngTmOvLdHgh = PARTAP_PI_LngTmOvLdHgh_GI ;
data->PARTAP_PI_LngTmOvLdRst = PARTAP_PI_LngTmOvLdRst_GI ;
data->PARTAP_PT_LngTmOvLdHgh = PARTAP_PT_LngTmOvLdHgh_GI ;
data->PARTAP_L_EnHBtSv = PARTAP_L_EnHBtSv_GI ;
data->PARTAP_PT_HBtSvMax = PARTAP_PT_HBtSvMax_GI ;
data->PARTAP_PT_HBtSvHgh = PARTAP_PT_HBtSvHgh_GI ;
data->PARTAP_L_EnHNteArSv = PARTAP_L_EnHNteArSv_GI ;
data->PARTAP_PH_NteArSvMax = PARTAP_PH_NteArSvMax_GI ;
data->PARTAP_PH_NteArSvHgh2 = PARTAP_PH_NteArSvHgh2_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1049
data->PARTAP_PH_NteArSvHgh1 = PARTAP_PH_NteArSvHgh1_GI ;
data->PARTAP_PH_NteArSvRst = PARTAP_PH_NteArSvRst_GI ;
data->PARTAP_PT_HNteArSvMax = PARTAP_PT_HNteArSvMax_GI ;
data->PARTAP_PT_HNteArSvHgh2 = PARTAP_PT_HNteArSvHgh2_GI ;
data->PARTAP_PT_HNteArSvHgh1 = PARTAP_PT_HNteArSvHgh1_GI ;
data->PARTAP_L_EnHNd1Sv = PARTAP_L_EnHNd1Sv_GI ;
data->PARTAP_L_EnHNd2Sv = PARTAP_L_EnHNd2Sv_GI ;
data->PARTAP_L_EnHNd3Sv = PARTAP_L_EnHNd3Sv_GI ;
data->PARTAP_PH_NdSvMax = PARTAP_PH_NdSvMax_GI ;
data->PARTAP_PH_NdSvHgh = PARTAP_PH_NdSvHgh_GI ;
data->PARTAP_PH_NdSvRst = PARTAP_PH_NdSvRst_GI ;
data->PARTAP_PT_HNdSvMax = PARTAP_PT_HNdSvMax_GI ;
data->PARTAP_PT_HNdSvHgh = PARTAP_PT_HNdSvHgh_GI ;
data->PARTAP_PT_HNdSnFl = PARTAP_PT_HNdSnFl_GI ;
data->PARTAP_L_DcCrBkSvEn = PARTAP_L_DcCrBkSvEn_GI ;
data->PARTAP_L_DcCrBkSvSltEn = PARTAP_L_DcCrBkSvSltEn_GI ;
data->PARTAP_PU_DcLkLowDcCrBkSv = PARTAP_PU_DcLkLowDcCrBkSv_GI ;
data->PARTAP_PT_DcCrBkSvDy = PARTAP_PT_DcCrBkSvDy_GI ;
data->PARTAP_PT_DcCrBkTrpRunTm = PARTAP_PT_DcCrBkTrpRunTm_GI ;
data->PARTAP_L_FnCrBkSvEn = PARTAP_L_FnCrBkSvEn_GI ;
data->PARTAP_L_FnCrBkSvPrBcEn = PARTAP_L_FnCrBkSvPrBcEn_GI ;
data->PARTAP_L_FnCrBkSvSltEn = PARTAP_L_FnCrBkSvSltEn_GI ;
data->PARTAP_PT_FnCrBkFbOpGhDy = PARTAP_PT_FnCrBkFbOpGhDy_GI ;
data->PARTAP_PT_FnCrBkOffGhCvOpDy = PARTAP_PT_FnCrBkOffGhCvOpDy_GI ;
data->PARTAP_PT_FnCrBkTrpRunTm = PARTAP_PT_FnCrBkTrpRunTm_GI ;
data->PARTAP_L_FnCtSvEn = PARTAP_L_FnCtSvEn_GI ;
data->PARTAP_L_FnCtSvPrBcEn = PARTAP_L_FnCtSvPrBcEn_GI ;
data->PARTAP_L_FnCtSvSltEn = PARTAP_L_FnCtSvSltEn_GI ;
data->PARTAP_PT_FnCtRp = PARTAP_PT_FnCtRp_GI ;
data->PARTAP_PT_FnCtOnTmOutFlHHtVd = PARTAP_PT_FnCtOnTmOutFlHHtVd_GI ;
data->PARTDP_PI_DcLnErfMax = PARTDP_PI_DcLnErfMax_GI ;
data->PARTDP_L_DsTrpLvSvDcLnErf = PARTDP_L_DsTrpLvSvDcLnErf_GI ;
data->PARTDP_L_DsErfDet = PARTDP_L_DsErfDet_GI ;
data->PARTDP_PX_ErfCntThr = PARTDP_PX_ErfCntThr_GI ;
data->PARTAP_PI_DfInFltMax2qc = PARTAP_PI_DfInFltMax2qc_GI ;
data->PARTAP_PT_DfInFltMaxDy2qc = PARTAP_PT_DfInFltMaxDy2qc_GI ;
data->PARTAP_L_EnErfSvIDf2qc = PARTAP_L_EnErfSvIDf2qc_GI ;
data->PARTAP_L_PraEnErfSvIDf2qc = PARTAP_L_PraEnErfSvIDf2qc_GI ;
data->PARTDP_PT_2qcCal = PARTDP_PT_2qcCal_GI ;
data->PARTDP_PT_3PhCal = PARTDP_PT_3PhCal_GI ;
data->PARTAP_PT_EnIPhCalDy = PARTAP_PT_EnIPhCalDy_GI ;
data->PARTDP_PI_PhCalOsMax_Rw = PARTDP_PI_PhCalOsMax_Rw_GI ;
data->PARTDP_PI_PhCalRipMax_Rw = PARTDP_PI_PhCalRipMax_Rw_GI ;
data->PARTAP_PT_EnUDcLkCalDy = PARTAP_PT_EnUDcLkCalDy_GI ;
data->PARTDP_PU_DcLkCalOsMax_Rw = PARTDP_PU_DcLkCalOsMax_Rw_GI ;
data->PARTDP_PU_DcLkCalRipMax_Rw = PARTDP_PU_DcLkCalRipMax_Rw_GI ;
data->PARTAP_PT_EnU3PhCalDy = PARTAP_PT_EnU3PhCalDy_GI ;
data->PARTDP_PU_3PhCalOsMax_Rw = PARTDP_PU_3PhCalOsMax_Rw_GI ;
data->PARTDP_PU_3PhCalRipMax_Rw = PARTDP_PU_3PhCalRipMax_Rw_GI ;
data->PARTAP_PT_EnIPhInCalDy = PARTAP_PT_EnIPhInCalDy_GI ;
data->PARTDP_PI_PhInCalOsMax_Rw = PARTDP_PI_PhInCalOsMax_Rw_GI ;
data->PARTDP_PI_PhInCalRipMax_Rw = PARTDP_PI_PhInCalRipMax_Rw_GI ;
data->PARTAP_PT_EnIDfInCalDy = PARTAP_PT_EnIDfInCalDy_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1050
data->PARTDP_PI_DfInCalOsMax_Rw = PARTDP_PI_DfInCalOsMax_Rw_GI ;
data->PARTDP_PI_DfInCalRipMax_Rw = PARTDP_PI_DfInCalRipMax_Rw_GI ;
data->PARTDP_PI_RctCalOsMax_Rw = PARTDP_PI_RctCalOsMax_Rw_GI ;
data->PARTDP_PI_RctCalRipMax_Rw = PARTDP_PI_RctCalRipMax_Rw_GI ;
data->PARTAP_PX_CalFl = PARTAP_PX_CalFl_GI ;
data->PARTAP_PT_CalFl = PARTAP_PT_CalFl_GI ;
data->PARTAP_PU_DcLkOnGduPSp = PARTAP_PU_DcLkOnGduPSp_GI ;
data->PARTAP_PT_OnGduPSpDy = PARTAP_PT_OnGduPSpDy_GI ;
data->PARTDP_PX_AnMmDfMax = PARTDP_PX_AnMmDfMax_GI ;
data->PARTDP_PT_AnMmDfDy = PARTDP_PT_AnMmDfDy_GI ;
data->PARTDP_L_FSgSvIgbtPoaEn = PARTDP_L_FSgSvIgbtPoaEn_GI ;
data->PARTDP_L_FSgSvIgbt2qcEn = PARTDP_L_FSgSvIgbt2qcEn_GI ;
data->PARTDP_L_FSgSvGduPoaEn = PARTDP_L_FSgSvGduPoaEn_GI ;
data->PARTDP_L_FSgSvGdu2qcEn = PARTDP_L_FSgSvGdu2qcEn_GI ;
data->PARTDP_PX_FSgSvDvMax = PARTDP_PX_FSgSvDvMax_GI ;
data->PARTDP_L_EnIRctFpgaSv = PARTDP_L_EnIRctFpgaSv_GI ;
data->PARTDP_PI_RctMax = PARTDP_PI_RctMax_GI ;
data->PARTDP_PT_IRctMaxDy = PARTDP_PT_IRctMaxDy_GI ;
data->PARTAP_L_EnIRctBalSv = PARTAP_L_EnIRctBalSv_GI ;
data->PARTAP_PI_RctBalSvMax = PARTAP_PI_RctBalSvMax_GI ;
data->PARTAP_PT_IRctBalSvDy = PARTAP_PT_IRctBalSvDy_GI ;
data->PARTAP_L_2qcEn = PARTAP_L_2qcEn_GI ;
data->PARTDP_L_2qcUDcLk2Mm = PARTDP_L_2qcUDcLk2Mm_GI ;
data->PARTDP_PN_UDcLkRef = PARTDP_PN_UDcLkRef_GI ;
data->PARTAP_PI_PhInRmsHgh2 = PARTAP_PI_PhInRmsHgh2_GI ;
data->PARTAP_PT_IPhInRmsHgh2Dy = PARTAP_PT_IPhInRmsHgh2Dy_GI ;
data->PARTAP_PI_PhInRmsHgh1 = PARTAP_PI_PhInRmsHgh1_GI ;
data->PARTAP_PT_IPhInRmsHgh1Dy = PARTAP_PT_IPhInRmsHgh1Dy_GI ;
data->PARTDP_PT_SiPhBc2qcTmWnd1 = PARTDP_PT_SiPhBc2qcTmWnd1_GI ;
data->PARTDP_PX_SiPhBc2qcMaxWnd1 = PARTDP_PX_SiPhBc2qcMaxWnd1_GI ;
data->PARTDP_PT_SiPhBc2qcTmWnd2 = PARTDP_PT_SiPhBc2qcTmWnd2_GI ;
data->PARTDP_PX_SiPhBc2qcMaxWnd2 = PARTDP_PX_SiPhBc2qcMaxWnd2_GI ;
data->PARTDP_PI_PhIn2qcMax = PARTDP_PI_PhIn2qcMax_GI ;
data->PARTDP_PT_IPhIn2qcMaxDy = PARTDP_PT_IPhIn2qcMaxDy_GI ;
data->PARTAP_L_EnPBalSv = PARTAP_L_EnPBalSv_GI ;
data->PARTAP_PP_BalSv = PARTAP_PP_BalSv_GI ;
data->PARTAP_PT_PBalSv = PARTAP_PT_PBalSv_GI ;
data->PARTAP_PX_UBtMmFl = PARTAP_PX_UBtMmFl_GI ;
data->PARTAP_PT_UBtMmFl = PARTAP_PT_UBtMmFl_GI ;
data->PARTAP_PX_IPhMmFl = PARTAP_PX_IPhMmFl_GI ;
data->PARTAP_PT_IPhMmFl = PARTAP_PT_IPhMmFl_GI ;
data->PARTAP_PX_U3PhMmFl = PARTAP_PX_U3PhMmFl_GI ;
data->PARTAP_PT_U3PhMmFl = PARTAP_PT_U3PhMmFl_GI ;
data->PARTAP_PX_IPhInMmFl = PARTAP_PX_IPhInMmFl_GI ;
data->PARTAP_PT_IPhInMmFl = PARTAP_PT_IPhInMmFl_GI ;
data->PARTAP_PX_UPhInMmFl = PARTAP_PX_UPhInMmFl_GI ;
data->PARTAP_PT_UPhInMmFl = PARTAP_PT_UPhInMmFl_GI ;
data->PARTAP_PX_UDcLkMmFl = PARTAP_PX_UDcLkMmFl_GI ;
data->PARTAP_PT_UDcLkMmFl = PARTAP_PT_UDcLkMmFl_GI ;
data->PARTAP_PX_IDfInMmFl = PARTAP_PX_IDfInMmFl_GI ;
data->PARTAP_PT_IDfInMmFl = PARTAP_PT_IDfInMmFl_GI ;
data->PARTAP_PX_UDcLkDfFl = PARTAP_PX_UDcLkDfFl_GI ;
data->PARTAP_PT_UDcLkDfFl = PARTAP_PT_UDcLkDfFl_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1051
data->PARTAP_PX_IBtCgMmFl = PARTAP_PX_IBtCgMmFl_GI ;
data->PARTAP_PT_IBtCgMmFl = PARTAP_PT_IBtCgMmFl_GI ;
data->PARTAP_PX_IBtMmFl = PARTAP_PX_IBtMmFl_GI ;
data->PARTAP_PT_IBtMmFl = PARTAP_PT_IBtMmFl_GI ;
data->PARTAP_PX_IRctMmFl = PARTAP_PX_IRctMmFl_GI ;
data->PARTAP_PT_IRctMmFl = PARTAP_PT_IRctMmFl_GI ;
data->PARTDP_PT_3PhMmSvRipDy = PARTDP_PT_3PhMmSvRipDy_GI ;
data->PARTDP_PT_2qcMmSvRipDy = PARTDP_PT_2qcMmSvRipDy_GI ;
data->PARTDP_PT_BtCpMmSvRipDy = PARTDP_PT_BtCpMmSvRipDy_GI ;
data->PARTAP_PX_GduFbOnPoaFl = PARTAP_PX_GduFbOnPoaFl_GI ;
data->PARTAP_PT_GduFbOnPoaFl = PARTAP_PT_GduFbOnPoaFl_GI ;
data->PARTAP_PX_GduFbSvPoa = PARTAP_PX_GduFbSvPoa_GI ;
data->PARTAP_PT_GduFbSvPoa = PARTAP_PT_GduFbSvPoa_GI ;
data->PARTAP_PX_GduFbSvOvp = PARTAP_PX_GduFbSvOvp_GI ;
data->PARTAP_PT_GduFbSvOvp = PARTAP_PT_GduFbSvOvp_GI ;
data->PARTAP_PX_GduFbSv2qc = PARTAP_PX_GduFbSv2qc_GI ;
data->PARTAP_PT_GduFbSv2qc = PARTAP_PT_GduFbSv2qc_GI ;
data->PARTAP_PX_OvUDcLk = PARTAP_PX_OvUDcLk_GI ;
data->PARTAP_PT_OvUDcLk = PARTAP_PT_OvUDcLk_GI ;
data->PARTAP_PX_UnUDcLk = PARTAP_PX_UnUDcLk_GI ;
data->PARTAP_PT_UnUDcLk = PARTAP_PT_UnUDcLk_GI ;
data->PARTAP_PX_OvIPh = PARTAP_PX_OvIPh_GI ;
data->PARTAP_PT_OvIPh = PARTAP_PT_OvIPh_GI ;
data->PARTAP_PX_IPhTmWndFl = PARTAP_PX_IPhTmWndFl_GI ;
data->PARTAP_PT_IPhTmWndFl = PARTAP_PT_IPhTmWndFl_GI ;
data->PARTAP_PX_IPhClTmOut = PARTAP_PX_IPhClTmOut_GI ;
data->PARTAP_PT_IPhClTmOut = PARTAP_PT_IPhClTmOut_GI ;
data->PARTAP_PX_IPhClRmsTmFl = PARTAP_PX_IPhClRmsTmFl_GI ;
data->PARTAP_PT_IPhClRmsTmFl = PARTAP_PT_IPhClRmsTmFl_GI ;
data->PARTAP_PX_IPhClTmWnd1Fl = PARTAP_PX_IPhClTmWnd1Fl_GI ;
data->PARTAP_PT_IPhClTmWnd1Fl = PARTAP_PT_IPhClTmWnd1Fl_GI ;
data->PARTAP_PX_IPhDcFl = PARTAP_PX_IPhDcFl_GI ;
data->PARTAP_PT_IPhDcFl = PARTAP_PT_IPhDcFl_GI ;
data->PARTAP_PX_IPhBalFl = PARTAP_PX_IPhBalFl_GI ;
data->PARTAP_PT_IPhBalFl = PARTAP_PT_IPhBalFl_GI ;
data->PARTAP_PX_CtFbSvFl = PARTAP_PX_CtFbSvFl_GI ;
data->PARTAP_PT_CtFbSvFl = PARTAP_PT_CtFbSvFl_GI ;
data->PARTAP_PX_AuLdCtFbSvFl = PARTAP_PX_AuLdCtFbSvFl_GI ;
data->PARTAP_PT_AuLdCtFbSvFl = PARTAP_PT_AuLdCtFbSvFl_GI ;
data->PARTAP_PX_UDcLkChSv = PARTAP_PX_UDcLkChSv_GI ;
data->PARTAP_PT_UDcLkChSv = PARTAP_PT_UDcLkChSv_GI ;
data->PARTAP_PX_UDcLkDhSv = PARTAP_PX_UDcLkDhSv_GI ;
data->PARTAP_PT_UDcLkDhSv = PARTAP_PT_UDcLkDhSv_GI ;
data->PARTAP_PX_OvpFcTsFl = PARTAP_PX_OvpFcTsFl_GI ;
data->PARTAP_PT_OvpFcTsFl = PARTAP_PT_OvpFcTsFl_GI ;
data->PARTAP_PX_OvpRsTpFl = PARTAP_PX_OvpRsTpFl_GI ;
data->PARTAP_PT_OvpRsTpFl = PARTAP_PT_OvpRsTpFl_GI ;
data->PARTAP_PX_SrCtISv = PARTAP_PX_SrCtISv_GI ;
data->PARTAP_PT_SrCtISv = PARTAP_PT_SrCtISv_GI ;
data->PARTAP_PX_3PhSzFl = PARTAP_PX_3PhSzFl_GI ;
data->PARTAP_PT_3PhSzFl = PARTAP_PT_3PhSzFl_GI ;
data->PARTAP_PX_PBalFl = PARTAP_PX_PBalFl_GI ;
data->PARTAP_PT_PBalFl = PARTAP_PT_PBalFl_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1052
data->PARTAP_PX_OvUPhInRmsFl = PARTAP_PX_OvUPhInRmsFl_GI ;
data->PARTAP_PT_OvUPhInRmsFl = PARTAP_PT_OvUPhInRmsFl_GI ;
data->PARTAP_PX_UnUPhInRmsFl = PARTAP_PX_UnUPhInRmsFl_GI ;
data->PARTAP_PT_UnUPhInRmsFl = PARTAP_PT_UnUPhInRmsFl_GI ;
data->PARTAP_PX_OvIPhIn_2qc = PARTAP_PX_OvIPhIn_2qc_GI ;
data->PARTAP_PT_OvIPhIn_2qc = PARTAP_PT_OvIPhIn_2qc_GI ;
data->PARTAP_PX_OvIPhInRms = PARTAP_PX_OvIPhInRms_GI ;
data->PARTAP_PT_OvIPhInRms = PARTAP_PT_OvIPhInRms_GI ;
data->PARTAP_PX_IPhInTmWndFl = PARTAP_PX_IPhInTmWndFl_GI ;
data->PARTAP_PT_IPhInTmWndFl = PARTAP_PT_IPhInTmWndFl_GI ;
data->PARTAP_PX_IDfInErf = PARTAP_PX_IDfInErf_GI ;
data->PARTAP_PT_IDfInErf = PARTAP_PT_IDfInErf_GI ;
data->PARTAP_PX_OvUBtFl = PARTAP_PX_OvUBtFl_GI ;
data->PARTAP_PT_OvUBtFl = PARTAP_PT_OvUBtFl_GI ;
data->PARTAP_PX_UnUBtFl = PARTAP_PX_UnUBtFl_GI ;
data->PARTAP_PT_UnUBtFl = PARTAP_PT_UnUBtFl_GI ;
data->PARTAP_PX_OvIBtCg = PARTAP_PX_OvIBtCg_GI ;
data->PARTAP_PT_OvIBtCg = PARTAP_PT_OvIBtCg_GI ;
data->PARTAP_PX_IBtClTmOut = PARTAP_PX_IBtClTmOut_GI ;
data->PARTAP_PT_IBtClTmOut = PARTAP_PT_IBtClTmOut_GI ;
data->PARTAP_PX_DcCrBrTp = PARTAP_PX_DcCrBrTp_GI ;
data->PARTAP_PT_DcCrBrTp = PARTAP_PT_DcCrBrTp_GI ;
data->PARTAP_PX_FnCrFl = PARTAP_PX_FnCrFl_GI ;
data->PARTAP_PT_FnCrFl = PARTAP_PT_FnCrFl_GI ;
data->PARTAP_PX_HTfSvMax = PARTAP_PX_HTfSvMax_GI ;
data->PARTAP_PT_HTfSvMaxTmWn = PARTAP_PT_HTfSvMaxTmWn_GI ;
data->PARTAP_PX_LngTmOvLd = PARTAP_PX_LngTmOvLd_GI ;
data->PARTAP_PT_LngTmOvLd = PARTAP_PT_LngTmOvLd_GI ;
data->PARTAP_PX_HBtSvMax = PARTAP_PX_HBtSvMax_GI ;
data->PARTAP_PT_HBtSvMaxTmWn = PARTAP_PT_HBtSvMaxTmWn_GI ;
data->PARTAP_PX_HNteArSvMax = PARTAP_PX_HNteArSvMax_GI ;
data->PARTAP_PT_HNteArSvMaxTmWn = PARTAP_PT_HNteArSvMaxTmWn_GI ;
data->PARTAP_PX_HNdSvMax = PARTAP_PX_HNdSvMax_GI ;
data->PARTAP_PT_HNdSvMaxTmWn = PARTAP_PT_HNdSvMaxTmWn_GI ;
data->PARTAP_PX_FSgFl = PARTAP_PX_FSgFl_GI ;
data->PARTAP_PT_FSgFl = PARTAP_PT_FSgFl_GI ;
data->PARTAP_PX_PSpFl = PARTAP_PX_PSpFl_GI ;
data->PARTAP_PT_PSpFl = PARTAP_PT_PSpFl_GI ;
data->PARTAP_PX_MvbWdgFl = PARTAP_PX_MvbWdgFl_GI ;
data->PARTAP_PT_MvbWdgFl = PARTAP_PT_MvbWdgFl_GI ;
data->PARTAP_PX_AdcMmFl = PARTAP_PX_AdcMmFl_GI ;
data->PARTAP_PT_AdcMmFl = PARTAP_PT_AdcMmFl_GI ;
data->PARTAP_PX_DspOvLdFl = PARTAP_PX_DspOvLdFl_GI ;
data->PARTAP_PT_DspOvLdFl = PARTAP_PT_DspOvLdFl_GI ;
data->PARTAP_PX_Nte15VFl = PARTAP_PX_Nte15VFl_GI ;
data->PARTAP_PT_Nte15VFl = PARTAP_PT_Nte15VFl_GI ;
data->PARTAP_PX_25MHzSvFl = PARTAP_PX_25MHzSvFl_GI ;
data->PARTAP_PT_25MHzSvFl = PARTAP_PT_25MHzSvFl_GI ;
data->PARTAP_PX_DspWdAlm = PARTAP_PX_DspWdAlm_GI ;
data->PARTAP_PT_DspWdAlm = PARTAP_PT_DspWdAlm_GI ;
data->PARTAP_PX_DspFpgaComFl = PARTAP_PX_DspFpgaComFl_GI ;
data->PARTAP_PT_DspFpgaComFl = PARTAP_PT_DspFpgaComFl_GI ;
data->PARTAP_PX_OvIRct = PARTAP_PX_OvIRct_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1053
data->PARTAP_PT_OvIRct = PARTAP_PT_OvIRct_GI ;
data->PARTAP_PX_IRctBalSv = PARTAP_PX_IRctBalSv_GI ;
data->PARTAP_PT_IRctBalSv = PARTAP_PT_IRctBalSv_GI ;
data->PARTAP_L_PrlAcm = PARTAP_L_PrlAcm_GI ;
data->PARTAP_PT_CvOpMn = PARTAP_PT_CvOpMn_GI ;
data->PARTAP_PT_SfSdCvSa = PARTAP_PT_SfSdCvSa_GI ;
data->PARTAP_PT_FsSdCvSa = PARTAP_PT_FsSdCvSa_GI ;
data->PARTAP_PT_PrSdCvSa = PARTAP_PT_PrSdCvSa_GI ;
data->PARTAP_PX_NteCoFl = PARTAP_PX_NteCoFl_GI ;
data->PARTAP_PT_NteCoFl = PARTAP_PT_NteCoFl_GI ;
data->PARTAP_PX_TpSnFl = PARTAP_PX_TpSnFl_GI ;
data->PARTAP_PT_TpSnFl = PARTAP_PT_TpSnFl_GI ;
data->PARTAP_PT_AyActMtFn = PARTAP_PT_AyActMtFn_GI ;
data->PARTAP_PV_ExtFnTnHgh = PARTAP_PV_ExtFnTnHgh_GI ;
data->PARTAP_PV_ExtFnTnLow = PARTAP_PV_ExtFnTnLow_GI ;
data->PARTAP_PH_HtFuSpeOnHgh = PARTAP_PH_HtFuSpeOnHgh_GI ;
data->PARTAP_PH_HtFuSpeOfHgh = PARTAP_PH_HtFuSpeOfHgh_GI ;
data->PARTAP_PH_HtFuSpeOnLow = PARTAP_PH_HtFuSpeOnLow_GI ;
data->PARTAP_PH_HtFuSpeOfLow = PARTAP_PH_HtFuSpeOfLow_GI ;
data->PARTAP_PH_NteArFuSpeOnHgh = PARTAP_PH_NteArFuSpeOnHgh_GI ;
data->PARTAP_PH_NteArFuSpeOfHgh = PARTAP_PH_NteArFuSpeOfHgh_GI ;
data->PARTAP_PH_NteArFuSpeOnLow = PARTAP_PH_NteArFuSpeOnLow_GI ;
data->PARTAP_PH_NteArFuSpeOfLow = PARTAP_PH_NteArFuSpeOfLow_GI ;
data->PARTAP_PT_ExtFnFl = PARTAP_PT_ExtFnFl_GI ;
data->PARTAP_PT_DyHfFuExtFnSpe = PARTAP_PT_DyHfFuExtFnSpe_GI ;
data->PARTAP_PT_DyFuHfExtFnSpe = PARTAP_PT_DyFuHfExtFnSpe_GI ;
data->PARTAP_PT_HfExtFnSpeMn = PARTAP_PT_HfExtFnSpeMn_GI ;
data->PARTAP_L_ExtTwoSpFn = PARTAP_L_ExtTwoSpFn_GI ;
data->PARTAP_PH_BrdFuSpeOfLow = PARTAP_PH_BrdFuSpeOfLow_GI ;
data->PARTAP_PH_BrdFuSpeOnLow = PARTAP_PH_BrdFuSpeOnLow_GI ;
data->PARTAP_PH_BrdFuSpeOfHgh = PARTAP_PH_BrdFuSpeOfHgh_GI ;
data->PARTAP_PH_BrdFuSpeOnHgh = PARTAP_PH_BrdFuSpeOnHgh_GI ;
data->PARTAP_PT_FnOfDy = PARTAP_PT_FnOfDy_GI ;
data->PARTAP_PH_NteTpDfMax = PARTAP_PH_NteTpDfMax_GI ;
data->PARTAP_PT_NteTpDf = PARTAP_PT_NteTpDf_GI ;
data->PARTAP_L_SfSdNteCoFl = PARTAP_L_SfSdNteCoFl_GI ;
data->PARTAP_L_BcDcuBrdTpNotVd = PARTAP_L_BcDcuBrdTpNotVd_GI ;
data->PARTAP_L_BcHtCoTpNotVd = PARTAP_L_BcHtCoTpNotVd_GI ;
data->PARTAP_L_BcNteArTpNotVd = PARTAP_L_BcNteArTpNotVd_GI ;
data->PARTAP_PH_HtCoOs = PARTAP_PH_HtCoOs_GI ;
data->PARTAP_PH_DcuBrdOs = PARTAP_PH_DcuBrdOs_GI ;
data->PARTAP_L_MltTpSnSvEn = PARTAP_L_MltTpSnSvEn_GI ;
data->PARTAP_PT_TpSnDy = PARTAP_PT_TpSnDy_GI ;
data->PARTAP_PX_IdPrSdPcl = PARTAP_PX_IdPrSdPcl_GI ;
data->PARTAP_PX_IdFsSdPcl = PARTAP_PX_IdFsSdPcl_GI ;
data->PARTAP_PX_IdSfSdPcl = PARTAP_PX_IdSfSdPcl_GI ;
data->PARTAP_PX_IdPrBcPcl = PARTAP_PX_IdPrBcPcl_GI ;
data->PARTAP_PX_IdClPcl = PARTAP_PX_IdClPcl_GI ;
data->PARTAP_PX_IdHwPcl = PARTAP_PX_IdHwPcl_GI ;
data->PARTAP_PX_IdTpPcl = PARTAP_PX_IdTpPcl_GI ;
data->PARTAP_PI_BtCpThr = PARTAP_PI_BtCpThr_GI ;
data->PARTAP_PT_BtCpCurBc = PARTAP_PT_BtCpCurBc_GI ;
data->PARTAP_PT_BtCpSfBc = PARTAP_PT_BtCpSfBc_GI ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1054
data->PARTAP_PT_BtCpAvTm = PARTAP_PT_BtCpAvTm_GI ;
data->PARTDP_PX_KpIBtCpCl = PARTDP_PX_KpIBtCpCl_GI ;
data->PARTDP_PX_KiIBtCpCl = PARTDP_PX_KiIBtCpCl_GI ;
data->PARTDP_PF_BtCpSg = PARTDP_PF_BtCpSg_GI ;
data->PARTDP_PI_IBtCp_Max = PARTDP_PI_IBtCp_Max_GI ;
data->PARTDP_PN_IEstBtCg_Flt = PARTDP_PN_IEstBtCg_Flt_GI ;
data->PARTDP_PN_UBtCp_Flt = PARTDP_PN_UBtCp_Flt_GI ;
data->PARTAP_L_EnCtSm = PARTAP_L_EnCtSm_GI ;
data->PARTGP_NX_DevCodFpga2 = PARTGP_NX_DevCodFpga2_GI ;
data->PARTGP_NX_VerCodFd1Fpga2 = PARTGP_NX_VerCodFd1Fpga2_GI ;
data->PARTGP_NX_VerCodFd2Fpga2 = PARTGP_NX_VerCodFd2Fpga2_GI ;
data->PARTGP_NX_VerCodFd3Fpga2 = PARTGP_NX_VerCodFd3Fpga2_GI ;
data->PARTGP_NX_VerCodFd4Fpga2 = PARTGP_NX_VerCodFd4Fpga2_GI ;
data->PARTGP_NX_VerCodFd5Fpga2 = PARTGP_NX_VerCodFd5Fpga2_GI ;
data->PARTGP_NX_DevCodDsp = PARTGP_NX_DevCodDsp_GI ;
data->PARTGP_NX_VerCodFd1Dsp = PARTGP_NX_VerCodFd1Dsp_GI ;
data->PARTGP_NX_VerCodFd2Dsp = PARTGP_NX_VerCodFd2Dsp_GI ;
data->PARTGP_NX_VerCodFd3Dsp = PARTGP_NX_VerCodFd3Dsp_GI ;
data->PARTGP_NX_VerCodFd4Dsp = PARTGP_NX_VerCodFd4Dsp_GI ;
data->PARTGP_NX_VerCodFd5Dsp = PARTGP_NX_VerCodFd5Dsp_GI ;
data->PARTDP_PU_BtCpClFl = PARTDP_PU_BtCpClFl_GI ;
data->PARTDP_PT_BtCpClFlDy = PARTDP_PT_BtCpClFlDy_GI ;
data->PARTDP_L_3PhRndEn = PARTDP_L_3PhRndEn_GI ;
data->PARTDP_PI_BtCgCalOsMax_Rw = PARTDP_PI_BtCgCalOsMax_Rw_GI ;
first = FALSE ;
}

