extern void snADC_dp(sn_CPU* cpuIndex);
extern void snADC_const(sn_CPU* cpuIndex);
extern void snADC_addr(sn_CPU* cpuIndex);
extern void snADC_long(sn_CPU* cpuIndex, rom* rom_Ptr){};
extern void snADC_addrY(sn_CPU* cpuIndex);
extern void snADC_addrX(sn_CPU* cpuIndex);
extern void snADC_longX(sn_CPU* cpuIndex, rom* rom_Ptr){};

extern void snAND_const(sn_CPU* cpuIndex);
extern void snAND_addr(sn_CPU* cpuIndex);
extern void snAND_long(sn_CPU* cpuIndex, rom* rom_Ptr){};
extern void snAND_addrX(sn_CPU* cpuIndex);

extern void snASL_dp(sn_CPU* cpuIndex);
extern void snASL_Acc(sn_CPU* cpuIndex);
extern void snASL_addr(sn_CPU* cpuIndex);
extern void snASL_dpX(sn_CPU* cpuIndex);
extern void snASL_addrX(sn_CPU* cpuIndex);

extern void snBCC(sn_CPU* cpuIndex);
extern void snBCS(sn_CPU* cpuIndex);
extern void snBEQ(sn_CPU* cpuIndex);

extern void snBIT_addr(sn_CPU* cpuIndex);

extern void snBRA(sn_CPU* cpuIndex);

extern void snCLC(sn_CPU* cpuIndex);
extern void snCLD(sn_CPU* cpuIndex);
extern void snCLI(sn_CPU* cpuIndex);
extern void snCLV(sn_CPU* cpuIndex);

extern void snCMP_dpIX(sn_CPU* cpuIndex);
extern void snCMP_srS(sn_CPU* cpuIndex);
extern void snCMP_dp(sn_CPU* cpuIndex);
extern void snCMP_dpI_long(sn_CPU* cpuIndex){};
extern void snCMP_const(sn_CPU* cpuIndex);
extern void snCMP_addr(sn_CPU* cpuIndex);
extern void snCMP_long(sn_CPU* cpuIndex, rom* rom_Ptr){};
extern void snCMP_dpIY(sn_CPU* cpuIndex);
extern void snCMP_dpI(sn_CPU* cpuIndex);
extern void snCMP_srSIY(sn_CPU* cpuIndex);
extern void snCMP_dpX(sn_CPU* cpuIndex);
extern void snCMP_dpI_longY(sn_CPU* cpuIndex);
extern void snCMP_addrY(sn_CPU* cpuIndex);
extern void snCMP_addrX(sn_CPU* cpuIndex);
extern void snCMP_longX(sn_CPU* cpuIndex, rom* rom_Ptr){};

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
extern void snLDA_long(sn_CPU* cpuIndex, rom* rom_Ptr){};

extern void snLDA_dpX(sn_CPU* cpuIndex);
extern void snLDA_addrY(sn_CPU* cpuIndex);
extern void snLDA_addrX(sn_CPU* cpuIndex);
extern void snLDA_longX(sn_CPU* cpuIndex, rom* rom_Ptr){};

extern void snLDX_const(sn_CPU* cpuIndex);
extern void snLDX_dp(sn_CPU* cpuIndex);
extern void snLDX_addr(sn_CPU* cpuIndex);
extern void snLDX_dpY(sn_CPU* cpuIndex);
extern void snLDX_addrY(sn_CPU* cpuIndex);

extern void snINC_Acc(sn_CPU* cpuIndex);
extern void snINC_dp(sn_CPU* cpuIndex);
extern void snINC_addr(sn_CPU* cpuIndex);
extern void snINC_dpX(sn_CPU* cpuIndex);
extern void snINC_addrX(sn_CPU* cpuIndex);

extern void snINX(sn_CPU* cpuIndex);
extern void snINY(sn_CPU* cpuIndex);

extern void snJMP_addr(sn_CPU* cpuIndex);
extern void snJMP_long(sn_CPU* cpuIndex, rom* rom_Ptr){};

extern void snJSR_addr(sn_CPU* cpuIndex);
extern void snJSR_long(sn_CPU* cpuIndex, rom* rom_Ptr);
extern void snJSR_addrXI(sn_CPU* cpuIndex);

extern void snORA_addr(sn_CPU* cpuIndex);
extern void snORA_long(sn_CPU* cpuIndex, rom* rom_Ptr){};
extern void snORA_const(sn_CPU* cpuIndex);
extern void snORA_addrY(sn_CPU* cpuIndex);
extern void snORA_addrX(sn_CPU* cpuIndex);
extern void snORA_longX(sn_CPU* cpuIndex, rom* rom_Ptr){};

extern void snREP_const(sn_CPU* cpuIndex);

extern void snSEC(sn_CPU* cpuIndex);
extern void snSED(sn_CPU* cpuIndex);
extern void snSEI(sn_CPU* cpuIndex);
extern void snSEP(sn_CPU* cpuIndex);

extern void snSTA_dp(sn_CPU* cpuIndex);
extern void snSTA_addr(sn_CPU* cpuIndex);
extern void snSTA_long(sn_CPU* cpuIndex, rom* rom_Ptr){};

extern void snSTY_addr(sn_CPU* cpuIndex);
extern void snSTY_dp(sn_CPU* cpuIndex);
extern void snSTY_dpX(sn_CPU* cpuIndex);

extern void snSTZ_dp(sn_CPU* cpuIndex);
extern void snSTZ_dpX(sn_CPU* cpuIndex);
extern void snSTZ_addr(sn_CPU* cpuIndex);
extern void snSTZ_addrX(sn_CPU* cpuIndex);

extern void snTAX(sn_CPU* cpuIndex);
extern void snTAY(sn_CPU* cpuIndex);
extern void snTCD(sn_CPU* cpuIndex);
extern void snTDC(sn_CPU* cpuIndex);
extern void snTXA(sn_CPU* cpuIndex);
extern void snTXY(sn_CPU* cpuIndex);
extern void snTYA(sn_CPU* cpuIndex);
extern void snTYX(sn_CPU* cpuIndex);

extern void snWAI(sn_CPU* cpuIndex);
extern void snXCE(sn_CPU* cpuIndex);
