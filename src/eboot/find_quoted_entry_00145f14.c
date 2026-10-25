/* HSTMATCH module=EBOOT.BIN start=0x00145f14 end=0x00145f94 symbol=FUN_00145f14 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: volatile size reload and error-first return branch; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern int DAT_003402c0;
struct Self
{
  char pad0[0x8e0];
  char *f8e0;
  volatile unsigned f8e4;
};

char *FUN_00145f14(struct Self *self, int key)
{
  int found = -1;
  unsigned i = 0;
  if (self->f8e4 != 0)
  {
    do
    {
      if (key == *(int *)(self->f8e0 + i * 0x30))
      {
        found = i;
        break;
      }
      i++;
    } while (i < self->f8e4);
  }
  if (found < 0) {
    DAT_003402c0 = -1;
    return (char *)&DAT_003402c0;
  }
  return self->f8e0 + found * 0x30;
}
