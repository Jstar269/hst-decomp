/* HSTMATCH module=EBOOT.BIN start=0x000fb4d0 end=0x000fb504 symbol=FUN_000fb4d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */

extern void FUN_000f6998(int param_1,int param_2,float *param_3);

void FUN_000fb4d0(int param_1,int param_2,float *param_3)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x3c) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x90), iVar1 != 0)) {
    FUN_000f6998(iVar1,param_2,param_3);
  }
}
