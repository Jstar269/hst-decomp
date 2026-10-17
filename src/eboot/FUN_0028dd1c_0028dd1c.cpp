/* HSTMATCH module=EBOOT.BIN start=0x0028dd1c end=0x0028df14 symbol=FUN_0028dd1c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-a5/v17) corrected by hand: typed the four source fields as signed short to select halfword loads; exact match verified; names and types await human review. */
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
extern undefined DAT_002fef18;
extern undefined DAT_002fef24;
extern undefined DAT_00309d64;
extern char DAT_002fef1c[];
extern char DAT_002fef28[];
extern char DAT_002fef34[];
extern char DAT_002fef44[];
extern char DAT_002fef54[];
extern char DAT_002fef60[];
extern char DAT_002fef6c[];
extern char DAT_002fef78[];
extern char DAT_002fef84[];
extern char DAT_002fef90[];
extern char DAT_002fef9c[];
extern void FUN_000ffb3c(...);
extern int FUN_001026b8(...);
extern int FUN_001039d8(...);
extern undefined4 * FUN_00257be0(...);
extern void FUN_0027fed8(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

extern "C" int * FUN_0028dd1c(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  FUN_00257be0();
  *param_1 = (int)&DAT_00309d64;
  param_1[0x61b] = 0;
  *(undefined2 *)(param_1 + 0x61c) = 0;
  param_1[0x61d] = 0;
  *(undefined1 *)(param_1 + 0x61e) = 0;
  param_1[0x61f] = 0;
  *(undefined2 *)(param_1 + 0x620) = 0;
  param_1[0x621] = 0;
  *(undefined1 *)(param_1 + 0x622) = 0;
  uVar1 = FUN_001039d8(param_1,&DAT_002fef18,0);
  iVar2 = FUN_001026b8(uVar1,DAT_002fef1c);
  param_1[0x617] = iVar2;
  iVar2 = FUN_001039d8(param_1,&DAT_002fef24,0);
  param_1[0x6e6] = iVar2;
  iVar2 = FUN_001026b8(iVar2,DAT_002fef28);
  param_1[0x6e5] = *(int *)(iVar2 + 0x20);
  iVar2 = FUN_001026b8(param_1[0x6e6],DAT_002fef34);
  param_1[0x619] = iVar2;
  iVar2 = FUN_001026b8(param_1[0x6e6],DAT_002fef44);
  param_1[0x61a] = iVar2;
  FUN_0027fed8(param_1 + 0x61b,param_1[0x619],1);
  FUN_0027fed8(param_1 + 0x61f,param_1[0x61a],0);
  iVar2 = FUN_001026b8(param_1[0x6e6],DAT_002fef54);
  piVar3 = *(int **)(iVar2 + 0x20);
  param_1[0x623] = (int)piVar3;
  ((VC_0 *)(piVar3))->m((int)(0x80000000));
  iVar2 = FUN_001026b8(param_1[0x6e6],DAT_002fef60);
  piVar3 = *(int **)(iVar2 + 0x20);
  param_1[0x624] = (int)piVar3;
  ((VC_1 *)(piVar3))->m((int)(0x80000000));
  iVar2 = FUN_001026b8(param_1[0x194],DAT_002fef6c);
  param_1[0x6e7] = iVar2;
  iVar2 = FUN_001026b8(param_1[0x194],DAT_002fef78);
  param_1[0x6e8] = iVar2;
  iVar2 = FUN_001026b8(param_1[0x194],DAT_002fef84);
  param_1[0x6e9] = iVar2;
  iVar2 = FUN_001026b8(param_1[0x194],DAT_002fef90);
  param_1[0x6ea] = iVar2;
  *(undefined2 *)(param_1 + 0x6eb) = *(short *)(param_1[0x6e7] + 4);
  *(undefined2 *)((int)param_1 + 0x1bae) = *(short *)(param_1[0x6e8] + 4);
  *(undefined2 *)(param_1 + 0x6ec) = *(short *)(param_1[0x6e9] + 4);
  *(undefined2 *)((int)param_1 + 0x1bb2) = *(short *)(param_1[0x6ea] + 4);
  iVar2 = FUN_001026b8(param_1[0x194],DAT_002fef9c);
  param_1[0x6ed] = iVar2;
  FUN_000ffb3c(param_1[0x1aa],1);
  param_1[0x614] = 0;
  ((VC_2 *)(param_1))->m();
  return param_1;
}
