/* HSTMATCH module=hstp_trans_main.prx start=0x000b66a8 end=0x000b66e8 symbol=FUN_000b66a8 lang=c99 */
/* Clone of src/eboot/type_range_check_000b3490.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_000b66a8(int param_1)
{
  int holder = *(int *)(param_1 + 0x5bc);
  int entry = *(int *)(holder + 0x58);
  int value = entry ? *(int *)(entry + 0xf0) : -1;
  if (value >= 118) {
    if (value < 130) return 1;
  }
  return 0;
}

