PROGRAM program1
  VAR
    PB1 AT %IX100.0 : BOOL;
    PB2 AT %IX100.1 : BOOL;
    LAMP AT %QX100.0 : BOOL;
  END_VAR

  LAMP := NOT(PB2) AND (LAMP OR PB1);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program1;
  END_RESOURCE
END_CONFIGURATION
