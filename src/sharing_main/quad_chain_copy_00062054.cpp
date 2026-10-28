/* HSTMATCH module=hstp_trans_main.prx start=0x00062054 end=0x00062160 symbol=FUN_00062054 lang=c++ */
/* Clone of src/eboot/quad_chain_copy_000611d0.cpp (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_000224c0(Q *out, const Q *in, float s);
extern "C" void FUN_0001cd04(Q *out, int a1, float f);
extern "C" void FUN_0001cdb0(Q *out, const Q *in);
extern "C" void FUN_00022570(Q *out, const Q *in, const Q *in2);
extern "C" void FUN_00022440(Q *out, const Q *a, const Q *b);
extern "C" void FUN_0006187c(Self *self);
extern "C" void FUN_00062054(Self *self, int a1, float f)
{
  Q t4; Q t3; Q t2[4]; Q q2; Q q; Q tmp; Q out;
  float keep = f;
  float s = self->f80;
  q = self->q1;
  FUN_000224c0(&tmp, &q, s);
  t4 = tmp;
  FUN_0001cd04(&t3, a1, keep);
  FUN_0001cdb0(t2, &t3);
  FUN_00022570(&t4, t2, &t4);
  q2 = self->q2;
  FUN_00022440(&out, &q2, &t4);
  Q t = out;
  self->out = t;
  FUN_0006187c(self);
}
