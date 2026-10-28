/* HSTMATCH module=hstp_trans_main.prx start=0x001773e0 end=0x00177434 symbol=FUN_001773e0 lang=c99 */
/* Clone of src/eboot/FUN_0016b21c.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */

extern int FUN_00177d4c();

int FUN_001773e0(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_00177d4c();
  if (0 <= param_1 && (param_1 < 0xf)) {
    iVar1 = iVar1 + param_1 * 0x38 + 4;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
