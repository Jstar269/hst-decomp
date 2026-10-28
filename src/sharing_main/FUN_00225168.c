/* HSTMATCH module=hstp_trans_main.prx start=0x00225168 end=0x00225178 symbol=FUN_00225168 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

void FUN_00225168(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
