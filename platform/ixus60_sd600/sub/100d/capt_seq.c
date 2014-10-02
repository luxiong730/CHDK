/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)0x61AC;   // found at 0xFF962120 (CaptureSeq.c)

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF95FBFC - 0xFF95FDA8, length=108
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    SUB     SP, SP, #4 \n"
"    MOV     R4, SP \n"
"    B       loc_FF95FD74 \n"

"loc_FF95FC0C:\n"
"    LDR     R2, [SP] \n"
"    LDR     R3, [R2] \n"
"    MOV     R0, R2 \n"
"    CMP     R3, #0x14 \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FF95FD48 \n"
"    .long   loc_FF95FC78 \n"
"    .long   loc_FF95FC98 \n"
"    .long   loc_FF95FCAC \n"
"    .long   loc_FF95FCBC \n"
"    .long   loc_FF95FCB4 \n"
"    .long   loc_FF95FCC4 \n"
"    .long   loc_FF95FCCC \n"
"    .long   loc_FF95FCD8 \n"
"    .long   loc_FF95FCE0 \n"
"    .long   loc_FF95FCEC \n"
"    .long   loc_FF95FCF4 \n"
"    .long   loc_FF95FCFC \n"
"    .long   loc_FF95FD04 \n"
"    .long   loc_FF95FD0C \n"
"    .long   loc_FF95FD14 \n"
"    .long   loc_FF95FD20 \n"
"    .long   loc_FF95FD28 \n"
"    .long   loc_FF95FD30 \n"
"    .long   loc_FF95FD38 \n"
"    .long   loc_FF95FD40 \n"
"    .long   loc_FF95FD5C \n"

"loc_FF95FC78:\n"
"    BL      sub_FF961648 \n"
"    BL      shooting_expo_param_override\n"   // +
"    BL      sub_FF95D990 \n"
"    LDR     R3, =0x99CC0 \n"
"    MOV     R2, #0\n"                          // added
"    STR     R2, [R3,#0x24]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
//"  LDR     R2, [R3, #0x24] \n"  // above patch makes these three lines redundant
//"  CMP     R2, #0 \n"
//"  BEQ     loc_FF95FD58 \n"
//"  BL      _sub_FF95F858 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FC98:\n"
"    BL      sub_FF95F788_my \n"  // --> Patched. Old value = 0xFF95F788.

"loc_FF95FC9C:\n"
"    LDR     R2, =0x99CC0 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2, #0x24] \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FCAC:\n"
"    BL      sub_FF9619D8 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FCB4:\n"
"    BL      sub_FF960848 \n"
"    B       loc_FF95FC9C \n"

"loc_FF95FCBC:\n"
"    BL      sub_FF960BE4 \n"
"    B       loc_FF95FC9C \n"

"loc_FF95FCC4:\n"
"    BL      sub_FF960BF4 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FCCC:\n"
"    BL      sub_FF96172C \n"
"    BL      sub_FF95D990 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FCD8:\n"
"    BL      sub_FF95F92C \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FCE0:\n"
"    BL      sub_FF961794 \n"
"    BL      sub_FF95D990 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FCEC:\n"
"    BL      sub_FF960BE4 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FCF4:\n"
"    BL      sub_FF961F2C \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FCFC:\n"
"    BL      sub_FF962278 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FD04:\n"
"    BL      sub_FF9622FC \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FD0C:\n"
"    BL      sub_FF9623E8 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FD14:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF9624B0 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FD20:\n"
"    BL      sub_FF96261C \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FD28:\n"
"    BL      sub_FF9626B0 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FD30:\n"
"    BL      sub_FF96276C \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FD38:\n"
"    BL      sub_FF962858 \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FD40:\n"
"    BL      sub_FF9628AC \n"
"    B       loc_FF95FD58 \n"

"loc_FF95FD48:\n"
"    MOV     R1, #0x36C \n"
"    LDR     R0, =0xFF95F514 /*'ShootTask.c'*/ \n"
"    ADD     R1, R1, #1 \n"
"    BL      _DebugAssert \n"

