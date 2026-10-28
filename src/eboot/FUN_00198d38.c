/* HSTMATCH module=EBOOT.BIN start=0x00198d38 end=0x00198d68 symbol=FUN_00198d38 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_00198d38.c; exact match verified; names and types await human review. */

int FUN_00198d38(int param_1,int param_2)
{
  int iVar1;
  
  if (param_2 >= 0 && (param_2 < 4)) {
    iVar1 = param_1 + param_2 * 8 + 0xa0;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
