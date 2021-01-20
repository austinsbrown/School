PROGRAM exercise2
  VAR
    count AT %MW8 : INT;
    color0 AT %MW0 : INT;
    color1 AT %MW1 : INT;
    color2 AT %MW2 : INT;
    color3 AT %MW3 : INT;
    color4 AT %MW4 : INT;
    color5 AT %MW5 : INT;
    color6 AT %MW6 : INT;
    color7 AT %MW7 : INT;
    red_anode AT %QX100.0 : BOOL;
    green_anode AT %QX100.1 : BOOL;
    blue_anode AT %QX100.2 : BOOL;
    button AT %IX100.0 : BOOL;
    mode AT %QX0.0 : BOOL;
  END_VAR
  VAR
    count_en : BOOL;
    auto_count_en : BOOL;
    CTU0 : CTU;
    TON0 : TON;
    TON1 : TON;
    MUX6_OUT : INT;
    MOD15_OUT : INT;
    INT_TO_BOOL25_OUT : BOOL;
    R_TRIG1 : R_TRIG;
    DIV18_OUT : INT;
    MOD16_OUT : INT;
    INT_TO_BOOL26_OUT : BOOL;
    SEL32_OUT : BOOL;
    DIV19_OUT : INT;
    MOD17_OUT : INT;
    INT_TO_BOOL27_OUT : BOOL;
  END_VAR

  MUX6_OUT := MUX(count, color0, color1, color2, color3, color4, color5, color6, color7);
  MOD15_OUT := MOD(MUX6_OUT, 2);
  INT_TO_BOOL25_OUT := INT_TO_BOOL(MOD15_OUT);
  blue_anode := INT_TO_BOOL25_OUT;
  R_TRIG1(CLK := count_en);
  CTU0(CU := R_TRIG1.Q, R := CTU0.Q, PV := 8);
  count := CTU0.CV;
  DIV18_OUT := DIV(MUX6_OUT, 2);
  MOD16_OUT := MOD(DIV18_OUT, 2);
  INT_TO_BOOL26_OUT := INT_TO_BOOL(MOD16_OUT);
  green_anode := INT_TO_BOOL26_OUT;
  SEL32_OUT := SEL(mode, button, auto_count_en);
  count_en := SEL32_OUT;
  DIV19_OUT := DIV(DIV18_OUT, 2);
  MOD17_OUT := MOD(DIV19_OUT, 2);
  INT_TO_BOOL27_OUT := INT_TO_BOOL(MOD17_OUT);
  red_anode := INT_TO_BOOL27_OUT;
  TON0(IN := NOT(auto_count_en), PT := T#750ms);
  IF TON0.Q THEN
    auto_count_en := TRUE; (*set*)
  END_IF;
  TON1(IN := auto_count_en, PT := T#750ms);
  IF TON1.Q THEN
    auto_count_en := FALSE; (*reset*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : exercise2;
  END_RESOURCE
END_CONFIGURATION
