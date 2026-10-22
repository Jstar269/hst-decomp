/* HSTMATCH module=EBOOT.BIN start=0x001e744c end=0x001e74d4 symbol=FUN_001e744c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_001ee224();
extern int FUN_00065740(int, const char *, int);
extern void FUN_00217834(int, unsigned, int, int);
extern char DAT_002ec18c[];

void FUN_001e744c(char *self)
{
  int x = *(int *)(self + 0x948);
  unsigned value = (unsigned)*(unsigned char *)(self + 0x99e) << 24 |
                   (unsigned)*(unsigned char *)(self + 0x99c) << 16 |
                   (unsigned)*(unsigned char *)(self + 0x99a) << 8 |
                   (unsigned)*(unsigned char *)(self + 0x998);
  int r = FUN_001ee224();
  r = FUN_00065740(r, DAT_002ec18c, 1);
  FUN_00217834((int)(self + 0x928), value, x, r);
}
