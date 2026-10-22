/* HSTMATCH module=hstp_trans_main.prx start=0x001b1fd8 end=0x001b203c symbol=FUN_001b1fd8 lang=c99 */
/* Clone of src/eboot/count_row_entries_001a4a0c.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Self
{
  char pad[0x330];
  int **f330;
};

int FUN_001b1fd8(struct Self *self)
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
