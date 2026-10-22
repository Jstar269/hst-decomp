/* HSTMATCH module=EBOOT.BIN start=0x0005d8d0 end=0x0005d98c symbol=FUN_0005d8d0 lang=c99 */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
extern void FUN_0005d100(void *, int, int, int, int, int, int);

typedef struct {
  void **f4;
  unsigned f8;
} Obj;

void FUN_0005d8d0(Obj *self, int p2, int p3, int p4, int p5, int p6, int p7)
{
  unsigned i = 0;
  if (self->f8 != 0) {
    do {
      FUN_0005d100(self->f4[i], p2, p3, p4, p5, p6, p7);
      i++;
    } while (i < self->f8);
  }
}
// near miss from lane km1 (unreviewed)
