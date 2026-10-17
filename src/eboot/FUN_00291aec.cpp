/* HSTMATCH module=EBOOT.BIN start=0x00291aec end=0x00291b8c symbol=FUN_00291aec lang=c++ */
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
extern undefined DAT_00309ddc;
extern void FUN_00000a00(...);
extern int FUN_0005ba00(...);
extern void FUN_00291cdc(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_00291aec(undefined4 *param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309ddc);
    piVar1 = (int *)param_1[3];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[3] = 0;
    }
    iVar2 = param_1[4];
    if (iVar2 != 0) {
      FUN_0005ba00(iVar2,1);
      param_1[4] = 0;
    }
    FUN_00291cdc(param_1);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
