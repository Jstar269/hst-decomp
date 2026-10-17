/* HSTMATCH module=EBOOT.BIN start=0x00225b6c end=0x00225b78 symbol=FUN_00225b6c lang=c99 */
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

extern void FUN_000f6b0c();

void FUN_00225b6c(int param_1)
{
  FUN_000f6b0c(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x30));
  return;
}
