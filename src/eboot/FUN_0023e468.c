/* HSTMATCH module=EBOOT.BIN start=0x0023e468 end=0x0023e47c symbol=FUN_0023e468 lang=c99 */
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

extern void FUN_0023de6c();

void FUN_0023e468(int param_1)
{
  *(undefined4 *)(*(int *)(param_1 + 0x14c0) + 0x1c) = 0;
  FUN_0023de6c(param_1,1,0);
  return;
}
