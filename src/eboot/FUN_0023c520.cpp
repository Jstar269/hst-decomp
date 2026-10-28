/* HSTMATCH module=EBOOT.BIN start=0x0023c520 end=0x0023c568 symbol=FUN_0023c520 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0023c520(int param_1)
{
  ((VC_0 *)(*(int **)(param_1 + 8)))->m((int)(0));
  ((VC_1 *)(*(int **)(param_1 + 0x28)))->m((int)(0));
}
