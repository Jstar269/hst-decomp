/* HSTMATCH module=EBOOT.BIN start=0x0017951c end=0x00179560 symbol=FUN_0017951c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
unsigned short FUN_0017951c(char *self, int kind)
{
  unsigned short value = 0;
  unsigned short *p = (unsigned short *)(self + 0x59e);
  if (kind != 4)
  {
    switch (kind)
    {
    case 0:
      value = p[0];
      break;
    case 1:
      value = p[1];
      break;
    case 2:
      value = p[2];
      break;
    case 3:
      value = p[3];
      break;
    }
  }
  return value;
}
