/* HSTMATCH module=EBOOT.BIN start=0x00268ca0 end=0x00268d3c symbol=FUN_00268ca0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (via the lane od3 near-miss wip; hstgen tag not recorded) corrected by hand: the callee FUN_0005f110 gets its dropped float argument 0.0f (shares the zero with the compare); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern void FUN_0005f110(void *, float);
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
        FUN_0005f110(o, 0.0f);
        o->fD0 = 0.0f;
      }
    }
  }
}
