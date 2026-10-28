/* HSTMATCH module=hstp_trans_main.prx start=0x000b43b0 end=0x000b43f0 symbol=FUN_000b43b0 lang=c99 */
/* Clone of src/eboot/FUN_000b13c4.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (range check written as one && condition); exact match verified; names and types await human review. */

int FUN_000b43b0(int param_1)
{
  int obj = *(int *)(*(int *)(param_1 + 0x5bc) + 0x58);
  int v = obj ? *(int *)(obj + 0xf0) : -1;
  if (v >= 0x48 && v < 0x4a) return 1;
  return 0;
}
