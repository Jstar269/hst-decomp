/* HSTMATCH module=EBOOT.BIN start=0x000d7e30 end=0x000d7e70 symbol=FUN_000d7e30 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

extern void FUN_00000a00();

int FUN_000d7e30(int param_1,short param_2)
{
  if ((param_1 != 0) && (0 < param_2)) {
    FUN_00000a00();
  }
  return param_1;
}
