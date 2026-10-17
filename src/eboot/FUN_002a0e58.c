/* HSTMATCH module=EBOOT.BIN start=0x002a0e58 end=0x002a0e88 symbol=FUN_002a0e58 lang=c99 */
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

extern undefined DAT_002cc2ac;

undefined4 * FUN_002a0e58(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_002cc2ac);
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  *(undefined1 *)(param_1 + 0x43) = 0;
  param_1[0x42] = 0x7fffffff;
  return param_1;
}
