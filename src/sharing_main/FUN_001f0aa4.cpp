/* HSTMATCH module=hstp_trans_main.prx start=0x001f0aa4 end=0x001f0b34 symbol=FUN_001f0aa4 lang=c++ */
/* Clone of src/eboot/FUN_001e2850.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern void FUN_00105470(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001f0aa4(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x58);
  ((VC_0 *)(piVar1))->m((int)(1));
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x5c);
  ((VC_1 *)(piVar1))->m((int)(0));
  FUN_00105470(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x7c),0);
  FUN_00105470(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x84),0);
  FUN_00105470(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x80),0);
  FUN_00105470(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x88),0);
  return;
}
