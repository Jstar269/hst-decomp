/* HSTMATCH module=hstp_trans_main.prx start=0x00094f00 end=0x00094f28 symbol=FUN_00094f00 lang=c99 */
/* Clone of src/eboot/FUN_0009306c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_0005fd08();

void FUN_00094f00(int param_1)
{
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_0005fd08(*(int *)(param_1 + 0x50));
  }
}
