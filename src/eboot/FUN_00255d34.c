/* HSTMATCH module=EBOOT.BIN start=0x00255d34 end=0x00255d74 symbol=FUN_00255d34 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_00255d34(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + param_2 * 0xa4 + param_3 * 4);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x28) + param_4;
  }
}
