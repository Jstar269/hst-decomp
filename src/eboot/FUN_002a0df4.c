/* HSTMATCH module=EBOOT.BIN start=0x002a0df4 end=0x002a0e08 symbol=FUN_002a0df4 lang=c99 */
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


void FUN_002a0df4(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4, undefined2 param_5)
{
  *(undefined2 *)(param_1 + 0xfc) = param_2;
  *(undefined2 *)(param_1 + 0xfe) = param_3;
  *(undefined2 *)(param_1 + 0x100) = param_4;
  *(undefined2 *)(param_1 + 0x102) = param_5;
  return;
}
