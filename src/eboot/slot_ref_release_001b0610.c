/* HSTMATCH module=EBOOT.BIN start=0x001b0610 end=0x001b06d4 symbol=FUN_001b0610 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00062418(int, int);

void FUN_001b0610(int *param_1, int param_2)
{
  int *p = param_1;
  int off = param_2 * 4;
  int *t = (int *)(off + (int)p + 0x778);
  int *q;
  int *qe;
  int n;
  int i;

  if (p[param_2 + 0x1de] == 0) return;
  n = 0;
  q = p + 0x1de;
  qe = p + 0x1e2;
  if (q != qe) {
    do {
      if (*q == *t) n++;
      q++;
    } while (q != qe);
  }
  if (n < 2) {
    for (i = 0; i < 0x1da; i++) {
      int c = p[i];
      if (c == *t) {
        int v = p[i];
        if (v != 0) { FUN_00062418(v, 1); p[i] = 0; }
        break;
      }
    }
  }
  *t = 0;
}
