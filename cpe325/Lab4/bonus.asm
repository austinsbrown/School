;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.

            .data
myStr:		.cstring	"I enjoy Learning msp430"

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

main:		mov		#myStr, r4

loop:		mov.b	@r4+, r5				; move character to r5
			cmp		#0, r5					; see if r5 is null
			jeq		end						; if null, go to end
			cmp		#93, r5					; see if r5 is uppercase
			jl		next					; if yes, loop
			cmp		#96, r5					; see if r5 is lowercase
			jge		convert					; if yes, go to convert

next:		jmp		loop

convert:	sub.b	#32, r5					; convert lowercase to upper
			mov.b	r5, -1(r4)
			jmp		loop



end:		mov.b 	R4, &P1OUT
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
            
