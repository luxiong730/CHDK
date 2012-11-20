#include "conf.h"

void change_video_tables(int a, int b){
}

void  set_quality(int *x){ // -17 highest; +12 lowest
 
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

void __attribute__((naked,noinline)) movie_record_task(){ //SX50HS

asm volatile (
		"STMFD   SP!, {R2-R12,LR}\n"
        "LDR     R11, =0x619\n"
        "LDR     R8, =sub_FF080EFC_my\n"
        "LDR     R9, =0xFF080EF8\n"
        "LDR     R4, =0x38B0\n"
        "LDR     R10, =0x2710\n"
        //"MOV     R7, 0xFFFFFFFF\n"
		"MVN     R7, #0\n"
        "MOV     R5, #1\n"
        "MOV     R6, #0\n"
"loc_FF0813E4:\n"
        "LDR     R0, [R4,#0x28]\n"
        "MOV     R2, #0\n"
        "ADD     R1, SP, #4\n"
        "BL      sub_68BDE0\n"
        "LDR     R2, =0xFF07E60C \n"
        "LDR     R0, [R4,#0x118]\n"
        "MOV     R3, R11\n"
        "MOV     R1, R10\n"
        "BL      sub_68AFEC\n"
        "LDR     R0, [R4,#0x30]\n"
        "CMP     R0, #0\n"
        "LDRNE   R0, [R4,#0x10]\n"
        "CMPNE   R0, #2\n"
        "LDRNE   R0, [R4,#0x44]\n"
        "CMPNE   R0, #6\n"
        "BNE     loc_FF08159C\n"
        "LDR     R0, [SP,#4]\n"
        "LDR     R1, [R0]\n"
        "SUB     R1, R1, #2\n"
        "CMP     R1, #0x11\n"
        "ADDCC   PC, PC, R1,LSL#2\n"
        "B       loc_FF08159C\n"
"loc_FF08143C:\n"
        "B       loc_FF0814D8\n"
"loc_FF081440:\n"
        "B       loc_FF0814F4\n"
"loc_FF081444:\n"
        "B       loc_FF081504\n"
"loc_FF081448:\n"
        "B       loc_FF08150C\n"
"loc_FF08144C:\n"
        "B       loc_FF081514\n"
"loc_FF081450:\n"
        "B       loc_FF08151C\n"
"loc_FF081454:\n"
        "B       loc_FF0814E0\n"
"loc_FF081458:\n"
        "B       loc_FF081548\n"
"loc_FF08145C:\n"
        "B       loc_FF081574\n"
"loc_FF081460:\n"
        "B       loc_FF08157C\n"
"loc_FF081464:\n"
        "B       loc_FF0814EC\n"
"loc_FF081468:\n"
        "B       loc_FF08159C\n"
"loc_FF08146C:\n"
        "B       loc_FF08158C\n"
"loc_FF081470:\n"
        "B       loc_FF081594\n"
"loc_FF081474:\n"
        "B       loc_FF081584\n"
"loc_FF081478:\n"
        "B       loc_FF0814B0\n"
"loc_FF08147C:\n"
        "B       loc_FF081480\n"
"loc_FF081480:\n"
        "STR     R6, [R4,#0x40]\n"
        "STR     R6, [R4,#0x34]\n"
        "STR     R7, [R4,#0x148]\n"
        "STRH    R6, [R4,#6]\n"
        "STR     R8, [R4,#0xCC]\n"
        "STR     R9, [R4,#0xE4]\n"
        "LDR     R0, [R4,#0x10]\n"
        "ADD     R0, R0, #1\n"
        "STR     R0, [R4,#0x10]\n"
        "MOV     R0, #6\n"
        "STR     R0, [R4,#0x44]\n"
        "B       loc_FF0814D0\n"
"loc_FF0814B0:\n"
        "STR     R6, [R4,#0x40]\n"
        "STR     R7, [R4,#0x148]\n"
        "STR     R8, [R4,#0xCC]\n"
        "STR     R9, [R4,#0xE4]\n"
        "LDR     R0, [R4,#0x10]\n"
        "ADD     R0, R0, #1\n"
        "STR     R0, [R4,#0x10]\n"
        "STR     R5, [R4,#0x44]\n"
"loc_FF0814D0:\n"
        "STR     R5, [R4,#8]\n"
        "B       loc_FF08159C\n"
"loc_FF0814D8:\n"
        //"BL      sub_FF080B4C\n"
		"BL      movie_time\n"
"label_A:\n"
        "B       loc_FF08159C\n"
"loc_FF0814E0:\n"
        "LDR     R1, [R4,#0xCC]\n"
        "BLX     R1\n"
        "B       loc_FF08159C\n"
"loc_FF0814EC:\n"
        "BL      sub_FF082120\n"
        "B       loc_FF08159C\n"
"loc_FF0814F4:\n"
        "LDR     R0, [R4,#0x44]\n"
        "CMP     R0, #5\n"
        "STRNE   R5, [R4,#0x34]\n"
        "B       loc_FF08159C\n"
"loc_FF081504:\n"
        "BL      sub_FF080178\n"
        "B       loc_FF08159C\n"
"loc_FF08150C:\n"
        "BL      sub_FF080060\n"
        "B       loc_FF08159C\n"
"loc_FF081514:\n"
        "BL      sub_FF07FD44\n"
        "B       loc_FF08159C\n"
"loc_FF08151C:\n"
        "LDR     R1, [R4,#0x94]\n"
        "LDR     R0, =0x4840F640\n"
        "CMP     R1, #0\n"
        "LDREQ   R1, =0xFF07FD08\n"
        "LDREQ   R0, [R4,#0x98]\n"
        "BEQ     loc_FF081540\n"
        "BL      sub_FF1EF898\n"
        "LDR     R1, =0xFF07FD08\n"
        "MOV     R0, #0\n"
"loc_FF081540:\n"
        "BL      sub_FF1EDD14\n"
        "B       loc_FF08159C\n"
"loc_FF081548:\n"
        "LDR     R0, =0x43964\n"
        "LDR     R0, [R0,#8]\n"
        "CMP     R0, #0\n"
        "LDRNE   R2, =0xFF07FC60\n"
        "LDRNE   R0, =0xFF07FCE4\n"
        "MOVNE   R3, #0\n"
        "MOVNE   R1, R3\n"
        "BLNE    sub_FF060640\n"
        "MOV     R0, #3\n"
        "STR     R0, [R4,#0x44]\n"
        "B       loc_FF08159C\n"
"loc_FF081574:\n"
        "BL      sub_FF07ED64\n"
        "B       loc_FF08159C\n"
"loc_FF08157C:\n"
        "BL      sub_FF08202C\n"
        "B       loc_FF08159C\n"
"loc_FF081584:\n"
        //"BL      loc_FF082040\n"
		"BL      sub_FF082040\n"
        "B       loc_FF08159C\n"
"loc_FF08158C:\n"
        "BL      sub_FF07FA5C\n"
        "B       loc_FF08159C\n"
"loc_FF081594:\n"
        "BL      sub_FF07F8DC\n"
        "STR     R5, [R4,#0x144]\n"
"loc_FF08159C:\n"
        "LDR     R1, [SP,#4]\n"
        "LDR     R3, =0x65B\n"
        "STR     R6, [R1]\n"
        "STR     R3, [SP]\n"
        "LDR     R3, =0xFF07E60C \n"
        "LDR     R0, [R4,#0x2C]\n"
        "MOV     R2, R10\n"
        "BL      sub_68B044\n"
        "LDR     R0, [R4,#0x118]\n"
        "BL      sub_68AAEC\n"
        "B       loc_FF0813E4\n"
    );
}

void __attribute__((naked,noinline)) movie_time() {
    if( (int)conf.ext_video_time == 1 ) {
        asm volatile (
          "BL     sub_FF080B4C_my\n"
          "B      label_A\n"
        );
    } else {
        asm volatile (
          "BL     sub_FF080B4C\n"
          "B      label_A\n"
        );
    }
}

void __attribute__((naked,noinline)) sub_FF080B4C_my() {
 asm volatile (
        "STMFD   SP!, {R0-R10,LR}\n"
        "LDR     R6, =0x38B0\n"
        "MOV     R9, #0\n"
        "STR     R9, [R6,#0x34]\n"
        "STR     R9, [R6,#0x38]\n"
        "MOV     R0, R6\n"
        "LDR     R4, [R0,#0x58]\n"
        "LDRH    R1, [R6,#6]\n"
        "MOV     R0, #0x3E8\n"
        "MUL     R0, R4, R0\n"
        "LDR     R8, =0xFFF00\n"
        "CMP     R1, #0\n"
        "MOV     R2, #1\n"
        "BNE     loc_FF080B94\n"
        "LDR     R1, [R6,#0x80]\n"
        "CMP     R1, #0\n"
        "BNE     loc_FF080BA4\n"
        "B       loc_FF080B9C\n"
"loc_FF080B94:\n"
        "CMP     R1, #3\n"
        "BNE     loc_FF080BA4\n"
"loc_FF080B9C:\n"
        "STR     R2, [R6,#0x48]\n"
        "B       loc_FF080BB0\n"
"loc_FF080BA4:\n"
        "MOV     R1, #0x3E8\n"
        "BL      sub_69092C\n"
        "STR     R0, [R6,#0x48]\n"
"loc_FF080BB0:\n"
        "LDR     R5, =0x43964\n"
        "MOV     R7, #2\n"
        "LDR     R0, [R5,#8]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF080C1C\n"
        "CMP     R4, #0x18\n"
        "MOV     R0, #4\n"
        "BEQ     loc_FF080C08\n"
        "BGT     loc_FF080BF0\n"
        "CMP     R4, #0xA\n"
        "CMPNE   R4, #0xF\n"
        "STREQ   R7, [R5,#0x14]\n"
        "BEQ     loc_FF080C1C\n"
        "CMP     R4, #0x14\n"
        "BNE     loc_FF080C10\n"
        "B       loc_FF080C08\n"
"loc_FF080BF0:\n"
        "CMP     R4, #0x19\n"
        "CMPNE   R4, #0x1E\n"
        "BEQ     loc_FF080C08\n"
        "CMP     R4, #0x3C \n"
        "BNE     loc_FF080C10\n"
        "MOV     R0, #8\n"
"loc_FF080C08:\n"
        "STR     R0, [R5,#0x14]\n"
        "B       loc_FF080C1C\n"
"loc_FF080C10:\n"
        "LDR     R1, =0x74C\n"
        "LDR     R0, =0xFF07E60C \n"
        "BL      sub_68B104\n"
"loc_FF080C1C:\n"
        "LDR     R0, [R6,#0x64]\n"
        "CMP     R0, #1\n"
        "BNE     loc_FF080C34\n"
        "BL      sub_FF196354\n"
        "LDR     R0, =0x4397C\n"
        "BL      sub_FF1EA00C\n"
"loc_FF080C34:\n"
        "LDR     R2, =0x38B2\n"
        "LDR     R0, [R6,#0xA4]\n"
        "MOV     R3, #2\n"
        "MOV     R1, #0xAA \n"
        "BL      sub_FF09B5F8\n"
        "LDR     R2, =0x38B4\n"
        "LDR     R0, [R6,#0xA4]\n"
        "MOV     R3, #2\n"
        "MOV     R1, #0xA9 \n"
        "BL      sub_FF09B5F8\n"
        "LDR     R2, =0x3900\n"
        "LDR     R0, [R6,#0xA4]\n"
        "MOV     R3, #4\n"
        "MOV     R1, #0xA2 \n"
        "BL      sub_FF09B5F8\n"
        "LDR     R2, =0x3904\n"
        "LDR     R0, [R6,#0xA4]\n"
        "MOV     R3, #4\n"
        "MOV     R1, #0xA3 \n"
        "BL      sub_FF09B5F8\n"
        "LDR     R0, [R6,#0x80]\n"
        "CMP     R0, #0\n"
        "LDRNE   R2, =0x3A10\n"
        "MOVNE   R1, #0\n"
        "MOVNE   R0, #0xF\n"
        "BLNE    sub_FF0959B8\n"
        "LDR     R0, [R6,#0x4C]\n"
        "LDR     R4, =0x3A10\n"
        "LDR     R10, =0x4394C\n"
        "CMP     R0, #1\n"
        "CMPNE   R0, #2\n"
        "BNE     loc_FF080D68\n"
        "LDR     R0, [R6,#0x80]\n"
        "CMP     R0, #0\n"
        "LDRNE   R0, =0x4A280A60\n"
        "STRNE   R0, [R4]\n"
        "BNE     loc_FF080D80\n"
        "LDR     R1, =0x484B4600\n"
        "LDR     R0, =0x3870600\n"
        "STR     R1, [R4]\n"
        "STR     R0, [R4,#4]\n"
        "LDMIA   R10, {R0,R2}\n"
        "MUL     R0, R2, R0\n"
        "MOV     R3, R0,LSL#1\n"
        "CMP     R3, R8\n"
        "STR     R3, [R6,#0x8C]\n"
        "MOVCC   R2, #0\n"
        "STR     R1, [R6,#0x90]\n"
        "BCC     loc_FF080D30\n"
        "MOV     R2, #0\n"
        "STMEA   SP, {R1,R2,R8}\n"
        "MOV     R3, R2\n"
        "MOV     R2, #9\n"
        "MOV     R1, #5\n"
        "MOV     R0, #0x16\n"
        "BL      sub_FF18E540\n"
        "LDR     R0, [R6,#0x8C]\n"
        "MOV     R2, #0\n"
        "SUB     R3, R0, #0xF0000\n"
        "LDR     R0, [R6,#0x90]\n"
        "SUB     R3, R3, #0xFF00\n"
        "ADD     R1, R0, #0xF0000\n"
        "ADD     R1, R1, #0xFF00\n"
"loc_FF080D30:\n"
        "STMEA   SP, {R1-R3}\n"
        "MOV     R3, #0\n"
        "MOV     R2, #9\n"
        "MOV     R1, #5\n"
        "MOV     R0, #0x16\n"
        "BL      sub_FF18E540\n"
        "LDR     R1, [R4]\n"
        "LDR     R0, [R6,#0x8C]\n"
        "ADD     R1, R1, R0,LSL#1\n"
        "STR     R1, [R4]\n"
        "LDR     R1, [R4,#4]\n"
        "RSB     R0, R0, #0\n"
        "ADD     R0, R1, R0,LSL#1\n"
        "STR     R0, [R4,#4]\n"
"loc_FF080D68:\n"
        "LDR     R0, [R6,#0x80]\n"
        "CMP     R0, #0\n"
        "LDREQ   R0, [R4,#4]\n"
        "LDREQ   R1, [R4]\n"
        "BEQ     loc_FF080DE4\n"
        "LDR     R0, [R4]\n"
"loc_FF080D80:\n"
        "STR     R0, [R6,#0x12C]\n"
        "ADD     R0, R0, #0x800000\n"
        "ADD     R0, R0, #0x19C00\n"
        "STR     R0, [R6,#0x134]\n"
        "ADD     R0, R0, #0x3FC000\n"
        "STR     R0, [R6,#0x124]\n"
        "LDRH    R0, [R6,#6]\n"
        "CMP     R0, #0\n"
        "STRNE   R9, [R6,#0x128]\n"
        "BNE     loc_FF080DB4\n"
        "LDR     R1, =0x39D8\n"
        "LDR     R0, [R5]\n"
        "BL      sub_FF1F014C\n"
"loc_FF080DB4:\n"
        "LDR     R0, [R6,#0x128]\n"
        "LDR     R1, [R6,#0x124]\n"
        "LDR     R2, =0x20F000\n"
        "ADD     R1, R1, R0\n"
        "STR     R1, [R6,#0xEC]\n"
        "ADD     R1, R1, R2\n"
        "ADD     R0, R0, R2\n"
        "STR     R2, [R6,#0xF0]\n"
        "LDR     R2, [R4,#4]\n"
        "SUB     R0, R2, R0\n"
        "SUB     R0, R0, #0xC00000\n"
        "SUB     R0, R0, #0x15C00\n"
"loc_FF080DE4:\n"
        "LDR     R2, =0x43964\n"
        "LDR     R3, =0xFF080B18\n"
        "STRD    R2, [SP]\n"
        "SUB     R3, R2, #0x18\n"
        "MOV     R2, R0\n"
        "LDR     R0, [R6,#0x80]\n"
        //"BL      sub_FF1ED0C0\n"
        "BL      sub_FF1ED0C0_my\n"

		
		"LDR     R0, [R6,#0x158]\n"
        "LDR     R1, [R6,#0x15C]\n"
        "LDR     R2, [R6,#0xA4]\n"
        "BL      sub_FF1ED6FC\n"
        "LDR     R3, =0x3928\n"
        "STR     R3, [SP]\n"
        "LDR     R0, [R6,#0x64]\n"
        "LDR     R1, [R10,#8]\n"
        "AND     R2, R0, #0xFF\n"
        "LDR     R0, [R10]\n"
        "SUB     R3, R3, #4\n"
        "BL      sub_FF1E9B68\n"
        "LDRH    R0, [R6,#6]\n"
        "CMP     R0, #2\n"
        "LDREQ   R0, =0xFF080818\n"
        "STREQ   R0, [R6,#0xCC]\n"
        "LDR     R0, [R6,#0x80]\n"
        "CMP     R0, #0\n"
        "LDREQ   R1, =0xFF080460\n"
        "STREQ   R1, [R6,#0xCC]\n"
        "LDR     R2, [R6,#0x10]\n"
        "LDR     R1, =0xFF49F03C\n"
        "CMP     R2, #2\n"
        "BNE     loc_FF080E84\n"
        "LDR     R0, [R6,#0x4C]\n"
        "ADD     R0, R1, R0,LSL#3\n"
        "LDR     R1, [R10,#0xC]\n"
        "LDR     R0, [R0,R1,LSL#2]\n"
        "BL      sub_FF1940F0\n"
        "LDR     R0, =0xFF080454\n"
        "MOV     R1, #0\n"
        "BL      sub_FF19467C\n"
        "B       loc_FF080EBC\n"
"loc_FF080E84:\n"
        "CMP     R0, #0\n"
        "LDR     R0, [R6,#0x4C]\n"
        "ADD     R0, R1, R0,LSL#3\n"
        "LDR     R1, [R10,#0xC]\n"
        "LDR     R0, [R0,R1,LSL#2]\n"
        "BNE     loc_FF080EAC\n"
        "LDR     R1, [R6,#0x88]\n"
        "BL      sub_FF19475C\n"
        "BL      sub_FF1947E0\n"
        "B       loc_FF080EBC\n"
"loc_FF080EAC:\n"
        "BL      sub_FF192290\n"
        "LDR     R0, =0xFF07EED0\n"
        "MOV     R1, #0\n"
        "BL      sub_FF192AEC\n"
"loc_FF080EBC:\n"
        "LDR     R0, [R5,#8]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF080EF0\n"
        "ADD     R0, SP, #0xC\n"
        "BL      sub_FF1EE940\n"
        "LDR     R1, [R5,#0xC]\n"
        "LDR     R0, [SP,#0xC]\n"
        "BL      sub_FF0608AC\n"
        "ADD     R0, SP, #0xC\n"
        "BL      sub_FF1EE940\n"
        "LDR     R1, [R5,#0xC]\n"
        "LDR     R0, [SP,#0xC]\n"
        "BL      sub_FF0608AC\n"
"loc_FF080EF0:\n"
        "STR     R7, [R6,#0x44]\n"
        "LDMFD   SP!, {R0-R10,PC}\n"

        );
}

void __attribute__((naked,noinline)) sub_FF1ED0C0_my(){
asm volatile (
        "STMFD   SP!, {R0-R11,LR}\n"
        "MOV     R9, R0\n"
        "LDR     R0, [R3,#0x10]\n"
        "SUB     SP, SP, #4\n"
        "CMP     R0, #0\n"
        "LDR     R7, [SP,#0x38]\n"
        "LDREQ   R1, =0x3B7\n"
        "LDREQ   R0, =0xFF1EA678 \n"
        "MOV     R6, #0\n"
        "MOV     R4, R3\n"
        "MOV     R5, R6\n"
        "BLEQ    sub_68B104\n"
        "LDR     R8, =0x9B38\n"
        "CMP     R9, #0\n"
        "MOV     R11, #0\n"
        "STR     R9, [R8,#0xA0]\n"
        "MOVEQ   R0, #1\n"
        "STRNE   R11, [R8,#0xE8]\n"
        "STREQ   R0, [R8,#0xE8]\n"
        "LDR     R0, [R4]\n"
        "LDR     R3, =0x61A8\n"
        "STR     R0, [R8,#0xF0]\n"
        "LDR     R0, [R4,#4]\n"
        "LDR     R1, =0x7530\n"
        "STR     R0, [R8,#0xF4]\n"
        "LDR     R0, [R4,#0x10]\n"
        "MOV     R2, #0x18\n"
        "STR     R0, [R8,#0x100]\n"
        "LDR     R9, [R4,#8]\n"
        "LDR     R0, =0x3E9\n"
        "CMP     R9, #0xF\n"
        "MOV     R12, #0x3E8\n"
        "MOV     R10, #0x1E\n"
        "ADDCC   PC, PC, R9,LSL#2\n"
        "B       loc_FF1ED218\n"
"loc_FF1ED14C:\n"
        "B       loc_FF1ED1A0\n"
"loc_FF1ED150:\n"
        "B       loc_FF1ED198\n"
"loc_FF1ED154:\n"
        "B       loc_FF1ED188\n"
"loc_FF1ED158:\n"
        "B       loc_FF1ED1F4\n"
"loc_FF1ED15C:\n"
        "B       loc_FF1ED204\n"
"loc_FF1ED160:\n"
        "B       loc_FF1ED218\n"
"loc_FF1ED164:\n"
        "B       loc_FF1ED218\n"
"loc_FF1ED168:\n"
        "B       loc_FF1ED218\n"
"loc_FF1ED16C:\n"
        "B       loc_FF1ED218\n"
"loc_FF1ED170:\n"
        "B       loc_FF1ED1C0\n"
"loc_FF1ED174:\n"
        "B       loc_FF1ED1B8\n"
"loc_FF1ED178:\n"
        "B       loc_FF1ED1B0\n"
"loc_FF1ED17C:\n"
        "B       loc_FF1ED1EC\n"
"loc_FF1ED180:\n"
        "B       loc_FF1ED1E4\n"
"loc_FF1ED184:\n"
        "B       loc_FF1ED1D0\n"
"loc_FF1ED188:\n"
        "LDR     R5, =0x5DC0\n"
        "STR     R2, [R8,#0xF8]\n"
        "STR     R5, [R8,#0x154]\n"
        "B       loc_FF1ED1A8\n"
"loc_FF1ED198:\n"
        "MOV     R5, R3\n"
        "B       loc_FF1ED1D4\n"
"loc_FF1ED1A0:\n"
        "MOV     R5, R1\n"
        "B       loc_FF1ED1C4\n"
"loc_FF1ED1A8:\n"
        "STR     R0, [R8,#0x158]\n"
        "B       loc_FF1ED224\n"
"loc_FF1ED1B0:\n"
        "LDR     R5, =0x5DC\n"
        "B       loc_FF1ED1C4\n"
"loc_FF1ED1B8:\n"
        "LDR     R5, =0xBB8\n"
        "B       loc_FF1ED1C4\n"
"loc_FF1ED1C0:\n"
        "LDR     R5, =0x1770\n"
"loc_FF1ED1C4:\n"
        "STR     R1, [R8,#0x154]\n"
        "STR     R10, [R8,#0xF8]\n"
        "B       loc_FF1ED1A8\n"
"loc_FF1ED1D0:\n"
        "LDR     R5, =0x4E2\n"
"loc_FF1ED1D4:\n"
        "STR     R2, [R8,#0xF8]\n"
        "STR     R3, [R8,#0x154]\n"
        "STR     R12, [R8,#0x158]\n"
        "B       loc_FF1ED224\n"
"loc_FF1ED1E4:\n"
        "LDR     R5, =0x9C4\n"
        "B       loc_FF1ED1D4\n"
"loc_FF1ED1EC:\n"
        "LDR     R5, =0x1388\n"
        "B       loc_FF1ED1D4\n"
"loc_FF1ED1F4:\n"
        "STR     R1, [R8,#0x154]\n"
      
	  //"LDR     R5, =0x3A980\n"
        "LDR     R5, =0x57600000\n"         //2hrs, orignal 0x3A980
		
	  //"MOV     R1, #0xF0 \n"
        "MOV     R1, #240\n"                //original 0xF0
	    
		"B       loc_FF1ED210\n"
"loc_FF1ED204:\n"
        
		//"LDR     R5, =0x1D4C0\n"
        "LDR     R5, =0x28800000\n"         //2hrs, original 0x1D4C0
		
		"STR     R1, [R8,#0x154]\n"
        "MOV     R1, #0x78 \n"
"loc_FF1ED210:\n"
        "STR     R1, [R8,#0xF8]\n"
        "B       loc_FF1ED1A8\n"
"loc_FF1ED218:\n"
        "LDR     R1, =0x411\n"
        "LDR     R0, =0xFF1EA678 \n"
        "BL      sub_68B104\n"
"loc_FF1ED224:\n"
        "LDR     R0, [R8,#0xF8]\n"
       
	//	"LDR     R1, =0xE0F\n"
        "LDR     R1, =7200\n"               //2hrs, original 0xE0F

		"MOV     R0, R0,LSR#1\n"
        "STR     R0, [R8,#0xFC]\n"
        "LDR     R0, [R7]\n"
        "STR     R0, [R8,#0x104]\n"
        "LDRH    R0, [R7,#0x10]\n"
        "STR     R0, [R8,#0x108]\n"
        "LDR     R0, [R7,#4]\n"
        "STRH    R0, [R8,#2]\n"
        "LDR     R0, [R7,#8]\n"
        "STRH    R0, [R8,#4]\n"
        "LDR     R0, [R7,#0x14]\n"
        "STR     R0, [R8,#0x10C]\n"
        "LDR     R0, [SP,#0x3C]\n"
        "STR     R0, [R8,#0x150]\n"
        "LDR     R0, [R8,#0xF0]\n"
        "CMP     R0, #0x140\n"
        "MOVEQ   R0, #0x20000\n"
        "MOVEQ   R6, #1\n"
        "STREQ   R0, [R8,#0xC4]\n"
        "BEQ     loc_FF1ED2BC\n"
        "CMP     R0, #0x280\n"
        "LDREQ   R0, =0x7A760\n"
        "MOVEQ   R6, #2\n"
        "STREQ   R0, [R8,#0xC4]\n"
        "BEQ     loc_FF1ED2BC\n"
        "CMP     R0, #0x500\n"
        "LDREQ   R0, =0x11DA50\n"
        
		//"LDR     R1, =0x707\n"
        "LDR     R1, =7200\n"               //2hrs, original 0x707
		
		"MOVEQ   R6, #4\n"
        "STREQ   R0, [R8,#0xC4]\n"
        "BEQ     loc_FF1ED2BC\n"
        "CMP     R0, #0x780\n"
        "BNE     loc_FF1ED2C4\n"
        
		//"MOV     R0, #0x200000\n"
		"MOV     R0, #2097152\n"            //10mins, original 0x200000
		
        "MOV     R6, #5\n"
        "STR     R0, [R8,#0xC4]\n"
"loc_FF1ED2BC:\n"
        "STR     R1, [R8,#0x58]\n"
        "B       loc_FF1ED2D0\n"
"loc_FF1ED2C4:\n"
        "LDR     R1, =0x439\n"
        "LDR     R0, =0xFF1EA678 \n"
        "BL      sub_68B104\n"
"loc_FF1ED2D0:\n"
        "LDR     R9, [R4,#8]\n"
        "CMP     R9, #0xB\n"
        "CMPNE   R9, #0xA\n"
        "CMPNE   R9, #9\n"
        "BNE     loc_FF1ED304\n"
        "LDR     R0, [R8,#0xF0]\n"
        "CMP     R0, #0x500\n"
        "BNE     loc_FF1ED304\n"
        "LDR     R0, [R8,#0x58]\n"
        "LDR     R1, [R8,#0x158]\n"
        "MUL     R0, R5, R0\n"
        "BL      sub_69092C\n"
        "B       loc_FF1ED324\n"
"loc_FF1ED304:\n"
        "LDR     R0, [R8,#0x58]\n"
        "LDR     R1, [R8,#0x158]\n"
        "MUL     R0, R5, R0\n"
        "BL      sub_69092C\n"
        "MOV     R1, #5\n"
        "BL      sub_69092C\n"
        "ADD     R0, R0, #1\n"
        "ADD     R0, R0, R0,LSL#2\n"
"loc_FF1ED324:\n"
        "CMP     R9, #0xB\n"
        "CMPNE   R9, #0xA\n"
        "CMPNE   R9, #9\n"
        "STR     R0, [R8,#0x54]\n"
        "BNE     loc_FF1ED34C\n"
        "LDR     R1, [R8,#0x158]\n"
        "MUL     R0, R1, R0\n"
        "MOV     R1, R5\n"
        "BL      sub_69092C\n"
        "STR     R0, [R8,#0x58]\n"
"loc_FF1ED34C:\n"
        "CMP     R9, #3\n"
        "CMPNE   R9, #4\n"
        "BNE     loc_FF1ED384\n"
        "RSB     R0, R5, R5,LSL#4\n"
        "STR     R10, [R8,#0x58]\n"
        "LDR     R1, [R8,#0x158]\n"
        "MOV     R0, R0,LSL#1\n"
        "BL      sub_69092C\n"
        "LDR     R1, [R8,#0x100]\n"
        "MOV     R10, R1\n"
        "BL      sub_69092C\n"
        "ADD     R0, R0, #1\n"
        "MUL     R0, R10, R0\n"
        "STR     R0, [R8,#0x54]\n"
"loc_FF1ED384:\n"
        "ADD     R0, R5, R5,LSL#8\n"
        "LDR     R1, [R8,#0x158]\n"
        "RSB     R0, R0, R0,LSL#3\n"
        "BL      sub_69092C\n"
        "STR     R0, [R8,#0x88]\n"
        "LDR     R0, [R4,#0xC]\n"
        "CMP     R0, #0\n"
        "MOVNE   R0, #1\n"
        "STR     R0, [SP]\n"
        "LDR     R5, [R7,#0xC]\n"
        "MOV     R0, R5,LSR#1\n"
        "STR     R5, [R8,#0xAC]\n"
        "STR     R0, [R8,#0xB0]\n"
        "LDR     R0, [SP,#8]\n"
        "ADD     R0, R0, #3\n"
        "BIC     R1, R0, #3\n"
        "STR     R1, [R8,#0x114]\n"
        "LDR     R0, [R8,#0x54]\n"
        "MOV     R0, R0,LSL#2\n"
        "ADD     R1, R1, R0\n"
        "STR     R1, [R8,#0x118]\n"
        "LDRH    R7, [R8,#4]\n"
        "LDR     R2, [SP,#0xC]\n"
        "LDR     R3, [SP,#8]\n"
        "CMP     R7, #0\n"
        "ADD     R10, R3, R2\n"
        "BEQ     sub_FF1ED654\n"
        "ADD     R9, R1, R0\n"
        "STR     R9, [R8,#0x11C]\n"
        "LDR     R1, [R8,#0xFC]\n"
        "BL      sub_69092C\n"
        "ADD     R0, R0, R9\n"
        "ADD     R0, R0, #0x1F\n"
        "BIC     R0, R0, #0x1F\n"
        "STR     R0, [R8,#0x120]\n"
        "LDR     R1, [R8,#0xE8]\n"
        "CMP     R1, #0\n"
        "BEQ     sub_FF1ED4E8\n"
        "LDR     R2, [R8,#0xC4]\n"
        "ADD     R0, R0, R2\n"
        "B       sub_FF1ED4A8\n"

        );
}
	
	void __attribute__((naked,noinline)) sub_FF080EFC_my(){
asm volatile (
        "STMFD   SP!, {R4-R8,LR}\n"
        "SUB     SP, SP, #0x50\n"
        "MOV     R8, #0\n"
        "LDR     R5, =0x38B0\n"
        "STR     R8, [SP,#0x40]\n"
        "STR     R8, [SP,#0x38]\n"
        "STR     R8, [R5,#0xC4]\n"
        "LDR     R1, [R5,#0x44]\n"
        "MOV     R4, R0\n"
        "CMP     R1, #3\n"
        "MOV     R6, R8\n"
        "MOV     R7, #1\n"
        "BNE     loc_FF080F54\n"
        "LDR     R0, [R5,#0x148]\n"
        "LDR     R1, [R5,#0x14C]\n"
        "CMP     R0, R1\n"
        "BNE     loc_FF0810E0\n"
        "MOV     R0, #4\n"
        "STR     R0, [R5,#0x44]\n"
        //"MOV     R0, 0xFFFFFFFF\n"
        "MVN     R0, #0\n"
		"STR     R0, [R5,#0x148]\n"
        "B       loc_FF080F5C\n"
"loc_FF080F54:\n"
        "CMP     R1, #4\n"
        "BNE     loc_FF0810E0\n"
"loc_FF080F5C:\n"
        "LDRH    R0, [R5,#6]\n"
        "CMP     R0, #3\n"
        "BNE     loc_FF080F94\n"
        "LDR     R0, [R5,#0xC8]\n"
        "CMP     R0, #0\n"
        "LDREQ   R1, =0x86B\n"
        "LDREQ   R0, =0xFF07E60C \n"
        "BLEQ    sub_68B104\n"
        "LDR     R0, [R5,#0x6C]\n"
        "LDR     R1, [R5,#0xC8]\n"
        "BL      sub_69092C\n"
        "CMP     R1, #0\n"
        "MOVNE   R7, #0\n"
        "BNE     loc_FF080FB0\n"
"loc_FF080F94:\n"
        "ADD     R3, SP, #0x38\n"
        "ADD     R2, SP, #0x3C\n"
        "ADD     R1, SP, #0x40\n"
        "ADD     R0, SP, #0x44\n"
        "BL      sub_FF1EED94\n"
        "MOVS    R8, R0\n"
        "BNE     loc_FF080FCC\n"
"loc_FF080FB0:\n"
        "LDR     R0, [R5,#0x34]\n"
        "CMP     R0, #1\n"
        "BNE     loc_FF0810E8\n"
        "LDR     R0, [R5,#0x6C]\n"
        "LDR     R1, [R5,#0x48]\n"
        "CMP     R0, R1\n"
        "BCC     loc_FF0810E8\n"
"loc_FF080FCC:\n"
        "MOV     R0, R8\n"
        "BL      sub_FF07EEF4\n"
        "BL      sub_FF08202C\n"
        "LDR     R2, [R5,#0x64]\n"
        "ADD     R3, SP, #0x48\n"
        //"MOV     R1, 0xFFFFFFFE\n"
        "MVN     R1, #0\n"
		"MOV     R0, #0\n"
        "ADD     R7, SP, #0x1C\n"
        "STMIA   R7, {R0-R3}\n"
        "LDR     R3, [R4,#0x1C]\n"
        "LDR     R1, [R5,#0x74]\n"
        "LDR     R2, [R5,#0x78]\n"
        "ADD     R0, SP, #0x4C\n"
        "ADD     R4, SP, #0xC\n"
        "STMIA   R4, {R0-R3}\n"
        "MOV     R3, #0\n"
        "MOV     R1, #0x40 \n"
        "STMEA   SP, {R1,R3}\n"
        "MOV     R2, #0\n"
        "STR     R3, [SP,#8]\n"
        "LDR     R3, =0x43A1C\n"
        "MOV     R1, R2\n"
        "MOV     R0, R2\n"
        "BL      sub_FF192968\n"
        "LDR     R0, [R5,#0x1C]\n"
        "LDR     R1, [R5,#0x60]\n"
        "BL      sub_68AA1C\n"
        "CMP     R0, #9\n"
        "BNE     loc_FF0810B4\n"
"loc_FF081040:\n"
        "MOV     R1, #1\n"
        "B       loc_FF081208\n"
"loc_FF0810B4:\n"
        "LDR     R0, [SP,#0x48]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF0810C8\n"
"loc_FF0810C0:\n"
        "MOV     R1, #1\n"
        "B       loc_FF081220\n"
"loc_FF0810C8:\n"
        "MOV     R0, #1\n"
        "BL      sub_FF192A14\n"
        "BL      sub_FF192AC0\n"
        "MOV     R0, #5\n"
        "STR     R6, [R5,#0x34]!\n"
        "STR     R0, [R5,#0x10]\n"
"loc_FF0810E0:\n"
        "ADD     SP, SP, #0x50\n"
        "LDMFD   SP!, {R4-R8,PC}\n"
"loc_FF0810E8:\n"
        "CMP     R7, #1\n"
        "BNE     loc_FF081334\n"
        "MOV     R0, #1\n"
        "STR     R0, [R5,#0x38]\n"
        "LDR     R0, [R5,#0x6C]\n"
        "LDR     R7, [R4,#0xC]\n"
        "CMP     R0, #0\n"
        "LDRNE   R8, [SP,#0x40]\n"
        "LDRNE   R12, [SP,#0x44]\n"
        "BNE     loc_FF0811A0\n"
        "LDR     R0, [R4,#0x20]\n"
        "LDR     R2, [R5,#0x64]\n"
        "ADD     R3, SP, #0x48\n"
        //"MOV     R1, 0xFFFFFFFF\n"
        "MVN     R1, #0\n"
		"ADD     R8, SP, #0x1C\n"
        "STMIA   R8, {R0-R3}\n"
        "LDR     R3, [R4,#0x1C]\n"
        "LDR     R1, [R5,#0x74]\n"
        "LDR     R2, [R5,#0x78]\n"
        "ADD     R0, SP, #0x4C\n"
        "ADD     R8, SP, #0xC\n"
        "STMIA   R8, {R0-R3}\n"
        "LDR     R1, [SP,#0x3C]\n"
        "LDR     R2, [SP,#0x40]\n"
        "LDR     R3, [SP,#0x38]\n"
        "STMFA   SP, {R1,R3}\n"
        "STR     R2, [SP]\n"
        "LDMIB   R4, {R0,R1}\n"
        "LDR     R3, [SP,#0x44]\n"
        "MOV     R2, R7\n"
        "BL      sub_FF192968\n"
        "LDR     R0, [R5,#0x1C]\n"
        "LDR     R1, [R5,#0x60]\n"
        "BL      sub_68AA1C\n"
        "CMP     R0, #9\n"
        "BEQ     loc_FF081040\n"
        "LDR     R0, [SP,#0x48]\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF0810C0\n"
        "MOV     R0, #1\n"
        "BL      sub_FF192A14\n"
        "LDR     R0, [SP,#0x4C]\n"
        "LDR     R1, [SP,#0x44]\n"
        "ADD     R12, R1, R0\n"
        "LDR     R1, [SP,#0x40]\n"
        "SUB     R8, R1, R0\n"
"loc_FF0811A0:\n"
        "LDR     R0, [R4,#0x20]\n"
        "LDR     R1, [R5,#0x68]\n"
        "LDR     R2, [R5,#0x64]\n"
        "ADD     R3, SP, #0x48\n"
        "ADD     LR, SP, #0x1C\n"
        "STMIA   LR, {R0-R3}\n"
        "LDR     R3, [R4,#0x1C]\n"
        "LDR     R1, [R5,#0x74]\n"
        "LDR     R2, [R5,#0x78]\n"
        "ADD     R0, SP, #0x4C\n"
        "ADD     LR, SP, #0xC\n"
        "STMIA   LR, {R0-R3}\n"
        "LDR     R2, [SP,#0x3C]\n"
        "LDR     R3, [SP,#0x38]\n"
        "STMFA   SP, {R2,R3}\n"
        "STR     R8, [SP]\n"
        "LDMIB   R4, {R0,R1}\n"
        "MOV     R3, R12\n"
        "MOV     R2, R7\n"
        "BL      sub_FF192968\n"
        "LDR     R0, [R5,#0x1C]\n"
        "LDR     R1, [R5,#0x60]\n"
        "BL      sub_68AA1C\n"
        "CMP     R0, #9\n"
        "BNE     loc_FF081210\n"
        "MOV     R1, #0\n"
"loc_FF081208:\n"
        "MOV     R0, #0x90000\n"
        "B       loc_FF081224\n"
"loc_FF081210:\n"
        "LDR     R0, [SP,#0x48]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF08122C\n"
        "MOV     R1, #0\n"
"loc_FF081220:\n"
        "MOV     R0, #0xA0000\n"
"loc_FF081224:\n"
        "BL      sub_FF07EE44\n"
        "B       loc_FF0810E0\n"
"loc_FF08122C:\n"
        "MOV     R0, #0\n"
        "BL      sub_FF192A14\n"
        "LDR     R0, [R5,#0x144]\n"
        "CMP     R0, #1\n"
        "BNE     loc_FF0812BC\n"
        "LDR     R0, [R5,#0x68]\n"
        "LDR     R1, [R5,#0x64]\n"
        "BL      sub_69092C\n"
        "MOVS    R4, R1\n"
        "STREQ   R6, [R5,#0x144]\n"
        "BEQ     loc_FF0812BC\n"
        "LDR     R7, [SP,#0x44]\n"
        "MOV     R2, #4\n"
        "ADD     R1, R7, #4\n"
        "ADD     R0, SP, #0x34\n"
        "BL      sub_690174\n"
        "LDR     R0, [SP,#0x34]\n"
        "MOV     R1, R0,LSR#24\n"
        "AND     R2, R0, #0xFF0000\n"
        "ORR     R1, R1, R2,LSR#8\n"
        "AND     R2, R0, #0xFF00\n"
        "ORR     R1, R1, R2,LSL#8\n"
        "ORR     R0, R1, R0,LSL#24\n"
        "BIC     R0, R0, #0x1E000\n"
        "ORR     R0, R0, R4,LSL#13\n"
        "MOV     R1, R0,LSR#24\n"
        "AND     R2, R0, #0xFF0000\n"
        "ORR     R1, R1, R2,LSR#8\n"
        "AND     R2, R0, #0xFF00\n"
        "ORR     R1, R1, R2,LSL#8\n"
        "ORR     R0, R1, R0,LSL#24\n"
        "STR     R0, [SP,#0x34]\n"
        "MOV     R2, #4\n"
        "ADD     R1, SP, #0x34\n"
        "ADD     R0, R7, #4\n"
        "BL      sub_690174\n"
"loc_FF0812BC:\n"
        "LDR     R0, [SP,#0x44]\n"
        "LDR     R1, [SP,#0x4C]\n"
        "BL      sub_FF1EF00C\n"
        "LDR     R0, [R5,#0x68]\n"
        "LDR     R3, =0x3928\n"
        "ADD     R1, R0, #1\n"
        "STR     R1, [R5,#0x68]\n"
        "LDR     R0, [SP,#0x4C]\n"
        "SUB     R2, R3, #4\n"
        "BL      sub_FF1E9D24\n" // PreCompresionCall

 		"LDR	R0, =0x3924\n" // +++++++++ found @FF080764 + FF080774
		"BL		set_quality\n" // +++++++++
		
		"LDR     R0, [R5,#0x64]\n"
        "CMP     R0, #1\n"
        "BNE     loc_FF081340\n"
        "ADD     R0, SP, #0x30\n"
        "BL      sub_FF1963C4\n"
        "LDR     R1, =0x4394C\n"
        "LDR     R0, [R1,#4]\n"
        "LDR     R1, [R1]\n"
        "SUB     R2, R0, #0x400\n"
        "SUBS    R2, R2, #0x38\n"
        "ADDEQ   R0, R0, #8\n"
        "MOV     R1, R1,LSR#4\n"
        "MOV     R0, R0,LSR#4\n"
        "MUL     R1, R0, R1\n"
        "LDR     R0, [SP,#0x30]\n"
        "BL      sub_69092C\n"
        "LDR     R1, =0x4397C\n"
        "STR     R0, [SP,#0x30]\n"
        "BL      sub_FF1EA060\n"
        "B       loc_FF081340\n"
"loc_FF081334:\n"
        "LDRH    R0, [R5,#6]\n"
        "CMP     R0, #3\n"
        "BNE     loc_FF0810E0\n"
"loc_FF081340:\n"
        "LDR     R0, [R5,#0x6C]\n"
        "ADD     R0, R0, #1\n"
        "STR     R0, [R5,#0x6C]\n"
        "LDRH    R1, [R5,#6]\n"
        "CMP     R1, #3\n"
        "LDRNE   R1, [R5,#0x54]\n"
        "MULNE   R0, R1, R0\n"
        "LDRNE   R1, [R5,#0x50]\n"
        "BNE     loc_FF081380\n"
        "LDR     R1, [R5,#0x58]\n"
        "CMP     R1, #0x19\n"
        "LDRNE   R1, =0x3E9\n"
        "MOVEQ   R1, #0x3E8\n"
        "MUL     R0, R1, R0\n"
        "LDRNE   R1, =0x1770\n"
        "LDREQ   R1, =0x1388\n"
"loc_FF081380:\n"
        "BL      sub_69092C\n"
        "MOV     R4, R0\n"
        "BL      sub_FF1EF6CC\n"
        "LDR     R0, [R5,#0x7C]\n"
        "CMP     R0, R4\n"
        "BNE     loc_FF0813A4\n"
        "LDR     R0, [R5,#0x3C]\n"
        "CMP     R0, #1\n"
        "BNE     loc_FF0813B8\n"
"loc_FF0813A4:\n"
        "LDR     R1, [R5,#0xA8]\n"
        "MOV     R0, R4\n"
        "BLX     R1\n"
        "STR     R4, [R5,#0x7C]\n"
        "STR     R6, [R5,#0x3C]\n"
"loc_FF0813B8:\n"
        "STR     R6, [R5,#0x38]\n"
        "B       loc_FF0810E0\n"

		    );
}

