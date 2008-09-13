#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[56]={
0x10000,0xC000,0x5800, 0x2000, 0x1C6A, 0x1550,0x9C5,  0x38D,  0x3C45, 0x2D34, 0x14B8, 0x788,  0x5F60, 0x4788,
0x20C9, 0xBE1, 0x8661, 0x64C9, 0x2E31, 0x10CB,0xB21A, 0x8594, 0x3D39, 0x1642, 0xE249, 0xA9B8, 0x4DC9, 0x1C48,
0x117D2,0xD1DF,0x6030, 0x22F9, 0x153D5,0xFEE1,0x74D1, 0x2A79, 0x195F8,0x1307C,0x8B8D, 0x32AA, 0x1E01C,0x16817,
0xA509, 0x3C01,0x2328E,0x1A5ED,0xC160, 0x4637,0x28C99,0x1E975,0xE054, 0x5190, 0x2F08B,0x2346B,0x102AF,0x5E0E
};

long def_table2[12]={0xE666,0xACCD,0x4F33,0x1CCD,-0x170A,-0x1148,-0x7EB,-0x2E1,-0x2BC6,-0x20D5,-0xF0C,-0x579};

long table1[56], table2[12];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<56;i++) table1[i]=(def_table1[i]*a)/b;
 for (i=0;i<12;i++) table2[i]=(def_table2[i]*a)/b;
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};


void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                "STMFD   SP!, {R4,LR}\n"              
                "SUB     SP, SP, #4\n"                
                "MOV     R4, SP\n"                    
                "B       loc_FF953CDC\n"              
"loc_FF953C08:\n"                                      
                "LDR     R3, =0x5C960\n"              
                "LDR     R2, [R3]\n"                  
                "CMP     R2, #0\n"                    
                "BNE     loc_FF953CA4\n"              
                "SUB     R3, R12, #1\n"               
                "CMP     R3, #0xA\n"                  
                "LDRLS   PC, [PC,R3,LSL#2]\n"         
                "B       loc_FF953CA4\n"              
                ".long loc_FF953C54\n"
                ".long loc_FF953C5C\n"
                ".long loc_FF953C74\n"
                ".long loc_FF953C7C\n"
                ".long loc_FF953C84\n"
                ".long loc_FF953C64\n"
                ".long loc_FF953C8C\n"
                ".long loc_FF953C6C\n"
                ".long loc_FF953CA4\n"
                ".long loc_FF953C9C\n"
                ".long loc_FF953C94\n"
"loc_FF953C54:\n"                                      
                                                  
                "BL      sub_FF953D70\n"              
                "B       loc_FF953CA0\n"              
"loc_FF953C5C:\n"                                      
                                                  
                "BL      sub_FF953FC4\n"
                "B       loc_FF953CA0\n"              
"loc_FF953C64:\n"                                      
                                                  
                "BL      sub_FF954478_my\n"   //------------->           
                "B       loc_FF953CA0\n"              
"loc_FF953C6C:\n"                                      
                                                  
                "BL      sub_FF954910\n"              
                "B       loc_FF953CA0\n"              
"loc_FF953C74:\n"                                      
                                                  
                "BL      sub_FF9546E0\n"              
                "B       loc_FF953CA0\n"              
"loc_FF953C7C:\n"                                      
                                                  
                "BL      sub_FF954C28\n"              
                "B       loc_FF953CA0\n"              
"loc_FF953C84:\n"                                      
                                                  
                "BL      sub_FF954DEC\n"              
                "B       loc_FF953CA0\n"              
"loc_FF953C8C:\n"                                      
                                                  
                "BL      sub_FF954ADC\n"              
                "B       loc_FF953CA0\n"              
"loc_FF953C94:\n"                                      
                                                  
                "BL      sub_FF954BBC\n"              
                "B       loc_FF953CA0\n"              
"loc_FF953C9C:\n"                                      
                                                  
                "BL      sub_FF954730\n"              
"loc_FF953CA0:\n"                                      
                                                  
                "LDR     R1, [SP]\n"                  
"loc_FF953CA4:\n"                                      
                                                  
                "LDR     R3, [R1]\n"                  
                "CMP     R3, #9\n"                    
                "BNE     loc_FF953CBC\n"              
                "MOV     R0, R1\n"                    
                "BL      sub_FF954F7C\n"    
                "LDR     R1, [SP]\n"                  
