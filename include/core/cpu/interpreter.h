#ifndef SNLS_INTERPRETER_HEADER
#define SNLS_INTERPRETER_HEADER
/*extern void snADC_dp(emGeneral* emulator);
extern void snADC_const(emGeneral* emulator);
extern void snADC_addr(emGeneral* emulator);
extern void snADC_long(emGeneral* emulator, rom* rom_Ptr){};
extern void snADC_addrY(emGeneral* emulator);
extern void snADC_addrX(emGeneral* emulator);
extern void snADC_longX(emGeneral* emulator, rom* rom_Ptr){};

extern void snAND_const(emGeneral* emulator);
extern void snAND_addr(emGeneral* emulator);
extern void snAND_long(emGeneral* emulator, rom* rom_Ptr){};
extern void snAND_addrX(emGeneral* emulator);

extern void snASL_dp(emGeneral* emulator);
extern void snASL_Acc(emGeneral* emulator);
extern void snASL_addr(emGeneral* emulator);
extern void snASL_dpX(emGeneral* emulator);
extern void snASL_addrX(emGeneral* emulator);

extern void snBCC(emGeneral* emulator);
extern void snBCS(emGeneral* emulator);
extern void snBEQ(emGeneral* emulator);

extern void snBIT_addr(emGeneral* emulator);

extern void snBRA(emGeneral* emulator);
extern void snBPL(emGeneral* emulator);

extern void snCLC(emGeneral* emulator);
extern void snCLD(emGeneral* emulator);
extern void snCLI(emGeneral* emulator);
extern void snCLV(emGeneral* emulator);

extern void snCMP_dpIX(emGeneral* emulator);
extern void snCMP_srS(emGeneral* emulator);
extern void snCMP_dp(emGeneral* emulator);
extern void snCMP_dpI_long(emGeneral* emulator){};
extern void snCMP_const(emGeneral* emulator);
extern void snCMP_addr(emGeneral* emulator);
extern void snCMP_long(emGeneral* emulator, rom* rom_Ptr){};
extern void snCMP_dpIY(emGeneral* emulator);
extern void snCMP_dpI(emGeneral* emulator);
extern void snCMP_srSIY(emGeneral* emulator);
extern void snCMP_dpX(emGeneral* emulator);
extern void snCMP_dpI_longY(emGeneral* emulator);
extern void snCMP_addrY(emGeneral* emulator);
extern void snCMP_addrX(emGeneral* emulator);
extern void snCMP_longX(emGeneral* emulator, rom* rom_Ptr){};

extern void snDEC_Acc(emGeneral* emulator);
extern void snDEC_dp(emGeneral* emulator);
extern void snDEC_addr(emGeneral* emulator);
extern void snDEC_dpX(emGeneral* emulator);
extern void snDEC_addrX(emGeneral* emulator);
extern void snDEX(emGeneral* emulator);
extern void snDEY(emGeneral* emulator);

extern void snLDA_dp(emGeneral* emulator);
extern void snLDA_const(emGeneral* emulator);
extern void snLDA_addr(emGeneral* emulator);
extern void snLDA_long(emGeneral* emulator, rom* rom_Ptr){};

extern void snLDA_dpX(emGeneral* emulator);
extern void snLDA_addrY(emGeneral* emulator);
extern void snLDA_addrX(emGeneral* emulator);
extern void snLDA_longX(emGeneral* emulator, rom* rom_Ptr){};

extern void snLDX_const(emGeneral* emulator);
extern void snLDX_dp(emGeneral* emulator);
extern void snLDX_addr(emGeneral* emulator);
extern void snLDX_dpY(emGeneral* emulator);
extern void snLDX_addrY(emGeneral* emulator);


extern void snINC_Acc(emGeneral* emulator);
extern void snINC_dp(emGeneral* emulator);
extern void snINC_addr(emGeneral* emulator);
extern void snINC_dpX(emGeneral* emulator);
extern void snINC_addrX(emGeneral* emulator);

extern void snINX(emGeneral* emulator);
extern void snINY(emGeneral* emulator);

extern void snJMP_addr(emGeneral* emulator);
extern void snJMP_long(emGeneral* emulator);

extern void snJSR_addr(emGeneral* emulator);
extern void snJSR_long(emGeneral* emulator, rom* rom_Ptr);
extern void snJSR_addrXI(emGeneral* emulator);

extern void snORA_addr(emGeneral* emulator);
extern void snORA_long(emGeneral* emulator, rom* rom_Ptr){};
extern void snORA_const(emGeneral* emulator);
extern void snORA_addrY(emGeneral* emulator);
extern void snORA_addrX(emGeneral* emulator);
extern void snORA_longX(emGeneral* emulator, rom* rom_Ptr){};

extern void snREP_const(emGeneral* emulator);

extern void snSEC(emGeneral* emulator);
extern void snSED(emGeneral* emulator);
extern void snSEI(emGeneral* emulator);
extern void snSEP(emGeneral* emulator);

extern void snSTA_dp(emGeneral* emulator);
extern void snSTA_addr(emGeneral* emulator);
extern void snSTA_addrY(emGeneral* emulator);
extern void snSTA_addrX(emGeneral* emulator);
extern void snSTA_long(emGeneral* emulator);
extern void snSTA_longX(emGeneral* emulator);

extern void snSTY_addr(emGeneral* emulator);
extern void snSTY_dp(emGeneral* emulator);
extern void snSTY_dpX(emGeneral* emulator);

extern void snSTZ_dp(emGeneral* emulator);
extern void snSTZ_dpX(emGeneral* emulator);
extern void snSTZ_addr(emGeneral* emulator);
extern void snSTZ_addrX(emGeneral* emulator);

extern void snTAX(emGeneral* emulator);
extern void snTAY(emGeneral* emulator);
extern void snTCD(emGeneral* emulator);
extern void snTDC(emGeneral* emulator);

extern void snTSB_addr(emGeneral* emulator);

extern void snTXA(emGeneral* emulator);
extern void snTXY(emGeneral* emulator);
extern void snTYA(emGeneral* emulator);
extern void snTYX(emGeneral* emulator);

extern void snWAI(emGeneral* emulator);
extern void snXCE(emGeneral* emulator);
*/

