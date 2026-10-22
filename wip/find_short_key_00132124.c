/* HSTMATCH module=EBOOT.BIN start=0x00132124 end=0x00132180 symbol=FUN_00132124 lang=c99 */
extern char DAT_0033b584[];

char *FUN_00132124(int key, int *out)
{
  char *p = DAT_0033b584;
  for (int i = 0; i < 0xe0; i++, p += 0x58)
  {
    if (*(short *)(p + 0x44) == key)
    {
      if (out != 0)
        *out = i;
      return DAT_0033b584 + i * 0x58;
    }
  }
  return 0;
}
// near miss from lane od3 (unreviewed)
