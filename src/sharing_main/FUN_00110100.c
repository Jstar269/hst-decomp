/* HSTMATCH module=hstp_trans_main.prx start=0x00110100 end=0x00110110 symbol=FUN_00110100 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

void FUN_00110100(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
