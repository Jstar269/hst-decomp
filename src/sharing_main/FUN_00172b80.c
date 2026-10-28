/* HSTMATCH module=hstp_trans_main.prx start=0x00172b80 end=0x00172b90 symbol=FUN_00172b80 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

void FUN_00172b80(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
