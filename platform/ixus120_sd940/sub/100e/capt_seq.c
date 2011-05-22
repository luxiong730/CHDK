// IXUS120-SD940 fw 1.00e
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

static long *nrflag = (long*)0x6718;			//

#include "../../../generic/capt_seq.c"

/*----------------------------------------------------------------------
	capt_seq_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"	STMFD	SP!, {R3-R9,LR} \n"                
"	LDR	R6, =0x2988 \n"                  
"	LDR	R4, =0x37B08 \n"                  
"	MOV	R9, #1 \n"                           
"	MOV	R7, #0 \n"   
"loc_FF872F98:\n"
"	LDR	R0, [R6, #4] \n"                     
"	MOV	R2, #0 \n"                           
"	MOV	R1, SP \n"                           
"	BL	sub_FF837DC8 \n"                      
"	TST	R0, #1 \n"                           
"	BEQ	loc_FF872FC4 \n"                     
"	LDR	R1, =0x5B4 \n"                       
"	LDR	R0, =0xFF872B14 \n"                
"	BL	sub_FF81E88C \n"                      
"	BL	sub_FF81E844 \n"                      
"	LDMFD	SP!, {R3-R9,PC} \n"                
"loc_FF872FC4:\n"
"	LDR	R0, [SP] \n"                         
"	LDR	R1, [R0] \n"                         
"	CMP	R1, #0x1D \n"                        
"	ADDLS	PC, PC, R1, LSL #2 \n"             
"	B	loc_FF873250 \n"     
                  
"	B	loc_FF873050 \n"                       
"	B	loc_FF8730B4 \n"                       
"	B	loc_FF8730F0 \n"                       
"	B	loc_FF873104 \n"                       
"	B	loc_FF8730FC \n"                       
"	B	loc_FF87310C \n"                       
"	B	loc_FF873114 \n"                       
"	B	loc_FF87311C \n"                       
"	B	loc_FF873174 \n"                       
"	B	loc_FF87319C \n"                       
"	B	loc_FF873180 \n"                       
"	B	loc_FF87318C \n"                       
"	B	loc_FF873194 \n"                       
"	B	loc_FF8731A4 \n"                       
"	B	loc_FF8731AC \n"                       
"	B	loc_FF8731B4 \n"                       
"	B	loc_FF8731BC \n"                       
"	B	loc_FF8731C4 \n"                       
"	B	loc_FF8731D0 \n"                       
"	B	loc_FF8731D8 \n"                       
"	B	loc_FF8731E0 \n"                       
"	B	loc_FF8731E8 \n"                       
"	B	loc_FF8731F0 \n"                       
"	B	loc_FF8731FC \n"                       
"	B	loc_FF873204 \n"                       
"	B	loc_FF87320C \n"                       
"	B	loc_FF873214 \n"                       
"	B	loc_FF87321C \n"                       
"	B	loc_FF873228 \n"                       
"	B	loc_FF87325C \n"  
                     
"loc_FF873050:\n"
"	BL	sub_FF8738DC \n"  
"	BL	shooting_expo_param_override\n"			// added                         
"	BL	sub_FF870DCC \n"   

//  this code added to avoid some incorrect behavior if overrides are used.
 //  but it can cause some unexpected side effects. In this case, remove this code!
"		MOV R0,	#0\n"
"		STR R0,	[R4,#0x24]\n"  // fixes overrides  behavior at short shutter press
                
"	LDR	R0, [R4, #0x24] \n"                  
"	CMP	R0, #0 \n"                           
"	BEQ	loc_FF87325C \n"                     
"	BL	sub_FF8727F4 \n"                      
"	MOV	R5, R0 \n"                           
"	LDR	R0, [R4, #0x24] \n"                  
"	CMP	R0, #0 \n"                           
"	BEQ	loc_FF873098 \n"                     
"	MOV	R0, #0xC \n"                         
"	BL	sub_FF877A20 \n"                      
"	TST	R0, #1 \n"                           
"	STRNE	R9, [R6, #0x10] \n"                
"	LDRNE	R0, [R5, #8] \n"                   
"	ORRNE	R0, R0, #0x40000000 \n"            
"	STRNE	R0, [R5, #8] \n"                   
"	BNE	loc_FF87325C \n"  
                   
"loc_FF873098:\n"
"	MOV	R0, R5 \n"                           
"	BL	sub_FF872A98 \n"                      
"	MOV	R0, R5 \n"   

//"	BL	sub_FF9425F4 \n" 
"	BL	sub_FF9425F4_my \n"    			// patched 
                     
"	TST	R0, #1 \n"                           
"	STRNE	R9, [R6, #0x10] \n"                
"	B	loc_FF87325C \n"
                       
"loc_FF8730B4:\n"
"	LDR	R0, [R4, #0x24] \n"                  
"	CMP	R0, #0 \n"                           
"	BNE	loc_FF8730E0 \n"                     
"	MOV	R0, #0xC \n"                         
"	BL	sub_FF877A20 \n"                      
"	TST	R0, #1 \n"                           
"	LDRNE	R0, [SP] \n"                       
"	MOVNE	R1, #1 \n"                         
"	LDRNE	R2, [R0, #0xC] \n"                 
"	MOVNE	R0, #1 \n"                         
"	BNE	loc_FF87316C \n"  
                   
"loc_FF8730E0:\n"
"	LDR	R0, [SP] \n"                         
//"	BL	sub_FF873374 \n"   
  "	BL	sub_FF873374_my \n"   			// patched 
  
  
"loc_FF8730E8:\n"
"	STR	R7, [R4, #0x24] \n"                  
"	B	loc_FF87325C \n"   
                    
"loc_FF8730F0:\n"
"	MOV	R0, #1 \n"                           
"	BL	sub_FF873B30 \n"                      
"	B	loc_FF87325C \n" 
                      
"loc_FF8730FC:\n"
"	BL	sub_FF87351C \n"                      
"	B	loc_FF8730E8 \n"    
                   
"loc_FF873104:\n"
"	BL	sub_FF8738BC \n"                      
"	B	loc_FF8730E8 \n"  
                     
"loc_FF87310C:\n"
"	BL	sub_FF8738C4 \n"                      
"	B	loc_FF87325C \n"  
                     
"loc_FF873114:\n"
"	BL	sub_FF873A50 \n"                      
"	B	loc_FF873178 \n"  
                     
"loc_FF87311C:\n"
"	LDR	R5, [R0, #0xC] \n"                   
"	BL	sub_FF8738CC \n"                      
"	MOV	R0, R5 \n"                           
"	BL	sub_FF941228 \n"                      
"	TST	R0, #1 \n"                           
"	MOV	R8, R0 \n"                           
"	BNE	loc_FF87315C \n"                     
"	BL	sub_FF884AD8 \n"                      
"	STR	R0, [R5, #0x18] \n"                  
"	MOV	R0, R5 \n"                           
"	BL	sub_FF942328 \n"                      
"	MOV	R0, R5 \n"                           
"	BL	sub_FF942724 \n"                      
"	MOV	R8, R0 \n"                           
"	LDR	R0, [R5, #0x18] \n"                  
"	BL	sub_FF884CDC \n"                      
"loc_FF87315C:\n"
"	BL	sub_FF8738BC \n"                      
"	MOV	R2, R5 \n"                           
"	MOV	R1, #9 \n"                           
"	MOV	R0, R8 \n"                           
"loc_FF87316C:\n"
"	BL	sub_FF8712B8 \n"                      
"	B	loc_FF87325C \n"  

                     
"loc_FF873174:\n"
"	BL	sub_FF873AB0 \n"                      
"loc_FF873178:\n"
"	BL	sub_FF870DCC \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF873180:\n"
"	LDR	R0, [R4, #0x54] \n"                  
"	BL	sub_FF873EBC \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF87318C:\n"
"	BL	sub_FF874170 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF873194:\n"
"	BL	sub_FF874204 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF87319C:\n"
"	BL	sub_FF8738BC \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731A4:\n"
"	BL	sub_FF941440 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731AC:\n"
"	BL	sub_FF941654 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731B4:\n"
"	BL	sub_FF9416EC \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731BC:\n"
"	BL	sub_FF9417BC \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731C4:\n"
"	MOV	R0, #0 \n"                           
"	BL	sub_FF941A0C \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731D0:\n"
"	BL	sub_FF941B5C \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731D8:\n"
"	BL	sub_FF941BEC \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731E0:\n"
"	BL	sub_FF941CAC \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731E8:\n"
"	BL	sub_FF873CA8 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731F0:\n"
"	BL	sub_FF873D48 \n"                      
"	BL	sub_FF835F18 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF8731FC:\n"
"	BL	sub_FF941888 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF873204:\n"
"	BL	sub_FF9418F4 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF87320C:\n"
"	BL	sub_FF8761D0 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF873214:\n"
"	BL	sub_FF876238 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF87321C:\n"
"	BL	sub_FF876294 \n"                      
"	BL	sub_FF876254 \n"                      
"	B	loc_FF87325C \n"                       
"loc_FF873228:\n"
"	MOV	R0, #1 \n"                           
"	BL	sub_FF942F68 \n"                      
"	MOV	R0, #1 \n"                           
"	BL	sub_FF943078 \n"                      
"	LDRH	R0, [R4, #0x98] \n"                 
"	CMP	R0, #4 \n"                           
"	BNE	loc_FF87325C \n"                     
"	BL	sub_FF876238 \n"                      
"	BL	sub_FF876674 \n"                      
"	B	loc_FF87325C \n"    
                   
"loc_FF873250:\n"
"	LDR	R1, =0x709 \n"                       
"	LDR	R0, =0xFF872B14 \n"                
"	BL	sub_FF81E88C \n"   
                   
"loc_FF87325C:\n"
"	LDR	R0, [SP] \n"                         
"	LDR	R1, [R0, #4] \n"                     
"	LDR	R0, [R6] \n"                         
"	BL	sub_FF87C7DC \n"                      
"	LDR	R5, [SP] \n"                         
"	LDR	R0, [R5, #8] \n"                     
"	CMP	R0, #0 \n"                           
"	LDREQ	R1, =0x132 \n"                     
"	LDREQ	R0, =0xFF872B14 \n"                
"	BLEQ	sub_FF81E88C \n"                    
"	STR	R7, [R5, #8] \n"                     
"	B	loc_FF872F98 \n"             
	);
}


/*----------------------------------------------------------------------
	sub_FF9425F4_my()  - capt_seq_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) sub_FF9425F4_my() {
asm volatile (
"	STMFD	SP!, {R0-R8,LR} \n"                
"	MOV	R4, R0 \n"                           
"	BL	sub_FF943264 \n"                      
"	MVN	R1, #0 \n"                           
"	BL	sub_FF87C810 \n"                      
"	LDR	R5, =0x6718 \n"                      
"	LDR	R0, [R5, #0xC] \n"                   
"	CMP	R0, #0 \n"                           
"	BNE	loc_FF942460 \n"                     
"	MOV	R1, #1 \n"                           
"	MOV	R0, #0 \n"                           
"	BL	sub_FF838610 \n"                      
"	STR	R0, [R5, #0xC] \n"                   
"	MOV	R3, #0 \n"                           
"	STR	R3, [SP] \n"                         
"	LDR	R3, =0xFF941D9C \n"                
"	LDR	R0, =0xFF94268C \n"                  
"	MOV	R2, #0x400 \n"                       
"	MOV	R1, #0x17 \n"                        
"	BL	sub_FF8385DC \n"                      
"loc_FF942460:\n"
"	MOV	R2, #4 \n"                           
"	ADD	R1, SP, #8 \n"                       
"	MOV	R0, #0x8A \n"                        
"	BL	sub_FF884948 \n"                      
"	TST	R0, #1 \n"                           
"	LDRNE	R1, =0x3C5 \n"                     
"	LDRNE	R0, =0xFF942034 \n"              
"	BLNE	sub_FF81E88C \n"                    
"	LDR	R6, =0x37BCC \n"                     
"	LDR	R8, =0x37B08 \n"                     
"	LDRSH	R2, [R6, #0xC] \n"                 
"	LDRSH	R1, [R6, #0xE] \n"                 
"	LDR	R0, [R8, #0x8C] \n"                  
"	BL	sub_FF90B548 \n"                      
"	BL	sub_FF85BC98 \n"                      
"	LDR	R3, =0x6720 \n"                      
"	STRH	R0, [R4, #0xA4] \n"                 
"	SUB	R2, R3, #4 \n"                       
"	STRD	R2, [SP]\n"   
"	MOV	R1, R0 \n"                           
"	LDRH	R0, [R8, #0x5C] \n"                 
"	LDRSH	R2, [R6, #0xC] \n"                 
"	SUB	R3, R3, #8 \n"                       
"	BL	sub_FF9448A8 \n"     
 
"	BL      wait_until_remote_button_is_released\n"
"	BL      capt_seq_hook_set_nr\n"
 
"	LDR	R0, [R4, #0x1C] \n"                  
"	CMP	R0, #0 \n"                           
"	MOVNE	R0, #1 \n"                         
"	STRNE	R0, [R5] \n"                       
"	LDR	R0, [R5, #4] \n"                     
"	BL	sub_FF90B7F8 \n"                      
"	LDR	R0, [R5, #8] \n"                     
"	BL	sub_FF8B9E48 \n"                      
"	MOV	R0, #1 \n"                           
"	BL	sub_FF8B9E54 \n"                      
"	LDR	R0, =0xFF941E0C \n"                
"	MOV	R1, R4 \n"                           
"	BL	sub_FF8B9E24 \n"                      
"	LDR	R0, [R5] \n"                         
"	CMP	R0, #5 \n"                           
"	ADDLS	PC, PC, R0, LSL #2 \n"    
         
"	B	sub_FF9425CC \n"   // go to the ROM                       
	);
}


	
/*----------------------------------------------------------------------
	sub_FF873374_my() - capt_seq_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) sub_FF873374_my() {
asm volatile (
"	STMFD	SP!, {R4-R6,LR} \n"                
"	LDR	R4, [R0, #0xC] \n"                   
"	LDR	R6, =0x37B08 \n"                     
"	LDR	R0, [R4, #8] \n"                     
"	MOV	R5, #0 \n"                           
"	ORR	R0, R0, #1 \n"                       
"	STR	R0, [R4, #8] \n"                     
"	LDR	R0, [R6, #0x24] \n"                  
"	CMP	R0, #0 \n"                           
"	MOVEQ	R0, #2 \n"                         
"	BLEQ	sub_FF86F4AC \n"                    
"	BL	sub_FF8738CC \n"                      
"	LDR	R0, [R6, #0x24] \n"                  
"	CMP	R0, #0 \n"                           
"	BNE	loc_FF87343C \n"                     
"	MOV	R0, #0 \n"                           
"	BL	sub_FF942F68 \n"                      
"	MOV	R0, #0 \n"                           
"	BL	sub_FF943078 \n"                      
"	MOV	R0, R4 \n"                           
"	BL	sub_FF873C50 \n"                      
"	MOV	R0, R4 \n"                           
"	BL	sub_FF940E78 \n"                      
"	CMP	R0, #0 \n"                           
"	BEQ	loc_FF873404 \n"                     
"	BL	sub_FF942FA8 \n"                      
"	BL	sub_FF9430BC \n"                      
"	BL	sub_FF94310C \n"                      
"	MOV	R0, R4 \n"                           
"	BL	sub_FF940F5C \n"                      
"	TST	R0, #1 \n"                           
"	MOVNE	R2, R4 \n"                         
"	LDMNEFD	SP!, {R4-R6,LR} \n"              
"	MOVNE	R1, #1 \n"                         
"	BNE	sub_FF8712B8 \n"                     
"	B	loc_FF873418 \n"                       
"loc_FF873404:\n"
"	MOV	R0, R4 \n"                           
"	BL	sub_FF940EF8 \n"                      
"	BL	sub_FF942FA8 \n"                      
"	BL	sub_FF9430BC \n"                      
"	BL	sub_FF94310C \n"                      
"loc_FF873418:\n"
"	MOV	R0, R4 \n"                           
"	BL	sub_FF872A98 \n"                      
"	MOV	R0, R4 \n"                           
"	BL	sub_FF942328 \n"                      
"	BL	sub_FF942DA0 \n"                      
"	MOV	R0, R4 \n"   
        
// this patch causes a crash when shooting
// it is unknown what the effect is of not calling this	(called elsewhere)	                 		
"	BL	sub_FF9425F4 \n"     
//"	BL	sub_FF9425F4_my \n"                      
"	MOV	R5, R0 \n"  
"	BL		capt_seq_hook_raw_here\n"  //----------->>                            
"	B	loc_FF87344C \n"   
// ---------------------------------------------------------------------------

                    
"loc_FF87343C:\n"
"	LDR	R0, =0x2988 \n"                      
"	LDR	R0, [R0, #0x10] \n"                  
"	CMP	R0, #0 \n"                           
"	MOVNE	R5, #0x1D \n"
                      
"loc_FF87344C:\n"
"	BL	sub_FF876238 \n"                      
"	BL	sub_FF876280 \n"                      
"	BL	sub_FF8762C0 \n"                      
"	MOV	R2, R4 \n"                           
"	MOV	R1, #1 \n"                           
"	MOV	R0, R5 \n"                           
"	BL	sub_FF8712B8 \n"                      
"	BL	sub_FF9426C8 \n"                      
"	CMP	R0, #0 \n"                           
"	LDRNE	R0, [R4, #8] \n"                   
"	ORRNE	R0, R0, #0x2000 \n"                
"	STRNE	R0, [R4, #8] \n"                   
"	LDMFD	SP!, {R4-R6,PC} \n"                     
	);
}


/*----------------------------------------------------------------------
	exp_drv_task()  0xFF8B2F58
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"	STMFD	SP!, {R4-R8,LR} \n"                
"	SUB	SP, SP, #0x20 \n"                    
"	LDR	R8, =0xBB8 \n"                       
"	LDR	R7, =0x3C80 \n"                      
"	LDR	R5, =0x3C760 \n"                     
"	MOV	R0, #0 \n"                           
"	ADD	R6, SP, #0x10 \n"                    
"	STR	R0, [SP, #0xC] \n"                   
"loc_FF8B2F78:\n"
"	LDR	R0, [R7, #0x20] \n"                  
"	MOV	R2, #0 \n"                           
"	ADD	R1, SP, #0x1C \n"                    
"	BL	sub_FF837DC8 \n"                      
"	LDR	R0, [SP, #0xC] \n"                   
"	CMP	R0, #1 \n"                           
"	BNE	loc_FF8B2FC4 \n"                     
"	LDR	R0, [SP, #0x1C] \n"                  
"	LDR	R0, [R0] \n"                         
"	CMP	R0, #0x13 \n"                        
"	CMPNE	R0, #0x14 \n"                      
"	CMPNE	R0, #0x15 \n"                      
"	CMPNE	R0, #0x16 \n"                      
"	BEQ	loc_FF8B30E0 \n"                     
"	CMP	R0, #0x28 \n"                        
"	BEQ	loc_FF8B30B8 \n"                     
"	ADD	R1, SP, #0xC \n"                     
"	MOV	R0, #0 \n"                           
"	BL	sub_FF8B2F08 \n"                      
"loc_FF8B2FC4:\n"
"	LDR	R0, [SP, #0x1C] \n"                  
"	LDR	R1, [R0] \n"                         
"	CMP	R1, #0x2D \n"                        
"	BNE	loc_FF8B2FF4 \n"                     
"	LDR	R0, [SP, #0x1C] \n"                  
"	BL	sub_FF8B41C8 \n"                      
"	LDR	R0, [R7, #0x1C] \n"                  
"	MOV	R1, #1 \n"                           
"	BL	sub_FF87C7DC \n"                      
"	BL	sub_FF81E844 \n"                      
"	ADD	SP, SP, #0x20 \n"                    
"	LDMFD	SP!, {R4-R8,PC} \n"                
"loc_FF8B2FF4:\n"
"	CMP	R1, #0x2C \n"                        
"	BNE	loc_FF8B3010 \n"                     
"	LDR	R2, [R0, #0x8C]! \n"                 
"	LDR	R1, [R0, #4] \n"                     
"	MOV	R0, R1 \n"                           
"	BLX	R2 \n"                               
"	B	loc_FF8B3508 \n"                       
"loc_FF8B3010:\n"
"	CMP	R1, #0x26 \n"                        
"	BNE	loc_FF8B3060 \n"                     
"	LDR	R0, [R7, #0x1C] \n"                  
"	MOV	R1, #0x80 \n"                        
"	BL	sub_FF87C810 \n"                      
"	LDR	R0, =0xFF8AF668 \n"                
"	MOV	R1, #0x80 \n"                        
"	BL	sub_FF936238 \n"                      
"	LDR	R0, [R7, #0x1C] \n"                  
"	MOV	R2, R8 \n"                           
"	MOV	R1, #0x80 \n"                        
"	BL	sub_FF87C71C \n"                      
"	TST	R0, #1 \n"                           
"	LDRNE	R1, =0xE54 \n"                     
"	BNE	loc_FF8B30A4 \n"                     
"loc_FF8B304C:\n"
"	LDR	R1, [SP, #0x1C] \n"                  
"	LDR	R0, [R1, #0x90] \n"                  
"	LDR	R1, [R1, #0x8C] \n"                  
"	BLX	R1 \n"                               
"	B	loc_FF8B3508 \n"                       
"loc_FF8B3060:\n"
"	CMP	R1, #0x27 \n"                        
"	BNE	loc_FF8B30B0 \n"                     
"	ADD	R1, SP, #0xC \n"                     
"	BL	sub_FF8B2F08 \n"                      
"	LDR	R0, [R7, #0x1C] \n"                  
"	MOV	R1, #0x100 \n"                       
"	BL	sub_FF87C810 \n"                      
"	LDR	R0, =0xFF8AF678 \n"                
"	MOV	R1, #0x100 \n"                       
"	BL	sub_FF9364C0 \n"                      
"	LDR	R0, [R7, #0x1C] \n"                  
"	MOV	R2, R8 \n"                           
"	MOV	R1, #0x100 \n"                       
"	BL	sub_FF87C71C \n"                      
"	TST	R0, #1 \n"                           
"	BEQ	loc_FF8B304C \n"                     
"	LDR	R1, =0xE5E \n"                       
"loc_FF8B30A4:\n"
"	LDR	R0, =0xFF8AFCDC \n"                
"	BL	sub_FF81E88C \n"                      
"	B	loc_FF8B304C \n"                       
"loc_FF8B30B0:\n"
"	CMP	R1, #0x28 \n"                        
"	BNE	loc_FF8B30C8 \n"                     
"loc_FF8B30B8:\n"
"	LDR	R0, [SP, #0x1C] \n"                  
"	ADD	R1, SP, #0xC \n"                     
"	BL	sub_FF8B2F08 \n"                      
"	B	loc_FF8B304C \n"                       
"loc_FF8B30C8:\n"
"	CMP	R1, #0x2B \n"                        
"	BNE	loc_FF8B30E0 \n"                     
"	BL	sub_FF8A3178 \n"                      
"	BL	sub_FF8A3D9C \n"                      
"	BL	sub_FF8A38F0 \n"                      
"	B	loc_FF8B304C \n"                       
"loc_FF8B30E0:\n"
"	LDR	R0, [SP, #0x1C] \n"                  
"	MOV	R4, #1 \n"                           
"	LDR	R1, [R0] \n"                         
"	CMP	R1, #0x11 \n"                        
"	CMPNE	R1, #0x12 \n"                      
"	BNE	loc_FF8B3150 \n"                     
"	LDR	R1, [R0, #0x7C] \n"                  
"	ADD	R1, R1, R1, LSL #1 \n"               
"	ADD	R1, R0, R1, LSL #2 \n"               
"	SUB	R1, R1, #8 \n"                       
"	LDMIA	R1, {R2-R4} \n"                    
"	STMIA	R6, {R2-R4} \n"                    
"	BL	sub_FF8B181C \n"                      
"	LDR	R0, [SP, #0x1C] \n"                  
"	LDR	R1, [R0, #0x7C] \n"                  
"	LDR	R3, [R0, #0x8C] \n"                  
"	LDR	R2, [R0, #0x90] \n"                  
"	ADD	R0, R0, #4 \n"                       
"	BLX	R3 \n"                               
"	LDR	R0, [SP, #0x1C] \n"                  
"	BL	sub_FF8B4588 \n"                      
"	LDR	R0, [SP, #0x1C] \n"                  
"	LDR	R1, [R0, #0x7C] \n"                  
"	LDR	R3, [R0, #0x94] \n"                  
"	LDR	R2, [R0, #0x98] \n"                  
"	ADD	R0, R0, #4 \n"                       
"	BLX	R3 \n"                               
"	B	loc_FF8B3448 \n"                       
"loc_FF8B3150:\n"
"	CMP	R1, #0x13 \n"                        
"	CMPNE	R1, #0x14 \n"                      
"	CMPNE	R1, #0x15 \n"                      
"	CMPNE	R1, #0x16 \n"                      
"	BNE	loc_FF8B3208 \n"                     
"	ADD	R3, SP, #0xC \n"                     
"	MOV	R2, SP \n"                           
"	ADD	R1, SP, #0x10 \n"                    
"	BL	sub_FF8B1B04 \n"                      
"	CMP	R0, #1 \n"                           
"	MOV	R4, R0 \n"                           
"	CMPNE	R4, #5 \n"                         
"	BNE	loc_FF8B31A4 \n"                     
"	LDR	R0, [SP, #0x1C] \n"                  
"	MOV	R2, R4 \n"                           
"	LDR	R1, [R0, #0x7C]! \n"                 
"	LDR	R12, [R0, #0x10]! \n"                
"	LDR	R3, [R0, #4] \n"                     
"	MOV	R0, SP \n"                           
"	BLX	R12 \n"                              
"	B	loc_FF8B31DC \n"                       
"loc_FF8B31A4:\n"
"	LDR	R0, [SP, #0x1C] \n"                  
"	CMP	R4, #2 \n"                           
"	LDR	R3, [R0, #0x90] \n"                  
"	CMPNE	R4, #6 \n"                         
"	BNE	loc_FF8B31F0 \n"                     
"	LDR	R12, [R0, #0x8C] \n"                 
"	MOV	R0, SP \n"                           
"	MOV	R2, R4 \n"                           
"	MOV	R1, #1 \n"                           
"	BLX	R12 \n"                              
"	LDR	R0, [SP, #0x1C] \n"                  
"	MOV	R2, SP \n"                           
"	ADD	R1, SP, #0x10 \n"                    
"	BL	sub_FF8B2C1C \n"                      
"loc_FF8B31DC:\n"
"	LDR	R0, [SP, #0x1C] \n"                  
"	LDR	R2, [SP, #0xC] \n"                   
"	MOV	R1, R4 \n"                           
"	BL	sub_FF8B2EA8 \n"                      
"	B	loc_FF8B3448 \n"                       
"loc_FF8B31F0:\n"
"	LDR	R1, [R0, #0x7C] \n"                  
"	LDR	R12, [R0, #0x8C] \n"                 
"	ADD	R0, R0, #4 \n"                       
"	MOV	R2, R4 \n"                           
"	BLX	R12 \n"                              
"	B	loc_FF8B3448 \n"                       
"loc_FF8B3208:\n"
"	CMP	R1, #0x22 \n"                        
"	CMPNE	R1, #0x23 \n"                      
"	BNE	loc_FF8B3254 \n"                     
"	LDR	R1, [R0, #0x7C] \n"                  
"	ADD	R1, R1, R1, LSL #1 \n"               
"	ADD	R1, R0, R1, LSL #2 \n"               
"	SUB	R1, R1, #8 \n"                       
"	LDMIA	R1, {R2-R4} \n"                    
"	STMIA	R6, {R2-R4} \n"                    
"	BL	sub_FF8B0D6C \n"                      
"	LDR	R0, [SP, #0x1C] \n"                  
"	LDR	R1, [R0, #0x7C] \n"                  
"	LDR	R3, [R0, #0x8C] \n"                  
"	LDR	R2, [R0, #0x90] \n"                  
"	ADD	R0, R0, #4 \n"                       
"	BLX	R3 \n"                               
"	LDR	R0, [SP, #0x1C] \n"                  
"	BL	sub_FF8B1060 \n"                      
"	B	loc_FF8B3448 \n"                       
"loc_FF8B3254:\n"
"	ADD	R1, R0, #4 \n"                       
"	LDMIA	R1, {R2,R3,R12} \n"                
"	STMIA	R6, {R2,R3,R12} \n"                
"	LDR	R1, [R0] \n"                         
"	CMP	R1, #0x25 \n"                        
"	ADDLS	PC, PC, R1, LSL #2 \n"             
"	B	loc_FF8B3428 \n"   
                   
"	B	loc_FF8B3308 \n"                       
"	B	loc_FF8B3308 \n"                       
"	B	loc_FF8B3310 \n"                       
"	B	loc_FF8B3318 \n"                       
"	B	loc_FF8B3318 \n"                       
"	B	loc_FF8B3318 \n"                       
"	B	loc_FF8B3308 \n"                       
"	B	loc_FF8B3310 \n"                       
"	B	loc_FF8B3318 \n"                       
"	B	loc_FF8B3318 \n"                       
"	B	loc_FF8B3330 \n"                       
"	B	loc_FF8B3330 \n"                       
"	B	loc_FF8B341C \n"                       
"	B	loc_FF8B3424 \n"                       
"	B	loc_FF8B3424 \n"                       
"	B	loc_FF8B3424 \n"                       
"	B	loc_FF8B3424 \n"                       
"	B	loc_FF8B3428 \n"                       
"	B	loc_FF8B3428 \n"                       
"	B	loc_FF8B3428 \n"                       
"	B	loc_FF8B3428 \n"                       
"	B	loc_FF8B3428 \n"                       
"	B	loc_FF8B3428 \n"                       
"	B	loc_FF8B3320 \n"                       
"	B	loc_FF8B3328 \n"                       
"	B	loc_FF8B3328 \n"                       
"	B	loc_FF8B333C \n"                       
"	B	loc_FF8B333C \n"                       
"	B	loc_FF8B3344 \n"                       
"	B	loc_FF8B3374 \n"                       
"	B	loc_FF8B33A4 \n"                       
"	B	loc_FF8B33D4 \n"                       
"	B	loc_FF8B3404 \n"                       
"	B	loc_FF8B3404 \n"                       
"	B	loc_FF8B3428 \n"                       
"	B	loc_FF8B3428 \n"                       
"	B	loc_FF8B340C \n"                       
"	B	loc_FF8B3414 \n"  

                     
"loc_FF8B3308:\n"
"	BL	sub_FF8AFB80 \n"                      
"	B	loc_FF8B3428 \n"   
                    
"loc_FF8B3310:\n"
"	BL	sub_FF8AFE08 \n"                      
"	B	loc_FF8B3428 \n"  
                     
"loc_FF8B3318:\n"
"	BL	sub_FF8B0010 \n"                      
"	B	loc_FF8B3428 \n"  
      
	  
"loc_FF8B3320:\n"
"	BL	sub_FF8B0288 \n"                      
"	B	loc_FF8B3428 \n"  
                     
"loc_FF8B3328:\n"
"	BL	sub_FF8B0480 \n"                      
"	B	loc_FF8B3428 \n"  
                     
"loc_FF8B3330:\n"
//"	BL	sub_FF8B07B4 \n"  
"	BL	sub_FF8B07B4_my \n"     //----->>>
               
			   
"	MOV	R4, #0 \n"                           
"	B	loc_FF8B3428 \n"  
                     
"loc_FF8B333C:\n"
"	BL	sub_FF8B087C \n"                      
"	B	loc_FF8B3428 \n" 
                      
"loc_FF8B3344:\n"
"	LDRH	R1, [R0, #4] \n"                    
"	STRH	R1, [SP, #0x10] \n"                 
"	LDRH	R1, [R5, #2] \n"                    
"	STRH	R1, [SP, #0x12] \n"                 
"	LDRH	R1, [R5, #4] \n"                    
"	STRH	R1, [SP, #0x14] \n"                 
"	LDRH	R1, [R5, #6] \n"                    
"	STRH	R1, [SP, #0x16] \n"                 
"	LDRH	R1, [R0, #0xC] \n"                  
"	STRH	R1, [SP, #0x18] \n"                 
"	BL	sub_FF8B423C \n"                      
"	B	loc_FF8B3428 \n" 
                      
"loc_FF8B3374:\n"
"	LDRH	R1, [R0, #4] \n"                    
"	STRH	R1, [SP, #0x10] \n"                 
"	LDRH	R1, [R5, #2] \n"                    
"	STRH	R1, [SP, #0x12] \n"                 
"	LDRH	R1, [R5, #4] \n"                    
"	STRH	R1, [SP, #0x14] \n"                 
"	LDRH	R1, [R5, #6] \n"                    
"	STRH	R1, [SP, #0x16] \n"                 
"	LDRH	R1, [R5, #8] \n"                    
"	STRH	R1, [SP, #0x18] \n"                 
"	BL	sub_FF8B43A0 \n"                      
"	B	loc_FF8B3428 \n" 
                      
"loc_FF8B33A4:\n"
"	LDRH	R1, [R5] \n"                        
"	STRH	R1, [SP, #0x10] \n"                 
"	LDRH	R1, [R0, #6] \n"                    
"	STRH	R1, [SP, #0x12] \n"                 
"	LDRH	R1, [R5, #4] \n"                    
"	STRH	R1, [SP, #0x14] \n"                 
"	LDRH	R1, [R5, #6] \n"                    
"	STRH	R1, [SP, #0x16] \n"                 
"	LDRH	R1, [R5, #8] \n"                    
"	STRH	R1, [SP, #0x18] \n"                 
"	BL	sub_FF8B444C \n"                      
"	B	loc_FF8B3428 \n" 
                      
"loc_FF8B33D4:\n"
"	LDRH	R1, [R5] \n"                        
"	STRH	R1, [SP, #0x10] \n"                 
"	LDRH	R1, [R5, #2] \n"                    
"	STRH	R1, [SP, #0x12] \n"                 
"	LDRH	R1, [R5, #4] \n"                    
"	STRH	R1, [SP, #0x14] \n"                 
"	LDRH	R1, [R5, #6] \n"                    
"	STRH	R1, [SP, #0x16] \n"                 
"	LDRH	R1, [R0, #0xC] \n"                  
"	STRH	R1, [SP, #0x18] \n"                 
"	BL	sub_FF8B44EC \n"                      
"	B	loc_FF8B3428 \n" 
                      
"loc_FF8B3404:\n"
"	BL	sub_FF8B0BC4 \n"                      
"	B	loc_FF8B3428 \n" 
                      
"loc_FF8B340C:\n"
"	BL	sub_FF8B1164 \n"                      
"	B	loc_FF8B3428 \n"   
                    
"loc_FF8B3414:\n"
"	BL	sub_FF8B13A0 \n"                      
"	B	loc_FF8B3428 \n" 
                      
"loc_FF8B341C:\n"
"	BL	sub_FF8B151C \n"                      
"	B	loc_FF8B3428 \n"  
                     
"loc_FF8B3424:\n"
"	BL	sub_FF8B16B8 \n"  
                    
"loc_FF8B3428:\n"
"	LDR	R0, [SP, #0x1C] \n"                  
"	LDR	R1, [R0, #0x7C] \n"                  
"	LDR	R3, [R0, #0x8C] \n"                  
"	LDR	R2, [R0, #0x90] \n"                  
"	ADD	R0, R0, #4 \n"                       
"	BLX	R3 \n"                               
"	CMP	R4, #1 \n"                           
"	BNE	loc_FF8B3490 \n"
                     
"loc_FF8B3448:\n"
"	LDR	R0, [SP, #0x1C] \n"                  
"	MOV	R2, #0xC \n"                         
"	LDR	R1, [R0, #0x7C] \n"                  
"	ADD	R1, R1, R1, LSL #1 \n"               
"	ADD	R0, R0, R1, LSL #2 \n"               
"	SUB	R4, R0, #8 \n"                       
"	LDR	R0, =0x3C760 \n"                     
"	ADD	R1, SP, #0x10 \n"                    
"	BL	sub_FFB07784 \n"                      
"	LDR	R0, =0x3C76C \n"                     
"	MOV	R2, #0xC \n"                         
"	ADD	R1, SP, #0x10 \n"                    
"	BL	sub_FFB07784 \n"                      
"	LDR	R0, =0x3C778 \n"                     
"	MOV	R2, #0xC \n"                         
"	MOV	R1, R4 \n"                           
"	BL	sub_FFB07784 \n"                      
"	B	loc_FF8B3508 \n"                       
"loc_FF8B3490:\n"
"	LDR	R0, [SP, #0x1C] \n"                  
"	LDR	R0, [R0] \n"                         
"	CMP	R0, #0xB \n"                         
"	BNE	loc_FF8B34D8 \n"                     
"	MOV	R3, #0 \n"                           
"	STR	R3, [SP] \n"                         
"	MOV	R3, #1 \n"                           
"	MOV	R2, #1 \n"                           
"	MOV	R1, #1 \n"                           
"	MOV	R0, #0 \n"                           
"	BL	sub_FF8AF988 \n"                      
"	MOV	R3, #0 \n"                           
"	STR	R3, [SP] \n"                         
"	MOV	R3, #1 \n"                           
"	MOV	R2, #1 \n"                           
"	MOV	R1, #1 \n"                           
"	MOV	R0, #0 \n"                           
"	B	loc_FF8B3504 \n"                       
"loc_FF8B34D8:\n"
"	MOV	R3, #1 \n"                           
"	MOV	R2, #1 \n"                           
"	MOV	R1, #1 \n"                           
"	MOV	R0, #1 \n"                           
"	STR	R3, [SP] \n"                         
"	BL	sub_FF8AF988 \n"                      
"	MOV	R3, #1 \n"                           
"	MOV	R2, #1 \n"                           
"	MOV	R1, #1 \n"                           
"	MOV	R0, #1 \n"                           
"	STR	R3, [SP] \n"  
                       
"loc_FF8B3504:\n"
"	BL	sub_FF8AFAC8 \n"  
                    
"loc_FF8B3508:\n"
"	LDR	R0, [SP, #0x1C] \n"                  
"	BL	sub_FF8B41C8 \n"                      
"	B	loc_FF8B2F78 \n" 	);
}


/*----------------------------------------------------------------------
	sub_FF8B07B4_my() - exp_drv_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) sub_FF8B07B4_my() {
asm volatile (
"	STMFD	SP!, {R4-R8,LR} \n"                
"	LDR	R7, =0x3C80 \n"                      
"	MOV	R4, R0 \n"                           
"	LDR	R0, [R7, #0x1C] \n"                  
"	MOV	R1, #0x3E \n"                        
"	BL	sub_FF87C810 \n"                      
"	LDRSH	R0, [R4, #4] \n"                   
"	MOV	R2, #0 \n"                           
"	MOV	R1, #0 \n"                           
"	BL	sub_FF8AF6EC \n"                      
"	MOV	R6, R0 \n"                           
"	LDRSH	R0, [R4, #6] \n"                   
"	BL	sub_FF8AF7FC \n"                      
"	LDRSH	R0, [R4, #8] \n"                   
"	BL	sub_FF8AF854 \n"                      
"	LDRSH	R0, [R4, #0xA] \n"                 
"	BL	sub_FF8AF8AC \n"                      
"	LDRSH	R0, [R4, #0xC] \n"                 
"	MOV	R1, #0 \n"                           
"	BL	sub_FF8AF904 \n"                      
"	MOV	R5, R0 \n"                           
"	LDR	R0, [R4] \n"                         
"	LDR	R8, =0x3C778 \n"                     
"	CMP	R0, #0xB \n"                         
"	MOVEQ	R6, #0 \n"                         
"	MOVEQ	R5, #0 \n"                         
"	BEQ	loc_FF8B07D0 \n"                     
"	CMP	R6, #1 \n"                           
"	BNE	loc_FF8B07D0 \n"                     
"	LDRSH	R0, [R4, #4] \n"                   
"	LDR	R1, =0xFF8AF658 \n"                
"	MOV	R2, #2 \n"                           
"	BL	sub_FF93638C \n"                      
"	STRH	R0, [R4, #4] \n"                    
"	MOV	R0, #0 \n"                           
"	STR	R0, [R7, #0x28] \n"                  
"	B	loc_FF8B07D8 \n"                       
"loc_FF8B07D0:\n"
"	LDRH	R0, [R8] \n"                        
"	STRH	R0, [R4, #4] \n"                    
"loc_FF8B07D8:\n"
"	CMP	R5, #1 \n"                           
"	LDRNEH	R0, [R8, #8] \n"                  
"	BNE	loc_FF8B07F4 \n"                     
"	LDRSH	R0, [R4, #0xC] \n"                 
"	LDR	R1, =0xFF8AF6DC \n"                
"	MOV	R2, #0x20 \n"                        
"	BL	sub_FF8B41F8 \n"                      
"loc_FF8B07F4:\n"
"	STRH	R0, [R4, #0xC] \n"                  
"	LDRSH	R0, [R4, #6] \n" 
                  
//"	BL	sub_FF8A2F60 \n"   
"	BL	sub_FF8A2F60_my \n"   //------------->>>   
                   
"	LDRSH	R0, [R4, #8] \n"                   
"	MOV	R1, #1 \n"                           
"	BL	sub_FF8A3638 \n"                      
"	MOV	R1, #0 \n"                           
"	ADD	R0, R4, #8 \n"                       
"	BL	sub_FF8A36C0 \n"                      
"	LDRSH	R0, [R4, #0xE] \n"                 
"	BL	sub_FF8AB1AC \n"                      
"	LDR	R4, =0xBB8 \n"                       
"	CMP	R6, #1 \n"                           
"	BNE	loc_FF8B084C \n"                     
"	LDR	R0, [R7, #0x1C] \n"                  
"	MOV	R2, R4 \n"                           
"	MOV	R1, #2 \n"                           
"	BL	sub_FF87C71C \n"                      
"	TST	R0, #1 \n"                           
"	SUBNE	R1, R4, #0x620 \n"                 
"	LDRNE	R0, =0xFF8AFCDC \n"                
"	BLNE	sub_FF81E88C \n"                    
"loc_FF8B084C:\n"
"	CMP	R5, #1 \n"                           
"	LDMNEFD	SP!, {R4-R8,PC} \n"              
"	LDR	R0, [R7, #0x1C] \n"                  
"	MOV	R2, R4 \n"                           
"	MOV	R1, #0x20 \n"                        
"	BL	sub_FF87C71C \n"                      
"	TST	R0, #1 \n"                           
"	LDRNE	R1, =0x59D \n"                     
"	LDRNE	R0, =0xFF8AFCDC \n"              
"	LDMNEFD	SP!, {R4-R8,LR} \n"              
"	BNE	sub_FF81E88C \n"                     
"	LDMFD	SP!, {R4-R8,PC} \n"               
	);
}


/*----------------------------------------------------------------------
	sub_FF8A2F60_my() - exp_drv_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) sub_FF8A2F60_my() {
asm volatile (
"	STMFD	SP!, {R4-R6,LR} \n"                
"	LDR	R5, =0x3998 \n"                      
"	MOV	R4, R0 \n"                           
"	LDR	R0, [R5, #4] \n"                     
"	CMP	R0, #1 \n"                           
"	LDRNE	R1, =0x146 \n"                     
"	LDRNE	R0, =0xFF8A2CEC \n"                
"	BLNE	sub_FF81E88C \n"                    
"	CMN	R4, #0xC00 \n"                       
"	LDREQSH	R4, [R5, #2] \n"                 
"	CMN	R4, #0xC00 \n"                       
"	MOVEQ	R1, #0x14C \n"                     
"	LDREQ	R0, =0xFF8A2CEC \n"                
"	STRH	R4, [R5, #2] \n"                    
"	BLEQ	sub_FF81E88C \n"                    
"	MOV	R0, R4 \n"    

//"	BL	sub_FF9D5360 \n"    	// old??? apex2us                   
"	BL	apex2us\n"		//--------------->>            
                     
"	MOV	R4, R0 \n"                           
//"	BL	sub_FF8D7AE8 \n"                      
"	MOV	R0, R4 \n"                           
"	BL	sub_FF8DB75C \n"                      
"	TST	R0, #1 \n"                           
"	LDRNE	R1, =0x151 \n"                     
"	LDMNEFD	SP!, {R4-R6,LR} \n"              
"	LDRNE	R0, =0xFF8A2CEC \n"                
"	BNE	sub_FF81E88C \n"                     
"	LDMFD	SP!, {R4-R6,PC} \n"               
	);
}

