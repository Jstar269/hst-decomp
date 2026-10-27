/* HSTMATCH module=EBOOT.BIN start=0x001c7cb4 end=0x001c7d30 symbol=FUN_001c7cb4 lang=c99 data=0x002ea9e4 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0201_001c7cb4_m04.c); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ea9e4-0x002eaa11) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern void FUN_000104e0();
extern void FUN_000143b0();
extern uint FUN_0004cad0();
extern void FUN_00127308();

int FUN_001c7cb4(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5, undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  uint uVar1;
  char acStack_80 [128];
  int iStack_84;
  
  FUN_000143b0(acStack_80,"data/script/script_bin/lobby%02d/motlist.mld",param_2,param_4,param_5,
               param_6,param_7,param_8);
  uVar1 = FUN_0004cad0(acStack_80,&iStack_84,0x10,1);
  if (param_4 != 0) {
    FUN_00127308(uVar1,param_3 - 1);
  }
  FUN_000104e0(uVar1);
  return param_4;
}
