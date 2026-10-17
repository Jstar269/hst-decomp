/* HSTMATCH module=EBOOT.BIN start=0x0017dc14 end=0x0017dc8c symbol=FUN_0017dc14 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: this/float argument order and clamp access; exact match verified; names and types await human review. */
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

extern "C" int FUN_0016bc7c();

struct StateView_0017dc14 { char pad[0x4c]; float value; };

static inline float Clamp(const float &value, const float &low, const float &high)
{
  return value < low ? low : (!(value > high) ? value : high);
}

static inline const float &Current(const struct StateView_0017dc14 *state)
{
  return state->value;
}

extern "C" void FUN_0017dc14(int param_2,float param_1)
{
  int iVar1;
  
  iVar1 = FUN_0016bc7c();
  *(float *)(param_2 + 0x4c) = *(float *)(param_2 + 0x4c) + param_1;
  *(float *)(param_2 + 0x4c) = Clamp(Current((const struct StateView_0017dc14 *)param_2),
                 *(float *)(iVar1 + 0x1c), *(float *)(iVar1 + 0x20));
  return;
}
