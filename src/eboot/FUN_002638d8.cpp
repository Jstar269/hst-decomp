/* HSTMATCH module=EBOOT.BIN start=0x002638d8 end=0x0026397c symbol=FUN_002638d8 lang=c++ */
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
extern undefined DAT_002fdee4;
extern undefined DAT_00309aac;
extern char DAT_002fdee8[];
extern int FUN_001026b8(...);
extern int FUN_001039d8(...);
extern undefined4 * FUN_00257be0(...);
extern int * FUN_0025de54(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

extern "C" int * FUN_002638d8(int *param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00257be0();
  *param_1 = (int)&DAT_00309aac;
  FUN_0025de54(param_1 + 0x618);
  uVar1 = FUN_001039d8(param_1,&DAT_002fdee4,0);
  iVar2 = FUN_001026b8(uVar1,DAT_002fdee8);
  param_1[0x791] = iVar2;
  ((VC_0 *)(param_1))->m();
  *(undefined1 *)(param_1[400] + 0x616) = 0;
  *(undefined1 *)(param_1[400] + 0x736) = 0;
  *(undefined1 *)(param_1[400] + 0x856) = 0;
  *(undefined1 *)(param_1[400] + 0x617) = 0;
  *(undefined1 *)(param_1[400] + 0x737) = 0;
  *(undefined1 *)(param_1[400] + 0x857) = 0;
  return param_1;
}
