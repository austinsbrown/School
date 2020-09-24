;
;	CPE 221 Assembly Example
;	
;	This program calculates a tax rate based on the value of income as
;      follows.
;      if (income < level1)
;        tax = 0;
;      else 
;        if (income < level2)
;          tax = 5;
;        else
;          tax = 10;
;

       AREA MULTI_WAY_IF, CODE, READWRITE
       ENTRY
	   LDR   r0, income
	   LDR   r1, level1
	   LDR   r2, level2
       MOV   r10, #0
       SUBS  r11, r0, r1
       BMI   done
       SUBS  r11, r0, r2
       BMI   five
       MOV   r10, #10
       B     done
five   MOV   r10, #5
done   STR   r10, tax
income DCD  25000
level1 DCD  15000
level2 DCD  25000
tax    SPACE   8
       END

