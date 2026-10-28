/* HSTMATCH module=EBOOT.BIN start=0x0016b1bc end=0x0016b1dc symbol=FUN_0016b1bc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern int FUN_0016b270();

int FUN_0016b1bc(void)
{
  int iVar1;
  
  iVar1 = FUN_0016b270();
  return (int)*(short *)(iVar1 + 2);
}
