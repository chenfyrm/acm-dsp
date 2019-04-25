//(*HSTIMA - Host interface signals from DSP to MCU*)
//29-45
XU_DcLk;/*DC-link voltage*/
XU_3PhPek;/*3-phase output load voltage, phase-phase, peak value*/
XI_PhPek;/*Phase current, peak value*/
XI_PhAct;/*Active phase current*/
XI_PhRct;/*Reactive phase current*/
//XI_BtCg;/*Battery charger current*/
//XI_Bt;/*Battery current*/
//XU_PhInRms;/*AC input phase voltage RMS value*/
//XI_PhInRms;/*AC input phase current RMS value*/
WU_IPhClTrs;/*3-phase output load voltage reference manipulation,transient phase current control*/
//WU_IBtCgCl;/*3-Phase output load voltage manipulation from battery charger current control*/
WU_OvMd;/*3-phase output load voltage manipulation due to over modulation*/
WU_IPhClRms;/*3-phase output load voltage manipulation,RMS phase current limitation*/
//XU_Bt;/*Battery voltage*/
XI_Ph1Rms;/*Phase current 1, RMS value*/
XI_Ph2Rms;/*Phase current 2, RMS value*/
XI_Ph3Rms;/*Phase current 3, RMS value*/
XU_3PhRms;/*3-phase output load voltage, phase-phase, RMS value*/
XU_3PhRe;/*3-phase output load voltage, phase-phase, real part*/
XU_3PhIm;/*3-phase output load voltage, phase-phase, imaginary part*/
XT_U3Ph;/*Period time of measured 3-phase output load voltage*/
XI_PhReFix;/*Phase current, real part of fix projection*/
XI_PhImFix;/*Phase current, imaginary part of fix projection*/
//XP_2qc;/*2QC input power*/
XP_3Ph;/*3-phase output power*/
XP_Ovp;/*OVP power*/
XX_AI24;/*AI 24 analogue input channel*/
XX_AI29;/*AI 29 analogue input channel*/
XQ_3Ph;/*3-phase output reactive power*/
//XI_DflnFlt;/*Filtered differential input current (2QC)*/
WU_Flt;/*Filtered voltage reference*/
//XU_DcLk2;/*DC-link voltage 2*/
XH_Ovp_Est;/*Estimated OVP temperature*/
//XI_Rct1_Rms;/*Rectifier current 1 RMS value*/
XI_BtCp;
//XI_Rct2_Rms;/*Rectifier current 2 RMS value*/
//XI_Rct3_Rms;/*Rectifier current 3 RMS value*/
//XI_BtCgEst;/*Estimated battery charger current(BtCp operation)*/
//XU_3Ph2Rms;/*(*3-phase output load voltage 2, phase-phase, RMS value*/
//XU_3Ph2Pek;/*(*3-phase output load voltage, phase-phase, peak value*/

//
Z_PrSd;
Z_PrSd_PmFl;
Z_FsSd;
Z_FsSd_PmFl;
Z_SfSd;
Z_SfSd_PmFl;
Z_PrBc;
Z_PrBc_PmFl;
Z_BtCpPrBc;
Z_BtCpPrBc_PmFl;
Z_CalFl;
Z_Dsp122;

//Z_Fpga203;
//Z_Fpga205;
//Z_Fpga208;
//Z_Fpga210;
//Z_Fpga211;

B_DspOvLdFl;/*DSP overload failure*/
S_DspWdAlm;/*(*Status DSP Watchdog alarm*/
