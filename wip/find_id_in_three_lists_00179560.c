/* HSTMATCH module=EBOOT.BIN start=0x00179560 end=0x001796c4 symbol=FUN_00179560 lang=c99 */
#pragma opt_strength_reduction off
struct Entry
{
  unsigned value;
};
struct Self
{
  char pad0[0x1e4];
  struct Entry **list0;
  volatile unsigned count0;
  char pad1[0x1fc - 0x1ec];
  struct Entry **list1;
  volatile unsigned count1;
  char pad2[0x208 - 0x204];
  struct Entry **list2;
  volatile unsigned count2;
  char pad3[0x59e - 0x210];
  unsigned short ids[4];
};

unsigned FUN_00179560(struct Self *self, int kind)
{
  unsigned short *ids = self->ids;
  unsigned result = 0;
  if (kind != 4)
  {
    switch (kind)
    {
    case 0:
      for (unsigned i = 0; i < self->count0; i++)
        if (ids[0] == self->list0[i]->value)
        {
          result = i;
          break;
        }
      break;
    case 1:
      for (unsigned i = 0; i < self->count1; i++)
        if (ids[1] == self->list1[i]->value)
        {
          result = i;
          break;
        }
      break;
    case 2:
      for (unsigned i = 0; i < self->count2; i++)
        if (ids[2] == self->list2[i]->value)
        {
          result = i;
          break;
        }
      break;
    case 3:
      for (unsigned i = 0; i < self->count2; i++)
        if (ids[3] == self->list2[i]->value)
        {
          result = i;
          break;
        }
      break;
    }
  }
  return result;
}
// near miss from lane od3 (unreviewed)
