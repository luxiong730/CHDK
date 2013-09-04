/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S
#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 300  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF07706C - 0xFF07736C, length=193
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    LDR     R4, =0x3A468 \n"
"    LDR     R7, =0x3524 \n"
"    MOV     R6, #0 \n"

"loc_FF07707C:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_004372A4 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0770A8 \n"
"    LDR     R1, =0x491 \n"
"    LDR     R0, =0xFF076A68 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R9,PC} \n"

"loc_FF0770A8:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x24 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF077334 \n"
"    B       loc_FF07714C \n"
"    B       loc_FF077164 \n"
"    B       loc_FF0771C8 \n"
"    B       loc_FF0771DC \n"
"    B       loc_FF0771D4 \n"
"    B       loc_FF0771E8 \n"
"    B       loc_FF0771F0 \n"
"    B       loc_FF0771F8 \n"
"    B       loc_FF077214 \n"
"    B       loc_FF077240 \n"
"    B       loc_FF077220 \n"
"    B       loc_FF07722C \n"
"    B       loc_FF077234 \n"
"    B       loc_FF077248 \n"
"    B       loc_FF077250 \n"
"    B       loc_FF077258 \n"
"    B       loc_FF077260 \n"
"    B       loc_FF077268 \n"
"    B       loc_FF077270 \n"
"    B       loc_FF077278 \n"
"    B       loc_FF077280 \n"
"    B       loc_FF077288 \n"
"    B       loc_FF077290 \n"
"    B       loc_FF07729C \n"
"    B       loc_FF0772A4 \n"
"    B       loc_FF0772B0 \n"
"    B       loc_FF0772B8 \n"
"    B       loc_FF0772C0 \n"
"    B       loc_FF0772C8 \n"
"    B       loc_FF0772D0 \n"
"    B       loc_FF0772D8 \n"
"    B       loc_FF0772E0 \n"
"    B       loc_FF0772EC \n"
"    B       loc_FF0772F4 \n"
"    B       loc_FF077300 \n"
"    B       loc_FF077340 \n"

"loc_FF07714C:\n"
"    BL      shooting_expo_iso_override\n"      // added
"    BL      sub_FF077818 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF074B88 \n"
"    MOV     R0, #0\n"                          // added
"    STR     R0, [R4,#0x28]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
//"  LDR     R0, [R4, #0x28] \n"  // above patch makes these three lines redundant
//"  CMP     R0, #0 \n"
//"  BLNE    _sub_FF18EE40 \n"
"    B       loc_FF077340 \n"

"loc_FF077164:\n"
"    LDR     R5, [R0, #0x10] \n"
"    LDR     R0, [R4, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF0771A0 \n"
"    BL      sub_FF078938 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF078990 \n"
"    LDR     R0, =0x10F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x24 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x28 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"

"loc_FF0771A0:\n"
"    MOV     R0, R5 \n"
"    BL      sub_FF18ED84_my \n"  // --> Patched. Old value = 0xFF18ED84.
"    BL      capt_seq_hook_raw_here \n"         // added
"    MOV     R8, R0 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF075054 \n"
"    TST     R8, #1 \n"
"    MOVEQ   R0, R5 \n"
"    BLEQ    sub_FF18E6E4 \n"
"    B       loc_FF077340 \n"

"loc_FF0771C8:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF077B20 \n"
"    B       loc_FF077340 \n"

"loc_FF0771D4:\n"
"    BL      sub_FF077524 \n"
"    B       loc_FF0771E0 \n"

"loc_FF0771DC:\n"
"    BL      sub_FF0777F8 \n"

"loc_FF0771E0:\n"
"    STR     R6, [R4, #0x28] \n"
"    B       loc_FF077340 \n"

"loc_FF0771E8:\n"
"    BL      sub_FF077800 \n"
"    B       loc_FF077340 \n"

"loc_FF0771F0:\n"
"    BL      sub_FF0779FC \n"
"    B       loc_FF077218 \n"

"loc_FF0771F8:\n"
"    LDR     R5, [R0, #0x10] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF18EED8 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #9 \n"
"    BL      sub_FF075054 \n"
"    B       loc_FF077340 \n"

"loc_FF077214:\n"
"    BL      sub_FF077A8C \n"

"loc_FF077218:\n"
"    BL      sub_FF074B88 \n"
"    B       loc_FF077340 \n"

