			.cdecls C,LIST,"msp430.h"       ; Include device header file
			.def	SW_product
			.text

SW_product:
			mov		8(SP), r15					; address of ans2
			mov		6(SP), r4					; get address of arr1
			mov		4(SP), r5					; get the address of array 2
			mov		2(SP), r8					; get the number of elements



gnext:		cmp 	#0, r8
			jz		rend
			mov		@r4+, r6					; get next element of arr1
			mov 	@r5+, r7					; get next element of arr2
			clr		r11							; clear r11
			mov		#8, r9						; move number of bits to r9

mul:		cmp		#0, r9						; see if at the end of binary number
			jeq		lend						; if so, jump to lend
			cmp		#1, r9						; check sign bit
			jeq		neg
			bit.b	#1, r7						; see if bit is 1
			jne		sum							; if yes, go to sum
			jmp		rotate						; else, go to rotate

sum:		add		r6, r11						; use r11 as placeholder
			rla.b	r6							; rotate r6
			rra.b	r7							; rotate r7
			dec 	r9							; dec r9
			jmp 	mul							; jump to mul

rotate:		rla.b	r6							; rotate r6
			rra.b	r7							; rotate r7
			dec		r9							; dec r9
			jmp 	mul							; jump to mul

neg:		bit		#1, r7
			jne		neg2
			bit		#1, r6
			jne		neg1
			jmp		lend

neg1:		sub		r6, r11
			jmp		lend

neg2:		bit		#1, r6
			jne		lend
			sub		r6, r11

lend:		dec		r8							; dec r8
			mov		r11, 0(r15)					; move r11 to r14
			add		#2, r15						; inc r14
			jmp		gnext						; go to gnext

rend:		ret
			.end



