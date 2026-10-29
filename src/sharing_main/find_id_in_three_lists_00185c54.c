/* HSTMATCH module=hstp_trans_main.prx start=0x00185c54 end=0x00185db8 symbol=FUN_00185c54 lang=c99 */
/* Clone of src/eboot/find_id_in_three_lists_00179560.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (starting from the od3 near miss in wip/find_id_in_three_lists_00185c54.c); exact match verified; names and types await human review. */
/* Matching idioms: `volatile unsigned count*` (bound reloaded every pass); `#pragma opt_strength_reduction off` (index recomputed per pass); each lookup is `unsigned i = 0; if (count != 0) { Entry **l = list; unsigned short id = ids[k]; do { ... } while (i < count); }`: the explicit emptiness test puts the table/id loads after the `beqz`, and declaring the table before the id gives retail's a2/a1 colouring. */
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

unsigned FUN_00185c54(struct Self *self, int kind)
{
  unsigned short *ids = self->ids;
  unsigned result = 0;
  if (kind != 4)
  {
    switch (kind)
    {
    case 0: {
      unsigned i = 0;
      if (self->count0 != 0)
      {
        struct Entry **l = self->list0;
        unsigned short id = ids[0];
        do
        {
          if (id == l[i]->value)
          {
            result = i;
            break;
          }
          i++;
        } while (i < self->count0);
      }
      break;
    }
    case 1: {
      unsigned i = 0;
      if (self->count1 != 0)
      {
        struct Entry **l = self->list1;
        unsigned short id = ids[1];
        do
        {
          if (id == l[i]->value)
          {
            result = i;
            break;
          }
          i++;
        } while (i < self->count1);
      }
      break;
    }
    case 2: {
      unsigned i = 0;
      if (self->count2 != 0)
      {
        struct Entry **l = self->list2;
        unsigned short id = ids[2];
        do
        {
          if (id == l[i]->value)
          {
            result = i;
            break;
          }
          i++;
        } while (i < self->count2);
      }
      break;
    }
    case 3: {
      unsigned i = 0;
      if (self->count2 != 0)
      {
        struct Entry **l = self->list2;
        unsigned short id = ids[3];
        do
        {
          if (id == l[i]->value)
          {
            result = i;
            break;
          }
          i++;
        } while (i < self->count2);
      }
      break;
    }
    }
  }
  return result;
}
