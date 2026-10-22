/* HSTMATCH module=hstp_trans_main.prx start=0x001e6528 end=0x001e6600 symbol=FUN_001e6528 lang=c99 */
/* Clone of src/eboot/build_nodes_001d877c.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002d6a04[];
extern void FUN_001055d8(void *);
struct Self
{
  char pad0[0xcc];
  int fcc;
  int fd0;
  int fd4;
  char pad1[0x51c - 0xd8];
  int f51c;
  int f520;
};

void FUN_001e6528(struct Self *self, int **list, int flag)
{
  for (int i = 0; i < self->f51c; i++)
  {
    int v = *(int *)((char *)DAT_002d6a04 + self->f520 * 24 +
                     ((self->fd4 + i) % self->f51c) * 4);
    if (i == 0)
    {
      int val = self->fcc + v;
      int *p = list[i];
      p[9] = val;
      p[10] = val;
    }
    else
    {
      int val = self->fd0 + v;
      int *p = list[i];
      p[9] = val;
      p[10] = val;
    }
    if (flag != 0)
      FUN_001055d8(list[i]);
  }
}
