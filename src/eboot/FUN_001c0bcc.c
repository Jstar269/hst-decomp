/* HSTMATCH module=EBOOT.BIN start=0x001c0bcc end=0x001c0c0c symbol=FUN_001c0bcc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern void FUN_00000a00();

int FUN_001c0bcc(int param_1,short param_2)
{
  if ((param_1 != 0) && (0 < param_2)) {
    FUN_00000a00();
  }
  return param_1;
}
