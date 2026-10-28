/* HSTMATCH module=EBOOT.BIN start=0x0019d208 end=0x0019d230 symbol=FUN_0019d208 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */

extern void FUN_0019be18();

void FUN_0019d208(int param_1)
{
  if (*(int *)(param_1 + 0x90) != 0) {
    FUN_0019be18(param_1);
  }
}
