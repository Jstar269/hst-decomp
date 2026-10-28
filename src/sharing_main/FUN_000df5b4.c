/* HSTMATCH module=hstp_trans_main.prx start=0x000df5b4 end=0x000df60c symbol=FUN_000df5b4 lang=c99 */
/* Clone of src/eboot/FUN_000db59c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_000df504();

int FUN_000df5b4(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (param_1 != 0) {
      FUN_000df504(param_1,0xffffffff);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
