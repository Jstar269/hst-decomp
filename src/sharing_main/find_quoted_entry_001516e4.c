/* HSTMATCH module=hstp_trans_main.prx start=0x001516e4 end=0x00151764 symbol=FUN_001516e4 lang=c99 */
/* Clone of src/eboot/find_quoted_entry_00145f14.c (hstclone.py tag lnmc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: volatile size reload and error-first return branch; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern int DAT_003e9600;
struct Self
{
  char pad0[0x8e0];
  char *f8e0;
  volatile unsigned f8e4;
};

char *FUN_001516e4(struct Self *self, int key)
{
  int found = -1;
  unsigned i = 0;
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
  if (found < 0) {
    DAT_003e9600 = -1;
    return (char *)&DAT_003e9600;
  }
  return self->f8e0 + found * 0x30;
}
