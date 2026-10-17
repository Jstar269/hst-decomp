/* HSTMATCH module=EBOOT.BIN start=0x0027caa0 end=0x0027cae4 symbol=FUN_0027caa0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined DAT_00309c34;
extern undefined4 * FUN_00060e2c();

undefined4 * FUN_0027caa0(undefined4 *param_1)
{
  FUN_00060e2c();
  *param_1 = (unsigned int)(&DAT_00309c34);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x21] = 0x40000000;
  return param_1;
}
