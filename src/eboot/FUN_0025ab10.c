/* HSTMATCH module=EBOOT.BIN start=0x0025ab10 end=0x0025ab40 symbol=FUN_0025ab10 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_0025ab10(int *param_1)
{
  int iVar1;
  
  param_1[1] = param_1[1] + -1;
  iVar1 = param_1[2];
  param_1[2] = iVar1 + 1;
  if (iVar1 + 1 == *param_1) {
    param_1[2] = 0;
  }
}
