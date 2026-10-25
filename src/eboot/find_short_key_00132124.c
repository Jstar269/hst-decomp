/* HSTMATCH module=EBOOT.BIN start=0x00132124 end=0x00132180 symbol=FUN_00132124 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: initialized result pointer and key on the left of the short comparison; exact match verified; names and types await human review. */
extern char DAT_0033b584[];

char *FUN_00132124(int key, int *out)
{
  char *result = 0;
  int i = 0;
  char *p = DAT_0033b584;
  for (;;)
  {
    if (key == *(short *)(p + 0x44))
    {
      result = DAT_0033b584 + i * 0x58;
      if (out != 0)
        *out = i;
      break;
    }
    i++;
    p += 0x58;
    if (i >= 0xe0) break;
  }
  return result;
}
