/* HSTMATCH module=EBOOT.BIN start=0x0013086c end=0x0013096c symbol=FUN_0013086c lang=c++ */
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
extern undefined DAT_003081f0;
extern undefined4 DAT_00340284;
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001f0f0(...);
extern int * FUN_00063e44(...);
extern void FUN_0013096c(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

extern "C" undefined4 * FUN_0013086c(undefined4 *param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003081f0);
    DAT_00340284 = 0;
    FUN_0013096c(param_1,0);
    piVar1 = (int *)param_1[0x1f];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0x1f] = 0;
    }
    piVar1 = (int *)param_1[0x20];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[0x20] = 0;
    }
    piVar1 = (int *)param_1[0x21];
    if (piVar1 != (int *)0x0) {
      delete ((VC_2 *)(piVar1));
      param_1[0x21] = 0;
    }
    iVar2 = param_1[0x12];
    if (iVar2 != 0) {
      FUN_00063e44(iVar2,1);
      param_1[0x12] = 0;
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
