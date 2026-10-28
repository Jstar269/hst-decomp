/* HSTMATCH module=hstp_trans_main.prx start=0x00131b34 end=0x00131b48 symbol=FUN_00131b34 lang=c99 */
/* Clone of src/eboot/FUN_001268c4.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */

int FUN_00131b34(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x1c) + 0x10) - *(int *)(*(int *)(param_1 + 0x1c) + 0xc);
}
