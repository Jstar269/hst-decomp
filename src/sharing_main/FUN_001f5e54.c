/* HSTMATCH module=hstp_trans_main.prx start=0x001f5e54 end=0x001f5e7c symbol=FUN_001f5e54 lang=c99 */
/* Clone of src/eboot/FUN_001e7c3c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00108f54();

void FUN_001f5e54(int param_1)
{
  if (*(int *)(param_1 + 0x2464) != 0) {
    FUN_00108f54(*(int *)(param_1 + 0x2464),1);
  }
}
