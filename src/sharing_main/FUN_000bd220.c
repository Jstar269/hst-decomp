/* HSTMATCH module=hstp_trans_main.prx start=0x000bd220 end=0x000bd240 symbol=FUN_000bd220 lang=c99 */
/* Clone of src/eboot/FUN_000b9edc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

void FUN_000bd220(int param_1)
{
  int iVar1;
  
  iVar1 = (*(int *)(param_1 + 0x6c) + 1) % 3;
  *(int *)(param_1 + 0x6c) = iVar1;
  *(int *)(param_1 + 100) = iVar1;
}
