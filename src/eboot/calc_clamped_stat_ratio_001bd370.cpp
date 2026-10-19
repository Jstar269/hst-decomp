/* HSTMATCH module=EBOOT.BIN start=0x001bd370 end=0x001bd550 symbol=FUN_001bd370 lang=c++ */
/* Hand-written reconstruction from disassembly: std::min<unsigned long long> with total (f8 + fc) and DAT_002e9da8, 8x-unrolled record sum loop over 0xa0-byte entries at +0xc0, clamped ratio (num * 100 / den) with DAT_002e9d60..64; exact match verified; names and types await human review. */

template <typename T>
static inline const T &Min(const T &a, const T &b) {
  return b < a ? b : a;
}

static inline float Clamp(const float &v, const float &lo, const float &hi) {
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

struct StatRec {
  char pad_00[24];
  int num;
  int den;
  char pad_20[128]; // sizeof(StatRec) == 160 (0xa0)
};

struct StatBlock {
  char pad_00[8];
  int f8;
  int fc;
  char pad_10[176]; // 0xc0 - 0x10 = 176
  struct StatRec recs[];
};

extern unsigned long long DAT_002e9da8;
extern float DAT_002e9d60;
extern float DAT_002e9d64;

extern "C" float FUN_001bd370(struct StatBlock *self) {
  unsigned long long total = (unsigned int)(self->f8 + self->fc);
  int count = (int)Min(total, DAT_002e9da8);
  struct StatRec *r = self->recs;
  int num = 0;
  int den = 0;
  for (int i = 0; i < count; i++, r++) {
    num += r->num;
    den += r->den;
  }
  float res;
  if (den != 0) {
    res = Clamp((float)num * 100.0f / (float)den, DAT_002e9d60, DAT_002e9d64);
  } else {
    res = 0.0f;
  }
  return res;
}
