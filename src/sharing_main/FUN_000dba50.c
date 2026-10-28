/* HSTMATCH module=hstp_trans_main.prx start=0x000dba50 end=0x000dba60 symbol=FUN_000dba50 lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

void FUN_000dba50(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
