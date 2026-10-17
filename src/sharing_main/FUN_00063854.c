/* HSTMATCH module=hstp_trans_main.prx start=0x00063854 end=0x00063888 symbol=FUN_00063854 lang=c99 */
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

extern void FUN_00063908();
extern void FUN_00077d4c();

void FUN_00063854(int param_1)
{
  FUN_00077d4c(*(undefined4 *)(param_1 + 4));
  FUN_00063908(param_1,*(undefined4 *)(param_1 + 0xc));
  return;
}