"loc_FF077220:\n"
"    LDR     R0, [R4, #0x58] \n"
"    BL      sub_FF07816C \n"
"    B       loc_FF077340 \n"

"loc_FF07722C:\n"
"    BL      sub_FF0785B4 \n"
"    B       loc_FF077340 \n"

"loc_FF077234:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF078618 \n"
"    B       loc_FF077340 \n"

"loc_FF077240:\n"
"    BL      sub_FF0777F8 \n"
"    B       loc_FF077340 \n"

"loc_FF077248:\n"
"    BL      sub_FF18D9A8 \n"
"    B       loc_FF077340 \n"

"loc_FF077250:\n"
"    BL      sub_FF18DBD4 \n"
"    B       loc_FF077340 \n"

"loc_FF077258:\n"
"    BL      sub_FF18DC8C \n"
"    B       loc_FF077340 \n"

"loc_FF077260:\n"
"    BL      sub_FF18DD40 \n"
"    B       loc_FF077340 \n"

"loc_FF077268:\n"
"    BL      sub_FF18DE18 \n"
"    B       loc_FF077340 \n"

"loc_FF077270:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF077294 \n"

"loc_FF077278:\n"
"    BL      sub_FF18E238 \n"
"    B       loc_FF077340 \n"

"loc_FF077280:\n"
"    BL      sub_FF18E2CC \n"
"    B       loc_FF077340 \n"

"loc_FF077288:\n"
"    BL      sub_FF18E374 \n"
"    B       loc_FF077340 \n"

"loc_FF077290:\n"
"    MOV     R0, #1 \n"

"loc_FF077294:\n"
"    BL      sub_FF18E0D4 \n"
"    B       loc_FF077340 \n"

"loc_FF07729C:\n"
"    BL      sub_FF077CB8 \n"
"    B       loc_FF077340 \n"

"loc_FF0772A4:\n"
"    BL      sub_FF077D3C \n"
"    BL      sub_FF18FB08 \n"
"    B       loc_FF077340 \n"

"loc_FF0772B0:\n"
"    BL      sub_FF18DFA8 \n"
"    B       loc_FF077340 \n"

"loc_FF0772B8:\n"
"    BL      sub_FF18E040 \n"
"    B       loc_FF077340 \n"

"loc_FF0772C0:\n"
"    BL      sub_FF18FBBC \n"
"    B       loc_FF077340 \n"

"loc_FF0772C8:\n"
"    BL      sub_FF01CAB0 \n"
"    B       loc_FF077340 \n"

"loc_FF0772D0:\n"
"    BL      sub_FF079E34 \n"
"    B       loc_FF077340 \n"

"loc_FF0772D8:\n"
"    BL      sub_FF079F20 \n"
"    B       loc_FF077340 \n"

"loc_FF0772E0:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF18E47C \n"
"    B       loc_FF077340 \n"

"loc_FF0772EC:\n"
"    BL      sub_FF18E4EC \n"
"    B       loc_FF077340 \n"

"loc_FF0772F4:\n"
"    BL      sub_FF07A0AC \n"
"    BL      sub_FF079F78 \n"
"    B       loc_FF077340 \n"

"loc_FF077300:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF18F61C \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF18F744 \n"
"    LDRH    R0, [R4, #0xA4] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R4] \n"
"    SUBNE   R1, R0, #0x8200 \n"
"    SUBNES  R1, R1, #0x2E \n"
"    BNE     loc_FF077340 \n"
"    BL      sub_FF079F20 \n"
"    BL      sub_FF07A51C \n"
"    B       loc_FF077340 \n"

"loc_FF077334:\n"
"    LDR     R1, =0x5F2 \n"
"    LDR     R0, =0xFF076A68 \n"
"    BL      _DebugAssert \n"

"loc_FF077340:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_0043ACF8 /*_SetEventFlag*/ \n"
"    LDR     R5, [SP] \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x117 \n"
"    LDREQ   R0, =0xFF076A68 \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R5, #8] \n"
"    B       loc_FF07707C \n"
);
}

/*************************************************************/
//** sub_FF18ED84_my @ 0xFF18ED84 - 0xFF18EE3C, length=47
void __attribute__((naked,noinline)) sub_FF18ED84_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x3A468 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R5, #0x28] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF18EDB4 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF07C718 \n"
"    TST     R0, #1 \n"
"    MOVNE   R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"

