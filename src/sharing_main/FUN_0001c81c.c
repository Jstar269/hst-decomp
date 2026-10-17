/* HSTMATCH module=hstp_trans_main.prx start=0x0001c81c end=0x0001c848 symbol=FUN_0001c81c lang=c99 */
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

extern undefined4 DAT_003751d0;
extern undefined4 DAT_003b8efc;

void FUN_0001c81c(int param_1)
{
  if (DAT_003b8efc == 0) {
    DAT_003751d0 = param_1 + 0x7fffU & 0xffff8000;
  }
  return;
}
