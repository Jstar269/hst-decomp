/* HSTMATCH module=EBOOT.BIN start=0x000ce8e8 end=0x000ce90c symbol=FUN_000ce8e8 lang=c99 */
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

extern undefined DAT_0030753c;
extern undefined DAT_00307550;

undefined4 * FUN_000ce8e8(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_0030753c);
  param_1[1] = 0;
  *param_1 = (unsigned int)(&DAT_00307550);
  return param_1;
}
