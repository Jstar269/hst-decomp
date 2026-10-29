/* HSTMATCH module=EBOOT.BIN start=0x00114f38 end=0x00114fb8 symbol=FUN_00114f38 lang=c99 */
typedef struct { short f0; short f2; short f4; short f6; short f8; short f10; } S;
void FUN_00114f38(S *p, S *q)
{
  short qd = q->f10;
  short qb = q->f6;
  short pd = p->f10;
  short pb = p->f6;
  int d = (short)(qd - qb) - (short)(pd - pb);
  short half = (short)(d / 2);
  short nb = q->f6 + half;
  short a = p->f4;
  short b = q->f8;
  p->f4 = b;
  p->f8 = p->f8 + (b - a);
  short t = p->f6;
  p->f6 = nb;
  p->f10 = p->f10 + (nb - t);
}
// near miss from lane dsn3 (unreviewed)