"loc_FF953CBC:\n"                                      
                "LDR     R3, =0x5C890\n"              
                "MOV     R2, #0\n"                    
                "LDR     R0, [R3]\n"                  
                "STR     R2, [R1]\n"                  
                "BL      sub_FF82134C\n"          
                "LDR     R3, =0x5CA30\n"              
                "LDR     R0, [R3]\n"                  
                "BL      sub_FF821D54\n"             
"loc_FF953CDC:\n"                                      
                "LDR     R3, =0x5C88C\n"              
                "MOV     R1, R4\n"                    
                "LDR     R0, [R3]\n"                  
                "MOV     R2, #0\n"                    
                "BL      sub_FF820F34\n"       
                "LDR     R3, =0x5CA30\n"              
                "MOV     R1, #0\n"                    
                "LDR     R0, [R3]\n"                  
                "BL      sub_FF821B6C\n"             
                "LDR     R0, [SP]\n"                  
                "LDR     R12, [R0]\n"                 
                "CMP     R12, #0xC\n"                 
                "MOV     R1, R0\n"                    
                "BNE     loc_FF953C08\n"              
                "LDR     R3, =0x5C884\n"              
                "LDR     R0, [R3]\n"                  
                "BL      sub_FF821D54\n"             
                "BL      sub_FF82275C\n"                  
                "ADD     SP, SP, #4\n"                
                "LDMFD   SP!, {R4,PC}\n"              
 );
}


void __attribute__((naked,noinline)) sub_FF954478_my(){
 asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n"           
                "LDR     R5, =0x5C97C\n"              
                "SUB     SP, SP, #0x1C\n"             
                "LDR     R3, [R5]\n"                  
                "CMP     R3, #3\n"                    
                "MOV     R4, R0\n"                    
                "MOVEQ   R3, #4\n"                    
                "STREQ   R3, [R5]\n"                  
                "LDR     R3, =0x5CA24\n"              
                "MOV     LR, PC\n"                    
                "LDR     PC, [R3]\n"                  
                "LDR     R2, [R5]\n"                  
                "CMP     R2, #4\n"                    
                "BNE     loc_FF954610\n"              
                "ADD     R0, SP, #0x18\n"             
                "BL      sub_FF9567E4_my\n"   //------------------->          
                "CMP     R0, #0\n"                    
                "BNE     loc_FF9544E8\n"              
                "LDR     R3, =0x5C968\n"              
                "LDR     R2, [R3]\n"                  
                "CMP     R2, #1\n"                    
                "BNE     loc_FF954504\n"              
                "LDR     R2, =0x5C9B8\n"              
                "LDR     R1, =0x5C990\n"              
                "LDR     R12, [R2]\n"                 
                "LDR     R3, [R1]\n"                  
                "CMP     R12, R3\n"                   
                "BCC     loc_FF954504\n"              
"loc_FF9544E8:\n"                                     
                "BL      sub_FF954658\n"              
                "LDR     R3, =0x5684\n"               
                "LDR     R0, [R3]\n"                  
                "BL      sub_FF8319D0\n"              
                "MOV     R3, #5\n"                    
                "STR     R3, [R5]\n"                  
                "B       loc_FF954610\n"              
"loc_FF954504:\n"                                     
                                                  
                "LDR     R0, [R4,#4]\n"               
                "LDR     R5, [R4,#0xC]\n"             
                "LDR     R3, =0x5C9C0\n"              
                "LDR     R4, [R4,#8]\n"               
                "LDR     R8, =0x5C9CC\n"              
                "LDR     R6, =0x5C96C\n"              
                "ADD     R12, SP, #0x14\n"            
                "ADD     LR, SP, #0x10\n"             
                "MOV     R7, #1\n"                    
                "LDR     R2, [R3]\n"                  
                "LDR     R1, [SP,#0x18]\n"            
                "STMEA   SP, {R4,R5,R12,LR}\n"        
                "LDR     R3, [R8]\n"                  
                "STR     R7, [R6]\n"                  
                "BL      sub_FF8A50F4\n"              
                "LDR     R3, =0x5C884\n"              
                "MOV     R1, #0x3E8\n"                
                "LDR     R0, [R3]\n"                  
                "BL      sub_FF821B6C\n"             
                "CMP     R0, #9\n"                    
                "BNE     loc_FF954568\n"              
                "BL      sub_FF956F20\n"              
                "LDR     R3, =0x5C97C\n"              
                "LDR     R0, =0xFF954460\n"       
                "B       loc_FF954580\n"              
"loc_FF954568:\n"                                     
                "LDR     R5, [SP,#0x10]\n"            
                "CMP     R5, #0\n"                    
                "BEQ     loc_FF95458C\n"              
                "BL      sub_FF956F20\n"              
                "LDR     R3, =0x5C97C\n"              
                "LDR     R0, =0xFF95446C\n"       
"loc_FF954580:\n"                                     
                "STR     R7, [R3]\n"                  
                "BL      sub_FF97C040\n"              
                "B       loc_FF954610\n"              
"loc_FF95458C:\n"                                     
                "BL      sub_FF8A51A0\n"      
                "LDR     R0, [SP,#0x18]\n"            
                "LDR     R1, [SP,#0x14]\n"            
                "BL      sub_FF956C38\n"              
                "LDR     R4, =0x5C9B8\n"              
                "LDR     R3, [R4]\n"                  
                "ADD     R3, R3, #1\n"                
                "LDR     R0, [SP,#0x14]\n"            
                "MOV     R1, R8\n"                    
                "STR     R3, [R4]\n"                  
                "MOV     R2, R5\n"                    
                "BL      sub_FF9556C8_my\n"  //---------------------->            
                "LDR     R3, =0x5C9A4\n"              
                "LDR     R4, [R4]\n"                  
                "LDR     R1, [R3]\n"                  
                "MOV     R0, R4\n"                    
                "BL      sub_FFAEA020\n"                 
                "CMP     R0, #0\n"                    
                "BEQ     loc_FF9545EC\n"              
                "LDR     R6, =0x5C970\n"              
                "LDR     R3, [R6]\n"                  
                "CMP     R3, #1\n"                    
                "BNE     loc_FF954604\n"              
                "B       loc_FF9545F0\n"              
"loc_FF9545EC:\n"                                     
                "LDR     R6, =0x5C970\n"              
"loc_FF9545F0:\n"                                     
                "MOV     R0, R4\n"                    
                "LDR     R3, =0x5CA00\n"              
                "MOV     LR, PC\n"                    
                "LDR     PC, [R3]\n"                  
                "STR     R5, [R6]\n"                  
"loc_FF954604:\n"                                     
                "LDR     R2, =0x5C96C\n"              
                "MOV     R3, #0\n"                    
                "STR     R3, [R2]\n"                  
"loc_FF954610:\n"                                     
                                                  
                "ADD     SP, SP, #0x1C\n"             
                "LDMFD   SP!, {R4-R8,PC}\n"           

 );
}