"loc_FF95FD58:\n"
"    LDR     R2, [SP] \n"

"loc_FF95FD5C:\n"
"    LDR     R3, =0x6F18C \n"
"    LDR     R1, [R2, #4] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF81FCE4 /*_SetEventFlag*/ \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF95F590 \n"

"loc_FF95FD74:\n"
"    LDR     R3, =0x6F190 \n"
"    MOV     R1, R4 \n"
"    LDR     R0, [R3] \n"
"    MOV     R2, #0 \n"
"    BL      sub_FF8203FC /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF95FC0C \n"
"    MOV     R1, #0x2A4 \n"
"    LDR     R0, =0xFF95F514 /*'ShootTask.c'*/ \n"
"    ADD     R1, R1, #3 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #4 \n"
"    LDMFD   SP!, {R4,PC} \n"
);
}

/*************************************************************/
//** sub_FF95F788_my @ 0xFF95F788 - 0xFF95F848, length=49
void __attribute__((naked,noinline)) sub_FF95F788_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R4, [R0, #0xC] \n"
"    BL      sub_FF967F2C \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF95F7A0 \n"
"    BL      sub_FF967F38 \n"

"loc_FF95F7A0:\n"
"    LDR     R3, =0x99CC0 \n"
"    LDR     R2, [R3, #0x24] \n"
"    CMP     R2, #0 \n"
"    BNE     loc_FF95F7D4 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF967F4C \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF95F7D4 \n"
"    MOV     R0, #1 \n"

"loc_FF95F7C4:\n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF95DE70 \n"

"loc_FF95F7D4:\n"
"    LDR     R3, =0x99CC0 \n"
"    LDR     R2, [R3, #0x24] \n"
"    CMP     R2, #0 \n"
"    BNE     loc_FF95F824 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF9619E8 \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF95F7C4 \n"
"    BL      sub_FF9A0B80 \n"
"    BL      sub_FF824A78 \n"
"    LDR     R2, =0x99C04 \n"
"    ADD     R3, R4, R4, LSL#1 \n"
"    STR     R0, [R2, R3, LSL#5] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF96339C \n"
"    BL      sub_FF961EEC \n"
"    BL      sub_FF961E88 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF962C30_my \n"  // --> Patched. Old value = 0xFF962C30.
"    BL      capt_seq_hook_raw_here\n"   // +
"    B       loc_FF95F838 \n"

"loc_FF95F824:\n"
"    LDR     R3, =0x61A4 \n"
"    LDR     R2, [R3] \n"
"    CMP     R2, #0 \n"
"    MOVNE   R0, #0x1D \n"
"    MOVEQ   R0, #0 \n"

"loc_FF95F838:\n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF95DE70 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF962E28 \n"
);
}

/*************************************************************/
//** sub_FF962C30_my @ 0xFF962C30 - 0xFF962C5C, length=12
void __attribute__((naked,noinline)) sub_FF962C30_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R3, =0x6F204 \n"
"    LDR     R5, =0x61B4 \n"
"    SUB     SP, SP, #4 \n"
"    MVN     R1, #0 \n"
"    STR     R0, [R5] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF81FE80 /*_ClearEventFlag*/ \n"
"    LDR     R3, =0x99CC0 \n"
"    LDR     R0, [R3, #0x7C] \n"
"    BL      sub_FF89E17C \n"
"    BL      sub_FF962B84 \n"
"    BL      wait_until_remote_button_is_released\n"
"    BL      capt_seq_hook_set_nr\n"
"    LDR     PC, =0xFF962C60 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF9064FC - 0xFF90693C, length=273
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x14 \n"
"    MOV     R7, SP \n"
"    B       loc_FF9068F8 \n"

"loc_FF90650C:\n"
"    CMP     R2, #0x1F \n"
"    BNE     loc_FF906524 \n"
"    LDR     R0, [R12, #0x50] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x4C] \n"
"    B       loc_FF906584 \n"

