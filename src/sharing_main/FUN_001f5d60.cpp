/* HSTMATCH module=hstp_trans_main.prx start=0x001f5d60 end=0x001f5dd8 symbol=FUN_001f5d60 lang=c++ */
/* Clone of src/eboot/FUN_001e7b48.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern void FUN_00108f54(...);
extern void FUN_001eec00(...);
extern void FUN_001f08e8(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001f5d60(int param_1)
{
  int *piVar1;
  
  FUN_001eec00(param_1,2);
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x58);
  ((VC_0 *)(piVar1))->m((int)(1));
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x5c);
  ((VC_1 *)(piVar1))->m((int)(1));
  FUN_001f08e8(param_1);
  FUN_00108f54(*(undefined4 *)(param_1 + 0x2464),0);
  *(undefined4 *)(*(int *)(param_1 + 0x246c) + 0x24) =
       *(undefined4 *)(*(int *)(param_1 + 0x246c) + 0x28);
  return;
}
