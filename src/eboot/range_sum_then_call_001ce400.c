/* HSTMATCH module=EBOOT.BIN start=0x001ce400 end=0x001ce440 symbol=FUN_001ce400 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the accumulator is a separate register local copied into the address-taken local after the loop, and the callee gets its four arguments; exact match verified; names and types await human review. */
extern int * FUN_001ce8c8(int *a, int *b, int c, int *d);

void FUN_001ce400(int *param_1,int *param_2,char param_3)
{
  int *piVar1;
  int sum;
  int local_4;

  sum = 0;
  for (piVar1 = param_1; piVar1 != param_2; piVar1 = piVar1 + 1) {
    sum = sum + *piVar1;
  }
  local_4 = sum;
  FUN_001ce8c8(param_1,param_2,(int)param_3,&local_4);
  return;
}
