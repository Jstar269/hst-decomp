/* HSTMATCH module=EBOOT.BIN start=0x001fe888 end=0x001fe8c0 symbol=FUN_001fe888 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

int FUN_001fe888(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (*param_1 != 0x7fffffff) {
      iVar1 = iVar1 + 1;
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 8;
  } while (iVar2 < 10);
  return iVar1;
}
