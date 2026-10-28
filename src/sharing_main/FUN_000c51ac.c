/* HSTMATCH module=hstp_trans_main.prx start=0x000c51ac end=0x000c51bc symbol=FUN_000c51ac lang=c99 */
/* Clone of src/eboot/FUN_0008b198.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

void FUN_000c51ac(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