void __attribute__((naked,noinline)) sub_FF9567E4_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n"          
                "LDR     R12, =0x5CD20\n"             
                "LDR     R3, =0x5CD38\n"              
                "SUB     SP, SP, #8\n"                
                "LDR     R1, [R3]\n"                  
                "LDR     R2, [R12]\n"                 
                "LDR     R3, =0x5CDBC\n"              
                "ADD     R7, R2, #1\n"                
                "LDR     R3, [R3]\n"                  
                "CMP     R7, R1\n"                    
                "STR     R7, [R12]\n"                 
                "MOV     R11, R0\n"                   
                "STR     R3, [SP,#4]\n"               
                "MOVHI   R3, #0\n"                    
                "STRHI   R3, [R11]\n"                 
                "MOVHI   R0, #0x80000001\n"           
                "BHI     loc_FF956BE8\n"              
                "LDR     R3, =0x5CDA0\n"              
                "LDR     R4, [R3]\n"                  
                "MOV     R0, R7\n"                    
                "MOV     R1, R4\n"                    
                "BL      sub_FFAEA020\n"                 
                "CMP     R0, #1\n"                    
                "BNE     loc_FF956A7C\n"              
                "LDR     R3, =0x5CDC0\n"              
                "LDR     R1, =0x5CDCC\n"              
                "LDR     R0, =0x5CD08\n"              
                "LDR     R10, [R3]\n"                 
                "LDR     R2, [R1]\n"                  
                "LDR     R5, [R0]\n"                  
                "ADD     R2, R10, R2\n"               
                "CMP     R2, R5\n"                    
                "BNE     loc_FF956898\n"              
                "MOV     R1, R4\n"                    
                "MOV     R0, R7\n"                    
                "BL      sub_FFAE9990\n"                 
                "LDR     R2, =0xAAAAAAAB\n"           
                "ADD     R0, R0, #1\n"                
                "UMULL   R1, R3, R2, R0\n"            
                "MOV     R3, R3,LSR#1\n"              
                "ADD     R3, R3, R3,LSL#1\n"          
                "LDR     R4, =0x5CD10\n"              
                "RSB     R0, R3, R0\n"                
                "STR     R10, [R4,R0,LSL#2]\n"        
                "B       loc_FF9568C4\n"              
