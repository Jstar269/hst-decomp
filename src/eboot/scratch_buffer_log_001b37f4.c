/* HSTMATCH module=EBOOT.BIN start=0x001b37f4 end=0x001b38dc symbol=FUN_001b37f4 lang=c99 data=0x002e950c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the two module addresses written as &DAT_0030ab9c / &DAT_0030ebf4 (lui/addiu, not lui/ori); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002e950c-0x002e9543) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_0030ab9c;
extern undefined DAT_0030ebf4;
extern undefined DAT_002e58d4;
extern undefined DAT_002e58d8;
extern int FUN_00010184();
extern void FUN_000104e0();
extern void FUN_0001bfb4();
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern int FUN_0001cbfc();
extern undefined4 FUN_0001cc54();
extern void FUN_001b06d4();

void FUN_001b37f4(undefined4 *param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = *param_1;
  uVar1 = FUN_00010184(0x40,0x100000);
  FUN_0001bfb4(&DAT_0030ab9c,uVar1,0x100000);
  FUN_0001ca58(&DAT_0030ebf4,"sound/menu/000_common_0.xb");
  FUN_001b06d4(uVar3,&DAT_002e58d4,1,0);
  FUN_0001cb88(&DAT_0030ebf4);
  FUN_0001ca58(&DAT_0030ebf4,"sound/menu/000_common_1.xb");
  FUN_001b06d4(uVar3,&DAT_002e58d8,3,0);
  FUN_0001cb88(&DAT_0030ebf4);
  uVar3 = FUN_0001cbfc();
  uVar2 = FUN_0001cc54();
  FUN_0001bfb4(&DAT_0030ab9c,uVar3,uVar2);
  FUN_000104e0(uVar1);
  return;
}
