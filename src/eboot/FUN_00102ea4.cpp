/* HSTMATCH module=EBOOT.BIN start=0x00102ea4 end=0x00102fb0 symbol=FUN_00102ea4 lang=c++ */
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
extern undefined DAT_00307b18;
extern void FUN_00000a00(...);
extern int * FUN_00054600(...);
extern int * FUN_000c3fd8(...);
extern void FUN_00102fb0(...);
extern int * FUN_001073f0(...);
extern int * FUN_001074ac(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_00102ea4(undefined4 *param_1,short param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307b18);
    FUN_00102fb0();
    piVar1 = (int *)param_1[7];
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      param_1[7] = 0;
    }
    puVar2 = param_1 + 0x10;
    if ((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
      FUN_000c3fd8(puVar2,0);
    }
    puVar2 = param_1 + 0xd;
    if ((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
      FUN_00054600(puVar2,0);
    }
    puVar2 = param_1 + 10;
    if ((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
      FUN_001074ac(puVar2,0);
    }
    puVar2 = param_1 + 4;
    if ((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
      FUN_001073f0(puVar2,0);
    }
    puVar2 = param_1 + 1;
    if ((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
      FUN_001073f0(puVar2,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
