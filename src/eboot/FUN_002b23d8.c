/* HSTMATCH module=EBOOT.BIN start=0x002b23d8 end=0x002b2628 symbol=FUN_002b23d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
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

extern char DAT_00302e9c[];
extern char DAT_00302fd0[];
extern char DAT_00302fe4[];
extern char DAT_00302ff0[];
extern char DAT_00303000[];
extern char DAT_00303010[];
extern char DAT_0030301c[];
extern char DAT_00303028[];
extern char DAT_0030303c[];
extern void FUN_000143b0();
extern void FUN_000ffb3c();
extern int FUN_001026b8();
extern int FUN_001039d8();

void FUN_002b23d8(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  undefined1 auStack_40 [64];
  
  FUN_000143b0(auStack_40,DAT_00302fd0);
  uVar1 = FUN_001039d8(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_001026b8(uVar1,auStack_40);
  FUN_000ffb3c(uVar1,1);
  FUN_000143b0(auStack_40,DAT_00302fe4,param_3);
  uVar1 = FUN_001039d8(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_001026b8(uVar1,auStack_40);
  FUN_000ffb3c(uVar1,1);
  FUN_000143b0(auStack_40,DAT_00302ff0,param_3);
  uVar1 = FUN_001039d8(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_001026b8(uVar1,auStack_40);
  FUN_000ffb3c(uVar1,1);
  FUN_000143b0(auStack_40,DAT_00303000,param_3);
  uVar1 = FUN_001039d8(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_001026b8(uVar1,auStack_40);
  FUN_000ffb3c(uVar1,1);
  FUN_000143b0(auStack_40,DAT_00303010,param_3);
  uVar1 = FUN_001039d8(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_001026b8(uVar1,auStack_40);
  FUN_000ffb3c(uVar1,1);
  FUN_000143b0(auStack_40,DAT_0030301c,param_3);
  uVar1 = FUN_001039d8(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_001026b8(uVar1,auStack_40);
  FUN_000ffb3c(uVar1,1);
  FUN_000143b0(auStack_40,DAT_00303028,param_3);
  uVar1 = FUN_001039d8(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_001026b8(uVar1,auStack_40);
  FUN_000ffb3c(uVar1,1);
  FUN_000143b0(auStack_40,DAT_0030303c,param_3);
  uVar1 = FUN_001039d8(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_001026b8(uVar1,auStack_40);
  FUN_000ffb3c(uVar1,1);
  FUN_000143b0(auStack_40,DAT_00302e9c,param_3);
  uVar1 = FUN_001039d8(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_001026b8(uVar1,auStack_40);
  FUN_000ffb3c(uVar1,1);
  return;
}