"loc_FF956898:\n"                                     
                "MOV     R1, R4\n"                    
                "MOV     R0, R7\n"                    
                "BL      sub_FFAE9990\n"                 
                "LDR     R2, =0xAAAAAAAB\n"           
                "ADD     R0, R0, #1\n"                
                "UMULL   R1, R3, R2, R0\n"            
                "MOV     R3, R3,LSR#1\n"              
                "ADD     R3, R3, R3,LSL#1\n"          
                "LDR     R4, =0x5CD10\n"              
                "RSB     R0, R3, R0\n"                
                "STR     R5, [R4,R0,LSL#2]\n"         
"loc_FF9568C4:\n"                                     
                "LDR     R3, =0x5CD20\n"              
                "LDR     R2, =0x5CDA0\n"              
                "LDR     R0, [R3]\n"                  
                "LDR     R1, [R2]\n"                  
                "BL      sub_FFAE9990\n"                 
                "LDR     R2, =0xAAAAAAAB\n"           
                "ADD     R0, R0, #1\n"                
                "UMULL   R1, R3, R2, R0\n"            
                "MOV     R3, R3,LSR#1\n"              
                "ADD     R3, R3, R3,LSL#1\n"          
                "RSB     R0, R3, R0\n"                
                "LDR     R3, =0x5CD04\n"              
                "LDR     R12, [R4,R0,LSL#2]\n"        
                "LDR     R2, [R3]\n"                  
                "CMP     R12, R2\n"                   
                "BHI     loc_FF956920\n"              
                "LDR     R4, =0x5CD58\n"              
                "LDR     R3, [R4]\n"                  
                "ADD     R3, R12, R3\n"               
                "ADD     R3, R3, #8\n"                
                "CMP     R2, R3\n"                    
                "BCS     loc_FF956924\n"              
                "B       loc_FF956AF8\n"              
"loc_FF956920:\n"                                     
                "LDR     R4, =0x5CD58\n"              
"loc_FF956924:\n"                                     
                "LDR     R2, =0x5CDC0\n"              
                "LDR     R1, =0x5CDCC\n"              
                "LDR     R0, [R4]\n"                  
                "LDR     R3, [R1]\n"                  
                "LDR     LR, [R2]\n"                  
                "ADD     R0, R12, R0\n"               
                "ADD     R2, LR, R3\n"                
                "ADD     R1, R0, #8\n"                
                "CMP     R1, R2\n"                    
                "BLS     loc_FF956974\n"              
                "LDR     R3, =0x5CD04\n"              
                "RSB     R2, R2, R0\n"                
                "ADD     R0, R2, #8\n"                
                "LDR     R1, [R3]\n"                  
                "ADD     R2, LR, R0\n"                
                "CMP     R1, R2\n"                    
                "BCC     loc_FF956AF8\n"              
                "LDR     R3, =0x5CD08\n"              
                "STR     R2, [R3]\n"                  
                "B       loc_FF95697C\n"              
"loc_FF956974:\n"                                     
                "LDR     R3, =0x5CD08\n"              
                "STR     R1, [R3]\n"                  
"loc_FF95697C:\n"                                     
                "LDR     R3, [R4]\n"                  
                "LDR     R12, =0x5CD70\n"             
                "ADD     R3, R3, #0x18\n"             
                "LDR     R2, [R12,#4]\n"              
                "MOV     R0, R3\n"                    
                "MOV     R1, #0\n"                    
                "CMP     R1, R2\n"                    
                "BHI     loc_FF956B38\n"              
                "BNE     loc_FF9569AC\n"              
                "LDR     R3, [R12]\n"                 
                "CMP     R0, R3\n"                    
                "BHI     loc_FF956B38\n"              
