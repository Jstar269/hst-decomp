/* HSTMATCH module=EBOOT.BIN start=0x00114fdc end=0x00115000 symbol=FUN_00114fdc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

int FUN_00114fdc(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + param_2 * 4);
  return (int)(short)(*(short *)(iVar1 + 8) - *(short *)(iVar1 + 4));
}
