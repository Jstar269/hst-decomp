/* HSTMATCH module=EBOOT.BIN start=0x000d99b8 end=0x000d9a00 symbol=FUN_000d99b8 lang=c99 */
extern int FUN_000d9ccc(void *dst, int a, int b, char c);
typedef struct { int f0; int f4; } S;
typedef struct { char b[8]; } L;
void FUN_000d99b8(short *o, short v, S *s)
{
  L loc;
  int n = s->f4 * 6;
  int r;
  o[0] = v;
  *(int *)((char *)o + 4) = 0;
  *(int *)((char *)o + 8) = 0;
  *(int *)((char *)o + 12) = 0;
  r = FUN_000d9ccc(o + 2, s->f0, s->f0 + n, loc.b[4]);
  if (r) return;
}
// near miss from lane dsn3 (unreviewed)
