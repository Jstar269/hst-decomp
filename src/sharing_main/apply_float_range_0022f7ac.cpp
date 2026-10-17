/* HSTMATCH module=hstp_trans_main.prx start=0x0022f7ac end=0x0022f8ac symbol=FUN_0022f7ac lang=c++ */
/* Clone of src/eboot/apply_float_range_00220238.cpp (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: typed nested float fields and used a const-reference clamp helper; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined4 DAT_0039835c;
extern float DAT_00398f18;
extern float DAT_00398f48;
extern float DAT_00398f4c;
extern undefined * DAT_003ea8e8;
extern float DAT_003f3530;
extern float DAT_003f3534;
extern void FUN_00105470(int, int);
extern void FUN_00108dac(int);
extern void FUN_0022f8e4(int);
extern undefined4 FUN_00280524(undefined *);
}

struct Inner_60 {
  char pad00[0x60];
  float f60;
  float f64;
  char pad68[0x10];
  float f78;
};

struct Outer_60 {
  char pad00[0x60];
  struct Inner_60 *inner;
};

static inline float Clamp_20220238(const float &value, const float &low, const float &high)
{
  return value < low ? low : (!(value > high) ? value : high);
}

extern "C" void FUN_0022f7ac(int param_1,undefined1 param_2)
{
  uint uVar1;
  int iVar2;
  float fVar3;
  
  uVar1 = FUN_00280524(DAT_003ea8e8 + 0x80);
  if ((uVar1 & 0xff) == 0) {
    *(undefined4 *)(param_1 + 0x5c) = DAT_0039835c;
    *(undefined1 *)(param_1 + 0x74) = param_2;
    FUN_0022f8e4(param_1);
    struct Outer_60 *outer = (struct Outer_60 *)param_1;
    outer->inner->f60 = DAT_003f3530;
    outer->inner->f64 = DAT_003f3534;
    fVar3 = Clamp_20220238(DAT_00398f18, DAT_00398f48, DAT_00398f4c);
    outer->inner->f78 = fVar3;
    FUN_00108dac(param_1);
    FUN_00105470(*(int *)(param_1 + 0x68),*(unsigned char *)(param_1 + 0x74) != 0 ^ 1);
  }
  return;
}
