/* HSTMATCH module=EBOOT.BIN start=0x002b7450 end=0x002b74b8 symbol=FUN_002b7450 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: the function takes a trailing empty by-value tag parameter that Ghidra omits (it adds 16 bytes of frame); exact match verified; names and types await human review. */
struct False {};
struct VC_0 { virtual void m(int); };

extern "C" void FUN_002b7450(int *param_1, int param_2, False)
{
  int *piVar1;

  piVar1 = (int *)(*param_1 + param_1[1] * 8);
  param_1[1] = param_1[1] - param_2;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    piVar1 = piVar1 + -2;
    ((VC_0 *)(piVar1))->m((int)(0xffffffff));
  }
}
