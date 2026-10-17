/* HSTMATCH module=EBOOT.BIN start=0x0021da3c end=0x0021dad4 symbol=FUN_0021da3c lang=c++ */
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
extern undefined DAT_00309744;
extern void FUN_00000a00(...);
extern undefined4 * FUN_00102ea4(...);
extern void FUN_0021dbbc(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_0021da3c(undefined4 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309744);
    FUN_0021dbbc();
    piVar1 = (int *)param_1[0x5b];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x5b] = 0;
    }
    FUN_00102ea4(param_1 + 0x5d,0xffffffff);
    FUN_00102ea4(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
