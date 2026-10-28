/* HSTMATCH module=EBOOT.BIN start=0x001fb978 end=0x001fb9dc symbol=FUN_001fb978 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001fb978(int *param_1,int param_2)
{
  ((VC_0 *)(param_1))->m((int)(param_1[1]));
  param_1[5] = param_1[1];
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  ((VC_1 *)(param_1))->m((int)(param_2));
}
