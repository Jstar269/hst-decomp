/* HSTMATCH module=EBOOT.BIN start=0x00218ab0 end=0x00218ae4 symbol=FUN_00218ab0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */

int FUN_00218ab0(int param_1)
{
  int iVar1;
  
  if (param_1 == 500) {
    iVar1 = 9;
  }
  else {
    iVar1 = param_1 / 10;
  }
  return iVar1;
}