"loc_FF906524:\n"
"    CMP     R2, #0x1A \n"
"    BNE     loc_FF906538 \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF90642C \n"
"    B       loc_FF906574 \n"

"loc_FF906538:\n"
"    CMP     R2, #0x1B \n"
"    BNE     loc_FF90654C \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF906468 \n"
"    B       loc_FF906574 \n"

"loc_FF90654C:\n"
"    SUB     R3, R2, #0x1C \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF906564 \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF9064A4 \n"
"    B       loc_FF906574 \n"

"loc_FF906564:\n"
"    CMP     R2, #0x1E \n"
"    BNE     loc_FF906590 \n"
"    BL      sub_FF8B1180 \n"
"    BL      sub_FF8B2F70 \n"

"loc_FF906574:\n"
"    LDR     R3, [SP] \n"
"    LDR     R0, [R3, #0x50] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x4C] \n"

"loc_FF906584:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF9041EC \n"
"    B       loc_FF9068F8 \n"

"loc_FF906590:\n"
"    CMP     R2, #0xD \n"
"    MOV     R8, #1 \n"
"    BNE     loc_FF906600 \n"
"    LDR     R1, [R12, #0x40] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#1 \n"
"    ADD     R6, SP, #0xC \n"
"    SUB     R1, R1, #2 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF9056BC \n"
"    LDR     R3, [SP] \n"
"    LDR     R1, [R3, #0x40] \n"
"    LDR     R2, [R3, #0x50] \n"
"    ADD     R0, R3, #4 \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x4C] \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF905840 \n"
"    LDR     R3, [SP] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x40] \n"
"    LDR     R2, [R3, #0x58] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x54] \n"
"    B       loc_FF9068A8 \n"

"loc_FF906600:\n"
"    SUB     R3, R2, #0xE \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF9066BC \n"
"    ADD     R6, SP, #0xC \n"
"    ADD     R5, SP, #4 \n"
"    MOV     R0, R12 \n"
"    MOV     R1, R6 \n"
"    MOV     R2, R5 \n"
"    BL      sub_FF9058BC \n"
"    MOV     R4, R0 \n"
"    CMP     R4, #5 \n"
"    CMPNE   R4, #1 \n"
"    BNE     loc_FF906654 \n"
"    LDR     R12, [SP] \n"
"    MOV     R0, R5 \n"
"    LDR     R1, [R12, #0x40] \n"
"    MOV     R2, R4 \n"
"    LDR     R3, [R12, #0x50] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x4C] \n"
"    B       loc_FF90668C \n"

"loc_FF906654:\n"
"    CMP     R4, #6 \n"
"    CMPNE   R4, #2 \n"
"    BNE     loc_FF90669C \n"
"    LDR     R12, [SP] \n"
"    MOV     R0, R5 \n"
"    MOV     R1, R8 \n"
"    MOV     R2, R4 \n"
"    LDR     R3, [R12, #0x50] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x4C] \n"
"    MOV     R1, R6 \n"
"    LDR     R0, [SP] \n"
"    MOV     R2, R5 \n"
"    BL      sub_FF906268 \n"

"loc_FF90668C:\n"
"    MOV     R1, R4 \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF90640C \n"
"    B       loc_FF9068A8 \n"

"loc_FF90669C:\n"
"    LDR     R12, [SP] \n"
"    MOV     R2, R4 \n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x40] \n"
"    LDR     R3, [R12, #0x50] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x4C] \n"
"    B       loc_FF9068A8 \n"

"loc_FF9066BC:\n"
"    SUB     R3, R2, #0x17 \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF906714 \n"
"    LDR     R1, [R12, #0x40] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#1 \n"
"    ADD     R6, SP, #0xC \n"
"    SUB     R1, R1, #2 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF9051F0 \n"
"    LDR     R3, [SP] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x40] \n"
"    LDR     R2, [R3, #0x50] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x4C] \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF9053C0 \n"
"    B       loc_FF9068A8 \n"

