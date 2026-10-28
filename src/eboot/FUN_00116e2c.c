/* HSTMATCH module=EBOOT.BIN start=0x00116e2c end=0x00116e3c symbol=FUN_00116e2c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_00116e2c(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
