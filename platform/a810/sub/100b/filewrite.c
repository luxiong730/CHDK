#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 7 // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc and name are always needed
 */
typedef struct
{
    int unkn1;
    int file_offset;    // needed for DryOS>=r50
    int full_size;      // needed for DryOS>=r50
    int unkn2, unkn3, unkn4;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    int seek_flag;      // needed for DryOS>=r50
    char name[32];
} fwt_data_struct;
#define FWT_MUSTSEEK    2   // value of the masked seek_flag indicating seek is required
#define FWT_SEEKMASK    0xffffffff   // masks out unneeded bits of seek_flag

#include "../../../generic/filewrite.c"

//** filewritetask  @ 0xFFA523F4 

void __attribute__((naked,noinline)) filewritetask(  ) { 
asm volatile (
      "    STMFD   SP!, {R1-R7,LR} \n" 
      "    LDR     R7, =0x96B0 \n" 
      "    MOV     R6, #0 \n" 
"loc_FFA52400:\n"
      "    LDR     R0, [R7, #0x14] \n" 
      "    MOV     R2, #0 \n" 
      "    ADD     R1, SP, #8 \n" 
      "    MOV     R5, R7 \n" 
      "    BL      sub_003F7218 \n" //ReceiveMessageQueue
      "    CMP     R0, #0 \n" 
      "    LDRNE   R1, =0x38E \n" 
      "    LDRNE   R0, =0xFFA52538 \n" // dwFWrite.c
      "    BLNE    _DebugAssert \n" //DebugAssert
      "    LDR     R0, [SP, #8] \n" 
      "    LDR     R1, [R0] \n" // state (aka msg number)
      "    CMP     R1, #0xB \n" 
      "    ADDCC   PC, PC, R1, LSL #2 \n" 
      "    B       loc_FFA52400 \n" 
      "    B       loc_FFA52508 \n" 
      "    B       loc_FFA52508 \n" 
      "    B       loc_FFA52508 \n" 
      "    B       loc_FFA52508 \n" 
      "    B       loc_FFA52508 \n" 
      "    B       loc_FFA52508 \n" 
      "    B       loc_FFA52508 \n" 
      "    B       loc_FFA52510 \n" 
      "    B       loc_FFA52464 \n" 
      "    B       loc_FFA524D4 \n" 
      "    B       loc_FFA524CC \n" 
"loc_FFA52464:\n"             // (state 8) empties the message queue
      "    STR     R6, [SP] \n" 
"loc_FFA52468:\n"
      "    LDR     R0, [R5, #0x14] \n" 
      "    MOV     R1, SP \n" 
      "    BL      sub_003F745C \n" //GetNumberOfPostedMessages
      "    LDR     R0, [SP] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FFA52494 \n" // no message left in queue
      "    LDR     R0, [R5, #0x14] \n" 
      "    MOV     R2, #0 \n" 
      "    ADD     R1, SP, #4 \n" 
      "    BL      sub_003F7218 \n" //ReceiveMessageQueue
      "    B       loc_FFA52468 \n" 
"loc_FFA52494:\n"
      "    LDR     R0, [R5, #8] \n" // file descriptor
      "    CMN     R0, #1 \n" 
      "    BEQ     loc_FFA524C0 \n" 
      "    BL      fwt_close\n"     // mod! sub_FF830158 Close
"loc_FFA524A4:\n"
      "    MVN     R0, #0 \n" 
      "    STR     R0, [R5, #8] \n" // file descriptor
      "    LDR     R0, =0x131D20 \n" 
      "    STR     R6, [R5, #4] \n" 
      "    BL      sub_FF86671C \n" // path check or something
      "    MOV     R1, #0 \n" 
      "    BL      sub_FF8647B8 \n" // file semaphore related
"loc_FFA524C0:\n"
      "    LDR     R0, [R5, #0x10] \n" 
      "    BL      sub_003F7704 \n" //GiveSemaphore
      "    B       loc_FFA52400 \n" 
"loc_FFA524CC:\n"
      "    BL      sub_FFA520F0_my \n" // -> open stage (state 10)
      "    B       loc_FFA52400 \n" 
"loc_FFA524D4:\n"                   // (state 9), append? overwrite?
      "    LDR     R1, [R0, #4] \n" 
      "    MOV     R4, R0 \n" 
      "    LDR     R0, [R5, #8] \n" // file descriptor
      "    MOV     R2, #0 \n"       // SEEK_SET
      "    BL      fwt_lseek\n"     // mod! sub_FF8302F0 lseek
      "    CMN     R0, #1 \n" 
      "    LDREQ   R0, =0x9200013 \n" 
      "    MOV     R1, R4 \n" 
      "    STREQ   R0, [R4, #0x14] \n" 
      "    MOVNE   R0, #0 \n"       // next state = 0 (write)
      "    MOVEQ   R0, #7 \n"       // next state = 7 (close)
      "    BL      sub_FFA52034 \n" // next state = 7 (close)
      "    B       loc_FFA52400 \n" 
"loc_FFA52508:\n"
      "    BL      sub_FFA52730_my \n" // -> write stage (states 0..6)
      "    B       loc_FFA52400 \n" 
"loc_FFA52510:\n"
      "    BL      sub_FFA5225C_my \n" // -> close stage (state 7)
      "    B       loc_FFA52400 \n" 
    );
}


