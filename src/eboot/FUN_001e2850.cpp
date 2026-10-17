/* HSTMATCH module=EBOOT.BIN start=0x001e2850 end=0x001e28e0 symbol=FUN_001e2850 lang=c++ */
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
extern void FUN_000ffb3c(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001e2850(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x58);
  ((VC_0 *)(piVar1))->m((int)(1));
  piVar1 = *(int **)(*(int *)(param_1 + 0x3c) + 0x5c);
  ((VC_1 *)(piVar1))->m((int)(0));
  FUN_000ffb3c(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x7c),0);
  FUN_000ffb3c(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x84),0);
  FUN_000ffb3c(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x80),0);
  FUN_000ffb3c(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x88),0);
  return;
}
