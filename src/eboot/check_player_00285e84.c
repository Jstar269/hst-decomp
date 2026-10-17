/* HSTMATCH module=EBOOT.BIN start=0x00285e84 end=0x00285f28 symbol=FUN_00285e84 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: structured loop with early continues and row pointer computed before ret-index test; exact match verified; names and types await human review. */
typedef unsigned char uchar;

extern int DAT_00338ac4;
extern int FUN_000bbba4(int, int);

int FUN_00285e84(int param_1)
{
  if (*(uchar *)(DAT_00338ac4 + 0x178) != 0) {
    return 1;
  }

  int res = 0;
  int ret = FUN_000bbba4(DAT_00338ac4, DAT_00338ac4 + 0x3e);
  int i = 0;
  int p = DAT_00338ac4;

  for (; i < 4; i++, p += 7, param_1 += 0x458) {
    uchar *row = (uchar *)p + 88;
    if (i != ret) {
      continue;
    }
    if (row[6] == 0) {
      continue;
    }
    if (*(uchar *)(param_1 + 0xa6d) == 0) {
      continue;
    }
    if (*(uchar *)(param_1 + 0xa70) == 0) {
      continue;
    }
    res = 1;
    break;
  }
  return res;
}
