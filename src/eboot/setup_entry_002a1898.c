/* HSTMATCH module=EBOOT.BIN start=0x002a1898 end=0x002a1a4c symbol=FUN_002a1898 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct views and prototypes (the float-argument calls FUN_00057bc0/FUN_00057b58/FUN_00058ec4 and the float-returning clamp); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

typedef struct Sub_002a1898 {
  char pad[0x78];
  float f78;
} Sub_002a1898;

typedef struct Inner_002a1898 {
  char pad0[0x5c];
  Sub_002a1898 *f5c;
  char pad60[8];
  int f68;
  int f6c;
  unsigned char f70;
  char pad71[3];
  int f74;
} Inner_002a1898;

typedef struct Arg_002a1898 {
  int f0;
  int f4;
  int f8;
} Arg_002a1898;

typedef struct Obj_002a1898 {
  char pad0[0x1c8];
  Inner_002a1898 *f1c8;
  char pad1[0x1e0 - 0x1cc];
  int f1e0;
  unsigned char f1e4;
} Obj_002a1898;

extern float DAT_00300658;
extern float DAT_0030066c;
extern float DAT_00300670;
extern float DAT_00300674;
extern float DAT_00300678;
extern void FUN_00057b58(Obj_002a1898 *, int, int, float);
extern void FUN_00057bc0(Obj_002a1898 *, int, int, float, float, float);
extern void FUN_00058ddc(Obj_002a1898 *, int, int);
extern void FUN_00058ec4(Obj_002a1898 *, int, float);
extern void FUN_00059084(Obj_002a1898 *, int);
extern void FUN_00103480(Inner_002a1898 *);
extern void FUN_00114fb8(int);
extern float FUN_001cdd68(float *, float *, float *);
extern Sub_002a1898 *FUN_001d1f80(Inner_002a1898 *, int);
extern void FUN_001d2124(Sub_002a1898 *);
extern void FUN_001d61e4(int);
extern void FUN_002a0b84(Inner_002a1898 *, int);
extern void FUN_002a1398(Obj_002a1898 *, int, int);
extern void FUN_002a165c(Obj_002a1898 *, int);
extern void FUN_002a1a4c(int *, int);

void FUN_002a1898(Obj_002a1898 *param_1, Arg_002a1898 *param_2, unsigned char param_3)
{
  Inner_002a1898 *in;
  int iVar1;
  float fVar5;
  float local_4;
  float local_8;

  iVar1 = param_2->f0;
  in = param_1->f1c8;
  FUN_002a0b84(in, 1);
  FUN_002a1a4c(&in->f74, iVar1);
  FUN_001d2124(in->f5c);
  FUN_001d61e4(in->f68);
  FUN_00114fb8(in->f6c);
  in->f70 = param_3;
  local_4 = DAT_00300658 + FUN_001d1f80(in, 0)->f78;
  fVar5 = FUN_001cdd68(&local_4, &DAT_0030066c, &DAT_00300670);
  FUN_001d1f80(in, 0)->f78 = fVar5;
  local_8 = in->f5c->f78 + DAT_00300658;
  fVar5 = FUN_001cdd68(&local_8, &DAT_00300674, &DAT_00300678);
  in->f5c->f78 = fVar5;
  FUN_00103480(in);
  param_1->f1e4 = 1;
  FUN_002a165c(param_1, param_2->f8);
  iVar1 = param_2->f4;
  param_1->f1e0 = iVar1;
  if (iVar1 == 0xe) {
    FUN_00057bc0(param_1, 1, -1, 0.0f, 0.0f, 0.0f);
    FUN_00057b58(param_1, 1, iVar1, 0.0f);
  } else {
    FUN_002a1398(param_1, 1, iVar1);
  }
  FUN_00058ddc(param_1, 1, 1);
  FUN_00058ec4(param_1, 1, 1.0f);
  FUN_00059084(param_1, 1);
}
