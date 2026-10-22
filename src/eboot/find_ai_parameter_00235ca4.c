/* HSTMATCH module=EBOOT.BIN start=0x00235ca4 end=0x00235d50 symbol=FUN_00235ca4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern int FUN_000146ec(char *, char *);
extern void FUN_000143b0(char *, char *, char *);
extern void FUN_0010a6f0(char *, int);
extern char DAT_002f517c[];
struct Self
{
  char pad0[0x14];
  char *f14;
  unsigned f18;
};

unsigned FUN_00235ca4(struct Self *self, char *name)
{
  unsigned i = 0;
  if (self->f18 != 0)
  {
    do
    {
      if (FUN_000146ec(name, self->f14 + i * 7 * 0x50 + 4) == 0)
        return i;
      i++;
    } while (i < self->f18);
  }
  char buf[256];
  FUN_000143b0(buf, DAT_002f517c, name);
  FUN_0010a6f0(buf, 0);
  return 0;
}
