/* HSTMATCH module=EBOOT.BIN start=0x000defb4 end=0x000df000 symbol=FUN_000defb4 lang=c99 */
#pragma opt_strength_reduction off
extern char DAT_003417b8[];

unsigned char FUN_000defb4(char *self)
{
  char found = 0;
  for (unsigned i = 0; i < 2; i++)
  {
    if (*(char *)(DAT_003417b8 + 9 + i) == '\t')
    {
      found = 1;
      break;
    }
  }
  return found ? *(unsigned char *)(self + 0x5e) : *(unsigned char *)(self + 0x5f);
}
// near miss from lane od3 (unreviewed)
