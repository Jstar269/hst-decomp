/* HSTMATCH module=hstp_trans_main.prx start=0x00066384 end=0x000663b8 symbol=FUN_00066384 lang=c99 */
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

extern void FUN_0006594c();
extern void FUN_00067694();

void FUN_00066384(int param_1)
{
  FUN_0006594c();
  FUN_00067694(param_1 + 0x10);
  FUN_00067694(param_1 + 0x20);
  return;
}
