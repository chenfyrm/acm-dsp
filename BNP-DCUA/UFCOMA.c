/*(*UFCOMA - 3-phase output load voltage and output frequency control*)
(*Output frequency reference and 3-phase output load voltage reference
and 3-phase output load voltage control*)*/

struct F3PhRef{
	WF_3PhRmp;
	WF_UF3PhCmp;
	WF_UF3PhSz;
	WF_IPhCl;

	WF_3PhDsp; /*(*Output frequency reference*)*/
	WF_3PhU3PhRef; /*(*Output frequency reference to U/f-ratio*)*/
};

struct U3PhRef{
	WU_3PhExt;
	WF_3PhU3PhRef;
	A_CvOp;
	PF_U3PhRef2;
	PF_U3PhRef3;
	PU_U3PhRef1;
	PU_U3PhRef2;
	PU_U3PhRef3;
	PU_U3PhRef4;
	L_ExtU3PhRef;
	PX_ExtU3PhRefRmp;
	L_EnRmpU3PhRef;
	PX_U3PhRefRmpSel;
	PX_U3PhRefRmp1;
	PX_U3PhRefRmp1;

	WU_3PhCl;
};
