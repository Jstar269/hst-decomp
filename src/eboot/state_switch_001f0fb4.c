/* HSTMATCH module=EBOOT.BIN start=0x001f0fb4 end=0x001f10ec symbol=FUN_001f0fb4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034179c;
extern void FUN_001fac6c(char *);
extern void FUN_001f3770(char *);
extern void FUN_001f4584(char *, int);
extern void FUN_001e2990(int);
extern void FUN_001e6224(int, int, int, unsigned char, int);
extern void FUN_001e6ffc(int, int);
extern int FUN_001b2af0(int, int);

void FUN_001f0fb4(char *self)
{
  int off;

  FUN_001fac6c(self);
  off = *(int *)(self + 0x135c) * 12;
  if (*(int *)(off + (int)self + 0x12e0) != 0x7f) {
    FUN_001f4584(self, 0);
    FUN_001e2990(*(int *)(self + 0x510));
    off = *(int *)(self + 0x135c) * 12;
    FUN_001e6224(*(int *)(self + 0x510),
                 *(int *)(off + (int)self + 0x12e0),
                 *(int *)(off + (int)self + 0x12e4),
                 *(unsigned char *)(off + (int)self + 0x12e8), 0);
    off = *(int *)(self + 0x135c) * 12;
    FUN_001e6ffc(*(int *)(self + 0x510), *(int *)(off + (int)self + 0x12e0));
    off = *(int *)(self + 0x135c) * 12;
    if (*(int *)(off + (int)self + 0x12e0) != 5) {
      *(unsigned char *)(self + 0x1364) = 0;
    }
    else {
      *(unsigned char *)(self + 0x1364) = 1;
    }
    off = *(int *)(self + 0x135c) * 12;
    if (*(unsigned char *)(off + (int)self + 0x12e8) != 0) {
      *(int *)(self + 0x5b8) = FUN_001b2af0((int)&DAT_0034179c, 0xd);
    }
    else {
      *(int *)(self + 0x5b8) = FUN_001b2af0((int)&DAT_0034179c, 0xc);
    }
    *(int *)(self + 0x12dc) = 1;
    *(int *)(self + 0x1360) = 0;
  }
  else {
    FUN_001f3770(self);
  }
}
