/* HSTMATCH module=EBOOT.BIN start=0x0019cf8c end=0x0019d02c symbol=FUN_0019cf8c lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a6); exact match verified; names and types await human review. */
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
extern undefined DAT_003091cc;
extern undefined4 DAT_003415d4;
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001f0f0(...);
extern void FUN_00190848(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_0019cf8c(undefined4 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003091cc);
    piVar1 = (int *)param_1[0xf];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0xf] = 0;
    }
    if (DAT_003415d4 != 0) {
      FUN_00190848(DAT_003415d4);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
