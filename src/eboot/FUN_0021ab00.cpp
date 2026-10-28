/* HSTMATCH module=EBOOT.BIN start=0x0021ab00 end=0x0021ab48 symbol=FUN_0021ab00 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_0021ab00(int *param_1)
{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *param_1 = 0;
  }
}
