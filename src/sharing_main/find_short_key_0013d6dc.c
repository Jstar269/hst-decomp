/* HSTMATCH module=hstp_trans_main.prx start=0x0013d6dc end=0x0013d738 symbol=FUN_0013d6dc lang=c99 */
/* Clone of src/eboot/find_short_key_00132124.c (hstclone.py tag lnmc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: initialized result pointer and key on the left of the short comparison; exact match verified; names and types await human review. */
extern char DAT_003e48c4[];

char *FUN_0013d6dc(int key, int *out)
{
  char *result = 0;
  int i = 0;
  char *p = DAT_003e48c4;
  for (;;)
  {
    if (key == *(short *)(p + 0x44))
    {
      result = DAT_003e48c4 + i * 0x58;
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
