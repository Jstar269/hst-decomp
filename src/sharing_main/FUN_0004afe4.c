/* HSTMATCH module=hstp_trans_main.prx start=0x0004afe4 end=0x0004b034 symbol=FUN_0004afe4 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_0004b13c();

int FUN_0004afe4(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_0004b13c(), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
