/* HSTMATCH module=EBOOT.BIN start=0x001c5044 end=0x001c5084 symbol=FUN_001c5044 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_001c5ed0();
void FUN_001c5044(int p)
{
  if (*(int *)(p + 0x16c) == 0) {
    switch (*(int *)(p + 0xc4)) {
      case 2:
        FUN_001c5ed0(p);
        break;
      default:
        break;
    }
  }
}
