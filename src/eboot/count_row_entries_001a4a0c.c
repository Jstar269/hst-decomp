/* HSTMATCH module=EBOOT.BIN start=0x001a4a0c end=0x001a4a70 symbol=FUN_001a4a0c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Self
{
  char pad[0x330];
  int **f330;
};

int FUN_001a4a0c(struct Self *self)
{
  int **base = self->f330;
  int count = 0;
  for (int i = 0; i < 2; i++)
  {
    int **sub = (int **)((char *)base + i * 12);
    for (int j = 0; j < 3; j++)
    {
      if (sub[0][j] != 0)
        count++;
    }
  }
  return count;
}
