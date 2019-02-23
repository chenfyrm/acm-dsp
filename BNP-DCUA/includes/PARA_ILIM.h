/* ------------------------------------------------------------------------
Module : PARA_ILIM
Abstract : Definition of initial values for resource PAR
Created : PC/P-Tool version 2.1.1.32 at 3/22/2016, 2:40:59 PM
Project : DCUA MCX Gen 3 Appl. Engineer : PP4 MCX Team
Device : MCU/A Par. version : 0.0.0.0
Spare : -
Spare : -
Spare : -
Remarks : Import this file in MTPE into a resource named PAR
------------------------------------------------------------------------
Copyright : (c) 2006 Bombardier Transportation
------------------------------------------------------------------------ */
#ifndef PARA_ILIM_H
#define PARA_ILIM_H
#include "mwt_types.h"
#ifdef LIMIT_UNUSED
#elif defined(__GNUC__)
#define LIMIT_UNUSED __attribute__((unused))
#else
#define LIMIT_UNUSED
#endif
/* limits for independent system specific parameters of PAR
*/
static MWT_UINT PARTAP_NX_ParVer_maximum = 65535 ;
static MWT_UINT PARTAP_NX_ParVer_minimum = 0 ;
static MWT_REAL PARTAP_PI_PhMmSvSrOp_maximum = 50.0 ;
static MWT_REAL PARTAP_PI_PhMmSvSrOp_minimum = -10.0 ;
static MWT_TIME PARTAP_PT_IPhMmSvSrOp_maximum = 5000 ;
static MWT_TIME PARTAP_PT_IPhMmSvSrOp_minimum = 0 ;
static MWT_REAL PARTAP_PI_PhMmSvNg_maximum = 0.0 ;
static MWT_REAL PARTAP_PI_PhMmSvNg_minimum = -500.0 ;
static MWT_TIME PARTAP_PT_IPhMmSvNg_maximum = 5000 ;
static MWT_TIME PARTAP_PT_IPhMmSvNg_minimum = 0 ;
static MWT_REAL PARTAP_PU_U3PhMmSvMin_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_U3PhMmSvMin_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_U3PhMmSvOpLo_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_U3PhMmSvOpLo_minimum = 0 ;
static MWT_TIME PARTAP_PT_U3PhMmSvMin_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_U3PhMmSvMin_minimum = 0 ;
static MWT_REAL PARTAP_PX_FRefRmpUpIPhInHgh_maximum = 1000.0 ;
static MWT_REAL PARTAP_PX_FRefRmpUpIPhInHgh_minimum = 1.0 ;
static MWT_REAL PARTAP_PX_FRefRmpDo1_maximum = 2000.0 ;
static MWT_REAL PARTAP_PX_FRefRmpDo1_minimum = 0.1 ;
static MWT_REAL PARTAP_PX_FRefRmpDo2_maximum = 2000.0 ;
static MWT_REAL PARTAP_PX_FRefRmpDo2_minimum = 0.1 ;
static MWT_REAL PARTAP_PX_FRefRmpDo3_maximum = 2000.0 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1256
static MWT_REAL PARTAP_PX_FRefRmpDo3_minimum = 0.1 ;
static MWT_REAL PARTAP_PF_FRefRmpDo12_maximum = 100.0 ;
static MWT_REAL PARTAP_PF_FRefRmpDo12_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_FRefRmpDo23_maximum = 100.0 ;
static MWT_REAL PARTAP_PF_FRefRmpDo23_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_3PhIPhDcClEn_maximum = 100.0 ;
static MWT_REAL PARTAP_PF_3PhIPhDcClEn_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_UDcLkMin_maximum = 100.0 ;
static MWT_REAL PARTAP_PF_UDcLkMin_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_DcLkFRefLow_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkFRefLow_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_DcLkFRefMin_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkFRefMin_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_FRefRmpUDcLkUp_maximum = 2000.0 ;
static MWT_REAL PARTAP_PX_FRefRmpUDcLkUp_minimum = 1.0 ;
static MWT_REAL PARTAP_PX_FRefRmpUDcLkDo_maximum = 2000.0 ;
static MWT_REAL PARTAP_PX_FRefRmpUDcLkDo_minimum = 1.0 ;
static MWT_REAL PARTAP_PF_3PhMin_maximum = 50.0 ;
static MWT_REAL PARTAP_PF_3PhMin_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_PhInFRefRmp_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_PhInFRefRmp_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_PhInFRefRmp_maximum = 22500.0 ;
static MWT_REAL PARTAP_PI_PhInFRefRmp_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_3PhClRefMin_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_3PhClRefMin_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_3PhClMax_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_3PhClMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_3PhClMin_maximum = 0.0 ;
static MWT_REAL PARTAP_PU_3PhClMin_minimum = -1000.0 ;
static MWT_REAL PARTAP_PX_KpU3PhCl_maximum = 50000.0 ;
static MWT_REAL PARTAP_PX_KpU3PhCl_minimum = 0.0 ;
static MWT_REAL PARTAP_PT_U3PhCl_maximum = 100000.0 ;
static MWT_REAL PARTAP_PT_U3PhCl_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_U3PhRef2_maximum = 100.0 ;
static MWT_REAL PARTAP_PF_U3PhRef2_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_U3PhRef3_maximum = 100.0 ;
static MWT_REAL PARTAP_PF_U3PhRef3_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_U3PhRef1_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_U3PhRef1_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_U3PhRef2_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_U3PhRef2_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_FRefUDcLk_maximum = 5000 ;
static MWT_TIME PARTAP_PT_FRefUDcLk_minimum = 0 ;
static MWT_REAL PARTAP_PX_ExtU3PhRefRmp_maximum = 2000.0 ;
static MWT_REAL PARTAP_PX_ExtU3PhRefRmp_minimum = 1.0 ;
static MWT_REAL PARTAP_PX_U3PhRefRmp1_maximum = 10000.0 ;
static MWT_REAL PARTAP_PX_U3PhRefRmp1_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_U3PhRefRmp2_maximum = 10000.0 ;
static MWT_REAL PARTAP_PX_U3PhRefRmp2_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_U3PhRefRmpSel_maximum = 1.0 ;
static MWT_REAL PARTAP_PX_U3PhRefRmpSel_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_UBtRef_maximum = 1000.0 ;
static MWT_REAL PARTAP_PI_UBtRef_minimum = 0.0 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1257
static MWT_TIME PARTAP_PT_BtRfCg_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_BtRfCg_minimum = 0 ;
static MWT_REAL PARTAP_PX_UBtRefRmpUp_maximum = 2000.0 ;
static MWT_REAL PARTAP_PX_UBtRefRmpUp_minimum = 1.0 ;
static MWT_REAL PARTAP_PX_UBtRefRmpDo_maximum = 2000.0 ;
static MWT_REAL PARTAP_PX_UBtRefRmpDo_minimum = 1.0 ;
static MWT_REAL PARTAP_PU_UBtClMax_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_UBtClMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_UBtClMin_maximum = 0.0 ;
static MWT_REAL PARTAP_PU_UBtClMin_minimum = -1000.0 ;
static MWT_REAL PARTAP_PX_KpUBtCl_maximum = 50000.0 ;
static MWT_REAL PARTAP_PX_KpUBtCl_minimum = 0.0 ;
static MWT_REAL PARTAP_PT_UBtCl_maximum = 100000.0 ;
static MWT_REAL PARTAP_PT_UBtCl_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_TrfRtBt3Ph_maximum = 100.0 ;
static MWT_REAL PARTAP_PX_TrfRtBt3Ph_minimum = 0.01 ;
static MWT_REAL PARTAP_PX_TrfRtPrBt_maximum = 100.0 ;
static MWT_REAL PARTAP_PX_TrfRtPrBt_minimum = 0.01 ;
static MWT_REAL PARTAP_PH_RctHtRef1_maximum = 1000.0 ;
static MWT_REAL PARTAP_PH_RctHtRef1_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_RctHtRef2_maximum = 1000.0 ;
static MWT_REAL PARTAP_PH_RctHtRef2_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_RctHtHBtRef_maximum = 1.0 ;
static MWT_REAL PARTAP_PX_RctHtHBtRef_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_UBtCpRefRmp_maximum = 1000.0 ;
static MWT_REAL PARTAP_PX_UBtCpRefRmp_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_IPhClMin_maximum = 50.0 ;
static MWT_REAL PARTAP_PF_IPhClMin_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_IPhClMinErr_maximum = 50.0 ;
static MWT_REAL PARTAP_PF_IPhClMinErr_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_IPhClIntMax_maximum = 100000.0 ;
static MWT_REAL PARTAP_PX_IPhClIntMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_IPhClIntMin_maximum = 0.0 ;
static MWT_REAL PARTAP_PX_IPhClIntMin_minimum = -100000.0 ;
static MWT_TIME PARTAP_PT_IPhClInt_maximum = 100000 ;
static MWT_TIME PARTAP_PT_IPhClInt_minimum = 0 ;
static MWT_REAL PARTAP_PI_IPhClActMax_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_IPhClActMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_IPhClActMin_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_IPhClActMin_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_IPhClActPsTrs_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_IPhClActPsTrs_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_IPhClActOs_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_IPhClActOs_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_IPhClActDe_maximum = 50000.0 ;
static MWT_REAL PARTAP_PX_IPhClActDe_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_IPhClRctMax_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_IPhClRctMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_IPhClRctMin_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_IPhClRctMin_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_IPhClRctPsTrs_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_IPhClRctPsTrs_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_IPhClRctOs_maximum = 5000.0 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1258
static MWT_REAL PARTAP_PI_IPhClRctOs_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_IPhClRctDePos_maximum = 50000.0 ;
static MWT_REAL PARTAP_PX_IPhClRctDePos_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_IPhClRctDeNg_maximum = 50000.0 ;
static MWT_REAL PARTAP_PX_IPhClRctDeNg_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_IPhClPsTrsLim_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_IPhClPsTrsLim_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_IBtCgRmp_maximum = 50000.0 ;
static MWT_REAL PARTAP_PX_IBtCgRmp_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_RfCgLim_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_RfCgLim_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_KpIBtCl_maximum = 50000.0 ;
static MWT_REAL PARTAP_PX_KpIBtCl_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_IBtClMax_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_IBtClMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_UF3PhCmpActHiLo_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_UF3PhCmpActHiLo_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_UF3PhCmpActHiLo_maximum = 0.0 ;
static MWT_REAL PARTAP_PF_UF3PhCmpActHiLo_minimum = -100.0 ;
static MWT_REAL PARTAP_PI_UF3PhCmpRctHiLo_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_UF3PhCmpRctHiLo_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_UF3PhSzClMaxMin_maximum = 50.0 ;
static MWT_REAL PARTAP_PF_UF3PhSzClMaxMin_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UF3PhSzRmp_maximum = 5000 ;
static MWT_TIME PARTAP_PT_UF3PhSzRmp_minimum = 0 ;
static MWT_REAL PARTAP_PU_UF3PhSzClAdd_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_UF3PhSzClAdd_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_UF3PhSzClMaxMin_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_UF3PhSzClMaxMin_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UF3PhSzFl_maximum = 30000 ;
static MWT_TIME PARTAP_PT_UF3PhSzFl_minimum = 0 ;
static MWT_REAL PARTAP_PU_DcLkUHgh_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkUHgh_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_2qcOpChRdy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_2qcOpChRdy_minimum = 0 ;
static MWT_REAL PARTAP_PU_3PhDcLkCvDh_maximum = 1000.0 ;
static MWT_REAL PARTAP_PU_3PhDcLkCvDh_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_3PhDcLkCvDh_maximum = 100.0 ;
static MWT_REAL PARTAP_PF_3PhDcLkCvDh_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_3PhIdlCmp_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_3PhIdlCmp_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_3PhActCmp_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_3PhActCmp_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_DySrCtOp_maximum = 5000 ;
static MWT_TIME PARTAP_PT_DySrCtOp_minimum = 0 ;
static MWT_TIME PARTAP_PT_DyAuLdCtOp_maximum = 5000 ;
static MWT_TIME PARTAP_PT_DyAuLdCtOp_minimum = 0 ;
static MWT_TIME PARTAP_PT_TmOutPrSd_maximum = 1800000 ;
static MWT_TIME PARTAP_PT_TmOutPrSd_minimum = 1000 ;
static MWT_TIME PARTAP_PT_TmOutFsSd_maximum = 1800000 ;
static MWT_TIME PARTAP_PT_TmOutFsSd_minimum = 1000 ;
static MWT_TIME PARTAP_PT_TmOutSfSd_maximum = 1800000 ;
static MWT_TIME PARTAP_PT_TmOutSfSd_minimum = 1000 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1259
static MWT_TIME PARTAP_PT_TmOutPrBc_maximum = 1800000 ;
static MWT_TIME PARTAP_PT_TmOutPrBc_minimum = 1000 ;
static MWT_INT PARTAP_PX_NoFlMvbCy_Hgh_maximum = 15 ;
static MWT_INT PARTAP_PX_NoFlMvbCy_Hgh_minimum = 2 ;
static MWT_INT PARTAP_PX_NoFlMvbCy_Max_maximum = 30 ;
static MWT_INT PARTAP_PX_NoFlMvbCy_Max_minimum = 2 ;
static MWT_TIME PARTAP_PT_UDcLkHgh2_maximum = 100000 ;
static MWT_TIME PARTAP_PT_UDcLkHgh2_minimum = 0 ;
static MWT_REAL PARTAP_PU_DcLkHghRst_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkHghRst_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UDcLkLowDy_maximum = 100000 ;
static MWT_TIME PARTAP_PT_UDcLkLowDy_minimum = 0 ;
static MWT_UINT PARTAP_PX_IBtCpTmWndFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IBtCpTmWndFl_minimum = 0 ;
static MWT_TIME PARTAP_PT_IBtCpTmWndFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IBtCpTmWndFl_minimum = 1000 ;
static MWT_TIME PARTAP_PT_IAcLimTmSvDy_maximum = 120000 ;
static MWT_TIME PARTAP_PT_IAcLimTmSvDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_IPhClTrsAvTof_maximum = 10000 ;
static MWT_TIME PARTAP_PT_IPhClTrsAvTof_minimum = 0 ;
static MWT_REAL PARTAP_PI_PhDcSvMax_maximum = 100.0 ;
static MWT_REAL PARTAP_PI_PhDcSvMax_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_IPhDcSvMaxDy_maximum = 120000 ;
static MWT_TIME PARTAP_PT_IPhDcSvMaxDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_IBalSvDelDy_maximum = 120000 ;
static MWT_TIME PARTAP_PT_IBalSvDelDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_IBalSvDyCvOp_maximum = 30000 ;
static MWT_TIME PARTAP_PT_IBalSvDyCvOp_minimum = 0 ;
static MWT_TIME PARTAP_PT_GduFbCk_Mx_maximum = 5000 ;
static MWT_TIME PARTAP_PT_GduFbCk_Mx_minimum = 0 ;
static MWT_UINT PARTAP_PX_GduFbSvBtCp_maximum = 1000 ;
static MWT_UINT PARTAP_PX_GduFbSvBtCp_minimum = 1 ;
static MWT_TIME PARTAP_PT_GduFbSvBtCp_maximum = 10000000 ;
static MWT_TIME PARTAP_PT_GduFbSvBtCp_minimum = 1000 ;
static MWT_REAL PARTAP_PU_3PhRmsMax_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_3PhRmsMax_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_U3PhRmsMax_maximum = 120000 ;
static MWT_TIME PARTAP_PT_U3PhRmsMax_minimum = 0 ;
static MWT_UINT PARTAP_PX_OvU3Ph_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvU3Ph_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvU3Ph_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvU3Ph_minimum = 1000 ;
static MWT_REAL PARTAP_PU_BtMax_maximum = 200.0 ;
static MWT_REAL PARTAP_PU_BtMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_BtHgh_maximum = 200.0 ;
static MWT_REAL PARTAP_PU_BtHgh_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UBtHghDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_UBtHghDy_minimum = 0 ;
static MWT_REAL PARTAP_PU_BtHghRst_maximum = 200.0 ;
static MWT_REAL PARTAP_PU_BtHghRst_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_BtMin_maximum = 200.0 ;
static MWT_REAL PARTAP_PU_BtMin_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UBtMinDy_maximum = 120000 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1260
static MWT_TIME PARTAP_PT_UBtMinDy_minimum = 0 ;
static MWT_REAL PARTAP_PU_BtMinRst_maximum = 200.0 ;
static MWT_REAL PARTAP_PU_BtMinRst_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_BtOpAuLdCt_maximum = 200.0 ;
static MWT_REAL PARTAP_PU_BtOpAuLdCt_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UBtOpAuLdCtDy_maximum = 120000 ;
static MWT_TIME PARTAP_PT_UBtOpAuLdCtDy_minimum = 0 ;
static MWT_REAL PARTAP_PU_BtCdAuLdCt_maximum = 200.0 ;
static MWT_REAL PARTAP_PU_BtCdAuLdCt_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_BtMinChTm_maximum = 120000 ;
static MWT_TIME PARTAP_PT_BtMinChTm_minimum = 0 ;
static MWT_TIME PARTAP_PT_IBtCgFltHghDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_IBtCgFltHghDy_minimum = 0 ;
static MWT_REAL PARTAP_PI_BtCpFltHgh_maximum = 1000.0 ;
static MWT_REAL PARTAP_PI_BtCpFltHgh_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_IBtCpFltHghDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_IBtCpFltHghDy_minimum = 0 ;
static MWT_REAL PARTAP_PX_IBtCgLimHghFr_maximum = 1.0 ;
static MWT_REAL PARTAP_PX_IBtCgLimHghFr_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_OffGhIBtCgLimHghDy_maximum = 120000000 ;
static MWT_TIME PARTAP_PT_OffGhIBtCgLimHghDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_IBtCgLimHghDy_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IBtCgLimHghDy_minimum = 0 ;
static MWT_REAL PARTAP_PI_BtCgLim_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_BtCgLim_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_IBtLimHghFr_maximum = 100.0 ;
static MWT_REAL PARTAP_PX_IBtLimHghFr_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_OffGhIBtLimHghDy_maximum = 32000000 ;
static MWT_TIME PARTAP_PT_OffGhIBtLimHghDy_minimum = 0 ;
static MWT_REAL PARTAP_PH_AmTp_Max_maximum = 100.0 ;
static MWT_REAL PARTAP_PH_AmTp_Max_minimum = 0.0 ;
static MWT_REAL PARTAP_PT_ChRsCoTmCns_maximum = 10000.0 ;
static MWT_REAL PARTAP_PT_ChRsCoTmCns_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_ChRsTp_UpThr_maximum = 1500.0 ;
static MWT_REAL PARTAP_PH_ChRsTp_UpThr_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_ChRsTp_LowThr_maximum = 1500.0 ;
static MWT_REAL PARTAP_PH_ChRsTp_LowThr_minimum = 0.0 ;
static MWT_REAL PARTAP_PR_ChRs_maximum = 2000.0 ;
static MWT_REAL PARTAP_PR_ChRs_minimum = 0.1 ;
static MWT_REAL PARTAP_PK_ChRs_maximum = 20000.0 ;
static MWT_REAL PARTAP_PK_ChRs_minimum = 0.0 ;
static MWT_REAL PARTAP_PC_DcLk_maximum = 0.05 ;
static MWT_REAL PARTAP_PC_DcLk_minimum = 0.0001 ;
static MWT_UINT PARTAP_PN_ChDcLkCnt_maximum = 10 ;
static MWT_UINT PARTAP_PN_ChDcLkCnt_minimum = 1 ;
static MWT_TIME PARTAP_PT_ChDcLkCnt_maximum = 10000000 ;
static MWT_TIME PARTAP_PT_ChDcLkCnt_minimum = 0 ;
static MWT_TIME PARTAP_PT_CtOnDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_CtOnDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_CtOfDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_CtOfDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_CtFi_maximum = 5000 ;
static MWT_TIME PARTAP_PT_CtFi_minimum = 0 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1261
static MWT_TIME PARTAP_PT_AuLdCtOnDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_AuLdCtOnDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_AuLdCtFi_maximum = 5000 ;
static MWT_TIME PARTAP_PT_AuLdCtFi_minimum = 0 ;
static MWT_TIME PARTAP_PT_AuLdCtOfDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_AuLdCtOfDy_minimum = 0 ;
static MWT_REAL PARTAP_PU_DcLkChLv1_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkChLv1_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_DcLkChLv2_maximum = 1.0 ;
static MWT_REAL PARTAP_PX_DcLkChLv2_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_DcLkChDyLv1_maximum = 5000 ;
static MWT_TIME PARTAP_PT_DcLkChDyLv1_minimum = 0 ;
static MWT_TIME PARTAP_PT_DcLkChDyLv2_maximum = 5000 ;
static MWT_TIME PARTAP_PT_DcLkChDyLv2_minimum = 0 ;
static MWT_REAL PARTAP_PU_DhDcLk_Max_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DhDcLk_Max_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_DcLkDhDy_maximum = 300000 ;
static MWT_TIME PARTAP_PT_DcLkDhDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_FrOvp_maximum = 5000 ;
static MWT_TIME PARTAP_PT_FrOvp_minimum = 0 ;
static MWT_REAL PARTAP_PU_DcLkCvSlDh_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkCvSlDh_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_DyOvpFcTs_maximum = 5000 ;
static MWT_TIME PARTAP_PT_DyOvpFcTs_minimum = 0 ;
static MWT_REAL PARTAP_PU_DcLkU_OvpFcTs_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkU_OvpFcTs_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_SrCtISv_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_SrCtISv_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_ChCtISv_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_ChCtISv_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_SrCtISvDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_SrCtISvDy_minimum = 0 ;
static MWT_REAL PARTAP_PH_HtSvMax_maximum = 150.0 ;
static MWT_REAL PARTAP_PH_HtSvMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_HtSvHgh2_maximum = 100.0 ;
static MWT_REAL PARTAP_PH_HtSvHgh2_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_HtSvHgh1_maximum = 100.0 ;
static MWT_REAL PARTAP_PH_HtSvHgh1_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_HtSvRst_maximum = 150.0 ;
static MWT_REAL PARTAP_PH_HtSvRst_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_HHtSvMax_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HHtSvMax_minimum = 0 ;
static MWT_TIME PARTAP_PT_HHtSvHgh2_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HHtSvHgh2_minimum = 0 ;
static MWT_TIME PARTAP_PT_HHtSvHgh1_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HHtSvHgh1_minimum = 0 ;
static MWT_REAL PARTAP_PI_HtSvHgh2_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_HtSvHgh2_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_HtSvCntLim_maximum = 1.0 ;
static MWT_REAL PARTAP_PX_HtSvCntLim_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_HtSvOvLdLim_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HtSvOvLdLim_minimum = 0 ;
static MWT_UINT PARTAP_PX_HHtSvMax_maximum = 1000 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1262
static MWT_UINT PARTAP_PX_HHtSvMax_minimum = 1 ;
static MWT_TIME PARTAP_PT_HHtSvMaxTmWn_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_HHtSvMaxTmWn_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IgbtOvLd_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IgbtOvLd_minimum = 1 ;
static MWT_TIME PARTAP_PT_IgbtOvLd_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IgbtOvLd_minimum = 1000 ;
static MWT_REAL PARTAP_PH_RctHtMax_maximum = 1000.0 ;
static MWT_REAL PARTAP_PH_RctHtMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_RctHtSvHgh_maximum = 1000.0 ;
static MWT_REAL PARTAP_PH_RctHtSvHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_RctHtSvRst_maximum = 1000.0 ;
static MWT_REAL PARTAP_PH_RctHtSvRst_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_RctHtSvMax_maximum = 100000 ;
static MWT_TIME PARTAP_PT_RctHtSvMax_minimum = 0 ;
static MWT_TIME PARTAP_PT_RctHtSvHgh_maximum = 100000 ;
static MWT_TIME PARTAP_PT_RctHtSvHgh_minimum = 0 ;
static MWT_REAL PARTAP_PH_TfSvMax_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_TfSvMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_TfSvHgh2_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_TfSvHgh2_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_TfSvHgh1_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_TfSvHgh1_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_TfSvRst_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_TfSvRst_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_HTfSvMax_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HTfSvMax_minimum = 0 ;
static MWT_TIME PARTAP_PT_HTfSvHgh2_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HTfSvHgh2_minimum = 0 ;
static MWT_TIME PARTAP_PT_HTfSvHgh1_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HTfSvHgh1_minimum = 0 ;
static MWT_TIME PARTAP_PT_LngTmOvLdInt_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_LngTmOvLdInt_minimum = 0 ;
static MWT_REAL PARTAP_PI_LngTmOvLdMax_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_LngTmOvLdMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_LngTmOvLdHgh_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_LngTmOvLdHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_LngTmOvLdRst_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_LngTmOvLdRst_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_LngTmOvLdHgh_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_LngTmOvLdHgh_minimum = 0 ;
static MWT_TIME PARTAP_PT_HBtSvMax_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HBtSvMax_minimum = 0 ;
static MWT_TIME PARTAP_PT_HBtSvHgh_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HBtSvHgh_minimum = 0 ;
static MWT_REAL PARTAP_PH_NteArSvMax_maximum = 150.0 ;
static MWT_REAL PARTAP_PH_NteArSvMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_NteArSvHgh2_maximum = 150.0 ;
static MWT_REAL PARTAP_PH_NteArSvHgh2_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_NteArSvHgh1_maximum = 150.0 ;
static MWT_REAL PARTAP_PH_NteArSvHgh1_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_NteArSvRst_maximum = 150.0 ;
static MWT_REAL PARTAP_PH_NteArSvRst_minimum = 0.0 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1263
static MWT_TIME PARTAP_PT_HNteArSvMax_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HNteArSvMax_minimum = 0 ;
static MWT_TIME PARTAP_PT_HNteArSvHgh2_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HNteArSvHgh2_minimum = 0 ;
static MWT_TIME PARTAP_PT_HNteArSvHgh1_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HNteArSvHgh1_minimum = 0 ;
static MWT_REAL PARTAP_PH_NdSvMax_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_NdSvMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_NdSvHgh_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_NdSvHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_NdSvRst_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_NdSvRst_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_HNdSvMax_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HNdSvMax_minimum = 0 ;
static MWT_TIME PARTAP_PT_HNdSvHgh_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HNdSvHgh_minimum = 0 ;
static MWT_TIME PARTAP_PT_HNdSnFl_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HNdSnFl_minimum = 1 ;
static MWT_REAL PARTAP_PU_DcLkLowDcCrBkSv_maximum = 3000.0 ;
static MWT_REAL PARTAP_PU_DcLkLowDcCrBkSv_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_DcCrBkSvDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_DcCrBkSvDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_DcCrBkTrpRunTm_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_DcCrBkTrpRunTm_minimum = 0 ;
static MWT_TIME PARTAP_PT_FnCrBkFbOpGhDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_FnCrBkFbOpGhDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_FnCrBkOffGhCvOpDy_maximum = 32000000 ;
static MWT_TIME PARTAP_PT_FnCrBkOffGhCvOpDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_FnCrBkTrpRunTm_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_FnCrBkTrpRunTm_minimum = 0 ;
static MWT_TIME PARTAP_PT_FnCtRp_maximum = 120000 ;
static MWT_TIME PARTAP_PT_FnCtRp_minimum = 0 ;
static MWT_TIME PARTAP_PT_FnCtOnTmOutFlHHtVd_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_FnCtOnTmOutFlHHtVd_minimum = 0 ;
static MWT_REAL PARTAP_PI_DfInFltMax2qc_maximum = 1000.0 ;
static MWT_REAL PARTAP_PI_DfInFltMax2qc_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_DfInFltMaxDy2qc_maximum = 120000 ;
static MWT_TIME PARTAP_PT_DfInFltMaxDy2qc_minimum = 0 ;
static MWT_TIME PARTAP_PT_EnIPhCalDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_EnIPhCalDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_EnUDcLkCalDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_EnUDcLkCalDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_EnU3PhCalDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_EnU3PhCalDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_EnIPhInCalDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_EnIPhInCalDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_EnIDfInCalDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_EnIDfInCalDy_minimum = 0 ;
static MWT_UINT PARTAP_PX_CalFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_CalFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_CalFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_CalFl_minimum = 1000 ;
static MWT_REAL PARTAP_PU_DcLkOnGduPSp_maximum = 4200.0 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1264
static MWT_REAL PARTAP_PU_DcLkOnGduPSp_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_OnGduPSpDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_OnGduPSpDy_minimum = 0 ;
static MWT_REAL PARTAP_PI_RctBalSvMax_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_RctBalSvMax_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_IRctBalSvDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_IRctBalSvDy_minimum = 0 ;
static MWT_REAL PARTAP_PI_PhInRmsHgh2_maximum = 3000.0 ;
static MWT_REAL PARTAP_PI_PhInRmsHgh2_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_IPhInRmsHgh2Dy_maximum = 120000 ;
static MWT_TIME PARTAP_PT_IPhInRmsHgh2Dy_minimum = 0 ;
static MWT_REAL PARTAP_PI_PhInRmsHgh1_maximum = 3000.0 ;
static MWT_REAL PARTAP_PI_PhInRmsHgh1_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_IPhInRmsHgh1Dy_maximum = 120000 ;
static MWT_TIME PARTAP_PT_IPhInRmsHgh1Dy_minimum = 0 ;
static MWT_REAL PARTAP_PP_BalSv_maximum = 1000000.0 ;
static MWT_REAL PARTAP_PP_BalSv_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_PBalSv_maximum = 100000 ;
static MWT_TIME PARTAP_PT_PBalSv_minimum = 0 ;
static MWT_UINT PARTAP_PX_UBtMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_UBtMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_UBtMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_UBtMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IPhMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IPhMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_IPhMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IPhMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_U3PhMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_U3PhMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_U3PhMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_U3PhMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IPhInMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IPhInMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_IPhInMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IPhInMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_UPhInMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_UPhInMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_UPhInMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_UPhInMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_UDcLkMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_UDcLkMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_UDcLkMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_UDcLkMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IDfInMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IDfInMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_IDfInMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IDfInMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_UDcLkDfFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_UDcLkDfFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_UDcLkDfFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_UDcLkDfFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IBtCgMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IBtCgMmFl_minimum = 1 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1265
static MWT_TIME PARTAP_PT_IBtCgMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IBtCgMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IBtMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IBtMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_IBtMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IBtMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IRctMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IRctMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_IRctMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IRctMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_GduFbOnPoaFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_GduFbOnPoaFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_GduFbOnPoaFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_GduFbOnPoaFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_GduFbSvPoa_maximum = 1000 ;
static MWT_UINT PARTAP_PX_GduFbSvPoa_minimum = 1 ;
static MWT_TIME PARTAP_PT_GduFbSvPoa_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_GduFbSvPoa_minimum = 1000 ;
static MWT_UINT PARTAP_PX_GduFbSvOvp_maximum = 1000 ;
static MWT_UINT PARTAP_PX_GduFbSvOvp_minimum = 1 ;
static MWT_TIME PARTAP_PT_GduFbSvOvp_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_GduFbSvOvp_minimum = 1000 ;
static MWT_UINT PARTAP_PX_GduFbSv2qc_maximum = 1000 ;
static MWT_UINT PARTAP_PX_GduFbSv2qc_minimum = 1 ;
static MWT_TIME PARTAP_PT_GduFbSv2qc_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_GduFbSv2qc_minimum = 1000 ;
static MWT_UINT PARTAP_PX_OvUDcLk_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvUDcLk_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvUDcLk_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvUDcLk_minimum = 1000 ;
static MWT_UINT PARTAP_PX_UnUDcLk_maximum = 1000 ;
static MWT_UINT PARTAP_PX_UnUDcLk_minimum = 1 ;
static MWT_TIME PARTAP_PT_UnUDcLk_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_UnUDcLk_minimum = 1000 ;
static MWT_UINT PARTAP_PX_OvIPh_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvIPh_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvIPh_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvIPh_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IPhTmWndFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IPhTmWndFl_minimum = 0 ;
static MWT_TIME PARTAP_PT_IPhTmWndFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IPhTmWndFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IPhClTmOut_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IPhClTmOut_minimum = 1 ;
static MWT_TIME PARTAP_PT_IPhClTmOut_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IPhClTmOut_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IPhClRmsTmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IPhClRmsTmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_IPhClRmsTmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IPhClRmsTmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IPhClTmWnd1Fl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IPhClTmWnd1Fl_minimum = 1 ;
static MWT_TIME PARTAP_PT_IPhClTmWnd1Fl_maximum = 100000000 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1266
static MWT_TIME PARTAP_PT_IPhClTmWnd1Fl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IPhDcFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IPhDcFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_IPhDcFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IPhDcFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IPhBalFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IPhBalFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_IPhBalFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IPhBalFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_CtFbSvFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_CtFbSvFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_CtFbSvFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_CtFbSvFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_AuLdCtFbSvFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_AuLdCtFbSvFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_AuLdCtFbSvFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_AuLdCtFbSvFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_UDcLkChSv_maximum = 1000 ;
static MWT_UINT PARTAP_PX_UDcLkChSv_minimum = 1 ;
static MWT_TIME PARTAP_PT_UDcLkChSv_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_UDcLkChSv_minimum = 1000 ;
static MWT_UINT PARTAP_PX_UDcLkDhSv_maximum = 1000 ;
static MWT_UINT PARTAP_PX_UDcLkDhSv_minimum = 1 ;
static MWT_TIME PARTAP_PT_UDcLkDhSv_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_UDcLkDhSv_minimum = 1000 ;
static MWT_UINT PARTAP_PX_OvpFcTsFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvpFcTsFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvpFcTsFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvpFcTsFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_OvpRsTpFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvpRsTpFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvpRsTpFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvpRsTpFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_SrCtISv_maximum = 1000 ;
static MWT_UINT PARTAP_PX_SrCtISv_minimum = 1 ;
static MWT_TIME PARTAP_PT_SrCtISv_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_SrCtISv_minimum = 1000 ;
static MWT_UINT PARTAP_PX_3PhSzFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_3PhSzFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_3PhSzFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_3PhSzFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_PBalFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_PBalFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_PBalFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_PBalFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_OvUPhInRmsFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvUPhInRmsFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvUPhInRmsFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvUPhInRmsFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_UnUPhInRmsFl_maximum = 2000 ;
static MWT_UINT PARTAP_PX_UnUPhInRmsFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_UnUPhInRmsFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_UnUPhInRmsFl_minimum = 1000 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1267
static MWT_UINT PARTAP_PX_OvIPhIn_2qc_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvIPhIn_2qc_minimum = 0 ;
static MWT_TIME PARTAP_PT_OvIPhIn_2qc_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvIPhIn_2qc_minimum = 1000 ;
static MWT_UINT PARTAP_PX_OvIPhInRms_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvIPhInRms_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvIPhInRms_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvIPhInRms_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IPhInTmWndFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IPhInTmWndFl_minimum = 0 ;
static MWT_TIME PARTAP_PT_IPhInTmWndFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IPhInTmWndFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IDfInErf_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IDfInErf_minimum = 1 ;
static MWT_TIME PARTAP_PT_IDfInErf_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IDfInErf_minimum = 1000 ;
static MWT_UINT PARTAP_PX_OvUBtFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvUBtFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvUBtFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvUBtFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_UnUBtFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_UnUBtFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_UnUBtFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_UnUBtFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_OvIBtCg_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvIBtCg_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvIBtCg_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvIBtCg_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IBtClTmOut_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IBtClTmOut_minimum = 1 ;
static MWT_TIME PARTAP_PT_IBtClTmOut_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IBtClTmOut_minimum = 1000 ;
static MWT_UINT PARTAP_PX_DcCrBrTp_maximum = 1000 ;
static MWT_UINT PARTAP_PX_DcCrBrTp_minimum = 1 ;
static MWT_TIME PARTAP_PT_DcCrBrTp_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_DcCrBrTp_minimum = 1000 ;
static MWT_UINT PARTAP_PX_FnCrFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_FnCrFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_FnCrFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_FnCrFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_HTfSvMax_maximum = 1000 ;
static MWT_UINT PARTAP_PX_HTfSvMax_minimum = 1 ;
static MWT_TIME PARTAP_PT_HTfSvMaxTmWn_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_HTfSvMaxTmWn_minimum = 1000 ;
static MWT_UINT PARTAP_PX_LngTmOvLd_maximum = 1000 ;
static MWT_UINT PARTAP_PX_LngTmOvLd_minimum = 1 ;
static MWT_TIME PARTAP_PT_LngTmOvLd_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_LngTmOvLd_minimum = 1000 ;
static MWT_UINT PARTAP_PX_HBtSvMax_maximum = 1000 ;
static MWT_UINT PARTAP_PX_HBtSvMax_minimum = 1 ;
static MWT_TIME PARTAP_PT_HBtSvMaxTmWn_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_HBtSvMaxTmWn_minimum = 1000 ;
static MWT_UINT PARTAP_PX_HNteArSvMax_maximum = 1000 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1268
static MWT_UINT PARTAP_PX_HNteArSvMax_minimum = 1 ;
static MWT_TIME PARTAP_PT_HNteArSvMaxTmWn_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_HNteArSvMaxTmWn_minimum = 1000 ;
static MWT_UINT PARTAP_PX_HNdSvMax_maximum = 1000 ;
static MWT_UINT PARTAP_PX_HNdSvMax_minimum = 0 ;
static MWT_TIME PARTAP_PT_HNdSvMaxTmWn_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_HNdSvMaxTmWn_minimum = 1000 ;
static MWT_UINT PARTAP_PX_FSgFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_FSgFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_FSgFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_FSgFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_PSpFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_PSpFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_PSpFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_PSpFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_MvbWdgFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_MvbWdgFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_MvbWdgFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_MvbWdgFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_AdcMmFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_AdcMmFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_AdcMmFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_AdcMmFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_DspOvLdFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_DspOvLdFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_DspOvLdFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_DspOvLdFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_Nte15VFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_Nte15VFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_Nte15VFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_Nte15VFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_25MHzSvFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_25MHzSvFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_25MHzSvFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_25MHzSvFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_DspWdAlm_maximum = 1000 ;
static MWT_UINT PARTAP_PX_DspWdAlm_minimum = 1 ;
static MWT_TIME PARTAP_PT_DspWdAlm_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_DspWdAlm_minimum = 1000 ;
static MWT_UINT PARTAP_PX_DspFpgaComFl_maximum = 1000 ;
static MWT_UINT PARTAP_PX_DspFpgaComFl_minimum = 1 ;
static MWT_TIME PARTAP_PT_DspFpgaComFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_DspFpgaComFl_minimum = 1000 ;
static MWT_UINT PARTAP_PX_OvIRct_maximum = 1000 ;
static MWT_UINT PARTAP_PX_OvIRct_minimum = 1 ;
static MWT_TIME PARTAP_PT_OvIRct_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_OvIRct_minimum = 1000 ;
static MWT_UINT PARTAP_PX_IRctBalSv_maximum = 1000 ;
static MWT_UINT PARTAP_PX_IRctBalSv_minimum = 1 ;
static MWT_TIME PARTAP_PT_IRctBalSv_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IRctBalSv_minimum = 1000 ;
static MWT_TIME PARTAP_PT_CvOpMn_maximum = 100000 ;
static MWT_TIME PARTAP_PT_CvOpMn_minimum = 0 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1269
static MWT_TIME PARTAP_PT_SfSdCvSa_maximum = 100000 ;
static MWT_TIME PARTAP_PT_SfSdCvSa_minimum = 0 ;
static MWT_TIME PARTAP_PT_FsSdCvSa_maximum = 100000 ;
static MWT_TIME PARTAP_PT_FsSdCvSa_minimum = 0 ;
static MWT_TIME PARTAP_PT_PrSdCvSa_maximum = 100000 ;
static MWT_TIME PARTAP_PT_PrSdCvSa_minimum = 0 ;
static MWT_UINT PARTAP_PX_NteCoFl_maximum = 10000 ;
static MWT_UINT PARTAP_PX_NteCoFl_minimum = 0 ;
static MWT_TIME PARTAP_PT_NteCoFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_NteCoFl_minimum = 0 ;
static MWT_UINT PARTAP_PX_TpSnFl_maximum = 10000 ;
static MWT_UINT PARTAP_PX_TpSnFl_minimum = 0 ;
static MWT_TIME PARTAP_PT_TpSnFl_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_TpSnFl_minimum = 0 ;
static MWT_TIME PARTAP_PT_AyActMtFn_maximum = 100000 ;
static MWT_TIME PARTAP_PT_AyActMtFn_minimum = 0 ;
static MWT_REAL PARTAP_PV_ExtFnTnHgh_maximum = 100000.0 ;
static MWT_REAL PARTAP_PV_ExtFnTnHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PV_ExtFnTnLow_maximum = 100000.0 ;
static MWT_REAL PARTAP_PV_ExtFnTnLow_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_HtFuSpeOnHgh_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_HtFuSpeOnHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_HtFuSpeOfHgh_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_HtFuSpeOfHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_HtFuSpeOnLow_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_HtFuSpeOnLow_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_HtFuSpeOfLow_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_HtFuSpeOfLow_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_NteArFuSpeOnHgh_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_NteArFuSpeOnHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_NteArFuSpeOfHgh_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_NteArFuSpeOfHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_NteArFuSpeOnLow_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_NteArFuSpeOnLow_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_NteArFuSpeOfLow_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_NteArFuSpeOfLow_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_ExtFnFl_maximum = 100000 ;
static MWT_TIME PARTAP_PT_ExtFnFl_minimum = 0 ;
static MWT_TIME PARTAP_PT_DyHfFuExtFnSpe_maximum = 100000 ;
static MWT_TIME PARTAP_PT_DyHfFuExtFnSpe_minimum = 0 ;
static MWT_TIME PARTAP_PT_DyFuHfExtFnSpe_maximum = 100000 ;
static MWT_TIME PARTAP_PT_DyFuHfExtFnSpe_minimum = 0 ;
static MWT_TIME PARTAP_PT_HfExtFnSpeMn_maximum = 100000 ;
static MWT_TIME PARTAP_PT_HfExtFnSpeMn_minimum = 0 ;
static MWT_REAL PARTAP_PH_BrdFuSpeOfLow_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_BrdFuSpeOfLow_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_BrdFuSpeOnLow_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_BrdFuSpeOnLow_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_BrdFuSpeOfHgh_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_BrdFuSpeOfHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_BrdFuSpeOnHgh_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_BrdFuSpeOnHgh_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_FnOfDy_maximum = 100000 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1270
static MWT_TIME PARTAP_PT_FnOfDy_minimum = 0 ;
static MWT_REAL PARTAP_PH_NteTpDfMax_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_NteTpDfMax_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_NteTpDf_maximum = 100000 ;
static MWT_TIME PARTAP_PT_NteTpDf_minimum = 0 ;
static MWT_REAL PARTAP_PH_HtCoOs_maximum = 100000.0 ;
static MWT_REAL PARTAP_PH_HtCoOs_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_DcuBrdOs_maximum = 1000.0 ;
static MWT_REAL PARTAP_PH_DcuBrdOs_minimum = -1000.0 ;
static MWT_TIME PARTAP_PT_TpSnDy_maximum = 100000 ;
static MWT_TIME PARTAP_PT_TpSnDy_minimum = 0 ;
static MWT_INT PARTAP_PX_IdPrSdPcl_maximum = 1000 ;
static MWT_INT PARTAP_PX_IdPrSdPcl_minimum = 0 ;
static MWT_INT PARTAP_PX_IdFsSdPcl_maximum = 1000 ;
static MWT_INT PARTAP_PX_IdFsSdPcl_minimum = 0 ;
static MWT_INT PARTAP_PX_IdSfSdPcl_maximum = 1000 ;
static MWT_INT PARTAP_PX_IdSfSdPcl_minimum = 0 ;
static MWT_INT PARTAP_PX_IdPrBcPcl_maximum = 1000 ;
static MWT_INT PARTAP_PX_IdPrBcPcl_minimum = 0 ;
static MWT_INT PARTAP_PX_IdClPcl_maximum = 1000 ;
static MWT_INT PARTAP_PX_IdClPcl_minimum = 0 ;
static MWT_INT PARTAP_PX_IdHwPcl_maximum = 1000 ;
static MWT_INT PARTAP_PX_IdHwPcl_minimum = 0 ;
static MWT_INT PARTAP_PX_IdTpPcl_maximum = 1000 ;
static MWT_INT PARTAP_PX_IdTpPcl_minimum = 0 ;
static MWT_REAL PARTAP_PI_BtCpThr_maximum = 1000.0 ;
static MWT_REAL PARTAP_PI_BtCpThr_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_BtCpCurBc_maximum = 10000 ;
static MWT_TIME PARTAP_PT_BtCpCurBc_minimum = 0 ;
static MWT_REAL PARTAP_PT_BtCpSfBc_maximum = 100000.0 ;
static MWT_REAL PARTAP_PT_BtCpSfBc_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_BtCpAvTm_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_BtCpAvTm_minimum = 0 ;
/* limits for system specific parameters of PAR
*/
static MWT_REAL PARTAP_PU_PhInRmsMax_maximum = 3000.0 ;
static MWT_REAL PARTAP_PU_PhInRmsMax_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UPhInRmsMaxDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_UPhInRmsMaxDy_minimum = 0 ;
static MWT_REAL PARTAP_PU_PhInRmsLow_maximum = 3000.0 ;
static MWT_REAL PARTAP_PU_PhInRmsLow_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UPhInRmsLowDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_UPhInRmsLowDy_minimum = 0 ;
static MWT_REAL PARTAP_PU_PhInRmsMin_maximum = 3000.0 ;
static MWT_REAL PARTAP_PU_PhInRmsMin_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UPhInRmsMinDy_maximum = 32000 ;
static MWT_TIME PARTAP_PT_UPhInRmsMinDy_minimum = 0 ;
static MWT_REAL PARTAP_PU_DcLkOpSa_maximum = 5000.0 ;
static MWT_REAL PARTAP_PU_DcLkOpSa_minimum = -100.0 ;
static MWT_TIME PARTAP_PT_DcLkUOpSa_maximum = 10000 ;
static MWT_TIME PARTAP_PT_DcLkUOpSa_minimum = 0 ;
static MWT_REAL PARTAP_PU_DcLkOpSo_maximum = 5000.0 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1271
static MWT_REAL PARTAP_PU_DcLkOpSo_minimum = -100.0 ;
static MWT_TIME PARTAP_PT_DcLkUOpSo_maximum = 100000 ;
static MWT_TIME PARTAP_PT_DcLkUOpSo_minimum = 0 ;
static MWT_REAL PARTAP_PU_DcLkDh_maximum = 5000.0 ;
static MWT_REAL PARTAP_PU_DcLkDh_minimum = -100.0 ;
static MWT_REAL PARTAP_PX_KpF3PhSzCl_maximum = 1000.0 ;
static MWT_REAL PARTAP_PX_KpF3PhSzCl_minimum = 0.0 ;
static MWT_REAL PARTAP_PT_F3PhSzCl_maximum = 1000.0 ;
static MWT_REAL PARTAP_PT_F3PhSzCl_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_DcLkLow_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkLow_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_FRefRmpUp_maximum = 1000.0 ;
static MWT_REAL PARTAP_PX_FRefRmpUp_minimum = 1.0 ;
static MWT_REAL PARTAP_PF_UF3PhSzRdy_maximum = 100.0 ;
static MWT_REAL PARTAP_PF_UF3PhSzRdy_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_UF3PhSzRdy_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_UF3PhSzRdy_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_TrfRtPr3Ph_maximum = 100.0 ;
static MWT_REAL PARTAP_PX_TrfRtPr3Ph_minimum = 0.01 ;
static MWT_REAL PARTAP_PI_BtCgFltHgh_maximum = 1000.0 ;
static MWT_REAL PARTAP_PI_BtCgFltHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_3PhClRefMax_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_3PhClRefMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_U3PhRef3_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_U3PhRef3_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_U3PhRef4_maximum = 2000.0 ;
static MWT_REAL PARTAP_PU_U3PhRef4_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_NomBt_maximum = 200.0 ;
static MWT_REAL PARTAP_PU_NomBt_minimum = 24.0 ;
static MWT_REAL PARTAP_PU_BtRfCg_maximum = 150.0 ;
static MWT_REAL PARTAP_PU_BtRfCg_minimum = 0.0 ;
static MWT_REAL PARTAP_PT_IBtCl_maximum = 100000.0 ;
static MWT_REAL PARTAP_PT_IBtCl_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_HtSvMaxLim_maximum = 5000.0 ;
static MWT_REAL PARTAP_PI_HtSvMaxLim_minimum = 0.0 ;
static MWT_REAL PARTAP_PX_HtSvOvLdLim_maximum = 1.0 ;
static MWT_REAL PARTAP_PX_HtSvOvLdLim_minimum = 0.0 ;
static MWT_REAL PARTAP_PF_3PhNom_maximum = 100.0 ;
static MWT_REAL PARTAP_PF_3PhNom_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_maximum = 0.0 ;
static MWT_REAL PARTAP_PU_UF3PhCmpRctHiLo_minimum = -2000.0 ;
static MWT_REAL PARTAP_PI_BalSvMax_maximum = 100.0 ;
static MWT_REAL PARTAP_PI_BalSvMax_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_DcLkChDy_maximum = 5000 ;
static MWT_TIME PARTAP_PT_DcLkChDy_minimum = 0 ;
static MWT_TIME PARTAP_PT_UF3PhSzRdy_maximum = 30000 ;
static MWT_TIME PARTAP_PT_UF3PhSzRdy_minimum = 0 ;
static MWT_REAL PARTAP_PH_BtSvMax_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_BtSvMax_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_BtSvHgh_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_BtSvHgh_minimum = 0.0 ;
static MWT_REAL PARTAP_PH_BtSvRst_maximum = 250.0 ;
static MWT_REAL PARTAP_PH_BtSvRst_minimum = 0.0 ;
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1272
static MWT_REAL PARTAP_PX_UBtIBtCgRef_maximum = 1.0 ;
static MWT_REAL PARTAP_PX_UBtIBtCgRef_minimum = 0.0 ;
static MWT_REAL PARTAP_PI_BtClLim_maximum = 1000.0 ;
static MWT_REAL PARTAP_PI_BtClLim_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_DcLkHgh2_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkHgh2_minimum = 0.0 ;
static MWT_REAL PARTAP_PU_DcLkHgh1_maximum = 4200.0 ;
static MWT_REAL PARTAP_PU_DcLkHgh1_minimum = 0.0 ;
static MWT_TIME PARTAP_PT_UDcLkHgh1_maximum = 100000 ;
static MWT_TIME PARTAP_PT_UDcLkHgh1_minimum = 0 ;
static MWT_TIME PARTAP_PT_IBtLimHghDy_maximum = 100000000 ;
static MWT_TIME PARTAP_PT_IBtLimHghDy_minimum = 0 ;
/*
Min and max values for dependent parameters are initialized.
Definitions of the parameters themselves are done in the appropriate PARA*P template file. (scale file)
*/
/* PCT parameters of PAR
*/
/* limitation functions
*/
static LIMIT_UNUSED void Limit_MWT_INT(MWT_INT *val, MWT_INT max, MWT_INT min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_REAL(MWT_REAL *val, MWT_REAL max, MWT_REAL min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_TIME(MWT_TIME *val, MWT_TIME max, MWT_TIME min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_BYTE(MWT_BYTE *val, MWT_BYTE max, MWT_BYTE min, MWT_BOOL *limited){
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1273
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_SINT(MWT_SINT *val, MWT_SINT max, MWT_SINT min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_WORD(MWT_WORD *val, MWT_WORD max, MWT_WORD min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_DWORD(MWT_DWORD *val, MWT_DWORD max, MWT_DWORD min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_ANALOG(MWT_ANALOG *val, MWT_ANALOG max, MWT_ANALOG min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_UINT(MWT_UINT *val, MWT_UINT max, MWT_UINT min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 1274
static LIMIT_UNUSED void Limit_MWT_DINT(MWT_DINT *val, MWT_DINT max, MWT_DINT min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_UDINT(MWT_UDINT *val, MWT_UDINT max, MWT_UDINT min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
static LIMIT_UNUSED void Limit_MWT_USINT(MWT_USINT *val, MWT_USINT max, MWT_USINT min, MWT_BOOL *limited){
if(*val>max){
*val = max;
*limited = TRUE;
}else if(*val<min){
*val = min;
*limited = TRUE;
}else{*limited = FALSE;}
}
#endif /* PARA_ILIM_H */

