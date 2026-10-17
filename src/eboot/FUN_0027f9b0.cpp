/* HSTMATCH module=EBOOT.BIN start=0x0027f9b0 end=0x0027fa8c symbol=FUN_0027f9b0 lang=c++ */
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
extern void FUN_00000a00(...);
extern int FUN_0027fa8c(...);
}
struct VC_0 {  virtual void m(int); };

extern "C" int * FUN_0027f9b0(int *param_1,short param_2)
{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)(*param_1 + param_1[4] * 0x28);
    piVar2 = piVar1 + param_1[1] * 10;
    if (piVar1 < piVar2) {
      do {
        piVar2 = piVar2 + -10;
        ((VC_0 *)(piVar2))->m((int)(0xffffffff));
      } while (piVar1 < piVar2);
      param_1[1] = 0;
    }
    else {
      param_1[1] = 0;
    }
    if ((param_1 != (int *)0x0) && (FUN_0027fa8c(param_1), *param_1 != 0)) {
      FUN_00000a00(*(int *)((int)param_1 + 0));
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
