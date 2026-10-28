/* HSTMATCH module=EBOOT.BIN start=0x0005f47c end=0x0005f4d8 symbol=FUN_0005f47c lang=c99 */
/* Clone of src/sharing_main/FUN_0006026c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();

int * FUN_0005f47c(int *param_1,short param_2)
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
