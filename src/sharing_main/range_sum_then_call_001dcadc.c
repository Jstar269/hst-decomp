/* HSTMATCH module=hstp_trans_main.prx start=0x001dcadc end=0x001dcb1c symbol=FUN_001dcadc lang=c99 */
/* Clone of src/eboot/range_sum_then_call_001ce400.c (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the accumulator is a separate register local copied into the address-taken local after the loop, and the callee gets its four arguments; exact match verified; names and types await human review. */
extern int * FUN_001dcfa4(int *a, int *b, int c, int *d);

void FUN_001dcadc(int *param_1,int *param_2,char param_3)
{
  int *piVar1;
  int sum;
  int local_4;

  sum = 0;
  for (piVar1 = param_1; piVar1 != param_2; piVar1 = piVar1 + 1) {
    sum = sum + *piVar1;
  }
  local_4 = sum;
  FUN_001dcfa4(param_1,param_2,(int)param_3,&local_4);
  return;
}
