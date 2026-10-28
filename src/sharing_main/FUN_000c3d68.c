/* HSTMATCH module=hstp_trans_main.prx start=0x000c3d68 end=0x000c3d7c symbol=FUN_000c3d68 lang=c99 */
/* Clone of src/eboot/FUN_000c06c8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

int FUN_000c3d68(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x14) + 0x10) - *(int *)(*(int *)(param_1 + 0x14) + 0xc);
}
