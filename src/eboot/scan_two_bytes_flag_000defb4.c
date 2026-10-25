/* HSTMATCH module=EBOOT.BIN start=0x000defb4 end=0x000df000 symbol=FUN_000defb4 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: set the result in the match branch and clear it after loop exhaustion; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern char DAT_003417b8[];

unsigned char FUN_000defb4(char *self)
{
  char *table = DAT_003417b8;
  int found;
  unsigned i = 0;
  for (; i < 2; i++)
  {
    if (table[i + 9] == '\t')
    {
      found = 1;
      goto done;
    }
  }
  found = 0;
done:
  return found ? *(unsigned char *)(self + 0x5e) : *(unsigned char *)(self + 0x5f);
}
