/* HSTMATCH module=EBOOT.BIN start=0x00194e20 end=0x00194e34 symbol=FUN_00194e20 lang=c99 */
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

extern undefined4 DAT_00341ccc;
extern void FUN_00194ba4();

void FUN_00194e20(undefined4 param_1)
{
  FUN_00194ba4(param_1,*(undefined2 *)(DAT_00341ccc + 0x1034),0x20);
  return;
}
