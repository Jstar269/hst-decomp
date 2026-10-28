/* HSTMATCH module=EBOOT.BIN start=0x000b9edc end=0x000b9efc symbol=FUN_000b9edc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_000b9edc(int param_1)
{
  int iVar1;
  
  iVar1 = (*(int *)(param_1 + 0x6c) + 1) % 3;
  *(int *)(param_1 + 0x6c) = iVar1;
  *(int *)(param_1 + 100) = iVar1;
}
