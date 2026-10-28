/* HSTMATCH module=EBOOT.BIN start=0x00115000 end=0x00115020 symbol=FUN_00115000 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

int FUN_00115000(int param_1)
{
  return (int)(short)(*(short *)((*(int **)(param_1 + 0x10))[6] + 10) -
                     *(short *)(**(int **)(param_1 + 0x10) + 6));
}
