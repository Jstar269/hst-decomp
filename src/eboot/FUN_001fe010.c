/* HSTMATCH module=EBOOT.BIN start=0x001fe010 end=0x001fe04c symbol=FUN_001fe010 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern void FUN_001fdbb4();
extern void FUN_001fdd50();
extern void FUN_00201910();
extern void FUN_00201dc8();

void FUN_001fe010(int param_1)
{
  FUN_001fdd50();
  FUN_001fdbb4(param_1);
  FUN_00201910(param_1 + 200);
  FUN_00201dc8(param_1 + 0x1250);
}
