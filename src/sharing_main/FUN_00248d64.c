/* HSTMATCH module=hstp_trans_main.prx start=0x00248d64 end=0x00248d74 symbol=FUN_00248d64 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

void FUN_00248d64(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
