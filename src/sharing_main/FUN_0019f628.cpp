/* HSTMATCH module=hstp_trans_main.prx start=0x0019f628 end=0x0019f69c symbol=FUN_0019f628 lang=c++ */
/* Clone of src/eboot/FUN_00192e18.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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
extern void FUN_0019f69c(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_0019f628(int param_1)
{
  int *piVar1;
  
  FUN_0019f69c();
  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    delete ((VC_1 *)(piVar1));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}
