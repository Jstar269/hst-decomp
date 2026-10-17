/* HSTMATCH module=hstp_trans_main.prx start=0x00055c68 end=0x00055d24 symbol=FUN_00055c68 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: modeled the indirect dispatch as a typed virtual call and shared the allocation result store across both paths; exact match verified; names and types await human review. */
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

extern "C" int FUN_00000bcc(int);
extern "C" int FUN_00054130(int,int,int,int,int,int,int);

struct VC_00055c68 { virtual ~VC_00055c68(); virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); };

extern "C" bool FUN_00055c68(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  
  ((VC_00055c68 *)param_1)->s2();
  iVar1 = FUN_00000bcc(0x30);
  if (iVar1 != 0) {
    iVar1 = FUN_00054130(iVar1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  param_1[0x23] = iVar1;
  *(undefined1 *)(param_1 + 0x24) = 1;
  return *(int *)(param_1[0x23] + 8) != 0;
}
