;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
myStr:		.cstring "3+2+1-7"
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------

main:		bis.b	#0FFh,&P2DIR
			mov 	#myStr, r4				; move myStr to r4
			mov.b	@r4+, r5				; priming read
			sub.b 	#48, r5					; convert r5 to int

gnext:		mov.b	@r4+, r6				; move the operand to r6
			cmp		#0, r6				; see if r6 is a null charcter
			jeq		end						; jump to lend
			mov.b	@r4+, r7				; move next character to r7
			sub.b	#48, r7					; convert character to int
			cmp		#'+', r6				; see if r6 is equal to +
			jeq		addS					; if yes, jump to addS
			cmp		#'-', r6				; see if r6 is equal to -
			jeq		subS					; if yes, jump to subS

addS:		add.b	r7, r5					; add r7 and r5
			jmp		gnext					; go back to gnext

subS:		sub.b	r7, r5					; sub r7 from r5
			jmp		gnext					; go back to gnext

end:		mov 	R5, &P2OUT
			bis.w	#LPM4, SR				; LPM4
			nop								; required for debugger

                                            

;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
            
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            
