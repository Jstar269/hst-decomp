/* HSTMATCH module=hstp_trans_main.prx start=0x0001badc end=0x0001bb2c symbol=FUN_0001badc lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_0001bc34();

int FUN_0001badc(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_0001bc34(), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
