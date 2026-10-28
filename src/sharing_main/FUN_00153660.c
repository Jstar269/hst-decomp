/* HSTMATCH module=hstp_trans_main.prx start=0x00153660 end=0x00153670 symbol=FUN_00153660 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */

void FUN_00153660(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
