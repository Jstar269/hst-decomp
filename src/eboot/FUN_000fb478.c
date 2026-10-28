/* HSTMATCH module=EBOOT.BIN start=0x000fb478 end=0x000fb4ac symbol=FUN_000fb478 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */

extern void FUN_000f6998(int param_1,int param_2,float *param_3);

void FUN_000fb478(int param_1,int param_2,float *param_3)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x3c) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x8c), iVar1 != 0)) {
    FUN_000f6998(iVar1,param_2,param_3);
  }
}
