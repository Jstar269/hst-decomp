/* HSTMATCH module=hstp_trans_main.prx start=0x0021a2c0 end=0x0021a978 symbol=FUN_0021a2c0 lang=c++ data=0x00397a98 */
/* Clone of src/eboot/FUN_0020b7a0.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00397a98-0x00397ab1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/types.h"

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
extern float DAT_00397a58;
extern float DAT_00397a5c;
extern float DAT_00397a60;
extern float DAT_00397a64;
extern float DAT_00397a68;
extern float DAT_00397a6c;
extern float DAT_00397a70;
extern float DAT_00397a74;
extern float DAT_00397a78;
extern float DAT_00397a7c;
extern float DAT_00397a80;
extern float DAT_00397a84;
extern float DAT_00397a88;
extern float DAT_00397a8c;
extern float DAT_00397a90;
extern float DAT_00397a94;
extern Cfg *DAT_003e1e84;

extern float FUN_0000ce54(float, float);
extern u32 FUN_0001342c(void);
extern bool FUN_000aae88(Self *, float *);
extern int FUN_00215150(Self *, int, int);
extern void FUN_002164c4(const char *, ...);
extern A *FUN_002248ac(Self *);
extern A *FUN_0022492c(...);
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

extern "C" int FUN_0021a2c0(Self *param_3, int param_4, int param_5, float param_1, float param_2)
{
  float fVar12;
  float fVar10;
  float fVar11;

  if (DAT_003e1e84->f90 == 1) {
    float s1 = FUN_0022492c()->f1c8;
    s1 = s1 + FUN_002248ac(param_3)->f1c8;
    fVar12 = Max(DAT_00397a58, s1);

    float s2 = FUN_0022492c(param_3)->f1cc;
    s2 = s2 + FUN_002248ac(param_3)->f1cc;
    fVar10 = Max(DAT_00397a5c, s2);

    float s3 = FUN_0022492c(param_3)->f1d0;
    s3 = s3 + FUN_002248ac(param_3)->f1d0;
    fVar11 = Max(DAT_00397a60, s3);
  }
  else {
    float vec[4];
    vec[0] = param_1;
    vec[1] = param_1;
    vec[2] = param_1;
    vec[3] = param_1;
    bool bVar4 = FUN_000aae88(param_3, vec);
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
    float s1 = FUN_0022492c(param_3)->slots[idx].f0;
    s1 = s1 + FUN_002248ac(param_3)->slots[idx].f0;
    fVar12 = Max(DAT_00397a64, s1);

    int h1 = FUN_0022492c(param_3)->slots[idx].s4 + FUN_002248ac(param_3)->slots[idx].s4;
    fVar10 = MaxV(DAT_00397a68, (float)h1);

    int h2 = FUN_0022492c(param_3)->slots[idx].s6 + FUN_002248ac(param_3)->slots[idx].s6;
    fVar11 = MaxV(DAT_00397a6c, (float)h2);

    if (DAT_003e1e84->f45 != 0) {
      if (bVar3) {
        fVar10 = Min(fVar10 + (float)param_3->f850, DAT_00397a70);
        fVar11 = Min(fVar11 + 0.5f * (float)param_3->f850, DAT_00397a74);
        FUN_002164c4("not lob %d\n", param_3->f850);
      }
      if (bVar2) {
        fVar10 = Min(fVar10 + 0.4f * (float)param_3->f84c, DAT_00397a78);
        fVar11 = Min(fVar11 + 0.2f * (float)param_3->f84c, DAT_00397a7c);
        FUN_002164c4("not drop %d\n", param_3->f84c);
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
        fVar10 = Clamp(fVar10 + d, DAT_00397a80, DAT_00397a84);
        fVar11 = Clamp(fVar11 + d, DAT_00397a88, DAT_00397a8c);
      }
    }
  }
  int code = FUN_00215150(param_3, param_4, param_5);
  int c1 = FUN_0022492c(param_3)->s4c + FUN_002248ac(param_3)->s4c;
  if ((float)code == MaxV(DAT_00397a90, (float)c1)) {
    fVar12 *= 1.2f;
    fVar10 *= 0.8f;
    fVar11 *= 0.8f;
  }
  else {
    int c2 = FUN_0022492c(param_3)->s4e + FUN_002248ac(param_3)->s4e;
    if ((float)code == MaxV(DAT_00397a94, (float)c2)) {
      fVar12 *= 0.8f;
      fVar10 *= 1.2f;
      fVar11 *= 1.2f;
    }
  }
  if (param_2 == 0.0f) {
    u32 u = FUN_0001342c();
    param_2 = FUN_0000ce54(4.656613e-10f * (float)(int)(u & 0xfffff800), fVar12);
  }
  return (int)(fVar10 + param_2 * (fVar11 - fVar10));
}