#include "emulator/general.h"

extern void sn_OpBMI(emGeneral* emulator);
extern void sn_OpBPL(emGeneral* emulator);
extern void sn_OpBRA(emGeneral* emulator);

extern void sn_OpCLC(emGeneral* emulator);
extern void sn_OpCLD(emGeneral* emulator);
extern void sn_OpCLI(emGeneral* emulator);
extern void sn_OpCLV(emGeneral* emulator);

extern void sn_OpJMP_addr(emGeneral* emulator);
extern void sn_OpJSR_addr(emGeneral* emulator);

extern void sn_OpLDA_const(emGeneral* emulator);
extern void sn_OpLDX_const(emGeneral* emulator);
extern void sn_OpLDY_const(emGeneral* emulator);
extern void sn_OpLDY_addr(emGeneral* emulator);

extern void sn_OpDEA(emGeneral* emulator);
extern void sn_OpDEX(emGeneral* emulator);
extern void sn_OpDEY(emGeneral* emulator);


extern void sn_OpINA(emGeneral* emulator);
extern void sn_OpINC_dp(emGeneral* emulator);
extern void sn_OpINC_addr(emGeneral* emulator);
extern void sn_OpINC_dpX(emGeneral* emulator);
extern void sn_OpINC_addrX(emGeneral* emulator);
extern void sn_OpINX(emGeneral* emulator);
extern void sn_OpINY(emGeneral* emulator);

extern void sn_OpSEC(emGeneral* emulator);
extern void sn_OpSED(emGeneral* emulator);
extern void sn_OpSEI(emGeneral* emulator);

extern void sn_OpSBC_const(emGeneral* emulator);

extern void sn_OpREP(emGeneral* emulator);
extern void sn_OpSEP(emGeneral* emulator);

extern void sn_OpSTA_addr(emGeneral* emulator);
extern void sn_OpSTA_long(emGeneral *emulator);
extern void sn_OpSTA_longX(emGeneral* emulator);

extern void sn_OpSTZ_dp(emGeneral* emulator);
extern void sn_OpSTZ_dpX(emGeneral* emulator);
extern void sn_OpSTZ_addr(emGeneral* emulator);
extern void sn_OpSTZ_addrX(emGeneral* emulator);

extern void sn_OpTAX(emGeneral* emulator);
extern void sn_OpTAY(emGeneral* emulator);
extern void sn_OpTCD(emGeneral* emulator);
extern void sn_OpTXY(emGeneral* emulator);
extern void sn_OpTYA(emGeneral* emulator);
extern void sn_OpTYX(emGeneral* emulator);

extern void sn_OpXCE(emGeneral* emulator);
#endif

