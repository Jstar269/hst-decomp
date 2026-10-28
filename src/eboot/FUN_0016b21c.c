/* HSTMATCH module=EBOOT.BIN start=0x0016b21c end=0x0016b270 symbol=FUN_0016b21c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_0016b21c.c; exact match verified; names and types await human review. */

extern int FUN_0016bb88();

int FUN_0016b21c(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0016bb88();
  if (0 <= param_1 && (param_1 < 0xf)) {
    iVar1 = iVar1 + param_1 * 0x38 + 4;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
