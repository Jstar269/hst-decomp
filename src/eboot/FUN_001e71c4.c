/* HSTMATCH module=EBOOT.BIN start=0x001e71c4 end=0x001e722c symbol=FUN_001e71c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e722c();

void FUN_001e71c4(int param_1,int param_2,int param_3,int param_4)
{
  FUN_001e2694(param_1);
  FUN_00103628(*(int *)(param_1 + 0x810),0);
  FUN_001e722c(param_1,param_2,param_3,param_4);
}