"loc_FF906714:\n"
"    ADD     R6, SP, #0xC \n"
"    ADD     R1, R12, #4 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R12, [SP] \n"
"    LDR     R3, [R12] \n"
"    MOV     R2, R12 \n"
"    CMP     R3, #0x19 \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FF906894 \n"
"    .long   loc_FF9067A8 \n"
"    .long   loc_FF9067B4 \n"
"    .long   loc_FF9067C0 \n"
"    .long   loc_FF9067C0 \n"
"    .long   loc_FF9067A8 \n"
"    .long   loc_FF9067B4 \n"
"    .long   loc_FF9067C0 \n"
"    .long   loc_FF9067C0 \n"
"    .long   loc_FF9067E4 \n"
"    .long   loc_FF9067E4 \n"
"    .long   loc_FF906868 \n"
"    .long   loc_FF906874 \n"
"    .long   loc_FF906884 \n"
"    .long   loc_FF906894 \n"
"    .long   loc_FF906894 \n"
"    .long   loc_FF906894 \n"
"    .long   loc_FF9067CC \n"
"    .long   loc_FF9067D8 \n"
"    .long   loc_FF9067F4 \n"
"    .long   loc_FF906800 \n"
"    .long   loc_FF906828 \n"
"    .long   loc_FF906850 \n"
"    .long   loc_FF906850 \n"
"    .long   loc_FF906894 \n"
"    .long   loc_FF906894 \n"
"    .long   loc_FF90685C \n"

"loc_FF9067A8:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF904790 \n"
"    B       loc_FF906890 \n"

"loc_FF9067B4:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF9048CC \n"
"    B       loc_FF906890 \n"

"loc_FF9067C0:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF9049FC \n"
"    B       loc_FF906890 \n"

"loc_FF9067CC:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF904BD0 \n"
"    B       loc_FF906890 \n"

"loc_FF9067D8:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF904CD8 \n"
"    B       loc_FF906890 \n"

"loc_FF9067E4:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF904D9C_my \n"  // --> Patched. Old value = 0xFF904D9C.
"    MOV     R8, #0 \n"
"    B       loc_FF906890 \n"

"loc_FF9067F4:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF904E5C \n"
"    B       loc_FF906890 \n"

"loc_FF906800:\n"
"    MOV     R0, R2 \n"
"    LDRH    R2, [R2, #4] \n"
"    LDR     R3, =0x4A1FC \n"
"    STRH    R2, [SP, #0xC] \n"
"    LDRH    R1, [R3, #4] \n"
"    STRH    R1, [SP, #0x10] \n"
"    LDRH    R3, [R3, #2] \n"
"    STRH    R3, [SP, #0xE] \n"
"    BL      sub_FF904FE4 \n"
"    B       loc_FF906890 \n"

"loc_FF906828:\n"
"    LDR     R3, =0x4A1FC \n"
"    LDRH    R1, [R3] \n"
"    STRH    R1, [SP, #0xC] \n"
"    MOV     R0, R2 \n"
"    LDRH    R2, [R2, #6] \n"
"    STRH    R2, [SP, #0xE] \n"
"    LDRH    R3, [R3, #4] \n"
"    STRH    R3, [SP, #0x10] \n"
"    BL      sub_FF905078 \n"
"    B       loc_FF906890 \n"

"loc_FF906850:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF9050F8 \n"
"    B       loc_FF906890 \n"

"loc_FF90685C:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF905450 \n"
"    B       loc_FF906890 \n"

"loc_FF906868:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF905524 \n"
"    B       loc_FF906890 \n"

"loc_FF906874:\n"
"    MOV     R0, R2 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF905610 \n"
"    B       loc_FF906890 \n"

"loc_FF906884:\n"
"    MOV     R0, R2 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF905610 \n"

"loc_FF906890:\n"
"    LDR     R12, [SP] \n"

"loc_FF906894:\n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x40] \n"
"    LDR     R2, [R12, #0x50] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x4C] \n"

