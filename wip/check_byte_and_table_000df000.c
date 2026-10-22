/* HSTMATCH module=EBOOT.BIN start=0x000df000 end=0x000df060 symbol=FUN_000df000 lang=c99 */
#pragma opt_strength_reduction off
extern char DAT_003417b8;
struct Self
{
  char pad[0x5e];
  unsigned char f5e;
  unsigned char f5f;
};

unsigned char FUN_000df000(struct Self *self)
{
  unsigned char c = self->f5e;
  int found = 0;
  if (c != 0)
  {
    for (unsigned i = 0; i < 2; i++)
    {
      if ((&DAT_003417b8)[i + 9] == '\t')
      {
        found = 1;
        break;
      }
    }
    if (!found)
      c = self->f5f;
    return !c;
  }
  return c;
}
// near miss from lane od3 (unreviewed)
