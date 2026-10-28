/* HSTMATCH module=hstp_trans_main.prx start=0x00138d68 end=0x00138d90 symbol=FUN_00138d68 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */

extern void FUN_0005ff00();

void FUN_00138d68(int param_1)
{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0005ff00(*(int *)(param_1 + 4));
  }
}
