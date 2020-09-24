
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file

;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
            .def    SW1_ISR
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET:      mov.w   #__STACK_END, SP        ; Initialize stack pointer
StopWDT:    mov.w   #WDTPW|WDTHOLD, &WDTCTL ; Stop watchdog timer
;-------------------------------------------------------------------------------
Setup:


            bis.b   #006h, &P2DIR           ; Set P2.2 to output
            bic.b   #006h, &P2OUT
                                            ; (ensure LED1 is off)
            bis.w   #GIE, SR                ; Enable Global Interrupts
            bis.b   #003h, &P1IE            ; Enable Port 1 interrupt from bit 0
            bis.b   #003h, &P1IES           ; Set interrupt to call from hi to low
            bic.b   #003h, &P1IFG           ; Clear interrupt flag
            mov		#1, r8


InfLoop:
            cmp		#0, r8                  ; Loop here until interrupt
            jnz		InfLoop					; go to InfLoop

prepBlink:	mov		#50000, r5				; set up delay counter
			mov		#6, r7					; times to blink

loop:		dec		r5						; delay
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			jnz		loop
			xor.b	#004h, &P2OUT			; alternate led1
			dec		r7						; amount of times to blink
			cmp		#0, r7
			jnz		loop
			add.b	#1, r8					; prepare to do an infinite loop
			bic.b	#004h, &P2OUT			; turn led1 off
			xor.b	#002h, &P2OUT			; alternate led2
			jmp		InfLoop					; go to InfLoop

                                            
;----------------------------------------------------------------------------
; P1_0 (SW1) interrupt service routine (ISR)
;----------------------------------------------------------------------------



SW1_ISR:
            bic.b   #003h, &P1IFG           ; Clear interrupt flag
     		bit.b   #02h, &P1IN             ; Check if SW2 is pressed
			jeq		SW2                		; loop and check again
            bit.b	#01h, &P1IN				; test sw1
			jeq		SW1
			jnz		LExit

SW1:		mov		#1, r4					; move 1 to test register
			jmp		Debounce				; go to Debounce

SW2:		mov		#2, r4					; move 2 to test register
			jmp		Debounce

Debounce:   mov.w   #2000, R15              ; Set to (2000 * 10 cc )
SWD20ms:    dec.w   R15                     ; Decrement R15
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            jnz     SWD20ms                	; Delay over?
            cmp		#2, r4					; see what buttone was pressed
            jeq		LED2on
            cmp		#1, r4					; see what buttone was pressed
         	jeq		blink

LED2on:     clr		r4
			xor.b   #002h, &P2OUT           ; Turn on LED2

SW2Wait:	bit.b	#02, &P1IN				; wait for button to be unpressed
			jz		SW2Wait
			jmp 	LExit

blink:		mov		#0, r8


LExit:
			reti                            ; Return from interrupt



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
            .sect   ".int20"                ;P1.x Vector
            .short  SW1_ISR
            .end