"loc_FF9569AC:\n"                                     
                "LDR     R4, [R4]\n"                  
                "LDR     LR, =0x5CD78\n"              
                "STR     R4, [SP]\n"                  
                "LDR     R12, =0x5CD70\n"             
                "LDR     R3, =0x5CD20\n"              
                "LDMIA   LR, {R7,R8}\n"               
                "LDMIA   R12, {R5,R6}\n"              
                "LDR     R10, [R3]\n"                 
                "LDR     R2, =0x5CDA0\n"              
                "MOV     R3, R4\n"                    
                "MOV     R4, #0\n"                    
                "ADDS    R7, R7, R3\n"                
                "ADC     R8, R8, R4\n"                
                "LDR     R9, [R2]\n"                  
                "SUBS    R5, R5, R3\n"                
                "SBC     R6, R6, R4\n"                
                "MVN     R2, #0\n"                    
                "MVN     R1, #0x17\n"                 
                "ADDS    R5, R5, R1\n"                
                "MOV     R4, #0\n"                    
                "MOV     R3, #0x18\n"                 
                "ADC     R6, R6, R2\n"                
                "ADDS    R7, R7, R3\n"                
                "ADC     R8, R8, R4\n"                
                "STMIA   R12, {R5,R6}\n"              
                "SUB     R0, R10, #1\n"               
                "MOV     R1, R9\n"                    
                "STMIA   LR, {R7,R8}\n"               
                "BL      sub_FFAE9990\n"                 
                "CMP     R10, #1\n"                   
                "MLA     R0, R9, R0, R0\n"            
                "BEQ     loc_FF956A7C\n"              
                "LDR     R1, [SP,#4]\n"               
                "SUB     R3, R0, #1\n"                
                "MOV     R3, R3,LSL#4\n"              
                "ADD     R4, R1, #0x10\n"             
                "ADD     R5, R1, #0x14\n"             
                "LDR     R1, [R5,R3]\n"               
                "LDR     R2, [R4,R3]\n"               
                "MOV     R3, R0,LSL#4\n"              
                "LDR     R0, [SP,#4]\n"               
                "ADD     R2, R2, R1\n"                
                "LDR     LR, =0x62773130\n"           
                "ADD     R1, R0, #8\n"                
                "ADD     R12, R0, #0xC\n"             
                "ADD     R2, R2, #8\n"                
                "MOV     R0, #0\n"                    
                "STR     LR, [R1,R3]\n"               
                "STR     R0, [R12,R3]\n"              
                "STR     R2, [R4,R3]\n"               
                "LDR     R1, [SP]\n"                  
                "STR     R1, [R5,R3]\n"               
"loc_FF956A7C:\n"                                     
                                                  
                "LDR     R2, =0x5CD08\n"              
                "LDR     R3, [R2]\n"                  
                "ADD     R1, R3, #8\n"                
                "STR     R1, [R11]\n"                 
                "LDR     R0, =0x5CD04\n"              
                "LDR     R2, [R0]\n"                  
                "CMP     R3, R2\n"                    
                "BHI     loc_FF956AB4\n"              
                "LDR     LR, =0x5CD68\n"              
                "LDR     R3, [LR]\n"                  
                "ADD     R3, R1, R3\n"                
                "CMP     R2, R3\n"                    
                "BCS     loc_FF956AB8\n"              
                "B       loc_FF956AF8\n"              
"loc_FF956AB4:\n"                                     
                "LDR     LR, =0x5CD68\n"              
"loc_FF956AB8:\n"                                     
                "LDR     R3, =0x5CDC0\n"              
                "LDR     R2, =0x5CDCC\n"              
                "LDR     R12, [R3]\n"                 
                "LDR     R0, [R2]\n"                  
                "LDR     R1, [R11]\n"                 
                "LDR     R3, [LR]\n"                  
                "ADD     R2, R1, R3\n"                
                "ADD     R1, R12, R0\n"               
                "CMP     R2, R1\n"                    
                "BLS     loc_FF956B08\n"              
                "RSB     R0, R1, R2\n"                
                "LDR     R1, =0x5CD04\n"              
                "LDR     R2, [R1]\n"                  
                "ADD     R3, R12, R0\n"               
                "CMP     R2, R3\n"                    
                "BCS     loc_FF956B08\n"              
