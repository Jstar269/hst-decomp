/* HSTMATCH module=EBOOT.BIN start=0x0011b468 end=0x0011b4b8 symbol=FUN_0011b468 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_0033b480;
extern void *FUN_00000bcc(unsigned n);
extern void *FUN_0011aaf4(void *p, int a);

void *FUN_0011b468(int a)
{
  void *p;
  if (DAT_0033b480 != 0) return 0;
  p = FUN_00000bcc(0xd0);
  if (p != 0) {
    p = FUN_0011aaf4(p, a);
  }
  return p;
}
