/* HSTMATCH module=EBOOT.BIN start=0x0027c8a0 end=0x0027c8d0 symbol=FUN_0027c8a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_0034a7e4;
int FUN_0027c8a0(int self)
{
  if (*(int *)(self + 0x78) >= 0) {
    return *(int *)(self + 0x7c);
  }
  int idx = *(int *)(self + 0x54);
  return *(int *)((char *)((idx << 6) + (int)DAT_0034a7e4) + 0x24);
}
