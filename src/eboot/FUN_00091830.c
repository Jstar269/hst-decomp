/* HSTMATCH module=EBOOT.BIN start=0x00091830 end=0x000918ac symbol=FUN_00091830 lang=c99 */
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

extern undefined DAT_00307264;
extern void FUN_00091af4();
extern void FUN_00091cbc();
extern undefined4 * FUN_0009444c();

undefined4 * FUN_00091830(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_00307264);
  FUN_0009444c(param_1 + 0x20);
  FUN_0009444c(param_1 + 0x2c);
  param_1[10] = 0;
  param_1[0xc] = 0xbf800000;
  param_1[0xd] = 0xbf800000;
  param_1[0xe] = 0xbf800000;
  param_1[0xf] = 0xbf800000;
  param_1[0x10] = 0;
  param_1[0x11] = 0x3f800000;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  FUN_00091af4(param_1);
  FUN_00091cbc(param_1);
  return param_1;
}