//** sub_FFA520F0_my  @ 0xFFA520F0 

void __attribute__((naked,noinline)) sub_FFA520F0_my(  ) { //open
asm volatile (
      "    STMFD   SP!, {R4-R9,LR} \n" 
      "    LDR     R6, =0x96B0 \n" 
      "    MOV     R4, R0 \n" 
//hook start placed here to avoid bne a few instructions below
      "STMFD SP!, {R4-R12,LR}\n"
      //"MOV R0, R4\n"        //data block start, commented out as R0 is already holding what we need
      "BL filewrite_main_hook\n"
      "LDMFD SP!, {R4-R12,LR}\n"
//hook end
      "    LDR     R0, [R6, #4] \n" 
      "    SUB     SP, SP, #0x3C \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FFA5222C \n"
      "    ADD     R0, R4, #0x54 \n" 
      "    BL      sub_FF86671C \n"   // path check or something
      "    MOV     R1, #0 \n" 
      "    BL      sub_FF86472C \n" 
      "    LDR     R0, [R4, #0x10] \n" 
      "    BL      sub_FF8636F0 \n" 
      "    LDR     R0, [R4, #0x50] \n" 
      "    LDR     R9, =0x1B6 \n" 
      "    CMP     R0, #1 \n" 
      "    LDREQ   R0, [R4, #0xC] \n" 
      "    ADD     R7, R4, #0x54 \n" 
      "    ORREQ   R0, R0, #0x8000 \n" 
      "    STREQ   R0, [R4, #0xC] \n" 
      "    LDR     R8, [R4, #0xC] \n" 
      "    LDR     R5, [R4, #0x10] \n" 
      "    MOV     R2, R9 \n" 
      "    MOV     R1, R8 \n" 
      "    MOV     R0, R7 \n" 
      "    BL      fwt_open\n"          // mod! sub_FF830154 Open
      "    CMN     R0, #1 \n" // rom:ffa52158
      "    BNE     loc_FFA521BC \n"
      "    MOV     R0, R7 \n" 
      "    BL      sub_FF83083C \n" 
      "    MOV     R2, #0xF \n" 
      "    MOV     R1, R7 \n" 
      "    ADD     R0, SP, #4 \n" 
      "    BL      sub_003FC17C \n" 
      "    MOV     R0, #0 \n" 
      "    LDR     R1, =0x41FF \n" 
      "    STRB    R0, [SP, #0x13] \n" 
      "    STR     R1, [SP, #0x24] \n" 
      "    MOV     R1, #0x10 \n" 
      "    STR     R0, [SP, #0x2C] \n" 
      "    STR     R1, [SP, #0x28] \n" 
      "    ADD     R1, SP, #0x24 \n" 
      "    ADD     R0, SP, #4 \n" 
      "    STR     R5, [SP, #0x30] \n" 
      "    STR     R5, [SP, #0x34] \n" 
      "    STR     R5, [SP, #0x38] \n" 
      "    BL      sub_FF863FF8 \n" 
      "    MOV     R2, R9 \n" 
      "    MOV     R1, R8 \n" 
      "    MOV     R0, R7 \n" 
      "    BL      sub_FF830154 \n" 
"loc_FFA521BC:\n"
      "    CMN     R0, #1 \n" 
      "    MOV     R5, R0 \n" 
      "    STR     R0, [R6, #8] \n" 
      "    BNE     loc_FFA521F8 \n" 
      "    ADD     R0, R4, #0x54 \n" 
      "    BL      sub_FF86671C \n" // path check or something
      "    LDR     R1, [R6, #0x1C] \n" 
      "    BL      sub_FF8647B8 \n" 
      "    LDR     R1, [R6, #0x18] \n" 
      "    CMP     R1, #0 \n" 
      "    BEQ     loc_FFA52254 \n" 
      "    ADD     SP, SP, #0x3C \n" 
      "    LDMFD   SP!, {R4-R9,LR} \n" 
      "    LDR     R0, =0x9200001 \n" 
      "    BX      R1 \n" 
"loc_FFA521F8:\n"
      "    MOV     R0, #1 \n" 
      "    STR     R0, [R6, #4] \n" 
      "    LDR     R0, =0x131D20 \n" 
      "    MOV     R2, #0x20 \n" 
      "    ADD     R1, R4, #0x54 \n" 
      "    BL      sub_003FC364 \n" 
//mod start      
      "LDR R3, =current_write_ignored\n"
      "LDR R3, [R3]\n"
      "CMP R3, #0\n"
      "BNE loc_FFA5222C\n" // jump over the next block
//mod end
      "    LDR     R1, [R4, #8] \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF830430 \n" 
      "    CMP     R0, #0 \n" 
      "    MOVEQ   R1, R4 \n" 
      "    MOVEQ   R0, #7 \n" 
      "    BEQ     loc_FFA52250 \n" 
"loc_FFA5222C:\n"
      "    LDR     R0, [R4, #0x50] \n" 
      "    CMP     R0, #2 \n" 
      "    BEQ     loc_FFA52248 \n" 
      "    LDR     R0, [R4, #4] \n" 
      "    CMP     R0, #0 \n" 
      "    MOVEQ   R1, R4 \n" 
      "    BEQ     loc_FFA52250 \n" 
"loc_FFA52248:\n"
      "    MOV     R1, R4 \n" 
      "    MOV     R0, #9 \n" // next state, the weird "append/overwrite" mode
"loc_FFA52250:\n"
      "    BL      sub_FFA52034 \n" // send_msg_to_filewritetask
"loc_FFA52254:\n"
      "    ADD     SP, SP, #0x3C \n" 
      "    LDMFD   SP!, {R4-R9,PC} \n" 
      );
}


