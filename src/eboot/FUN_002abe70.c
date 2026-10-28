/* HSTMATCH module=EBOOT.BIN start=0x002abe70 end=0x002abe88 symbol=FUN_002abe70 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */

void FUN_002abe70(char *param_1,int param_2)
{
  if (param_2 != *(int *)(param_1 + 0x54)) {
    *(int *)(param_1 + 0x54) = param_2;
  }
}
