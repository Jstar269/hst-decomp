/* HSTMATCH module=EBOOT.BIN start=0x00268ca0 end=0x00268d3c symbol=FUN_00268ca0 lang=c99 */
#pragma opt_strength_reduction off
extern void FUN_0005f110(void *);
struct Inner
{
  char pad[0xd0];
  float fD0;
};
struct Entry
{
  char pad[0x24];
  struct Inner *f24;
};
struct Self
{
  char pad[0x3c];
  int f3c;
  unsigned char f40;
  char pad2[0x50 - 0x41];
  struct Entry **f50;
  unsigned f54;
};

void FUN_00268ca0(struct Self *self, int value)
{
  if (self->f3c != value)
  {
    self->f3c = value;
    self->f40 = 1;
    for (unsigned i = 0; i < self->f54; i++)
    {
      struct Inner *o = self->f50[i]->f24;
      if (o->fD0 != 0.0f)
      {
        FUN_0005f110(o);
        o->fD0 = 0.0f;
      }
    }
  }
}
// near miss from lane od3 (unreviewed)
