/* HSTMATCH module=EBOOT.BIN start=0x000d1f3c end=0x000d1fa0 symbol=FUN_000d1f3c lang=c++ */
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
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void m(int, int); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void m(int, int); };

extern "C" void FUN_000d1f3c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5)
{
  ((VC_0 *)(param_1))->m((int)(param_4), (int)(param_5));
  ((VC_1 *)(param_1))->m((int)(param_2), (int)(param_3));
  return;
}
