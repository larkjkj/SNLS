extern void snADC_const(sn_CPU* cpuIndex);

extern void snAND_const(sn_CPU* cpuIndex);
extern void snAND_addr(sn_CPU* cpuIndex);

extern void snASL_dp(sn_CPU* cpuIndex);
extern void snASL_acc(sn_CPU* cpuIndex);
extern void snASL_addr(sn_CPU* cpuIndex);
extern void snASL_dpX(sn_CPU* cpuIndex);
extern void snASL_addrX(sn_CPU* cpuIndex);

extern void snCLC(sn_CPU* cpuIndex);
extern void snCLD(sn_CPU* cpuIndex);
extern void snCLI(sn_CPU* cpuIndex);
extern void snCLV(sn_CPU* cpuIndex);

extern void snCMP_dpIX(sn_CPU* cpuIndex);
extern void snCMP_srS(sn_CPU* cpuIndex);
extern void snCMP_dp(sn_CPU* cpuIndex);
extern void snCMP_dpI_long(sn_CPU* cpuIndex);
extern void snCMP_const(sn_CPU* cpuIndex);
extern void snCMP_addr(sn_CPU* cpuIndex);
extern void snCMP_long(sn_CPU* cpuIndex);
extern void snCMP_dpIY(sn_CPU* cpuIndex);
extern void snCMP_dpI(sn_CPU* cpuIndex);
extern void snCMP_srSIY(sn_CPU* cpuIndex);
extern void snCMP_dpX(sn_CPU* cpuIndex);
extern void snCMP_dpI_longY(sn_CPU* cpuIndex);
extern void snCMP_addrY(sn_CPU* cpuIndex);
extern void snCMP_addrX(sn_CPU* cpuIndex);
extern void snCMP_longX(sn_CPU* cpuIndex);
extern void snCMP_dpX(sn_CPU* cpuIndex);

extern void snDEC_Acc(sn_CPU* cpuIndex);
extern void snDEC_dp(sn_CPU* cpuIndex);
extern void snDEC_addr(sn_CPU* cpuIndex);
extern void snDEC_dpX(sn_CPU* cpuIndex);
extern void snDEC_addrX(sn_CPU* cpuIndex);
extern void snDEX(sn_CPU* cpuIndex);
extern void snDEY(sn_CPU* cpuIndex);

extern void snLDA_dp(sn_CPU* cpuIndex);
extern void snLDA_const(sn_CPU* cpuIndex);
extern void snLDA_addr(sn_CPU* cpuIndex);

extern void snSEC(sn_CPU* cpuIndex);
extern void snSED(sn_CPU* cpuIndex);
extern void snSEI(sn_CPU* cpuIndex);
extern void snSEP(sn_CPU* cpuIndex);

extern void snSTA_addr(sn_CPU* cpuIndex);

extern void snSTZ_dp(sn_CPU* cpuIndex);
extern void snSTZ_addr(sn_CPU* cpuIndex);

extern void snTCD(sn_CPU* cpuIndex);

extern void snWAI(sn_CPU* cpuIndex);
