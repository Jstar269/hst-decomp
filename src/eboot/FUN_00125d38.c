/* HSTMATCH module=EBOOT.BIN start=0x00125d38 end=0x00125d74 symbol=FUN_00125d38 lang=c99 */
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

extern undefined DAT_00308018;
extern undefined4 * FUN_00060e2c();

undefined4 * FUN_00125d38(undefined4 *param_1)
{
  FUN_00060e2c();
  *param_1 = (unsigned int)(&DAT_00308018);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  return param_1;
}