"loc_FF9068A8:\n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF9068D0 \n"
"    LDR     R1, [SP] \n"
"    LDR     R3, [R1, #0x40] \n"
"    ADD     R3, R3, R3, LSL#1 \n"
"    ADD     R1, R1, R3, LSL#1 \n"
"    MOV     R0, R6 \n"
"    SUB     R1, R1, #2 \n"
"    BL      sub_FF904600 \n"
"    B       loc_FF9068F0 \n"

"loc_FF9068D0:\n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FF9045A4 \n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FF9046BC \n"

"loc_FF9068F0:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF9041EC \n"

"loc_FF9068F8:\n"
"    LDR     R3, =0x4A1F4 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R3] \n"
"    MOV     R1, R7 \n"
"    BL      sub_FF8203FC /*_ReceiveMessageQueue*/ \n"
"    LDR     R12, [SP] \n"
"    LDR     R2, [R12] \n"
"    CMP     R2, #0x20 \n"
"    BNE     loc_FF90650C \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF9041EC \n"
"    LDR     R3, =0x4A1F0 \n"
"    MOV     R1, #1 \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF81FCE4 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x14 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FF904D9C_my @ 0xFF904D9C - 0xFF904E4C, length=45
void __attribute__((naked,noinline)) sub_FF904D9C_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R3, =0x4A1F0 \n"
"    MOV     R4, R0 \n"
"    MOV     R1, #0xE \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF81FE80 /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FF9042C8 \n"
"    MOV     R5, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF90443C \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF9044D8 \n"
"    LDR     R3, [R4] \n"
"    CMP     R3, #9 \n"
"    MOVEQ   R5, #0 \n"
"    CMP     R5, #1 \n"
"    LDR     R1, =0xFF904220 \n"
"    MOV     R2, #2 \n"
"    BNE     loc_FF904E08 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FFAAD660 \n"
"    LDR     R2, =0x4A21C \n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2] \n"
"    B       loc_FF904E0C \n"

"loc_FF904E08:\n"
"    BL      sub_FF904574 \n"

"loc_FF904E0C:\n"
"    STRH    R0, [R4, #4] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8B0E08_my \n"  // --> Patched. Old value = 0xFF8B0E08.
"    LDRSH   R0, [R4, #8] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF8B2B30 \n"
"    MOV     R1, #0 \n"
"    ADD     R0, R4, #8 \n"
"    BL      sub_FF8B2BF0 \n"
"    CMP     R5, #1 \n"
"    MOV     R1, #2 \n"
"    MOV     R2, #0 \n"
"    LDMNEFD SP!, {R4,R5,PC} \n"
"    LDR     R3, =0x4A1F0 \n"
"    LDR     R0, [R3] \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FF81FCD4 /*_WaitForAllEventFlag*/ \n"
);
}

/*************************************************************/
//** sub_FF8B0E08_my @ 0xFF8B0E08 - 0xFF8B0E64, length=24
void __attribute__((naked,noinline)) sub_FF8B0E08_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R3, =0x531C \n"
"    LDR     R2, [R3] \n"
"    MOV     R1, #0x114 \n"
"    MOV     R3, R0, LSL#16 \n"
"    CMP     R2, #1 \n"
"    ADD     R1, R1, #1 \n"
"    LDR     R0, =0xFF8B0884 /*'Shutter.c'*/ \n"
"    MOV     R4, R3, ASR#16 \n"
"    BEQ     loc_FF8B0E34 \n"
"    BL      _DebugAssert \n"

"loc_FF8B0E34:\n"
"    MOV     R1, #0x118 \n"
"    CMN     R4, #0xC00 \n"
"    LDR     R3, =0x3D04E \n"
"    LDR     R0, =0xFF8B0884 /*'Shutter.c'*/ \n"
"    ADD     R1, R1, #3 \n"
"    LDREQSH R4, [R3] \n"
"    LDRNE   R3, =0x3D04E \n"
"    CMN     R4, #0xC00 \n"
"    STRH    R4, [R3] \n"
"    BNE     loc_FF8B0E60 \n"
"    BL      _DebugAssert \n"

"loc_FF8B0E60:\n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF8B0E68 \n"  // Continue in firmware
);
}
