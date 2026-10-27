/* HSTMATCH module=EBOOT.BIN start=0x00133e1c end=0x00133e98 symbol=FUN_00133e1c lang=c99 data=0x002db72c */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002db72c-0x002db750) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined4 DAT_003402a4;
extern char DAT_002db344[];
extern void FUN_000143b0();
extern void FUN_00143104();

undefined4 FUN_00133e1c(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  undefined1 auStack_100 [256];
  
  uVar1 = DAT_003402a4;
  FUN_000143b0(auStack_100,"data/court/%s/haichi/%s__haichi.i3m",DAT_003402a4,DAT_003402a4);
  FUN_00143104(param_1 + 0x40,auStack_100,DAT_002db344,uVar1,param_3,0,0);
  return 1;
}
