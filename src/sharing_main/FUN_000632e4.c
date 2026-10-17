/* HSTMATCH module=hstp_trans_main.prx start=0x000632e4 end=0x00063304 symbol=FUN_000632e4 lang=c99 */
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


undefined4 * FUN_000632e4(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0xffffffff;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[3] = 0xffffffff;
  param_1[4] = 0;
  return param_1;
}
