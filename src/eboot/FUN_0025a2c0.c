/* HSTMATCH module=EBOOT.BIN start=0x0025a2c0 end=0x0025a2ec symbol=FUN_0025a2c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

int * FUN_0025a2c0(int *param_1)
{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + 4;
  if (iVar1 + 4 == param_1[3]) {
    *param_1 = param_1[1];
  }
  return param_1;
}
