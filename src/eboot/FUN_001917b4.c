/* HSTMATCH module=EBOOT.BIN start=0x001917b4 end=0x001917f8 symbol=FUN_001917b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

void FUN_001917b4(int *param_1,int *param_2)
{
  int iVar1;
  
  *param_1 = param_2[3] + param_2[2] * 4;
  iVar1 = param_2[3];
  param_1[1] = iVar1;
  param_1[2] = iVar1 + param_2[2] * 4;
  param_1[3] = param_1[1] + *param_2 * 4;
}