//** sub_FFA52730_my  @ 0xFFA52730 

void __attribute__((naked,noinline)) sub_FFA52730_my(  ) { 
asm volatile (
      "    STMFD   SP!, {R4-R10,LR} \n" 
      "    MOV     R5, R0 \n" 
      "    LDR     R0, [R0] \n" 
      "    CMP     R0, #6 \n" 
      "    BHI     loc_FFA5275C \n" 
      "    ADD     R0, R5, R0, LSL #3 \n" 
      "    LDR     R8, [R0, #0x18]! \n" 
      "    LDR     R7, [R0, #4] \n" 
      "    CMP     R7, #0 \n" 
      "    BNE     loc_FFA52774 \n" 
      "    B       loc_FFA52768 \n" 
"loc_FFA5275C:\n"
      "    LDR     R1, =0x2DD \n" 
      "    LDR     R0, =0xFFA52538 \n" 
      "    BL      sub_003F6AFC \n" 
"loc_FFA52768:\n"
      "    MOV     R1, R5 \n" 
      "    MOV     R0, #7 \n" 
      "    B       loc_FFA52808 \n" 
"loc_FFA52774:\n"
      "    LDR     R9, =0x96B0 \n" 
      "    MOV     R4, R7 \n" 
"loc_FFA5277C:\n"
      "    LDR     R0, [R5, #4] \n" 
      "    CMP     R4, #0x1000000 \n" 
      "    MOVLS   R6, R4 \n" 
      "    MOVHI   R6, #0x1000000 \n" 
      "    BIC     R1, R0, #0xFF000000 \n" 
      "    CMP     R1, #0 \n" 
      "    BICNE   R0, R0, #0xFF000000 \n" 
      "    RSBNE   R0, R0, #0x1000000 \n" 
      "    CMPNE   R6, R0 \n" 
      "    MOVHI   R6, R0 \n" 
      "    LDR     R0, [R9, #8] \n" 
      "    MOV     R2, R6 \n" 
      "    MOV     R1, R8 \n" 
      "    BL      fwt_write\n"     // mod! sub_FF830290 Write
      "    LDR     R1, [R5, #4] \n"
      "    CMP     R6, R0 \n" 
      "    ADD     R1, R1, R0 \n" 
      "    STR     R1, [R5, #4] \n" 
      "    BEQ     loc_FFA527DC \n" 
      "    CMN     R0, #1 \n" 
      "    LDRNE   R0, =0x9200015 \n" 
      "    LDREQ   R0, =0x9200005 \n" 
      "    STR     R0, [R5, #0x14] \n" 
      "    B       loc_FFA52768 \n" 
"loc_FFA527DC:\n"
      "    SUB     R4, R4, R0 \n" 
      "    CMP     R4, R7 \n" 
      "    ADD     R8, R8, R0 \n" 
      "    MOVCS   R1, #0x308 \n" 
      "    LDRCS   R0, =0xFFA52538 \n" 
      "    BLCS    sub_003F6AFC \n" //DebugAssert
      "    CMP     R4, #0 \n" 
      "    BNE     loc_FFA5277C \n" 
      "    LDR     R0, [R5] \n" 
      "    MOV     R1, R5 \n" 
      "    ADD     R0, R0, #1 \n" 
"loc_FFA52808:\n"
      "    LDMFD   SP!, {R4-R10,LR} \n" 
      "    B       sub_FFA52034 \n" // send_msg_to_filewritetask
      ".ltorg\n" //+
    );
}


