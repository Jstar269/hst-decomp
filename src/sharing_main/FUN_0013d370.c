/* HSTMATCH module=hstp_trans_main.prx start=0x0013d370 end=0x0013d3b8 symbol=FUN_0013d370 lang=c99 */
/* Clone of src/eboot/FUN_00131db8.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: the unused leading parameter (a0) is what retail's signature has (its index arrives in a1). */

extern unsigned long long DAT_003824a4[8];

int FUN_0013d370(int param_1, int param_2)
{
  unsigned long long buf[8];
  const unsigned long long *s = DAT_003824a4;
  unsigned long long *d = buf;
  int n = 8;

  do {
    *d++ = *s++;
  } while (--n > 0);
  return ((int *)buf)[param_2];
}
