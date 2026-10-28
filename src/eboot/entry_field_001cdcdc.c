/* HSTMATCH module=EBOOT.BIN start=0x001cdcdc end=0x001cdd0c symbol=FUN_001cdcdc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_001cdcdc(int self,int i)
{
  int base = *(int *)(self + 0x58);
  if (!base) return -1;
  return *(int *)((char *)(i * 52) + base + 0xf0);
}
