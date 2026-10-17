/* HSTMATCH module=EBOOT.BIN start=0x001e7b48 end=0x001e7bc0 symbol=FUN_001e7b48 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
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
extern void FUN_00103628(...);
extern void FUN_001e09dc(...);
extern void FUN_001e2694(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001e7b48(int param_1)
{
  int *piVar1;
  
  FUN_001e09dc(param_1,2);
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x58);
  ((VC_0 *)(piVar1))->m((int)(1));
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x5c);
  ((VC_1 *)(piVar1))->m((int)(1));
  FUN_001e2694(param_1);
  FUN_00103628(*(undefined4 *)(param_1 + 0x2464),0);
  *(undefined4 *)(*(int *)(param_1 + 0x246c) + 0x24) =
       *(undefined4 *)(*(int *)(param_1 + 0x246c) + 0x28);
  return;
}
