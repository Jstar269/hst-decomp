/* HSTMATCH module=EBOOT.BIN start=0x00131db8 end=0x00131e00 symbol=FUN_00131db8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: the unused leading parameter (a0) is what retail's signature has (its index arrives in a1). */

extern unsigned long long DAT_002db298[8];

int FUN_00131db8(int param_1, int param_2)
{
  unsigned long long buf[8];
  const unsigned long long *s = DAT_002db298;
  unsigned long long *d = buf;
  int n = 8;

  do {
    *d++ = *s++;
  } while (--n > 0);
  return ((int *)buf)[param_2];
}
