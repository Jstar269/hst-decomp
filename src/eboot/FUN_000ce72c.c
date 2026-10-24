/* HSTMATCH module=EBOOT.BIN start=0x000ce72c end=0x000ce74c symbol=FUN_000ce72c lang=c99 */
/* AppendCourtParticleLists: data/court/particle/{texlist,motlist}.csv; see docs/DATA-TABLES.md */
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

extern char DAT_002d630c[];
extern char DAT_002d632c[];
extern void FUN_00067e54();

void FUN_000ce72c(void)
{
  FUN_00067e54(DAT_002d630c,DAT_002d632c
               ,0x10,0,1);
  return;
}
