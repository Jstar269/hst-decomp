/* HSTMATCH module=EBOOT.BIN start=0x001ec418 end=0x001ec488 symbol=FUN_001ec418 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_001ec418(int *param_1)
{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *param_1 = 0;
  }
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    delete ((VC_1 *)(piVar1));
    param_1[1] = 0;
  }
}
