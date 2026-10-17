/* HSTMATCH module=hstp_trans_main.prx start=0x00061cb0 end=0x00061d00 symbol=FUN_00061cb0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined DAT_003b0348;
extern undefined4 * FUN_0006163c();

undefined4 * FUN_00061cb0(undefined4 *param_1)
{
  FUN_0006163c();
  *param_1 = (unsigned int)(&DAT_003b0348);
  param_1[0x20] = 0x42340000;
  param_1[0x21] = 0x3e4ccccd;
  param_1[0x22] = 0x447a0000;
  return param_1;
}
