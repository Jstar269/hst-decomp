/* HSTMATCH module=hstp_trans_main.prx start=0x0012dd1c end=0x0012e590 symbol=FUN_0012dd1c lang=c++ */
/* Hand-written reconstruction (port of src/eboot/FUN_00122b48.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

struct Sub48 {
  char pad0[0x50];
  signed char f50;
  char pad1[3];
  signed char f54;
};

struct Sub50 {
  char pad0[0x44];
  short f44;
};

struct Obj {
  char pad0[0x48];
  Sub48 *f48;
  Sub48 *f4c;
  Sub50 *f50;
  int f54;
  int f58;
  int f5c;
  float f60;
  float f64;
  float f68;
  float f6c;
  float f70;
  int f74;
  unsigned char f78;
  char pad79[0x84 - 0x79];
  float f84;
  float f88;
  int f8c;
  int f90;
  unsigned char f94;
};

struct TableEntry {
  char pad0[0x44];
  short f44;
  short f46;
  short f48;
  char pad4a[0x4e - 0x4a];
  signed char f4e;
  char f4f;
  signed char f50;
  char pad51[0x58 - 0x51];
};

extern "C" {
extern undefined4 DAT_003da704;
extern undefined * DAT_003e19f0;
extern TableEntry DAT_003e48c4[];
extern undefined * DAT_003e95c4;
extern void FUN_0012f448(...);
extern void FUN_0012f5f0(...);
extern void FUN_0012f7e4(...);
extern int FUN_001303e0(...);
extern undefined4 FUN_001303ec(...);
extern float FUN_001304a4(...);
extern int FUN_001304d0(...);
extern void FUN_00130984(...);
extern void FUN_00130af0(...);
extern void FUN_00131004(...);
extern void FUN_00131270(...);
extern float FUN_0013c0c8(...);
extern void FUN_0013c714(...);
extern undefined1 * FUN_0013d6dc(...);
extern void FUN_0017682c(...);
extern void FUN_002252e0(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0012dd1c(Obj *param_1)
{
  if (!param_1->f78) {
    return;
  }
  float fVar7;
  float fVar8;
  param_1->f68 += 1.0f;
  if (param_1->f6c > 0.0f) {
    if (param_1->f64 > 0.0f) {
      fVar8 = param_1->f64;
      param_1->f64 += 1.0f;
    }
    else if (param_1->f60 > 0.0f) {
      fVar8 = param_1->f60;
    }
    else {
      int iVar3 = *(int *)(*(int *)(DAT_003e19f0 + 0x9c) + 0x58);
      fVar8 = (float)iVar3 + FUN_0013c0c8(DAT_003e95c4);
    }
    if (fVar8 < (float)FUN_001303e0(param_1, 3)) {
      param_1->f6c -= 1.0f;
      if (param_1->f6c != 1.0f && param_1->f6c <= 0.0f) {
        int local_4;
        param_1->f84 = 0.0f;
        if (DAT_003e48c4[param_1->f58].f48 != 0) {
          FUN_0013d6dc((int)DAT_003e48c4[param_1->f58].f48, &local_4);
          local_4 = FUN_001304d0(param_1, local_4);
        }
        else {
          FUN_0012f448(param_1);
          FUN_0013d6dc((int)DAT_003e48c4[param_1->f58].f44, &local_4);
          local_4 = FUN_001304d0(param_1, local_4);
        }
        param_1->f58 = -1;
        param_1->f90 = (int)((float)param_1->f90 + param_1->f70);
        FUN_00130af0(param_1, local_4);
      }
    }
  }
  fVar8 = param_1->f84;
  if (fVar8 >= 0.0f) {
    if (param_1->f64 > 0.0f) {
      fVar7 = param_1->f64;
      switch (*(unsigned char *)(DAT_003e19f0 + 0x4c)) {
      case 0:
        param_1->f64 += 1.0f;
        break;
      }
    }
    else if (param_1->f60 > 0.0f) {
      fVar7 = param_1->f60;
    }
    else {
      int iVar3 = *(int *)(*(int *)(DAT_003e19f0 + 0x9c) + 0x58);
      fVar7 = (float)iVar3 + FUN_0013c0c8(DAT_003e95c4);
    }
    param_1->f84 = fVar7 - (float)param_1->f90;
    if (param_1->f60 <= 0.0f) {
      if (param_1->f94 == 0 && param_1->f58 == 7) {
        param_1->f84 = 0.0f;
      }
      else if (param_1->f94 != 0 || DAT_003e48c4[param_1->f58].f46 != 60) {
        float fVar6 = param_1->f88;
        if (param_1->f84 == fVar6 - 1.0f) {
          if (*(int *)(DAT_003e95c4 + 0x8c) == 3) {
            FUN_0013c714(DAT_003e95c4);
            return;
          }
        }
        else if (fVar8 < fVar6 && param_1->f84 >= fVar6) {
          signed char mode = DAT_003e48c4[param_1->f58].f4e;
          if (mode == 5) {
            int local_8;
            param_1->f84 = 0.0f;
            FUN_0013d6dc((int)param_1->f50->f44, &local_8);
            local_8 = FUN_001304d0(param_1, local_8);
            param_1->f58 = -1;
            float f = param_1->f88 - FUN_0013c0c8(DAT_003e95c4);
            param_1->f90 = (int)((float)param_1->f90 + f);
            FUN_00130af0(param_1, local_8);
          }
          else if (mode == 4 || mode == 1 || mode == 2) {
            int local_c;
            FUN_0013d6dc((int)param_1->f50->f44, &local_c);
            local_c = FUN_001304d0(param_1, local_c);
            if (DAT_003e48c4[local_c].f4e != 0 || DAT_003e48c4[param_1->f58].f50 == 7) {
              param_1->f84 = 0.0f;
              param_1->f58 = -1;
              float f = param_1->f88 - FUN_0013c0c8(DAT_003e95c4);
              param_1->f90 = (int)((float)param_1->f90 + f);
              FUN_00130af0(param_1, local_c);
            }
          }
          else if (mode == 3 && DAT_003e48c4[param_1->f58].f48 != 999) {
            int local_10;
            if (param_1->f64 > 0.0f) {
              param_1->f84 = 0.0f;
              FUN_0013d6dc((int)DAT_003e48c4[param_1->f58].f44, &local_10);
              local_10 = FUN_001304d0(param_1, local_10);
              for (int i = 0; local_10 == param_1->f58 && i < 100; i++) {
                FUN_0013d6dc((int)DAT_003e48c4[param_1->f58].f44, &local_10);
                local_10 = FUN_001304d0(param_1, local_10);
              }
              param_1->f58 = -1;
              FUN_00130af0(param_1, local_10);
              param_1->f64 = (float)param_1->f90;
            }
            else if (fVar7 >= FUN_001304a4(param_1) - 60.0f) {
            }
            else {
              param_1->f84 = 0.0f;
              FUN_0012f448(param_1);
              FUN_0013d6dc((int)DAT_003e48c4[param_1->f58].f44, &local_10);
              local_10 = FUN_001304d0(param_1, local_10);
              param_1->f58 = -1;
              float f = param_1->f88 - FUN_0013c0c8(DAT_003e95c4);
              param_1->f90 = (int)((float)param_1->f90 + f);
              FUN_00130af0(param_1, local_10);
            }
          }
        }
      }
      if (param_1->f94 != 0 && DAT_003e48c4[param_1->f58].f48 == 60 &&
          fVar7 != FUN_001304a4(param_1) && fVar7 > FUN_001304a4(param_1)) {
        int local_14;
        FUN_0013d6dc(60, &local_14);
        int uVar2 = FUN_001304d0(param_1, local_14);
        param_1->f90 = (int)(1.0f + FUN_001304a4(param_1));
        FUN_00130af0(param_1, uVar2);
      }
    }
  }
  if (param_1->f84 >= 0.0f) {
    signed char c = param_1->f4c->f50;
    if (c != 4 && c != 6) {
      FUN_0012f5f0(param_1);
    }
    FUN_0012f7e4(param_1);
  }
  else {
    signed char c = param_1->f48->f50;
    if (c != 4 && c != 6) {
      FUN_0012f5f0(param_1);
    }
    FUN_00131004(FUN_001303ec(param_1), 0);
    FUN_00130984(param_1, FUN_001303ec(param_1));
    FUN_002252e0(param_1->f54, FUN_001303ec(param_1));
    FUN_0017682c(FUN_001303ec(param_1), param_1->f48->f54 > 0);
    int uVar2 = FUN_001303ec(param_1);
    int iVar3 = FUN_001303ec(param_1);
    FUN_00131270(uVar2, **(undefined4 **)(iVar3 + 0x90));
    VC_0 *piVar4 = (VC_0 *)FUN_001303ec(param_1);
    piVar4->m(DAT_003da704);
  }
}
