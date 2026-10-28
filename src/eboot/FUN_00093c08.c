/* HSTMATCH module=EBOOT.BIN start=0x00093c08 end=0x00093c30 symbol=FUN_00093c08 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */

extern void FUN_00059100();

void FUN_00093c08(int param_1,int param_2)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_00059100(*(int *)(param_1 + 0x58),param_2);
  }
}
