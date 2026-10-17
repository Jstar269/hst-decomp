/* HSTMATCH module=hstp_trans_main.prx start=0x001699cc end=0x00169a1c symbol=FUN_001699cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: byte-typed flag global and unsigned byte pointer for the lbu/sb accesses, Ghidra typedef noise removed; exact match verified; names and types await human review. */
typedef unsigned char byte;

extern byte DAT_003e9748;
extern int DAT_00384184;
extern char DAT_003f39a8;

extern byte *FUN_0023ce60();
extern void FUN_00244258(char *, int);

void FUN_001699cc(void)
{
  byte *p;

  DAT_003e9748 = 0;
  DAT_00384184 = 0x1f;
  p = FUN_0023ce60();
  p[0xf0] |= 4;
  p[0x13d] = 1;
  FUN_00244258(&DAT_003f39a8, 0x4b);
}
