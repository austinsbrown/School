
;           CPE 221 Assembly Example
;           
;           This program multiplies two numbers by repeated addition.
;           First, take absolute values of both numbers, do multiplication,
;           then adjust result as necessary. Taking the absolute value is done
;           as a subroutine and the multiplication is a subroutine. Main 
;           loads numbers in and stores the result.

;           int mpy_ne(int, int)
;           int abs(int)

;           int main()
;           {
;             int first = 8;
;             int second = -9;
;             int result;
;             result = mpy_ne(first, second);
;           }

;           int  mpy_ne (int num1; int num2)
;           {
;             int a, b, mult;
;             a = abs(num1);
;             b = abs(num2);
;             mult = 0;
;             for (i = 0; i < a; i++)
;               mult = mult + b;
;             if (num1 < 0)
;               mult = -mult;
;             if (num2 < 0)
;               mult = -mult;
;             return mult;
;           }

;           int abs(int x)
;           {
;             if (x < 0)
;               x = -x;
;             return x;
;           }

        AREA MULTIPLY_BY_ADDING_SUBFRAME, CODE, READONLY
        ENTRY
main    LDR   r1, num1       ; Put num1 in r1. (0)
        LDR   r2, num2       ; Put num2 in r2. (4)
        LDR   r3, num3       ; (8)
        LDR   r4, num4       ; (12)
        MOV   fp, sp                                ; Slide 8 (16)
        SUB   sp, sp, #12                           ; Slide 9 (20)
        STR   r1, [fp, #-4]                         ; Slide 10 (24)
        STR   r2, [fp, #-8]                         ; Slide 11 (28)
        BL    mpy_ne          ; call mpy_ne (32)
        LDR   r5, [fp, #-12]  ; pull result off the stack (36)
        STR   r5, case1       ; save result in case1 (40)
        MOV   sp, fp          ; collapse the frame    Slide 39 (44)
final   B     final           ; infinite loop at end (48)


mpy_ne  PUSH  {lr}                  ; prepare for calling subroutine Slide 12 (52)
        PUSH  {r0, r1, r3, r4, r5}  ; by storing lr and              Slide 13 (56)
                                    ; other working registers
        LDR   r0, [fp, #-8]         ; copy first parameter from stack (60)
        LDR   r1, [fp, #-4]         ; copy second parameter from stack (64)
        MOV   r3, #0                ; Set r3 to 0, it will hold the result. (68)
        TEQ   r0, #0                ; Is num1 = 0? (72)
        BEQ   done                  ; If so we are done, result = 0. (76)
        TEQ   r1, #0                ; Is num2 = 0? (80)
        BEQ   done                  ; If so, we are done, result = 0. (84)
        PUSH  {fp}                  ; More prep, store old frame 
                                    ; pointer                        Slide 14 (88)
        MOV   fp, sp                ; Set new frame pointer          Slide 15 (92)
        SUB   sp, sp, #8            ; Make room on stack for input
                                    ; and output parameters for abs  Slide 16 (96)
        STR   r1, [fp, #-4]         ; Put input for abs on stack     Slide 17 (100)
        BL    abs                   ; Go to abs (104)
        LDR   r4, [fp, #-8]         ; Copy num1 to r4 for loop control. (108)
        MOV   sp, fp                ; Collapse frame                 Slide 23 (112)
        POP   {fp}                  ; Get frame pointer off stack    Slide 24 (116)
        PUSH  {fp}                  ; Prepare, store frame pointer   Slide 25 (120)
        MOV   fp, sp                ; Set new frame pointer          Slide 26 (124)
        SUB   sp, sp, #8            ; Make room on stack for input
                                    ; and output parameters for abs  Slide 27 (128)
        STR   r0, [fp, #-4]         ; Put input for abs on stack     Slide 28 (132)
        BL    abs                   ; Go to abs (136)
        LDR   r5, [fp, #-8]         ; Get abs result (140)
        MOV   sp, fp                ; Collapse frame                 Slide 34 (144)
        POP   {fp}                  ; Get frame pointer off stack    Slide 35 (148)
adding  ADD   r3, r3, r5            ; Already handled 0 case, add num2 once. (152)
        SUBS  r4, r4, #1            ; Decrement r4. (156)
        BEQ   adjust                ; If r4 = 0, done adding, go to adjust. (160)
        B     adding                ; Need to add again. (164)
adjust  MOVS  r0, r0                ; Done adding, now adjust sign of result. (168)
        RSBMI r3, r3, #0            ; If num2 negative, negate result. (172)
        MOVS  r1, r1                ; (176)
        RSBMI r3, r3, #0            ; If num1 negative, negate result. (180)
done    STR   r3, [fp, #-12]        ; Push result for return to main Slide 36 (184)
        POP   {r0, r1, r3, r4, r5}  ; Restore old register values    Slide 37 (188)
        POP   {pc}                  ; Return to main                 Slide 38 (192)
abs     PUSH  {lr}                  ; Prepare for call             Slides 18, 29 (196)
        PUSH  {r0}                  ; Store r0 before using        Slides 19. 30 (200)
        LDR   r0, [fp, #-4]         ; Copy input into r0 (204(
        CMP   r0, #0                ; Compare to 0 (208)
        BPL   d_abs                 ; If positive, no need to adjust (212)
        RSB   r0, r0, #0            ; If negative, take –x (216)
d_abs   STR   r0, [fp, #-8]         ; Put result on stack          Slides 20, 31 (220)
        POP   {r0}                  ; Restore old r0 value         Slides 21, 32 (224)
        POP   {pc}                  ; Return to mpy_ne             Slides 22, 33 (228)
num1    DCD   8                     ; (232)
num2    DCD   9                     ; (236)
num3    DCD   -8                    ; (240)
num4    DCD   -9                    ; (244)
case1   SPACE 4                     ; (248)
            END
