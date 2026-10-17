/* HSTMATCH module=EBOOT.BIN start=0x002aff18 end=0x002affdc symbol=FUN_002aff18 lang=c++ */
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
extern undefined DAT_00309f98;
extern undefined DAT_00309fb4;
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001f0f0(...);
extern undefined4 * FUN_00102ea4(...);
extern int FUN_002175d4(...);
extern void FUN_002afeac(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_002aff18(undefined4 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309f98);
    param_1[0xf] = (unsigned int)(&DAT_00309fb4);
    piVar1 = (int *)param_1[0x12a];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x12a] = 0;
    }
    FUN_002175d4(param_1 + 0x107,0xffffffff);
    FUN_00000788(param_1 + 0x26,FUN_002afeac,0xc,10);
    FUN_00102ea4(param_1 + 0xf,0);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
