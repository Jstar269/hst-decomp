/* HSTMATCH module=hstp_trans_main.prx start=0x00002b04 end=0x00002b60 symbol=FUN_00002b04 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_00004408();

int FUN_00002b04(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 4) != 0) {
      FUN_00004408(*(int *)(param_1 + 4));
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
