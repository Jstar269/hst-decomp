/* HSTMATCH module=EBOOT.BIN start=0x0025d580 end=0x0025d5c4 symbol=FUN_0025d580 lang=c++ */
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
extern void FUN_0025d5c4(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void m(int); };

extern "C" void FUN_0025d580(int param_1)
{
  FUN_00103628(param_1,1);
  ((VC_0 *)(*(int **)(param_1 + 0x68)))->m((int)(0));
  FUN_0025d5c4(param_1);
  return;
}
