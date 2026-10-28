/* HSTMATCH module=EBOOT.BIN start=0x0016b19c end=0x0016b1bc symbol=FUN_0016b19c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern int FUN_0016b21c();

int FUN_0016b19c(void)
{
  int iVar1;
  
  iVar1 = FUN_0016b21c();
  return (int)*(short *)(iVar1 + 2);
}
