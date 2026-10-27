/* HSTMATCH module=hstp_trans_main.prx start=0x001e1fcc end=0x001e20f4 symbol=FUN_001e1fcc lang=c99 */
/* Clone of src/eboot/frame_sample_001d41c8.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: ROW() spells the key-row address index-first ((idx<<4)+self, then the member) to get retail addu operand order. */
typedef struct V4 { float v[4]; } V4;

typedef struct Sampler {
  char pad0[0xd4];
  int phase;           /* 0xd4 */
  char pad1[400 - 0xd8];
  char mtx[0x1d0 - 400]; /* 400 */
  int mtx_arg;         /* 0x1d0 */
  char pad2[0x1e0 - 0x1d4];
  V4 keys[9];          /* 0x1e0 */
  float offset;        /* 0x270 */
  char pad4[0x51c - 0x274];
  int period;          /* 0x51c */
} Sampler;

typedef struct Out { float v[4]; } Out;

extern void *FUN_000ec4e0(void *, void *, void *, void *, void *);
extern void FUN_000ec4d0(void *, int, void *);
extern void *FUN_0006f4b4(void *, float, float, float, float);
extern void FUN_000c77ec(void *, void *, void *);

/* index-first row addressing: the row base is (idx * 16 + self), then the keys member */
#define ROW(s, i) (&((Sampler *)(((i) << 4) + (int)(s)))->keys[0])

float FUN_001e1fcc(Sampler *self, Out *out, int step)
{
  int basis[16];
  int powers[4];
  float t;
  int idx;
  void *p;
  float w;
  float t2;
  float t3;

  t = self->offset + (float)self->phase + (float)step * (6.0f / (float)self->period);
  if (t >= 6.0f) {
    t = t - 6.0f;
  }
  idx = (int)t;
  idx = ((unsigned)idx >= 9) ? 8 : idx;
  t = t - (float)idx;
  p = FUN_000ec4e0(basis, ROW(self, idx), ROW(self, idx + 1), ROW(self, idx + 2), ROW(self, idx + 3));
  FUN_000ec4d0(self->mtx, self->mtx_arg, p);
  t2 = t * t;
  t3 = t2 * t;
  p = FUN_0006f4b4(powers, t3, t2, t, 1.0f);
  FUN_000c77ec(out, p, self->mtx);
  w = out->v[3];
  out->v[3] = 1.0f;
  return w;
}
