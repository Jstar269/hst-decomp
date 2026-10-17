/* HSTMATCH module=EBOOT.BIN start=0x00219184 end=0x00219210 symbol=FUN_00219184 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
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
extern void FUN_000006e8(...);
extern void FUN_00000a00(...);
extern void FUN_002190e4(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int * FUN_00219184(int *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    if (param_1[1] != 0) {
      FUN_000006e8(param_1[1],FUN_002190e4);
      param_1[1] = 0;
    }
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *param_1 = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
