/* HSTMATCH module=EBOOT.BIN start=0x00145f14 end=0x00145f94 symbol=FUN_00145f14 lang=c99 */
#pragma opt_strength_reduction off
extern int DAT_003402c0;
struct Self
{
  char pad0[0x8e0];
  char *f8e0;
  unsigned f8e4;
};

char *FUN_00145f14(struct Self *self, int key)
{
  unsigned i = 0;
  int found = -1;
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
  if (found >= 0)
    return self->f8e0 + found * 0x30;
  DAT_003402c0 = -1;
  return (char *)&DAT_003402c0;
}
// near miss from lane od3 (unreviewed)
