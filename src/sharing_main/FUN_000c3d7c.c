/* HSTMATCH module=hstp_trans_main.prx start=0x000c3d7c end=0x000c3d90 symbol=FUN_000c3d7c lang=c99 */
/* Clone of src/eboot/FUN_000c06dc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

int FUN_000c3d7c(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x18) + 0x10) - *(int *)(*(int *)(param_1 + 0x18) + 0xc);
}
