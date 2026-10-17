/* HSTMATCH module=hstp_trans_main.prx start=0x0018a380 end=0x0018a3f0 symbol=FUN_0018a380 lang=c++ */
/* Clone of src/eboot/FUN_0017dc8c_0017dc8c.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a/v2) corrected by hand: this/float argument order and clamp access; exact match verified; names and types await human review. */
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
typedef float undefined4;

extern "C" int FUN_00177ea4();

struct StateView_0018a380 { char pad[0x4c]; float value; };

static inline float Clamp(const float &value, const float &low, const float &high)
{
  return value < low ? low : (!(value > high) ? value : high);
}

static inline const float &Current(const struct StateView_0018a380 *state)
{
  return state->value;
}

extern "C" void FUN_0018a380(int param_2,float param_1)
{
  int iVar1;
  
  iVar1 = FUN_00177ea4();
  *(float *)(param_2 + 0x4c) = param_1;
  *(float *)(param_2 + 0x4c) = Clamp(Current((const struct StateView_0018a380 *)param_2),
                 *(float *)(iVar1 + 0x1c), *(float *)(iVar1 + 0x20));
  return;
}
