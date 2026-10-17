/* HSTMATCH module=hstp_trans_main.prx start=0x0005b448 end=0x0005b540 symbol=FUN_0005b448 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v17) corrected by hand: grouped the helper calls under switch cases 4, 3, and 1; exact match verified; names and types await human review. */
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

extern "C" {
extern void FUN_000536b4(...);
}
struct VC_0 { virtual void d0(); virtual int m(); };

extern "C" void FUN_0005b448(int *param_1,undefined4 param_2,int *param_3)
{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    param_3 = param_1 + 4;
  }
  iVar1 = ((VC_0 *)(param_1))->m();
  switch (iVar1) {
  case 4:
    FUN_000536b4(param_2,param_3,4,param_1[0x18],param_1[0x17],0,param_1[param_1[0x15] + 0x19]);
    break;
  case 3:
    FUN_000536b4(param_2,param_3,3,param_1[0x18],param_1[0x17],0,param_1[param_1[0x15] + 0x19]);
    break;
  case 1:
    FUN_000536b4(param_2,param_3,1,param_1[0x18],param_1[0x17],0,param_1[param_1[0x15] + 0x19]);
    break;
  }
  return;
}
