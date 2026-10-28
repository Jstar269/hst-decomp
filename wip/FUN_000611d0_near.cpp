/* HSTMATCH module=EBOOT.BIN start=0x000611d0 end=0x000612dc symbol=FUN_000611d0 lang=c++ */
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
  Q out;      /* 32 */
  Q tmp;      /* 48 */
  Q q;        /* 64 */
  Q q2;       /* 80 */
  Q t2;       /* 96 */
  Q t3;       /* 160 */
  Q t4;       /* 176 */
  float keep = f;
  q = self->q1;
  FUN_00022498(&tmp, &q, self->f80);
  t4 = tmp;
  FUN_0001d0b8(&t3, a1, keep);
  FUN_0001d164(&t2, &t3);
  FUN_00022548(&t4, &t2, &t4);
  q2 = self->q2;
  FUN_00022418(&out, &q2, &t4);
  self->out = out;
  FUN_000609f8(self);
}
// NEAR 67/67 words, 40 differ - lane dsn2, 2026-10-27 session 7 (1 compile, draft).
// The whole structure is RIGHT on the first attempt: frame 192 in retail vs 144 here; the five calls in order
// (FUN_00022498(out,&q,self->f80), FUN_0001d0b8(&t3,a1,keep), FUN_0001d164(&t2,&t3), FUN_00022548(&t4,&t2,&t4),
// FUN_00022418(&out,&q2,&t4)), the q = self->q1 / q2 = self->q2 copies, the t4 = tmp float copy and the final
// `self->out = out; FUN_000609f8(self);` all line up instruction for instruction.
// WHAT IS LEFT (all 40 differences are STACK SLOTS, not instructions): retail's declared 16-byte objects sit at
// sp+32 (out), sp+48 (tmp), sp+64 (q), sp+80 (q2), sp+96 (t2), sp+160 (t3), sp+176 (t4) - with a 48-byte HOLE at
// sp+112..159 that no local in this draft accounts for, i.e. retail almost certainly declared three more 16-byte
// temporaries (dead, address-taken) or MWCC's -O4,p gave the call-result temporaries their own slots. Our
// declaration order (out, tmp, q, q2, t2, t3, t4) only pins `out` at 32; the rest land as
// tmp 112 / q 96 / q2 64 / t2 64-ish / t3 48 / t4 40 - i.e. the RESULT temporaries (tmp, and the ones built by
// calls) are allocated bottom-up while the plain copies are top-down.
// NEXT STEP: reproduce the hole - declare three extra address-taken `Q` dead locals between t2 and t3 (the
// 0x00065480 slot-span lever says declared objects take slots in declaration order), or find the source order
// that makes MWCC give the call-result temporaries the low slots 48/96/160 in that sequence. Then the frame
// arithmetic (144 vs 192) lands by itself. 40 words to go, none of them structural.
// near miss from lane dsn2 (unreviewed)