"loc_FF956AF8:\n"                                     
                                                  
                "MOV     R3, #0\n"                    
                "STR     R3, [R11]\n"                 
                "MOV     R0, #0x80000003\n"           
                "B       loc_FF956BE8\n"              
"loc_FF956B08:\n"                                     
                                                  
                "LDR     R3, [LR]\n"                  
                "LDR     R12, =0x5CD70\n"             
                "ADD     R3, R3, #0x18\n"             
                "LDR     R2, [R12,#4]\n"              
                "MOV     R0, R3\n"                    
                "MOV     R1, #0\n"                    
                "CMP     R1, R2\n"                    
                "BHI     loc_FF956B38\n"              
                "BNE     loc_FF956B48\n"              
                "LDR     R3, [R12]\n"                 
                "CMP     R0, R3\n"                    
                "BLS     loc_FF956B48\n"              
"loc_FF956B38:\n"                                     
                                                  
                "MOV     R3, #0\n"                    
                "STR     R3, [R11]\n"                 
                "MOV     R0, #0x80000005\n"           
                "B       loc_FF956BE8\n"              
"loc_FF956B48:\n"                                     
                                                  
                "LDR     R1, =0x5CD50\n"              
                "LDR     R0, =0x5CDA0\n"              
                "LDR     R3, [R1]\n"                  
                "LDR     R2, [R0]\n"                  
                "ADD     R3, R3, R2,LSL#4\n"          
                "ADD     R3, R3, R3,LSL#2\n"          
                "LDR     R12, =0x5CD70\n"             
                "MOV     R3, R3,LSL#1\n"              
                "ADD     R3, R3, #0xA0\n"             
                "LDR     R2, [R12,#4]\n"              
                "MOV     R0, R3\n"                    
                "MOV     R1, #0\n"                    
                "CMP     R1, R2\n"                    
                "BHI     loc_FF956B90\n"              
                "BNE     loc_FF956BB4\n"              
                "LDR     R3, [R12]\n"                 
                "CMP     R0, R3\n"                    
                "BLS     loc_FF956BB4\n"              
"loc_FF956B90:\n"                                     
                "LDR     R4, =0x5CD88\n"              
                "LDR     R1, [R4]\n"                  
                "CMP     R1, #0\n"                    
                "BNE     loc_FF956BB4\n"              
                "MOV     R0, #0x3140\n"               
                "ADD     R0, R0, #8\n"                
                "BL      sub_FF97FF70\n"              
                "MOV     R3, #1\n"                    
                "STR     R3, [R4]\n"                  
"loc_FF956BB4:\n"                                     
                                                  
                "LDR     R2, =0x5CD78\n"              
                "LDR     R3, [R2,#4]\n"               
                "CMP     R3, #0\n"                    
                "BHI     loc_FF956BD4\n"              
                "BNE     loc_FF956BE4\n"              
                "LDR     R3, [R2]\n"                  
                "CMP     R3, #0x40000000\n"           

          //    "BLS     loc_FF956BE4\n"     // -           

                "B       loc_FF956BE4\n"     // +

"loc_FF956BD4:\n"                                     
                "MOV     R3, #0\n"                    
                "STR     R3, [R11]\n"                 
                "MOV     R0, #0x80000007\n"           
                "B       loc_FF956BE8\n"              
"loc_FF956BE4:\n"                                     
                                                  
                "MOV     R0, #0\n"                    
"loc_FF956BE8:\n"                                     
                                                  
                "ADD     SP, SP, #8\n"                
                "LDMFD   SP!, {R4-R11,PC}\n"          

 );
}


