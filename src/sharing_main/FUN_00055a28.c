/* HSTMATCH module=hstp_trans_main.prx start=0x00055a28 end=0x00055a6c symbol=FUN_00055a28 lang=c99 */
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

extern undefined DAT_003b02a0;
extern void FUN_00055ad0();

undefined4 * FUN_00055a28(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = (unsigned int)(&DAT_003b02a0);
  FUN_00055ad0();
  param_1[0x23] = param_2;
  return param_1;
}
