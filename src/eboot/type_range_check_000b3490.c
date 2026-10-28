/* HSTMATCH module=EBOOT.BIN start=0x000b3490 end=0x000b34d0 symbol=FUN_000b3490 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_000b3490(int param_1)
{
  int holder = *(int *)(param_1 + 0x5bc);
  int entry = *(int *)(holder + 0x58);
  int value = entry ? *(int *)(entry + 0xf0) : -1;
  if (value >= 118) {
    if (value < 130) return 1;
  }
  return 0;
}

