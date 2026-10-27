/* HSTMATCH module=EBOOT.BIN start=0x000ce70c end=0x000ce72c symbol=FUN_000ce70c lang=c99 data=0x002d62bc */
/* LoadMenuParticleLists: data/menu/game_eff/particle/{texlist,motlist}.csv; see docs/DATA-TABLES.md Data: its string literals (2 strings, 0x002d62bc-0x002d630c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_00067e54();

void FUN_000ce70c(void)
{
  FUN_00067e54("data/menu/game_eff/particle/texlist.csv",
               "data/menu/game_eff/particle/motlist.csv",0x10,0,0);
  return;
}
