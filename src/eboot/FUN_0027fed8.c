/* HSTMATCH module=EBOOT.BIN start=0x0027fed8 end=0x0027fef0 symbol=FUN_0027fed8 lang=c99 */
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


void FUN_0027fed8(int *param_1,int param_2,undefined1 param_3)
{
  *param_1 = param_2;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 4);
  *(undefined1 *)(param_1 + 3) = param_3;
  return;
}