"loc_FF18EDB4:\n"
"    MOV     R0, R6 \n"
"    BL      sub_FF18FC30 \n"
"    BL      sub_FF077808 \n"
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF18EE24 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF18E5DC \n"
"    TST     R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF18EA2C \n"
"    BL      sub_FF18F3FC \n"
"    LDRH    R0, [R5, #0xA2] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R6, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #4 \n"
"    BLLS    sub_FF0FDF98 \n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    MOV     R0, #2 \n"
"    BL      sub_FF07DE40 \n"
"    LDR     R0, [R5, #0x94] \n"
"    TST     R0, #0x10 \n"
"    BNE     loc_FF18EE34 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF2DC3F0 \n"
"    MOV     R4, R0 \n"
"    B       loc_FF18EE38 \n"

"loc_FF18EE24:\n"
"    LDR     R0, =0x7C48 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF18EE38 \n"

"loc_FF18EE34:\n"
"    MOV     R4, #0x1D \n"

"loc_FF18EE38:\n"
"    MOV     R0, R4 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF0B5B1C - 0xFF0B61AC, length=421
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x4934 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x578E0 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF0B5B3C:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_004372A4 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF0B5B88 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF0B5CE8 \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF0B5C70 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0B5ACC \n"

"loc_FF0B5B88:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF0B5BB4 \n"
"    BL      sub_FF0B7048 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_0043ACF8 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF0B5BB4:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF0B5BD0 \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF0B61A4 \n"

"loc_FF0B5BD0:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF0B5C20 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0043AD2C /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0B1378 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF17BC00 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0043AC38 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1635 \n"
"    BNE     loc_FF0B5CDC \n"

"loc_FF0B5C0C:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF0B61A4 \n"

"loc_FF0B5C20:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF0B5C68 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF0B5ACC \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0043AD2C /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0B1388 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF17C9B4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0043AC38 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0B5C0C \n"
"    LDR     R1, =0x163F \n"
"    B       loc_FF0B5CDC \n"

"loc_FF0B5C68:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF0B5C80 \n"

"loc_FF0B5C70:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF0B5ACC \n"
"    B       loc_FF0B5C0C \n"

"loc_FF0B5C80:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF0B5C98 \n"
"    BL      sub_FF0A1A60 \n"
"    BL      sub_FF0A2850 \n"
"    BL      sub_FF0A2360 \n"
"    B       loc_FF0B5C0C \n"

"loc_FF0B5C98:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF0B5CE8 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_0043AD2C /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF0B13A8 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF0A14B0 \n"
"    BL      sub_FF0A1740 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_0043AB54 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0B5C0C \n"
"    LDR     R1, =0x1667 \n"

"loc_FF0B5CDC:\n"
"    LDR     R0, =0xFF0B1AB8 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF0B5C0C \n"

"loc_FF0B5CE8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF0B5D50 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0B3FCC \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0B7450 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_FF0B6068 \n"

"loc_FF0B5D50:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF0B5E08 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF0B422C \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF0B5DA4 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF0B5DDC \n"

"loc_FF0B5DA4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_FF0B5DF0 \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF0B57B8 \n"

"loc_FF0B5DDC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF0B5A6C \n"
"    B       loc_FF0B6070 \n"

"loc_FF0B5DF0:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF0B6070 \n"

"loc_FF0B5E08:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF0B5E54 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0B2FA8 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0B3400 \n"
"    B       loc_FF0B6070 \n"

"loc_FF0B5E54:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF0B6058 \n"
"    B       loc_FF0B5F10 \n"
"    B       loc_FF0B5F10 \n"
"    B       loc_FF0B5F18 \n"
"    B       loc_FF0B5F20 \n"
"    B       loc_FF0B5F20 \n"
"    B       loc_FF0B5F20 \n"
"    B       loc_FF0B5F10 \n"
"    B       loc_FF0B5F18 \n"
"    B       loc_FF0B5F20 \n"
"    B       loc_FF0B5F20 \n"
"    B       loc_FF0B5F38 \n"
"    B       loc_FF0B5F38 \n"
"    B       loc_FF0B6044 \n"
"    B       loc_FF0B604C \n"
"    B       loc_FF0B604C \n"
"    B       loc_FF0B604C \n"
"    B       loc_FF0B604C \n"
"    B       loc_FF0B6054 \n"
"    B       loc_FF0B6058 \n"
"    B       loc_FF0B6058 \n"
"    B       loc_FF0B6058 \n"
"    B       loc_FF0B6058 \n"
"    B       loc_FF0B6058 \n"
"    B       loc_FF0B6058 \n"
"    B       loc_FF0B5F28 \n"
"    B       loc_FF0B5F30 \n"
"    B       loc_FF0B5F30 \n"
"    B       loc_FF0B5F30 \n"
"    B       loc_FF0B5F44 \n"
"    B       loc_FF0B5F44 \n"
"    B       loc_FF0B5F4C \n"
"    B       loc_FF0B5F84 \n"
"    B       loc_FF0B5FBC \n"
"    B       loc_FF0B5FF4 \n"
"    B       loc_FF0B602C \n"
"    B       loc_FF0B602C \n"
"    B       loc_FF0B6058 \n"
"    B       loc_FF0B6058 \n"
"    B       loc_FF0B6034 \n"
"    B       loc_FF0B603C \n"

