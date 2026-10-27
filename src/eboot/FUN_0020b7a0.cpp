/* HSTMATCH module=EBOOT.BIN start=0x0020b7a0 end=0x0020be58 symbol=FUN_0020b7a0 lang=c++ data=0x002ef8b8 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002ef8b8-0x002ef8d1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef unsigned int uint;

struct Cfg {
  char pad0[0x45];
  unsigned char f45;
  char pad1[0x90 - 0x46];
  int f90;
};

struct Self {
  char pad0[0x84c];
  int f84c;
  int f850;
  int f854;
  int f858;
};

struct Slot8 {
  float f0;
  short s4;
  short s6;
};

struct A {
  char pad0[0x1c];
  Slot8 slots[6];
  short s4c;
  short s4e;
  char pad1[0x1c8 - 0x50];
  float f1c8;
  float f1cc;
  float f1d0;
};

extern "C" {
extern float DAT_002ef878;
extern float DAT_002ef87c;
extern float DAT_002ef880;
extern float DAT_002ef884;
extern float DAT_002ef888;
extern float DAT_002ef88c;
extern float DAT_002ef890;
extern float DAT_002ef894;
extern float DAT_002ef898;
extern float DAT_002ef89c;
extern float DAT_002ef8a0;
extern float DAT_002ef8a4;
extern float DAT_002ef8a8;
extern float DAT_002ef8ac;
extern float DAT_002ef8b0;
extern float DAT_002ef8b4;
extern Cfg *DAT_00338b44;

extern float FUN_0000ce3c(float, float);
extern uint FUN_0001342c(void);
extern bool FUN_000a8494(Self *, float *);
extern int FUN_002068e8(Self *, int, int);
extern void FUN_0020b600(const char *, ...);
extern A *FUN_00215a20(Self *);
extern A *FUN_00215a58(...);
}

static inline float Max(const float &a, const float &b)
{
  return !(a > b) ? b : a;
}

static inline float MaxV(const float &a, float b)
{
  return !(a > b) ? b : a;
}

static inline float Min(const float &a, const float &b)
{
  return !(a > b) ? a : b;
}

static inline const int &MaxInt(const int &a, const int &b)
{
  return a < b ? b : a;
}

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" int FUN_0020b7a0(Self *param_3, int param_4, int param_5, float param_1, float param_2)
{
  float fVar12;
  float fVar10;
  float fVar11;

  if (DAT_00338b44->f90 == 1) {
    float s1 = FUN_00215a58()->f1c8;
    s1 = s1 + FUN_00215a20(param_3)->f1c8;
    fVar12 = Max(DAT_002ef878, s1);

    float s2 = FUN_00215a58(param_3)->f1cc;
    s2 = s2 + FUN_00215a20(param_3)->f1cc;
    fVar10 = Max(DAT_002ef87c, s2);

    float s3 = FUN_00215a58(param_3)->f1d0;
    s3 = s3 + FUN_00215a20(param_3)->f1d0;
    fVar11 = Max(DAT_002ef880, s3);
  }
  else {
    float vec[4];
    vec[0] = param_1;
    vec[1] = param_1;
    vec[2] = param_1;
    vec[3] = param_1;
    bool bVar4 = FUN_000a8494(param_3, vec);
    bool bVar3 = (param_5 == 0 && param_4 == 2);
    bool bVar2 = (param_5 == 6);
    int idx;
    if (bVar4) {
      if (bVar3) {
        idx = 4;
      }
      else if (bVar2) {
        idx = 5;
      }
      else {
        idx = 3;
      }
    }
    else {
      if (bVar3) {
        idx = 1;
      }
      else if (bVar2) {
        idx = 2;
      }
      else {
        idx = 0;
      }
    }
    float s1 = FUN_00215a58(param_3)->slots[idx].f0;
    s1 = s1 + FUN_00215a20(param_3)->slots[idx].f0;
    fVar12 = Max(DAT_002ef884, s1);

    int h1 = FUN_00215a58(param_3)->slots[idx].s4 + FUN_00215a20(param_3)->slots[idx].s4;
    fVar10 = MaxV(DAT_002ef888, (float)h1);

    int h2 = FUN_00215a58(param_3)->slots[idx].s6 + FUN_00215a20(param_3)->slots[idx].s6;
    fVar11 = MaxV(DAT_002ef88c, (float)h2);

    if (DAT_00338b44->f45 != 0) {
      if (bVar3) {
        fVar10 = Min(fVar10 + (float)param_3->f850, DAT_002ef890);
        fVar11 = Min(fVar11 + 0.5f * (float)param_3->f850, DAT_002ef894);
        FUN_0020b600("not lob %d\n", param_3->f850);
      }
      if (bVar2) {
        fVar10 = Min(fVar10 + 0.4f * (float)param_3->f84c, DAT_002ef898);
        fVar11 = Min(fVar11 + 0.2f * (float)param_3->f84c, DAT_002ef89c);
        FUN_0020b600("not drop %d\n", param_3->f84c);
      }
      float sign = 0.0f;
      if (param_4 == 1) {
        sign = param_3->f854 > 0 ? -1.0f : 1.0f;
      }
      else if (param_4 == 0) {
        sign = param_3->f858 > 0 ? -1.0f : 1.0f;
      }
      float d = sign * (float)MaxInt(param_3->f854, param_3->f858);
      if (d != 0.0f) {
        if (d > 0.0f) {
          d = d * 0.4f;
        }
        else {
          d = d * 0.5f;
        }
        fVar10 = Clamp(fVar10 + d, DAT_002ef8a0, DAT_002ef8a4);
        fVar11 = Clamp(fVar11 + d, DAT_002ef8a8, DAT_002ef8ac);
      }
    }
  }
  int code = FUN_002068e8(param_3, param_4, param_5);
  int c1 = FUN_00215a58(param_3)->s4c + FUN_00215a20(param_3)->s4c;
  if ((float)code == MaxV(DAT_002ef8b0, (float)c1)) {
    fVar12 *= 1.2f;
    fVar10 *= 0.8f;
    fVar11 *= 0.8f;
  }
  else {
    int c2 = FUN_00215a58(param_3)->s4e + FUN_00215a20(param_3)->s4e;
    if ((float)code == MaxV(DAT_002ef8b4, (float)c2)) {
      fVar12 *= 0.8f;
      fVar10 *= 1.2f;
      fVar11 *= 1.2f;
    }
  }
  if (param_2 == 0.0f) {
    uint u = FUN_0001342c();
    param_2 = FUN_0000ce3c(4.656613e-10f * (float)(int)(u & 0xfffff800), fVar12);
  }
  return (int)(fVar10 + param_2 * (fVar11 - fVar10));
}
