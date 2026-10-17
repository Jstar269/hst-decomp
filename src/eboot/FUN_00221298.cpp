/* HSTMATCH module=EBOOT.BIN start=0x00221298 end=0x00221314 symbol=FUN_00221298 lang=c++ */
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
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void m(int); };
struct VC_3 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_00221298(int param_1)
{
  FUN_00103628(param_1,0);
  *(undefined1 *)(param_1 + 0x58) = 0;
  ((VC_0 *)(*(int **)(param_1 + 100)))->m((int)(1));
  ((VC_1 *)(*(int **)(param_1 + 0x6c)))->m((int)(1));
  ((VC_2 *)(*(int **)(param_1 + 0x70)))->m((int)(1));
  ((VC_3 *)(*(int **)(param_1 + 0x74)))->m((int)(1));
  return;
}
