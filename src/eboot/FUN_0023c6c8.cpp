/* HSTMATCH module=EBOOT.BIN start=0x0023c6c8 end=0x0023c71c symbol=FUN_0023c6c8 lang=c++ */
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
extern void FUN_0010b6d4(...);
extern void FUN_0023de6c(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0023c6c8(int param_1)
{
  ((VC_0 *)(*(int **)(param_1 + 0x11b8)))->m((int)(0));
  FUN_0010b6d4(*(undefined4 *)(param_1 + 0x11b8),0x11,0x19);
  FUN_0023de6c(param_1,1,0);
  return;
}
