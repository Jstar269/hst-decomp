/* HSTMATCH module=EBOOT.BIN start=0x000d0cfc end=0x000d0f2c symbol=FUN_000d0cfc lang=c++ */
struct Tag {};

struct VObj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
};

struct Vec {
    int *data;
    unsigned int size;
    unsigned int cap;
    void shrink(int n) { size -= n; }
    void clear() { shrink(size); }
};

extern "C" {
extern void *DAT_003074a0;
extern const unsigned char DAT_002c049c;
extern const short DAT_002c049e;
extern const float DAT_002c04a0;
extern const float DAT_002c04a4;
extern const float DAT_002c04a8;
extern const float DAT_002c04ac;
extern const float DAT_002c04b0;
extern const short DAT_002c04b4;
extern const float DAT_002c04b8;
extern const float DAT_002c04bc;
extern const float DAT_002c04c0;
extern const float DAT_002c04c4;
extern const float DAT_002c04c8;
extern const int DAT_002c04cc;
extern const short DAT_002c04d0;
extern const int DAT_002c04d4;
extern float DAT_002c04e0[];
extern void FUN_000d5480(Vec *, int);
extern void *FUN_000e5580();
}
static inline void Reserve(Vec *v, unsigned int n, Tag t) { if (v->cap < n) FUN_000d5480(v, n); }
extern "C" {

void *FUN_000d0cfc(int *param_1)
{
  FUN_000e5580();
  *(void **)param_1 = &DAT_003074a0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  *(unsigned char *)(param_1 + 0x66) = 0;
  param_1[0x67] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  *(unsigned char *)(param_1 + 0x70) = 0;
  param_1[0x71] = 0;
  param_1[0x73] = 0;
  ((Vec *)(param_1 + 0x32))->clear();
  Reserve((Vec *)(param_1 + 0x6a), 0x10, Tag());
  ((VObj *)param_1)->m9();
  {
    int i = 0;
    float *src = DAT_002c04e0;
    float *dst = (float *)param_1;
    do {
      i += 5;
      dst[0x38 + 0] = src[0];
      dst[0x38 + 1] = src[1];
      dst[0x38 + 2] = src[2];
      dst[0x38 + 3] = src[3];
      dst[0x38 + 4] = src[4];
      dst[0x38 + 5] = src[5];
      dst[0x38 + 6] = src[6];
      dst[0x38 + 7] = src[7];
      dst[0x38 + 8] = src[8];
      dst[0x38 + 9] = src[9];
      dst[0x38 + 10] = src[10];
      dst[0x38 + 11] = src[11];
      dst[0x38 + 12] = src[12];
      dst[0x38 + 13] = src[13];
      dst[0x38 + 14] = src[14];
      dst[0x38 + 15] = src[15];
      dst[0x38 + 16] = src[16];
      dst[0x38 + 17] = src[17];
      dst[0x38 + 18] = src[18];
      dst[0x38 + 19] = src[19];
      src += 20;
      dst += 20;
    } while (i < 10);
  }
  *(unsigned char *)(param_1 + 0x21) = DAT_002c049c;
  *(short *)((char *)param_1 + 0x86) = DAT_002c049e;
  *(float *)(param_1 + 0x22) = DAT_002c04a0;
  *(float *)(param_1 + 0x23) = DAT_002c04a4;
  *(float *)(param_1 + 0x24) = DAT_002c04a8;
  *(float *)(param_1 + 0x25) = DAT_002c04ac;
  *(float *)(param_1 + 0x26) = DAT_002c04b0;
  *(short *)(param_1 + 0x27) = DAT_002c04b4;
  *(float *)(param_1 + 0x28) = DAT_002c04b8;
  *(float *)(param_1 + 0x29) = DAT_002c04bc;
  *(float *)(param_1 + 0x2a) = DAT_002c04c0;
  *(float *)(param_1 + 0x2b) = DAT_002c04c4;
  *(float *)(param_1 + 0x2c) = DAT_002c04c8;
  param_1[0x2d] = DAT_002c04cc;
  *(short *)(param_1 + 0x2e) = DAT_002c04d0;
  param_1[0x2f] = DAT_002c04d4;
  return param_1;
}
}

// NEAR (lane sx1): 141/140 words, 111 differ (was 139/140, 116 differ). Everything matches in content; the residue is ONE extra word: after
// `if (cap < 16) reserve(16)` retail uses a plain `beqz at,L` with the then-block's `addiu a0,s0,424` in the slot, ours picks `beqzl at,L` with the
// virtual-call's `lw t9,0(s0)` in the slot AND keeps it at L (+1 word, shifting every later word). Levers found: lang=c++; Vec{data,size,cap} with
// `clear()` = shrink(size) (gives `lw v0,204; subu v0,v0,v0; sw`); slot 9 virtual (`lw t9,44(t9)`) via a 10-virtual VObj; frame 32 = static inline
// `Reserve(Vec*, unsigned, Tag t)` that drops its Tag (calls the 2-argument FUN_000d5480); the 2x20-float template copy is `float` with dst = (float*)param_1
// and `dst[0x38 + k]`; the trailing template members must be `extern const` (fresh `lui v0` per field, one load ahead) while the 20-float table stays non-const.
// near miss from lane sx1 (unreviewed)
