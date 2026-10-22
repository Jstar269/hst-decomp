/* HSTMATCH module=EBOOT.BIN start=0x001d877c end=0x001d8854 symbol=FUN_001d877c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002c6498[];
extern void FUN_000ffca4(void *);
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

void FUN_001d877c(struct Self *self, int **list, int flag)
{
  for (int i = 0; i < self->f51c; i++)
  {
    int v = *(int *)((char *)DAT_002c6498 + self->f520 * 24 +
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
      FUN_000ffca4(list[i]);
  }
}
