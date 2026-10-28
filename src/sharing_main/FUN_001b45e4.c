/* HSTMATCH module=hstp_trans_main.prx start=0x001b45e4 end=0x001b45f4 symbol=FUN_001b45e4 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

void FUN_001b45e4(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
