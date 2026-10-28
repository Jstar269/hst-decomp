/* HSTMATCH module=EBOOT.BIN start=0x001e5a9c end=0x001e5ac4 symbol=FUN_001e5a9c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_00222b48(int);
int FUN_001e5a9c(int self)
{
  int p = *(int *)(self + 0x1954);
  if (!p) return 0;
  return FUN_00222b48(p);
}
