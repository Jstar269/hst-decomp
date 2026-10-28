/* HSTMATCH module=EBOOT.BIN start=0x000611d0 end=0x000612dc symbol=FUN_000611d0 lang=c++ */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); exact match verified; names and types await human review. */
struct Q { float x, y, z, w; };
struct Self {
  char pad00[48];
  Q q1;            /* 48 */
  Q q2;            /* 64 */
  float f80;       /* 80 */
  char pad84[12];
  Q out;           /* 96 */
};
extern "C" void FUN_00022498(Q *out, const Q *in, float s);
extern "C" void FUN_0001d0b8(Q *out, int a1, float f);
extern "C" void FUN_0001d164(Q *out, const Q *in);
extern "C" void FUN_00022548(Q *out, const Q *in, const Q *in2);
extern "C" void FUN_00022418(Q *out, const Q *a, const Q *b);
extern "C" void FUN_000609f8(Self *self);
extern "C" void FUN_000611d0(Self *self, int a1, float f)
{
  Q t4; Q t3; Q t2[4]; Q q2; Q q; Q tmp; Q out;
  float keep = f;
  float s = self->f80;
  q = self->q1;
  FUN_00022498(&tmp, &q, s);
  t4 = tmp;
  FUN_0001d0b8(&t3, a1, keep);
  FUN_0001d164(t2, &t3);
  FUN_00022548(&t4, t2, &t4);
  q2 = self->q2;
  FUN_00022418(&out, &q2, &t4);
  Q t = out;
  self->out = t;
  FUN_000609f8(self);
}