"loc_FF0B5F10:\n"
"    BL      sub_FF0B193C \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5F18:\n"
"    BL      sub_FF0B1BF0 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5F20:\n"
"    BL      sub_FF0B1E18 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5F28:\n"
"    BL      sub_FF0B213C \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5F30:\n"
"    BL      sub_FF0B2354 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5F38:\n"
"    BL      sub_FF0B2710_my \n"  // --> Patched. Old value = 0xFF0B2710.
"    MOV     R8, #0 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5F44:\n"
"    BL      sub_FF0B2850 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5F4C:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0B70DC \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5F84:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0B7250 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5FBC:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0B7304 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B5FF4:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0B73AC \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B602C:\n"
"    BL      sub_FF0B2D40 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B6034:\n"
"    BL      sub_FF0B3504 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B603C:\n"
"    BL      sub_FF0B37E8 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B6044:\n"
"    BL      sub_FF0B3AA0 \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B604C:\n"
"    BL      sub_FF0B3C5C \n"
"    B       loc_FF0B6058 \n"

"loc_FF0B6054:\n"
"    BL      sub_FF0B3DC4 \n"

"loc_FF0B6058:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_FF0B6068:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF0B6070:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF0B60A8 \n"
"    BGT     loc_FF0B6098 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF0B60DC \n"
"    B       loc_FF0B60A8 \n"

"loc_FF0B6098:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF0B60DC \n"

"loc_FF0B60A8:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF0B60DC \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF0B7654 \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF0B60DC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF0B612C \n"
"    LDR     R1, [R0, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x578E0 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_0043C0D4 \n"
"    LDR     R0, =0x578EC \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_0043C0D4 \n"
"    LDR     R0, =0x578F8 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_0043C0D4 \n"
"    B       loc_FF0B61A4 \n"

"loc_FF0B612C:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF0B6170 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0B1710 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF0B61A0 \n"

"loc_FF0B6170:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF0B1710 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF0B61A0:\n"
"    BL      sub_FF0B1888 \n"

"loc_FF0B61A4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0B7048 \n"
"    B       loc_FF0B5B3C \n"
);
}

/*************************************************************/
//** sub_FF0B2710_my @ 0xFF0B2710 - 0xFF0B27D0, length=49
void __attribute__((naked,noinline)) sub_FF0B2710_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x4934 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_0043AD2C /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF0B1410 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF0B1570 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF0B15C8 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF0B1620 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0B1678 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x578F8 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF0B27A4 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF0B27A4 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF0B1368 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF17BF20 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF0B27AC \n"

"loc_FF0B27A4:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF0B27AC:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF0B27C8 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF0B13EC \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF0B7098 \n"

"loc_FF0B27C8:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF0A17AC_my \n"  // --> Patched. Old value = 0xFF0A17AC.
"    LDR     PC, =0xFF0B27D4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF0A17AC_my @ 0xFF0A17AC - 0xFF0A1814, length=27
void __attribute__((naked,noinline)) sub_FF0A17AC_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x45BC \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0x14D \n"
"    LDRNE   R0, =0xFF0A15E4 \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x153 \n"
"    LDREQ   R0, =0xFF0A15E4 \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us. _apex2us
"    MOV     R4, R0 \n"
//"  BL      _sub_FF0FD744 \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FF105444 \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0x158 \n"
"    LDR     R0, =0xFF0A15E4 \n"
"    B       _DebugAssert \n"
);
}
