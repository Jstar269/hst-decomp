/* HSTMATCH module=EBOOT.BIN start=0x001d41c8 end=0x001d42f0 symbol=FUN_001d41c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: ROW() spells the key-row address index-first ((idx<<4)+self, then the member) to get retail addu operand order. */
/* Number of key rows in the sampler and the length (in frames) of one sampling cycle. */
#define KEY_ROWS 9
#define CYCLE_LENGTH 6.0f

typedef struct V4 { float v[4]; } V4;

typedef struct Sampler {
  char pad0[0xd4];
  int phase;           /* 0xd4 */
  char pad1[400 - 0xd8];
  char mtx[0x1d0 - 400]; /* 400 */
  int mtx_arg;         /* 0x1d0 */
  char pad2[0x1e0 - 0x1d4];
  V4 keys[KEY_ROWS];          /* 0x1e0 */
  float offset;        /* 0x270 */
  char pad4[0x51c - 0x274];
  int period;          /* 0x51c */
} Sampler;

typedef struct Out { float v[4]; } Out;

extern void *FUN_000e74e4(void *, void *, void *, void *, void *);
extern void FUN_000e74d4(void *, int, void *);
extern void *FUN_0006de18(void *, float, float, float, float);
extern void FUN_000c3f84(void *, void *, void *);

/* index-first row addressing: the row base is (idx * 16 + self), then the keys member */
#define ROW(s, i) (&((Sampler *)(((i) << 4) + (int)(s)))->keys[0])

/* Sample the key curve at step frames ahead of the current phase; returns the sample's fourth component. */
float FUN_001d41c8(Sampler *self, Out *out, int step)
{
  int basis[16];
  int powers[4];
  float t;
  int idx;
  void *p;
  float w;
  float t2;
  float t3;

  t = self->offset + (float)self->phase + (float)step * (CYCLE_LENGTH / (float)self->period);
  if (t >= CYCLE_LENGTH) {
    t = t - CYCLE_LENGTH;
  }
  idx = (int)t;
  idx = ((unsigned)idx >= KEY_ROWS) ? KEY_ROWS - 1 : idx;
  t = t - (float)idx;
  p = FUN_000e74e4(basis, ROW(self, idx), ROW(self, idx + 1), ROW(self, idx + 2), ROW(self, idx + 3));
  FUN_000e74d4(self->mtx, self->mtx_arg, p);
  t2 = t * t;
  t3 = t2 * t;
  p = FUN_0006de18(powers, t3, t2, t, 1.0f);
  FUN_000c3f84(out, p, self->mtx);
  w = out->v[3];
  out->v[3] = 1.0f;
  return w;
}
