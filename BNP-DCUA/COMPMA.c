/*(*COMPMA - Voltage and frequency compounding*)
(*The 3-phase output load voltage reference is adjusted
as a function of the reactive phase current.
The output frequency reference is adjusted as a
function of the active phase current.*)*/

struct UF3PhCmp
{
	XI_PhAct;
	XI_PhRct;
	A_CvOp;
	L_EnUF3PhCmp;
	PI_UF3PhCmpActHiLo;//4000 page1128  [0.0,5000.0] page1259
	PF_UF3PhCmpActHiLo;//-10 page1128   [-100.0,0.0]
	PI_UF3PhCmpRctHiLo;//4000 page1128  [0.0,5000.0] page1259
	PU_UF3PhCmpRctHiLo;//-200 page1142 [-2000.0,0.0] page1272  /* initial value: 3-phase output load voltage breakpoint, phase-neutral, peak value */

	WF_UF3PhCmp;
	WU_UF3PhCmp;
};
