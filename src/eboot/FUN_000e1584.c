/* HSTMATCH module=EBOOT.BIN start=0x000e1584 end=0x000e1610 symbol=FUN_000e1584 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
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

extern undefined DAT_002d6b10;
extern undefined DAT_003076ac;
extern undefined4 * FUN_0001f06c();
extern void FUN_000e1674();
extern void FUN_000e1798();

undefined4 * FUN_000e1584(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  FUN_0001f06c(param_1);
  *param_1 = (unsigned int)(&DAT_003076ac);
  param_1[0x15] = 0;
  param_1[0x10] = 0;
  param_1[0x16] = param_2;
  param_1[0x11] = param_3;
  param_1[0xf] = (unsigned int)(&DAT_002d6b10);
  if (param_4 != 0) {
    param_1[0xf] = param_4;
  }
  FUN_000e1674((int)param_1);
  FUN_000e1798(param_1);
  return param_1;
}
