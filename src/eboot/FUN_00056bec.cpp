/* HSTMATCH module=EBOOT.BIN start=0x00056bec end=0x00056cb0 symbol=FUN_00056bec lang=c++ */
/* Clone of src/sharing_main/FUN_00057840.cpp (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v12) corrected by hand: typed the helper calls and expressed virtual slot +0x10 as a C++ method; exact match verified; names and types await human review. */
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

extern undefined DAT_00306ff8;
extern "C" void FUN_00056d68(int *);
extern "C" int * FUN_0005eaa8(int *);

struct V5
{
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2(undefined4,undefined4,undefined4,undefined4,undefined4,undefined4);
};

extern "C" int * FUN_00056bec(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  FUN_0005eaa8(param_1);
  *param_1 = (int)&DAT_00306ff8;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  FUN_00056d68(param_1);
  ((V5 *)param_1)->Slot2(param_2,param_3,param_4,param_5,param_6,param_7);
  return param_1;
}
