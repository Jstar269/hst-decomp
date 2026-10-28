/* HSTMATCH module=EBOOT.BIN start=0x0010749c end=0x001074ac symbol=FUN_0010749c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_0010749c(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
