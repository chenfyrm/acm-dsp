//(*HSTOMA - Host interface signals from MCU to DSP*)
//21-24
WU_3PhDsp;
WF_3PhDsp;
WI_PhActDsp;
WI_PhRctDsp;

//27-34
XX_IPhClTrsKpActDsp;
XX_IPhClTrsKpRctDsp;
XX_IPhClTrsKpAbsDsp;/**/
WI_BtCgLim;/*Battery charger current limit*/
WU_3PhReDsp;/*Voltage reference from PCT,real part,to the DSP*/
WU_3PhImDsp;/*Voltage reference from PCT,imaginary part,to the DSP*/
WI_PctParSelTrp;/*Phase overcurrent trip level in PCT*/
XX_DdCmpFa;/*Dead time compensation factor*/

//35
//(*Digital signals from MCU to DSP, word 3*)

//40
//(*Digital signals from MCU to DSP, word 1*)

//41-45
Z_PrSd;
Z_FsSd;
Z_SfSd;
Z_PrBc;
Z_BtCpPrBc;

//50
//(*Digital signals from MCU to DSP, word 2*)

//60
Z_Fpga203;

//61
//(*Reset word from FPGA, 204 *)

//62-64
Z_Fpga205;
Z_Fpga206;
WU_BtDsp; /*Battery voltage reference to DSP for BtCp control*/








