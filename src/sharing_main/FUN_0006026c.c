/* HSTMATCH module=hstp_trans_main.prx start=0x0006026c end=0x000602c8 symbol=FUN_0006026c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */

extern void FUN_00000a00();

int * FUN_0006026c(int *param_1,short param_2)
{
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      FUN_00000a00(*param_1);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
