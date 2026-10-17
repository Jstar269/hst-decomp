/* HSTMATCH module=EBOOT.BIN start=0x002178ac end=0x002178d4 symbol=FUN_002178ac lang=c99 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;


void FUN_002178ac(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)
{
  *(undefined1 *)(param_1 + 0x78) = 1;
  *(undefined1 *)(param_1 + 0x79) = 0;
  *(undefined4 *)(param_1 + 0x7c) = param_4;
  *(undefined2 *)(param_1 + 0x84) = param_2;
  *(undefined2 *)(param_1 + 0x86) = param_3;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined2 *)(param_1 + 0x88) = *(undefined2 *)(param_1 + 0x84);
  return;
}