//** sub_FFA5225C_my  @ 0xFFA5225C 

void __attribute__((naked,noinline)) sub_FFA5225C_my(  ) { 
asm volatile (
      "    STMFD   SP!, {R4-R6,LR} \n" 
      "    MOV     R4, R0 \n" 
      "    LDR     R0, [R0, #0x50] \n" 
      "    LDR     R5, =0x96B0 \n" 
      "    CMP     R0, #3 \n" 
      "    SUB     SP, SP, #0x38 \n" 
      "    BEQ     loc_FFA523D4 \n" 
      "    LDR     R0, [R5, #8] \n" 
      "    CMN     R0, #1 \n" 
      "    BEQ     loc_FFA522B0 \n" 
      "    LDR     R1, [R4, #0xC] \n" 
      "    LDR     R6, =0x9200003 \n" 
      "    TST     R1, #0x8000 \n" 
      "    BEQ     loc_FFA5229C \n" 
//mod start      
      "LDR R3, =current_write_ignored\n"
      "LDR R3, [R3]\n"
      "CMP R3, #0\n"
      "BNE loc_FFA5229C\n" // jump over the next block
//mod end
      "    BL      sub_FF83015C \n" 
      "    B       loc_FFA522A0 \n" 
"loc_FFA5229C:\n"
      "    BL      fwt_close\n"         // mod! sub_FF830158 Close
"loc_FFA522A0:\n"
      "    CMP     R0, #0 \n" 
      "    MVN     R0, #0 \n" 
      "    STRNE   R6, [R4, #0x14] \n" 
      "    STR     R0, [R5, #8] \n" 
"loc_FFA522B0:\n"
      "    LDR     R0, [R4, #0x14] \n" 
      "    TST     R0, #1 \n" 
      "    BNE     loc_FFA523B8 \n" 
      "    LDR     R0, [R4, #0xC] \n" 
      "    TST     R0, #8 \n" 
      "    BNE     loc_FFA522D4 \n" 
      "    LDR     R0, [R4, #0x50] \n" 
      "    CMP     R0, #3 \n" 
      "    BNE     loc_FFA52304 \n" 
"loc_FFA522D4:\n"
      "    ADD     R1, SP, #0x20 \n" 
      "    ADD     R0, R4, #0x54 \n" 
      "    BL      sub_FF863F40 \n" 
      "    CMP     R0, #0 \n" 
      "    LDREQ   R1, =0x346 \n" 
      "    LDREQ   R0, =0xFFA52538 \n" 
      "    BLEQ    sub_003F6AFC \n" //DebugAssert
      "    LDR     R0, [SP, #0x28] \n" 
      "    LDR     R1, [R4, #4] \n" 
      "    ADD     R0, R0, R1 \n" 
      "    STR     R0, [SP, #0x28] \n" 
      "    B       loc_FFA52334 \n" 
"loc_FFA52304:\n"
      "    LDR     R0, =0x81FF \n" 
      "    STR     R0, [SP, #0x20] \n" 
      "    MOV     R0, #0x20 \n" 
      "    STR     R0, [SP, #0x24] \n" 
      "    LDR     R0, [R4, #4] \n" 
      "    STR     R0, [SP, #0x28] \n" 
      "    LDR     R0, [R4, #0x10] \n" 
      "    STR     R0, [SP, #0x2C] \n" 
      "    LDR     R0, [R4, #0x10] \n" 
      "    STR     R0, [SP, #0x30] \n" 
      "    LDR     R0, [R4, #0x10] \n" 
      "    STR     R0, [SP, #0x34] \n" 
"loc_FFA52334:\n"
      "    LDR     R0, [R4, #0x50] \n" 
      "    CMP     R0, #2 \n" 
      "    BEQ     loc_FFA523B8 \n" 
      "    ADD     R1, SP, #0x20 \n" 
      "    ADD     R0, R4, #0x54 \n" 
      "    BL      sub_FF863FF8 \n" 
      "    LDR     R0, [R4, #0x50] \n" 
      "    CMP     R0, #1 \n" 
      "    BNE     loc_FFA523B8 \n" 
      "    MOV     R2, #0x20 \n" 
      "    ADD     R1, R4, #0x54 \n" 
      "    MOV     R0, SP \n" 
      "    BL      sub_003FC364 \n" 
      "    MOV     R0, SP \n" 
      "    BL      sub_FF812E38 \n" 
      "    MOV     R2, #0x54 \n" 
      "    ADD     R0, R0, SP \n" 
      "    MOV     R1, #0x4D \n" 
      "    STRB    R2, [R0, #-3] \n" 
      "    STRB    R1, [R0, #-2] \n" 
      "    MOV     R1, #0x50 \n" 
      "    STRB    R1, [R0, #-1] \n" 
      "    MOV     R1, SP \n" 
      "    ADD     R0, R4, #0x54 \n" 
      "    BL      sub_FF863878 \n" 
      "    CMP     R0, #0 \n" 
      "    MOVEQ   R1, #0x164 \n" 
      "    LDREQ   R0, =0xFFA52538 \n" 
      "    BLEQ    sub_003F6AFC \n" //DebugAssert
      "    MOV     R0, SP \n" 
      "    BL      sub_FF864454 \n" 
      "    ADD     R0, R4, #0x54 \n" 
      "    BL      sub_FF864454 \n" 
"loc_FFA523B8:\n"
      "    ADD     R0, R4, #0x54 \n" 
      "    BL      sub_FF86671C \n" // path check or something
      "    LDR     R1, [R5, #0x1C] \n" 
      "    BL      sub_FF8647B8 \n" 
      "    MOV     R0, #0 \n" 
      "    STR     R0, [R5, #4] \n" 
      "    B       loc_FFA523DC \n" 
"loc_FFA523D4:\n"
      "    LDR     R0, [R5, #0x1C] \n" 
      "    BLX     R0 \n" 
"loc_FFA523DC:\n"
      "    LDR     R1, [R5, #0x18] \n" 
      "    CMP     R1, #0 \n" 
      "    LDRNE   R0, [R4, #0x14] \n" 
      "    BLXNE   R1 \n" 
      "    ADD     SP, SP, #0x38 \n" 
      "    LDMFD   SP!, {R4-R6,PC} \n" 
    );
}
