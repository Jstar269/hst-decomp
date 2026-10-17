/* HSTMATCH module=EBOOT.BIN start=0x00266748 end=0x00266760 symbol=FUN_00266748 lang=c99 */
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


void FUN_00266748(int param_1)
{
  if (*(int *)(param_1 + 0x70) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x70) + 0xd0) = 0;
  }
  return;
}
