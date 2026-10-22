/* HSTMATCH module=EBOOT.BIN start=0x001a4a70 end=0x001a4af4 symbol=FUN_001a4a70 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Self
{
  char pad[0x330];
  void *f330;
  char pad2[0x390 - 0x334];
  void *f390;
};
int FUN_001a4a70(struct Self *self, int key)
{
  int count = 0;
  for (int outer = 0; outer < 2; outer++)
  {
    int **sub = (int **)((char *)self->f330 + outer * 12);
    for (int inner = 0; inner < 3; inner++)
    {
      if (sub[0][inner] != 0)
      {
        if (count == key)
          return *(int *)(*(int *)((char *)self->f390 + outer * 12) + inner * 4);
        count++;
      }
    }
  }
  return 0;
}
