/* HSTMATCH module=EBOOT.BIN start=0x000b7880 end=0x000b7890 symbol=FUN_000b7880 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_000b7880(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
