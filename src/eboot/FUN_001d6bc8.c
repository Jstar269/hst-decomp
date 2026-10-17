/* HSTMATCH module=EBOOT.BIN start=0x001d6bc8 end=0x001d6bf0 symbol=FUN_001d6bc8 lang=c99 */
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

extern undefined DAT_00309c94;
extern undefined DAT_00309ca0;

undefined4 * FUN_001d6bc8(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00309ca0);
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = (unsigned int)(&DAT_00309c94);
  return param_1;
}
