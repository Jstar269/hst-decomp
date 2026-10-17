/* HSTMATCH module=EBOOT.BIN start=0x0024df84 end=0x0024df94 symbol=FUN_0024df84 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern char DAT_002fbee4[];
extern undefined4 FUN_000657e4();

void FUN_0024df84(undefined4 param_1)
{
  FUN_000657e4(param_1,DAT_002fbee4,1);
  return;
}
