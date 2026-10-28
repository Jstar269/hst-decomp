/* HSTMATCH module=hstp_trans_main.prx start=0x00241314 end=0x00241340 symbol=FUN_00241314 lang=c99 */
/* Clone of src/eboot/FUN_00231214.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00241348();

void FUN_00241314(int param_1)
{
  if (*(int *)(param_1 + 4) == 1) {
    FUN_00241348(param_1,0);
  }
}
