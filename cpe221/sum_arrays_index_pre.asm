;
;      CPE 221 Assembly Example
;
;      This program adds each corresponding element of two arrays and
;      stores the results in a third array.
;
;      int main()
;      {
;        const int size = 10;
;        int x[size] = {100, 3, -1, 2, 4, 4, 2, -1, 3, 100};
;        int y[size] = {-53, 247, 95, -7, 481, 91, -33, 1500, 29 -83};
;        int z[size];
;        int i;
;        for (i = 0; i < size; i++)
;          z[i] = x[i] + y[i];
;      }
;
       AREA  SUM_ARRAYS, CODE, READONLY
       ADR    r0, x - 4              ; pointer to 4 bytes before &x[0]
       ADR    r1, y - 4              ; pointer to 4 bytes before &y[0]
       ADR    r2, z - 4              ; pointer to 4 bytes before &z[0]
       LDR    r3, size               ; holds size of arrays
       LDR    r4, i                  ; holds loop counter
loop   CMP    r4, r3             ; compute i - size
       BPL    done                   ; if i - size >= 0, done
       LDR    r5, [r0, #4]!   ; r5 = x[i]
       LDR    r6, [r1, #4]!   ; r6 = y[i]
       ADD    r5, r5, r6      ; r5 = x[i] + y[i]
       STR    r5, [r2, #4]!  ; store result in z[i]
       ADD    r4, r4, #1
       B      loop
done   B      done
size   DCD    10
i      DCD    0
x      DCD    100, 3, -1, 2, 4, 4, 2, -1, 3, 100 
y      DCD    -53, 247, 95, -7, 481, 91, -33, 1500, 29, -83
z      SPACE  40
	   END

