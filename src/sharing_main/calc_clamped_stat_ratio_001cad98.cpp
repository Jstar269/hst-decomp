/* HSTMATCH module=hstp_trans_main.prx start=0x001cad98 end=0x001caf78 symbol=FUN_001cad98 lang=c++ */
/* Clone of src/eboot/calc_clamped_stat_ratio_001bcfb0.cpp (hstclone.py tag s10172123g4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from disassembly: std::min<unsigned long long> with total (f8 + fc) and DAT_003919e0, 8x-unrolled record sum loop over 0xa0-byte entries at +0xc0, clamped ratio (num * 100 / den) with DAT_00391988..54; exact match verified; names and types await human review. */

template <typename T>
static inline const T &Min(const T &a, const T &b) {
  return b < a ? b : a;
}

static inline float Clamp(const float &v, const float &lo, const float &hi) {
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

struct StatRec {
  char pad_00[8];
  int num;
  int den;
  char pad_10[144]; // sizeof(StatRec) == 160 (0xa0)
};

struct StatBlock {
  char pad_00[8];
  int f8;
  int fc;
  char pad_10[176]; // 0xc0 - 0x10 = 176
  struct StatRec recs[];
};

extern unsigned long long DAT_003919e0;
extern float DAT_00391988;
extern float DAT_0039198c;

extern "C" float FUN_001cad98(struct StatBlock *self) {
  unsigned long long total = (unsigned int)(self->f8 + self->fc);
  int count = (int)Min(total, DAT_003919e0);
  struct StatRec *r = self->recs;
  int num = 0;
  int den = 0;
  for (int i = 0; i < count; i++, r++) {
    num += r->num;
    den += r->den;
  }
  float res;
  if (den != 0) {
    res = Clamp((float)num * 100.0f / (float)den, DAT_00391988, DAT_0039198c);
  } else {
    res = 0.0f;
  }
  return res;
}