void __attribute__((naked,noinline)) sub_FF9556C8_my(){
 asm volatile(
                "CMP     R2, #1\n"                    
                "STMFD   SP!, {R4-R7,LR}\n"           
                "MOV     R7, R0\n"                    
                "MOV     R6, R1\n"                    
                "LDREQ   R3, =CompressionRateTable\n" 
                "LDREQ   R2, [R3]\n"                  
                "STREQ   R2, [R6]\n"                  
                "LDMEQFD SP!, {R4-R7,PC}\n"           
                "LDR     R12, =0x5CA80\n"             
                "LDR     R0, [R12]\n"                 
                "LDR     R3, =0x5CA88\n"              
                "CMP     R0, #0\n"                    
                "LDR     R1, [R3]\n"                  
                "BEQ     loc_FF955714\n"              
                "LDR     R2, =0x5CA8C\n"              
                "LDR     R3, [R2]\n"                  
                "CMP     R3, #1\n"                    
                "BNE     loc_FF955728\n"              
                "B       loc_FF955718\n"              
"loc_FF955714:\n"                                     
                "LDR     R2, =0x5CA8C\n"              
"loc_FF955718:\n"                                     
                "MOV     R3, #0\n"                    
                "STR     R3, [R2]\n"                  
                "STR     R7, [R12]\n"                 
                "B       loc_FF9557DC\n"              
"loc_FF955728:\n"                                     
                "LDR     R3, =0x5CA84\n"              
                "LDR     R2, [R3]\n"                  
                "LDR     R5, =table1\n"  // + 0xFF95549C       
                "MOV     LR, R2,LSL#2\n"              
                "LDR     R3, [R5,LR]\n"               
                "LDR     R4, =table2\n"  // + 0xFF95557C       
                "RSB     R12, R3, R0\n"               
                "LDR     R2, [R4,LR]\n"               
                "CMP     R12, #0\n"                   
                "RSB     R0, R2, R0\n"                
                "BLE     loc_FF955788\n"              
                "ADD     R3, R5, #0x10\n"             
                "LDR     R2, [R3,LR]\n"               
                "CMP     R2, R12\n"                   
                "ADDGE   R1, R1, #1\n"                
                "BGE     loc_FF95577C\n"              
                "ADD     R3, R5, #0x20\n"             
                "LDR     R2, [R3,LR]\n"               
                "CMP     R2, R12\n"                   
                "ADDGE   R1, R1, #2\n"                
                "ADDLT   R1, R1, #3\n"                
"loc_FF95577C:\n"                                     
           //   "CMP     R1, #0xE\n"    // -           
           //   "MOVGE   R1, #0xE\n"    // -           
                "CMP     R1, #0x1A\n"   // +            
                "MOVGE   R1, #0x1A\n"   // +            

                "B       loc_FF9557C0\n"              
"loc_FF955788:\n"                                     
                "CMP     R0, #0\n"                    
                "BGE     loc_FF9557C0\n"              
                "ADD     R3, R4, #0x10\n"             
                "LDR     R2, [R3,LR]\n"               
                "CMP     R2, R0\n"                    
                "SUBLE   R1, R1, #1\n"                
                "BLE     loc_FF9557B8\n"              
                "ADD     R3, R4, #0x20\n"             
                "LDR     R2, [R3,LR]\n"               
                "CMP     R2, R0\n"                    
                "SUBLE   R1, R1, #2\n"                
                "SUBGT   R1, R1, #3\n"                
"loc_FF9557B8:\n"                                     
                "CMP     R1, #0\n"                    
                "MOVLT   R1, #0\n"                    
"loc_FF9557C0:\n"                                     
                                                  
                "LDR     R0, =0x5CA88\n"              
                "LDR     R3, [R0]\n"                  
                "CMP     R1, R3\n"                    
                "LDRNE   R2, =0x5CA8C\n"              
                "MOVNE   R3, #1\n"                    
                "STRNE   R1, [R0]\n"                  
                "STRNE   R3, [R2]\n"                  
"loc_FF9557DC:\n"                                     
                "LDR     R3, =0x5CA88\n"              
           //   "LDR     R1, =0x5688\n"   // -
                "LDR     R1, =video_mode\n" //+     
                "LDR     R0, [R3]\n"                  
                "LDR     R2, =CompressionRateTable\n" 
                "LDR     R12, [R1]\n"
                "LDR     R12, [R12]\n" //+                
                "LDR     LR, [R2,R0,LSL#2]\n"         
                "LDR     R3, =0x5CA80\n"              
                "CMP     R12, #1\n"                   
                "STR     R7, [R3]\n"                  
                "STR     LR, [R6]\n"                  
           //   "MOVEQ   R3, #0xB\n"        // -

                "LDREQ   R3, =video_quality\n"          // +
                "LDREQ   R3, [R3]\n"                    // +
                "LDREQ   R3, [R3]\n"                    // +

                "STREQ   R3, [R6]\n"                  
                "LDMFD   SP!, {R4-R7,PC}\n"           

 );
}
