/* HSTMATCH module=hstp_trans_main.prx start=0x001b203c end=0x001b20c0 symbol=FUN_001b203c lang=c99 */
/* Clone of src/eboot/lookup_two_level_001a4a70.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Self
{
  char pad[0x330];
  void *f330;
  char pad2[0x390 - 0x334];
  void *f390;
};
int FUN_001b203c(struct Self *self, int key)
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
