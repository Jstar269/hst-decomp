/* HSTMATCH module=EBOOT.BIN start=0x0026b590 end=0x0026b674 symbol=FUN_0026b590 lang=c++ */
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
extern undefined DAT_00309380;
extern undefined DAT_00309b74;
extern char DAT_002fe0d4[];
extern char DAT_002fe104[];
extern char DAT_002fe110[];
extern char DAT_002fe11c[];
extern char DAT_002fe124[];
extern int FUN_001026b8(...);
extern undefined4 * FUN_00102e38(...);
extern int FUN_001039d8(...);
extern void FUN_00104118(...);
extern void FUN_0026b724(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

extern "C" int * FUN_0026b590(int *param_1)
{
  int iVar1;
  
  FUN_00102e38();
  *param_1 = (int)&DAT_00309380;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined1 *)((int)param_1 + 0x55) = 0;
  param_1[0x16] = 0;
  *param_1 = (int)&DAT_00309b74;
  FUN_00104118(param_1,DAT_002fe0d4,0);
  iVar1 = FUN_001039d8(param_1,DAT_002fe104,0);
  param_1[0x18] = iVar1;
  iVar1 = FUN_001039d8(param_1,DAT_002fe110,0);
  param_1[0x19] = iVar1;
  iVar1 = FUN_001026b8(param_1[0x18],DAT_002fe11c);
  param_1[0x16] = *(int *)(iVar1 + 0x20);
  iVar1 = FUN_001026b8(param_1[0x19],DAT_002fe124);
  *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x28) + 1;
  param_1[0x1a] = 0;
  FUN_0026b724(param_1,0);
  ((VC_0 *)(param_1))->m();
  return param_1;
}
