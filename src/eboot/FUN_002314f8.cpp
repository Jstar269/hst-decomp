/* HSTMATCH module=EBOOT.BIN start=0x002314f8 end=0x002315c4 symbol=FUN_002314f8 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7), refined by hstperm.py tag p4 random mutation from try/gen-a7/v20c/FUN_002314f8.cpp; exact match verified; names and types await human review. */
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
extern undefined DAT_00309820;
extern int * DAT_0034a65c;
extern undefined4 DAT_0034a660;
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001f0f0(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_002314f8(undefined4 *param_1,short param_2)
{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309820);
    DAT_0034a660 = 0;
    piVar1 = DAT_0034a65c;
    if (DAT_0034a65c != (int *)0x0) {
      if (DAT_0034a65c != (int *)0x0) {
        DAT_0034a65c = (int *)0x0;
        piVar2 = (int *)*piVar1;
        if (piVar2 != (int *)0x0) {
          delete ((VC_0 *)(piVar2));
          *piVar1 = 0;
        }
        FUN_00000a00(piVar1);
      }
      DAT_0034a65c = (int *)0x0;
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
