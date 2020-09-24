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
myStr: 		.cstring	"Do 42+53/76%8=2*8$3271 & you can sleep."
myInt:		.int		0
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

main:		bis.b	#0FFh, &P1DIR			; configure P1.x as output
			mov		#myStr, R4				; move mystring to r4
			mov		#myInt, r8

			clr.b 	R5						; use r5 as the counter

gnext:		mov.b 	@R4+, R6				; get a new character
			cmp 	#0, R6					; see if r6 is a null character
			jeq		lend
			cmp.b 	#'+', R6;				; see if R6 = "+"
			jeq		eadd
			cmp.b 	#'-', R6;				; see if R6 = "-"
			jeq		eadd
			cmp.b 	#'*', R6;				; see if R6 = "*"
			jeq		eadd
			cmp.b 	#'/', R6;				; see if R6 = "/"
			jeq		eadd
			cmp.b 	#'%', R6;				; see if R6 = "%"
			jeq		eadd
			cmp.b 	#'&', R6;				; see if R6 = "&"
			jeq		eadd
			cmp.b 	#'<', R6;				; see if R6 = "<"
			jeq		eadd
			cmp.b 	#'>', R6;				; see if R6 = ">"
			jeq		eadd
			cmp.b 	#'=', R6;				; see if R6 = "="
			jeq		eadd
			jmp		gnext					; go back to gnext

eadd:		inc		R5						; increment R5 by one
			jmp		gnext					; go back to gnext


lend:		mov 	r5, myInt
			mov.b 	R5, &P1OUT
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
            
