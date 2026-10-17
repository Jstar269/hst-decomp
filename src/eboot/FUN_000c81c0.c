/* HSTMATCH module=EBOOT.BIN start=0x000c81c0 end=0x000c81ec symbol=FUN_000c81c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a3); exact match verified; names and types await human review. */
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

extern void FUN_000ce72c();

undefined4 FUN_000c81c0(int param_1)
{
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_000ce72c(*(int *)(param_1 + 0x44));
  }
  return 1;
}
