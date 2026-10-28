/* HSTMATCH module=hstp_trans_main.prx start=0x00229fe0 end=0x0022a030 symbol=FUN_00229fe0 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_0022a074();

int FUN_00229fe0(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_0022a074(), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
