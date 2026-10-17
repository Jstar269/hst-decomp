/* HSTMATCH module=EBOOT.BIN start=0x00250f48 end=0x00250f58 symbol=FUN_00250f48 lang=c99 */
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

extern undefined4 DAT_002fbef4;

void FUN_00250f48(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x304) = param_2;
  DAT_002fbef4 = param_2;
  return;
}
