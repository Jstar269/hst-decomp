/* HSTMATCH module=EBOOT.BIN start=0x00115588 end=0x001155c0 symbol=FUN_00115588 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_001031e8();

void FUN_00115588(int param_1)
{
  if (((*(uint *)(param_1 + 0x6c) & 8) == 0) || (*(int *)(param_1 + 0x88) < 1)) {
    FUN_001031e8();
  }
  return;
}
