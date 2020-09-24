			.cdecls C,LIST,"msp430.h"       ; Include device header file
			.def	HW_product
			.text

HW_product:
			mov		10(SP), r14					; address of ans 1
			mov		6(SP), r4					; get address of arr1
			mov		4(SP), r5					; get the address of array 2
			mov		2(SP), r8					; get the number of elements


mul:		cmp		#0, r8
			jz		end
			mov		@r4+, r6					; get next element of arr1
			mov 	@r5+, r7					; get next element of arr2
			mov		r6, &MPY					; load first operand
			mov		r7, &OP2					; load second operand
			dec		r8
			mov		RESLO, 0(r14)
			add		#2, r14
			jmp		mul

end:		ret
			.end



