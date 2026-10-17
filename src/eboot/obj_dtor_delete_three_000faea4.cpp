/* HSTMATCH module=EBOOT.BIN start=0x000faea4 end=0x000faf9c symbol=FUN_000faea4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the tested global DAT_0034a820 is also the argument of FUN_00291cdc (Ghidra dropped it; retail loads it into a0), which also fixes the s0/s1 assignment; exact match verified; names and types await human review. */
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
extern undefined DAT_00307760;
extern undefined4 DAT_00338c20;
extern undefined4 DAT_0034a820;
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001f0f0(...);
extern void FUN_00291cdc(...);

}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

extern "C" undefined4 * FUN_000faea4(undefined4 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307760);
    DAT_00338c20 = 0;
    piVar1 = (int *)param_1[0xf];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[0xf] = 0;
    }
    piVar1 = (int *)param_1[0x11];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[0x11] = 0;
    }
    piVar1 = (int *)param_1[0x10];
    if (piVar1 != (int *)0x0) {
      delete ((VC_2 *)(piVar1));
      param_1[0x10] = 0;
    }
    if (DAT_0034a820 != 0) {
      FUN_00291cdc(DAT_0034a820);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
