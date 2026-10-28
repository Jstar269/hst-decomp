/* HSTMATCH module=EBOOT.BIN start=0x002a038c end=0x002a03c0 symbol=FUN_002a038c lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };

extern "C" void FUN_002a038c(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x1b0);
  if (piVar1 != (int *)0x0) {
    ((VC_0 *)(piVar1))->m((int)(1));
  }
}
