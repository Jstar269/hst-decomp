/* HSTMATCH module=EBOOT.BIN start=0x001c6328 end=0x001c6354 symbol=FUN_001c6328 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */

extern void FUN_0015a304();

void FUN_001c6328(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x15c) + 0x58);
  if (iVar1 != 0) {
    FUN_0015a304(iVar1);
  }
}
